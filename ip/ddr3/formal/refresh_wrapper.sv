// Formal harness for the periodic refresh requester feeding the scheduler.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_refresh_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer T_RCD   = 3;
    localparam integer T_RP    = 3;
    localparam integer T_RAS   = 5;
    localparam integer T_RC    = 8;
    localparam integer T_RTP   = 3;
    localparam integer T_WR    = 6;
    localparam integer T_CCD   = 4;
    localparam integer T_WTR   = 6;
    localparam integer T_RRD   = 3;
    localparam integer T_FAW   = 8;
    localparam integer T_RFC   = 4;
    localparam integer T_REFI  = 24;
    localparam integer T_MARGIN = 6;

    wire        refresh_req;
    wire        refresh_ack;
    wire        refresh_busy;
    wire        refresh_late;
    wire        refresh_window;
    wire [7:0]  cycles_to_deadline;
    wire [15:0] refresh_count;

    wire [7:0]  bank_busy;
    wire [7:0]  bank_open;
    wire        cmd_valid;
    wire        cs_n;
    wire        ras_n;
    wire        cas_n;
    wire        we_n;
    wire [2:0]  ba;
    wire [14:0] addr;

    ddr3_refresh #(
        .COUNTER_BITS(8),
        .T_REFI(T_REFI),
        .T_MARGIN(T_MARGIN)
    ) timer (
        .i_clk(clk),
        .i_rst(rst),
        .i_enable(!rst),
        .i_refresh_ack(refresh_ack),
        .o_refresh_req(refresh_req),
        .o_refresh_late(refresh_late),
        .o_refresh_window(refresh_window),
        .o_cycles_to_deadline(cycles_to_deadline),
        .o_refresh_count(refresh_count)
    );

    ddr3_scheduler #(
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
    ) scheduler (
        .i_clk(clk),
        .i_rst(rst),
        .i_req_valid(1'b0),
        .o_req_ready(),
        .i_req_write(1'b0),
        .i_req_bank(3'd0),
        .i_req_row(15'd0),
        .i_req_col(15'd0),
        .i_refresh_req(refresh_req),
        .o_refresh_ack(refresh_ack),
        .o_refresh_busy(refresh_busy),
        .o_rsp_valid(),
        .o_rsp_write(),
        .o_rsp_bank(),
        .o_bank_busy(bank_busy),
        .o_bank_open(bank_open),
        .o_cmd_valid(cmd_valid),
        .o_cs_n(cs_n),
        .o_ras_n(ras_n),
        .o_cas_n(cas_n),
        .o_we_n(we_n),
        .o_ba(ba),
        .o_addr(addr)
    );

    ddr3_cmd_timing_monitor #(
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
        .T_REFI(T_REFI),
        .CHECK_REFRESH_DEADLINE(1)
    ) monitor (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_valid(cmd_valid),
        .i_cs_n(cs_n),
        .i_ras_n(ras_n),
        .i_cas_n(cas_n),
        .i_we_n(we_n),
        .i_bank(ba),
        .i_addr(addr)
    );

`ifdef FORMAL
    wire selected = cmd_valid && !cs_n;
    wire cmd_ref = selected && ({cs_n, ras_n, cas_n, we_n} == `DDR3_CMD_REF);

    reg f_past_valid = 1'b0;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (!rst) begin
            assert(!refresh_late);

            if (refresh_window)
                assert(refresh_req);

            if (refresh_ack)
                assert(cmd_ref);

            if (cmd_ref) begin
                assert(refresh_ack);
                assert(bank_open == 8'd0);
            end

            cover(refresh_count == 16'd1);
            cover(refresh_count == 16'd2);
        end
    end
`endif
endmodule

`default_nettype wire
