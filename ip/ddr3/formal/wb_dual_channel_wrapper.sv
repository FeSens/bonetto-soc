// Formal harness for the dual-channel Wishbone DDR3 bridge.

`default_nettype none

module ddr3_wb_dual_channel_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer LINE_ADDR_W = 25;
    localparam integer PHY_DATA_W = LANES * 8;

    (* anyseq *) wire                         m_cyc;
    (* anyseq *) wire                         m_stb;
    (* anyseq *) wire                         m_we;
    (* anyseq *) wire [GLOBAL_WORD_ADDR_W-1:0] m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]         m_dat;
    (* anyseq *) wire [(WB_DATA_W/8)-1:0]     m_sel;
    (* anyseq *) wire [(CHANNELS*PHY_DATA_W)-1:0] phy_rd_data;

    wire                         s_stall;
    wire                         s_ack;
    wire [WB_DATA_W-1:0]         s_dat;
    wire                         s_err;

    wire [CHANNELS-1:0]          cmd_valid;
    wire [CHANNELS-1:0]          cmd_ready = {CHANNELS{1'b1}};
    wire [CHANNELS-1:0]          cmd_write;
    wire [(CHANNELS*LINE_ADDR_W)-1:0] cmd_line_addr;
    wire [CHANNELS-1:0]          line_done;
    wire [CHANNELS-1:0]          line_rd_valid;
    wire [(CHANNELS*LANES)-1:0]  phy_wr_valid;
    wire [(CHANNELS*LANES)-1:0]  phy_wr_ready =
        {(CHANNELS*LANES){1'b1}};
    wire [(CHANNELS*PHY_DATA_W)-1:0] phy_wr_data;
    wire [(CHANNELS*LANES)-1:0]  phy_wr_mask;
    wire [(CHANNELS*LANES)-1:0]  phy_wr_last;
    wire [(CHANNELS*LANES)-1:0]  phy_rd_ready;
    wire [(CHANNELS*LANES)-1:0]  phy_rd_valid = phy_rd_ready;

    ddr3_wb_dual_channel dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wb_cyc(m_cyc),
        .i_wb_stb(m_stb),
        .i_wb_we(m_we),
        .i_wb_adr(m_adr),
        .i_wb_dat(m_dat),
        .i_wb_sel(m_sel),
        .o_wb_stall(s_stall),
        .o_wb_ack(s_ack),
        .o_wb_dat(s_dat),
        .o_wb_err(s_err),
        .o_cmd_valid(cmd_valid),
        .i_cmd_ready(cmd_ready),
        .o_cmd_write(cmd_write),
        .o_cmd_line_addr(cmd_line_addr),
        .o_busy(),
        .o_line_done(line_done),
        .o_line_rd_valid(line_rd_valid),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data)
    );

    fwb_slave #(
        .AW(GLOBAL_WORD_ADDR_W),
        .DW(WB_DATA_W),
        .F_MAX_STALL(20),
        .F_MAX_ACK_DELAY(32),
        .F_LGDEPTH(6),
        .F_MAX_REQUESTS(1),
        .OPT_BUS_ABORT(0),
        .F_OPT_DISCONTINUOUS(0),
        .F_OPT_MINCLOCK_DELAY(1)
    ) fwb (
        .i_clk(clk),
        .i_reset(rst),
        .i_wb_cyc(m_cyc),
        .i_wb_stb(m_stb),
        .i_wb_we(m_we),
        .i_wb_addr(m_adr),
        .i_wb_data(m_dat),
        .i_wb_sel(m_sel),
        .i_wb_ack(s_ack),
        .i_wb_stall(s_stall),
        .i_wb_idata(s_dat),
        .i_wb_err(s_err),
        .f_nreqs(),
        .f_nacks(),
        .f_outstanding()
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg f_pending = 1'b0;
    reg f_pending_channel = 1'b0;

    wire wb_accept = m_cyc && m_stb && !s_stall;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst || !m_cyc) begin
            f_pending <= 1'b0;
            f_pending_channel <= 1'b0;
        end else begin
            assert(!(cmd_valid[0] && cmd_valid[1]));
            assert(!s_err);

            if (wb_accept) begin
                assert(!f_pending);
                f_pending <= 1'b1;
                f_pending_channel <= m_adr[29];
            end

            if (f_past_valid && $past(wb_accept)) begin
                if ($past(m_adr[29])) begin
                    assert(cmd_valid == 2'b10);
                    assert(cmd_write[1] == $past(m_we));
                    assert(cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W] ==
                           $past(m_adr[28:4]));
                end else begin
                    assert(cmd_valid == 2'b01);
                    assert(cmd_write[0] == $past(m_we));
                    assert(cmd_line_addr[0 +: LINE_ADDR_W] ==
                           $past(m_adr[28:4]));
                end
            end

            if (s_ack) begin
                assert(f_pending);
                f_pending <= 1'b0;
            end

            if (cmd_valid[0])
                assert(f_pending && !f_pending_channel);
            if (cmd_valid[1])
                assert(f_pending && f_pending_channel);

            cover(f_past_valid && $past(wb_accept) &&
                  !$past(m_adr[29]) && cmd_valid[0]);
            cover(f_past_valid && $past(wb_accept) &&
                  $past(m_adr[29]) && cmd_valid[1]);
            cover(s_ack);
        end
    end
`endif
endmodule

`default_nettype wire
