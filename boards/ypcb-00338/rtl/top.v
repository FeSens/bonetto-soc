// Top-level for the Inspur YPCB-00338 (xc7k480t-ffg1156-2).
//
// Iter-2.5: memtest_lite drives a wb_decode2 that routes to wb_memory
// (adr[14]=0) and jtag_uart (adr[14]=1). After each 1024 memory tests,
// memtest publishes its pass counter to jtag_uart so the host reads
// the live counter via XVC + USER1 DR scan.

`default_nettype none

module top (
    input  wire       clk_50,        // AA28
    output wire [2:0] led            // P30 / M30 / N30
);
    // -------- WB master (memtest_lite) --------
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

    // -------- wb_decode2: SEL_BIT 14 (BRAM @ adr<14>=0, UART @ adr<14>=1) --
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

    // -------- Slave 0: wb_memory (BRAM, 14 word-addr bits = 64 KB) --------
    wb_memory #(
        .WB_DATA_W(32),
        .WB_ADDR_W(14)
    ) mem (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .i_wb_cyc   (mem_cyc),
        .i_wb_stb   (mem_stb),
        .i_wb_we    (mem_we),
        .i_wb_adr   (mem_adr[13:0]),    // strip the decoder bit
        .i_wb_dat   (mem_dat_w),
        .i_wb_sel   (mem_sel),
        .o_wb_stall (mem_stall),
        .o_wb_ack   (mem_ack),
        .o_wb_dat   (mem_dat_r),
        .o_wb_err   (mem_err)
    );

    // -------- Slave 1: jtag_uart (BSCANE2-backed scratch register) -------
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
endmodule
