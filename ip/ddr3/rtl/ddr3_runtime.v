// ddr3_runtime — DDR3 runtime read/write FSM (post-init).
//
// Production-quality target. Iter-2.5 skeleton: ACT → RD/WR → PRE per
// transaction (no row caching), single-bank-at-a-time, hard-coded
// burst length 8. Refresh scheduler interleaved.
//
// Iter-3 refinements (TODO, marked in code):
//   * Per-bank state tracking with row caching (avoid ACT/PRE on the
//     same row twice).
//   * Command queue with bank-interleaved arbitration.
//   * Real BL8 data unpacking on a wide WB interface; right now the
//     skeleton just acks a single WB word per BL8 burst (wastes 7/8 of
//     each burst — fine for correctness, not for throughput).
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
    parameter integer DQ_BITS   = 8
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

    // -------- DDR3 DQ side (placeholder for iter-3 PHY layer) --------
    input  wire [DQ_BITS-1:0]         i_dq,           // from PHY read path
    output wire [DQ_BITS-1:0]         o_dq,           // to PHY write path
    output wire                       o_dq_oe,        // 1 = drive DQ

    // -------- MPR-read request port (iter-3c, for read-leveling) --------
    // When `i_mpr_req` pulses, the FSM emits an RD command with
    // address bits driven from `i_mpr_addr` (A[12]=1, A[2:0]=000 for
    // MPR location 0). No ACT precedes, no PRE follows — MPR data is
    // internal to the DDR3 chip, not in a row. The chip must already
    // be in MR3[2]=1 mode (programmed via the init FSM's MR3-rewrite
    // pass after standard init completes).
    input  wire                       i_mpr_req,
    input  wire [12:0]                i_mpr_addr,
    output wire                       o_mpr_busy
);
    // ---- WB address split ----
    // adr = { bank, row, col[COL_BITS-1:3] } — bottom 3 bits absorbed by BL8.
    // For WB_ADDR_W = 28 and our 15+3+10 = 28-bit DRAM address space, this fits.
    wire [BANK_BITS-1:0]        wb_bank = i_wb_adr[BANK_BITS + ROW_BITS + (COL_BITS-3) - 1 -: BANK_BITS];
    wire [ROW_BITS-1:0]         wb_row  = i_wb_adr[ROW_BITS + (COL_BITS-3) - 1            -: ROW_BITS];
    wire [COL_BITS-1:0]         wb_col  = { i_wb_adr[(COL_BITS-3)-1:0], 3'b000 };

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
            if (ref_ctr == `DDR3_TREFI - 1) begin
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
        S_MPR_WAIT  = 5'd16;

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
    reg [7:0]  beat_ctr;                   // BL8 beat counter (0..7)
    reg [7:0]  wait_ctr;                   // generic wait counter
    reg [BANK_BITS-1:0]  saved_bank;
    reg [ROW_BITS-1:0]   saved_row;
    reg [COL_BITS-1:0]   saved_col;
    reg                  saved_we;

    // Accept WB only in IDLE with no pending refresh.
    wire wb_accept_ok = i_init_done && (state == S_IDLE) && !ref_pending;
    assign o_wb_stall = ~wb_accept_ok;
    assign o_wb_err   = 1'b0;
    assign o_dq       = i_wb_dat[DQ_BITS-1:0];   // placeholder — iter-3 PHY layer
    assign o_dq_oe    = (state == S_DATA_WR);

    // For iter-2.5, we ack EACH WB write/read after the BL8 completes. This
    // wastes 7/8 of each burst; iter-3 widens the WB interface or buffers
    // multi-word transactions.
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            state       <= S_IDLE;
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_cmd_ba    <= {BANK_BITS{1'b0}};
            o_cmd_addr  <= {ROW_BITS{1'b0}};
            o_wb_ack    <= 1'b0;
            o_wb_dat    <= {WB_DATA_W{1'b0}};
            beat_ctr    <= 8'd0;
            wait_ctr    <= 8'd0;
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;
        end else begin
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_wb_ack    <= 1'b0;
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;

            case (state)
                S_IDLE: begin
                    if (ref_pending) begin
                        // Refresh has higher priority than new WB / MPR requests.
                        state    <= S_REF_PRE;
                    end else if (mpr_pending) begin
                        // MPR-read takes priority over WB during calibration.
                        state    <= S_MPR_RD;
                    end else if (i_wb_cyc && i_wb_stb && !o_wb_stall) begin
                        saved_bank <= wb_bank;
                        saved_row  <= wb_row;
                        saved_col  <= wb_col;
                        saved_we   <= i_wb_we;
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
                    if (wait_ctr == `DDR3_TRCD - 2) begin
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
                    if (wait_ctr == `DDR3_CL - 2) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_RD;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_RD: begin
                    // Iter-2.5 placeholder: read first beat into o_wb_dat,
                    // ack, then drain remaining 7 beats as NOP.
                    if (beat_ctr == 0) o_wb_dat <= {{(WB_DATA_W-DQ_BITS){1'b0}}, i_dq};
                    if (beat_ctr == `DDR3_BL - 1) begin
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
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_CWL;
                end

                S_WAIT_CWL: begin
                    if (wait_ctr == `DDR3_CWL - 2) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_WR;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_WR: begin
                    if (beat_ctr == `DDR3_BL - 1) begin
                        o_wb_ack <= 1'b1;
                        beat_ctr <= 8'd0;
                        // tWR must elapse before PRE. tWR = 12 tCK > BL8 = 4 tCK
                        // pairs, so we still need tWR-BL/2 cycles before PRE.
                        state    <= S_PRE;
                    end else begin
                        beat_ctr <= beat_ctr + 1'b1;
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
                    if (wait_ctr == `DDR3_TRP - 2) begin
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
                    if (wait_ctr == `DDR3_TRP - 2) begin
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
                    if (wait_ctr == `DDR3_TRFC - 2) begin
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
                    if (wait_ctr == `DDR3_TCCD - 1) begin
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
    wire _u = &{1'b0, i_wb_sel, i_wb_dat, ref_pending, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
