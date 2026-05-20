// Formal harness for the DDR3 x8 SERDES-domain BL8 lane adapter.

`default_nettype none

module ddr3_x8_serdes_burst_lane_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WRITE_LATENCY = 2;
    localparam integer READ_LATENCY = 2;

    (* anyseq *) wire        wr_valid;
    (* anyseq *) wire [63:0] wr_data;
    (* anyseq *) wire        start_write;
    (* anyseq *) wire        start_read;
    (* anyseq *) wire [63:0] serdes_dq_in;
    (* anyseq *) wire        rd_ready;

    wire        wr_ready;
    wire        wr_loaded;
    wire        busy;
    wire        error;
    wire [63:0] serdes_dq_bits;
    wire [7:0]  serdes_dqs_bits;
    wire [3:0]  serdes_dq_oe;
    wire [3:0]  serdes_dqs_oe;
    wire        rd_valid;
    wire [63:0] rd_data;

    ddr3_x8_serdes_burst_lane #(
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_valid(wr_valid),
        .o_wr_ready(wr_ready),
        .i_wr_data(wr_data),
        .o_wr_loaded(wr_loaded),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .o_busy(busy),
        .o_error(error),
        .o_serdes_dq_bits(serdes_dq_bits),
        .o_serdes_dqs_bits(serdes_dqs_bits),
        .o_serdes_dq_oe(serdes_dq_oe),
        .o_serdes_dqs_oe(serdes_dqs_oe),
        .i_serdes_dq_bits(serdes_dq_in),
        .o_rd_valid(rd_valid),
        .i_rd_ready(rd_ready),
        .o_rd_data(rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg [63:0] f_wr_data = 64'd0;
    reg        f_wr_loaded_seen = 1'b0;

    wire wr_accept = wr_valid && wr_ready;
    wire write_data_cycle = |serdes_dq_oe;
    wire write_dqs_cycle = |serdes_dqs_oe;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wr_data <= 64'd0;
            f_wr_loaded_seen <= 1'b0;
        end else begin
            assume(!(start_write && start_read));
            if (start_write)
                assume(wr_loaded && !busy);
            if (start_read)
                assume(!busy && !rd_valid);
            if (wr_valid && !wr_ready)
                assume(wr_data == $past(wr_data));

            if (wr_accept) begin
                f_wr_data <= wr_data;
                f_wr_loaded_seen <= 1'b1;
            end

            if (wr_loaded)
                assert(f_wr_loaded_seen);

            if (start_write)
                f_wr_loaded_seen <= 1'b0;

            assert(!wr_ready || (!wr_loaded && !busy));
            assert(!write_data_cycle || (serdes_dq_oe == 4'hf));
            assert(!write_data_cycle || (serdes_dqs_oe == 4'hf));
            assert(!write_data_cycle || (serdes_dqs_bits == 8'b0101_0101));
            assert(!write_data_cycle || (serdes_dq_bits == f_wr_data));
            assert(!write_dqs_cycle || (serdes_dqs_oe == 4'hf));
            assert(!write_dqs_cycle || write_data_cycle ||
                   (serdes_dqs_bits == 8'h00));
            assert(write_dqs_cycle || (serdes_dqs_oe == 4'h0));
            assert(write_data_cycle || (serdes_dq_oe == 4'h0));

            if (f_past_valid && $past(rd_valid && !rd_ready)) begin
                assert(rd_valid);
                assert(rd_data == $past(rd_data));
            end

            if (f_past_valid && rd_valid && !$past(rd_valid))
                assert(rd_data == $past(serdes_dq_in));

            cover(wr_accept);
            cover(write_data_cycle);
            cover(rd_valid && rd_ready);
        end
    end
`endif
endmodule

`default_nettype wire
