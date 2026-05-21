`default_nettype none
`timescale 1ps/1ps

module tb_serdes_edge_window;
    reg clk = 1'b0;
    reg rst = 1'b1;
    always #5000 clk = !clk;

    reg [63:0] dq_bits = 64'd0;
    reg [7:0] dqs_bits = 8'd0;
    reg [3:0] history_age = 4'd0;

    wire valid;
    wire [63:0] dq_window;
    wire [7:0] dqs_window;
    wire [7:0] rise_dq;
    wire [7:0] fall_dq;
    wire [7:0] rise_count;
    wire [7:0] fall_count;
    wire [7:0] event_count;

    ddr3_serdes_edge_window dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_dq_bits(dq_bits),
        .i_dqs_bits(dqs_bits),
        .i_history_age(history_age),
        .o_valid(valid),
        .o_dq_bits(dq_window),
        .o_dqs_bits(dqs_window),
        .o_rise_dq(rise_dq),
        .o_fall_dq(fall_dq),
        .o_rise_count(rise_count),
        .o_fall_count(fall_count),
        .o_event_count(event_count)
    );

    function [63:0] samples_to_lane_word;
        input [7:0] b0;
        input [7:0] b1;
        input [7:0] b2;
        input [7:0] b3;
        input [7:0] b4;
        input [7:0] b5;
        input [7:0] b6;
        input [7:0] b7;
        reg [63:0] out;
        reg [7:0] sample_byte;
        integer sample;
        integer bit_i;
        begin
            out = 64'd0;
            for (sample = 0; sample < 8; sample = sample + 1) begin
                case (sample)
                    0: sample_byte = b0;
                    1: sample_byte = b1;
                    2: sample_byte = b2;
                    3: sample_byte = b3;
                    4: sample_byte = b4;
                    5: sample_byte = b5;
                    6: sample_byte = b6;
                    default: sample_byte = b7;
                endcase
                for (bit_i = 0; bit_i < 8; bit_i = bit_i + 1)
                    out[sample*8 + bit_i] = sample_byte[bit_i];
            end
            samples_to_lane_word = out;
        end
    endfunction

    initial begin
        repeat (4) @(posedge clk);
        rst = 1'b0;

        @(negedge clk);
        dq_bits = samples_to_lane_word(
            8'h10, 8'h11, 8'h12, 8'h13,
            8'h14, 8'h15, 8'h16, 8'h17);
        dqs_bits = 8'h00;
        @(posedge clk);
        #1;
        if (valid || event_count !== 8'd0) begin
            $display("[serdes-edge-window] unexpected event at idle");
            $fatal(1);
        end

        @(negedge clk);
        history_age = 4'd0;
        dq_bits = samples_to_lane_word(
            8'ha0, 8'ha1, 8'ha2, 8'ha3,
            8'ha4, 8'ha5, 8'ha6, 8'ha7);
        dqs_bits = 8'haa;
        @(posedge clk);
        #1;
        if (!valid || event_count !== 8'd1 || dq_window !== dq_bits ||
            dqs_window !== 8'haa || rise_count !== 8'd4 ||
            fall_count !== 8'd3 || rise_dq !== 8'ha7 ||
            fall_dq !== 8'ha6) begin
            $display("[serdes-edge-window] first event mismatch valid=%0d events=%0d dqs=%02x rise=%02x fall=%02x rc=%0d fc=%0d",
                     valid, event_count, dqs_window, rise_dq, fall_dq,
                     rise_count, fall_count);
            $fatal(1);
        end

        @(negedge clk);
        dq_bits = samples_to_lane_word(
            8'hb0, 8'hb1, 8'hb2, 8'hb3,
            8'hb4, 8'hb5, 8'hb6, 8'hb7);
        dqs_bits = 8'hff;
        @(posedge clk);
        #1;
        if (event_count !== 8'd1 || dq_window === dq_bits) begin
            $display("[serdes-edge-window] stable-high frame was latched");
            $fatal(1);
        end

        @(negedge clk);
        history_age = 4'd1;
        dq_bits = samples_to_lane_word(
            8'hc0, 8'hc1, 8'hc2, 8'hc3,
            8'hc4, 8'hc5, 8'hc6, 8'hc7);
        dqs_bits = 8'h00;
        @(posedge clk);
        #1;
        if (event_count !== 8'd2 ||
            dq_window !== samples_to_lane_word(
                8'hb0, 8'hb1, 8'hb2, 8'hb3,
                8'hb4, 8'hb5, 8'hb6, 8'hb7) ||
            dqs_window !== 8'hff || rise_count !== 8'd4 ||
            fall_count !== 8'd4 || fall_dq !== 8'hc0) begin
            $display("[serdes-edge-window] second event mismatch events=%0d dqs=%02x rise=%02x fall=%02x rc=%0d fc=%0d",
                     event_count, dqs_window, rise_dq, fall_dq,
                     rise_count, fall_count);
            $fatal(1);
        end

        $display("[serdes-edge-window] DQS edge-window latch passed");
        $finish;
    end

    initial begin
        repeat (80) @(posedge clk);
        $display("[serdes-edge-window] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire
