// ddr3_ctrl — DDR3 memory controller.
//
// Current scope:
//   * Wishbone B4 pipelined slave port (locked in iter-1 — same set as
//     `wb_memory` so the board top swaps one for the other with no other
//     RTL changes).
//   * ddr3_init.v drives the DDR3 command bus through power-up.
//   * ddr3_runtime.v handles post-init ACT -> RD/WR -> PRE transactions,
//     BL8 data movement, and refresh-priority arbitration.
//   * The PHY-facing data path is parameterized by byte lane count, per-lane
//     DQ width, and SERDES ratio.
//
// Deliberately out of current scope: row caching, command reordering, ECC,
// multi-rank support, and a vendor-independent PHY wrapper.
//
// Per INVARIANTS #4, the WB port set NEVER changes. New parameters can
// be added; signal names cannot be renamed.

`default_nettype none

`include "ddr3_params.vh"
`include "ddr3_cmd.vh"

module ddr3_ctrl #(
    parameter integer WB_DATA_W   = 32,
    parameter integer WB_ADDR_W   = 28,                  // word-aligned within the DDR3 window
    parameter         DDR3_PART   = "MT41K256M8DA-125",
    parameter integer SPEED_GRADE = 1600,
    parameter integer ROW_BITS    = `DDR3_ROW_BITS,
    parameter integer BANK_BITS   = `DDR3_BANK_BITS,
    parameter integer COL_BITS    = `DDR3_COL_BITS,
    parameter integer DQ_BITS     = 8,                   // per-chip DQ width
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer SERDES_RATIO   = 4,
    parameter integer WB_BURST_WORD_BITS = 0,
    parameter integer BURST_WRITE_RMW = 1,
    parameter integer BROADCAST_WRITE_SAMPLES = 0,
    parameter [NUM_BYTE_LANES*4-1:0] RD_SAMPLE_OFFSET_MAP = {NUM_BYTE_LANES{4'd0}},
    parameter [NUM_BYTE_LANES*4-1:0] WR_SAMPLE_OFFSET_MAP = {NUM_BYTE_LANES{4'd0}}
) (
    input  wire                     i_clk,               // SoC clock (50 MHz on YPCB-00338)
    input  wire                     i_clk_phy,           // DDR3 command clock
    input  wire                     i_rst,

    // -------- Wishbone B4 pipelined slave (locked port set) --------
    input  wire                     i_wb_cyc,
    input  wire                     i_wb_stb,
    input  wire                     i_wb_we,
    input  wire [WB_ADDR_W-1:0]     i_wb_adr,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]   i_wb_sel,
    output wire                     o_wb_stall,
    output reg                      o_wb_ack,
    output reg  [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err,

    // -------- DDR3 chip-facing pins --------
    output wire                     o_ddr3_reset_n,
    output wire                     o_ddr3_cke,
    output wire                     o_ddr3_odt,
    output wire                     o_ddr3_cs_n,
    output wire                     o_ddr3_ras_n,
    output wire                     o_ddr3_cas_n,
    output wire                     o_ddr3_we_n,
    output wire [BANK_BITS-1:0]     o_ddr3_ba,
    output wire [ROW_BITS-1:0]      o_ddr3_addr,

    // -------- PHY data path --------
    input  wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] i_phy_rd_data,
    input  wire                     i_phy_rd_valid,
    output wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] o_phy_wr_data,
    output wire                     o_phy_wr_valid,
    output wire                     o_phy_rd_capture,

    // -------- MPR-read interface (for ddr3_phy_rdlvl, board-level wiring) -----
    // The PHY's read-leveling FSM pulses i_mpr_req with the desired
    // MPR address; ctrl forwards to ddr3_runtime which emits an RD on
    // the command bus. o_mpr_busy is high while a request is queued
    // or being serviced.
    input  wire                     i_mpr_req,
    input  wire [12:0]              i_mpr_addr,
    output wire                     o_mpr_busy,

    // -------- MRS-rewrite interface (iter-8, for cal_seq) -----
    // cal_seq pulses i_mrs_req with the target MR (via i_mrs_ba) and
    // payload (via i_mrs_addr) to toggle write-leveling or MPR modes
    // mid-calibration. Forwarded directly to the runtime FSM.
    input  wire                     i_mrs_req,
    input  wire [BANK_BITS-1:0]     i_mrs_ba,
    input  wire [ROW_BITS-1:0]      i_mrs_addr,
    output wire                     o_mrs_busy,

    // -------- Status (for host / debug) --------
    output wire                     o_init_done,
    output wire                     o_init_error,
    output wire [3:0]               o_init_error_code,
    output wire [4:0]               o_init_state
);

    // -------- Wishbone error tied off, no faults raised in iter-2 --------
    assign o_wb_err = 1'b0;

    // ---------------- Init FSM ----------------
    wire [3:0]            init_cmd;       // {cs_n, ras_n, cas_n, we_n}
    wire [BANK_BITS-1:0]  init_ba;
    wire [ROW_BITS-1:0]   init_addr;
    wire                  init_reset_n;
    wire                  init_cke;
    wire                  init_odt;

    ddr3_init #(
        .ROW_BITS (ROW_BITS),
        .BANK_BITS(BANK_BITS),
        .CMD_BITS (4)
    ) u_init (
        .i_clk_phy        (i_clk_phy),
        .i_rst            (i_rst),
        .o_ddr3_reset_n   (init_reset_n),
        .o_ddr3_cke       (init_cke),
        .o_ddr3_odt       (init_odt),
        .o_ddr3_cmd       (init_cmd),
        .o_ddr3_ba        (init_ba),
        .o_ddr3_addr      (init_addr),
        .o_init_done      (o_init_done),
        .o_init_error     (o_init_error),
        .o_init_error_code(o_init_error_code),
        .o_state          (o_init_state)
    );

    // ---------------- Runtime FSM ----------------
    // Once init_done is high, the runtime FSM owns the command bus.
    // ACT -> RD/WR -> PRE per transaction with refresh interleaving.
    wire [3:0]            rt_cmd;
    wire [BANK_BITS-1:0]  rt_ba;
    wire [ROW_BITS-1:0]   rt_addr;
    wire                  rt_cmd_valid;
    wire                  rt_reset_n   = 1'b1;
    wire                  rt_cke       = 1'b1;
    wire                  rt_odt;

    wire                  rt_wb_stall;
    wire                  rt_wb_ack;
    wire [WB_DATA_W-1:0]  rt_wb_dat;
    wire                  rt_wb_err;

    ddr3_runtime #(
        .WB_DATA_W (WB_DATA_W),
        .WB_ADDR_W (WB_ADDR_W),
        .ROW_BITS  (ROW_BITS),
        .BANK_BITS (BANK_BITS),
        .COL_BITS  (COL_BITS),
        .DQ_BITS   (DQ_BITS),
        .NUM_BYTE_LANES (NUM_BYTE_LANES),
        .SERDES_RATIO   (SERDES_RATIO),
        .WB_BURST_WORD_BITS (WB_BURST_WORD_BITS),
        .BURST_WRITE_RMW (BURST_WRITE_RMW),
        .BROADCAST_WRITE_SAMPLES (BROADCAST_WRITE_SAMPLES),
        .RD_SAMPLE_OFFSET_MAP (RD_SAMPLE_OFFSET_MAP),
        .WR_SAMPLE_OFFSET_MAP (WR_SAMPLE_OFFSET_MAP)
    ) u_runtime (
        .i_clk_phy   (i_clk_phy),
        .i_rst       (i_rst),
        .i_init_done (o_init_done),

        .i_wb_cyc    (i_wb_cyc),
        .i_wb_stb    (i_wb_stb),
        .i_wb_we     (i_wb_we),
        .i_wb_adr    (i_wb_adr),
        .i_wb_dat    (i_wb_dat),
        .i_wb_sel    (i_wb_sel),
        .o_wb_stall  (rt_wb_stall),
        .o_wb_ack    (rt_wb_ack),
        .o_wb_dat    (rt_wb_dat),
        .o_wb_err    (rt_wb_err),

        .o_cmd_valid (rt_cmd_valid),
        .o_cmd       (rt_cmd),
        .o_cmd_ba    (rt_ba),
        .o_cmd_addr  (rt_addr),
        .o_cmd_odt   (rt_odt),

        .i_rd_data   (i_phy_rd_data),
        .i_rd_valid  (i_phy_rd_valid),
        .o_wr_data   (o_phy_wr_data),
        .o_wr_valid  (o_phy_wr_valid),
        .o_rd_capture(o_phy_rd_capture),

        .i_mpr_req   (i_mpr_req),
        .i_mpr_addr  (i_mpr_addr),
        .o_mpr_busy  (o_mpr_busy),

        .i_mrs_req   (i_mrs_req),
        .i_mrs_ba    (i_mrs_ba),
        .i_mrs_addr  (i_mrs_addr),
        .o_mrs_busy  (o_mrs_busy)
    );

    // ---------------- Command bus mux ----------------
    // init owns the bus until init_done; runtime FSM after.
    wire [3:0] sel_cmd      = o_init_done ? rt_cmd      : init_cmd;
    wire       sel_reset_n  = o_init_done ? rt_reset_n  : init_reset_n;
    wire       sel_cke      = o_init_done ? rt_cke      : init_cke;
    wire       sel_odt      = o_init_done ? rt_odt      : init_odt;
    wire [BANK_BITS-1:0] sel_ba   = o_init_done ? rt_ba   : init_ba;
    wire [ROW_BITS-1:0]  sel_addr = o_init_done ? rt_addr : init_addr;

    assign {o_ddr3_cs_n, o_ddr3_ras_n, o_ddr3_cas_n, o_ddr3_we_n} = sel_cmd;
    assign o_ddr3_reset_n = sel_reset_n;
    assign o_ddr3_cke     = sel_cke;
    assign o_ddr3_odt     = sel_odt;
    assign o_ddr3_ba      = sel_ba;
    assign o_ddr3_addr    = sel_addr;

    // ---------------- Wishbone slave routing ----------------
    // Pre-init: front-end stalls everything.
    // Post-init: ddr3_runtime owns the WB responses.
    assign o_wb_stall = (~o_init_done) | rt_wb_stall;

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_wb_ack <= 1'b0;
            o_wb_dat <= {WB_DATA_W{1'b0}};
        end else begin
            o_wb_ack <= rt_wb_ack;
            o_wb_dat <= rt_wb_dat;
        end
    end

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_we, i_wb_adr, i_wb_dat, i_wb_sel,
                     DDR3_PART[0], SPEED_GRADE[0], COL_BITS[0],
                     DQ_BITS[0], NUM_BYTE_LANES[0], SERDES_RATIO[0], 1'b0};
    /* verilator lint_on UNUSED */
endmodule
