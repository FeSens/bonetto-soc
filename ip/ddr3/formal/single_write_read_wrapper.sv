// Formal harness for the minimal single-bank WRITE then READ command slice.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_single_write_read_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer T_RCD     = 3;
    localparam integer T_WTR_CMD = 6;
    localparam integer T_RTP     = 3;
    localparam integer T_RP      = 3;
    localparam integer T_RFC     = 4;

    wire       busy;
    wire       done;
    wire [3:0] state;
    wire       cmd_valid;
    wire       cs_n;
    wire       ras_n;
    wire       cas_n;
    wire       we_n;
    wire [2:0] ba;
    wire [14:0] addr;

    ddr3_single_write_read_seq #(
        .T_RCD(T_RCD),
        .T_WTR_CMD(T_WTR_CMD),
        .T_RTP(T_RTP),
        .T_RP(T_RP),
        .T_RFC(T_RFC)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_start(1'b1),
        .o_busy(busy),
        .o_done(done),
        .o_state(state),
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
        .T_RAS(T_RCD + T_WTR_CMD + T_RTP + 1),
        .T_RC(T_RCD + T_WTR_CMD + T_RTP + T_RP + 2),
        .T_RRD(3),
        .T_FAW(8),
        .T_CCD(4),
        .T_WTR(T_WTR_CMD),
        .T_RTP(T_RTP),
        .T_WR(4),
        .T_RFC(T_RFC),
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
    wire issue = selected && (cmd != `DDR3_CMD_NOP);

    reg f_past_valid = 1'b0;
    reg [3:0] command_index = 4'd0;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (done) begin
            assert(!busy);
            assert(command_index == 4'd5);
        end

        if (rst) begin
            command_index <= 4'd0;
        end else if (issue) begin
            case (command_index)
                4'd0: begin
                    assert(cmd == `DDR3_CMD_ACT);
                    assert(ba == 3'd0);
                    assert(addr == 15'h0123);
                end
                4'd1: begin
                    assert(cmd == `DDR3_CMD_WR);
                    assert(ba == 3'd0);
                    assert(addr == 15'h0000);
                end
                4'd2: begin
                    assert(cmd == `DDR3_CMD_RD);
                    assert(ba == 3'd0);
                    assert(addr == 15'h0000);
                end
                4'd3: begin
                    assert(cmd == `DDR3_CMD_PRE);
                    assert(ba == 3'd0);
                    assert(!addr[10]);
                end
                4'd4: begin
                    assert(cmd == `DDR3_CMD_REF);
                end
                default: assert(1'b0);
            endcase
            command_index <= command_index + 4'd1;
        end

        cover(done);
    end
`endif
endmodule

`default_nettype wire
