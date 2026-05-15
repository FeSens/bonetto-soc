// Top-level for the Inspur YPCB-00338 (xc7k480t-ffg1156-2).
// Iteration 1: instantiates wb_memory + a minimal Wishbone-master
// memtest, drives the 3 LEDs with: pass-state / heartbeat / sticky-error.

`default_nettype none

module top (
    input  wire       clk_50,        // AA28
    output wire [2:0] led            // P30 / M30 / N30
);
    // Wishbone fabric between memtest_lite (master) and wb_memory (slave)
    wire        wb_cyc, wb_stb, wb_we;
    wire [13:0] wb_adr;
    wire [31:0] wb_dat_w, wb_dat_r;
    wire [3:0]  wb_sel;
    wire        wb_stall, wb_ack, wb_err;

    memtest_lite mtest (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .o_wb_cyc   (wb_cyc),
        .o_wb_stb   (wb_stb),
        .o_wb_we    (wb_we),
        .o_wb_adr   (wb_adr),
        .o_wb_dat   (wb_dat_w),
        .o_wb_sel   (wb_sel),
        .i_wb_stall (wb_stall),
        .i_wb_ack   (wb_ack),
        .i_wb_dat   (wb_dat_r),
        .i_wb_err   (wb_err),
        .o_led      (led)
    );

    wb_memory #(
        .WB_DATA_W(32),
        .WB_ADDR_W(14)
    ) mem (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .i_wb_cyc   (wb_cyc),
        .i_wb_stb   (wb_stb),
        .i_wb_we    (wb_we),
        .i_wb_adr   (wb_adr),
        .i_wb_dat   (wb_dat_w),
        .i_wb_sel   (wb_sel),
        .o_wb_stall (wb_stall),
        .o_wb_ack   (wb_ack),
        .o_wb_dat   (wb_dat_r),
        .o_wb_err   (wb_err)
    );

    // jtag_uart present so its BSCANE2 USER1 chain is reachable from the
    // host. WB slave inputs tied off in iter-1 — `fpga_to_host` therefore
    // stays at its 0xDEADBEEF init value, which is what the host-side
    // tools/jtag_uart_read.py script should observe on the first read.
    // Iter-2 wires memtest_lite -> wb_decode2 -> jtag_uart for live pass count.
    /* verilator lint_off PINMISSING */
    jtag_uart #(
        .WB_DATA_W(32),
        .WB_ADDR_W(2),
        .USER_CHAIN(1)
    ) uart (
        .i_clk      (clk_50),
        .i_rst      (1'b0),
        .i_wb_cyc   (1'b0),
        .i_wb_stb   (1'b0),
        .i_wb_we    (1'b0),
        .i_wb_adr   (2'b0),
        .i_wb_dat   (32'b0),
        .i_wb_sel   (4'b0),
        .o_wb_stall (),
        .o_wb_ack   (),
        .o_wb_dat   (),
        .o_wb_err   ()
    );
    /* verilator lint_on PINMISSING */
endmodule
