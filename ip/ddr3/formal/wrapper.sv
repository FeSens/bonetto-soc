// Formal harness for ddr3_ctrl's Wishbone slave port.
//
// Same `fwb_slave` pattern as ip/wb-memory: feed the DUT's WB inputs
// with symbolic stimulus and let ZipCPU's fwb_slave.v assume + assert
// the B4 pipelined protocol around it.
//
// This wrapper does NOT verify the DDR3 init FSM (that's covered by
// sim — `ip/ddr3/sim/tb_ddr3_init.cpp` walks the full state machine).
// Per INVARIANTS #1, the WB slave port itself must satisfy fwb_slave
// regardless of what the DDR3-side state is.
//
// The init FSM normally stalls WB transactions for ~700 µs after
// reset. fwb_slave's F_MAX_STALL parameter accommodates that — we
// set it to F_MAX_STALL=0 (unbounded stall allowed) so the proof
// doesn't fail just because init takes time.

`default_nettype none

module ddr3_ctrl_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_DATA_W = 32;
    localparam integer WB_ADDR_W = 8;       // small for fast formal

    // Symbolic WB master stimulus
    (* anyseq *) wire                     m_cyc, m_stb, m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [WB_DATA_W/8-1:0]   m_sel;

    wire                     s_stall, s_ack, s_err;
    wire [WB_DATA_W-1:0]     s_dat;

    // DDR3-side pins — unused in this formal harness (left dangling).
    wire                     dut_reset_n, dut_cke, dut_odt;
    wire                     dut_cs_n, dut_ras_n, dut_cas_n, dut_we_n;
    wire [2:0]               dut_ba;
    wire [14:0]              dut_addr;
    wire                     init_done, init_error;
    wire [3:0]               init_error_code;
    wire [4:0]               init_state;

    ddr3_ctrl #(
        .WB_DATA_W(WB_DATA_W),
        .WB_ADDR_W(WB_ADDR_W),
        .ROW_BITS (15),
        .BANK_BITS(3),
        .COL_BITS (10),
        .DQ_BITS  (8)
    ) dut (
        .i_clk     (clk),
        .i_clk_phy (clk),       // one-clock for formal; iter-3 uses MMCM
        .i_rst     (rst),
        .i_wb_cyc  (m_cyc),
        .i_wb_stb  (m_stb),
        .i_wb_we   (m_we),
        .i_wb_adr  (m_adr),
        .i_wb_dat  (m_dat),
        .i_wb_sel  (m_sel),
        .o_wb_stall(s_stall),
        .o_wb_ack  (s_ack),
        .o_wb_dat  (s_dat),
        .o_wb_err  (s_err),
        .o_ddr3_reset_n(dut_reset_n),
        .o_ddr3_cke    (dut_cke),
        .o_ddr3_odt    (dut_odt),
        .o_ddr3_cs_n   (dut_cs_n),
        .o_ddr3_ras_n  (dut_ras_n),
        .o_ddr3_cas_n  (dut_cas_n),
        .o_ddr3_we_n   (dut_we_n),
        .o_ddr3_ba     (dut_ba),
        .o_ddr3_addr   (dut_addr),
        .i_phy_rd_data  (288'd0),
        .i_phy_rd_valid (1'b1),
        .o_phy_wr_data  (),
        .o_phy_wr_valid (),
        .o_phy_rd_capture(),
        .o_init_done   (init_done),
        .o_init_error  (init_error),
        .o_init_error_code(init_error_code),
        .o_init_state  (init_state)
    );

    fwb_slave #(
        .AW                  (WB_ADDR_W),
        .DW                  (WB_DATA_W),
        .F_MAX_STALL         (0),         // stall unbounded (init takes ~700 µs)
        .F_MAX_ACK_DELAY     (0),
        .F_LGDEPTH           (4),
        .F_OPT_DISCONTINUOUS (1),
        .F_OPT_MINCLOCK_DELAY(0)
    ) fwb (
        .i_clk      (clk),
        .i_reset    (rst),
        .i_wb_cyc   (m_cyc),
        .i_wb_stb   (m_stb),
        .i_wb_we    (m_we),
        .i_wb_addr  (m_adr),
        .i_wb_data  (m_dat),
        .i_wb_sel   (m_sel),
        .i_wb_ack   (s_ack),
        .i_wb_stall (s_stall),
        .i_wb_idata (s_dat),
        .i_wb_err   (s_err),
        .f_nreqs    (),
        .f_nacks    (),
        .f_outstanding ()
    );

`ifdef FORMAL
    initial assume(rst);
`endif

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, dut_reset_n, dut_cke, dut_odt, dut_cs_n, dut_ras_n,
                dut_cas_n, dut_we_n, dut_ba, dut_addr,
                init_done, init_error, init_error_code, init_state, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
