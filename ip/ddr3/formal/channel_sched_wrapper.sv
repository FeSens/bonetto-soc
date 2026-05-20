// Formal harness for the BL8 line-to-DDR3 scheduler adapter.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_channel_sched_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = 1;
    localparam integer ROW_BITS  = `DDR3_ROW_BITS;
    localparam integer COL_BITS  = `DDR3_COL_BITS;
    localparam integer COL_LINE_BITS = COL_BITS - 3;
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS;
    localparam integer T_RCD = 3;
    localparam integer T_RP  = 3;
    localparam integer T_RAS = 5;
    localparam integer T_RC  = 8;
    localparam integer T_RTP = 3;
    localparam integer T_WR  = 6;
    localparam integer T_CCD = 4;
    localparam integer T_WTR = 6;
    localparam integer T_RRD = 3;
    localparam integer T_FAW = 8;
    localparam integer T_RFC = 4;

    (* anyseq *) wire                    cmd_valid;
    (* anyseq *) wire                    cmd_write;
    (* anyseq *) wire [LINE_ADDR_W-1:0]  cmd_line_addr;

    wire                    cmd_ready;
    wire                    xfer_start;
    wire                    refresh_req;
    wire                    refresh_ack;
    wire                    refresh_busy;
    wire                    refresh_late;
    wire [15:0]             refresh_count;
    wire                    req_pending;
    wire [(1 << BANK_BITS)-1:0] bank_busy;
    wire [(1 << BANK_BITS)-1:0] bank_open;
    wire                    ddr_cmd_valid;
    wire                    cs_n;
    wire                    ras_n;
    wire                    cas_n;
    wire                    we_n;
    wire [BANK_BITS-1:0]    ba;
    wire [ADDR_BITS-1:0]    addr;

    ddr3_channel_sched #(
        .BANK_BITS(BANK_BITS),
        .T_RCD(T_RCD),
        .T_RP(T_RP),
        .T_RAS(T_RAS),
        .T_RC(T_RC),
        .T_RTP(T_RTP),
        .T_WR(T_WR),
        .T_CCD(T_CCD),
        .T_WTR(T_WTR),
        .T_RRD(T_RRD),
        .T_FAW(T_FAW),
        .T_RFC(T_RFC)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_valid(cmd_valid),
        .o_cmd_ready(cmd_ready),
        .i_cmd_write(cmd_write),
        .i_cmd_line_addr(cmd_line_addr),
        .o_xfer_start(xfer_start),
        .i_refresh_enable(1'b0),
        .o_refresh_req(refresh_req),
        .o_refresh_ack(refresh_ack),
        .o_refresh_busy(refresh_busy),
        .o_refresh_late(refresh_late),
        .o_refresh_count(refresh_count),
        .o_req_pending(req_pending),
        .o_bank_busy(bank_busy),
        .o_bank_open(bank_open),
        .o_cmd_valid(ddr_cmd_valid),
        .o_cs_n(cs_n),
        .o_ras_n(ras_n),
        .o_cas_n(cas_n),
        .o_we_n(we_n),
        .o_ba(ba),
        .o_addr(addr)
    );

    ddr3_cmd_timing_monitor #(
        .BANK_BITS(BANK_BITS),
        .T_RCD(T_RCD),
        .T_RP(T_RP),
        .T_RAS(T_RAS),
        .T_RC(T_RC),
        .T_RRD(T_RRD),
        .T_FAW(T_FAW),
        .T_CCD(T_CCD),
        .T_WTR(T_WTR),
        .T_RTP(T_RTP),
        .T_WR(T_WR),
        .T_RFC(T_RFC),
        .T_ZQ(4),
        .T_REFI(64),
        .CHECK_REFRESH_DEADLINE(0)
    ) monitor (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_valid(ddr_cmd_valid),
        .i_cs_n(cs_n),
        .i_ras_n(ras_n),
        .i_cas_n(cas_n),
        .i_we_n(we_n),
        .i_bank(ba),
        .i_addr(addr)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg f_wait_cmd_ready = 1'b0;
    reg f_pending = 1'b0;
    reg f_pending_write = 1'b0;
    reg [LINE_ADDR_W-1:0] f_pending_line = {LINE_ADDR_W{1'b0}};
    reg saw_read = 1'b0;
    reg saw_write = 1'b0;

    wire selected = ddr_cmd_valid && !cs_n;
    wire [3:0] ddr_cmd = {cs_n, ras_n, cas_n, we_n};
    wire ddr_read = selected && (ddr_cmd == `DDR3_CMD_RD);
    wire ddr_write = selected && (ddr_cmd == `DDR3_CMD_WR);
    wire f_new_cmd = cmd_valid && !f_wait_cmd_ready && !f_pending;

    initial assume(rst);

    function [BANK_BITS-1:0] line_bank;
        input [LINE_ADDR_W-1:0] line;
        begin
            line_bank = line[LINE_ADDR_W-1 -: BANK_BITS];
        end
    endfunction

    function [ADDR_BITS-1:0] line_col_addr;
        input [LINE_ADDR_W-1:0] line;
        begin
            line_col_addr = {{(ADDR_BITS-COL_BITS){1'b0}},
                             line[COL_LINE_BITS-1:0], 3'b000};
        end
    endfunction

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wait_cmd_ready <= 1'b0;
            f_pending <= 1'b0;
            f_pending_write <= 1'b0;
            f_pending_line <= {LINE_ADDR_W{1'b0}};
            saw_read <= 1'b0;
            saw_write <= 1'b0;
        end else begin
            assert(!refresh_req);
            assert(!refresh_ack);
            assert(!refresh_busy);
            assert(!refresh_late);
            assert(refresh_count == 16'd0);

            if (f_wait_cmd_ready && !cmd_ready) begin
                assume(cmd_valid);
                assume(cmd_write == f_pending_write);
                assume(cmd_line_addr == f_pending_line);
            end

            if (f_pending)
                assume(!cmd_valid);

            if (f_new_cmd) begin
                f_wait_cmd_ready <= 1'b1;
                f_pending_write <= cmd_write;
                f_pending_line <= cmd_line_addr;
            end

            if (cmd_ready) begin
                assert(f_wait_cmd_ready || f_new_cmd);
                assert(!f_pending);
                f_wait_cmd_ready <= 1'b0;
                f_pending <= 1'b1;
                if (f_new_cmd) begin
                    f_pending_write <= cmd_write;
                    f_pending_line <= cmd_line_addr;
                end
            end

            if (xfer_start) begin
                assert(f_pending);
                assert((f_pending_write && ddr_write) ||
                       (!f_pending_write && ddr_read));
                assert(ba == line_bank(f_pending_line));
                assert(addr == line_col_addr(f_pending_line));
                f_pending <= 1'b0;
                if (f_pending_write)
                    saw_write <= 1'b1;
                else
                    saw_read <= 1'b1;
            end

            assert(!(cmd_ready && xfer_start));
            assert(req_pending == f_pending);

            cover(saw_write);
            cover(saw_read);
            cover(bank_open != {(1 << BANK_BITS){1'b0}});
            cover(bank_busy != {(1 << BANK_BITS){1'b0}});
        end
    end
`endif
endmodule

`default_nettype wire
