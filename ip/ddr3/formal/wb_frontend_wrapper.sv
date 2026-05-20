// Formal harness for the DDR3 Wishbone-to-BL8 frontend.

`default_nettype none

module ddr3_wb_frontend_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WB_ADDR_W = 5;
    localparam integer WB_DATA_W = 32;
    localparam integer LINE_BYTES = 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8);
    localparam integer WORD_INDEX_W = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE);
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W;

    (* anyseq *) wire                     m_cyc;
    (* anyseq *) wire                     m_stb;
    (* anyseq *) wire                     m_we;
    (* anyseq *) wire [WB_ADDR_W-1:0]     m_adr;
    (* anyseq *) wire [WB_DATA_W-1:0]     m_dat;
    (* anyseq *) wire [(WB_DATA_W/8)-1:0] m_sel;

    (* anyseq *) wire                     req_ready;
    (* anyseq *) wire                     rsp_valid;
    (* anyseq *) wire [LINE_DATA_W-1:0]   rsp_data;
    (* anyseq *) wire                     rsp_err;

    wire                    s_stall;
    wire                    s_ack;
    wire [WB_DATA_W-1:0]    s_dat;
    wire                    s_err;

    wire                    req_valid;
    wire                    req_write;
    wire [LINE_ADDR_W-1:0]  req_line_addr;
    wire [WORD_INDEX_W-1:0] req_word_index;
    wire [LINE_DATA_W-1:0]  req_wr_data;
    wire [LINE_BYTES-1:0]   req_wr_mask;

    ddr3_wb_frontend #(
        .WB_ADDR_W(WB_ADDR_W),
        .LINE_BYTES(LINE_BYTES),
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
        .o_req_valid(req_valid),
        .i_req_ready(req_ready),
        .o_req_write(req_write),
        .o_req_line_addr(req_line_addr),
        .o_req_word_index(req_word_index),
        .o_req_wr_data(req_wr_data),
        .o_req_wr_mask(req_wr_mask),
        .i_rsp_valid(rsp_valid),
        .i_rsp_data(rsp_data),
        .i_rsp_err(rsp_err)
    );

    fwb_slave #(
        .AW(WB_ADDR_W),
        .DW(WB_DATA_W),
        .F_MAX_STALL(8),
        .F_MAX_ACK_DELAY(12),
        .F_LGDEPTH(4),
        .F_MAX_REQUESTS(1),
        .OPT_BUS_ABORT(1),
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
    reg [2:0] req_wait = 3'd0;
    reg [2:0] rsp_wait = 3'd0;
    reg read_pending = 1'b0;
    reg [WORD_INDEX_W-1:0] pending_word_index = {WORD_INDEX_W{1'b0}};

    wire wb_accept = m_cyc && m_stb && !s_stall;
    wire backend_accept = req_valid && req_ready;

    initial assume(rst);

    function [LINE_DATA_W-1:0] expected_wr_data;
        input [WB_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            expected_wr_data = {LINE_DATA_W{1'b0}};
            for (i = 0; i < (WB_DATA_W / 8); i = i + 1)
                expected_wr_data[(word_index * WB_DATA_W) + (i * 8) +: 8] =
                    data[(i * 8) +: 8];
        end
    endfunction

    function [LINE_BYTES-1:0] expected_wr_mask;
        input [(WB_DATA_W/8)-1:0] sel;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            expected_wr_mask = {LINE_BYTES{1'b0}};
            for (i = 0; i < (WB_DATA_W / 8); i = i + 1)
                expected_wr_mask[(word_index * (WB_DATA_W / 8)) + i] = sel[i];
        end
    endfunction

    function [WB_DATA_W-1:0] expected_rd_data;
        input [LINE_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            expected_rd_data = data[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            req_wait <= 3'd0;
            rsp_wait <= 3'd0;
            read_pending <= 1'b0;
            pending_word_index <= {WORD_INDEX_W{1'b0}};
        end else begin
            if (req_valid && !req_ready) begin
                req_wait <= req_wait + 3'd1;
                if (req_wait == 3'd3)
                    assume(req_ready);
            end else begin
                req_wait <= 3'd0;
            end

            if (read_pending && !rsp_valid) begin
                rsp_wait <= rsp_wait + 3'd1;
                if (rsp_wait == 3'd3)
                    assume(rsp_valid);
            end else begin
                rsp_wait <= 3'd0;
            end

            if (!read_pending)
                assume(!rsp_valid);

            if (f_past_valid && $past(wb_accept)) begin
                assert(req_valid);
                assert(req_write == $past(m_we));
                assert(req_line_addr == $past(m_adr[WB_ADDR_W-1:WORD_INDEX_W]));
                assert(req_word_index == $past(m_adr[WORD_INDEX_W-1:0]));
                assert(req_wr_data == expected_wr_data(
                    $past(m_dat), $past(m_adr[WORD_INDEX_W-1:0])));
                assert(req_wr_mask == expected_wr_mask(
                    $past(m_sel), $past(m_adr[WORD_INDEX_W-1:0])));
            end

            if (f_past_valid && $past(req_valid && !req_ready)) begin
                assert(req_valid);
                assert(req_write == $past(req_write));
                assert(req_line_addr == $past(req_line_addr));
                assert(req_word_index == $past(req_word_index));
                assert(req_wr_data == $past(req_wr_data));
                assert(req_wr_mask == $past(req_wr_mask));
            end

            if (backend_accept && !req_write) begin
                read_pending <= 1'b1;
                pending_word_index <= req_word_index;
            end

            if (rsp_valid && read_pending)
                read_pending <= 1'b0;

            if (f_past_valid && $past(backend_accept && req_write && m_cyc)) begin
                assert(s_ack);
                assert(!s_err);
            end

            if (f_past_valid && $past(read_pending && rsp_valid && m_cyc)) begin
                assert(s_ack);
                assert(s_err == $past(rsp_err));
                assert(s_dat == expected_rd_data(
                    $past(rsp_data), $past(pending_word_index)));
            end

            cover(backend_accept && req_write);
            cover(read_pending && rsp_valid && m_cyc);
        end
    end
`endif
endmodule

`default_nettype wire
