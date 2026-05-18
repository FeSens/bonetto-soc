// Top-level for the Inspur YPCB-00338 (xc7k480t-ffg1156-2).
//
// Iter-5 (cal-gated DDR3 datapath + status mux):
//   * memtest_lite + wb_memory (BRAM) + ddr3_ctrl now share clk_sys
//     (100 MHz from the PHY MMCM). Before MMCM locks they are held
//     in reset by rst_sys.
//   * wb_decode2 routes memtest's address space:
//       adr[14]=0 → wb_memory (BRAM, 16K words = 64 KB)
//       adr[14]=1 → ddr3_ctrl (full controller-visible DDR3 space)
//   * memtest_lite gates target promotion to DDR3 on i_cal_done.
//     Until cal completes (or skip mode), it loops on BRAM. Once cal
//     completes AND a full BRAM sweep passes, memtest switches to DDR3.
//   * jtag_uart still runs on clk_50 with i_fpga_to_host driven by the
//     status mux. CDC across clk_sys → clk_50 for all status signals.

`default_nettype none

`include "soc_params.vh"

`ifdef DDR3_FULL_2CH
`define DDR3_FULL_CH0
`endif

module top (
    input  wire        clk_50,

    output wire [2:0]  led,

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
`ifdef DDR3_FULL_CH0
    inout  wire [71:0] ddr3_dq,
    inout  wire [8:0]  ddr3_dqs_p,
    inout  wire [8:0]  ddr3_dqs_n
