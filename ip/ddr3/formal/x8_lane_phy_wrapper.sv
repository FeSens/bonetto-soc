// Formal harness for the DDR3 x8 lane PHY timing core.

`default_nettype none

module ddr3_x8_lane_phy_wrapper (
    input wire       clk,
    input wire       rst
);
    localparam integer WRITE_LATENCY = 2;
    localparam integer READ_LATENCY = 2;

    (* anyseq *) wire       lane_wr_valid;
    (* anyseq *) wire [7:0] lane_wr_data;
    (* anyseq *) wire       lane_wr_mask;
    (* anyseq *) wire       lane_wr_last;
    (* anyseq *) wire       start_write;
    (* anyseq *) wire       start_read;
    (* anyseq *) wire       rd_sample_valid;
    (* anyseq *) wire [7:0] dq_rise;
    (* anyseq *) wire [7:0] dq_fall;
    (* anyseq *) wire       lane_rd_ready;

    wire       lane_wr_ready;
    wire       wr_loaded;
    wire       busy;
    wire       error;
    wire       dq_oe;
    wire       dm_oe;
    wire       dqs_oe;
    wire [7:0] dq_out_rise;
    wire [7:0] dq_out_fall;
    wire       dm_rise;
    wire       dm_fall;
    wire       dqs_rise;
    wire       dqs_fall;
    wire       rd_capturing;
    wire       lane_rd_valid;
    wire [7:0] lane_rd_data;

    ddr3_x8_lane_phy #(
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_lane_wr_valid(lane_wr_valid),
        .o_lane_wr_ready(lane_wr_ready),
        .i_lane_wr_data(lane_wr_data),
        .i_lane_wr_mask(lane_wr_mask),
        .i_lane_wr_last(lane_wr_last),
        .o_wr_loaded(wr_loaded),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .o_busy(busy),
        .o_error(error),
        .o_dq_oe(dq_oe),
        .o_dm_oe(dm_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_out_rise),
        .o_dq_fall(dq_out_fall),
        .o_dm_rise(dm_rise),
        .o_dm_fall(dm_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_rise),
        .i_dq_fall(dq_fall),
        .o_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_ready(lane_rd_ready),
        .o_lane_rd_data(lane_rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;

    reg [3:0]  f_wr_count = 4'd0;
    reg [63:0] f_wr_data = 64'd0;
    reg [7:0]  f_wr_mask = 8'hff;
    reg        f_write_launch = 1'b0;
    reg [2:0]  f_write_pair = 3'd0;

    reg [63:0] f_rd_data = 64'd0;
    reg [2:0]  f_rd_capture_count = 3'd0;
    reg [2:0]  f_rd_emit_count = 3'd0;

    wire wr_accept = lane_wr_valid && lane_wr_ready;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wr_count <= 4'd0;
            f_wr_data <= 64'd0;
            f_wr_mask <= 8'hff;
            f_write_launch <= 1'b0;
            f_write_pair <= 3'd0;
            f_rd_data <= 64'd0;
            f_rd_capture_count <= 3'd0;
            f_rd_emit_count <= 3'd0;
        end else begin
            assume(!(start_write && start_read));
            if (start_write)
                assume(wr_loaded && !busy);
            if (start_read)
                assume(!busy);
            if (rd_capturing)
                assume(rd_sample_valid);

            if (lane_wr_valid && !lane_wr_ready) begin
                assume(lane_wr_data == $past(lane_wr_data));
                assume(lane_wr_mask == $past(lane_wr_mask));
                assume(lane_wr_last == $past(lane_wr_last));
            end

            if (wr_accept) begin
                assume(lane_wr_last == (f_wr_count == 4'd7));
                f_wr_data[f_wr_count[2:0]*8 +: 8] <= lane_wr_data;
                f_wr_mask[f_wr_count[2:0]] <= lane_wr_mask;
                if (f_wr_count != 4'd8)
                    f_wr_count <= f_wr_count + 4'd1;
            end

            if (!wr_loaded && (f_wr_count == 4'd8) && !f_write_launch)
                f_wr_count <= 4'd0;

            assert(!dq_oe || (dm_oe && dqs_oe));
            assert(!dm_oe || dq_oe);
            assert(!dq_oe || (dqs_rise && !dqs_fall));
            assert(!lane_wr_ready || !wr_loaded);

            if (wr_loaded)
                assert(f_wr_count == 4'd8);

            if (start_write) begin
                f_write_launch <= 1'b1;
                f_write_pair <= 3'd0;
            end

            if (dq_oe) begin
                assert(f_write_launch);
                assert(f_write_pair < 3'd4);
                assert(dq_out_rise == f_wr_data[(f_write_pair*16) +: 8]);
                assert(dq_out_fall == f_wr_data[(f_write_pair*16) + 8 +: 8]);
                assert(dm_rise == f_wr_mask[f_write_pair*2]);
                assert(dm_fall == f_wr_mask[(f_write_pair*2) + 1]);

                if (f_write_pair == 3'd3) begin
                    f_write_pair <= 3'd0;
                    f_write_launch <= 1'b0;
                end else begin
                    f_write_pair <= f_write_pair + 3'd1;
                end
            end

            if (start_read) begin
                f_rd_capture_count <= 3'd0;
                f_rd_emit_count <= 3'd0;
                f_rd_data <= 64'd0;
            end

            if (rd_capturing && rd_sample_valid) begin
                assert(f_rd_capture_count < 3'd4);
                f_rd_data[f_rd_capture_count*16 +: 8] <= dq_rise;
                f_rd_data[(f_rd_capture_count*16) + 8 +: 8] <= dq_fall;
                f_rd_capture_count <= f_rd_capture_count + 3'd1;
            end

            if (f_past_valid && $past(lane_rd_valid && !lane_rd_ready)) begin
                assert(lane_rd_valid);
                assert(lane_rd_data == $past(lane_rd_data));
            end

            if (lane_rd_valid) begin
                assert(f_rd_capture_count == 3'd4);
                assert(lane_rd_data == f_rd_data[f_rd_emit_count*8 +: 8]);
                if (lane_rd_ready) begin
                    if (f_rd_emit_count == 3'd7)
                        f_rd_emit_count <= 3'd0;
                    else
                        f_rd_emit_count <= f_rd_emit_count + 3'd1;
                end
            end

            cover(wr_accept && lane_wr_last);
            cover(dq_oe && (f_write_pair == 3'd3));
            cover(lane_rd_valid && lane_rd_ready && (f_rd_emit_count == 3'd7));
        end
    end
`endif
endmodule

`default_nettype wire
