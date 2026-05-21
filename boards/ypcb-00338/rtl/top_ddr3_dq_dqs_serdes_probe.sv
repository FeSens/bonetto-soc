// Route-only full-bus DDR3 SERDES primitive probe.
//
// Both DDR3 devices are held reset/CKE-low. This image does not perform memory
// transactions. It proves that all physical DQ/DQS pins can be occupied by the
// intended 7-series OSERDESE2/ISERDESE2/IDELAYE2 shell at the DDR3-800 clocks.

`default_nettype none

`ifndef DDR3_SERDES_ACTIVE_LANES
`define DDR3_SERDES_ACTIVE_LANES 18
`endif

`ifndef DDR3_SERDES_FIRST_LANE
`define DDR3_SERDES_FIRST_LANE 0
`endif

`ifndef DDR3_SERDES_ENABLE_TX
`define DDR3_SERDES_ENABLE_TX 1
`endif

`ifndef DDR3_SERDES_ENABLE_RX
`define DDR3_SERDES_ENABLE_RX 1
`endif

`ifndef DDR3_SERDES_USE_IDELAY
`define DDR3_SERDES_USE_IDELAY 1
`endif

module top_ddr3_dq_dqs_serdes_probe (
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
    localparam integer LANES_PER_CH = 9;
    localparam integer TOTAL_LANES = 18;
    localparam integer FIRST_LANE = `DDR3_SERDES_FIRST_LANE;
    localparam integer ACTIVE_LANES = `DDR3_SERDES_ACTIVE_LANES;
    localparam integer BITS_PER_LANE = 64;

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

    ddr3_ck_out_7series u_ck_ch1 (
        .i_clk_ddr(clk_ddr),
        .i_rst(1'b0),
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

    reg [7:0] pattern_ctr = 8'd0;
    reg [23:0] led_ctr = 24'd0;

    always @(posedge clk_sys) begin
        pattern_ctr <= pattern_ctr + 8'd1;
        led_ctr <= led_ctr + 24'd1;
    end

    wire route_rst = !pll_locked || !idelay_ready;
    wire [3:0] burst_oe = {4{pll_locked && idelay_ready && SYS_RSTN}};
    wire [ACTIVE_LANES*BITS_PER_LANE-1:0] active_rd_bits;
    wire [ACTIVE_LANES*8-1:0] active_rd_dqs_bits;

    genvar active_i;
    generate
        for (active_i = 0; active_i < ACTIVE_LANES; active_i = active_i + 1) begin : gen_lane
            localparam integer lane_i = FIRST_LANE + active_i;
            localparam integer CH = lane_i / LANES_PER_CH;
            localparam integer LANE = lane_i % LANES_PER_CH;
            localparam integer RD_BASE = active_i * BITS_PER_LANE;
            localparam integer DQS_BASE = active_i * 8;
            localparam [7:0] LANE_TAG = lane_i[7:0];

            wire [63:0] dq_bits = {
                (pattern_ctr ^ LANE_TAG ^ 8'h87),
                (pattern_ctr ^ LANE_TAG ^ 8'h69),
                (pattern_ctr ^ LANE_TAG ^ 8'h5a),
                (pattern_ctr ^ LANE_TAG ^ 8'h3c),
                (pattern_ctr ^ LANE_TAG ^ 8'hc3),
                (pattern_ctr ^ LANE_TAG ^ 8'ha5),
                (pattern_ctr ^ LANE_TAG ^ 8'h96),
                (pattern_ctr ^ LANE_TAG ^ 8'h78)
            };

            if (CH == 0) begin : gen_ch0
                ddr3_x8_serdes_io_7series #(
                    .ENABLE_TX(`DDR3_SERDES_ENABLE_TX),
                    .ENABLE_RX(`DDR3_SERDES_ENABLE_RX),
                    .USE_IDELAY(`DDR3_SERDES_USE_IDELAY)
                ) u_serdes_lane (
                    .i_clk_serdes(clk_dq),
                    .i_clk_div(clk_sys),
                    .i_rst(route_rst),
                    .i_dq_bits(dq_bits),
                    .i_dqs_bits(8'b0101_0101),
                    .i_dq_oe(burst_oe),
                    .i_dqs_oe(burst_oe),
                    .i_bitslip(1'b0),
                    .i_idelay_load(1'b0),
                    .i_idelay_tap(5'd0),
                    .o_dq_bits(active_rd_bits[RD_BASE +: BITS_PER_LANE]),
                    .o_dqs_bits(active_rd_dqs_bits[DQS_BASE +: 8]),
                    .io_dq(ddr3_dq[LANE*8 +: 8]),
                    .io_dqs_p(ddr3_dqs_p[LANE]),
                    .io_dqs_n(ddr3_dqs_n[LANE])
                );
            end else begin : gen_ch1
                ddr3_x8_serdes_io_7series #(
                    .ENABLE_TX(`DDR3_SERDES_ENABLE_TX),
                    .ENABLE_RX(`DDR3_SERDES_ENABLE_RX),
                    .USE_IDELAY(`DDR3_SERDES_USE_IDELAY)
                ) u_serdes_lane (
                    .i_clk_serdes(clk_dq),
                    .i_clk_div(clk_sys),
                    .i_rst(route_rst),
                    .i_dq_bits(dq_bits),
                    .i_dqs_bits(8'b0101_0101),
                    .i_dq_oe(burst_oe),
                    .i_dqs_oe(burst_oe),
                    .i_bitslip(1'b0),
                    .i_idelay_load(1'b0),
                    .i_idelay_tap(5'd0),
                    .o_dq_bits(active_rd_bits[RD_BASE +: BITS_PER_LANE]),
                    .o_dqs_bits(active_rd_dqs_bits[DQS_BASE +: 8]),
                    .io_dq(ddr3_ch1_dq[LANE*8 +: 8]),
                    .io_dqs_p(ddr3_ch1_dqs_p[LANE]),
                    .io_dqs_n(ddr3_ch1_dqs_n[LANE])
                );
            end
        end
    endgenerate

    reg rd_mix = 1'b0;
    always @(posedge clk_sys) begin
        rd_mix <= ^active_rd_bits ^ ^active_rd_dqs_bits;
    end

    assign led_3bits_tri_o = {rd_mix, idelay_ready, pll_locked};
endmodule

`default_nettype wire
