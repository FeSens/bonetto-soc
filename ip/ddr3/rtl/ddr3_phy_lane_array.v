// ddr3_phy_lane_array — replicate ddr3_phy_dq N times for the full data path.
//
// One ddr3_phy_dq per byte lane. YPCB-00338 Channel 0 has 9 byte lanes
// (8 DQ + 1 ECC), so the default NUM_BYTE_LANES=9. The legacy 1-byte
// case (NUM_BYTE_LANES=1) still works for the original test bench.
//
// Cal interface — per-lane LD pulses + shared CNTVALUEIN bus:
//
//   `i_cal_dq_load_lane[L]   one-cycle pulse → load the DQ-bit IDELAY of
//                            byte lane L whose bit position is selected by
//                            `i_cal_dq_sel` (one-hot within the lane)
//   `i_cal_dqs_load_lane[L]  one-cycle pulse → load the DQS IDELAY of L
//   `i_cal_dq_tap            5-bit IDELAY value, shared across lanes — the
//                            CAL FSM (wlvl / rdlvl) drives one lane at a
//                            time, so a shared bus is sufficient.
//
// IDELAYCTRL — one instance per clock region in real silicon. This module
// only has one for now; the iter-3b XDC adds extras via tile placement.
// The reference clock must be 200 MHz (matches REFCLK_FREQUENCY in
// ddr3_phy_dq.v's IDELAYE2 instances).

`default_nettype none

module ddr3_phy_lane_array #(
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer DQ_BITS        = 8,
    parameter integer RATIO          = 4
) (
    // -------- Clocks --------
    input  wire                              i_clk_sys,
    input  wire                              i_clk_phy_x4,
    input  wire                              i_clk_dq,
    input  wire                              i_clk_ref_200,    // IDELAYCTRL reference
    input  wire                              i_rst,

    // -------- Write side --------
    input  wire                              i_wr_en,
    input  wire [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] i_wr_data,
    input  wire                              i_wr_dqs_en,

    // -------- Read side --------
    output wire [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] o_rd_data,
    output wire [NUM_BYTE_LANES-1:0]         o_rd_valid_lane,
    output wire                              o_rd_valid_all,

    // -------- Calibration --------
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dq_load_lane,
    input  wire [DQ_BITS-1:0]                i_cal_dq_sel,     // bit within lane
    input  wire [4:0]                        i_cal_dq_tap,
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dqs_load_lane,
    input  wire [4:0]                        i_cal_dqs_tap,

    // -------- IDELAYCTRL ready output --------
    output wire                              o_idelay_ready,

    // -------- DDR3 chip-side pins --------
    inout  wire [NUM_BYTE_LANES*DQ_BITS-1:0] io_ddr3_dq,
    inout  wire [NUM_BYTE_LANES-1:0]         io_ddr3_dqs_p,
    inout  wire [NUM_BYTE_LANES-1:0]         io_ddr3_dqs_n,
    output wire [NUM_BYTE_LANES-1:0]         o_ddr3_dm
);

`ifdef BONETTO_SOC_SIM
    // Sim stub — primitives are synthesis-only.
    assign io_ddr3_dq      = {(NUM_BYTE_LANES*DQ_BITS){1'bz}};
    assign io_ddr3_dqs_p   = {NUM_BYTE_LANES{1'bz}};
    assign io_ddr3_dqs_n   = {NUM_BYTE_LANES{1'bz}};
    assign o_ddr3_dm       = {NUM_BYTE_LANES{1'b0}};
    assign o_rd_data       = {(NUM_BYTE_LANES*DQ_BITS*RATIO){1'b0}};
    assign o_rd_valid_lane = {NUM_BYTE_LANES{1'b0}};
    assign o_rd_valid_all  = 1'b0;
    assign o_idelay_ready  = ~i_rst;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_sys, i_clk_phy_x4, i_clk_dq, i_clk_ref_200,
                i_wr_en, i_wr_data, i_wr_dqs_en,
                i_cal_dq_load_lane, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_load_lane, i_cal_dqs_tap, 1'b0};
    /* verilator lint_on UNUSED */
`else
    // ---------------- IDELAYCTRL — single instance for now. ----------------
    // Production designs replicate this per clock region (clock-region
    // placement is via XDC LOC). The XDC must provide a 200 MHz reference
    // clock pin or MMCM output to drive REFCLK.
    IDELAYCTRL u_idelayctrl (
        .RDY    (o_idelay_ready),
        .REFCLK (i_clk_ref_200),
        .RST    (i_rst)
    );

    // ---------------- Per-byte-lane instances ----------------
    genvar bl;
    generate
        for (bl = 0; bl < NUM_BYTE_LANES; bl = bl + 1) begin : g_lane
            ddr3_phy_dq #(
                .DQ_BITS (DQ_BITS),
                .RATIO   (RATIO)
            ) u_lane (
                .i_clk_sys      (i_clk_sys),
                .i_clk_phy_x4   (i_clk_phy_x4),
                .i_clk_dq       (i_clk_dq),
                .i_rst          (i_rst),

                .i_wr_en        (i_wr_en),
                .i_wr_data      (i_wr_data[bl*DQ_BITS*RATIO +: DQ_BITS*RATIO]),
                .i_wr_dqs_en    (i_wr_dqs_en),

                .o_rd_data      (o_rd_data[bl*DQ_BITS*RATIO +: DQ_BITS*RATIO]),
                .o_rd_valid     (o_rd_valid_lane[bl]),

                .i_cal_dq_load  (i_cal_dq_load_lane[bl]),
                .i_cal_dq_sel   (i_cal_dq_sel),
                .i_cal_dq_tap   (i_cal_dq_tap),
                .i_cal_dqs_load (i_cal_dqs_load_lane[bl]),
                .i_cal_dqs_tap  (i_cal_dqs_tap),

                .io_ddr3_dq     (io_ddr3_dq[bl*DQ_BITS +: DQ_BITS]),
                .io_ddr3_dqs_p  (io_ddr3_dqs_p[bl]),
                .io_ddr3_dqs_n  (io_ddr3_dqs_n[bl]),
                .o_ddr3_dm      (o_ddr3_dm[bl])
            );
        end
    endgenerate

    assign o_rd_valid_all = &o_rd_valid_lane;
`endif
endmodule
