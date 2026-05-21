// Formal harness for the DQS-domain x8 BL8 read burst capture.

`default_nettype none

module ddr3_dqs_burst_capture_wrapper (
    input wire clk,
    input wire rst
);
    reg f_past_valid = 1'b0;
    reg [3:0] f_cycle = 4'd0;

    wire enable =
        ((f_cycle >= 4'd1) && (f_cycle <= 4'd7)) ||
        ((f_cycle >= 4'd9) && (f_cycle <= 4'd15));

`ifdef FORMAL
    (* anyseq *) wire [7:0] dq_rise;
    (* anyseq *) wire [7:0] dq_fall;
`else
    wire [7:0] dq_rise = 8'd0;
    wire [7:0] dq_fall = 8'd0;
`endif
    wire [2:0] skip_pairs = (f_cycle >= 4'd9) ? 3'd1 : 3'd0;
    wire swap_edges = (f_cycle >= 4'd9);

    wire valid;
    wire toggle;
    wire [1:0] pair_index;
    wire [7:0] burst_count;
    wire [63:0] data;
    reg [7:0] burst_count_q = 8'd0;
    reg toggle_q = 1'b0;
    reg valid_q = 1'b0;
    reg [63:0] data_q = 64'd0;

    ddr3_dqs_burst_capture dut (
        .i_dqs_clk(clk),
        .i_rst(rst),
        .i_capture_enable(enable),
        .i_swap_edges(swap_edges),
        .i_skip_pairs(skip_pairs),
        .i_dq_rise(dq_rise),
        .i_dq_fall(dq_fall),
        .o_valid(valid),
        .o_toggle(toggle),
        .o_pair_index(pair_index),
        .o_burst_count(burst_count),
        .o_data(data)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(*) begin
        if (f_past_valid)
            assume(!rst);
    end

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (rst) begin
            f_cycle <= 4'd0;
        end else begin
            if (f_cycle != 4'd15)
                f_cycle <= f_cycle + 4'd1;

            burst_count_q <= burst_count;
            toggle_q <= toggle;
            valid_q <= valid;
            data_q <= data;

            assert(pair_index <= 2'd3);

            if (!enable) begin
                assert(pair_index == 2'd0);
                assert(!valid);
                assert(data == 64'd0);
            end

            if (valid && !valid_q) begin
                assert(enable);
                assert(pair_index == 2'd3);
                assert(burst_count == burst_count_q + 8'd1);
                assert(toggle != toggle_q);
            end else if (valid && valid_q) begin
                assert(enable);
                assert(pair_index == 2'd3);
                assert(burst_count == burst_count_q);
                assert(toggle == toggle_q);
                assert(data == data_q);
            end else if (f_past_valid && enable) begin
                assert(burst_count == burst_count_q);
                assert(toggle == toggle_q);
            end

            if (f_cycle == 4'd8) begin
                assert(!valid);
                assert(pair_index == 2'd0);
                assert(data == 64'd0);
            end

            cover(valid && (burst_count == 8'd2));
        end
    end
`endif
endmodule

`default_nettype wire
