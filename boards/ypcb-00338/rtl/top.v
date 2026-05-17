// Top-level for the Inspur YPCB-00338 (xc7k480t-ffg1156-2).
//
// Iter-5 (cal-gated DDR3 datapath + status mux):
//   * memtest_lite + wb_memory (BRAM) + ddr3_ctrl now share clk_sys
//     (200 MHz from the PHY MMCM). Before MMCM locks they are held
//     in reset by rst_sys.
//   * wb_decode2 routes memtest's address space:
//       adr[14]=0 → wb_memory (BRAM, 16K words = 64 KB)
//       adr[14]=1 → ddr3_ctrl (16K-word window inside 1 GB DDR3 space)
//   * memtest_lite gates target promotion to DDR3 on i_cal_done.
//     Until cal completes (or skip mode), it loops on BRAM. Once cal
//     completes AND a full BRAM sweep passes, memtest switches to DDR3.
//   * jtag_uart still runs on clk_50 with i_fpga_to_host driven by the
//     status mux. CDC across clk_sys → clk_50 for all status signals.

`default_nettype none

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
    inout  wire [71:0] ddr3_dq,
    inout  wire [8:0]  ddr3_dqs_p,
    inout  wire [8:0]  ddr3_dqs_n
);
    // ---- Power-on reset on clk_50 (16K cycles ≈ 320 µs @ 50 MHz) ----
    reg [13:0] por_ctr_50 = 14'h3FFF;
    always @(posedge clk_50) begin
        if (por_ctr_50 != 0) por_ctr_50 <= por_ctr_50 - 1'b1;
    end
    wire por_rst_50 = (por_ctr_50 != 0);

    // ---- DDR3 PHY clocks + reset (200 MHz controller clk_sys) ----
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
    // memtest_lite → wb_decode2 → {wb_memory, ddr3_ctrl}
    // All on clk_sys.
    // =================================================================
    wire        m_cyc, m_stb, m_we;
    wire [14:0] m_adr;
    wire [31:0] m_dat_w, m_dat_r;
    wire [3:0]  m_sel;
    wire        m_stall, m_ack, m_err;

    wire [31:0] mtest_pass_ctr;
    wire [31:0] mtest_ddr3_pass_ctr;
    wire [31:0] mtest_err_ctr;
    wire [31:0] mtest_first_err_addr;
    wire [31:0] mtest_first_err_expected;
    wire [31:0] mtest_first_err_got;
    wire        mtest_any_err;
    wire        mtest_target;
    wire [1:0]  mtest_pattern_idx;

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

    memtest_lite #(.WB_ADDR_W(15)) mtest (
        .i_clk                (clk_sys),
        .i_rst                (rst_sys),
        .i_cal_done           (cal_done),
        .o_wb_cyc             (m_cyc),
        .o_wb_stb             (m_stb),
        .o_wb_we              (m_we),
        .o_wb_adr             (m_adr),
        .o_wb_dat             (m_dat_w),
        .o_wb_sel             (m_sel),
        .i_wb_stall           (m_stall),
        .i_wb_ack             (m_ack),
        .i_wb_dat             (m_dat_r),
        .i_wb_err             (m_err),
        .o_led                (led),
        .o_pass_ctr           (mtest_pass_ctr),
        .o_ddr3_pass_ctr      (mtest_ddr3_pass_ctr),
        .o_err_ctr            (mtest_err_ctr),
        .o_first_err_addr     (mtest_first_err_addr),
        .o_first_err_expected (mtest_first_err_expected),
        .o_first_err_got      (mtest_first_err_got),
        .o_any_err            (mtest_any_err),
        .o_target             (mtest_target),
        .o_pattern_idx        (mtest_pattern_idx)
    );

    wire        bram_cyc, bram_stb, bram_we;
    wire [14:0] bram_adr;
    wire [31:0] bram_dat_w;
    wire [3:0]  bram_sel;
    wire        bram_stall, bram_ack, bram_err;
    wire [31:0] bram_dat_r;

    wire        d3_cyc, d3_stb, d3_we;
    wire [14:0] d3_adr;
    wire [31:0] d3_dat_w;
    wire [3:0]  d3_sel;
    wire        d3_stall, d3_ack, d3_err;
    wire [31:0] d3_dat_r;

    wb_decode2 #(
        .WB_DATA_W(32),
        .WB_ADDR_W(15),
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
    wire        ctrl_reset_n;
    wire        ctrl_cke;
    wire        ctrl_odt;
    wire        ctrl_cs_n, ctrl_ras_n, ctrl_cas_n, ctrl_we_n;
    wire [2:0]  ctrl_ba;
    wire [14:0] ctrl_addr;

    wire        phy_mpr_req;
    wire [12:0] phy_mpr_addr;
    wire        ctrl_mpr_busy;

    wire        cal_wlvl_start, cal_wlvl_done, cal_wlvl_error;
    wire        cal_rdlvl_start, cal_rdlvl_done, cal_rdlvl_error;

    ddr3_ctrl #(.WB_DATA_W(32), .WB_ADDR_W(28), .DQ_BITS(8)) u_ddr3_ctrl (
        .i_clk          (clk_sys),
        .i_clk_phy      (clk_sys),
        .i_rst          (rst_sys),
        .i_wb_cyc       (d3_cyc),
        .i_wb_stb       (d3_stb),
        .i_wb_we        (d3_we),
        .i_wb_adr       ({13'b0, d3_adr[13:0], 1'b0}),  // word→byte addr in 28-bit space
        .i_wb_dat       (d3_dat_w),
        .i_wb_sel       (d3_sel),
        .o_wb_stall     (d3_stall),
        .o_wb_ack       (d3_ack),
        .o_wb_dat       (d3_dat_r),
        .o_wb_err       (d3_err),
        .o_ddr3_reset_n (ctrl_reset_n),
        .o_ddr3_cke     (ctrl_cke),
        .o_ddr3_odt     (ctrl_odt),
        .o_ddr3_cs_n    (ctrl_cs_n),
        .o_ddr3_ras_n   (ctrl_ras_n),
        .o_ddr3_cas_n   (ctrl_cas_n),
        .o_ddr3_we_n    (ctrl_we_n),
        .o_ddr3_ba      (ctrl_ba),
        .o_ddr3_addr    (ctrl_addr),
        .i_mpr_req      (phy_mpr_req),
        .i_mpr_addr     (phy_mpr_addr),
        .o_mpr_busy     (ctrl_mpr_busy),
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
        .o_cal_done       (cal_done),
        .o_cal_error      (cal_error),
        .o_cal_error_code (cal_error_code),
        .o_state          (cal_seq_state)
    );

    ddr3_phy #(.DQ_BITS(8), .NUM_BYTE_LANES(9), .SERDES_RATIO(4)) u_ddr3_phy (
        .i_clk_ref      (clk_50),
        .i_rst_ref      (por_rst_50),
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

        .i_wr_valid     (1'b0),
        .i_wr_data      ({(9*8*4){1'b0}}),
        .i_wr_mask      (9'b0),

        .o_rd_valid     (),
        .o_rd_data      (),

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
        .io_ddr3_dq     (ddr3_dq),
        .io_ddr3_dqs_p  (ddr3_dqs_p),
        .io_ddr3_dqs_n  (ddr3_dqs_n),
        .o_ddr3_dm      ()
    );

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
    // 0xFE  | VERSION (magic + iter)
    // 0xFF  | ECHO (returns last host-written word)
    // other | 0xDEADBA<idx>
    // =================================================================
    wire [31:0] host_to_fpga;

    // Heartbeat on clk_50.
    reg [23:0] heartbeat = 24'd0;
    always @(posedge clk_50) heartbeat <= heartbeat + 1'b1;

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

    always @(posedge clk_50) begin
        mmcm_locked_sync     <= {mmcm_locked_sync[0],   mmcm_locked};
        idelay_ready_sync    <= {idelay_ready_sync[0],  idelay_ready};
        init_done_sync       <= {init_done_sync[0],     ctrl_init_done};
        init_error_sync      <= {init_error_sync[0],    ctrl_init_error};
        cal_done_sync        <= {cal_done_sync[0],      cal_done};
        cal_error_sync       <= {cal_error_sync[0],     cal_error};
        mpr_busy_sync        <= {mpr_busy_sync[0],      ctrl_mpr_busy};
        mtest_any_err_sync   <= {mtest_any_err_sync[0], mtest_any_err};
        mtest_target_sync    <= {mtest_target_sync[0],  mtest_target};
        mtest_pattern_idx_sync[0] <= mtest_pattern_idx;
        mtest_pattern_idx_sync[1] <= mtest_pattern_idx_sync[0];

        cal_error_code_sync[0]  <= cal_error_code;
        cal_error_code_sync[1]  <= cal_error_code_sync[0];
        init_error_code_sync[0] <= ctrl_init_error_code;
        init_error_code_sync[1] <= init_error_code_sync[0];
        init_state_sync[0]      <= ctrl_init_state;
        init_state_sync[1]      <= init_state_sync[0];
        cal_seq_state_sync[0]   <= cal_seq_state;
        cal_seq_state_sync[1]   <= cal_seq_state_sync[0];
        cal_wlvl_state_sync[0]  <= cal_wlvl_state;
        cal_wlvl_state_sync[1]  <= cal_wlvl_state_sync[0];
        cal_rdlvl_state_sync[0] <= cal_rdlvl_state;
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

    reg [31:0] status_word;
    always @(*) begin
        case (host_to_fpga[7:0])
            8'h00:   status_word = status_flags;
            8'h01:   status_word = state_bits;
            8'h02:   status_word = {8'h00, heartbeat};
            8'h03:   status_word = mtest_pass_ctr_sync[1];
            8'h04:   status_word = mtest_err_ctr_sync[1];
            8'h05:   status_word = mtest_first_err_addr_sync[1];
            8'h06:   status_word = mtest_first_err_expected_sync[1];
            8'h07:   status_word = mtest_first_err_got_sync[1];
            8'h08:   status_word = mtest_ddr3_pass_ctr_sync[1];
            8'hFE:   status_word = {16'hB07E, 16'h0006};
            8'hFF:   status_word = host_to_fpga;
            default: status_word = {24'hDEADBA, host_to_fpga[7:0]};
        endcase
    end

    jtag_uart #(.WB_DATA_W(32), .WB_ADDR_W(2), .USER_CHAIN(1)) uart (
        .i_clk          (clk_50),
        .i_rst          (1'b0),
        .i_wb_cyc       (1'b0),
        .i_wb_stb       (1'b0),
        .i_wb_we        (1'b0),
        .i_wb_adr       (2'b0),
        .i_wb_dat       (32'b0),
        .i_wb_sel       (4'b0),
        .o_wb_stall     (),
        .o_wb_ack       (),
        .o_wb_dat       (),
        .o_wb_err       (),
        .i_fpga_to_host (status_word),
        .o_host_to_fpga (host_to_fpga)
    );

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, clk_phy_x4, clk_dq, ctrl_mpr_busy,
                cal_wlvl_state, cal_rdlvl_state, idelay_ready, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
