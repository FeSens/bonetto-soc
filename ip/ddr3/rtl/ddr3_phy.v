// ddr3_phy — Xilinx 7-series PHY layer for the DDR3 controller.
//
// Generates DDR3-side clocks, serializes/deserializes DQ around DQS,
// and provides per-bit IDELAY for read-eye tuning. Validated on YPCB-00338
// at DDR3-800 (2.5 ns tCK). Faster operating points need renewed timing and
// hardware validation.
//
// Architecture:
//
//   clk_50 ──> PLL ───┬──> clk_sys (100/200 MHz)  -> controller logic
//                     ├──> clk_phy_x4 (400/800 MHz) -> DDR3 CK
//                     └──> clk_dq (= clk_phy_x4 with 90 deg phase) for DQS
//
//   clk_sys ─→ fixed-phase fabric I/O path for YPCB-00338 bring-up
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
`include "ddr3_cmd.vh"

module ddr3_phy #(
    parameter integer DQ_BITS        = 8,           // per byte lane
    parameter integer NUM_BYTE_LANES = 9,           // YPCB-00338: 8 data + 1 ECC
    parameter integer ROW_BITS       = `DDR3_ROW_BITS,
    parameter integer BANK_BITS      = `DDR3_BANK_BITS,
    parameter integer SERDES_RATIO   = 4,
    parameter integer USE_EXTERNAL_CLOCKS = 0,
    parameter integer RD_VALID_REQUIRE_ALL = 1
) (
    // Reference clock from board (50 MHz on YPCB-00338).
    input  wire                            i_clk_ref,
    input  wire                            i_rst_ref,

    // Optional shared clocks for multi-channel board integrations.
    input  wire                            i_clk_sys_ext,
    input  wire                            i_clk_phy_x4_ext,
    input  wire                            i_clk_dq_ext,
    input  wire                            i_locked_ext,
    input  wire                            i_idelay_ready_ext,

    // MMCM outputs to controller side.
    output wire                            o_clk_sys,       // 100 MHz controller
    output wire                            o_clk_phy_x4,    // 400 MHz DDR CK
    output wire                            o_clk_dq,        // 400 MHz +90 deg
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
    input  wire                            i_rd_capture,
    output wire                            o_rd_valid,
    output wire [NUM_BYTE_LANES-1:0]       o_rd_valid_lane,
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

    // iter-10: host-driven IDELAY override (from jtag_wb_master).
    // OR'd with the rdlvl FSM's outputs inside ddr3_phy_lane_array.
    input  wire [NUM_BYTE_LANES-1:0]       i_cal_jwb_load_lane,
    input  wire [4:0]                      i_cal_jwb_tap,

    // iter-11: MMCM fine-phase shift on CLKOUT2 (clk_dq), the
    // HR-bank-compatible write-leveling alternative to ODELAYE2 on
    // the DQS output. Each pulse on i_phase_req shifts clk_dq phase
    // by 1/56 of the VCO period (22.3ps with our 800 MHz VCO).
    // With the PLLE2 bring-up clocking this cannot physically shift clk_dq,
    // so the counter is visibility-only until the MMCM path is restored.
    input  wire                            i_phase_req,
    input  wire                            i_phase_inc,
    output wire                            o_phase_busy,
    output wire [7:0]                      o_phase_count,

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
    // PLL - 50 MHz ref -> controller clock + DDR CK + DDR CK +90 deg.
    // DDR3_RATE_800:  100 MHz sys + 400 MHz CK.
    // DDR3_RATE_1600: 200 MHz sys + 800 MHz CK.
    //
    // The original bring-up used MMCME2_ADV for dynamic phase shifting, but
    // the current openXC7/prjxray Kintex-7 flow programs an MMCM that does
    // not lock on this board. PLLE2_ADV is covered by the local DB and gives
    // us the three static clocks needed to move DDR3 init/cal bring-up
    // forward. Dynamic phase-shift commands are counted for host visibility
    // below, but they do not affect the PLL output phase.
    // ============================================================
    wire   clkfb;
    wire   mmcm_clkout_sys;       // 100 MHz
    wire   mmcm_clkout_phy_x4;    // 400 MHz
    wire   mmcm_clkout_dq;        // 400 MHz, +90 deg
    wire   mmcm_clkout_ref_200;   // 200 MHz IDELAYCTRL reference
    wire   clk_ref_200;

`ifdef BONETTO_SOC_SIM
    assign mmcm_clkout_sys    = i_clk_ref;
    assign mmcm_clkout_phy_x4 = i_clk_ref;
    assign mmcm_clkout_dq     = i_clk_ref;
    assign mmcm_clkout_ref_200 = i_clk_ref;
    assign clk_ref_200        = i_clk_ref;
    assign o_locked           = ~i_rst_ref;
    assign o_clk_sys          = mmcm_clkout_sys;
    assign o_clk_phy_x4       = mmcm_clkout_phy_x4;
    assign o_clk_dq           = mmcm_clkout_dq;
    // iter-11 stubs for sim: track phase count, never go busy.
    reg [7:0] sim_phase_count = 8'd0;
    always @(posedge i_clk_ref) begin
        if (i_phase_req) sim_phase_count <= i_phase_inc ? (sim_phase_count + 8'd1)
                                                        : (sim_phase_count - 8'd1);
    end
    assign o_phase_busy  = 1'b0;
    assign o_phase_count = sim_phase_count;
`else
    generate
    if (USE_EXTERNAL_CLOCKS) begin : g_external_clocks
        assign mmcm_clkout_sys    = i_clk_sys_ext;
        assign mmcm_clkout_phy_x4 = i_clk_phy_x4_ext;
        assign mmcm_clkout_dq     = i_clk_dq_ext;
        assign mmcm_clkout_ref_200 = i_clk_sys_ext;
        assign clk_ref_200        = i_clk_sys_ext;
        assign o_clk_sys          = i_clk_sys_ext;
        assign o_clk_phy_x4       = i_clk_phy_x4_ext;
        assign o_clk_dq           = i_clk_dq_ext;
        assign o_locked           = i_locked_ext;
        assign o_phase_busy       = 1'b0;
        assign o_phase_count      = 8'd0;
    end else begin : g_local_pll
    // ----------------------------------------------------------------
    // iter-11 host phase commands are retained as a visible counter. PLLE2_ADV
    // has no MMCM-style PSEN/PSDONE interface, so this is a no-op physically.
    // ----------------------------------------------------------------
    reg [2:0] ps_req_sync;
    always @(posedge i_clk_ref or posedge i_rst_ref) begin
        if (i_rst_ref)
            ps_req_sync <= 3'b000;
        else
            ps_req_sync <= {ps_req_sync[1:0], i_phase_req};
    end
    wire ps_req_edge = ps_req_sync[1] && !ps_req_sync[2];

    reg [7:0] ps_count;     // running phase-step count, observable via status
    always @(posedge i_clk_ref or posedge i_rst_ref) begin
        if (i_rst_ref) begin
            ps_count    <= 8'd0;
        end else begin
            if (ps_req_edge) begin
                ps_count    <= i_phase_inc ? (ps_count + 8'd1) : (ps_count - 8'd1);
            end
        end
    end

    assign o_phase_busy  = 1'b0;
    assign o_phase_count = ps_count;

`ifdef DDR3_RATE_1600
    localparam integer PLL_CLKOUT0_DIVIDE = 4;
    localparam integer PLL_CLKOUT1_DIVIDE = 1;
    localparam integer PLL_CLKOUT2_DIVIDE = 1;
`else
    localparam integer PLL_CLKOUT0_DIVIDE = 8;
    localparam integer PLL_CLKOUT1_DIVIDE = 2;
    localparam integer PLL_CLKOUT2_DIVIDE = 2;
`endif

    PLLE2_ADV #(
        .CLKIN1_PERIOD          (20.0),
        .CLKFBOUT_MULT          (16),
        .DIVCLK_DIVIDE          (1),
        .CLKOUT0_DIVIDE         (PLL_CLKOUT0_DIVIDE),
        .CLKOUT1_DIVIDE         (PLL_CLKOUT1_DIVIDE),
        .CLKOUT2_DIVIDE         (PLL_CLKOUT2_DIVIDE),
        .CLKOUT3_DIVIDE         (4),
        .CLKOUT2_PHASE          (90.0),
        .COMPENSATION           ("INTERNAL"),
        .STARTUP_WAIT           ("FALSE")
    ) u_pll (
        .CLKIN1     (i_clk_ref),
        .CLKIN2     (1'b0),
        .CLKINSEL   (1'b1),
        .RST        (i_rst_ref),
        .PWRDWN     (1'b0),
        .CLKFBIN    (clkfb),
        .CLKFBOUT   (clkfb),
        .CLKOUT0    (mmcm_clkout_sys),
        .CLKOUT1    (mmcm_clkout_phy_x4),
        .CLKOUT2    (mmcm_clkout_dq),
        .CLKOUT3    (mmcm_clkout_ref_200),
        .CLKOUT4    (),
        .CLKOUT5    (),
        .LOCKED     (o_locked),
        .DADDR      (7'b0), .DCLK (1'b0), .DEN (1'b0), .DI (16'b0), .DWE (1'b0),
        .DO         (), .DRDY ()
    );

    BUFG u_bufg_sys    (.I(mmcm_clkout_sys),    .O(o_clk_sys));
    BUFG u_bufg_phy_x4 (.I(mmcm_clkout_phy_x4), .O(o_clk_phy_x4));
    BUFG u_bufg_dq     (.I(mmcm_clkout_dq),     .O(o_clk_dq));
    BUFG u_bufg_ref_200(.I(mmcm_clkout_ref_200), .O(clk_ref_200));
    end
    endgenerate
`endif

    wire phy_io_rst = i_rst_ref | ~o_locked;

    // ============================================================
    // Differential DDR3 clock output (OBUFDS_DIFF_OUT)
    // ============================================================
`ifdef BONETTO_SOC_SIM
    assign o_ddr3_ck_p =  mmcm_clkout_dq;
    assign o_ddr3_ck_n = ~mmcm_clkout_dq;
`else
    wire ck_out;

    ODDR #(
        .DDR_CLK_EDGE("SAME_EDGE"),
        .INIT(1'b0),
        .SRTYPE("SYNC")
    ) u_oddr_ck (
        .Q  (ck_out),
        .C  (o_clk_phy_x4),
        .CE (1'b1),
        .D1 (1'b1),
        .D2 (1'b0),
        .R  (phy_io_rst),
        .S  (1'b0)
    );

    OBUFDS u_obufds_ck (
        .I  (ck_out),
        .O  (o_ddr3_ck_p),
        .OB (o_ddr3_ck_n)
    );
`endif

    // ============================================================
    // Command-bus output FFs (single-data-rate)
    //
    // The controller runs at clk_sys (100 MHz) while DDR3 CK is 400 MHz.
    // Capture one command/address/control word per clk_sys cycle, then
    // launch it from the +90 degree clk_dq domain for one DDR3 CK cycle.
    // That keeps command pins away from the CK sampling edge and inserts
    // NOPs on the other three CK cycles within each clk_sys cycle.
    // ============================================================
    reg cke_shadow, reset_shadow, odt_shadow;
    reg wr_shadow;
    reg [3:0] cmd_shadow;
    reg [BANK_BITS-1:0] ba_shadow;
    reg [ROW_BITS-1:0] addr_shadow;

    always @(posedge o_clk_sys or posedge phy_io_rst) begin
        if (phy_io_rst) begin
            cke_shadow   <= 1'b0;
            reset_shadow <= 1'b0;
            odt_shadow   <= 1'b0;
            wr_shadow    <= 1'b0;
            cmd_shadow   <= 4'b1111;
            ba_shadow    <= {BANK_BITS{1'b0}};
            addr_shadow  <= {ROW_BITS{1'b0}};
        end else begin
            cke_shadow   <= i_cmd_cke;
            reset_shadow <= i_cmd_reset_n;
            odt_shadow   <= i_cmd_odt;
            if (i_cmd_valid) begin
                wr_shadow   <= (i_cmd == `DDR3_CMD_WRITE);
                cmd_shadow  <= i_cmd;
                ba_shadow   <= i_cmd_ba;
                addr_shadow <= i_cmd_addr;
            end else begin
                wr_shadow   <= 1'b0;
                cmd_shadow  <= 4'b1111;
                ba_shadow   <= {BANK_BITS{1'b0}};
                addr_shadow <= {ROW_BITS{1'b0}};
            end
        end
    end

    reg cke_q, reset_q, cs_q, ras_q, cas_q, we_q, odt_q;
    reg [BANK_BITS-1:0]  ba_q;
    reg [ROW_BITS-1:0]   addr_q;
    reg [1:0]            cmd_phase;
    reg                  wr_cmd_launch_q;
`ifdef DDR3_WR_DQS_DELAY_CK
    localparam integer WR_DQS_DELAY_CK = `DDR3_WR_DQS_DELAY_CK;
`else
    localparam integer WR_DQS_DELAY_CK = 2;
`endif
`ifdef DDR3_WR_DQ_OE_DELAY_SYS
    localparam integer WR_DQ_OE_DELAY_SYS = `DDR3_WR_DQ_OE_DELAY_SYS;
`else
    localparam integer WR_DQ_OE_DELAY_SYS = 0;
`endif
`ifdef DDR3_WR_DQ_OE_HOLD_SYS
    localparam integer WR_DQ_OE_HOLD_SYS = `DDR3_WR_DQ_OE_HOLD_SYS;
`else
    localparam integer WR_DQ_OE_HOLD_SYS = 4;
`endif

    always @(posedge o_clk_dq or posedge phy_io_rst) begin
        if (phy_io_rst) begin
            cmd_phase <= 2'd0;
            cke_q    <= 1'b0;
            reset_q  <= 1'b0;
            odt_q    <= 1'b0;
            {cs_q, ras_q, cas_q, we_q} <= 4'b1111;
            ba_q     <= {BANK_BITS{1'b0}};
            addr_q   <= {ROW_BITS{1'b0}};
            wr_cmd_launch_q <= 1'b0;
        end else begin
            cmd_phase <= cmd_phase + 2'd1;
            cke_q    <= cke_shadow;
            reset_q  <= reset_shadow;
            odt_q    <= odt_shadow;
            wr_cmd_launch_q <= 1'b0;
            if (cmd_phase == 2'd0) begin
                {cs_q, ras_q, cas_q, we_q} <= cmd_shadow;
                ba_q   <= ba_shadow;
                addr_q <= addr_shadow;
                wr_cmd_launch_q <= wr_shadow;
            end else begin
                {cs_q, ras_q, cas_q, we_q} <= 4'b1111;
                ba_q   <= {BANK_BITS{1'b0}};
                addr_q <= {ROW_BITS{1'b0}};
            end
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

    // iter-10: OR rdlvl with JWB-driven host override + priority-mux taps.
    wire [NUM_BYTE_LANES-1:0]    eff_dqs_in_load_lane = rdlvl_dqs_in_load_lane | i_cal_jwb_load_lane;
    wire                         jwb_cal_active       = |i_cal_jwb_load_lane;
    wire [4:0]                   eff_dqs_in_tap       = jwb_cal_active ? i_cal_jwb_tap : rdlvl_dqs_in_tap;

    // Per-lane read-data + read-valid (lane-aligned by ISERDESE2)
    wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] lane_rd_data;
    wire [NUM_BYTE_LANES-1:0]                      lane_rd_valid;

    ddr3_phy_lane_array #(
        .NUM_BYTE_LANES (NUM_BYTE_LANES),
        .DQ_BITS        (DQ_BITS),
        .RATIO          (SERDES_RATIO),
        .WR_DQS_DELAY_CK(WR_DQS_DELAY_CK),
        .WR_DQ_OE_DELAY_SYS(WR_DQ_OE_DELAY_SYS),
        .WR_DQ_OE_HOLD_SYS (WR_DQ_OE_HOLD_SYS),
        .RD_VALID_REQUIRE_ALL(RD_VALID_REQUIRE_ALL),
        .USE_IDELAYCTRL(!USE_EXTERNAL_CLOCKS)
    ) u_lanes (
        .i_clk_sys                (o_clk_sys),
        .i_clk_phy_x4             (o_clk_phy_x4),
        .i_clk_dq                 (o_clk_dq),
        .i_clk_ref_200            (clk_ref_200),
        .i_rst                    (phy_io_rst),

        .i_wr_en                  (wr_cmd_launch_q),
        .i_wr_data                (i_wr_data),
        .i_wr_dqs_en              (i_wr_valid), // sys-domain write-data strobe
        .i_rd_capture             (i_rd_capture),

        .o_rd_data                (lane_rd_data),
        .o_rd_valid_lane          (lane_rd_valid),
        .o_rd_valid_all           (o_rd_valid),

        .i_cal_dq_load_lane       (cal_dq_load_lane),
        .i_cal_dq_sel             (cal_dq_sel),
        .i_cal_dq_tap             (cal_dq_tap),

        .i_cal_dqs_in_load_lane   (eff_dqs_in_load_lane),
        .i_cal_dqs_in_tap         (eff_dqs_in_tap),

        .i_cal_dqs_out_load_lane  (wlvl_dqs_out_load_lane),
        .i_cal_dqs_out_tap        (wlvl_dqs_out_tap),
        .i_cal_dqs_toggle_en_lane (wlvl_dqs_toggle_en),

        .i_idelay_ready_ext       (i_idelay_ready_ext),
        .o_idelay_ready           (o_idelay_ready),

        .io_ddr3_dq               (io_ddr3_dq),
        .io_ddr3_dqs_p            (io_ddr3_dqs_p),
        .io_ddr3_dqs_n            (io_ddr3_dqs_n),
        .o_ddr3_dm                (o_ddr3_dm)
    );

    assign o_rd_data = lane_rd_data;
    assign o_rd_valid_lane = lane_rd_valid;

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
    wire _u = &{1'b0, i_wr_mask, i_idelay_ready_ext, mmcm_clkout_dq,
                SERDES_RATIO[0], 1'b0};
    /* verilator lint_on UNUSED */
endmodule
