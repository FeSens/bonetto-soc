// ddr3_phy — Xilinx 7-series PHY layer for the DDR3 controller.
//
// Generates DDR3-side clocks, serializes/deserializes DQ around DQS,
// and provides per-bit IDELAY for read-eye tuning. Targets DDR3-800
// (2.5 ns tCK) in iter-3a; DDR3-1600 (1.25 ns tCK) follows once read/
// write levelling is in.
//
// Architecture:
//
//   clk_50 ──> MMCM ──┬──> clk_sys (200 MHz)  -> controller logic
//                     ├──> clk_phy_x4 (400 MHz) -> OSERDESE2 IO
//                     └──> clk_dq (= clk_phy_x4 with 90° phase) for DQS
//
//   Controller cmd ──> OSERDESE2 (DDR) ──> DDR3 cmd pins
//   Controller wdat ──> OSERDESE2 (DDR) ──> ODELAYE2 ──> DDR3 DQ pin
//                       OSERDESE2        ──> ODELAYE2 ──> DDR3 DQS pin
//   DDR3 DQ ──> IDELAYE2 ──> ISERDESE2 (DDR) ──> controller rdat
//   DDR3 DQS ──> IDELAYE2 (calibrated) ──> ISERDESE2 read gate
//
// Iter-3 PHY (this file): MMCM, OSERDESE2 for DQ out, ISERDESE2 for
// DQ in, IDELAYE2 + IDELAYCTRL for delay control, OBUFDS for the
// differential DDR3 clock. Write/read levelling and per-bit deskew
// are iter-3b.
//
// Notes:
//   * Verilator can't simulate Xilinx primitives without a unisim
//     library — this module is for synthesis only. Sim uses a
//     behavioural stub via `BONETTO_SOC_SIM` (similar to jtag_uart's
//     BSCANE2 handling).
//   * The board top routes the ddr3_* outputs to the YPCB-00338's
//     DDR3 BGA pins per `boards/ypcb-00338/constraints/`.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_phy #(
    parameter integer DQ_BITS    = 8,            // per-chip; total = DQ_BITS * NUM_CHIPS
    parameter integer NUM_CHIPS  = 8,            // YPCB-00338 has 8 chips per channel
    parameter integer ROW_BITS   = `DDR3_ROW_BITS,
    parameter integer BANK_BITS  = `DDR3_BANK_BITS,
    parameter integer SERDES_RATIO = 4           // 4:1 SERDES (controller @ 200 MHz, DDR @ 400 MHz)
) (
    // Reference clock from board (50 MHz on YPCB-00338).
    input  wire                            i_clk_ref,
    input  wire                            i_rst_ref,

    // MMCM outputs to controller side.
    output wire                            o_clk_sys,       // controller domain
    output wire                            o_clk_phy_x4,    // SERDES domain (= 4 × clk_sys)
    output wire                            o_clk_dq,        // = clk_phy_x4 phase-shifted 90°
    output wire                            o_locked,

    // Controller-side parallel command (driven by ddr3_init + ddr3_runtime).
    // One sample per clk_sys cycle; PHY serialises to clk_phy_x4 over DDR.
    input  wire                            i_cmd_valid,
    input  wire [3:0]                      i_cmd,           // {cs_n, ras_n, cas_n, we_n}
    input  wire [BANK_BITS-1:0]            i_cmd_ba,
    input  wire [ROW_BITS-1:0]             i_cmd_addr,
    input  wire                            i_cmd_cke,
    input  wire                            i_cmd_reset_n,
    input  wire                            i_cmd_odt,

    // Controller-side write data: 4 successive 8-bit beats packed into
    // a 32-bit word per chip (SERDES_RATIO = 4). For BL8 the controller
    // sends two of these words back-to-back.
    input  wire                            i_wr_valid,
    input  wire [DQ_BITS*NUM_CHIPS*4-1:0]  i_wr_data,
    input  wire [DQ_BITS*NUM_CHIPS/8-1:0]  i_wr_mask,

    // Controller-side read data: same packing as write side. valid pulses
    // when a full BL8 burst has been captured.
    output wire                            o_rd_valid,
    output wire [DQ_BITS*NUM_CHIPS*4-1:0]  o_rd_data,

    // DDR3 chip pins.
    output wire                            o_ddr3_ck_p,
    output wire                            o_ddr3_ck_n,
    output wire                            o_ddr3_cke,
    output wire                            o_ddr3_reset_n,
    output wire                            o_ddr3_cs_n,
    output wire                            o_ddr3_ras_n,
    output wire                            o_ddr3_cas_n,
    output wire                            o_ddr3_we_n,
    output wire                            o_ddr3_odt,
    output wire [BANK_BITS-1:0]            o_ddr3_ba,
    output wire [ROW_BITS-1:0]             o_ddr3_addr,
    inout  wire [DQ_BITS*NUM_CHIPS-1:0]    io_ddr3_dq,
    inout  wire [NUM_CHIPS-1:0]            io_ddr3_dqs_p,
    inout  wire [NUM_CHIPS-1:0]            io_ddr3_dqs_n,
    output wire [NUM_CHIPS-1:0]            o_ddr3_dm
);
    // ============================================================
    // MMCM — 50 MHz ref → 200 MHz sys (controller) + 400 MHz x4 SERDES
    // ============================================================
    wire   clkfb;
    wire   mmcm_clkout_sys;       // 200 MHz
    wire   mmcm_clkout_phy_x4;    // 400 MHz
    wire   mmcm_clkout_dq;        // 400 MHz, +90°

