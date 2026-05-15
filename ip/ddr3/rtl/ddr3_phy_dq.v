// ddr3_phy_dq — Single byte-lane DQ + DQS path for the DDR3 PHY.
//
// Implements one "byte lane" (8 DQ bits, 1 DQS pair, 1 DM) of the
// DDR3 data path using Xilinx 7-series primitives:
//
//   Writes (4:1 SERDES, DDR-mode):
//     ctrl-side 4 bits per DQ per clk_sys cycle →
//     OSERDESE2 (DATA_RATE_OQ=DDR, MODE=MASTER, RATE=4) →
//     IOBUF_DCIEN → DQ pin
//
//     OE control via separate OSERDESE2 (TQ tristate-mode).
//
//   Writes — DQS:
//     OSERDESE2 producing a 90°-phase-shifted strobe (uses clk_dq, the
//     90° MMCM output of ddr3_phy_clock) →
//     OBUFTDS_DCIEN → DQS_P/N pin pair.
//
//   Reads (4:1 SERDES, DDR-mode):
//     DQ pin → IDELAYE2 (per-bit calibrated delay) →
//     ISERDESE2 (DATA_RATE=DDR, MODE=MASTER, RATE=4) → 4 ctrl-side bits.
//
//   Reads — DQS:
//     DQS_P/N → IBUFDS_DIFF_OUT → IDELAYE2 (gate-trained) →
//     drives ISERDESE2 strobes (CLKDIVP/CLKB).
//
// Per-bit IDELAYE2 taps default to 0. Calibration writes new tap
// values via the cal interface; iter-3b's calibration FSM lands in
// `ddr3_phy_cal.v` and trains taps for the eye centre.
//
// Sim guard: `BONETTO_SOC_SIM` stubs primitives the same way as
// ddr3_phy.v / jtag_uart.v.

