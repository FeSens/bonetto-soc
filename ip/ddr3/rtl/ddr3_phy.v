// ddr3_phy — Xilinx 7-series PHY layer for the DDR3 controller.
//
// Generates DDR3-side clocks, serializes/deserializes DQ around DQS,
// and provides per-bit IDELAY for read-eye tuning. Targets DDR3-800
// (2.5 ns tCK) in iter-3a; DDR3-1600 (1.25 ns tCK) follows once read/
// write levelling is in.
//
// Architecture (iter-3b):
//
//   clk_50 ──> MMCM ──┬──> clk_sys (200 MHz)  -> controller logic
//                     ├──> clk_phy_x4 (400 MHz) -> OSERDESE2 IO
//                     └──> clk_dq (= clk_phy_x4 with 90° phase) for DQS
//
//   clk_sys ─→ IDELAYCTRL (REFCLK=200 MHz) ─→ all IDELAYE2 ref taps
//
//   Controller wdat ─→ OSERDESE2 (DDR) ─→ IOBUFDS_DCIEN ─→ DDR3 DQ
//   Controller DQS ─→ OSERDESE2 (clk_dq, +90°) ─→ IOBUFDS_DCIEN ─→ DQS pair
//   DDR3 DQ ─→ IDELAYE2 (per-bit) ─→ ISERDESE2 ─→ controller rdat
//   DDR3 DQS ─→ IBUFDS ─→ IDELAYE2 (per-byte) ─→ ISERDESE2 strobe
//
//   Calibration: ddr3_phy_wlvl runs after init to align DQS-out to CK,
//                ddr3_phy_rdlvl follows to centre the DQS-in IDELAY tap
//                inside the MPR-pattern eye. Both expose start / done /
//                error to the upstream controller; the controller is
//                expected to gate them in order during the post-init
//                MR-rewrite sequence.
//
// Sim guard: `BONETTO_SOC_SIM` stubs primitives the same way as
// ddr3_phy_dq.v / jtag_uart.v. The cal FSMs are functional under sim
// and exercise themselves against the stubs.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_phy #(
    parameter integer DQ_BITS        = 8,           // per byte lane
    parameter integer NUM_BYTE_LANES = 9,           // YPCB-00338: 8 data + 1 ECC
    parameter integer ROW_BITS       = `DDR3_ROW_BITS,
    parameter integer BANK_BITS      = `DDR3_BANK_BITS,
    parameter integer SERDES_RATIO   = 4
) (
    // Reference clock from board (50 MHz on YPCB-00338).
    input  wire                            i_clk_ref,
    input  wire                            i_rst_ref,

    // MMCM outputs to controller side.
    output wire                            o_clk_sys,       // 200 MHz controller
    output wire                            o_clk_phy_x4,    // 400 MHz SERDES
    output wire                            o_clk_dq,        // 400 MHz +90°
    output wire                            o_locked,
    output wire                            o_idelay_ready,  // from IDELAYCTRL

    // Controller-side parallel command bus.
    input  wire                            i_cmd_valid,
    input  wire [3:0]                      i_cmd,           // {cs_n, ras_n, cas_n, we_n}
    input  wire [BANK_BITS-1:0]            i_cmd_ba,
    input  wire [ROW_BITS-1:0]             i_cmd_addr,
    input  wire                            i_cmd_cke,
    input  wire                            i_cmd_reset_n,
    input  wire                            i_cmd_odt,

    // Controller-side write data.
    input  wire                            i_wr_valid,
    input  wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] i_wr_data,
    input  wire [NUM_BYTE_LANES-1:0]       i_wr_mask,

    // Controller-side read data.
    output wire                            o_rd_valid,
    output wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] o_rd_data,

    // -------- Calibration control --------
    input  wire                            i_cal_start_wlvl,
    output wire                            o_cal_done_wlvl,
    output wire                            o_cal_error_wlvl,
    output wire [3:0]                      o_cal_state_wlvl,

    input  wire                            i_cal_start_rdlvl,
    output wire                            o_cal_done_rdlvl,
    output wire                            o_cal_error_rdlvl,
    output wire [3:0]                      o_cal_state_rdlvl,

    // rdlvl needs an upstream RD-command issuer
    output wire                            o_mpr_read_req,
    output wire [12:0]                     o_mpr_read_addr,

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
    inout  wire [NUM_BYTE_LANES*DQ_BITS-1:0] io_ddr3_dq,
    inout  wire [NUM_BYTE_LANES-1:0]       io_ddr3_dqs_p,
    inout  wire [NUM_BYTE_LANES-1:0]       io_ddr3_dqs_n,
    output wire [NUM_BYTE_LANES-1:0]       o_ddr3_dm
);
    // ============================================================
    // MMCM — 50 MHz ref → 200 MHz sys + 400 MHz x4 SERDES + 400 +90°
    // ============================================================
    wire   clkfb;
    wire   mmcm_clkout_sys;       // 200 MHz
    wire   mmcm_clkout_phy_x4;    // 400 MHz
    wire   mmcm_clkout_dq;        // 400 MHz, +90°

