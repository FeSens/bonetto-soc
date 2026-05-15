// Top-level for the Inspur YPCB-00338 (xc7k480t-ffg1156-2).
//
// Iter-3d: the SoC stack (memtest_lite → wb_decode2 → {wb_memory,
// jtag_uart}) coexists with the DDR3 IP stack (ddr3_phy +
// ddr3_ctrl). The DDR3 stack runs from the PHY's 200 MHz MMCM
// output. ctrl drives the parallel command bus, phy latches into
// FFs (+ adds a cycle of Tco) and drives the chip pins. The
// rdlvl FSM inside phy feeds o_mpr_read_req / o_mpr_read_addr
// back into ctrl so the runtime FSM emits real RD commands on
// the DDR3 cmd bus during calibration.
//
// Wishbone master into ddr3_ctrl is tied to a no-op for iter-3d.
// memtest_lite continues to drive BRAM + JTAG-UART per iter-2.5.
// Iter-3e will widen the master decoder so memtest reaches DDR3
// directly.

`default_nettype none

module top (
    input  wire        clk_50,            // AA28

    // SoC LEDs (LVCMOS18)
    output wire [2:0]  led,

    // DDR3 chip pins (see boards/ypcb-00338/constraints/ddr3_ch0.xdc)
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
    // =================================================================
    // SoC stack — memtest_lite + wb_decode2 + wb_memory + jtag_uart.
    // Runs on clk_50 directly. Same as iter-2.5.
    // =================================================================
    wire        m_cyc, m_stb, m_we;
    wire [14:0] m_adr;
    wire [31:0] m_dat_w, m_dat_r;
    wire [3:0]  m_sel;
    wire        m_stall, m_ack, m_err;

    memtest_lite mtest (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .o_wb_cyc   (m_cyc),
        .o_wb_stb   (m_stb),
        .o_wb_we    (m_we),
        .o_wb_adr   (m_adr),
        .o_wb_dat   (m_dat_w),
        .o_wb_sel   (m_sel),
        .i_wb_stall (m_stall),
        .i_wb_ack   (m_ack),
        .i_wb_dat   (m_dat_r),
        .i_wb_err   (m_err),
        .o_led      (led)
    );

    wire        mem_cyc, mem_stb, mem_we;
    wire [14:0] mem_adr;
    wire [31:0] mem_dat_w;
    wire [3:0]  mem_sel;
    wire        mem_stall, mem_ack, mem_err;
    wire [31:0] mem_dat_r;

    wire        uart_cyc, uart_stb, uart_we;
    wire [14:0] uart_adr;
    wire [31:0] uart_dat_w;
    wire [3:0]  uart_sel;
    wire        uart_stall, uart_ack, uart_err;
    wire [31:0] uart_dat_r;

    wb_decode2 #(
        .WB_DATA_W(32),
        .WB_ADDR_W(15),
        .SEL_BIT  (14)
    ) xbar (
        .i_clk     (clk_50),
        .i_rst     (1'b0),
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
        .o_s0_cyc  (mem_cyc),
        .o_s0_stb  (mem_stb),
        .o_s0_we   (mem_we),
        .o_s0_adr  (mem_adr),
        .o_s0_dat  (mem_dat_w),
        .o_s0_sel  (mem_sel),
        .i_s0_stall(mem_stall),
        .i_s0_ack  (mem_ack),
        .i_s0_dat  (mem_dat_r),
        .i_s0_err  (mem_err),
        .o_s1_cyc  (uart_cyc),
        .o_s1_stb  (uart_stb),
        .o_s1_we   (uart_we),
        .o_s1_adr  (uart_adr),
        .o_s1_dat  (uart_dat_w),
        .o_s1_sel  (uart_sel),
        .i_s1_stall(uart_stall),
        .i_s1_ack  (uart_ack),
        .i_s1_dat  (uart_dat_r),
        .i_s1_err  (uart_err)
    );

    wb_memory #(
        .WB_DATA_W(32),
        .WB_ADDR_W(14)
    ) mem (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .i_wb_cyc   (mem_cyc),
        .i_wb_stb   (mem_stb),
        .i_wb_we    (mem_we),
        .i_wb_adr   (mem_adr[13:0]),
        .i_wb_dat   (mem_dat_w),
        .i_wb_sel   (mem_sel),
        .o_wb_stall (mem_stall),
        .o_wb_ack   (mem_ack),
        .o_wb_dat   (mem_dat_r),
        .o_wb_err   (mem_err)
    );

    jtag_uart #(
        .WB_DATA_W(32),
        .WB_ADDR_W(2),
        .USER_CHAIN(1)
    ) uart (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .i_wb_cyc   (uart_cyc),
        .i_wb_stb   (uart_stb),
        .i_wb_we    (uart_we),
        .i_wb_adr   (uart_adr[1:0]),
        .i_wb_dat   (uart_dat_w),
        .i_wb_sel   (uart_sel),
        .o_wb_stall (uart_stall),
        .o_wb_ack   (uart_ack),
        .o_wb_dat   (uart_dat_r),
        .o_wb_err   (uart_err)
    );

    // =================================================================
    // DDR3 stack — phy + ctrl. Runs on phy.o_clk_sys (200 MHz from MMCM).
    // ctrl's WB master tied to no-op; data path lives in iter-3e.
    // =================================================================

    // ---- Power-on reset on clk_50 (16K cycles ≈ 320 µs @ 50 MHz) ----
    reg [13:0] por_ctr_50 = 14'h3FFF;
    always @(posedge clk_50) begin
        if (por_ctr_50 != 0) por_ctr_50 <= por_ctr_50 - 1'b1;
    end
    wire por_rst_50 = (por_ctr_50 != 0);

    // ---- DDR3 PHY clocks + reset ----
    wire clk_sys;        // 200 MHz controller clock from PHY MMCM
    wire clk_phy_x4;     // 400 MHz SERDES clock
    wire clk_dq;         // 400 MHz +90° DQS clock
    wire mmcm_locked;
    wire idelay_ready;

    // ---- ctrl ↔ phy parallel command bus ----
    wire        ctrl_reset_n;
    wire        ctrl_cke;
    wire        ctrl_odt;
    wire        ctrl_cs_n, ctrl_ras_n, ctrl_cas_n, ctrl_we_n;
    wire [2:0]  ctrl_ba;
    wire [14:0] ctrl_addr;

    // ---- phy → ctrl MPR-read request ----
    wire        phy_mpr_req;
    wire [12:0] phy_mpr_addr;
    wire        ctrl_mpr_busy;

    // ---- Synchronize por_rst into the 200 MHz domain (after MMCM lock) ----
    reg [2:0] rst_sync_sys = 3'b111;
    always @(posedge clk_sys or posedge por_rst_50) begin
        if (por_rst_50)            rst_sync_sys <= 3'b111;
        else if (!mmcm_locked)     rst_sync_sys <= 3'b111;
        else                       rst_sync_sys <= {rst_sync_sys[1:0], 1'b0};
    end
    wire rst_sys = rst_sync_sys[2];

    // ---- ddr3_ctrl on clk_sys ----
    ddr3_ctrl #(
        .WB_DATA_W (32),
        .WB_ADDR_W (28),
        .DQ_BITS   (8)
    ) u_ddr3_ctrl (
        .i_clk          (clk_sys),
        .i_clk_phy      (clk_sys),       // shared until iter-3e splits domains
        .i_rst          (rst_sys),
        // WB slave — tied to no-op for iter-3d.
        .i_wb_cyc       (1'b0),
        .i_wb_stb       (1'b0),
        .i_wb_we        (1'b0),
        .i_wb_adr       (28'b0),
        .i_wb_dat       (32'b0),
        .i_wb_sel       (4'b0),
        .o_wb_stall     (),
        .o_wb_ack       (),
        .o_wb_dat       (),
        .o_wb_err       (),
        // DDR3 chip-side cmd bus (parallel, into phy).
        .o_ddr3_reset_n (ctrl_reset_n),
        .o_ddr3_cke     (ctrl_cke),
        .o_ddr3_odt     (ctrl_odt),
        .o_ddr3_cs_n    (ctrl_cs_n),
        .o_ddr3_ras_n   (ctrl_ras_n),
        .o_ddr3_cas_n   (ctrl_cas_n),
        .o_ddr3_we_n    (ctrl_we_n),
        .o_ddr3_ba      (ctrl_ba),
        .o_ddr3_addr    (ctrl_addr),
        // MPR-read port (from phy.rdlvl)
        .i_mpr_req      (phy_mpr_req),
        .i_mpr_addr     (phy_mpr_addr),
        .o_mpr_busy     (ctrl_mpr_busy),
        // Status (left as no-connect at top level; future SoC reads via JTAG)
        .o_init_done        (),
        .o_init_error       (),
        .o_init_error_code  (),
        .o_init_state       ()
    );

    // ---- ddr3_phy on its own MMCM-derived clocks ----
    ddr3_phy #(
        .DQ_BITS        (8),
        .NUM_BYTE_LANES (9),
        .SERDES_RATIO   (4)
    ) u_ddr3_phy (
        .i_clk_ref      (clk_50),
        .i_rst_ref      (por_rst_50),
        .o_clk_sys      (clk_sys),
        .o_clk_phy_x4   (clk_phy_x4),
        .o_clk_dq       (clk_dq),
        .o_locked       (mmcm_locked),
        .o_idelay_ready (idelay_ready),

        // Parallel command bus from ctrl.
        .i_cmd_valid    (1'b1),                         // ctrl always drives cmd (NOP when idle)
        .i_cmd          ({ctrl_cs_n, ctrl_ras_n, ctrl_cas_n, ctrl_we_n}),
        .i_cmd_ba       (ctrl_ba),
        .i_cmd_addr     (ctrl_addr),
        .i_cmd_cke      (ctrl_cke),
        .i_cmd_reset_n  (ctrl_reset_n),
        .i_cmd_odt      (ctrl_odt),

        // Write data path tied off for iter-3d (no real writes yet).
        .i_wr_valid     (1'b0),
        .i_wr_data      ({(9*8*4){1'b0}}),
        .i_wr_mask      (9'b0),

        // Read data path floats (not consumed at this iter; rdlvl uses
        // it internally inside phy).
        .o_rd_valid     (),
        .o_rd_data      (),

        // Calibration controls — not started in iter-3d.
        // Iter-3e adds a small "cal sequencer" FSM that pulses these
        // after init_done.
        .i_cal_start_wlvl  (1'b0),
        .o_cal_done_wlvl   (),
        .o_cal_error_wlvl  (),
        .o_cal_state_wlvl  (),
        .i_cal_start_rdlvl (1'b0),
        .o_cal_done_rdlvl  (),
        .o_cal_error_rdlvl (),
        .o_cal_state_rdlvl (),
        .o_mpr_read_req    (phy_mpr_req),
        .o_mpr_read_addr   (phy_mpr_addr),

        // DDR3 chip pins.
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
        .o_ddr3_dm      ()                              // DM pads not constrained on this board
    );

    // ---- Unused signals — keep nextpnr happy ----
    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, clk_phy_x4, clk_dq, idelay_ready, ctrl_mpr_busy, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
