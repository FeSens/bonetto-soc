// ddr3_runtime — DDR3 runtime read/write FSM (post-init).
//
// Current runtime: ACT -> RD/WR -> PRE per transaction (no row caching),
// single-bank-at-a-time, hard-coded burst length 8. Refresh scheduler
// interleaved.
//
// Iter-3 refinements (TODO, marked in code):
//   * Per-bank state tracking with row caching (avoid ACT/PRE on the
//     same row twice).
//   * Command queue with bank-interleaved arbitration.
//   * Wide WB burst buffering to use every word in each BL8 transaction.
//   * Auto-precharge variant (A10=1 on RD/WR) to skip the explicit PRE.
//
// State machine (single-bank simple variant):
//
//   IDLE ──[wb_stb, !pending_ref]──▶ ACT
//   ACT  ─────[1 cycle]────────────▶ WAIT_RCD
//   WAIT_RCD ──[tRCD elapsed]──────▶ CMD (RD or WR)
//   CMD ─────[1 cycle]─────────────▶ WAIT_CL  (read) or WAIT_CWL (write)
//   WAIT_CL ─[tCL elapsed]─────────▶ DATA_RD (CL cycles → first beat)
//   WAIT_CWL──[tCWL elapsed]──────▶ DATA_WR
//   DATA_RD ─[8 beats]─────────────▶ PRE
//   DATA_WR ─[8 beats]─────────────▶ PRE
//   PRE  ─[tRP elapsed]────────────▶ IDLE
//
// Refresh:
//   While IDLE, if (cycles_since_ref > tREFI), insert PRE_ALL → tRP →
//   REF → tRFC → IDLE before accepting new WB requests.