`default_nettype none

module ddr3_phy_dq #(
    parameter integer DQ_BITS = 8,
    parameter integer RATIO   = 4         // OSERDESE2 / ISERDESE2 ratio
) (
    // -------- Clocks --------
    input  wire                     i_clk_sys,        // controller domain
    input  wire                     i_clk_phy_x4,     // 4× SERDES clock (= clk_sys × 4)
    input  wire                     i_clk_dq,         // 90° phase of clk_phy_x4 for DQS
    input  wire                     i_rst,

    // -------- Controller-side parallel buses (per clk_sys cycle) ----
    input  wire                     i_wr_en,          // 1 = drive DQ this cycle
    input  wire [DQ_BITS*RATIO-1:0] i_wr_data,        // 4 DDR samples per DQ bit
    input  wire                     i_wr_dqs_en,      // DQS strobe enable

    output wire [DQ_BITS*RATIO-1:0] o_rd_data,
    output wire                     o_rd_valid,

    // -------- Per-bit IDELAYE2 tap control (calibration interface) --
    input  wire                     i_cal_dq_load,    // pulse to load tap value
    input  wire [DQ_BITS-1:0]       i_cal_dq_sel,     // which DQ bit's tap to update
    input  wire [4:0]               i_cal_dq_tap,     // 5-bit IDELAY tap (0..31)
    input  wire                     i_cal_dqs_load,
    input  wire [4:0]               i_cal_dqs_tap,

    // -------- DDR3 pins --------
    inout  wire [DQ_BITS-1:0]       io_ddr3_dq,
    inout  wire                     io_ddr3_dqs_p,
    inout  wire                     io_ddr3_dqs_n,
    output wire                     o_ddr3_dm
);
    // -------- DM tied to 0 in iter-3a (no byte-mask writes yet) -----
    assign o_ddr3_dm = 1'b0;

`ifdef BONETTO_SOC_SIM
    // Sim stub — primitives not visible to Verilator without unisims.
    assign io_ddr3_dq    = {DQ_BITS{1'bz}};
    assign io_ddr3_dqs_p = 1'bz;
    assign io_ddr3_dqs_n = 1'bz;
    assign o_rd_data     = {(DQ_BITS*RATIO){1'b0}};
    assign o_rd_valid    = 1'b0;
`else
    // ===========================================================
    // Per-DQ write path: OSERDESE2 (DATA + TRISTATE) + IOBUF
    // ===========================================================
    wire [DQ_BITS-1:0] dq_out;
    wire [DQ_BITS-1:0] dq_tristate_n;
    wire [DQ_BITS-1:0] dq_in_raw;
    wire [DQ_BITS-1:0] dq_in_delayed;

    genvar i;
    generate
        for (i = 0; i < DQ_BITS; i = i + 1) begin : g_dq

            // -------- WRITE: data SERDES --------
            // OSERDESE2 takes 4 bits per clk_sys cycle (D1..D4) and
            // serialises them onto OQ at the DDR rate.
            OSERDESE2 #(
                .DATA_RATE_OQ   ("DDR"),
                .DATA_RATE_TQ   ("BUF"),
                .DATA_WIDTH     (4),
                .TRISTATE_WIDTH (1),
                .SERDES_MODE    ("MASTER"),
                .INIT_OQ        (1'b0)
            ) u_oserdes_dq (
                .OQ      (dq_out[i]),
                .TQ      (dq_tristate_n[i]),
                .CLK     (i_clk_phy_x4),
                .CLKDIV  (i_clk_sys),
                .D1      (i_wr_data[i*4 + 0]),
                .D2      (i_wr_data[i*4 + 1]),
                .D3      (i_wr_data[i*4 + 2]),
                .D4      (i_wr_data[i*4 + 3]),
                .D5      (1'b0), .D6 (1'b0), .D7 (1'b0), .D8 (1'b0),
                .T1      (~i_wr_en),
                .T2      (1'b0), .T3 (1'b0), .T4 (1'b0),
                .TCE     (1'b1),
                .OCE     (1'b1),
                .RST     (i_rst),
                .SHIFTIN1(1'b0), .SHIFTIN2(1'b0),
                .TBYTEIN (1'b0)
            );

            // -------- READ: IDELAYE2 (per-bit tuned delay) ----------
            IDELAYE2 #(
                .IDELAY_TYPE   ("VAR_LOAD"),
                .IDELAY_VALUE  (0),
                .DELAY_SRC     ("IDATAIN"),
                .HIGH_PERFORMANCE_MODE ("TRUE"),
                .SIGNAL_PATTERN ("DATA"),
                .REFCLK_FREQUENCY (200.0),
                .CINVCTRL_SEL  ("FALSE"),
                .PIPE_SEL      ("FALSE")
            ) u_idelay_dq (
                .DATAOUT (dq_in_delayed[i]),
                .IDATAIN (dq_in_raw[i]),
                .DATAIN  (1'b0),
                .C       (i_clk_sys),
                .CE      (1'b0),
                .INC     (1'b0),
                .LD      (i_cal_dq_load & i_cal_dq_sel[i]),
                .LDPIPEEN(1'b0),
                .REGRST  (i_rst),
                .CNTVALUEIN (i_cal_dq_tap),
                .CNTVALUEOUT(),
                .CINVCTRL (1'b0)
            );

            // -------- READ: data SERDES --------
            wire [3:0] rd_bits;
            ISERDESE2 #(
                .DATA_RATE      ("DDR"),
                .DATA_WIDTH     (4),
                .INTERFACE_TYPE ("NETWORKING"),
                .NUM_CE         (1),
                .SERDES_MODE    ("MASTER"),
                .IOBDELAY       ("IFD")
            ) u_iserdes_dq (
                .Q1       (rd_bits[0]),
                .Q2       (rd_bits[1]),
                .Q3       (rd_bits[2]),
                .Q4       (rd_bits[3]),
                .Q5       (), .Q6 (), .Q7 (), .Q8 (),
                .CLK      (i_clk_phy_x4),
                .CLKB     (~i_clk_phy_x4),
                .CLKDIV   (i_clk_sys),
                .CLKDIVP  (1'b0),
                .CE1      (1'b1),
                .CE2      (1'b0),
                .OCLK     (1'b0), .OCLKB (1'b0),
                .DDLY     (dq_in_delayed[i]),
                .D        (1'b0),
                .BITSLIP  (1'b0),
                .RST      (i_rst),
                .DYNCLKDIVSEL (1'b0),
                .DYNCLKSEL    (1'b0),
                .O        (),
                .SHIFTIN1 (1'b0), .SHIFTIN2 (1'b0),
                .SHIFTOUT1(), .SHIFTOUT2 (),
                .OFB      (1'b0)
            );

            assign o_rd_data[i*4 +: 4] = rd_bits;

            // -------- IOBUF for the DQ pad ----------
            IOBUFDS_DCIEN #(.SLEW("FAST")) u_dq_iobuf (
                .O   (dq_in_raw[i]),
                .IO  (io_ddr3_dq[i]),
                .IOB (),
                .I   (dq_out[i]),
                .T   (dq_tristate_n[i]),
                .IBUFDISABLE (1'b0),
                .DCITERMDISABLE (1'b0)
            );
        end
    endgenerate

    // ===========================================================
    // DQS — single differential strobe per byte lane
    // ===========================================================
    wire dqs_out, dqs_tristate_n;
    wire dqs_in_raw, dqs_in_delayed;

    OSERDESE2 #(
        .DATA_RATE_OQ   ("DDR"),
        .DATA_RATE_TQ   ("BUF"),
        .DATA_WIDTH     (4),
        .TRISTATE_WIDTH (1),
        .SERDES_MODE    ("MASTER"),
        .INIT_OQ        (1'b0)
    ) u_oserdes_dqs (
        .OQ      (dqs_out),
        .TQ      (dqs_tristate_n),
        .CLK     (i_clk_dq),          // 90° shifted clock
        .CLKDIV  (i_clk_sys),
        .D1      (1'b0), .D2 (1'b1),
        .D3      (1'b0), .D4 (1'b1),
        .D5      (1'b0), .D6 (1'b0), .D7 (1'b0), .D8 (1'b0),
        .T1      (~i_wr_dqs_en),
        .T2      (1'b0), .T3 (1'b0), .T4 (1'b0),
        .TCE     (1'b1),
        .OCE     (1'b1),
        .RST     (i_rst),
        .SHIFTIN1(1'b0), .SHIFTIN2 (1'b0),
        .TBYTEIN (1'b0)
    );

    IOBUFDS_DCIEN #(.SLEW("FAST")) u_dqs_iobuf (
        .O   (dqs_in_raw),
        .IO  (io_ddr3_dqs_p),
        .IOB (io_ddr3_dqs_n),
        .I   (dqs_out),
        .T   (dqs_tristate_n),
        .IBUFDISABLE (1'b0),
        .DCITERMDISABLE (1'b0)
    );

    IDELAYE2 #(
        .IDELAY_TYPE   ("VAR_LOAD"),
        .IDELAY_VALUE  (0),
        .DELAY_SRC     ("IDATAIN"),
        .HIGH_PERFORMANCE_MODE ("TRUE"),
        .SIGNAL_PATTERN ("CLOCK"),
        .REFCLK_FREQUENCY (200.0),
        .CINVCTRL_SEL  ("FALSE"),
        .PIPE_SEL      ("FALSE")
    ) u_idelay_dqs (
        .DATAOUT (dqs_in_delayed),
        .IDATAIN (dqs_in_raw),
        .DATAIN  (1'b0),
        .C       (i_clk_sys),
        .CE      (1'b0),
        .INC     (1'b0),
        .LD      (i_cal_dqs_load),
        .LDPIPEEN(1'b0),
        .REGRST  (i_rst),
        .CNTVALUEIN (i_cal_dqs_tap),
        .CNTVALUEOUT(),
        .CINVCTRL(1'b0)
    );

    assign o_rd_valid = 1'b0;   // iter-3b: gate-train signal lights this

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, dqs_in_delayed, 1'b0};
    /* verilator lint_on UNUSED */
`endif
endmodule