`ifdef BONETTO_SOC_SIM
    assign mmcm_clkout_sys    = i_clk_ref;
    assign mmcm_clkout_phy_x4 = i_clk_ref;
    assign mmcm_clkout_dq     = i_clk_ref;
    assign o_locked           = ~i_rst_ref;
    assign o_clk_sys          = mmcm_clkout_sys;
    assign o_clk_phy_x4       = mmcm_clkout_phy_x4;
    assign o_clk_dq           = mmcm_clkout_dq;
`else
    MMCME2_ADV #(
        .CLKIN1_PERIOD       (20.0),
        .CLKFBOUT_MULT_F     (16.0),
        .DIVCLK_DIVIDE       (1),
        .CLKOUT0_DIVIDE_F    (4.0),
        .CLKOUT1_DIVIDE      (2),
        .CLKOUT2_DIVIDE      (2),
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
    // Command-bus output FFs (single-data-rate)
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

    // ============================================================
    // Lane array — multi-byte-lane data path + IDELAYCTRL
    // ============================================================
    wire [NUM_BYTE_LANES-1:0]    cal_dq_load_lane = {NUM_BYTE_LANES{1'b0}}; // per-bit deskew TBD
    wire [DQ_BITS-1:0]           cal_dq_sel       = {DQ_BITS{1'b0}};
    wire [4:0]                   cal_dq_tap       = 5'd0;

    // wlvl drives the DQS OUTPUT path (ODELAYE2) per lane
    wire [NUM_BYTE_LANES-1:0]    wlvl_dqs_out_load_lane;
    wire [4:0]                   wlvl_dqs_out_tap;
    wire [NUM_BYTE_LANES-1:0]    wlvl_dqs_toggle_en;

    // rdlvl drives the DQS INPUT path (IDELAYE2) per lane
    wire [NUM_BYTE_LANES-1:0]    rdlvl_dqs_in_load_lane;
    wire [4:0]                   rdlvl_dqs_in_tap;

    // Per-lane read-data + read-valid (lane-aligned by ISERDESE2)
    wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] lane_rd_data;
    wire [NUM_BYTE_LANES-1:0]                      lane_rd_valid;

    ddr3_phy_lane_array #(
        .NUM_BYTE_LANES (NUM_BYTE_LANES),
        .DQ_BITS        (DQ_BITS),
        .RATIO          (SERDES_RATIO)
    ) u_lanes (
        .i_clk_sys                (o_clk_sys),
        .i_clk_phy_x4             (o_clk_phy_x4),
        .i_clk_dq                 (o_clk_dq),
        .i_clk_ref_200            (o_clk_sys),       // 200 MHz sys clock doubles as IDELAYCTRL ref
        .i_rst                    (i_rst_ref),

        .i_wr_en                  (i_wr_valid),
        .i_wr_data                (i_wr_data),
        .i_wr_dqs_en              (i_wr_valid),      // normal-write DQS strobe

        .o_rd_data                (lane_rd_data),
        .o_rd_valid_lane          (lane_rd_valid),
        .o_rd_valid_all           (o_rd_valid),

        .i_cal_dq_load_lane       (cal_dq_load_lane),
        .i_cal_dq_sel             (cal_dq_sel),
        .i_cal_dq_tap             (cal_dq_tap),

        .i_cal_dqs_in_load_lane   (rdlvl_dqs_in_load_lane),
        .i_cal_dqs_in_tap         (rdlvl_dqs_in_tap),

        .i_cal_dqs_out_load_lane  (wlvl_dqs_out_load_lane),
        .i_cal_dqs_out_tap        (wlvl_dqs_out_tap),
        .i_cal_dqs_toggle_en_lane (wlvl_dqs_toggle_en),

        .o_idelay_ready           (o_idelay_ready),

        .io_ddr3_dq               (io_ddr3_dq),
        .io_ddr3_dqs_p            (io_ddr3_dqs_p),
        .io_ddr3_dqs_n            (io_ddr3_dqs_n),
        .o_ddr3_dm                (o_ddr3_dm)
    );

    assign o_rd_data = lane_rd_data;

    // ============================================================
    // Write-leveling FSM
    // ============================================================
    // DQ[0] of each byte lane after the read SERDES — written by DDR3
    // chip while in MR1[7]=1 write-leveling mode. We pick bit 0 of beat 0.
    wire [NUM_BYTE_LANES-1:0] dq0_per_lane;
    genvar gl;
    generate
        for (gl = 0; gl < NUM_BYTE_LANES; gl = gl + 1) begin : g_dq0
            assign dq0_per_lane[gl] = lane_rd_data[gl*DQ_BITS*SERDES_RATIO];
        end
    endgenerate

    ddr3_phy_wlvl #(
        .NUM_BYTE_LANES (NUM_BYTE_LANES)
    ) u_wlvl (
        .i_clk                (o_clk_sys),
        .i_rst                (i_rst_ref),
        .i_start              (i_cal_start_wlvl),
        .o_done               (o_cal_done_wlvl),
        .o_error              (o_cal_error_wlvl),
        .o_state              (o_cal_state_wlvl),
        .i_dq0_per_lane       (dq0_per_lane),
        .o_dqs_out_load_lane  (wlvl_dqs_out_load_lane),
        .o_dqs_out_tap        (wlvl_dqs_out_tap),
        .o_dqs_toggle_en_lane (wlvl_dqs_toggle_en),
        .o_locked_tap_lane    ()
    );

    // ============================================================
    // Read-leveling FSM
    // ============================================================
    ddr3_phy_rdlvl #(
        .NUM_BYTE_LANES (NUM_BYTE_LANES),
        .DQ_BITS        (DQ_BITS),
        .RATIO          (SERDES_RATIO)
    ) u_rdlvl (
        .i_clk              (o_clk_sys),
        .i_rst              (i_rst_ref),
        .i_start            (i_cal_start_rdlvl),
        .o_done             (o_cal_done_rdlvl),
        .o_error            (o_cal_error_rdlvl),
        .o_state            (o_cal_state_rdlvl),
        .o_mpr_read_req     (o_mpr_read_req),
        .o_mpr_read_addr    (o_mpr_read_addr),
        .i_rd_data_valid    (o_rd_valid),
        .i_rd_data          (lane_rd_data),
        .o_dqs_in_load_lane (rdlvl_dqs_in_load_lane),
        .o_dqs_in_tap       (rdlvl_dqs_in_tap),
        .o_locked_tap_lane  ()
    );

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_wr_mask, mmcm_clkout_dq, SERDES_RATIO[0], 1'b0};
    /* verilator lint_on UNUSED */
endmodule
