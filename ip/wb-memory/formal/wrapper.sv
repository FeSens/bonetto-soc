// Formal harness for wb_memory.
//
// Symbolic master inputs feed both the DUT and ZipCPU's fwb_slave.v.
// fwb_slave assumes the inputs are well-formed (Wishbone-legal) and
// asserts the slave's outputs obey the protocol. SymbiYosys runs BMC
// + induction per `wb_memory.sby`.

`default_nettype none

module wb_memory_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_DATA_W = 32;
    localparam integer WB_ADDR_W = 8;     // small for fast formal

    // Symbolic master-side stimulus
    (* anyseq *) wire                     m_cyc, m_stb, m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [WB_DATA_W/8-1:0]   m_sel;

    wire                     s_stall, s_ack, s_err;
    wire [WB_DATA_W-1:0]     s_dat;

    wb_memory #(
        .WB_DATA_W(WB_DATA_W),
        .WB_ADDR_W(WB_ADDR_W)
    ) dut (
        .i_clk    (clk),
        .i_rst    (rst),
        .i_wb_cyc (m_cyc),
        .i_wb_stb (m_stb),
        .i_wb_we  (m_we),
        .i_wb_adr (m_adr),
        .i_wb_dat (m_dat),
        .i_wb_sel (m_sel),
        .o_wb_stall (s_stall),
        .o_wb_ack   (s_ack),
        .o_wb_dat   (s_dat),
        .o_wb_err   (s_err)
    );

    // ZipCPU's slave-side property file: assumes legal master inputs,
    // asserts legal slave outputs.
    fwb_slave #(
        .AW                      (WB_ADDR_W),
        .DW                      (WB_DATA_W),
        .F_MAX_STALL             (0),     // wb_memory never stalls
        .F_MAX_ACK_DELAY         (2),     // ack within 1 cycle of accept
        .F_LGDEPTH               (4),
        .F_OPT_DISCONTINUOUS     (1),
        .F_OPT_MINCLOCK_DELAY    (0)
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
    // Start in reset; assume reset deasserts after a finite time.
    initial assume(rst);
`endif
endmodule
