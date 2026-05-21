// Latch the deserialized DQ frame that contains a DQS transition.
//
// A host-triggered raw capture can easily miss a BL8 read burst if it samples
// a later clkdiv cycle. This helper keeps the most recent 8-sample frame that
// showed DQS activity, so debug logic can read the frame that actually crossed
// the byte-lane strobe.

`default_nettype none

module ddr3_serdes_edge_window (
    input  wire        i_clk,
    input  wire        i_rst,
    input  wire [63:0] i_dq_bits,
    input  wire [7:0]  i_dqs_bits,
    input  wire [3:0]  i_history_age,

    output reg         o_valid,
    output reg  [63:0] o_dq_bits,
    output reg  [7:0]  o_dqs_bits,
    output reg  [7:0]  o_rise_dq,
    output reg  [7:0]  o_fall_dq,
    output reg  [7:0]  o_rise_count,
    output reg  [7:0]  o_fall_count,
    output reg  [7:0]  o_event_count
);
    reg dqs_prev = 1'b0;
    reg [63:0] dq_history [0:2];
    reg [7:0] dqs_history [0:2];

    integer sample_i;
    integer hist_i;
    reg dqs_walk;
    reg edge_seen;
    reg [3:0] rise_inc;
    reg [3:0] fall_inc;
    reg [7:0] rise_dq_next;
    reg [7:0] fall_dq_next;

    function [63:0] select_dq_history;
        input [3:0] age;
        begin
            case (age)
                4'd0:    select_dq_history = i_dq_bits;
                4'd1:    select_dq_history = dq_history[0];
                4'd2:    select_dq_history = dq_history[1];
                default: select_dq_history = dq_history[2];
            endcase
        end
    endfunction

    function [7:0] select_dqs_history;
        input [3:0] age;
        begin
            case (age)
                4'd0:    select_dqs_history = i_dqs_bits;
                4'd1:    select_dqs_history = dqs_history[0];
                4'd2:    select_dqs_history = dqs_history[1];
                default: select_dqs_history = dqs_history[2];
            endcase
        end
    endfunction

    always @(posedge i_clk) begin
        if (i_rst) begin
            dqs_prev <= 1'b0;
            o_valid <= 1'b0;
            o_dq_bits <= 64'd0;
            o_dqs_bits <= 8'd0;
            o_rise_dq <= 8'd0;
            o_fall_dq <= 8'd0;
            o_rise_count <= 8'd0;
            o_fall_count <= 8'd0;
            o_event_count <= 8'd0;
            for (hist_i = 0; hist_i < 3; hist_i = hist_i + 1) begin
                dq_history[hist_i] <= 64'd0;
                dqs_history[hist_i] <= 8'd0;
            end
        end else begin
            for (hist_i = 2; hist_i > 0; hist_i = hist_i - 1) begin
                dq_history[hist_i] <= dq_history[hist_i - 1];
                dqs_history[hist_i] <= dqs_history[hist_i - 1];
            end
            dq_history[0] <= i_dq_bits;
            dqs_history[0] <= i_dqs_bits;

            dqs_walk = dqs_prev;
            edge_seen = 1'b0;
            rise_inc = 4'd0;
            fall_inc = 4'd0;
            rise_dq_next = o_rise_dq;
            fall_dq_next = o_fall_dq;

            for (sample_i = 0; sample_i < 8; sample_i = sample_i + 1) begin
                if (!dqs_walk && i_dqs_bits[sample_i]) begin
                    edge_seen = 1'b1;
                    rise_inc = rise_inc + 4'd1;
                    rise_dq_next = i_dq_bits[sample_i*8 +: 8];
                end
                if (dqs_walk && !i_dqs_bits[sample_i]) begin
                    edge_seen = 1'b1;
                    fall_inc = fall_inc + 4'd1;
                    fall_dq_next = i_dq_bits[sample_i*8 +: 8];
                end
                dqs_walk = i_dqs_bits[sample_i];
            end

            dqs_prev <= dqs_walk;
            o_rise_dq <= rise_dq_next;
            o_fall_dq <= fall_dq_next;
            o_rise_count <= o_rise_count + {4'd0, rise_inc};
            o_fall_count <= o_fall_count + {4'd0, fall_inc};

            if (edge_seen) begin
                o_valid <= 1'b1;
                o_dq_bits <= select_dq_history(i_history_age);
                o_dqs_bits <= select_dqs_history(i_history_age);
                o_event_count <= o_event_count + 8'd1;
            end
        end
    end
endmodule

`default_nettype wire