`default_nettype none

`include "ddr3_params.vh"
`include "ddr3_cmd.vh"

module ddr3_runtime #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 28,
    parameter integer ROW_BITS  = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS  = `DDR3_COL_BITS,
    parameter integer DQ_BITS   = 8,
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer SERDES_RATIO   = 4
) (
    input  wire                       i_clk_phy,
    input  wire                       i_rst,
    input  wire                       i_init_done,

    // -------- Wishbone B4 pipelined slave (from ddr3_ctrl front-end) --------
    input  wire                       i_wb_cyc,
    input  wire                       i_wb_stb,
    input  wire                       i_wb_we,
    input  wire [WB_ADDR_W-1:0]       i_wb_adr,
    input  wire [WB_DATA_W-1:0]       i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]     i_wb_sel,
    output wire                       o_wb_stall,
    output reg                        o_wb_ack,
    output reg  [WB_DATA_W-1:0]       o_wb_dat,
    output wire                       o_wb_err,

    // -------- DDR3 command outputs (when active) --------
    output reg                        o_cmd_valid,    // 1 = drive cmd this cycle
    output reg  [3:0]                 o_cmd,          // {cs_n, ras_n, cas_n, we_n}
    output reg  [BANK_BITS-1:0]       o_cmd_ba,
    output reg  [ROW_BITS-1:0]        o_cmd_addr,
    output wire                       o_cmd_odt,

    // -------- DDR3 PHY data side --------
    input  wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] i_rd_data,
    input  wire                       i_rd_valid,
    output wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] o_wr_data,
    output reg                        o_wr_valid,
    output wire                       o_rd_capture,

    // -------- MPR-read request port (iter-3c, for read-leveling) --------
    // When `i_mpr_req` pulses, the FSM emits an RD command with
    // address bits driven from `i_mpr_addr` (A[12]=1, A[2:0]=000 for
    // MPR location 0). No ACT precedes, no PRE follows — MPR data is
    // internal to the DDR3 chip, not in a row. The chip must already
    // be in MR3[2]=1 mode (programmed via the init FSM's MR3-rewrite
    // pass after standard init completes).
    input  wire                       i_mpr_req,
    input  wire [12:0]                i_mpr_addr,
    output wire                       o_mpr_busy,

    // -------- MRS-rewrite request port (iter-8, for cal_seq) --------
    // Lets cal_seq toggle MR1[7] (wlvl enable) or MR3[2] (MPR enable)
    // mid-calibration. The runtime FSM emits a single MRS command with
    // the supplied bank/addr and then waits tMOD before resuming WB
    // traffic. Priority: refresh > MRS > MPR > WB.
    input  wire                       i_mrs_req,
    input  wire [BANK_BITS-1:0]       i_mrs_ba,
    input  wire [ROW_BITS-1:0]        i_mrs_addr,
    output wire                       o_mrs_busy
);
    // ---- WB address split ----
    // adr = { bank, row, col[COL_BITS-1:3] } — bottom 3 bits absorbed by BL8.
    // For WB_ADDR_W = 28 and our 15+3+10 = 28-bit DRAM address space, this fits.
    wire [BANK_BITS-1:0]        wb_bank = i_wb_adr[BANK_BITS + ROW_BITS + (COL_BITS-3) - 1 -: BANK_BITS];
    wire [ROW_BITS-1:0]         wb_row  = i_wb_adr[ROW_BITS + (COL_BITS-3) - 1            -: ROW_BITS];
    wire [COL_BITS-1:0]         wb_col  = { i_wb_adr[(COL_BITS-3)-1:0], 3'b000 };

    localparam integer WB_BYTES = WB_DATA_W / 8;
    localparam integer PHY_DATA_W = NUM_BYTE_LANES * DQ_BITS * SERDES_RATIO;
    localparam integer CK_PER_SYS = `DDR3_CK_PER_SYS;
    function integer tck_to_sys;
        input integer tck_cycles;
        begin
            tck_to_sys = (tck_cycles + CK_PER_SYS - 1) / CK_PER_SYS;
            if (tck_to_sys < 1) tck_to_sys = 1;
        end
    endfunction
    function integer wait_limit;
        input integer sys_cycles;
        begin
            wait_limit = (sys_cycles > 1) ? (sys_cycles - 2) : 0;
        end
    endfunction

    localparam integer CL_SYS  = tck_to_sys(`DDR3_CL);
    localparam integer CWL_SYS = tck_to_sys(`DDR3_CWL);
    localparam integer BURST_SYS_CYCLES = tck_to_sys(`DDR3_BL / 2);
    localparam integer CWL_START_WAIT = (CWL_SYS > 2) ? (CWL_SYS - 3) : 0;
    localparam integer READ_CAPTURE_SYS_CYCLES = BURST_SYS_CYCLES + 6;
    localparam integer READ_SETTLE_SYS_CYCLES = 4;
    localparam integer TREFI_SYS = tck_to_sys(`DDR3_TREFI);
    localparam integer TRCD_WAIT = wait_limit(tck_to_sys(`DDR3_TRCD));
    localparam integer TRP_WAIT  = wait_limit(tck_to_sys(`DDR3_TRP));
    localparam integer TRFC_WAIT = wait_limit(tck_to_sys(`DDR3_TRFC));
    localparam integer TCCD_WAIT = wait_limit(tck_to_sys(`DDR3_TCCD));
    localparam integer TMOD_WAIT = wait_limit(tck_to_sys(`DDR3_TMOD));
    localparam integer TWR_SYS   = tck_to_sys(`DDR3_TWR);

    // ---- Refresh scheduler ----
    // ref_pending is SET by the scheduler when tREFI elapses and
    // CLEARED by the main FSM when REF completes. Both updates live in
    // the same always block to avoid multiple-driver issues.
    reg [15:0] ref_ctr;
    reg        ref_pending;
    reg        ref_clear;                  // pulses from FSM at end of REF
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            ref_ctr     <= 16'd0;
            ref_pending <= 1'b0;
        end else begin
            if (ref_ctr == TREFI_SYS - 1) begin
                ref_ctr     <= 16'd0;
                ref_pending <= 1'b1;
            end else begin
                ref_ctr <= ref_ctr + 1'b1;
            end
            if (ref_clear) ref_pending <= 1'b0;
        end
    end

    // ---- Runtime FSM ----
    localparam [4:0]
        S_IDLE      = 5'd0,
        S_ACT       = 5'd1,
        S_WAIT_RCD  = 5'd2,
        S_RD        = 5'd3,
        S_WR        = 5'd4,
        S_WAIT_CL   = 5'd5,
        S_WAIT_CWL  = 5'd6,
        S_DATA_RD   = 5'd7,
        S_DATA_WR   = 5'd8,
        S_PRE       = 5'd9,
        S_WAIT_RP   = 5'd10,
        S_REF_PRE   = 5'd11,
        S_REF_WAIT_RP = 5'd12,
        S_REF       = 5'd13,
        S_REF_WAIT  = 5'd14,
        S_MPR_RD    = 5'd15,
        S_MPR_WAIT  = 5'd16,
        S_MRS       = 5'd17,
        S_MRS_WAIT  = 5'd18,
        S_WR_RECOV  = 5'd19;

    // ---- MPR-request latch (single-shot; cleared on completion) ----
    reg        mpr_pending;
    reg [12:0] mpr_addr_q;
    reg        mpr_clear;     // pulses from FSM when MPR-RD command emitted

    reg [4:0]  state;

    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            mpr_pending <= 1'b0;
            mpr_addr_q  <= 13'd0;
        end else begin
            if (i_mpr_req) begin
                mpr_pending <= 1'b1;
                mpr_addr_q  <= i_mpr_addr;
            end
            if (mpr_clear) mpr_pending <= 1'b0;
        end
    end

    assign o_mpr_busy = mpr_pending || (state == S_MPR_RD) || (state == S_MPR_WAIT);

    // ---- MRS-rewrite latch (single-shot; cleared when FSM emits MRS) ----
    reg                       mrs_pending;
    reg [BANK_BITS-1:0]       mrs_ba_q;
    reg [ROW_BITS-1:0]        mrs_addr_q;
    reg                       mrs_clear;
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            mrs_pending <= 1'b0;
            mrs_ba_q    <= {BANK_BITS{1'b0}};
            mrs_addr_q  <= {ROW_BITS{1'b0}};
        end else begin
            if (i_mrs_req) begin
                mrs_pending <= 1'b1;
                mrs_ba_q    <= i_mrs_ba;
                mrs_addr_q  <= i_mrs_addr;
            end
            if (mrs_clear) mrs_pending <= 1'b0;
        end
    end

    assign o_mrs_busy = mrs_pending || (state == S_MRS) || (state == S_MRS_WAIT);
    reg [7:0]  beat_ctr;                   // BL8 beat counter (0..7)
    reg [7:0]  wait_ctr;                   // generic wait counter
    reg [BANK_BITS-1:0]  saved_bank;
    reg [ROW_BITS-1:0]   saved_row;
    reg [COL_BITS-1:0]   saved_col;
    reg                  saved_we;
    reg [WB_DATA_W-1:0]  saved_wdat;

    // Accept WB only in IDLE with no pending refresh.
    wire wb_accept_ok = i_init_done && (state == S_IDLE) && !ref_pending;
    assign o_wb_stall = ~wb_accept_ok;
    assign o_wb_err   = 1'b0;
    assign o_rd_capture = (state == S_DATA_RD) && (beat_ctr < READ_CAPTURE_SYS_CYCLES);
    assign o_cmd_odt = (state == S_WR) || (state == S_WAIT_CWL) ||
                       (state == S_DATA_WR) || (state == S_WR_RECOV);

    wire [WB_DATA_W-1:0] phy_rd_word;

    genvar gl, gb, gs;
    generate
        for (gl = 0; gl < NUM_BYTE_LANES; gl = gl + 1) begin : g_lane_pack
            wire [7:0] lane_byte = (gl < WB_BYTES) ? saved_wdat[gl*8 +: 8] : 8'h00;
            for (gb = 0; gb < DQ_BITS; gb = gb + 1) begin : g_bit_pack
                for (gs = 0; gs < SERDES_RATIO; gs = gs + 1) begin : g_ser_pack
                    assign o_wr_data[gl*DQ_BITS*SERDES_RATIO + gb*SERDES_RATIO + gs]
                        = lane_byte[gb];
                end
            end
        end

        for (gl = 0; gl < WB_BYTES; gl = gl + 1) begin : g_lane_unpack
            for (gb = 0; gb < 8; gb = gb + 1) begin : g_bit_unpack
                assign phy_rd_word[gl*8 + gb]
                    = i_rd_data[gl*DQ_BITS*SERDES_RATIO + gb*SERDES_RATIO];
            end
        end
    endgenerate

    // Ack each WB write/read after the BL8 command completes. This uses one
    // 32-bit word per BL8 burst, which is correct but throughput-limited.
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            state       <= S_IDLE;
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_cmd_ba    <= {BANK_BITS{1'b0}};
            o_cmd_addr  <= {ROW_BITS{1'b0}};
            o_wb_ack    <= 1'b0;
            o_wb_dat    <= {WB_DATA_W{1'b0}};
            o_wr_valid  <= 1'b0;
            beat_ctr    <= 8'd0;
            wait_ctr    <= 8'd0;
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;
            mrs_clear   <= 1'b0;
        end else begin
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_wb_ack    <= 1'b0;
            o_wr_valid  <= 1'b0;
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;
            mrs_clear   <= 1'b0;

            case (state)
                S_IDLE: begin
                    if (ref_pending) begin
                        // Refresh has higher priority than new WB / MPR / MRS requests.
                        state    <= S_REF_PRE;
                    end else if (mrs_pending) begin
                        // MRS-rewrite (cal driving MR1[7] or MR3[2]) — before MPR
                        // so cal_seq can enable MPR mode before issuing MPR reads.
                        state    <= S_MRS;
                    end else if (mpr_pending) begin
                        state    <= S_MPR_RD;
                    end else if (i_wb_cyc && i_wb_stb && !o_wb_stall) begin
                        saved_bank <= wb_bank;
                        saved_row  <= wb_row;
                        saved_col  <= wb_col;
                        saved_we   <= i_wb_we;
                        saved_wdat <= i_wb_dat;
                        state      <= S_ACT;
                    end
                end

                S_ACT: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_ACT;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= saved_row;
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_RCD;
                end

                S_WAIT_RCD: begin
                    if (wait_ctr == TRCD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= saved_we ? S_WR : S_RD;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_RD: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_READ;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= { {(ROW_BITS-COL_BITS-1){1'b0}}, 1'b0 /* A10=0 no AP */, saved_col };
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_CL;
                end

                S_WAIT_CL: begin
                    if (wait_ctr == CL_SYS - 2) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_RD;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_RD: begin
                    if (beat_ctr == READ_CAPTURE_SYS_CYCLES + READ_SETTLE_SYS_CYCLES - 1) begin
                        o_wb_dat <= i_rd_valid ? phy_rd_word : 32'hBAD0_BAD0;
                        o_wb_ack <= 1'b1;
                        beat_ctr <= 8'd0;
                        state    <= S_PRE;
                    end else begin
                        beat_ctr <= beat_ctr + 1'b1;
                    end
                end

                S_WR: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_WRITE;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= { {(ROW_BITS-COL_BITS-1){1'b0}}, 1'b0, saved_col };
                    o_wr_valid  <= 1'b1;
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_CWL;
                end

                S_WAIT_CWL: begin
                    if (wait_ctr == CWL_START_WAIT) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_WR;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_WR: begin
                    if (beat_ctr == BURST_SYS_CYCLES - 1) begin
                        o_wb_ack <= 1'b1;
                        beat_ctr <= 8'd0;
                        wait_ctr <= 8'd0;
                        state    <= S_WR_RECOV;
                    end else begin
                        beat_ctr <= beat_ctr + 1'b1;
                    end
                end

                S_WR_RECOV: begin
                    if (wait_ctr == TWR_SYS - 1) begin
                        wait_ctr <= 8'd0;
                        state    <= S_PRE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_PRE: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_PRE;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= {{(ROW_BITS-11){1'b0}}, 1'b0 /* A10=0 single bank */, 10'b0};
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_RP;
                end

                S_WAIT_RP: begin
                    if (wait_ctr == TRP_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- Refresh path ----
                S_REF_PRE: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_PRE;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    // A10 = 1 → all-bank precharge
                    o_cmd_addr  <= { {(ROW_BITS-11){1'b0}}, 1'b1, 10'b0 };
                    wait_ctr    <= 8'd0;
                    state       <= S_REF_WAIT_RP;
                end

                S_REF_WAIT_RP: begin
                    if (wait_ctr == TRP_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_REF;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_REF: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_REF;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    o_cmd_addr  <= {ROW_BITS{1'b0}};
                    wait_ctr    <= 8'd0;
                    state       <= S_REF_WAIT;
                end

                S_REF_WAIT: begin
                    if (wait_ctr == TRFC_WAIT) begin
                        wait_ctr  <= 8'd0;
                        ref_clear <= 1'b1;          // pulse to refresh scheduler
                        state     <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- MPR-read path (used by read-leveling) ----
                // No ACT, no PRE — MPR data is internal to the chip.
                // After RD with A[12]=1, wait CL cycles for data to
                // start appearing on DQ; rdlvl drives its own data
                // capture via the PHY's o_rd_valid pulse.
                S_MPR_RD: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_READ;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    // ROW_BITS-wide address; low 13 bits come from rdlvl,
                    // upper bits zero.
                    o_cmd_addr  <= { {(ROW_BITS-13){1'b0}}, mpr_addr_q };
                    mpr_clear   <= 1'b1;        // ack the request
                    wait_ctr    <= 8'd0;
                    state       <= S_MPR_WAIT;
                end

                S_MPR_WAIT: begin
                    // tCCD = 4 tCK minimum between back-to-back reads
                    // (BL8 occupies 4 tCK on the bus). After tCCD the
                    // next RD command can issue; rdlvl gates that by
                    // its own SETTLE_CYCLES + READ_LATENCY logic.
                    if (wait_ctr == TCCD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- MRS-rewrite path (used by cal_seq) ----
                S_MRS: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_MRS;
                    o_cmd_ba    <= mrs_ba_q;
                    o_cmd_addr  <= mrs_addr_q;
                    mrs_clear   <= 1'b1;
                    wait_ctr    <= 8'd0;
                    state       <= S_MRS_WAIT;
                end

                S_MRS_WAIT: begin
                    // tMOD before any non-MRS command may issue.
                    if (wait_ctr == TMOD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                default: state <= S_IDLE;
            endcase
        end
    end

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_wb_sel, ref_pending, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
