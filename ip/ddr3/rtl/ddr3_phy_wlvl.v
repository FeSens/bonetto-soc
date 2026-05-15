// ddr3_phy_wlvl — DDR3 write-leveling FSM.
//
// Per JEDEC 79-3F §6.5 (Write Leveling):
//
//   1. Controller programs MR1[7]=1 (write-leveling enabled), with
//      MR2[10:9]=00 (RTT_WR disabled). The init FSM emits these MR
//      writes — the wlvl FSM is started AFTER init completes and after
//      a second MR1 write enables write-leveling.
//   2. Controller drives ODT high.
//   3. After tWLDQSEN (25 tCK) + tWLMRD (40 tCK), controller toggles
//      DQS at the byte-lane being trained.
//   4. On each DQS rising edge, the DDR3 chip samples CK and drives
//      DQ[0] of that byte lane:
//          DQ[0] = 0  → DQS is too early (leading CK).
//          DQ[0] = 1  → DQS is on time or late (sampled CK high).
//   5. Controller walks the DQS-output delay (ODELAYE2 on the OSERDESE2
//      DQS output) from tap 0 upward, sampling DQ[0] at each tap, until
//      it sees the 0 → 1 transition. The tap one position before the
//      transition is the locked value.
//   6. Repeat for every byte lane.
//
// This module owns the search FSM. It does NOT instantiate ODELAYE2 —
// that primitive lives in `ddr3_phy_dq.v` (see TODO: add ODELAYE2 on
// the DQS output path for iter-3b finish). For now this FSM drives the
// per-lane load pulse + shared tap bus, and the lane-array wires those
// to whichever output-delay primitive is in place.
//
// Multi-lane training is sequential: train lane 0 to completion, then
// lane 1, etc. This avoids contention on the shared MR1[7]=1 state and
// matches the JEDEC flow.
//
// Sim guard: `BONETTO_SOC_SIM` keeps the FSM functional but instantiated
// against the existing ddr3_phy_dq sim stubs (which always return 0 on
// DQ). So in sim, the FSM walks every tap and finishes with `o_error=1`
// because no transition is ever seen — the sim test verifies the
// state-machine flow, not the calibration result.

