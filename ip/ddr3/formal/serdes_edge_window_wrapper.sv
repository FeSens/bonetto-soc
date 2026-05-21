// Formal harness for the DQS edge-window latch.

`default_nettype none

module ddr3_serdes_edge_window_wrapper (
    input wire clk,
    input wire rst
);
    reg [3:0] f_cycle = 4'd0;
    reg f_past_valid = 1'b0;
    reg [63:0] dq_bits = 64'd0;
    reg [7:0] dqs_bits = 8'd0;
    reg [3:0] history_age = 4'd0;

    wire valid;
    wire [63:0] dq_window;
    wire [7:0] dqs_window;
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
        .o_rise_dq(),
        .o_fall_dq(),
        .o_rise_count(rise_count),
        .o_fall_count(fall_count),
        .o_event_count(event_count)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 4'd0;
            dq_bits <= 64'd0;
            dqs_bits <= 8'd0;
            history_age <= 4'd0;
        end else begin
            if (f_cycle != 4'd15)
                f_cycle <= f_cycle + 4'd1;

            case (f_cycle)
                4'd0: begin
                    dq_bits <= 64'h0000_0000_0000_0000;
                    dqs_bits <= 8'h00;
                end
                4'd1: begin
                    dq_bits <= 64'h0123_4567_89ab_cdef;
                    dqs_bits <= 8'haa;
                    history_age <= 4'd0;
                end
                4'd2: begin
                    dq_bits <= 64'hfedc_ba98_7654_3210;
                    dqs_bits <= 8'hff;
                end
                4'd3: begin
                    dq_bits <= 64'h1122_3344_5566_7788;
                    dqs_bits <= 8'h00;
                end
                default: begin
                    dq_bits <= dq_bits;
                    dqs_bits <= dqs_bits;
                end
            endcase

            if (f_cycle == 4'd1) begin
                assert(!valid);
                assert(event_count == 8'd0);
            end

            if (f_cycle == 4'd2) begin
                assert(valid);
                assert(event_count == 8'd1);
                assert(dq_window == 64'h0123_4567_89ab_cdef);
                assert(dqs_window == 8'haa);
                assert(rise_count == 8'd4);
                assert(fall_count == 8'd3);
            end

            if (f_cycle == 4'd3) begin
                assert(event_count == 8'd1);
                assert(dq_window == 64'h0123_4567_89ab_cdef);
            end

            if (f_cycle == 4'd4) begin
                assert(valid);
                assert(event_count == 8'd2);
                assert(dq_window == 64'h1122_3344_5566_7788);
                assert(dqs_window == 8'h00);
                assert(rise_count == 8'd4);
                assert(fall_count == 8'd4);
            end

            cover(valid && event_count == 8'd2);
        end
    end
`endif
endmodule

`default_nettype wire
