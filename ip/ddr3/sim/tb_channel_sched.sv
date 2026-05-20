`default_nettype none
`timescale 1ns/1ps

module tb_channel_sched;
    localparam integer ADDR_BITS = 15;
    localparam integer BANK_BITS = 1;
    localparam integer ROW_BITS = 15;
    localparam integer COL_BITS = 10;
    localparam integer COL_LINE_BITS = COL_BITS - 3;
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS;

    localparam [3:0] CMD_ACT = 4'b0011;
    localparam [3:0] CMD_WR  = 4'b0100;
    localparam [3:0] CMD_RD  = 4'b0101;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg                     cmd_valid = 1'b0;
    wire                    cmd_ready;
    reg                     cmd_write = 1'b0;
    reg [LINE_ADDR_W-1:0]   cmd_line_addr = {LINE_ADDR_W{1'b0}};
    wire                    xfer_start;
    wire                    xfer_write;
    wire                    req_pending;
    wire [1:0]              bank_busy;
    wire [1:0]              bank_open;
    wire                    ddr_cmd_valid;
    wire                    cs_n;
    wire                    ras_n;
    wire                    cas_n;
    wire                    we_n;
    wire [BANK_BITS-1:0]    ba;
    wire [ADDR_BITS-1:0]    addr;

    always #5 clk = ~clk;

    ddr3_channel_sched #(
        .BANK_BITS(BANK_BITS),
        .T_RCD(3),
        .T_RP(3),
        .T_RAS(5),
        .T_RC(8),
        .T_RTP(3),
        .T_WR(6),
        .T_CCD(4),
        .T_WTR(6),
        .T_RRD(3),
        .T_FAW(8),
        .T_RFC(4),
        .T_REFI(128),
        .T_MARGIN(32)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_valid(cmd_valid),
        .o_cmd_ready(cmd_ready),
        .i_cmd_write(cmd_write),
        .i_cmd_line_addr(cmd_line_addr),
        .o_xfer_start(xfer_start),
        .o_xfer_write(xfer_write),
        .i_refresh_enable(1'b0),
        .o_refresh_req(),
        .o_refresh_ack(),
        .o_refresh_busy(),
        .o_refresh_late(),
        .o_refresh_count(),
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

    function [LINE_ADDR_W-1:0] make_line;
        input [BANK_BITS-1:0] bank;
        input [ROW_BITS-1:0] row;
        input [COL_LINE_BITS-1:0] col_line;
        begin
            make_line = {bank, row, col_line};
        end
    endfunction

    function [ADDR_BITS-1:0] make_col_addr;
        input [COL_LINE_BITS-1:0] col_line;
        begin
            make_col_addr = {{(ADDR_BITS-COL_BITS){1'b0}}, col_line, 3'b000};
        end
    endfunction

    task issue_line;
        input write;
        input [BANK_BITS-1:0] bank;
        input [ROW_BITS-1:0] row;
        input [COL_LINE_BITS-1:0] col_line;
        input [3:0] expected_cmd;
        begin
            @(negedge clk);
            cmd_valid = 1'b1;
            cmd_write = write;
            cmd_line_addr = make_line(bank, row, col_line);

            wait (cmd_ready);
            @(negedge clk);
            cmd_valid = 1'b0;

            wait (xfer_start);
            #1;
            if (!ddr_cmd_valid ||
                xfer_write !== write ||
                {cs_n, ras_n, cas_n, we_n} !== expected_cmd ||
                ba !== bank ||
                addr !== make_col_addr(col_line)) begin
                $display("[channel-sched] transfer mismatch write=%0b cmd=%b bank=%0d addr=%h expected_write=%0b expected_cmd=%b expected_bank=%0d expected_addr=%h",
                         xfer_write, {cs_n, ras_n, cas_n, we_n}, ba, addr,
                         write,
                         expected_cmd, bank, make_col_addr(col_line));
                $fatal(1);
            end

            @(negedge clk);
        end
    endtask

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        issue_line(1'b1, 1'b0, 15'h0003, 7'h05, CMD_WR);
        if (!bank_open[0]) begin
            $display("[channel-sched] bank 0 should remain open after write");
            $fatal(1);
        end

        issue_line(1'b0, 1'b0, 15'h0003, 7'h06, CMD_RD);
        issue_line(1'b1, 1'b1, 15'h0004, 7'h02, CMD_WR);

        $display("[channel-sched] BL8 line requests issue through scheduler");
        $finish;
    end

    initial begin
        repeat (600) @(posedge clk);
        $display("[channel-sched] timeout valid=%0b ready=%0b xfer=%0b pending=%0b busy=%b open=%b",
                 cmd_valid, cmd_ready, xfer_start, req_pending,
                 bank_busy, bank_open);
        $fatal(1);
    end
endmodule

`default_nettype wire