`else
    inout  wire [39:0] ddr3_dq,
    inout  wire [4:0]  ddr3_dqs_p,
    inout  wire [4:0]  ddr3_dqs_n
`endif
`ifdef DDR3_FULL_2CH
    ,
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
`endif
);
    // ---- Power-on reset on clk_50 (16K cycles ≈ 320 µs @ 50 MHz) ----
    reg [13:0] por_ctr_50 = 14'h3FFF;
    always @(posedge clk_50) begin
        if (por_ctr_50 != 0) por_ctr_50 <= por_ctr_50 - 1'b1;
    end
    wire por_rst_50 = (por_ctr_50 != 0);

    // ---- DDR3 PHY clocks + reset (100 MHz controller clk_sys) ----
    wire clk_sys;
    wire clk_phy_x4;
    wire clk_dq;
    wire mmcm_locked;
    wire idelay_ready;

    reg [2:0] rst_sync_sys = 3'b111;
    always @(posedge clk_sys or posedge por_rst_50) begin
        if (por_rst_50)        rst_sync_sys <= 3'b111;
        else if (!mmcm_locked) rst_sync_sys <= 3'b111;
        else                   rst_sync_sys <= {rst_sync_sys[1:0], 1'b0};
    end
    wire rst_sys = rst_sync_sys[2];

    // =================================================================
    // {memtest_lite, jtag_wb_master} → arbiter → wb_decode2 → {wb_memory, ddr3_ctrl}
    // All on clk_sys.
    //
    // iter-7: a second WB master (jtag_wb_master) lives alongside memtest_lite
    // so the host can drive arbitrary WB transactions over JTAG. A priority
    // grant arbiter hands the bus to whichever master is requesting; if both
    // request, jwb wins (memtest is paused via i_pause anyway when host wants
    // direct control).
    // =================================================================
    localparam integer FABRIC_ADDR_W = `WB_ADDR_W;
`ifdef DDR3_FULL_2CH
    // Build-only dual-channel expansion: two 64-bit channels over BL8.
    // The global DDR3 word address uses bit 29 as channel select and
    // bits [28:0] as the per-channel MT41K256M8 address.
    localparam integer DDR3_MEMTEST_ADDR_W = 30;
    localparam integer DDR3_ACTIVE_BYTE_LANES = 8;
    localparam integer DDR3_SERDES_RATIO = 8;
    localparam integer DDR3_WB_BURST_WORD_BITS = 4;
    localparam integer DDR3_MEMTEST_DIRECT_ADDR = 1;
`elsif DDR3_FULL_CH0
    // Build-only CH0 expansion: 64 data bits over BL8, with physical lane 3
    // bypassed and the board ECC lane used as logical data lane 7.
    localparam integer DDR3_MEMTEST_ADDR_W = 29;
    localparam integer DDR3_ACTIVE_BYTE_LANES = 8;
    localparam integer DDR3_SERDES_RATIO = 8;
    localparam integer DDR3_WB_BURST_WORD_BITS = 4;
    localparam integer DDR3_MEMTEST_DIRECT_ADDR = 0;
`elsif DDR3_RATIO8_CH0
    // Diagnostic isolation mode: keep the validated 4-lane CH0 slice and
    // 25-bit address map, but exercise the RATIO=8 BL8 PHY sequencer.
    localparam integer DDR3_MEMTEST_ADDR_W = 25;
    localparam integer DDR3_ACTIVE_BYTE_LANES = 4;
    localparam integer DDR3_SERDES_RATIO = 8;
    localparam integer DDR3_WB_BURST_WORD_BITS = 0;
    localparam integer DDR3_MEMTEST_DIRECT_ADDR = 0;
`else
    localparam integer DDR3_MEMTEST_ADDR_W = 25;
    localparam integer DDR3_ACTIVE_BYTE_LANES = 4;
    localparam integer DDR3_SERDES_RATIO = 4;
    localparam integer DDR3_WB_BURST_WORD_BITS = 0;
    localparam integer DDR3_MEMTEST_DIRECT_ADDR = 0;
`endif
`ifdef DDR3_RATIO8_CH0
    // Hardware diagnostic: lanes 0-2 return the stable repeated-byte word at
    // BL8 sample 7, while lane 3 (physical byte lane 4) returns it at sample 0.
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_RD_SAMPLE_OFFSET_MAP = 16'h0777;
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_WR_SAMPLE_OFFSET_MAP = 16'h0000;
`elsif DDR3_FULL_CH0
    // Full CH0 keeps the validated lower-lane RATIO8 capture offsets.
    // Writes use the raw BL8 sample order; RATIO8 lower-lane hardware
    // validation did not need a launch-side sample shift.
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_RD_SAMPLE_OFFSET_MAP = 32'h0000_0777;
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_WR_SAMPLE_OFFSET_MAP = 32'h0000_0000;
`else
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_RD_SAMPLE_OFFSET_MAP =
        {DDR3_ACTIVE_BYTE_LANES{4'd0}};
    localparam [DDR3_ACTIVE_BYTE_LANES*4-1:0] DDR3_WR_SAMPLE_OFFSET_MAP =
        {DDR3_ACTIVE_BYTE_LANES{4'd0}};
`endif
`ifdef DDR3_JTAG_ONLY
    // Debug-only isolation mode: write one selected 32-bit word inside a BL8
    // burst without first preserving the rest of the burst through RMW.
    localparam integer DDR3_BURST_WRITE_RMW = 0;
`else
    localparam integer DDR3_BURST_WRITE_RMW = 1;
`endif
    localparam integer JWB_LOCAL_ADDR_W = 15;
    localparam integer JWB_DDR3_LOCAL_W = 14;
    localparam integer JWB_DDR3_HI_W = FABRIC_ADDR_W - JWB_DDR3_LOCAL_W;

    wire        m_cyc, m_stb, m_we;
    wire [FABRIC_ADDR_W-1:0] m_adr;
    wire [31:0] m_dat_w, m_dat_r;
    wire [3:0]  m_sel;
    wire        m_stall, m_ack, m_err;

    // Memtest-side master signals (output of memtest, input of arbiter).
    wire        mt_cyc, mt_stb, mt_we;
    wire [FABRIC_ADDR_W-1:0] mt_adr;
    wire [31:0] mt_dat_w;
    wire [3:0]  mt_sel;
    wire        mt_stall, mt_ack, mt_err;

    // JTAG-WB-master signals (output of jwb, input of arbiter).
    wire        jwb_cyc, jwb_stb, jwb_we;
    wire [14:0] jwb_adr;
    wire [31:0] jwb_dat_w;
    wire [3:0]  jwb_sel;
    wire        jwb_stall, jwb_ack, jwb_err;
    wire        jwb_busy, jwb_last_ack, jwb_last_err, jwb_halt_others;
    wire [31:0] jwb_data_echo, jwb_rd_data;
    wire [JWB_LOCAL_ADDR_W-1:0] jwb_addr_echo;
    wire [JWB_DDR3_HI_W-1:0] jwb_addr_hi_echo;

    wire [31:0] mtest_pass_ctr;
    wire [31:0] mtest_ddr3_pass_ctr;
    wire [31:0] mtest_err_ctr;
    wire [31:0] mtest_first_err_addr;
    wire [31:0] mtest_first_err_expected;
    wire [31:0] mtest_first_err_got;
    wire [31:0] mtest_sweep_ctr;
    wire [31:0] mtest_last_xor_expected;
    wire [31:0] mtest_last_xor_got;
    wire        mtest_checksum_err;
    wire        mtest_any_err;
    wire        mtest_target;
    wire [1:0]  mtest_pattern_idx;
    wire [2:0]  mt_led_unused;

`ifdef DDR3_FULL_CH0
    // Physical lane 3 is present in the online pin map but intentionally
    // bypassed by this build. Keep those package pins undriven.
    wire [7:0] ddr3_lane3_dq_unused;
    wire       ddr3_lane3_dqs_unused;

    genvar ddr3_lane3_i;
    generate
        for (ddr3_lane3_i = 0; ddr3_lane3_i < 8; ddr3_lane3_i = ddr3_lane3_i + 1) begin : g_ddr3_lane3_bypass
            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O  (ddr3_lane3_dq_unused[ddr3_lane3_i]),
                .IO (ddr3_dq[24 + ddr3_lane3_i]),
                .I  (1'b0),
                .T  (1'b1)
            );
        end
    endgenerate

    IOBUFDS #(.SLEW("FAST")) u_dqs_iobuf (
        .O   (ddr3_lane3_dqs_unused),
        .IO  (ddr3_dqs_p[3]),
        .IOB (ddr3_dqs_n[3]),
        .I   (1'b0),
        .T   (1'b1)
    );
`endif

`ifdef DDR3_FULL_2CH
    // Mirror the CH0 lane-3 bypass on CH1 for the build-only dual-channel
    // image; logical lane 7 is mapped onto the CH1 ECC byte lane.
    wire [7:0] ddr3_ch1_lane3_dq_unused;
    wire       ddr3_ch1_lane3_dqs_unused;

    genvar ddr3_ch1_lane3_i;
    generate
        for (ddr3_ch1_lane3_i = 0; ddr3_ch1_lane3_i < 8; ddr3_ch1_lane3_i = ddr3_ch1_lane3_i + 1) begin : g_ddr3_ch1_lane3_bypass
            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O  (ddr3_ch1_lane3_dq_unused[ddr3_ch1_lane3_i]),
                .IO (ddr3_ch1_dq[24 + ddr3_ch1_lane3_i]),
                .I  (1'b0),
                .T  (1'b1)
            );
        end
    endgenerate

    IOBUFDS #(.SLEW("FAST")) u_ch1_dqs_iobuf (
        .O   (ddr3_ch1_lane3_dqs_unused),
        .IO  (ddr3_ch1_dqs_p[3]),
        .IOB (ddr3_ch1_dqs_n[3]),
        .I   (1'b0),
        .T   (1'b1)
    );
`endif

    // Cal done signal lives in clk_sys (cal_seq runs there).
    wire ctrl_init_done;
    wire ctrl_init_error;
    wire [3:0] ctrl_init_error_code;
    wire [4:0] ctrl_init_state;
    wire       cal_done;
    wire       cal_error;
    wire [1:0] cal_error_code;
    wire [3:0] cal_seq_state;
    wire [3:0] cal_wlvl_state;
    wire [3:0] cal_rdlvl_state;

`ifdef DDR3_FULL_2CH
    wire ctrl_init_done_ch1;
    wire ctrl_init_error_ch1;
    wire [3:0] ctrl_init_error_code_ch1;
    wire [4:0] ctrl_init_state_ch1;
    wire       cal_done_ch1;
    wire       cal_error_ch1;
    wire [1:0] cal_error_code_ch1;
    wire [3:0] cal_seq_state_ch1;
    wire [3:0] cal_wlvl_state_ch1;
    wire [3:0] cal_rdlvl_state_ch1;
    wire       ddr3_all_cal_done = cal_done & cal_done_ch1;
`else
    wire       ddr3_all_cal_done = cal_done;
`endif

`ifdef DDR3_JTAG_ONLY
    assign mt_cyc = 1'b0;
    assign mt_stb = 1'b0;
    assign mt_we = 1'b0;
    assign mt_adr = {FABRIC_ADDR_W{1'b0}};
    assign mt_dat_w = 32'd0;
    assign mt_sel = 4'h0;

    assign mtest_pass_ctr = 32'd0;
    assign mtest_ddr3_pass_ctr = 32'd0;
    assign mtest_err_ctr = 32'd0;
    assign mtest_first_err_addr = 32'd0;
    assign mtest_first_err_expected = 32'd0;
    assign mtest_first_err_got = 32'd0;
    assign mtest_sweep_ctr = 32'd0;
    assign mtest_last_xor_expected = 32'd0;
    assign mtest_last_xor_got = 32'd0;
    assign mtest_checksum_err = 1'b0;
    assign mtest_any_err = 1'b0;
    assign mtest_target = 1'b1;
    assign mtest_pattern_idx = 2'd0;
    assign mt_led_unused = 3'b000;
`else
    memtest_lite #(
        .WB_ADDR_W(FABRIC_ADDR_W),
        .BRAM_ADDR_W(14),
        .DDR3_ADDR_W(DDR3_MEMTEST_ADDR_W),
        .DIRECT_DDR_ADDRESS(DDR3_MEMTEST_DIRECT_ADDR)
    ) mtest (
        .i_clk                (clk_sys),
        .i_rst                (rst_sys),
        .i_cal_done           (ddr3_all_cal_done),
        .i_pause              (jwb_halt_others),
        .o_wb_cyc             (mt_cyc),
        .o_wb_stb             (mt_stb),
        .o_wb_we              (mt_we),
        .o_wb_adr             (mt_adr),
        .o_wb_dat             (mt_dat_w),
        .o_wb_sel             (mt_sel),
        .i_wb_stall           (mt_stall),
        .i_wb_ack             (mt_ack),
        .i_wb_dat             (m_dat_r),
        .i_wb_err             (mt_err),
        .o_led                (mt_led_unused),
        .o_pass_ctr           (mtest_pass_ctr),
        .o_ddr3_pass_ctr      (mtest_ddr3_pass_ctr),
        .o_err_ctr            (mtest_err_ctr),
        .o_first_err_addr     (mtest_first_err_addr),
        .o_first_err_expected (mtest_first_err_expected),
        .o_first_err_got      (mtest_first_err_got),
        .o_sweep_ctr          (mtest_sweep_ctr),
        .o_last_xor_expected  (mtest_last_xor_expected),
        .o_last_xor_got       (mtest_last_xor_got),
        .o_checksum_err       (mtest_checksum_err),
        .o_any_err            (mtest_any_err),
        .o_target             (mtest_target),
        .o_pattern_idx        (mtest_pattern_idx)
    );
`endif

    // -----------------------------------------------------------------
    // CDC: host_to_fpga + write event from clk_50 to clk_sys.
    // Hold each host word in clk_50 and transfer an event toggle into clk_sys.
    // The JTAG write cadence is much slower than either clock, so by the time
    // the toggle edge arrives the held word has crossed the data synchronizer.
    // -----------------------------------------------------------------
    wire [31:0] host_to_fpga;
    wire        host_to_fpga_valid_50;
    reg  [31:0] h2f_hold_50 = 32'd0;
    reg         h2f_toggle_50 = 1'b0;
    always @(posedge clk_50) begin
        if (por_rst_50) begin
            h2f_hold_50   <= 32'd0;
            h2f_toggle_50 <= 1'b0;
        end else if (host_to_fpga_valid_50) begin
            h2f_hold_50   <= host_to_fpga;
            h2f_toggle_50 <= ~h2f_toggle_50;
        end
    end

    reg  [31:0] h2f_data_q1, h2f_data_q2;
    reg  [2:0]  h2f_toggle_sync;
    reg  [31:0] h2f_cmd_sys;
    reg         h2f_cmd_valid_sys;
    always @(posedge clk_sys) begin
        if (rst_sys) begin
            h2f_data_q1      <= 32'd0;
            h2f_data_q2      <= 32'd0;
            h2f_toggle_sync  <= 3'b000;
            h2f_cmd_sys      <= 32'd0;
            h2f_cmd_valid_sys <= 1'b0;
        end else begin
            h2f_data_q1      <= h2f_hold_50;
            h2f_data_q2      <= h2f_data_q1;
            h2f_toggle_sync  <= {h2f_toggle_sync[1:0], h2f_toggle_50};
            h2f_cmd_valid_sys <= h2f_toggle_sync[2] ^ h2f_toggle_sync[1];
            if (h2f_toggle_sync[2] ^ h2f_toggle_sync[1])
                h2f_cmd_sys <= h2f_data_q2;
        end
    end

    wire [8:0] jwb_cal_load_lane;
    wire [4:0] jwb_cal_tap;
    wire       jwb_phase_req;
    wire       jwb_phase_inc;
    wire       phy_phase_busy;
    wire [7:0] phy_phase_count;

    jtag_wb_master #(
        .WB_ADDR_W(JWB_LOCAL_ADDR_W),
        .WB_DATA_W(32),
        .NUM_BYTE_LANES(9)
    ) u_jwb (
        .i_clk         (clk_sys),
        .i_rst         (rst_sys),
        .i_cmd_word    (h2f_cmd_sys),
        .i_cmd_valid   (h2f_cmd_valid_sys),
        .o_wb_cyc      (jwb_cyc),
        .o_wb_stb      (jwb_stb),
        .o_wb_we       (jwb_we),
        .o_wb_adr      (jwb_adr),
        .o_wb_dat      (jwb_dat_w),
        .o_wb_sel      (jwb_sel),
        .i_wb_stall    (jwb_stall),
        .i_wb_ack      (jwb_ack),
        .i_wb_dat      (m_dat_r),
        .i_wb_err      (jwb_err),
        .o_busy        (jwb_busy),
        .o_last_ack    (jwb_last_ack),
        .o_last_err    (jwb_last_err),
        .o_addr        (jwb_addr_echo),
        .o_addr_hi     (jwb_addr_hi_echo),
        .o_data        (jwb_data_echo),
        .o_rd_data     (jwb_rd_data),
        .o_halt_others (jwb_halt_others),
        .o_cal_load_lane (jwb_cal_load_lane),
        .o_cal_tap       (jwb_cal_tap),
        .o_phase_req     (jwb_phase_req),
        .o_phase_inc     (jwb_phase_inc)
    );

    // Priority-grant arbiter. jwb_grant flips when jwb wants the bus and
    // memtest is idle; it stays asserted until jwb drops cyc, giving jwb
    // a clean WB cycle without ever interrupting an in-flight mt cycle.
    reg jwb_grant;
    always @(posedge clk_sys) begin
        if (rst_sys) jwb_grant <= 1'b0;
        else if (jwb_grant) begin
            if (!jwb_cyc) jwb_grant <= 1'b0;
        end else begin
            if (jwb_cyc && !mt_cyc) jwb_grant <= 1'b1;
        end
    end

    assign m_cyc   = jwb_grant ? jwb_cyc   : mt_cyc;
    assign m_stb   = jwb_grant ? jwb_stb   : mt_stb;
    assign m_we    = jwb_grant ? jwb_we    : mt_we;
    assign m_adr   = jwb_grant ? {{(FABRIC_ADDR_W-15){1'b0}}, jwb_adr} : mt_adr;
    assign m_dat_w = jwb_grant ? jwb_dat_w : mt_dat_w;
    assign m_sel   = jwb_grant ? jwb_sel   : mt_sel;

    assign mt_stall = jwb_grant ? 1'b1 : m_stall;
    assign mt_ack   = jwb_grant ? 1'b0 : m_ack;
    assign mt_err   = jwb_grant ? 1'b0 : m_err;

    assign jwb_stall = jwb_grant ? m_stall : 1'b1;
    assign jwb_ack   = jwb_grant ? m_ack   : 1'b0;
    assign jwb_err   = jwb_grant ? m_err   : 1'b0;

    wire        bram_cyc, bram_stb, bram_we;
    wire [FABRIC_ADDR_W-1:0] bram_adr;
    wire [31:0] bram_dat_w;
    wire [3:0]  bram_sel;
    wire        bram_stall, bram_ack, bram_err;
    wire [31:0] bram_dat_r;

    wire        d3_cyc, d3_stb, d3_we;
    wire [FABRIC_ADDR_W-1:0] d3_adr;
    wire [31:0] d3_dat_w;
    wire [3:0]  d3_sel;
    wire        d3_stall, d3_ack, d3_err;
    wire [31:0] d3_dat_r;
`ifdef DDR3_FULL_2CH
    wire        full2ch_d3_select = jwb_grant ? m_adr[14] : mtest_target;
    wire [FABRIC_ADDR_W-1:0] d3_global_adr = jwb_grant ?
        {jwb_addr_hi_echo, m_adr[JWB_DDR3_LOCAL_W-1:0]} :
        m_adr;
    wire        d3_ch_sel = d3_global_adr[29];
    wire [FABRIC_ADDR_W-1:0] d3_ctrl_adr =
        {{(FABRIC_ADDR_W-29){1'b0}}, d3_global_adr[28:0]};

    assign bram_cyc   = m_cyc & ~full2ch_d3_select;
    assign bram_stb   = m_stb & ~full2ch_d3_select;
    assign bram_we    = m_we;
    assign bram_adr   = m_adr;
    assign bram_dat_w = m_dat_w;
    assign bram_sel   = m_sel;

    assign d3_cyc   = m_cyc & full2ch_d3_select;
    assign d3_stb   = m_stb & full2ch_d3_select;
    assign d3_we    = m_we;
    assign d3_adr   = d3_global_adr;
    assign d3_dat_w = m_dat_w;
    assign d3_sel   = m_sel;

    assign m_stall = full2ch_d3_select ? d3_stall : bram_stall;
    assign m_ack   = full2ch_d3_select ? d3_ack   : bram_ack;
    assign m_err   = full2ch_d3_select ? d3_err   : bram_err;
    assign m_dat_r = full2ch_d3_select ? d3_dat_r : bram_dat_r;
`else
    wire [FABRIC_ADDR_W-1:0] d3_ctrl_adr = (jwb_grant && m_adr[14]) ?
        {jwb_addr_hi_echo, d3_adr[JWB_DDR3_LOCAL_W-1:0]} :
        {{(FABRIC_ADDR_W-DDR3_MEMTEST_ADDR_W){1'b0}},
         d3_adr[DDR3_MEMTEST_ADDR_W:JWB_LOCAL_ADDR_W],
         d3_adr[JWB_DDR3_LOCAL_W-1:0]};
    wire        d3_ch_sel = 1'b0;

    wb_decode2 #(
        .WB_DATA_W(32),
        .WB_ADDR_W(FABRIC_ADDR_W),
        .SEL_BIT  (14)
    ) xbar (
        .i_clk     (clk_sys),
        .i_rst     (rst_sys),
        .i_wb_cyc  (m_cyc),
        .i_wb_stb  (m_stb),
        .i_wb_we   (m_we),
        .i_wb_adr  (m_adr),
        .i_wb_dat  (m_dat_w),
        .i_wb_sel  (m_sel),
        .o_wb_stall(m_stall),
        .o_wb_ack  (m_ack),
        .o_wb_dat  (m_dat_r),
        .o_wb_err  (m_err),
        .o_s0_cyc  (bram_cyc),
        .o_s0_stb  (bram_stb),
        .o_s0_we   (bram_we),
        .o_s0_adr  (bram_adr),
        .o_s0_dat  (bram_dat_w),
        .o_s0_sel  (bram_sel),
        .i_s0_stall(bram_stall),
        .i_s0_ack  (bram_ack),
        .i_s0_dat  (bram_dat_r),
        .i_s0_err  (bram_err),
        .o_s1_cyc  (d3_cyc),
        .o_s1_stb  (d3_stb),
        .o_s1_we   (d3_we),
        .o_s1_adr  (d3_adr),
        .o_s1_dat  (d3_dat_w),
        .o_s1_sel  (d3_sel),
        .i_s1_stall(d3_stall),
        .i_s1_ack  (d3_ack),
        .i_s1_dat  (d3_dat_r),
        .i_s1_err  (d3_err)
    );
`endif

    wb_memory #(.WB_DATA_W(32), .WB_ADDR_W(14)) mem (
        .i_clk      (clk_sys),
        .i_rst      (rst_sys),
        .i_wb_cyc   (bram_cyc),
        .i_wb_stb   (bram_stb),
        .i_wb_we    (bram_we),
        .i_wb_adr   (bram_adr[13:0]),
        .i_wb_dat   (bram_dat_w),
        .i_wb_sel   (bram_sel),
        .o_wb_stall (bram_stall),
        .o_wb_ack   (bram_ack),
        .o_wb_dat   (bram_dat_r),
        .o_wb_err   (bram_err)
    );

    // =================================================================
    // DDR3 stack on clk_sys
    // =================================================================
    wire        d3_ch0_cyc = d3_cyc & ~d3_ch_sel;
    wire        d3_ch0_stb = d3_stb & ~d3_ch_sel;
    wire        d3_ch0_we  = d3_we;
    wire [FABRIC_ADDR_W-1:0] d3_ch0_adr = d3_ctrl_adr;
    wire [31:0] d3_ch0_dat_w = d3_dat_w;
    wire [3:0]  d3_ch0_sel = d3_sel;
    wire        d3_ch0_stall, d3_ch0_ack, d3_ch0_err;
    wire [31:0] d3_ch0_dat_r;

`ifdef DDR3_FULL_2CH
    wire        d3_ch1_cyc = d3_cyc & d3_ch_sel;
    wire        d3_ch1_stb = d3_stb & d3_ch_sel;
    wire        d3_ch1_we  = d3_we;
    wire [FABRIC_ADDR_W-1:0] d3_ch1_adr = d3_ctrl_adr;
    wire [31:0] d3_ch1_dat_w = d3_dat_w;
    wire [3:0]  d3_ch1_sel = d3_sel;
    wire        d3_ch1_stall, d3_ch1_ack, d3_ch1_err;
    wire [31:0] d3_ch1_dat_r;

    assign d3_stall = d3_ch_sel ? d3_ch1_stall : d3_ch0_stall;
    assign d3_ack   = d3_ch_sel ? d3_ch1_ack   : d3_ch0_ack;
    assign d3_err   = d3_ch_sel ? d3_ch1_err   : d3_ch0_err;
    assign d3_dat_r = d3_ch_sel ? d3_ch1_dat_r : d3_ch0_dat_r;
`else
    assign d3_stall = d3_ch0_stall;
    assign d3_ack   = d3_ch0_ack;
    assign d3_err   = d3_ch0_err;
    assign d3_dat_r = d3_ch0_dat_r;
`endif

    wire        ctrl_reset_n;
    wire        ctrl_cke;
    wire        ctrl_odt;
    wire        ctrl_cs_n, ctrl_ras_n, ctrl_cas_n, ctrl_we_n;
    wire [2:0]  ctrl_ba;
    wire [14:0] ctrl_addr;

    wire        phy_mpr_req;
    wire [12:0] phy_mpr_addr;
    wire        ctrl_mpr_busy;

    wire        cal_mrs_req;
    wire [2:0]  cal_mrs_ba;
    wire [14:0] cal_mrs_addr;
    wire        ctrl_mrs_busy;

    wire        cal_wlvl_start, cal_wlvl_done, cal_wlvl_error;
    wire        cal_rdlvl_start, cal_rdlvl_done, cal_rdlvl_error;
    localparam integer DDR3_DQ_BITS = 8;
    localparam integer DDR3_PHY_DATA_W =
        DDR3_ACTIVE_BYTE_LANES * DDR3_DQ_BITS * DDR3_SERDES_RATIO;

    wire        phy_wr_valid;
    wire [DDR3_PHY_DATA_W-1:0] phy_wr_data;
    wire        phy_rd_capture;
    wire        phy_rd_valid;
    wire [DDR3_ACTIVE_BYTE_LANES-1:0] phy_rd_valid_lane;
    wire [DDR3_PHY_DATA_W-1:0] phy_rd_data;
`ifdef DDR3_DEBUG_PHY_RD_DATA
    localparam integer PHY_RD_DATA_STATUS_WORDS = DDR3_PHY_DATA_W / 32;
    reg  [DDR3_PHY_DATA_W-1:0] phy_rd_data_last = {DDR3_PHY_DATA_W{1'b0}};
    reg  [31:0] phy_rd_data_status_word_sys = 32'hAB20_0000;
    integer phy_rd_data_word_i;

    always @(posedge clk_sys) begin
        if (rst_sys) begin
            phy_rd_data_last <= {DDR3_PHY_DATA_W{1'b0}};
            phy_rd_data_status_word_sys <= 32'hAB20_0000;
        end else begin
            if (phy_rd_valid)
                phy_rd_data_last <= phy_rd_data;
            if (h2f_cmd_valid_sys && (h2f_cmd_sys[7:5] == 3'b001)) begin
                phy_rd_data_status_word_sys <= {16'hAB20, 11'd0, h2f_cmd_sys[4:0]};
                for (phy_rd_data_word_i = 0;
                     phy_rd_data_word_i < PHY_RD_DATA_STATUS_WORDS;
                     phy_rd_data_word_i = phy_rd_data_word_i + 1) begin
                    if (h2f_cmd_sys[4:0] == phy_rd_data_word_i[4:0])
                        phy_rd_data_status_word_sys <=
                            phy_rd_data_last[phy_rd_data_word_i*32 +: 32];
                end
            end
        end
    end
`endif

    ddr3_ctrl #(
        .WB_DATA_W(32),
        .WB_ADDR_W(FABRIC_ADDR_W),
        .DQ_BITS(DDR3_DQ_BITS),
        .NUM_BYTE_LANES(DDR3_ACTIVE_BYTE_LANES),
        .SERDES_RATIO(DDR3_SERDES_RATIO),
        .WB_BURST_WORD_BITS(DDR3_WB_BURST_WORD_BITS),
        .BURST_WRITE_RMW(DDR3_BURST_WRITE_RMW),
        .RD_SAMPLE_OFFSET_MAP(DDR3_RD_SAMPLE_OFFSET_MAP),
        .WR_SAMPLE_OFFSET_MAP(DDR3_WR_SAMPLE_OFFSET_MAP)
    ) u_ddr3_ctrl (
        .i_clk          (clk_sys),
        .i_clk_phy      (clk_sys),
        .i_rst          (rst_sys),
        .i_wb_cyc       (d3_ch0_cyc),
        .i_wb_stb       (d3_ch0_stb),
        .i_wb_we        (d3_ch0_we),
        .i_wb_adr       (d3_ch0_adr),
        .i_wb_dat       (d3_ch0_dat_w),
        .i_wb_sel       (d3_ch0_sel),
        .o_wb_stall     (d3_ch0_stall),
        .o_wb_ack       (d3_ch0_ack),
        .o_wb_dat       (d3_ch0_dat_r),
        .o_wb_err       (d3_ch0_err),
        .o_ddr3_reset_n (ctrl_reset_n),
        .o_ddr3_cke     (ctrl_cke),
        .o_ddr3_odt     (ctrl_odt),
        .o_ddr3_cs_n    (ctrl_cs_n),
        .o_ddr3_ras_n   (ctrl_ras_n),
        .o_ddr3_cas_n   (ctrl_cas_n),
        .o_ddr3_we_n    (ctrl_we_n),
        .o_ddr3_ba      (ctrl_ba),
        .o_ddr3_addr    (ctrl_addr),
        .i_phy_rd_data   (phy_rd_data),
        .i_phy_rd_valid  (phy_rd_valid),
        .o_phy_wr_data   (phy_wr_data),
        .o_phy_wr_valid  (phy_wr_valid),
        .o_phy_rd_capture(phy_rd_capture),
        .i_mpr_req      (phy_mpr_req),
        .i_mpr_addr     (phy_mpr_addr),
        .o_mpr_busy     (ctrl_mpr_busy),
        .i_mrs_req      (cal_mrs_req),
        .i_mrs_ba       (cal_mrs_ba),
        .i_mrs_addr     (cal_mrs_addr),
        .o_mrs_busy     (ctrl_mrs_busy),
        .o_init_done        (ctrl_init_done),
        .o_init_error       (ctrl_init_error),
        .o_init_error_code  (ctrl_init_error_code),
        .o_init_state       (ctrl_init_state)
    );

    ddr3_cal_seq #(.SKIP_WLVL(1), .SKIP_RDLVL(1)) u_cal_seq (
        .i_clk            (clk_sys),
        .i_rst            (rst_sys),
        .i_init_done      (ctrl_init_done),
        .o_wlvl_start     (cal_wlvl_start),
        .i_wlvl_done      (cal_wlvl_done),
        .i_wlvl_error     (cal_wlvl_error),
        .o_rdlvl_start    (cal_rdlvl_start),
        .i_rdlvl_done     (cal_rdlvl_done),
        .i_rdlvl_error    (cal_rdlvl_error),
        .o_mrs_req        (cal_mrs_req),
        .o_mrs_ba         (cal_mrs_ba),
        .o_mrs_addr       (cal_mrs_addr),
        .i_mrs_busy       (ctrl_mrs_busy),
        .o_cal_done       (cal_done),
        .o_cal_error      (cal_error),
        .o_cal_error_code (cal_error_code),
        .o_state          (cal_seq_state)
    );

    ddr3_phy #(
        .DQ_BITS(DDR3_DQ_BITS),
        .NUM_BYTE_LANES(DDR3_ACTIVE_BYTE_LANES),
        .SERDES_RATIO(DDR3_SERDES_RATIO),
        .USE_EXTERNAL_CLOCKS(0)
    ) u_ddr3_phy (
        .i_clk_ref      (clk_50),
        .i_rst_ref      (por_rst_50),
        .i_clk_sys_ext  (1'b0),
        .i_clk_phy_x4_ext(1'b0),
        .i_clk_dq_ext   (1'b0),
        .i_locked_ext   (1'b0),
        .i_idelay_ready_ext(1'b0),
        .o_clk_sys      (clk_sys),
        .o_clk_phy_x4   (clk_phy_x4),
        .o_clk_dq       (clk_dq),
        .o_locked       (mmcm_locked),
        .o_idelay_ready (idelay_ready),

        .i_cmd_valid    (1'b1),
        .i_cmd          ({ctrl_cs_n, ctrl_ras_n, ctrl_cas_n, ctrl_we_n}),
        .i_cmd_ba       (ctrl_ba),
        .i_cmd_addr     (ctrl_addr),
        .i_cmd_cke      (ctrl_cke),
        .i_cmd_reset_n  (ctrl_reset_n),
        .i_cmd_odt      (ctrl_odt),

        .i_wr_valid     (phy_wr_valid),
        .i_wr_data      (phy_wr_data),
        .i_wr_mask      ({DDR3_ACTIVE_BYTE_LANES{1'b0}}),
        .i_rd_capture   (phy_rd_capture),

        .o_rd_valid     (phy_rd_valid),
        .o_rd_valid_lane(phy_rd_valid_lane),
        .o_rd_data      (phy_rd_data),

        .i_cal_start_wlvl  (cal_wlvl_start),
        .o_cal_done_wlvl   (cal_wlvl_done),
        .o_cal_error_wlvl  (cal_wlvl_error),
        .o_cal_state_wlvl  (cal_wlvl_state),
        .i_cal_start_rdlvl (cal_rdlvl_start),
        .o_cal_done_rdlvl  (cal_rdlvl_done),
        .o_cal_error_rdlvl (cal_rdlvl_error),
        .o_cal_state_rdlvl (cal_rdlvl_state),
        .o_mpr_read_req    (phy_mpr_req),
        .o_mpr_read_addr   (phy_mpr_addr),

        .i_cal_jwb_load_lane (jwb_cal_load_lane[DDR3_ACTIVE_BYTE_LANES-1:0]),
        .i_cal_jwb_tap       (jwb_cal_tap),

        .i_phase_req     (jwb_phase_req),
        .i_phase_inc     (jwb_phase_inc),
        .o_phase_busy    (phy_phase_busy),
        .o_phase_count   (phy_phase_count),

        .o_ddr3_ck_p    (ddr3_ck_p),
        .o_ddr3_ck_n    (ddr3_ck_n),
        .o_ddr3_cke     (ddr3_cke),
        .o_ddr3_reset_n (ddr3_reset_n),
        .o_ddr3_cs_n    (ddr3_cs_n),
        .o_ddr3_ras_n   (ddr3_ras_n),
        .o_ddr3_cas_n   (ddr3_cas_n),
        .o_ddr3_we_n    (ddr3_we_n),
        .o_ddr3_odt     (ddr3_odt),
        .o_ddr3_ba      (ddr3_ba),
        .o_ddr3_addr    (ddr3_addr),
`ifdef DDR3_FULL_CH0
        // Full CH0 build-only map from the online MEMORY_CH0.ucf: skip
        // physical lane 3 and use the ECC lane as logical data lane 7.
        .io_ddr3_dq     ({ddr3_dq[71:64], ddr3_dq[63:56], ddr3_dq[55:48],
                          ddr3_dq[47:40], ddr3_dq[39:32], ddr3_dq[23:0]}),
        .io_ddr3_dqs_p  ({ddr3_dqs_p[8], ddr3_dqs_p[7], ddr3_dqs_p[6],
                          ddr3_dqs_p[5], ddr3_dqs_p[4], ddr3_dqs_p[2:0]}),
        .io_ddr3_dqs_n  ({ddr3_dqs_n[8], ddr3_dqs_n[7], ddr3_dqs_n[6],
                          ddr3_dqs_n[5], ddr3_dqs_n[4], ddr3_dqs_n[2:0]}),
`else
        // Physical lane 3 currently reads as a stuck-zero byte on YPCB-00338.
        // Use lanes 0,1,2,4 as the validated 32-bit slice while keeping the
        // controller-facing byte order contiguous.
        .io_ddr3_dq     ({ddr3_dq[39:32], ddr3_dq[23:0]}),
        .io_ddr3_dqs_p  ({ddr3_dqs_p[4],  ddr3_dqs_p[2:0]}),
        .io_ddr3_dqs_n  ({ddr3_dqs_n[4],  ddr3_dqs_n[2:0]}),
`endif
        .o_ddr3_dm      ()
    );

`ifdef DDR3_FULL_2CH
    wire        ctrl_reset_n_ch1;
    wire        ctrl_cke_ch1;
    wire        ctrl_odt_ch1;
    wire        ctrl_cs_n_ch1, ctrl_ras_n_ch1, ctrl_cas_n_ch1, ctrl_we_n_ch1;
    wire [2:0]  ctrl_ba_ch1;
    wire [14:0] ctrl_addr_ch1;

    wire        phy_mpr_req_ch1;
    wire [12:0] phy_mpr_addr_ch1;
    wire        ctrl_mpr_busy_ch1;

    wire        cal_mrs_req_ch1;
    wire [2:0]  cal_mrs_ba_ch1;
    wire [14:0] cal_mrs_addr_ch1;
    wire        ctrl_mrs_busy_ch1;

    wire        cal_wlvl_start_ch1, cal_wlvl_done_ch1, cal_wlvl_error_ch1;
    wire        cal_rdlvl_start_ch1, cal_rdlvl_done_ch1, cal_rdlvl_error_ch1;

    wire        phy_wr_valid_ch1;
    wire [DDR3_PHY_DATA_W-1:0] phy_wr_data_ch1;
    wire        phy_rd_capture_ch1;
    wire        phy_rd_valid_ch1;
    wire [DDR3_ACTIVE_BYTE_LANES-1:0] phy_rd_valid_lane_ch1;
    wire [DDR3_PHY_DATA_W-1:0] phy_rd_data_ch1;

    ddr3_ctrl #(
        .WB_DATA_W(32),
        .WB_ADDR_W(FABRIC_ADDR_W),
        .DQ_BITS(DDR3_DQ_BITS),
        .NUM_BYTE_LANES(DDR3_ACTIVE_BYTE_LANES),
        .SERDES_RATIO(DDR3_SERDES_RATIO),
        .WB_BURST_WORD_BITS(DDR3_WB_BURST_WORD_BITS),
        .BURST_WRITE_RMW(DDR3_BURST_WRITE_RMW),
        .RD_SAMPLE_OFFSET_MAP(DDR3_RD_SAMPLE_OFFSET_MAP),
        .WR_SAMPLE_OFFSET_MAP(DDR3_WR_SAMPLE_OFFSET_MAP)
    ) u_ddr3_ctrl_ch1 (
        .i_clk          (clk_sys),
        .i_clk_phy      (clk_sys),
        .i_rst          (rst_sys),
        .i_wb_cyc       (d3_ch1_cyc),
        .i_wb_stb       (d3_ch1_stb),
        .i_wb_we        (d3_ch1_we),
        .i_wb_adr       (d3_ch1_adr),
        .i_wb_dat       (d3_ch1_dat_w),
        .i_wb_sel       (d3_ch1_sel),
        .o_wb_stall     (d3_ch1_stall),
        .o_wb_ack       (d3_ch1_ack),
        .o_wb_dat       (d3_ch1_dat_r),
        .o_wb_err       (d3_ch1_err),
        .o_ddr3_reset_n (ctrl_reset_n_ch1),
        .o_ddr3_cke     (ctrl_cke_ch1),
        .o_ddr3_odt     (ctrl_odt_ch1),
        .o_ddr3_cs_n    (ctrl_cs_n_ch1),
        .o_ddr3_ras_n   (ctrl_ras_n_ch1),
        .o_ddr3_cas_n   (ctrl_cas_n_ch1),
        .o_ddr3_we_n    (ctrl_we_n_ch1),
        .o_ddr3_ba      (ctrl_ba_ch1),
        .o_ddr3_addr    (ctrl_addr_ch1),
        .i_phy_rd_data   (phy_rd_data_ch1),
        .i_phy_rd_valid  (phy_rd_valid_ch1),
        .o_phy_wr_data   (phy_wr_data_ch1),
        .o_phy_wr_valid  (phy_wr_valid_ch1),
        .o_phy_rd_capture(phy_rd_capture_ch1),
        .i_mpr_req      (phy_mpr_req_ch1),
        .i_mpr_addr     (phy_mpr_addr_ch1),
        .o_mpr_busy     (ctrl_mpr_busy_ch1),
        .i_mrs_req      (cal_mrs_req_ch1),
        .i_mrs_ba       (cal_mrs_ba_ch1),
        .i_mrs_addr     (cal_mrs_addr_ch1),
        .o_mrs_busy     (ctrl_mrs_busy_ch1),
        .o_init_done        (ctrl_init_done_ch1),
        .o_init_error       (ctrl_init_error_ch1),
        .o_init_error_code  (ctrl_init_error_code_ch1),
        .o_init_state       (ctrl_init_state_ch1)
    );

    ddr3_cal_seq #(.SKIP_WLVL(1), .SKIP_RDLVL(1)) u_cal_seq_ch1 (
        .i_clk            (clk_sys),
        .i_rst            (rst_sys),
        .i_init_done      (ctrl_init_done_ch1),
        .o_wlvl_start     (cal_wlvl_start_ch1),
        .i_wlvl_done      (cal_wlvl_done_ch1),
        .i_wlvl_error     (cal_wlvl_error_ch1),
        .o_rdlvl_start    (cal_rdlvl_start_ch1),
        .i_rdlvl_done     (cal_rdlvl_done_ch1),
        .i_rdlvl_error    (cal_rdlvl_error_ch1),
        .o_mrs_req        (cal_mrs_req_ch1),
        .o_mrs_ba         (cal_mrs_ba_ch1),
        .o_mrs_addr       (cal_mrs_addr_ch1),
        .i_mrs_busy       (ctrl_mrs_busy_ch1),
        .o_cal_done       (cal_done_ch1),
        .o_cal_error      (cal_error_ch1),
        .o_cal_error_code (cal_error_code_ch1),
        .o_state          (cal_seq_state_ch1)
    );

    wire clk_sys_ch1_unused;
    wire clk_phy_x4_ch1_unused;
    wire clk_dq_ch1_unused;
    wire mmcm_locked_ch1_unused;
    wire idelay_ready_ch1;
    wire phy_phase_busy_ch1;
    wire [7:0] phy_phase_count_ch1;

    ddr3_phy #(
        .DQ_BITS(DDR3_DQ_BITS),
        .NUM_BYTE_LANES(DDR3_ACTIVE_BYTE_LANES),
        .SERDES_RATIO(DDR3_SERDES_RATIO),
        .USE_EXTERNAL_CLOCKS(1)
    ) u_ddr3_phy_ch1 (
        .i_clk_ref      (clk_50),
        .i_rst_ref      (por_rst_50),
        .i_clk_sys_ext  (clk_sys),
        .i_clk_phy_x4_ext(clk_phy_x4),
        .i_clk_dq_ext   (clk_dq),
        .i_locked_ext   (mmcm_locked),
        .i_idelay_ready_ext(idelay_ready),
        .o_clk_sys      (clk_sys_ch1_unused),
        .o_clk_phy_x4   (clk_phy_x4_ch1_unused),
        .o_clk_dq       (clk_dq_ch1_unused),
        .o_locked       (mmcm_locked_ch1_unused),
        .o_idelay_ready (idelay_ready_ch1),

        .i_cmd_valid    (1'b1),
        .i_cmd          ({ctrl_cs_n_ch1, ctrl_ras_n_ch1, ctrl_cas_n_ch1, ctrl_we_n_ch1}),
        .i_cmd_ba       (ctrl_ba_ch1),
        .i_cmd_addr     (ctrl_addr_ch1),
        .i_cmd_cke      (ctrl_cke_ch1),
        .i_cmd_reset_n  (ctrl_reset_n_ch1),
        .i_cmd_odt      (ctrl_odt_ch1),

        .i_wr_valid     (phy_wr_valid_ch1),
        .i_wr_data      (phy_wr_data_ch1),
        .i_wr_mask      ({DDR3_ACTIVE_BYTE_LANES{1'b0}}),
        .i_rd_capture   (phy_rd_capture_ch1),

        .o_rd_valid     (phy_rd_valid_ch1),
        .o_rd_valid_lane(phy_rd_valid_lane_ch1),
        .o_rd_data      (phy_rd_data_ch1),

        .i_cal_start_wlvl  (cal_wlvl_start_ch1),
        .o_cal_done_wlvl   (cal_wlvl_done_ch1),
        .o_cal_error_wlvl  (cal_wlvl_error_ch1),
        .o_cal_state_wlvl  (cal_wlvl_state_ch1),
        .i_cal_start_rdlvl (cal_rdlvl_start_ch1),
        .o_cal_done_rdlvl  (cal_rdlvl_done_ch1),
        .o_cal_error_rdlvl (cal_rdlvl_error_ch1),
        .o_cal_state_rdlvl (cal_rdlvl_state_ch1),
        .o_mpr_read_req    (phy_mpr_req_ch1),
        .o_mpr_read_addr   (phy_mpr_addr_ch1),

        .i_cal_jwb_load_lane ({DDR3_ACTIVE_BYTE_LANES{1'b0}}),
        .i_cal_jwb_tap       (jwb_cal_tap),

        .i_phase_req     (1'b0),
        .i_phase_inc     (1'b0),
        .o_phase_busy    (phy_phase_busy_ch1),
        .o_phase_count   (phy_phase_count_ch1),

        .o_ddr3_ck_p    (ddr3_ch1_ck_p),
        .o_ddr3_ck_n    (ddr3_ch1_ck_n),
        .o_ddr3_cke     (ddr3_ch1_cke),
        .o_ddr3_reset_n (ddr3_ch1_reset_n),
        .o_ddr3_cs_n    (ddr3_ch1_cs_n),
        .o_ddr3_ras_n   (ddr3_ch1_ras_n),
        .o_ddr3_cas_n   (ddr3_ch1_cas_n),
        .o_ddr3_we_n    (ddr3_ch1_we_n),
        .o_ddr3_odt     (ddr3_ch1_odt),
        .o_ddr3_ba      (ddr3_ch1_ba),
        .o_ddr3_addr    (ddr3_ch1_addr),
        .io_ddr3_dq     ({ddr3_ch1_dq[71:64], ddr3_ch1_dq[63:56],
                          ddr3_ch1_dq[55:48], ddr3_ch1_dq[47:40],
                          ddr3_ch1_dq[39:32], ddr3_ch1_dq[23:0]}),
        .io_ddr3_dqs_p  ({ddr3_ch1_dqs_p[8], ddr3_ch1_dqs_p[7],
                          ddr3_ch1_dqs_p[6], ddr3_ch1_dqs_p[5],
                          ddr3_ch1_dqs_p[4], ddr3_ch1_dqs_p[2:0]}),
        .io_ddr3_dqs_n  ({ddr3_ch1_dqs_n[8], ddr3_ch1_dqs_n[7],
                          ddr3_ch1_dqs_n[6], ddr3_ch1_dqs_n[5],
                          ddr3_ch1_dqs_n[4], ddr3_ch1_dqs_n[2:0]}),
        .o_ddr3_dm      ()
    );
`endif

`ifdef DDR3_FULL_2CH
    wire       ctrl_init_done_status = ctrl_init_done & ctrl_init_done_ch1;
    wire       ctrl_init_error_status = ctrl_init_error | ctrl_init_error_ch1;
    wire [3:0] ctrl_init_error_code_status =
        ctrl_init_error ? ctrl_init_error_code : ctrl_init_error_code_ch1;
    wire [4:0] ctrl_init_state_status =
        ctrl_init_done ? ctrl_init_state_ch1 : ctrl_init_state;
    wire       cal_done_status = cal_done & cal_done_ch1;
    wire       cal_error_status = cal_error | cal_error_ch1;
    wire [1:0] cal_error_code_status =
        cal_error ? cal_error_code : cal_error_code_ch1;
    wire [3:0] cal_seq_state_status =
        cal_done ? cal_seq_state_ch1 : cal_seq_state;
    wire [3:0] cal_wlvl_state_status =
        cal_done ? cal_wlvl_state_ch1 : cal_wlvl_state;
    wire [3:0] cal_rdlvl_state_status =
        cal_done ? cal_rdlvl_state_ch1 : cal_rdlvl_state;
    wire       ctrl_mpr_busy_status = ctrl_mpr_busy | ctrl_mpr_busy_ch1;
    wire       idelay_ready_status = idelay_ready & idelay_ready_ch1;
`else
    wire       ctrl_init_done_status = ctrl_init_done;
    wire       ctrl_init_error_status = ctrl_init_error;
    wire [3:0] ctrl_init_error_code_status = ctrl_init_error_code;
    wire [4:0] ctrl_init_state_status = ctrl_init_state;
    wire       cal_done_status = cal_done;
    wire       cal_error_status = cal_error;
    wire [1:0] cal_error_code_status = cal_error_code;
    wire [3:0] cal_seq_state_status = cal_seq_state;
    wire [3:0] cal_wlvl_state_status = cal_wlvl_state;
    wire [3:0] cal_rdlvl_state_status = cal_rdlvl_state;
    wire       ctrl_mpr_busy_status = ctrl_mpr_busy;
    wire       idelay_ready_status = idelay_ready;
`endif

    // =================================================================
    // STATUS MUX — host writes a register index to jtag_uart, then reads
    // the corresponding 32-bit status word.
    //
    // Index | Description
    // ------|-------------------------------------------------------------
    // 0x00  | STATUS_FLAGS (magic + critical bits)
    // 0x01  | STATE_BITS (FSM states + low heartbeat bits)
    // 0x02  | HEARTBEAT_CLK50
    // 0x03  | MEMTEST_PASS_CTR (BRAM + DDR3 combined)
    // 0x04  | MEMTEST_ERR_CTR
    // 0x05  | MEMTEST_FIRST_ERR_ADDR ({target, addr})
    // 0x06  | MEMTEST_FIRST_ERR_EXPECTED
    // 0x07  | MEMTEST_FIRST_ERR_GOT
    // 0x08  | MEMTEST_DDR3_PASS_CTR
    // 0x09  | MEMTEST_SWEEP_CTR
    // 0x0A  | MEMTEST_LAST_XOR_EXPECTED
    // 0x0B  | MEMTEST_LAST_XOR_GOT
    // 0x0C  | MEMTEST_CHECKSUM_STATUS {magic=0xAB0C, checksum_err}
    // 0x10  | JWB_STATUS {busy, last_ack, last_err, halt_others, ...}
    // 0x11  | JWB_ADDR     (15-bit, zero-extended)
    // 0x12  | JWB_DATA     (host-written write data)
    // 0x13  | JWB_RD_DATA  (last successful read)
    // 0x14  | PHASE_STATUS {magic=0xAB14, busy, count8b} (iter-11)
    // 0x15  | CLK_SYS_PROBE    {magic=0xAB15, alive, synced_bit, _, ticks_lo[5:0]}
    // 0x16  | CLK_PHY_X4_PROBE {magic=0xAB16, alive, synced_bit, _, ticks_lo[5:0]}
    // 0x17  | CLK_DQ_PROBE     {magic=0xAB17, alive, synced_bit, _, ticks_lo[5:0]}
    // 0x19  | PHY_RD_VALID_LANES
    //         (iter-13 — detect prjxray-gap CLKOUT routing failures.
    //         Each CLKOUT can fail independently because per-output
    //         CMT_LR_LOWER_B_MMCM_CLKOUT segbits are independently missing
    //         from prjxray's kintex7 DB. If any `alive=0` while
    //         mmcm_locked=1, that specific clock domain is silently dead.)
    // 0xFE  | VERSION (magic + iter)
    // 0xFF  | ECHO (returns last host-written word)
    // other | 0xDEADBA<idx>
    // =================================================================

    // Heartbeat on clk_50.
    reg [23:0] heartbeat = 24'd0;
    always @(posedge clk_50) heartbeat <= heartbeat + 1'b1;

    // Liveness probes for each MMCM CLKOUT. The prjxray-db kintex7
    // segbit gap for CMT_LR_LOWER_B_MMCM_CLKOUT0/1/2 means each output's
    // routing can fail INDEPENDENTLY in silicon. We probe all three.
    wire sys_clk_alive;
    wire [5:0] sys_hb_ticks_lo;
    wire       sys_hb_synced_bit;
    clk_liveness #(.DIV_BIT(7)) u_clk_sys_probe (
        .i_clk        (clk_sys),
        .i_clk_obs    (clk_50),
        .o_alive      (sys_clk_alive),
        .o_synced_bit (sys_hb_synced_bit),
        .o_ticks_lo   (sys_hb_ticks_lo)
    );

    wire phy_x4_alive;
    wire [5:0] phy_x4_ticks_lo;
    wire       phy_x4_synced_bit;
    clk_liveness #(.DIV_BIT(8)) u_clk_phy_x4_probe (  // 400 MHz / 2^8 = 1.56 MHz
        .i_clk        (clk_phy_x4),
        .i_clk_obs    (clk_50),
        .o_alive      (phy_x4_alive),
        .o_synced_bit (phy_x4_synced_bit),
        .o_ticks_lo   (phy_x4_ticks_lo)
    );

    wire dq_alive;
    wire [5:0] dq_ticks_lo;
    wire       dq_synced_bit;
    clk_liveness #(.DIV_BIT(8)) u_clk_dq_probe (
        .i_clk        (clk_dq),
        .i_clk_obs    (clk_50),
        .o_alive      (dq_alive),
        .o_synced_bit (dq_synced_bit),
        .o_ticks_lo   (dq_ticks_lo)
    );

    // CDC sync: clk_sys → clk_50 for status bits.
    reg [1:0] mmcm_locked_sync     = 2'b00;
    reg [1:0] idelay_ready_sync    = 2'b00;
    reg [1:0] init_done_sync       = 2'b00;
    reg [1:0] init_error_sync      = 2'b00;
    reg [1:0] cal_done_sync        = 2'b00;
    reg [1:0] cal_error_sync       = 2'b00;
    reg [1:0] mpr_busy_sync        = 2'b00;
    reg [1:0] mtest_any_err_sync   = 2'b00;
    reg [1:0] mtest_target_sync    = 2'b00;
    reg [1:0] mtest_pattern_idx_sync [1:0];

    reg [1:0]  cal_error_code_sync  [1:0];
    reg [3:0]  init_error_code_sync [1:0];
    reg [4:0]  init_state_sync      [1:0];
    reg [3:0]  cal_seq_state_sync   [1:0];
    reg [3:0]  cal_wlvl_state_sync  [1:0];
    reg [3:0]  cal_rdlvl_state_sync [1:0];
    reg [31:0] mtest_pass_ctr_sync           [1:0];
    reg [31:0] mtest_ddr3_pass_ctr_sync      [1:0];
    reg [31:0] mtest_err_ctr_sync            [1:0];
    reg [31:0] mtest_first_err_addr_sync     [1:0];
    reg [31:0] mtest_first_err_expected_sync [1:0];
    reg [31:0] mtest_first_err_got_sync      [1:0];
    reg [31:0] mtest_sweep_ctr_sync          [1:0];
    reg [31:0] mtest_last_xor_expected_sync  [1:0];
    reg [31:0] mtest_last_xor_got_sync       [1:0];
    reg [1:0]  mtest_checksum_err_sync       = 2'b00;

    always @(posedge clk_50) begin
        mmcm_locked_sync     <= {mmcm_locked_sync[0],   mmcm_locked};
        idelay_ready_sync    <= {idelay_ready_sync[0],  idelay_ready_status};
        init_done_sync       <= {init_done_sync[0],     ctrl_init_done_status};
        init_error_sync      <= {init_error_sync[0],    ctrl_init_error_status};
        cal_done_sync        <= {cal_done_sync[0],      cal_done_status};
        cal_error_sync       <= {cal_error_sync[0],     cal_error_status};
        mpr_busy_sync        <= {mpr_busy_sync[0],      ctrl_mpr_busy_status};
        mtest_any_err_sync   <= {mtest_any_err_sync[0], mtest_any_err};
        mtest_target_sync    <= {mtest_target_sync[0],  mtest_target};
        mtest_pattern_idx_sync[0] <= mtest_pattern_idx;
        mtest_pattern_idx_sync[1] <= mtest_pattern_idx_sync[0];

        cal_error_code_sync[0]  <= cal_error_code_status;
        cal_error_code_sync[1]  <= cal_error_code_sync[0];
        init_error_code_sync[0] <= ctrl_init_error_code_status;
        init_error_code_sync[1] <= init_error_code_sync[0];
        init_state_sync[0]      <= ctrl_init_state_status;
        init_state_sync[1]      <= init_state_sync[0];
        cal_seq_state_sync[0]   <= cal_seq_state_status;
        cal_seq_state_sync[1]   <= cal_seq_state_sync[0];
        cal_wlvl_state_sync[0]  <= cal_wlvl_state_status;
        cal_wlvl_state_sync[1]  <= cal_wlvl_state_sync[0];
        cal_rdlvl_state_sync[0] <= cal_rdlvl_state_status;
        cal_rdlvl_state_sync[1] <= cal_rdlvl_state_sync[0];

        mtest_pass_ctr_sync[0]           <= mtest_pass_ctr;
        mtest_pass_ctr_sync[1]           <= mtest_pass_ctr_sync[0];
        mtest_ddr3_pass_ctr_sync[0]      <= mtest_ddr3_pass_ctr;
        mtest_ddr3_pass_ctr_sync[1]      <= mtest_ddr3_pass_ctr_sync[0];
        mtest_err_ctr_sync[0]            <= mtest_err_ctr;
        mtest_err_ctr_sync[1]            <= mtest_err_ctr_sync[0];
        mtest_first_err_addr_sync[0]     <= mtest_first_err_addr;
        mtest_first_err_addr_sync[1]     <= mtest_first_err_addr_sync[0];
        mtest_first_err_expected_sync[0] <= mtest_first_err_expected;
        mtest_first_err_expected_sync[1] <= mtest_first_err_expected_sync[0];
        mtest_first_err_got_sync[0]      <= mtest_first_err_got;
        mtest_first_err_got_sync[1]      <= mtest_first_err_got_sync[0];
        mtest_sweep_ctr_sync[0]          <= mtest_sweep_ctr;
        mtest_sweep_ctr_sync[1]          <= mtest_sweep_ctr_sync[0];
        mtest_last_xor_expected_sync[0]  <= mtest_last_xor_expected;
        mtest_last_xor_expected_sync[1]  <= mtest_last_xor_expected_sync[0];
        mtest_last_xor_got_sync[0]       <= mtest_last_xor_got;
        mtest_last_xor_got_sync[1]       <= mtest_last_xor_got_sync[0];
        mtest_checksum_err_sync          <= {mtest_checksum_err_sync[0], mtest_checksum_err};
    end

    // CDC for JTAG-WB master status (clk_sys → clk_50).
    reg [1:0]  jwb_busy_sync, jwb_last_ack_sync, jwb_last_err_sync, jwb_halt_others_sync;
    reg [1:0]  phase_busy_sync;
    reg [1:0]  phy_rd_capture_sync;
    reg [7:0]  phase_count_sync [1:0];
    reg [JWB_LOCAL_ADDR_W-1:0] jwb_addr_echo_sync   [1:0];
    reg [JWB_DDR3_HI_W-1:0] jwb_addr_hi_echo_sync [1:0];
    reg [31:0] jwb_data_echo_sync   [1:0];
    reg [31:0] jwb_rd_data_sync     [1:0];
    reg [DDR3_ACTIVE_BYTE_LANES-1:0] phy_rd_valid_lane_sync [1:0];
`ifdef DDR3_DEBUG_PHY_RD_DATA
    reg [31:0] phy_rd_data_status_word_sync [1:0];
`endif
    reg [7:0]  d3_ctrl_sync             [1:0];
    always @(posedge clk_50) begin
        jwb_busy_sync        <= {jwb_busy_sync[0],        jwb_busy};
        jwb_last_ack_sync    <= {jwb_last_ack_sync[0],    jwb_last_ack};
        jwb_last_err_sync    <= {jwb_last_err_sync[0],    jwb_last_err};
        jwb_halt_others_sync <= {jwb_halt_others_sync[0], jwb_halt_others};
        phase_busy_sync      <= {phase_busy_sync[0], phy_phase_busy};
        phy_rd_capture_sync  <= {phy_rd_capture_sync[0], phy_rd_capture};
        phase_count_sync[0]  <= phy_phase_count;
        phase_count_sync[1]  <= phase_count_sync[0];
        jwb_addr_echo_sync[0] <= jwb_addr_echo;
        jwb_addr_echo_sync[1] <= jwb_addr_echo_sync[0];
        jwb_addr_hi_echo_sync[0] <= jwb_addr_hi_echo;
        jwb_addr_hi_echo_sync[1] <= jwb_addr_hi_echo_sync[0];
        jwb_data_echo_sync[0] <= jwb_data_echo;
        jwb_data_echo_sync[1] <= jwb_data_echo_sync[0];
        jwb_rd_data_sync[0]   <= jwb_rd_data;
        jwb_rd_data_sync[1]   <= jwb_rd_data_sync[0];
        phy_rd_valid_lane_sync[0] <= phy_rd_valid_lane;
        phy_rd_valid_lane_sync[1] <= phy_rd_valid_lane_sync[0];
`ifdef DDR3_DEBUG_PHY_RD_DATA
        phy_rd_data_status_word_sync[0] <= phy_rd_data_status_word_sys;
        phy_rd_data_status_word_sync[1] <= phy_rd_data_status_word_sync[0];
`endif
        d3_ctrl_sync[0]  <= {d3_cyc, d3_stb, d3_we, d3_ack, d3_stall,
                             d3_err, phy_wr_valid, phy_rd_valid};
        d3_ctrl_sync[1]  <= d3_ctrl_sync[0];
    end

    wire mmcm_locked_d   = mmcm_locked_sync[1];
    wire idelay_ready_d  = idelay_ready_sync[1];
    wire init_done_d     = init_done_sync[1];
    wire init_error_d    = init_error_sync[1];
    wire cal_done_d      = cal_done_sync[1];
    wire cal_error_d     = cal_error_sync[1];
    wire mpr_busy_d      = mpr_busy_sync[1];
    wire mtest_any_err_d = mtest_any_err_sync[1];
    wire mtest_target_d  = mtest_target_sync[1];
    wire [1:0] mtest_pattern_idx_d = mtest_pattern_idx_sync[1];

    wire [1:0] cal_error_code_d  = cal_error_code_sync[1];
    wire [3:0] init_error_code_d = init_error_code_sync[1];
    wire [4:0] init_state_d      = init_state_sync[1];
    wire [3:0] cal_seq_state_d   = cal_seq_state_sync[1];
    wire [3:0] cal_wlvl_state_d  = cal_wlvl_state_sync[1];
    wire [3:0] cal_rdlvl_state_d = cal_rdlvl_state_sync[1];

    // Cable-less silicon health indicator. All inputs are already
    // clk_50-domain (synced above or native), so the LED encoder runs
    // directly on clk_50 — that means LEDs work even before the DDR3
    // MMCM locks, which is exactly the state we most need to diagnose.
    bringup_status_led u_blu (
        .i_clk_50        (clk_50),
        .i_por_active    (por_rst_50),
        .i_mmcm_locked   (mmcm_locked_d),
        .i_clk_sys_alive (sys_clk_alive),
        .i_init_done     (init_done_d),
        .i_init_error    (init_error_d),
        .i_cal_done      (cal_done_d),
        .i_cal_error     (cal_error_d),
        .i_mtest_any_err (mtest_any_err_d),
        .i_mtest_target  (mtest_target_d),
        .o_led           (led)
    );

    wire [31:0] status_flags = {
        16'hB07E,            // [31:16]
        cal_done_d,          // [15]
        cal_error_d,         // [14]
        cal_error_code_d,    // [13:12]
        init_done_d,         // [11]
        init_error_d,        // [10]
        init_error_code_d,   // [9:6]
        mmcm_locked_d,       // [5]
        idelay_ready_d,      // [4]
        por_rst_50,          // [3]
        mpr_busy_d,          // [2]
        mtest_any_err_d,     // [1]
        mtest_target_d       // [0] — 0=BRAM, 1=DDR3
    };

    wire [31:0] state_bits = {
        init_state_d,         // [31:27]
        cal_seq_state_d,      // [26:23]
        cal_wlvl_state_d,     // [22:19]
        cal_rdlvl_state_d,    // [18:15]
        mtest_pattern_idx_d,  // [14:13]
        heartbeat[12:0]       // [12:0]
    };

`ifdef DDR3_DEBUG_PHY_RD_DATA
    wire [31:0] phy_rd_data_status_word = phy_rd_data_status_word_sync[1];
`else
    wire [31:0] phy_rd_data_status_word = {16'hAB20, 11'd0, host_to_fpga[4:0]};
`endif

    reg [31:0] status_word_comb;
    always @(*) begin
        if (host_to_fpga[7:5] == 3'b001) begin
            status_word_comb = phy_rd_data_status_word;
        end else begin
        case (host_to_fpga[7:0])
            8'h00:   status_word_comb = status_flags;
            8'h01:   status_word_comb = state_bits;
            8'h02:   status_word_comb = {8'h00, heartbeat};
            8'h03:   status_word_comb = mtest_pass_ctr_sync[1];
            8'h04:   status_word_comb = mtest_err_ctr_sync[1];
            8'h05:   status_word_comb = mtest_first_err_addr_sync[1];
            8'h06:   status_word_comb = mtest_first_err_expected_sync[1];
            8'h07:   status_word_comb = mtest_first_err_got_sync[1];
            8'h08:   status_word_comb = mtest_ddr3_pass_ctr_sync[1];
            8'h09:   status_word_comb = mtest_sweep_ctr_sync[1];
            8'h0A:   status_word_comb = mtest_last_xor_expected_sync[1];
            8'h0B:   status_word_comb = mtest_last_xor_got_sync[1];
            8'h0C:   status_word_comb = {16'hAB0C, 15'd0, mtest_checksum_err_sync[1]};
            8'h10:   status_word_comb = {16'hAB10,
                                    12'd0,
                                    jwb_busy_sync[1],
                                    jwb_last_ack_sync[1],
                                    jwb_last_err_sync[1],
                                    jwb_halt_others_sync[1]};
            8'h11:   status_word_comb = {17'd0, jwb_addr_echo_sync[1]};
            8'h12:   status_word_comb = jwb_data_echo_sync[1];
            8'h13:   status_word_comb = jwb_rd_data_sync[1];
            8'h14:   status_word_comb = {16'hAB14, 7'd0, phase_busy_sync[1], phase_count_sync[1]};
            8'h15:   status_word_comb = {16'hAB15, sys_clk_alive, sys_hb_synced_bit,
                                    8'd0, sys_hb_ticks_lo};
            8'h16:   status_word_comb = {16'hAB16, phy_x4_alive, phy_x4_synced_bit,
                                    8'd0, phy_x4_ticks_lo};
            8'h17:   status_word_comb = {16'hAB17, dq_alive, dq_synced_bit,
                                    8'd0, dq_ticks_lo};
            8'h18:   status_word_comb = {16'hAB18, 15'd0, phy_rd_capture_sync[1]};
            8'h19:   status_word_comb = {16'hAB19,
                                    {(16-DDR3_ACTIVE_BYTE_LANES){1'b0}},
                                    phy_rd_valid_lane_sync[1]};
            8'h1A:   status_word_comb = {16'hAB1A, jwb_addr_hi_echo_sync[1]};
            8'h1B:   status_word_comb = {16'hAB1B, 16'd0};
            8'h1C:   status_word_comb = {24'hAB1C00, d3_ctrl_sync[1]};
            8'hFE:   status_word_comb = {16'hB07E, 16'h0011};
            8'hFF:   status_word_comb = host_to_fpga;
            default: status_word_comb = {24'hDEADBA, host_to_fpga[7:0]};
        endcase
        end
    end

    reg [31:0] status_word = 32'd0;
    always @(posedge clk_50) begin
        status_word <= status_word_comb;
    end

    jtag_uart #(.WB_DATA_W(32), .WB_ADDR_W(2), .USER_CHAIN(1)) uart (
        .i_clk                (clk_50),
        .i_rst                (1'b0),
        .i_wb_cyc             (1'b0),
        .i_wb_stb             (1'b0),
        .i_wb_we              (1'b0),
        .i_wb_adr             (2'b0),
        .i_wb_dat             (32'b0),
        .i_wb_sel             (4'b0),
        .o_wb_stall           (),
        .o_wb_ack             (),
        .o_wb_dat             (),
        .o_wb_err             (),
        .i_fpga_to_host       (status_word),
        .o_host_to_fpga       (host_to_fpga),
        .o_host_to_fpga_valid (host_to_fpga_valid_50)
    );

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, ctrl_mpr_busy,
                cal_wlvl_state, cal_rdlvl_state, idelay_ready, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
