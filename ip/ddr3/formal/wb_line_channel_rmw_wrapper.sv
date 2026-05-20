// Formal harness for the no-DM read-modify-write line bridge mode.

`default_nettype none

module ddr3_wb_line_channel_rmw_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_ADDR_W = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer LANES = 8;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8);
    localparam integer WORD_INDEX_W =
        (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE);
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W;

    (* anyseq *) wire                     m_cyc;
    (* anyseq *) wire                     m_stb;
    (* anyseq *) wire                     m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [(WB_DATA_W/8)-1:0] m_sel;

    (* anyseq *) wire                    cmd_ready;
    (* anyseq *) wire                    wr_line_ready;
    (* anyseq *) wire                    xfer_start;
    (* anyseq *) wire                    rd_line_valid;
    (* anyseq *) wire [LINE_DATA_W-1:0]  rd_line_data;
    (* anyseq *) wire                    rd_line_err;

    wire                    s_stall;
    wire                    s_ack;
    wire [WB_DATA_W-1:0]    s_dat;
    wire                    s_err;
    wire                    cmd_valid;
    wire                    cmd_write;
    wire [LINE_ADDR_W-1:0]  cmd_line_addr;
    wire                    wr_line_valid;
    wire [LINE_DATA_W-1:0]  wr_line_data;
    wire [LINE_BYTES-1:0]   wr_line_mask;
    wire                    rd_line_ready;

    ddr3_wb_line_channel #(
        .WB_ADDR_W(WB_ADDR_W),
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W),
        .PHY_HAS_BYTE_MASK(0)
    ) dut (
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
        .i_xfer_start(xfer_start),
        .o_phy_wr_line_valid(wr_line_valid),
        .i_phy_wr_line_ready(wr_line_ready),
        .i_phy_wr_line_loaded(wr_line_ready),
        .o_phy_wr_line_data(wr_line_data),
        .o_phy_wr_line_mask(wr_line_mask),
        .o_phy_rd_line_ready(rd_line_ready),
        .i_phy_rd_line_valid(rd_line_valid),
        .i_phy_rd_line_data(rd_line_data),
        .i_phy_rd_line_err(rd_line_err)
    );

    fwb_slave #(
        .AW(WB_ADDR_W),
        .DW(WB_DATA_W),
        .F_MAX_STALL(24),
        .F_MAX_ACK_DELAY(48),
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
    reg f_pending_write = 1'b0;
    reg [LINE_ADDR_W-1:0] f_pending_line_addr = {LINE_ADDR_W{1'b0}};
    reg [WORD_INDEX_W-1:0] f_pending_word_index = {WORD_INDEX_W{1'b0}};
    reg [WB_DATA_W-1:0] f_pending_data = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] f_pending_sel = {(WB_DATA_W/8){1'b0}};
    reg f_wait_xfer = 1'b0;
    reg f_wait_data = 1'b0;
    reg f_wait_rmw_write = 1'b0;
    reg [LINE_DATA_W-1:0] f_rmw_read_line = {LINE_DATA_W{1'b0}};

    wire wb_accept = m_cyc && m_stb && !s_stall;
    wire cmd_accept = cmd_valid && cmd_ready;

    initial assume(rst);

    function [WB_DATA_W-1:0] expected_read_word;
        input [LINE_DATA_W-1:0] line;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            expected_read_word = line[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    function [LINE_DATA_W-1:0] expected_merged_line;
        input [LINE_DATA_W-1:0] old_line;
        input [WB_DATA_W-1:0] data;
        input [(WB_DATA_W/8)-1:0] sel;
        input [WORD_INDEX_W-1:0] word_index;
        integer byte_i;
        begin
            expected_merged_line = old_line;
            for (byte_i = 0; byte_i < (WB_DATA_W / 8); byte_i = byte_i + 1) begin
                if (sel[byte_i])
                    expected_merged_line[(word_index * WB_DATA_W) +
                                         (byte_i * 8) +: 8] =
                        data[(byte_i * 8) +: 8];
            end
        end
    endfunction

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_pending <= 1'b0;
            f_pending_write <= 1'b0;
            f_pending_line_addr <= {LINE_ADDR_W{1'b0}};
            f_pending_word_index <= {WORD_INDEX_W{1'b0}};
            f_pending_data <= {WB_DATA_W{1'b0}};
            f_pending_sel <= {(WB_DATA_W/8){1'b0}};
            f_wait_xfer <= 1'b0;
            f_wait_data <= 1'b0;
            f_wait_rmw_write <= 1'b0;
            f_rmw_read_line <= {LINE_DATA_W{1'b0}};
        end else begin
            if (f_pending || f_wait_xfer || f_wait_data || f_wait_rmw_write)
                assume(m_cyc);

            if (wb_accept) begin
                assert(!f_pending);
                assert(!f_wait_xfer);
                assert(!f_wait_data);
                assert(!f_wait_rmw_write);
                f_pending <= 1'b1;
                f_pending_write <= m_we;
                f_pending_line_addr <= m_adr[WB_ADDR_W-1:WORD_INDEX_W];
                f_pending_word_index <= m_adr[WORD_INDEX_W-1:0];
                f_pending_data <= m_dat;
                f_pending_sel <= m_sel;
            end

            if (f_past_valid && $past(wb_accept)) begin
                assert(cmd_valid);
                assert(!cmd_write);
                assert(cmd_line_addr ==
                       $past(m_adr[WB_ADDR_W-1:WORD_INDEX_W]));
            end

            if (f_past_valid && $past(cmd_valid && !cmd_ready)) begin
                assert(cmd_valid);
                assert(cmd_write == $past(cmd_write));
                assert(cmd_line_addr == $past(cmd_line_addr));
                if (!$past(cmd_write))
                    assert(!wr_line_valid);
            end

            if (wr_line_valid) begin
                assert(f_wait_rmw_write);
                assert(!cmd_valid);
                assert(wr_line_mask == {LINE_BYTES{1'b0}});
                assert(wr_line_data == expected_merged_line(
                    f_rmw_read_line, f_pending_data, f_pending_sel,
                    f_pending_word_index));
            end

            if (cmd_accept && !cmd_write) begin
                assert(f_pending);
                assert(cmd_line_addr == f_pending_line_addr);
                f_pending <= 1'b0;
                f_wait_xfer <= 1'b1;
            end

            if (xfer_start && f_wait_xfer) begin
                f_wait_xfer <= 1'b0;
                f_wait_data <= 1'b1;
            end

            if (rd_line_ready)
                assert(f_wait_data);

            if (rd_line_valid && rd_line_ready) begin
                assert(f_wait_data);
                f_wait_data <= 1'b0;
                if (f_pending_write && !rd_line_err) begin
                    f_wait_rmw_write <= 1'b1;
                    f_rmw_read_line <= rd_line_data;
                end
            end

            if (cmd_accept && cmd_write) begin
                assert(f_wait_rmw_write);
                assert(!wr_line_valid);
                f_wait_rmw_write <= 1'b0;
            end

            if (s_ack && f_pending_write)
                assert(!s_err || rd_line_err);

            if (s_ack && !f_pending_write) begin
                assert(s_err == rd_line_err);
                assert(s_dat == expected_read_word(
                    rd_line_data, f_pending_word_index));
            end

            cover(cmd_accept && !cmd_write && f_pending_write);
            cover(wr_line_valid && s_ack);
            cover(rd_line_valid && rd_line_ready && s_ack && !f_pending_write);
        end
    end
`endif
endmodule

`default_nettype wire
