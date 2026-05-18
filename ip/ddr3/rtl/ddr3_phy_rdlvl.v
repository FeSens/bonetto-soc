// ddr3_phy_rdlvl — DDR3 read-leveling FSM using MPR.
//
// Per JEDEC 79-3F §6.5 (MPR Read), the DDR3 chip exposes a Multi-Purpose
// Register that drives a predefined pattern onto DQ for a BL8 read,
// independent of the DRAM array. The predefined pattern (selected by
// MR3[1:0]=00) is 0,1,0,1,0,1,0,1 across the 8 beats — when sampled
// with a 4:1 SERDES into two 32-bit words per byte lane, each word is
// 32'hAAAA_AAAA (DQ[7:0] = 0xAA per beat-quad).
//
// Procedure:
//
//   1. Init FSM programs MR3[2]=1, MR3[1:0]=00 (MPR enabled, predefined
//      pattern). MR1[7]=0 (write-leveling disabled). Wait tMOD.
//   2. For each byte lane:
//        a. For each candidate IDELAYE2 tap (0..31) on that lane's DQS:
//             - Load the tap (o_dqs_in_load_lane pulse, o_dqs_in_tap bus)
//             - Wait SETTLE_CYCLES for the IDELAY load to propagate.
//             - Issue an MPR read (o_mpr_read_req pulse).
//             - Wait READ_LATENCY cycles for data to come back.
//             - Compare i_rd_data[lane*32 +: 32] to EXPECTED_PATTERN.
//             - Record pass/fail in a per-tap bitmap.
//        b. Find the longest contiguous run of passes in the bitmap.
//        c. Pick the centre of that run as the locked tap. Load it.
//   3. Init FSM clears MR3[2]=0 to leave MPR mode.
//
// Eye-finding policy: pick the geometric centre of the largest contiguous
// pass-tap run. If multiple equal-length runs exist (rare; usually noise),
// pick the first. If no pass tap exists at all, set o_error.
//
// MPR-read issuing is delegated upstream — this module pulses
// `o_mpr_read_req` and observes captured data on `i_rd_data` /
// `i_rd_data_valid`. The parent (ddr3_phy or ddr3_ctrl wrapper) is
// responsible for actually emitting the RD command to the DDR3 chip
// at the right address and timing.

