// PHY-clock timing-probe experiment for YPCB-00338.
//
// This keeps external DQ/DQS high-Z, but moves the abstract line-lane PHY and
// a small pin-pair timing probe into clk_dq behind a dual-clock bridge. The
// probe checks burst shape and immediate readback through the PHY path without
// putting a large addressable debug memory on the DQ clock.
//
// This is not a DDR3-800 signoff image. The soft line-lane/probe fabric has
// been observed to route at about 107 MHz against the 400 MHz clk_dq target.
// Keep this target as evidence for the next architecture split: slow fabric
// controller/lane assembly, tiny fast I/O shell.

`default_nettype none

module top_ddr3_ctrl_line_phyclkloop (
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
    top_ddr3_ctrl_line_loopback #(
        .DRIVE_DDR3_COMMANDS(1),
        .PHY_HAS_BYTE_MASK(0),
        .USE_LINE_TO_LANES(0),
        .USE_LINE_LANE_PHY(1),
        .USE_PHY_CLOCK_BRIDGE(1),
        .USE_PINPAIR_TIMING_PROBE(1),
        .GATE_VERSION(32'hB07E_0D88),
        .DEFAULT_MAGIC(24'hD3AD88)
    ) u_top (
        .SYS_CLK(SYS_CLK),
        .SYS_RSTN(SYS_RSTN),
        .led_3bits_tri_o(led_3bits_tri_o),
        .ddr3_addr(ddr3_addr),
        .ddr3_ba(ddr3_ba),
        .ddr3_ras_n(ddr3_ras_n),
        .ddr3_cas_n(ddr3_cas_n),
        .ddr3_we_n(ddr3_we_n),
        .ddr3_cs_n(ddr3_cs_n),
        .ddr3_cke(ddr3_cke),
        .ddr3_odt(ddr3_odt),
        .ddr3_reset_n(ddr3_reset_n),
        .ddr3_ck_p(ddr3_ck_p),
        .ddr3_ck_n(ddr3_ck_n),
        .ddr3_dq(ddr3_dq),
        .ddr3_dqs_p(ddr3_dqs_p),
        .ddr3_dqs_n(ddr3_dqs_n),
        .ddr3_ch1_addr(ddr3_ch1_addr),
        .ddr3_ch1_ba(ddr3_ch1_ba),
        .ddr3_ch1_ras_n(ddr3_ch1_ras_n),
        .ddr3_ch1_cas_n(ddr3_ch1_cas_n),
        .ddr3_ch1_we_n(ddr3_ch1_we_n),
        .ddr3_ch1_cs_n(ddr3_ch1_cs_n),
        .ddr3_ch1_cke(ddr3_ch1_cke),
        .ddr3_ch1_odt(ddr3_ch1_odt),
        .ddr3_ch1_reset_n(ddr3_ch1_reset_n),
        .ddr3_ch1_ck_p(ddr3_ch1_ck_p),
        .ddr3_ch1_ck_n(ddr3_ch1_ck_n),
        .ddr3_ch1_dq(ddr3_ch1_dq),
        .ddr3_ch1_dqs_p(ddr3_ch1_dqs_p),
        .ddr3_ch1_dqs_n(ddr3_ch1_dqs_n)
    );
endmodule

`default_nettype wire
