// DDR3-800 line-to-lane loopback image for YPCB-00338.
//
// This gate keeps external DDR3 DQ/DQS high-Z, but it inserts the reusable
// ddr3_line_to_lanes RTL between the line-level controller and the internal
// lane loopback memories. It is the hardware-visible step between the complete
// line controller and a real DQ/DQS PHY.

`default_nettype none

module top_ddr3_ctrl_line_laneloop (
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
        .DRIVE_DDR3_COMMANDS(0),
        .PHY_HAS_BYTE_MASK(1),
        .USE_LINE_TO_LANES(1),
        .GATE_VERSION(32'hB07E_0D85),
        .DEFAULT_MAGIC(24'hD3AD85)
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
