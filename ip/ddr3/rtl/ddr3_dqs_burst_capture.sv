// DQS-domain x8 BL8 read burst capture.
//
// This debug block is fed by DQS-clocked DDR input flops. When the host arms a
// read, it skips a programmable number of DQS pairs, captures the next four
// rise/fall pairs, then freezes the 64-bit BL8 word until the host deasserts the
// capture enable. Freezing the word lets the slower JTAG/status clock sample a
// stable value after the burst has completed.

`default_nettype none

module ddr3_dqs_burst_capture #(
    parameter integer SWAP_EDGES = 0
) (
    input  wire        i_dqs_clk,
    input  wire        i_rst,
    input  wire        i_capture_enable,
    input  wire        i_swap_edges,
    input  wire [2:0]  i_skip_pairs,
    input  wire [7:0]  i_dq_rise,
    input  wire [7:0]  i_dq_fall,

    output reg         o_valid,
    output reg         o_toggle,
    output reg  [1:0]  o_pair_index,
    output reg  [7:0]  o_burst_count,
    output reg  [63:0] o_data
);
    wire swap_effective = i_swap_edges ^ (SWAP_EDGES != 0);
    wire [7:0] dq_even = swap_effective ? i_dq_fall : i_dq_rise;
    wire [7:0] dq_odd  = swap_effective ? i_dq_rise : i_dq_fall;
    wire [15:0] pair_now = {dq_odd, dq_even};

    reg started = 1'b0;
    reg [2:0] skip_left = 3'd0;

    task automatic capture_pair;
        input [15:0] pair;
        begin
            case (o_pair_index)
                2'd0: o_data[15:0] <= pair;
                2'd1: o_data[31:16] <= pair;
                2'd2: o_data[47:32] <= pair;
                default: o_data[63:48] <= pair;
            endcase

            if (o_pair_index == 2'd3) begin
                o_valid <= 1'b1;
                o_toggle <= !o_toggle;
                o_burst_count <= o_burst_count + 8'd1;
            end else begin
                o_pair_index <= o_pair_index + 2'd1;
            end
        end
    endtask

    initial begin
        started = 1'b0;
        skip_left = 3'd0;
        o_valid = 1'b0;
        o_toggle = 1'b0;
        o_pair_index = 2'd0;
        o_burst_count = 8'd0;
        o_data = 64'd0;
    end

    always @(posedge i_dqs_clk or posedge i_rst or
             negedge i_capture_enable) begin
        if (i_rst) begin
            started <= 1'b0;
            skip_left <= 3'd0;
            o_valid <= 1'b0;
            o_pair_index <= 2'd0;
            o_data <= 64'd0;
        end else if (!i_capture_enable) begin
            started <= 1'b0;
            skip_left <= 3'd0;
            o_valid <= 1'b0;
            o_pair_index <= 2'd0;
            o_data <= 64'd0;
        end else if (!o_valid) begin
            if (!started) begin
                started <= 1'b1;
                if (i_skip_pairs != 3'd0) begin
                    skip_left <= i_skip_pairs - 3'd1;
                end else begin
                    capture_pair(pair_now);
                end
            end else if (skip_left != 3'd0) begin
                skip_left <= skip_left - 3'd1;
            end else begin
                capture_pair(pair_now);
            end
        end
    end
endmodule

`default_nettype wire
