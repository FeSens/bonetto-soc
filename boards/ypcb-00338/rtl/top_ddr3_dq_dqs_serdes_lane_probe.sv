// Route-only single-lane DDR3 SERDES primitive probe.
//
// This diagnostic target keeps the real CH0 lane-0 DQ/DQS package pins, but
// does not expose the rest of the dual-channel DQ/DQS bus. It separates the
// x8 OSERDESE2/ISERDESE2/IDELAYE2 lane route from unrelated inactive DDR3 pads.

`default_nettype none

`ifndef DDR3_SERDES_ENABLE_TX
`define DDR3_SERDES_ENABLE_TX 1
`endif

`ifndef DDR3_SERDES_ENABLE_RX
`define DDR3_SERDES_ENABLE_RX 1
`endif

`ifndef DDR3_SERDES_USE_IDELAY
`define DDR3_SERDES_USE_IDELAY 1
`endif

module top_ddr3_dq_dqs_serdes_lane_probe (
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
    inout  wire [7:0]  ddr3_dq,
    inout  wire [0:0]  ddr3_dqs_p,
    inout  wire [0:0]  ddr3_dqs_n
);
    wire clk_sys;
    wire clk_ddr;
    wire clk_dq;
    wire clk_idelay_ref;
    wire pll_locked;
    wire idelay_ready;
    localparam integer USE_IDELAYCTRL =
        (`DDR3_SERDES_ENABLE_RX != 0) && (`DDR3_SERDES_USE_IDELAY != 0);

    ddr3_800_clocking u_clocking (
        .i_clk_50(SYS_CLK),
        .i_rst(!SYS_RSTN),
        .o_clk_sys(clk_sys),
        .o_clk_ddr(clk_ddr),
        .o_clk_dq(clk_dq),
        .o_clk_idelay_ref(clk_idelay_ref),
        .o_locked(pll_locked)
    );

    generate
        if (USE_IDELAYCTRL != 0) begin : gen_idelayctrl
            ddr3_idelayctrl_7series u_idelayctrl (
                .i_clk_ref(clk_idelay_ref),
                .i_rst(!pll_locked || !SYS_RSTN),
                .o_ready(idelay_ready)
            );
        end else begin : gen_no_idelayctrl
            assign idelay_ready = 1'b1;
        end
    endgenerate

    ddr3_ck_out_7series u_ck_ch0 (
        .i_clk_ddr(clk_ddr),
        .i_rst(1'b0),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    assign ddr3_addr    = 15'd0;
    assign ddr3_ba      = 3'd0;
    assign ddr3_ras_n   = 1'b1;
    assign ddr3_cas_n   = 1'b1;
    assign ddr3_we_n    = 1'b1;
    assign ddr3_cs_n    = 1'b1;
    assign ddr3_cke     = 1'b0;
    assign ddr3_odt     = 1'b0;
    assign ddr3_reset_n = 1'b0;

    reg [7:0] pattern_ctr = 8'd0;
    reg [23:0] led_ctr = 24'd0;

    always @(posedge clk_sys) begin
        pattern_ctr <= pattern_ctr + 8'd1;
        led_ctr <= led_ctr + 24'd1;
    end

    wire [63:0] dq_bits = {
        (pattern_ctr ^ 8'h87),
        (pattern_ctr ^ 8'h69),
        (pattern_ctr ^ 8'h5a),
        (pattern_ctr ^ 8'h3c),
        (pattern_ctr ^ 8'hc3),
        (pattern_ctr ^ 8'ha5),
        (pattern_ctr ^ 8'h96),
        (pattern_ctr ^ 8'h78)
    };

    wire [63:0] rd_bits;
    wire [7:0] rd_dqs_bits;
    wire route_rst = !pll_locked || !idelay_ready;
    wire [3:0] burst_oe = {4{pll_locked && idelay_ready && SYS_RSTN}};

    ddr3_x8_serdes_io_7series #(
        .ENABLE_TX(`DDR3_SERDES_ENABLE_TX),
        .ENABLE_RX(`DDR3_SERDES_ENABLE_RX),
        .USE_IDELAY(`DDR3_SERDES_USE_IDELAY)
    ) u_serdes_lane0 (
        .i_clk_serdes(clk_dq),
        .i_clk_div(clk_sys),
        .i_rst(route_rst),
        .i_dq_bits(dq_bits),
        .i_dqs_bits(8'b0101_0101),
        .i_dq_oe(burst_oe),
        .i_dqs_oe(burst_oe),
        .i_bitslip(1'b0),
        .o_dq_bits(rd_bits),
        .o_dqs_bits(rd_dqs_bits),
        .io_dq(ddr3_dq),
        .io_dqs_p(ddr3_dqs_p[0]),
        .io_dqs_n(ddr3_dqs_n[0])
    );

    reg rd_mix = 1'b0;
    always @(posedge clk_sys) begin
        rd_mix <= ^rd_bits ^ ^rd_dqs_bits;
    end

    assign led_3bits_tri_o = {rd_mix, idelay_ready, pll_locked};
endmodule

`default_nettype wire