`default_nettype none

module ddr3_phy_rdlvl #(
    parameter integer NUM_BYTE_LANES  = 9,
    parameter integer DQ_BITS         = 8,
    parameter integer RATIO           = 4,
    parameter integer TAP_MAX         = 31,    // IDELAYE2 5-bit
    parameter integer SETTLE_CYCLES   = 32,
    parameter integer READ_LATENCY    = 32,    // wait this many cycles for MPR data to arrive
    parameter [DQ_BITS*RATIO-1:0] EXPECTED_PATTERN = {(DQ_BITS*RATIO/8){8'hAA}}
) (
    input  wire                              i_clk,
    input  wire                              i_rst,

    // -------- Control --------
    input  wire                              i_start,
    output wire                              o_done,
    output wire                              o_error,
    output wire [3:0]                        o_state,

    // -------- Upstream MPR-read interface --------
    // The parent (or runtime FSM, when MPR-bypass is wired in) issues
    // the RD command in response to o_mpr_read_req; o_mpr_read_addr is
    // the column address (only A[12]=1 + A[2]=1 are meaningful for MPR;
    // parent encodes this as needed).
    output reg                               o_mpr_read_req,
    output wire [12:0]                       o_mpr_read_addr,
    input  wire                              i_rd_data_valid,
    input  wire [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] i_rd_data,

    // -------- Knobs into the lane array's DQS *input*-delay (IDELAYE2) --
    output reg  [NUM_BYTE_LANES-1:0]         o_dqs_in_load_lane,
    output reg  [4:0]                        o_dqs_in_tap,

    // -------- Final locked tap per lane, exposed for status/debug ----
    output reg  [NUM_BYTE_LANES*5-1:0]       o_locked_tap_lane
);
    // -------- Address for MPR location 0 ----------------------------
    // A[12]=1 (BC# disable, forces full BL8). A[2:0]=000 (MPR
    // predefined-pattern location 0). All other bits 0.
    // Per JEDEC, MPR-read selection itself is via MR3[2]=1 — programmed
    // by the init FSM ahead of i_start.
    assign o_mpr_read_addr = 13'b1_0000_0000_0000;

    // -------- LANE_IDX_W: ceil(log2(NUM_BYTE_LANES)) ----------------
    localparam integer LANE_IDX_W =
          (NUM_BYTE_LANES <=  1) ?  1
        : (NUM_BYTE_LANES <=  2) ?  1
        : (NUM_BYTE_LANES <=  4) ?  2
        : (NUM_BYTE_LANES <=  8) ?  3
        : (NUM_BYTE_LANES <= 16) ?  4
        : 5;

    // -------- FSM states --------------------------------------------
    localparam [3:0] S_IDLE         = 4'd0;
    localparam [3:0] S_SETUP_LANE   = 4'd1;
    localparam [3:0] S_LOAD_TAP     = 4'd2;
    localparam [3:0] S_SETTLE       = 4'd3;
    localparam [3:0] S_ISSUE_READ   = 4'd4;
    localparam [3:0] S_WAIT_READ    = 4'd5;
    localparam [3:0] S_CHECK        = 4'd6;
    localparam [3:0] S_TAP_NEXT     = 4'd7;
    localparam [3:0] S_FIND_CENTRE  = 4'd8;
    localparam [3:0] S_LOAD_CENTRE  = 4'd9;
    localparam [3:0] S_NEXT_LANE    = 4'd10;
    localparam [3:0] S_DONE         = 4'd11;
    localparam [3:0] S_ERROR        = 4'd12;

    reg [3:0]              state;
    reg [4:0]              tap;
    reg [LANE_IDX_W-1:0]   lane;
    reg [NUM_BYTE_LANES-1:0] lane_onehot;
    reg [31:0]             timer;
    reg                    done_r, error_r;

    // -------- Per-tap pass bitmap for the lane currently being trained --
    reg [TAP_MAX:0]        pass_bitmap;

    // -------- Centre-finding scratch state --------------------------
    reg [5:0]              best_start, best_len;     // (TAP_MAX+1) ≤ 32; 6 bits is enough
    reg [5:0]              cur_start,  cur_len;
    reg [5:0]              scan_idx;

    // -------- Read-data buffer (latched on i_rd_data_valid) ---------
    reg [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] rd_buf;
    reg                                    rd_ready;

    // -------- Sequential update -------------------------------------
    integer check_i;
    integer lock_i;
    wire [4:0] centre_tap = best_start[4:0] + (best_len[5:1]);

    always @(posedge i_clk) begin
        if (i_rst) begin
            state              <= S_IDLE;
            tap                <= 5'd0;
            lane               <= {LANE_IDX_W{1'b0}};
            lane_onehot        <= {{(NUM_BYTE_LANES-1){1'b0}}, 1'b1};
            timer              <= 32'd0;
            done_r             <= 1'b0;
            error_r            <= 1'b0;
            pass_bitmap        <= {(TAP_MAX+1){1'b0}};
            best_start         <= 6'd0;
            best_len           <= 6'd0;
            cur_start          <= 6'd0;
            cur_len            <= 6'd0;
            scan_idx           <= 6'd0;
            rd_buf             <= {(NUM_BYTE_LANES*DQ_BITS*RATIO){1'b0}};
            rd_ready           <= 1'b0;
            o_mpr_read_req     <= 1'b0;
            o_dqs_in_load_lane <= {NUM_BYTE_LANES{1'b0}};
            o_dqs_in_tap       <= 5'd0;
            o_locked_tap_lane  <= {(NUM_BYTE_LANES*5){1'b0}};
        end else begin
            // Default single-cycle pulses
            o_mpr_read_req     <= 1'b0;
            o_dqs_in_load_lane <= {NUM_BYTE_LANES{1'b0}};

            // Always latch read data when valid (ahead of S_WAIT_READ check)
            if (i_rd_data_valid) begin
                rd_buf   <= i_rd_data;
                rd_ready <= 1'b1;
            end

            case (state)
                S_IDLE: begin
                    if (i_start) begin
                        tap         <= 5'd0;
                        lane        <= {LANE_IDX_W{1'b0}};
                        lane_onehot <= {{(NUM_BYTE_LANES-1){1'b0}}, 1'b1};
                        pass_bitmap <= {(TAP_MAX+1){1'b0}};
                        done_r      <= 1'b0;
                        error_r     <= 1'b0;
                        state       <= S_SETUP_LANE;
                    end
                end

                S_SETUP_LANE: begin
                    tap         <= 5'd0;
                    pass_bitmap <= {(TAP_MAX+1){1'b0}};
                    state       <= S_LOAD_TAP;
                end

                S_LOAD_TAP: begin
                    o_dqs_in_tap       <= tap;
                    o_dqs_in_load_lane <= lane_onehot;
                    timer              <= SETTLE_CYCLES;
                    state              <= S_SETTLE;
                end

                S_SETTLE: begin
                    if (timer == 0)
                        state <= S_ISSUE_READ;
                    else
                        timer <= timer - 1;
                end

                S_ISSUE_READ: begin
                    o_mpr_read_req <= 1'b1;
                    rd_ready       <= 1'b0;
                    timer          <= READ_LATENCY;
                    state          <= S_WAIT_READ;
                end

                S_WAIT_READ: begin
                    if (rd_ready) begin
                        state <= S_CHECK;
                    end else if (timer == 0) begin
                        // Treat read-timeout as a fail at this tap.
                        pass_bitmap[tap] <= 1'b0;
                        state            <= S_TAP_NEXT;
                    end else begin
                        timer <= timer - 1;
                    end
                end

                S_CHECK: begin
                    // Sample only the lane currently being trained.
                    pass_bitmap[tap] <= 1'b0;
                    for (check_i = 0; check_i < NUM_BYTE_LANES; check_i = check_i + 1) begin
                        if (lane_onehot[check_i] &&
                                (rd_buf[check_i*DQ_BITS*RATIO +: DQ_BITS*RATIO]
                                    == EXPECTED_PATTERN))
                            pass_bitmap[tap] <= 1'b1;
                    end
                    state <= S_TAP_NEXT;
                end

                S_TAP_NEXT: begin
                    if (tap == TAP_MAX[4:0]) begin
                        // All taps scanned for this lane — find centre.
                        scan_idx   <= 6'd0;
                        cur_start  <= 6'd0;
                        cur_len    <= 6'd0;
                        best_start <= 6'd0;
                        best_len   <= 6'd0;
                        state      <= S_FIND_CENTRE;
                    end else begin
                        tap   <= tap + 5'd1;
                        state <= S_LOAD_TAP;
                    end
                end

                S_FIND_CENTRE: begin
                    // Walk pass_bitmap[0..TAP_MAX] one entry per cycle.
                    // For each pass entry, advance the current run and
                    // commit to best-so-far on the same cycle so the
                    // final scan_idx=TAP_MAX iteration handles the last
                    // entry's contribution correctly (no off-by-one).
                    if (pass_bitmap[scan_idx]) begin
                        // Extend the current run.
                        if (cur_len == 0)
                            cur_start <= scan_idx;
                        cur_len <= cur_len + 1;
                        // Commit to best-so-far using the *next* cur_len.
                        if ((cur_len + 1) > best_len) begin
                            best_start <= (cur_len == 0) ? scan_idx : cur_start;
                            best_len   <= cur_len + 1;
                        end
                    end else begin
                        // Run broken — reset cur_len so the next pass
                        // starts a fresh run. (cur_start updated lazily
                        // when the next run begins.)
                        cur_len <= 6'd0;
                    end
                    if (scan_idx == TAP_MAX[5:0])
                        state <= S_LOAD_CENTRE;
                    else
                        scan_idx <= scan_idx + 1;
                end

                S_LOAD_CENTRE: begin
                    if (best_len == 0) begin
                        error_r <= 1'b1;
                        state   <= S_ERROR;
                    end else begin
                        for (lock_i = 0; lock_i < NUM_BYTE_LANES; lock_i = lock_i + 1) begin
                            if (lane_onehot[lock_i])
                                o_locked_tap_lane[lock_i*5 +: 5] <= centre_tap;
                        end
                        o_dqs_in_tap       <= centre_tap;
                        o_dqs_in_load_lane <= lane_onehot;
                        state <= S_NEXT_LANE;
                    end
                end

                S_NEXT_LANE: begin
                    if (lane == (NUM_BYTE_LANES-1)) begin
                        done_r <= 1'b1;
                        state  <= S_DONE;
                    end else begin
                        lane        <= lane + 1'b1;
                        lane_onehot <= lane_onehot << 1;
                        state       <= S_SETUP_LANE;
                    end
                end

                S_DONE: begin
                    if (i_start) begin
                        tap         <= 5'd0;
                        lane        <= {LANE_IDX_W{1'b0}};
                        lane_onehot <= {{(NUM_BYTE_LANES-1){1'b0}}, 1'b1};
                        done_r      <= 1'b0;
                        error_r     <= 1'b0;
                        state       <= S_SETUP_LANE;
                    end
                end

                S_ERROR: begin
                    if (i_start) begin
                        tap         <= 5'd0;
                        lane        <= {LANE_IDX_W{1'b0}};
                        lane_onehot <= {{(NUM_BYTE_LANES-1){1'b0}}, 1'b1};
                        done_r      <= 1'b0;
                        error_r     <= 1'b0;
                        state       <= S_SETUP_LANE;
                    end
                end

                default: state <= S_IDLE;
            endcase
        end
    end

    assign o_done  = done_r;
    assign o_error = error_r;
    assign o_state = state;

endmodule
