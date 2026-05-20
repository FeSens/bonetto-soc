// Route-only DDR3 DQ/DQS I/O-shell probe for YPCB-00338.
//
// This top intentionally holds the DDR3 devices in reset with CKE low. It is
// not a controller image and has no program target. Its purpose is to keep the
// next PHY step honest: route the tiny 7-series DQ/DQS primitive shell at the
// DDR3-800 bit clock before attaching any wide controller or lane fabric.

`default_nettype none

module top_ddr3_dq_dqs_iobuf_probe (
    input  wire        SYS_CLK,
    input  wire        SYS_RSTN,
    output wire [2:0]  led_3bits_tri_o,

    output wire [14:0] ddr3_addr,
    output wire [2:0]  ddr3_ba,
    output wire        ddr3_ras_n,
    output wire        ddr3_cas_n,
    output wire        ddr3_we_n,
    output wire        ddr3_cs_n,
    output wire        ddr3_cke,
    output wire        ddr3_odt,
    output wire        ddr3_reset_n,
    output wire        ddr3_ck_p,
    output wire        ddr3_ck_n,
    inout  wire [71:0] ddr3_dq,
    inout  wire [8:0]  ddr3_dqs_p,
    inout  wire [8:0]  ddr3_dqs_n,

    output wire [14:0] ddr3_ch1_addr,
    output wire [2:0]  ddr3_ch1_ba,
    output wire        ddr3_ch1_ras_n,
    output wire        ddr3_ch1_cas_n,
    output wire        ddr3_ch1_we_n,
    output wire        ddr3_ch1_cs_n,
    output wire        ddr3_ch1_cke,
    output wire        ddr3_ch1_odt,
    output wire        ddr3_ch1_reset_n,
    output wire        ddr3_ch1_ck_p,
    output wire        ddr3_ch1_ck_n,
    inout  wire [71:0] ddr3_ch1_dq,
    inout  wire [8:0]  ddr3_ch1_dqs_p,
    inout  wire [8:0]  ddr3_ch1_dqs_n
);
    localparam [71:0] DQ_RISE_CH0 = 72'h55_AA_33_CC_0F_F0_96_69_5A;
    localparam [71:0] DQ_RISE_CH1 = 72'hA5_5A_C3_3C_F0_0F_69_96_A6;

    wire clk_sys;
    wire clk_ddr;
    wire clk_dq;
    wire pll_locked;

    ddr3_800_clocking u_clocking (
        .i_clk_50(SYS_CLK),
        .i_rst(!SYS_RSTN),
        .o_clk_sys(clk_sys),
        .o_clk_ddr(clk_ddr),
        .o_clk_dq(clk_dq),
        .o_locked(pll_locked)
    );

    reg [2:0] pll_locked_dq_sr = 3'b000;
    always @(posedge clk_dq) begin
        pll_locked_dq_sr <= {pll_locked_dq_sr[1:0], pll_locked};
    end
    wire pll_locked_dq = pll_locked_dq_sr[2];

    reg [4:0] rst_dq_sr = 5'b1_1111;
    always @(posedge clk_dq) begin
        if (!pll_locked_dq)
            rst_dq_sr <= 5'b1_1111;
        else
            rst_dq_sr <= {rst_dq_sr[3:0], 1'b0};
    end
    wire rst_dq = rst_dq_sr[4];

    ddr3_ck_out_7series u_ck_ch0 (
        .i_clk_ddr(clk_ddr),
        .i_rst(rst_dq),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    ddr3_ck_out_7series u_ck_ch1 (
        .i_clk_ddr(clk_ddr),
        .i_rst(rst_dq),
        .o_ck_p(ddr3_ch1_ck_p),
        .o_ck_n(ddr3_ch1_ck_n)
    );

    assign ddr3_addr       = 15'd0;
    assign ddr3_ba         = 3'd0;
    assign ddr3_ras_n      = 1'b1;
    assign ddr3_cas_n      = 1'b1;
    assign ddr3_we_n       = 1'b1;
    assign ddr3_cs_n       = 1'b1;
    assign ddr3_cke        = 1'b0;
    assign ddr3_odt        = 1'b0;
    assign ddr3_reset_n    = 1'b0;

    assign ddr3_ch1_addr    = 15'd0;
    assign ddr3_ch1_ba      = 3'd0;
    assign ddr3_ch1_ras_n   = 1'b1;
    assign ddr3_ch1_cas_n   = 1'b1;
    assign ddr3_ch1_we_n    = 1'b1;
    assign ddr3_ch1_cs_n    = 1'b1;
    assign ddr3_ch1_cke     = 1'b0;
    assign ddr3_ch1_odt     = 1'b0;
    assign ddr3_ch1_reset_n = 1'b0;

    wire [8:0] dq_oe_ch0 = rst_dq ? 9'h000 : 9'h1ff;
    wire [8:0] dq_oe_ch1 = rst_dq ? 9'h000 : 9'h1ff;
    wire [71:0] dq_fall_ch0 = ~DQ_RISE_CH0;
    wire [71:0] dq_fall_ch1 = ~DQ_RISE_CH1;
    wire [8:0] dqs_rise_ch0 = 9'h1ff;
    wire [8:0] dqs_fall_ch0 = 9'h000;
    wire [8:0] dqs_rise_ch1 = 9'h1ff;
    wire [8:0] dqs_fall_ch1 = 9'h000;

    wire [71:0] dq_sample_rise_ch0;
    wire [71:0] dq_sample_fall_ch0;
    wire [8:0] dqs_sample_rise_ch0;
    wire [8:0] dqs_sample_fall_ch0;
    wire [71:0] dq_sample_rise_ch1;
    wire [71:0] dq_sample_fall_ch1;
    wire [8:0] dqs_sample_rise_ch1;
    wire [8:0] dqs_sample_fall_ch1;

    ddr3_dq_dqs_io_7series u_dq_dqs_ch0 (
        .i_clk_dq(clk_dq),
        .i_rst(rst_dq),
        .i_dq_oe(dq_oe_ch0),
        .i_dqs_oe(dq_oe_ch0),
        .i_dq_rise(DQ_RISE_CH0),
        .i_dq_fall(dq_fall_ch0),
        .i_dqs_rise(dqs_rise_ch0),
        .i_dqs_fall(dqs_fall_ch0),
        .o_dq_rise(dq_sample_rise_ch0),
        .o_dq_fall(dq_sample_fall_ch0),
        .o_dqs_rise(dqs_sample_rise_ch0),
        .o_dqs_fall(dqs_sample_fall_ch0),
        .io_dq(ddr3_dq),
        .io_dqs_p(ddr3_dqs_p),
        .io_dqs_n(ddr3_dqs_n)
    );

    ddr3_dq_dqs_io_7series u_dq_dqs_ch1 (
        .i_clk_dq(clk_dq),
        .i_rst(rst_dq),
        .i_dq_oe(dq_oe_ch1),
        .i_dqs_oe(dq_oe_ch1),
        .i_dq_rise(DQ_RISE_CH1),
        .i_dq_fall(dq_fall_ch1),
        .i_dqs_rise(dqs_rise_ch1),
        .i_dqs_fall(dqs_fall_ch1),
        .o_dq_rise(dq_sample_rise_ch1),
        .o_dq_fall(dq_sample_fall_ch1),
        .o_dqs_rise(dqs_sample_rise_ch1),
        .o_dqs_fall(dqs_sample_fall_ch1),
        .io_dq(ddr3_ch1_dq),
        .io_dqs_p(ddr3_ch1_dqs_p),
        .io_dqs_n(ddr3_ch1_dqs_n)
    );

    wire sample_mix = ^{dq_sample_rise_ch0, dq_sample_fall_ch0,
                        dqs_sample_rise_ch0, dqs_sample_fall_ch0,
                        dq_sample_rise_ch1, dq_sample_fall_ch1,
                        dqs_sample_rise_ch1, dqs_sample_fall_ch1};

    assign led_3bits_tri_o = {sample_mix, !rst_dq, pll_locked};

    wire _unused = &{1'b0, clk_sys, 1'b0};
endmodule

`default_nettype wire
