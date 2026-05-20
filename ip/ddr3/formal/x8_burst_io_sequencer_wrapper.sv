// Formal harness for the DDR3 x8 fast-domain burst I/O sequencer.

`default_nettype none

module ddr3_x8_burst_io_sequencer_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer WRITE_LATENCY = 2;
    localparam integer READ_LATENCY = 2;

    (* anyseq *) wire        wr_valid;
    (* anyseq *) wire [63:0] wr_data;
    (* anyseq *) wire        start_write;
    (* anyseq *) wire        start_read;
    (* anyseq *) wire        rd_sample_valid;
    (* anyseq *) wire [7:0]  dq_in_rise;
    (* anyseq *) wire [7:0]  dq_in_fall;
    (* anyseq *) wire        rd_ready;

    wire        wr_ready;
    wire        wr_loaded;
    wire        busy;
    wire        error;
    wire        dq_oe;
    wire        dqs_oe;
    wire [7:0]  dq_out_rise;
    wire [7:0]  dq_out_fall;
    wire        dqs_rise;
    wire        dqs_fall;
    wire        rd_capturing;
    wire        rd_valid;
    wire [63:0] rd_data;

    ddr3_x8_burst_io_sequencer #(
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
        .o_dq_oe(dq_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_out_rise),
        .o_dq_fall(dq_out_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_in_rise),
        .i_dq_fall(dq_in_fall),
        .o_rd_valid(rd_valid),
        .i_rd_ready(rd_ready),
        .o_rd_data(rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;

    reg [63:0] f_wr_data = 64'd0;
    reg        f_wr_loaded_seen = 1'b0;
    reg        f_write_launch = 1'b0;
    reg [2:0]  f_write_pair = 3'd0;

    reg [63:0] f_rd_data = 64'd0;
    reg [2:0]  f_rd_capture_count = 3'd0;

    wire wr_accept = wr_valid && wr_ready;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wr_data <= 64'd0;
            f_wr_loaded_seen <= 1'b0;
            f_write_launch <= 1'b0;
            f_write_pair <= 3'd0;
            f_rd_data <= 64'd0;
            f_rd_capture_count <= 3'd0;
        end else begin
            assume(!(start_write && start_read));
            if (start_write)
                assume(wr_loaded && !busy);
            if (start_read)
                assume(!busy && !rd_valid);
            if (rd_capturing)
                assume(rd_sample_valid);

            if (wr_valid && !wr_ready)
                assume(wr_data == $past(wr_data));

            if (wr_accept) begin
                f_wr_data <= wr_data;
                f_wr_loaded_seen <= 1'b1;
            end

            if (wr_loaded)
                assert(f_wr_loaded_seen);

            assert(!dq_oe || dqs_oe);
            assert(!dq_oe || (dqs_rise && !dqs_fall));
            assert(!dqs_oe || dq_oe || (!dqs_rise && !dqs_fall));
            assert(!wr_ready || (!wr_loaded && !busy));

            if (f_past_valid && $past(rd_valid && !rd_ready)) begin
                assert(rd_valid);
                assert(rd_data == $past(rd_data));
            end

            if (start_write) begin
                f_write_launch <= 1'b1;
                f_write_pair <= 3'd0;
            end

            if (dq_oe) begin
                assert(f_write_launch);
                assert(f_write_pair < 3'd4);
                assert(dq_out_rise == f_wr_data[(f_write_pair * 16) +: 8]);
                assert(dq_out_fall == f_wr_data[(f_write_pair * 16) + 8 +: 8]);

                if (f_write_pair == 3'd3) begin
                    f_write_pair <= 3'd0;
                    f_write_launch <= 1'b0;
                    f_wr_loaded_seen <= 1'b0;
                end else begin
                    f_write_pair <= f_write_pair + 3'd1;
                end
            end

            if (start_read) begin
                f_rd_capture_count <= 3'd0;
                f_rd_data <= 64'd0;
            end

            if (rd_capturing && rd_sample_valid) begin
                assert(f_rd_capture_count < 3'd4);
                f_rd_data[(f_rd_capture_count * 16) +: 8] <= dq_in_rise;
                f_rd_data[(f_rd_capture_count * 16) + 8 +: 8] <= dq_in_fall;
                f_rd_capture_count <= f_rd_capture_count + 3'd1;
            end

            if (rd_valid) begin
                assert(f_rd_capture_count == 3'd4);
                assert(rd_data == f_rd_data);
            end

            cover(wr_accept);
            cover(dq_oe && (f_write_pair == 3'd3));
            cover(rd_valid && rd_ready);
        end
    end
`endif
endmodule

`default_nettype wire
