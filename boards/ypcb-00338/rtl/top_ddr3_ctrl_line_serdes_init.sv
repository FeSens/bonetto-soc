// Live DDR3-800 init-only controller-to-SERDES image for YPCB-00338.
//
// This is the first gate that combines the clean line controller, live DDR3
// reset/CKE/command pins, and the full x9 OSERDES/ISERDES/IDELAY DQ/DQS shell.
// JTAG/Wishbone DDR3 accesses are blocked deliberately: this image validates
// JEDEC init and physical pin presence, not uncalibrated external storage.

`default_nettype none

module top_ddr3_ctrl_line_serdes_init (
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
        .BLOCK_DDR_WISHBONE(1),
        .PHY_HAS_BYTE_MASK(0),
        .USE_LINE_TO_LANES(0),
        .USE_LINE_LANE_PHY(0),
        .USE_LINE_SERDES_PHY(1),
        .GATE_VERSION(32'hB07E_0D89),
        .DEFAULT_MAGIC(24'hD3AD89)
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
