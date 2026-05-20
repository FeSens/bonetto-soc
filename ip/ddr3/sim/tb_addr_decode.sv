`default_nettype none
`timescale 1ns/1ps

module tb_addr_decode;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer LOCAL_WORD_ADDR_W = 29;
    localparam integer LINE_ADDR_W = 25;

    reg [GLOBAL_WORD_ADDR_W-1:0] addr = {GLOBAL_WORD_ADDR_W{1'b0}};

    wire channel;
    wire [LOCAL_WORD_ADDR_W-1:0] local_word_addr;
    wire [LINE_ADDR_W-1:0] line_addr;
    wire [3:0] word_index;
    wire [2:0] bank;
    wire [14:0] row;
    wire [6:0] col_line;
    wire [9:0] col;

    ddr3_addr_decode dut (
        .i_word_addr(addr),
        .o_channel(channel),
        .o_local_word_addr(local_word_addr),
        .o_line_addr(line_addr),
        .o_word_index(word_index),
        .o_bank(bank),
        .o_row(row),
        .o_col_line(col_line),
        .o_col(col)
    );

    task check;
        input [GLOBAL_WORD_ADDR_W-1:0] in_addr;
        input exp_channel;
        input [2:0] exp_bank;
        input [14:0] exp_row;
        input [6:0] exp_col_line;
        input [3:0] exp_word_index;
        begin
            addr = in_addr;
            #1;

            if (channel !== exp_channel ||
                bank !== exp_bank ||
                row !== exp_row ||
                col_line !== exp_col_line ||
                word_index !== exp_word_index ||
                col !== {exp_col_line, 3'b000} ||
                line_addr !== {exp_bank, exp_row, exp_col_line} ||
                local_word_addr !== in_addr[28:0]) begin
                $display("[addr-decode] mismatch addr=%h ch=%0b bank=%0d row=%0h col_line=%0h word=%0h line=%h col=%h local=%h",
                         in_addr, channel, bank, row, col_line, word_index,
                         line_addr, col, local_word_addr);
                $fatal(1);
            end
        end
    endtask

    initial begin
        check(30'h0000_0000, 1'b0, 3'd0, 15'h0000, 7'h00, 4'h0);
        check(30'h0000_000f, 1'b0, 3'd0, 15'h0000, 7'h00, 4'hf);
        check(30'h0000_0010, 1'b0, 3'd0, 15'h0000, 7'h01, 4'h0);
        check({1'b1, 3'd5, 15'h1234, 7'h56, 4'ha},
              1'b1, 3'd5, 15'h1234, 7'h56, 4'ha);
        check(30'h3fff_ffff, 1'b1, 3'd7, 15'h7fff, 7'h7f, 4'hf);

        $display("[addr-decode] full-capacity dual-channel address map passed");
        $finish;
    end
endmodule

`default_nettype wire
