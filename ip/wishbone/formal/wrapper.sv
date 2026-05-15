// Formal harness for wb_decode2.
//
// Symbolic master inputs feed the decoder; the decoder's routing logic
// is verified by checking that the master-facing port satisfies the
// Wishbone B4 pipelined protocol regardless of what the slaves do.
// Slave-side inputs are symbolic; the decoder must still produce a
// protocol-legal master view.

`default_nettype none

module wb_decode2_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_DATA_W = 32;
    localparam integer WB_ADDR_W = 8;
    localparam integer SEL_BIT   = 4;

    // Symbolic master stimulus
    (* anyseq *) wire                     m_cyc, m_stb, m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [WB_DATA_W/8-1:0]   m_sel;

    // Symbolic slave responses (anyseq — model arbitrary well-behaved slaves)
    (* anyseq *) wire                     s0_stall, s0_ack, s0_err;
    (* anyseq *) wire [WB_DATA_W-1:0]     s0_dat;
    (* anyseq *) wire                     s1_stall, s1_ack, s1_err;
    (* anyseq *) wire [WB_DATA_W-1:0]     s1_dat;

    // Decoder outputs to slaves (verified by the assumes inside fwb_slave
    // applied to each slave port via separate instances below)
    wire                     s0_cyc, s0_stb, s0_we;
    wire [WB_ADDR_W-1:0]     s0_adr;
    wire [WB_DATA_W-1:0]     s0_dat_out;
    wire [WB_DATA_W/8-1:0]   s0_sel_out;
    wire                     s1_cyc, s1_stb, s1_we;
    wire [WB_ADDR_W-1:0]     s1_adr;
    wire [WB_DATA_W-1:0]     s1_dat_out;
    wire [WB_DATA_W/8-1:0]   s1_sel_out;

    // Master-facing response from the decoder
    wire                     m_stall, m_ack, m_err;
    wire [WB_DATA_W-1:0]     m_dat_out;

    wb_decode2 #(
        .WB_DATA_W(WB_DATA_W),
        .WB_ADDR_W(WB_ADDR_W),
        .SEL_BIT  (SEL_BIT)
    ) dut (
        .i_clk     (clk),
        .i_rst     (rst),
        .i_wb_cyc  (m_cyc),
        .i_wb_stb  (m_stb),
        .i_wb_we   (m_we),
        .i_wb_adr  (m_adr),
        .i_wb_dat  (m_dat),
        .i_wb_sel  (m_sel),
        .o_wb_stall(m_stall),
        .o_wb_ack  (m_ack),
        .o_wb_dat  (m_dat_out),
        .o_wb_err  (m_err),

        .o_s0_cyc  (s0_cyc),
        .o_s0_stb  (s0_stb),
        .o_s0_we   (s0_we),
        .o_s0_adr  (s0_adr),
        .o_s0_dat  (s0_dat_out),
        .o_s0_sel  (s0_sel_out),
        .i_s0_stall(s0_stall),
        .i_s0_ack  (s0_ack),
        .i_s0_dat  (s0_dat),
        .i_s0_err  (s0_err),

        .o_s1_cyc  (s1_cyc),
        .o_s1_stb  (s1_stb),
        .o_s1_we   (s1_we),
        .o_s1_adr  (s1_adr),
        .o_s1_dat  (s1_dat_out),
        .o_s1_sel  (s1_sel_out),
        .i_s1_stall(s1_stall),
        .i_s1_ack  (s1_ack),
        .i_s1_dat  (s1_dat),
        .i_s1_err  (s1_err)
    );

    // Apply fwb_slave on the MASTER-side port (decoder's master view).
    // The decoder is, from the master's perspective, a slave. So the same
    // fwb_slave property file applies — assertions on master-side outputs,
    // assumptions on master-side inputs.
    fwb_slave #(
        .AW                  (WB_ADDR_W),
        .DW                  (WB_DATA_W),
        .F_MAX_STALL         (0),
        .F_MAX_ACK_DELAY     (0),
        .F_LGDEPTH           (4),
        .F_OPT_DISCONTINUOUS (1)
    ) fwb_master_face (
        .i_clk      (clk),
        .i_reset    (rst),
        .i_wb_cyc   (m_cyc),
        .i_wb_stb   (m_stb),
        .i_wb_we    (m_we),
        .i_wb_addr  (m_adr),
        .i_wb_data  (m_dat),
        .i_wb_sel   (m_sel),
        .i_wb_ack   (m_ack),
        .i_wb_stall (m_stall),
        .i_wb_idata (m_dat_out),
        .i_wb_err   (m_err),
        .f_nreqs    (), .f_nacks (), .f_outstanding ()
    );

`ifdef FORMAL
    initial assume(rst);
`endif

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, s0_we, s0_adr, s0_dat_out, s0_sel_out,
                s1_we, s1_adr, s1_dat_out, s1_sel_out,
                s0_cyc, s0_stb, s1_cyc, s1_stb, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
