// Formal harness for the one-bank row/timing machine.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_bank_wrapper (
    input wire        clk,
    input wire        rst,
    input wire        req_valid,
    input wire        req_write,
    input wire [14:0] req_row,
    input wire [14:0] req_col
);
    localparam integer T_RCD = 3;
    localparam integer T_RP  = 3;
    localparam integer T_RAS = 5;
    localparam integer T_RC  = 8;
    localparam integer T_RTP = 3;
    localparam integer T_WR  = 6;
    localparam integer T_CCD = 4;
    localparam integer T_WTR = 6;

    wire       req_ready;
    wire       rsp_valid;
    wire       rsp_write;
    wire [3:0] state;
    wire       busy;
    wire       open;
    wire [14:0] open_row;
    wire       cmd_valid;
    wire       cs_n;
    wire       ras_n;
    wire       cas_n;
    wire       we_n;
    wire [2:0] ba;
    wire [14:0] addr;

    ddr3_bank #(
        .T_RCD(T_RCD),
        .T_RP(T_RP),
        .T_RAS(T_RAS),
        .T_RC(T_RC),
        .T_RTP(T_RTP),
        .T_WR(T_WR),
        .T_CCD(T_CCD),
        .T_WTR(T_WTR)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_req_valid(req_valid),
        .o_req_ready(req_ready),
        .i_req_write(req_write),
        .i_req_row(req_row),
        .i_req_col({req_col[14:11], 1'b0, req_col[9:0]}),
        .i_cmd_ready(1'b1),
        .i_close_req(1'b0),
        .o_close_ready(),
        .o_rsp_valid(rsp_valid),
        .o_rsp_write(rsp_write),
        .o_state(state),
        .o_busy(busy),
        .o_open(open),
        .o_open_row(open_row),
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
        .T_RRD(3),
        .T_FAW(8),
        .T_CCD(T_CCD),
        .T_WTR(T_WTR),
        .T_RTP(T_RTP),
        .T_WR(T_WR),
        .T_RFC(4),
        .T_ZQ(4),
        .T_REFI(64),
        .CHECK_REFRESH_DEADLINE(0)
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
    wire [3:0] cmd = {cs_n, ras_n, cas_n, we_n};
    wire cmd_act = selected && (cmd == `DDR3_CMD_ACT);
    wire cmd_pre = selected && (cmd == `DDR3_CMD_PRE);
    wire cmd_rd  = selected && (cmd == `DDR3_CMD_RD);
    wire cmd_wr  = selected && (cmd == `DDR3_CMD_WR);

    reg f_past_valid = 1'b0;
    reg outstanding = 1'b0;
    reg accepted_write = 1'b0;
    reg [14:0] accepted_row = 15'd0;
    reg [14:0] accepted_col = 15'd0;

    reg saw_read = 1'b0;
    reg saw_write = 1'b0;
    reg saw_precharge = 1'b0;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            outstanding <= 1'b0;
            accepted_write <= 1'b0;
            accepted_row <= 15'd0;
            accepted_col <= 15'd0;
            saw_read <= 1'b0;
            saw_write <= 1'b0;
            saw_precharge <= 1'b0;
        end else begin
            assert(req_ready == !busy);

            if (req_valid && req_ready) begin
                assert(!outstanding);
                outstanding <= 1'b1;
                accepted_write <= req_write;
                accepted_row <= req_row;
                accepted_col <= {req_col[14:11], 1'b0, req_col[9:0]};
            end

            if (rsp_valid) begin
                assert(outstanding);
                assert(rsp_write == accepted_write);
                outstanding <= 1'b0;
            end

            if (cmd_act) begin
                assert(ba == 3'd0);
                assert(addr == accepted_row);
            end

            if (cmd_rd || cmd_wr) begin
                assert(ba == 3'd0);
                assert(addr == accepted_col);
                assert(rsp_valid);
                assert(cmd_wr == rsp_write);
            end

            if (cmd_pre) begin
                assert(ba == 3'd0);
                assert(!addr[10]);
                saw_precharge <= 1'b1;
            end

            if (cmd_rd)
                saw_read <= 1'b1;
            if (cmd_wr)
                saw_write <= 1'b1;

            cover(saw_read && saw_write && saw_precharge);
            cover(state == 4'd0 && open && !outstanding);
        end
    end
`endif
endmodule

`default_nettype wire