`default_nettype none

module ddr3_phy_wlvl #(
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer TAP_MAX        = 31,    // IDELAYE2 / ODELAYE2 5-bit
    parameter integer SETTLE_CYCLES  = 32     // cycles between LD and sample
) (
    input  wire                              i_clk,
    input  wire                              i_rst,

    // -------- Control --------
    input  wire                              i_start,
    output wire                              o_done,
    output wire                              o_error,
    output wire [3:0]                        o_state,

    // -------- Per-byte-lane DQ[0] feedback (from the read SERDES) ----
    // The chip drives a steady level on each DQ[0] in wlvl mode, so the
    // controller samples this directly each cycle.
    input  wire [NUM_BYTE_LANES-1:0]         i_dq0_per_lane,

    // -------- Knobs into the lane array's DQS output-delay primitive --
    output reg  [NUM_BYTE_LANES-1:0]         o_dqs_out_load_lane,
    output reg  [4:0]                        o_dqs_out_tap,
    output reg  [NUM_BYTE_LANES-1:0]         o_dqs_toggle_en_lane,

    // -------- Final locked tap per lane, exposed for status/debug ----
    output reg  [NUM_BYTE_LANES*5-1:0]       o_locked_tap_lane
);
    // -------- LANE_IDX_W: ceil(log2(NUM_BYTE_LANES)) -----------------
    localparam integer LANE_IDX_W =
          (NUM_BYTE_LANES <=  1) ?  1
        : (NUM_BYTE_LANES <=  2) ?  1
        : (NUM_BYTE_LANES <=  4) ?  2
        : (NUM_BYTE_LANES <=  8) ?  3
        : (NUM_BYTE_LANES <= 16) ?  4
        : 5;

    // -------- FSM states --------------------------------------------
    // DQ[0] transitions monotonically 0→1 as DQS-out delay walks past
    // CK, so we lock at the first tap where DQ[0]=1.
    localparam [3:0] S_IDLE       = 4'd0;
    localparam [3:0] S_SETUP_LANE = 4'd1;
    localparam [3:0] S_LOAD_TAP   = 4'd2;
    localparam [3:0] S_SETTLE     = 4'd3;
    localparam [3:0] S_SAMPLE     = 4'd4;
    localparam [3:0] S_NEXT_LANE  = 4'd5;
    localparam [3:0] S_DONE       = 4'd6;
    localparam [3:0] S_ERROR      = 4'd7;

    reg [3:0]              state;
    reg [4:0]              tap;
    reg [LANE_IDX_W-1:0]   lane;
    reg [31:0]             settle_ctr;
    reg                    done_r, error_r;

    // -------- Sequential update -------------------------------------
    always @(posedge i_clk) begin
        if (i_rst) begin
            state               <= S_IDLE;
            tap                 <= 5'd0;
            lane                <= {LANE_IDX_W{1'b0}};
            settle_ctr          <= 32'd0;
            done_r              <= 1'b0;
            error_r             <= 1'b0;
            o_dqs_out_load_lane <= {NUM_BYTE_LANES{1'b0}};
            o_dqs_out_tap       <= 5'd0;
            o_dqs_toggle_en_lane<= {NUM_BYTE_LANES{1'b0}};
            o_locked_tap_lane   <= {(NUM_BYTE_LANES*5){1'b0}};
        end else begin
            // Default — single-cycle pulses
            o_dqs_out_load_lane <= {NUM_BYTE_LANES{1'b0}};

            case (state)
                S_IDLE: begin
                    if (i_start) begin
                        tap        <= 5'd0;
                        lane       <= {LANE_IDX_W{1'b0}};
                        done_r     <= 1'b0;
                        error_r    <= 1'b0;
                        state      <= S_SETUP_LANE;
                    end
                end

                S_SETUP_LANE: begin
                    // Reset the per-lane tap walk and enable DQS toggle
                    // for the active lane only.
                    tap                  <= 5'd0;
                    o_dqs_toggle_en_lane <= ({{(NUM_BYTE_LANES-1){1'b0}}, 1'b1} << lane);
                    state                <= S_LOAD_TAP;
                end

                S_LOAD_TAP: begin
                    // Drive shared tap bus + one-hot per-lane load pulse
                    o_dqs_out_tap        <= tap;
                    o_dqs_out_load_lane  <= ({{(NUM_BYTE_LANES-1){1'b0}}, 1'b1} << lane);
                    settle_ctr           <= SETTLE_CYCLES;
                    state                <= S_SETTLE;
                end

                S_SETTLE: begin
                    if (settle_ctr == 0)
                        state <= S_SAMPLE;
                    else
                        settle_ctr <= settle_ctr - 1;
                end

                S_SAMPLE: begin
                    // DQ[0] transitions monotonically 0→1 with increasing
                    // tap; the first tap reading high is the answer.
                    if (i_dq0_per_lane[lane] == 1'b1) begin
                        o_locked_tap_lane[lane*5 +: 5] <= tap;
                        state <= S_NEXT_LANE;
                    end else if (tap == TAP_MAX[4:0]) begin
                        // No transition seen across the full delay line.
                        error_r <= 1'b1;
                        state   <= S_ERROR;
                    end else begin
                        tap   <= tap + 5'd1;
                        state <= S_LOAD_TAP;
                    end
                end

                S_NEXT_LANE: begin
                    o_dqs_toggle_en_lane <= {NUM_BYTE_LANES{1'b0}};
                    if (lane == (NUM_BYTE_LANES-1)) begin
                        done_r <= 1'b1;
                        state  <= S_DONE;
                    end else begin
                        lane  <= lane + 1'b1;
                        state <= S_SETUP_LANE;
                    end
                end

                S_DONE: begin
                    if (i_start) begin
                        done_r  <= 1'b0;
                        error_r <= 1'b0;
                        state   <= S_SETUP_LANE;
                    end
                end

                S_ERROR: begin
                    if (i_start) begin
                        done_r  <= 1'b0;
                        error_r <= 1'b0;
                        state   <= S_SETUP_LANE;
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
