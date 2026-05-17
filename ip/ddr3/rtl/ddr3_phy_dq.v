// ddr3_phy_dq — Single byte-lane DQ + DQS path for the DDR3 PHY.
//
// Iter-4 (HR-bank compatible): YPCB-00338's DDR3 DQS pins land on HR
// (high-range) banks of the xc7k480t — these don't support ODELAYE2.
// Write-leveling per JEDEC requires sweeping DQS output delay, so on
// this board we accept fixed 90° DQS-vs-CK timing from `clk_dq` (the
// MMCM's +90° output) and skip programmable DQS-out delay entirely.
//
// The cal interface still exposes DQS-out load/tap/toggle_en ports so
// upstream FSMs (wlvl) stay protocol-compatible; the load/tap inputs
// are simply ignored. The toggle_en still gates the OSERDESE2 T1 so
// wlvl-mode DQS toggling (for the future MMCM-phase-shift wlvl path)
// is possible without spurious lane interactions.
//
// DQ INPUT path: per-bit IDELAYE2 (rdlvl).
// DQS INPUT path: per-lane IDELAYE2 (rdlvl, gate-train).
// DQ OUTPUT path: direct from OSERDESE2 (no delay).
// DQS OUTPUT path: direct from OSERDESE2 on clk_dq (no programmable delay).

`default_nettype none

module ddr3_phy_dq #(
    parameter integer DQ_BITS = 8,
    parameter integer RATIO   = 4
) (
    input  wire                     i_clk_sys,
    input  wire                     i_clk_phy_x4,
    input  wire                     i_clk_dq,
    input  wire                     i_rst,

    input  wire                     i_wr_en,
    input  wire [DQ_BITS*RATIO-1:0] i_wr_data,
    input  wire                     i_wr_dqs_en,

    output wire [DQ_BITS*RATIO-1:0] o_rd_data,
    output wire                     o_rd_valid,

    input  wire                     i_cal_dq_load,
    input  wire [DQ_BITS-1:0]       i_cal_dq_sel,
    input  wire [4:0]               i_cal_dq_tap,

    input  wire                     i_cal_dqs_in_load,
    input  wire [4:0]               i_cal_dqs_in_tap,

    // DQS-out cal interface kept for source-compat — ignored on HR banks.
    input  wire                     i_cal_dqs_out_load,
    input  wire [4:0]               i_cal_dqs_out_tap,
    input  wire                     i_cal_dqs_toggle_en,

    inout  wire [DQ_BITS-1:0]       io_ddr3_dq,
    inout  wire                     io_ddr3_dqs_p,
    inout  wire                     io_ddr3_dqs_n,
    output wire                     o_ddr3_dm
);
    assign o_ddr3_dm = 1'b0;

`ifdef BONETTO_SOC_SIM
    assign io_ddr3_dq    = {DQ_BITS{1'bz}};
    assign io_ddr3_dqs_p = 1'bz;
    assign io_ddr3_dqs_n = 1'bz;
    assign o_rd_data     = {(DQ_BITS*RATIO){1'b0}};
    assign o_rd_valid    = 1'b0;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_sys, i_clk_phy_x4, i_clk_dq, i_rst,
                i_wr_en, i_wr_data, i_wr_dqs_en,
                i_cal_dq_load, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_in_load, i_cal_dqs_in_tap,
                i_cal_dqs_out_load, i_cal_dqs_out_tap, i_cal_dqs_toggle_en,
                1'b0};
    /* verilator lint_on UNUSED */
`else
    wire [DQ_BITS-1:0] dq_out;
    wire [DQ_BITS-1:0] dq_tristate_n;
    wire [DQ_BITS-1:0] dq_in_raw;
    wire [DQ_BITS-1:0] dq_in_delayed;

    genvar i;
    generate
        for (i = 0; i < DQ_BITS; i = i + 1) begin : g_dq

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
                .OCLK     (i_clk_phy_x4), .OCLKB (i_clk_phy_x4),
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

            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O  (dq_in_raw[i]),
                .IO (io_ddr3_dq[i]),
                .I  (dq_out[i]),
                .T  (dq_tristate_n[i])
            );
        end
    endgenerate

    // ===========================================================
    // DQS — differential strobe per byte lane.
    // No ODELAYE2 (HR-bank-only constraint on YPCB-00338).
    // DQS-out timing is fixed at 90° from CK via clk_dq.
    // ===========================================================
    wire dqs_out, dqs_tristate_n;
    wire dqs_in_raw, dqs_in_delayed;

    wire dqs_drive = i_wr_dqs_en | i_cal_dqs_toggle_en;

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
        .CLK     (i_clk_dq),
        .CLKDIV  (i_clk_sys),
        .D1      (1'b0), .D2 (1'b1),
        .D3      (1'b0), .D4 (1'b1),
        .D5      (1'b0), .D6 (1'b0), .D7 (1'b0), .D8 (1'b0),
        .T1      (~dqs_drive),
        .T2      (1'b0), .T3 (1'b0), .T4 (1'b0),
        .TCE     (1'b1),
        .OCE     (1'b1),
        .RST     (i_rst),
        .SHIFTIN1(1'b0), .SHIFTIN2 (1'b0),
        .TBYTEIN (1'b0)
    );

    IOBUFDS #(.SLEW("FAST")) u_dqs_iobuf (
        .O   (dqs_in_raw),
        .IO  (io_ddr3_dqs_p),
        .IOB (io_ddr3_dqs_n),
        .I   (dqs_out),
        .T   (dqs_tristate_n)
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
        .LD      (i_cal_dqs_in_load),
        .LDPIPEEN(1'b0),
        .REGRST  (i_rst),
        .CNTVALUEIN (i_cal_dqs_in_tap),
        .CNTVALUEOUT(),
        .CINVCTRL(1'b0)
    );

    assign o_rd_valid = 1'b0;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, dqs_in_delayed,
                i_cal_dqs_out_load, i_cal_dqs_out_tap, 1'b0};
    /* verilator lint_on UNUSED */
`endif
endmodule
