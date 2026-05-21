`default_nettype none
`timescale 1ps/1ps

module tb_dqs_burst_capture;
    reg clk = 1'b0;
    reg rst = 1'b1;
    reg enable = 1'b0;
    reg runtime_swap = 1'b0;
    reg [2:0] skip_pairs = 3'd0;
    reg [7:0] dq_rise = 8'd0;
    reg [7:0] dq_fall = 8'd0;

    always #2500 clk = !clk;

    wire valid;
    wire toggle;
    wire [1:0] pair_index;
    wire [7:0] burst_count;
    wire [63:0] data;

    wire valid_swap;
    wire [63:0] data_swap;

    ddr3_dqs_burst_capture dut (
        .i_dqs_clk(clk),
        .i_rst(rst),
        .i_capture_enable(enable),
        .i_swap_edges(runtime_swap),
        .i_skip_pairs(skip_pairs),
        .i_dq_rise(dq_rise),
        .i_dq_fall(dq_fall),
        .o_valid(valid),
        .o_toggle(toggle),
        .o_pair_index(pair_index),
        .o_burst_count(burst_count),
        .o_data(data)
    );

    ddr3_dqs_burst_capture #(
        .SWAP_EDGES(1)
    ) dut_swap (
        .i_dqs_clk(clk),
        .i_rst(rst),
        .i_capture_enable(enable),
        .i_swap_edges(runtime_swap),
        .i_skip_pairs(skip_pairs),
        .i_dq_rise(dq_rise),
        .i_dq_fall(dq_fall),
        .o_valid(valid_swap),
        .o_toggle(),
        .o_pair_index(),
        .o_burst_count(),
        .o_data(data_swap)
    );

    function [63:0] lane_word;
        input [7:0] b0;
        input [7:0] b1;
        input [7:0] b2;
        input [7:0] b3;
        input [7:0] b4;
        input [7:0] b5;
        input [7:0] b6;
        input [7:0] b7;
        begin
            lane_word = {b7, b6, b5, b4, b3, b2, b1, b0};
        end
    endfunction

    task automatic drive_pair;
        input [7:0] rise_byte;
        input [7:0] fall_byte;
        begin
            dq_rise = rise_byte;
            dq_fall = fall_byte;
            @(posedge clk);
            #1;
        end
    endtask

    initial begin
        repeat (4) @(posedge clk);
        rst = 1'b0;

        drive_pair(8'h01, 8'h02);
        if (valid || pair_index !== 2'd0 || burst_count !== 8'd0) begin
            $display("[dqs-burst-capture] disabled capture changed state");
            $fatal(1);
        end

        @(negedge clk);
        enable = 1'b1;
        #1;
        drive_pair(8'ha0, 8'ha1);
        if (valid || pair_index !== 2'd1) begin
            $display("[dqs-burst-capture] pair 0 state mismatch valid=%0d pair=%0d count=%0d data=%016x",
                     valid, pair_index, burst_count, data);
            $fatal(1);
        end

        drive_pair(8'ha2, 8'ha3);
        if (valid || pair_index !== 2'd2) begin
            $display("[dqs-burst-capture] pair 1 state mismatch valid=%0d pair=%0d count=%0d data=%016x",
                     valid, pair_index, burst_count, data);
            $fatal(1);
        end

        drive_pair(8'ha4, 8'ha5);
        if (valid || pair_index !== 2'd3) begin
            $display("[dqs-burst-capture] pair 2 state mismatch valid=%0d pair=%0d count=%0d data=%016x",
                     valid, pair_index, burst_count, data);
            $fatal(1);
        end

        drive_pair(8'ha6, 8'ha7);
        if (!valid || !valid_swap || !toggle || pair_index !== 2'd3 ||
            burst_count !== 8'd1 ||
            data !== lane_word(8'ha0, 8'ha1, 8'ha2, 8'ha3,
                               8'ha4, 8'ha5, 8'ha6, 8'ha7) ||
            data_swap !== lane_word(8'ha1, 8'ha0, 8'ha3, 8'ha2,
                                    8'ha5, 8'ha4, 8'ha7, 8'ha6)) begin
            $display("[dqs-burst-capture] first burst mismatch valid=%0d toggle=%0d pair=%0d count=%0d data=%016x swap=%016x",
                     valid, toggle, pair_index, burst_count, data, data_swap);
            $fatal(1);
        end

        drive_pair(8'hb0, 8'hb1);
        drive_pair(8'hb2, 8'hb3);
        if (!valid || burst_count !== 8'd1 ||
            data !== lane_word(8'ha0, 8'ha1, 8'ha2, 8'ha3,
                               8'ha4, 8'ha5, 8'ha6, 8'ha7)) begin
            $display("[dqs-burst-capture] frozen burst changed count=%0d data=%016x",
                     burst_count, data);
            $fatal(1);
        end

        @(negedge clk);
        enable = 1'b0;
        runtime_swap = 1'b1;
        #1;
        if (data !== 64'd0 || data_swap !== 64'd0) begin
            $display("[dqs-burst-capture] disable did not clear stale data data=%016x swap=%016x",
                     data, data_swap);
            $fatal(1);
        end
        drive_pair(8'hc0, 8'hc1);
        if (valid || pair_index !== 2'd0 || burst_count !== 8'd1) begin
            $display("[dqs-burst-capture] disable did not re-arm state");
            $fatal(1);
        end

        @(negedge clk);
        #1;
        enable = 1'b1;
        drive_pair(8'hb0, 8'hb1);
        drive_pair(8'hb2, 8'hb3);
        drive_pair(8'hb4, 8'hb5);
        drive_pair(8'hb6, 8'hb7);
        if (!valid || toggle || burst_count !== 8'd2 ||
            data !== lane_word(8'hb1, 8'hb0, 8'hb3, 8'hb2,
                               8'hb5, 8'hb4, 8'hb7, 8'hb6)) begin
            $display("[dqs-burst-capture] second armed burst mismatch toggle=%0d count=%0d data=%016x",
                     toggle, burst_count, data);
            $fatal(1);
        end

        @(negedge clk);
        enable = 1'b0;
        runtime_swap = 1'b0;
        #1;
        if (data !== 64'd0) begin
            $display("[dqs-burst-capture] final disable did not clear stale data data=%016x",
                     data);
            $fatal(1);
        end
        drive_pair(8'hd0, 8'hd1);
        if (valid || pair_index !== 2'd0) begin
            $display("[dqs-burst-capture] disable did not return to pair zero");
            $fatal(1);
        end

        @(negedge clk);
        #1;
        skip_pairs = 3'd1;
        enable = 1'b1;
        drive_pair(8'hcc, 8'hcc);
        drive_pair(8'hd0, 8'hd1);
        drive_pair(8'hd2, 8'hd3);
        drive_pair(8'hd4, 8'hd5);
        drive_pair(8'hd6, 8'hd7);
        drive_pair(8'he0, 8'he1);
        if (!valid || burst_count !== 8'd3 ||
            data !== lane_word(8'hd0, 8'hd1, 8'hd2, 8'hd3,
                               8'hd4, 8'hd5, 8'hd6, 8'hd7)) begin
            $display("[dqs-burst-capture] skip burst mismatch count=%0d data=%016x",
                     burst_count, data);
            $fatal(1);
        end

        $display("[dqs-burst-capture] BL8 DQS capture passed");
        $finish;
    end

    initial begin
        repeat (80) @(posedge clk);
        $display("[dqs-burst-capture] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire
