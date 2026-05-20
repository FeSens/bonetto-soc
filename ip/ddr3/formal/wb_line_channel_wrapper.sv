// Formal harness for the line-level Wishbone-to-DDR3 channel bridge.

`default_nettype none

module ddr3_wb_line_channel_wrapper (
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
        .WB_DATA_W(WB_DATA_W)
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
        .F_MAX_STALL(20),
        .F_MAX_ACK_DELAY(32),
        .F_LGDEPTH(5),
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
    reg f_wait_read_xfer = 1'b0;
    reg f_wait_read_data = 1'b0;
    reg [WORD_INDEX_W-1:0] f_read_word_index = {WORD_INDEX_W{1'b0}};

    wire wb_accept = m_cyc && m_stb && !s_stall;
    wire cmd_accept = cmd_valid && cmd_ready;

    initial assume(rst);

    function [7:0] expected_write_byte;
        input integer byte_index;
        integer word_byte;
        begin
            word_byte = byte_index -
                (f_pending_word_index * (WB_DATA_W / 8));
            expected_write_byte = 8'h00;
            if ((byte_index >=
                    (f_pending_word_index * (WB_DATA_W / 8))) &&
                (byte_index <
                    ((f_pending_word_index + 1'b1) * (WB_DATA_W / 8))))
                expected_write_byte = f_pending_data[(word_byte * 8) +: 8];
        end
    endfunction

    function expected_write_mask;
        input integer byte_index;
        integer word_byte;
        begin
            word_byte = byte_index -
                (f_pending_word_index * (WB_DATA_W / 8));
            expected_write_mask = 1'b1;
            if ((byte_index >=
                    (f_pending_word_index * (WB_DATA_W / 8))) &&
                (byte_index <
                    ((f_pending_word_index + 1'b1) * (WB_DATA_W / 8))))
                expected_write_mask = ~f_pending_sel[word_byte];
        end
    endfunction

    function [WB_DATA_W-1:0] expected_read_word;
        input [LINE_DATA_W-1:0] line;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            expected_read_word = line[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    integer i;

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
            f_wait_read_xfer <= 1'b0;
            f_wait_read_data <= 1'b0;
            f_read_word_index <= {WORD_INDEX_W{1'b0}};
        end else begin
            if (f_pending || f_wait_read_xfer || f_wait_read_data)
                assume(m_cyc);

            if (wb_accept) begin
                assert(!f_pending);
                assert(!f_wait_read_xfer);
                assert(!f_wait_read_data);
                f_pending <= 1'b1;
                f_pending_write <= m_we;
                f_pending_line_addr <= m_adr[WB_ADDR_W-1:WORD_INDEX_W];
                f_pending_word_index <= m_adr[WORD_INDEX_W-1:0];
                f_pending_data <= m_dat;
                f_pending_sel <= m_sel;
            end

            if (f_past_valid && $past(wb_accept)) begin
                assert(cmd_write == $past(m_we));
                assert(cmd_line_addr ==
                       $past(m_adr[WB_ADDR_W-1:WORD_INDEX_W]));
            end

            if (f_past_valid && $past(cmd_valid && !cmd_ready)) begin
                assert(cmd_valid == $past(cmd_valid));
                assert(cmd_write == $past(cmd_write));
                assert(cmd_line_addr == $past(cmd_line_addr));
                if ($past(cmd_write))
                    assert(!wr_line_valid);
            end

            if (cmd_valid && cmd_write)
                assert(wr_line_ready);

            if (wr_line_valid) begin
                assert(cmd_valid);
                assert(cmd_ready);
                assert(cmd_write);
                for (i = 0; i < LINE_BYTES; i = i + 1) begin
                    assert(wr_line_data[i * 8 +: 8] ==
                           expected_write_byte(i));
                    assert(wr_line_mask[i] == expected_write_mask(i));
                end
            end

            if (cmd_accept) begin
                assert(f_pending);
                assert(cmd_write == f_pending_write);
                assert(cmd_line_addr == f_pending_line_addr);
                f_pending <= 1'b0;
                if (f_pending_write) begin
                    assert(wr_line_valid);
                end else begin
                    f_wait_read_xfer <= 1'b1;
                    f_read_word_index <= f_pending_word_index;
                end
            end

            if (xfer_start && f_wait_read_xfer) begin
                f_wait_read_xfer <= 1'b0;
                f_wait_read_data <= 1'b1;
            end

            if (rd_line_ready)
                assert(f_wait_read_data);

            if (rd_line_valid && rd_line_ready) begin
                assert(f_wait_read_data);
                f_wait_read_data <= 1'b0;
            end

            if (s_ack && f_pending_write) begin
                assert(!s_err);
            end

            if (s_ack && !f_pending_write) begin
                assert(s_err == rd_line_err);
                assert(s_dat == expected_read_word(
                    rd_line_data, f_read_word_index));
            end

            cover(wr_line_valid && s_ack);
            cover(rd_line_valid && rd_line_ready && s_ack);
        end
    end
`endif
endmodule

`default_nettype wire
