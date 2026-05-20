// Formal harness for the integrated Wishbone-to-full-channel BL8 data bridge.

`default_nettype none

module ddr3_wb_channel_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_ADDR_W = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer LANES = 8;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8);
    localparam integer WORD_INDEX_W = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE);
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W;

    (* anyseq *) wire                     m_cyc;
    (* anyseq *) wire                     m_stb;
    (* anyseq *) wire                     m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [(WB_DATA_W/8)-1:0] m_sel;

    (* anyseq *) wire                     cmd_ready;
    (* anyseq *) wire [LANES-1:0]         phy_wr_ready;
    (* anyseq *) wire [LANES-1:0]         phy_rd_valid;
    (* anyseq *) wire [(LANES*8)-1:0]     phy_rd_data;

    wire                    s_stall;
    wire                    s_ack;
    wire [WB_DATA_W-1:0]    s_dat;
    wire                    s_err;
    wire                    cmd_valid;
    wire                    cmd_write;
    wire [LINE_ADDR_W-1:0]  cmd_line_addr;
    wire                    xfer_start;
    wire                    line_done;
    wire                    line_rd_valid;
    wire [LANES-1:0]        phy_wr_valid;
    wire [(LANES*8)-1:0]    phy_wr_data;
    wire [LANES-1:0]        phy_wr_mask;
    wire [LANES-1:0]        phy_wr_last;
    wire [LANES-1:0]        phy_rd_ready;

    ddr3_wb_channel #(
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
        .AW(WB_ADDR_W),
        .DW(WB_DATA_W),
        .F_MAX_STALL(20),
        .F_MAX_ACK_DELAY(24),
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
    reg [2:0] cmd_wait = 3'd0;
    reg f_pending = 1'b0;
    reg f_pending_write = 1'b0;
    reg [LINE_ADDR_W-1:0] f_pending_line_addr = {LINE_ADDR_W{1'b0}};
    reg [WORD_INDEX_W-1:0] f_pending_word_index = {WORD_INDEX_W{1'b0}};
    reg [WB_DATA_W-1:0] f_pending_data = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] f_pending_sel = {(WB_DATA_W/8){1'b0}};

    reg f_xfer_pending = 1'b0;
    reg f_xfer_write = 1'b0;
    reg [WORD_INDEX_W-1:0] f_xfer_word_index = {WORD_INDEX_W{1'b0}};
    reg [WB_DATA_W-1:0] f_xfer_data = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] f_xfer_sel = {(WB_DATA_W/8){1'b0}};

    reg f_write_active = 1'b0;
    reg [WORD_INDEX_W-1:0] f_write_word_index = {WORD_INDEX_W{1'b0}};
    reg [WB_DATA_W-1:0] f_write_data = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] f_write_sel = {(WB_DATA_W/8){1'b0}};
    reg [(LANES*3)-1:0] f_wr_index = {(LANES*3){1'b0}};

    reg f_read_active = 1'b0;
    reg [WORD_INDEX_W-1:0] f_read_word_index = {WORD_INDEX_W{1'b0}};
    reg [(LINE_BYTES*8)-1:0] f_read_line = {(LINE_BYTES*8){1'b0}};
    reg [(LANES*3)-1:0] f_rd_index = {(LANES*3){1'b0}};

    reg [(LINE_BYTES*8)-1:0] f_read_line_next;
    integer i;

    wire wb_accept = m_cyc && m_stb && !s_stall;
    wire cmd_accept = cmd_valid && cmd_ready;
    assign xfer_start = f_xfer_pending && !f_write_active && !f_read_active;

    initial assume(rst);

    function [2:0] lane_wr_index;
        input integer lane;
        begin
            lane_wr_index = f_wr_index[(lane * 3) +: 3];
        end
    endfunction

    function [2:0] lane_rd_index;
        input integer lane;
        begin
            lane_rd_index = f_rd_index[(lane * 3) +: 3];
        end
    endfunction

    function [7:0] expected_write_byte;
        input integer lane;
        input [2:0] beat;
        integer byte_index;
        integer word_byte;
        begin
            byte_index = (lane * 8) + beat;
            word_byte = byte_index - (f_write_word_index * (WB_DATA_W / 8));
            expected_write_byte = 8'h00;
            if ((byte_index >= (f_write_word_index * (WB_DATA_W / 8))) &&
                (byte_index < ((f_write_word_index + 1'b1) * (WB_DATA_W / 8))))
                expected_write_byte = f_write_data[(word_byte * 8) +: 8];
        end
    endfunction

    function expected_write_mask;
        input integer lane;
        input [2:0] beat;
        integer byte_index;
        integer word_byte;
        begin
            byte_index = (lane * 8) + beat;
            word_byte = byte_index - (f_write_word_index * (WB_DATA_W / 8));
            expected_write_mask = 1'b1;
            if ((byte_index >= (f_write_word_index * (WB_DATA_W / 8))) &&
                (byte_index < ((f_write_word_index + 1'b1) * (WB_DATA_W / 8))))
                expected_write_mask = ~f_write_sel[word_byte];
        end
    endfunction

    function [WB_DATA_W-1:0] expected_read_word;
        input [(LINE_BYTES*8)-1:0] line;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            expected_read_word = line[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    always @(*) begin
        f_read_line_next = f_read_line;

        for (i = 0; i < LANES; i = i + 1) begin
            if (phy_rd_valid[i] && phy_rd_ready[i]) begin
                f_read_line_next[((i * 8) + lane_rd_index(i)) * 8 +: 8] =
                    phy_rd_data[(i * 8) +: 8];
            end
        end
    end

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            cmd_wait <= 3'd0;
            f_pending <= 1'b0;
            f_pending_write <= 1'b0;
            f_pending_line_addr <= {LINE_ADDR_W{1'b0}};
            f_pending_word_index <= {WORD_INDEX_W{1'b0}};
            f_pending_data <= {WB_DATA_W{1'b0}};
            f_pending_sel <= {(WB_DATA_W/8){1'b0}};
            f_xfer_pending <= 1'b0;
            f_xfer_write <= 1'b0;
            f_xfer_word_index <= {WORD_INDEX_W{1'b0}};
            f_xfer_data <= {WB_DATA_W{1'b0}};
            f_xfer_sel <= {(WB_DATA_W/8){1'b0}};
            f_write_active <= 1'b0;
            f_write_word_index <= {WORD_INDEX_W{1'b0}};
            f_write_data <= {WB_DATA_W{1'b0}};
            f_write_sel <= {(WB_DATA_W/8){1'b0}};
            f_wr_index <= {(LANES*3){1'b0}};
            f_read_active <= 1'b0;
            f_read_word_index <= {WORD_INDEX_W{1'b0}};
            f_read_line <= {(LINE_BYTES*8){1'b0}};
            f_rd_index <= {(LANES*3){1'b0}};
        end else begin
            if (cmd_valid && !cmd_ready) begin
                cmd_wait <= cmd_wait + 3'd1;
                if (cmd_wait == 3'd3)
                    assume(cmd_ready);
            end else begin
                cmd_wait <= 3'd0;
            end

            if (f_pending || f_xfer_pending || f_write_active || f_read_active)
                assume(m_cyc);

            if (f_write_active)
                assume(phy_wr_ready == {LANES{1'b1}});
            if (f_read_active)
                assume(phy_rd_valid == phy_rd_ready);

            if (wb_accept) begin
                assert(!f_pending);
                f_pending <= 1'b1;
                f_pending_write <= m_we;
                f_pending_line_addr <= m_adr[WB_ADDR_W-1:WORD_INDEX_W];
                f_pending_word_index <= m_adr[WORD_INDEX_W-1:0];
                f_pending_data <= m_dat;
                f_pending_sel <= m_sel;
            end

            if (f_past_valid && $past(wb_accept)) begin
                assert(cmd_valid);
                assert(cmd_write == $past(m_we));
                assert(cmd_line_addr == $past(m_adr[WB_ADDR_W-1:WORD_INDEX_W]));
            end

            if (f_past_valid && $past(cmd_valid && !cmd_ready)) begin
                assert(cmd_valid);
                assert(cmd_write == $past(cmd_write));
                assert(cmd_line_addr == $past(cmd_line_addr));
            end

            if (cmd_accept) begin
                assert(f_pending);
                assert(cmd_write == f_pending_write);
                assert(cmd_line_addr == f_pending_line_addr);
                f_pending <= 1'b0;
                f_xfer_pending <= 1'b1;
                f_xfer_write <= f_pending_write;
                f_xfer_word_index <= f_pending_word_index;
                f_xfer_data <= f_pending_data;
                f_xfer_sel <= f_pending_sel;
            end

            if (xfer_start) begin
                assert(f_xfer_pending || cmd_accept);
                assert(!f_write_active);
                assert(!f_read_active);
                f_xfer_pending <= 1'b0;

                if (cmd_accept ? f_pending_write : f_xfer_write) begin
                    f_write_active <= 1'b1;
                    f_write_word_index <= cmd_accept ?
                        f_pending_word_index : f_xfer_word_index;
                    f_write_data <= cmd_accept ? f_pending_data : f_xfer_data;
                    f_write_sel <= cmd_accept ? f_pending_sel : f_xfer_sel;
                    f_wr_index <= {(LANES*3){1'b0}};
                end else begin
                    f_read_active <= 1'b1;
                    f_read_word_index <= cmd_accept ?
                        f_pending_word_index : f_xfer_word_index;
                    f_read_line <= {(LINE_BYTES*8){1'b0}};
                    f_rd_index <= {(LANES*3){1'b0}};
                end
            end

            if (f_write_active) begin
                for (i = 0; i < LANES; i = i + 1) begin
                    if (phy_wr_valid[i] && phy_wr_ready[i]) begin
                        if (lane_wr_index(i) == 3'd7)
                            f_wr_index[(i * 3) +: 3] <= 3'd0;
                        else
                            f_wr_index[(i * 3) +: 3] <= lane_wr_index(i) + 3'd1;
                    end
                end
            end

            if (f_read_active) begin
                f_read_line <= f_read_line_next;

                for (i = 0; i < LANES; i = i + 1) begin
                    if (phy_rd_valid[i] && phy_rd_ready[i]) begin
                        if (lane_rd_index(i) == 3'd7)
                            f_rd_index[(i * 3) +: 3] <= 3'd0;
                        else
                            f_rd_index[(i * 3) +: 3] <= lane_rd_index(i) + 3'd1;
                    end
                end
            end

            if (line_done && f_write_active)
                f_write_active <= 1'b0;

            if (line_rd_valid)
                assert(f_read_active);

            if (s_ack && f_read_active) begin
                assert(!s_err);
                assert(s_dat == expected_read_word(f_read_line, f_read_word_index));
                f_read_active <= 1'b0;
            end

            if (s_ack && f_write_active) begin
                assert(!s_err);
            end

            for (i = 0; i < LANES; i = i + 1) begin
                if (phy_wr_valid[i]) begin
                    assert(f_write_active);
                    assert(phy_wr_data[(i * 8) +: 8] ==
                           expected_write_byte(i, lane_wr_index(i)));
                    assert(phy_wr_mask[i] ==
                           expected_write_mask(i, lane_wr_index(i)));
                    assert(phy_wr_last[i] == (lane_wr_index(i) == 3'd7));
                end

                if (phy_rd_ready[i])
                    assert(f_read_active);
            end

            cover(cmd_accept && cmd_write);
            cover(xfer_start && (f_xfer_pending || cmd_accept));
            cover(s_ack && f_read_active);
        end
    end
`endif
endmodule

`default_nettype wire