`ifdef BONETTO_SOC_SIM
    // Sim stub — fake the clocks; Verilator can't sim Xilinx primitives
    // without unisims, and this module is synthesis-only for iter-3a.
    assign mmcm_clkout_sys    = i_clk_ref;
    assign mmcm_clkout_phy_x4 = i_clk_ref;
    assign mmcm_clkout_dq     = i_clk_ref;
    assign o_locked           = ~i_rst_ref;
    assign o_clk_sys          = mmcm_clkout_sys;
    assign o_clk_phy_x4       = mmcm_clkout_phy_x4;
    assign o_clk_dq           = mmcm_clkout_dq;
`else
    MMCME2_ADV #(
        .CLKIN1_PERIOD       (20.0),       // 50 MHz ref
        .CLKFBOUT_MULT_F     (16.0),       // VCO = 800 MHz
        .DIVCLK_DIVIDE       (1),
        .CLKOUT0_DIVIDE_F    (4.0),        // 200 MHz controller
        .CLKOUT1_DIVIDE      (2),          // 400 MHz SERDES
        .CLKOUT2_DIVIDE      (2),          // 400 MHz DQS clock (+90°)
        .CLKOUT2_PHASE       (90.0),
        .STARTUP_WAIT        ("FALSE")
    ) u_mmcm (
        .CLKIN1     (i_clk_ref),
        .CLKIN2     (1'b0),
        .CLKINSEL   (1'b1),
        .RST        (i_rst_ref),
        .PWRDWN     (1'b0),
        .CLKFBIN    (clkfb),
        .CLKFBOUT   (clkfb),
        .CLKFBOUTB  (),
        .CLKOUT0    (mmcm_clkout_sys),
        .CLKOUT0B   (),
        .CLKOUT1    (mmcm_clkout_phy_x4),
        .CLKOUT1B   (),
        .CLKOUT2    (mmcm_clkout_dq),
        .CLKOUT2B   (),
        .CLKOUT3    (), .CLKOUT3B (),
        .CLKOUT4    (),
        .CLKOUT5    (),
        .CLKOUT6    (),
        .LOCKED     (o_locked),
        .DADDR      (7'b0), .DCLK (1'b0), .DEN (1'b0), .DI (16'b0), .DWE (1'b0),
        .DO         (), .DRDY (),
        .PSCLK      (1'b0), .PSEN (1'b0), .PSINCDEC (1'b0), .PSDONE (),
        .CLKINSTOPPED (), .CLKFBSTOPPED ()
    );

    BUFG u_bufg_sys    (.I(mmcm_clkout_sys),    .O(o_clk_sys));
    BUFG u_bufg_phy_x4 (.I(mmcm_clkout_phy_x4), .O(o_clk_phy_x4));
    BUFG u_bufg_dq     (.I(mmcm_clkout_dq),     .O(o_clk_dq));
`endif

    // ============================================================
    // Differential DDR3 clock output (OBUFDS_DIFF_OUT)
    // ============================================================
`ifdef BONETTO_SOC_SIM
    assign o_ddr3_ck_p =  mmcm_clkout_dq;
    assign o_ddr3_ck_n = ~mmcm_clkout_dq;
`else
    OBUFDS u_obufds_ck (
        .I  (mmcm_clkout_phy_x4),
        .O  (o_ddr3_ck_p),
        .OB (o_ddr3_ck_n)
    );
`endif

    // ============================================================
    // Command-bus output FFs (single-data-rate; iter-3a goal). For
    // iter-3b these become OSERDESE2 for tighter Tco alignment.
    // ============================================================
    reg cke_q, reset_q, cs_q, ras_q, cas_q, we_q, odt_q;
    reg [BANK_BITS-1:0]  ba_q;
    reg [ROW_BITS-1:0]   addr_q;

    always @(posedge o_clk_sys) begin
        cke_q   <= i_cmd_cke;
        reset_q <= i_cmd_reset_n;
        odt_q   <= i_cmd_odt;
        if (i_cmd_valid) begin
            {cs_q, ras_q, cas_q, we_q} <= i_cmd;
            ba_q   <= i_cmd_ba;
            addr_q <= i_cmd_addr;
        end else begin
            // NOP: deselect with CS=1 keeps DDR3 idle without latching.
            {cs_q, ras_q, cas_q, we_q} <= 4'b1111;
        end
    end

    assign o_ddr3_cke     = cke_q;
    assign o_ddr3_reset_n = reset_q;
    assign o_ddr3_cs_n    = cs_q;
    assign o_ddr3_ras_n   = ras_q;
    assign o_ddr3_cas_n   = cas_q;
    assign o_ddr3_we_n    = we_q;
    assign o_ddr3_odt     = odt_q;
    assign o_ddr3_ba      = ba_q;
    assign o_ddr3_addr    = addr_q;
    assign o_ddr3_dm      = {NUM_CHIPS{1'b0}};       // iter-3b: connect masks

    // ============================================================
    // DQ / DQS — SERDES path (iter-3a stub; full implementation iter-3b)
    // ============================================================
    // Iter-3a: drive DQ tristate to high-Z, capture nothing.
    // Iter-3b: per-byte OSERDESE2/ISERDESE2 with IDELAYE2 and
    //          IDELAYCTRL ref tap.
    assign io_ddr3_dq    = {(DQ_BITS*NUM_CHIPS){1'bz}};
    assign io_ddr3_dqs_p = {NUM_CHIPS{1'bz}};
    assign io_ddr3_dqs_n = {NUM_CHIPS{1'bz}};
    assign o_rd_valid    = 1'b0;
    assign o_rd_data     = {(DQ_BITS*NUM_CHIPS*4){1'b0}};

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_wr_valid, i_wr_data, i_wr_mask, mmcm_clkout_dq,
                SERDES_RATIO[0], 1'b0};
    /* verilator lint_on UNUSED */
endmodule
