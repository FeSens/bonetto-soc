// Formal harness for the global DDR3 scheduler slice.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_scheduler_wrapper (
    input wire        clk,
    input wire        rst,
    input wire        req_valid,
    input wire        req_write,
    input wire [2:0]  req_bank,
    input wire [14:0] req_row,
    input wire [14:0] req_col,
    input wire        refresh_req
);
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

    wire       req_ready;
    wire       rsp_valid;
    wire       rsp_write;
    wire [2:0] rsp_bank;
    wire       refresh_ack;
    wire       refresh_busy;
    wire [7:0] bank_busy;
    wire [7:0] bank_open;
    wire       cmd_valid;
    wire       cs_n;
    wire       ras_n;
    wire       cas_n;
    wire       we_n;
    wire [2:0] ba;
    wire [14:0] addr;

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
        .T_FAW(T_FAW)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_req_valid(req_valid),
        .o_req_ready(req_ready),
        .i_req_write(req_write),
        .i_req_bank(req_bank),
        .i_req_row(req_row),
        .i_req_col({req_col[14:11], 1'b0, req_col[9:0]}),
        .i_refresh_req(refresh_req),
        .o_refresh_ack(refresh_ack),
        .o_refresh_busy(refresh_busy),
        .o_rsp_valid(rsp_valid),
        .o_rsp_write(rsp_write),
        .o_rsp_bank(rsp_bank),
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
    wire cmd_ref = selected && (cmd == `DDR3_CMD_REF);
    wire cmd_rd  = selected && (cmd == `DDR3_CMD_RD);
    wire cmd_wr  = selected && (cmd == `DDR3_CMD_WR);

    reg f_past_valid = 1'b0;
    reg [7:0] outstanding = 8'd0;
    reg [7:0] accepted_write = 8'd0;
    reg saw_read = 1'b0;
    reg saw_write = 1'b0;
    reg saw_refresh = 1'b0;
    reg saw_bank0_act = 1'b0;
    reg saw_other_bank_act = 1'b0;
    reg last_stalled = 1'b0;
    reg last_req_write = 1'b0;
    reg [2:0] last_req_bank = 3'd0;
    reg [14:0] last_req_row = 15'd0;
    reg [14:0] last_req_col = 15'd0;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            outstanding <= 8'd0;
            accepted_write <= 8'd0;
            saw_read <= 1'b0;
            saw_write <= 1'b0;
            saw_refresh <= 1'b0;
            saw_bank0_act <= 1'b0;
            saw_other_bank_act <= 1'b0;
            last_stalled <= 1'b0;
            last_req_write <= 1'b0;
            last_req_bank <= 3'd0;
            last_req_row <= 15'd0;
            last_req_col <= 15'd0;
        end else begin
            assume(req_bank <= 3'd1);
            if (refresh_req)
                assume(outstanding == 8'd0);
            if (req_valid)
                assume(!outstanding[req_bank]);

            if (last_stalled) begin
                assume(req_valid);
                assume(req_write == last_req_write);
                assume(req_bank == last_req_bank);
                assume(req_row == last_req_row);
                assume(req_col == last_req_col);
            end

            if (req_valid && req_ready) begin
                assert(!outstanding[req_bank]);
                outstanding[req_bank] <= 1'b1;
                accepted_write[req_bank] <= req_write;
            end

            if (rsp_valid) begin
                assert(outstanding[rsp_bank]);
                assert(rsp_write == accepted_write[rsp_bank]);
                outstanding[rsp_bank] <= 1'b0;
            end

            if (refresh_ack)
                assert(cmd_ref);
            if (cmd_ref) begin
                assert(refresh_ack);
                assert(bank_open == 8'd0);
                saw_refresh <= 1'b1;
            end

            if (cmd_act && ba == 3'd0)
                saw_bank0_act <= 1'b1;
            if (cmd_act && ba != 3'd0)
                saw_other_bank_act <= 1'b1;
            if (cmd_rd)
                saw_read <= 1'b1;
            if (cmd_wr)
                saw_write <= 1'b1;

            cover(saw_bank0_act && saw_other_bank_act);
            cover(saw_read && saw_write);
            cover(saw_refresh);
            cover(bank_open != 8'd0);

            last_stalled <= req_valid && !req_ready;
            last_req_write <= req_write;
            last_req_bank <= req_bank;
            last_req_row <= req_row;
            last_req_col <= req_col;
        end
    end
`endif
endmodule

`default_nettype wire
