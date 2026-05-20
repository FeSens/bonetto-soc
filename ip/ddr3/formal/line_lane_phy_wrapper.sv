// Focused formal harnesses for the DDR3 line-to-lane PHY timing bridge.

`default_nettype none

module ddr3_line_lane_phy_write_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 1;
    localparam integer LANES = 1;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WRITE_LATENCY = 1;
    localparam integer READ_LATENCY = 1;
    localparam [LINE_DATA_W-1:0] F_WR_DATA = 64'hf1e2_d3c4_b5a6_9788;
    localparam [LINE_BYTES-1:0]  F_WR_MASK = 8'b1001_0110;

    reg [5:0] f_cycle = 6'd0;
    reg       f_started = 1'b0;
    reg       f_done = 1'b0;
    reg [2:0] f_pair = 3'd0;
    reg       f_past_valid = 1'b0;

    wire [CHANNELS-1:0] wr_line_valid = (f_cycle == 6'd1);
    wire [CHANNELS-1:0] start_write = (f_cycle == 6'd12);
    wire [CHANNELS-1:0] start_read = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] rd_line_ready = {CHANNELS{1'b0}};

    wire [CHANNELS-1:0] wr_line_ready;
    wire [CHANNELS-1:0] rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data;
    wire [CHANNELS-1:0] rd_line_err;
    wire [CHANNELS-1:0] channel_busy;
    wire [CHANNELS-1:0] channel_error;
    wire [PHY_LANES-1:0] lane_busy;
    wire [PHY_LANES-1:0] lane_error;
    wire [PHY_LANES-1:0] dq_oe;
    wire [PHY_LANES-1:0] dm_oe;
    wire [PHY_LANES-1:0] dqs_oe;
    wire [(PHY_LANES*8)-1:0] dq_rise;
    wire [(PHY_LANES*8)-1:0] dq_fall;
    wire [PHY_LANES-1:0] dm_rise;
    wire [PHY_LANES-1:0] dm_fall;
    wire [PHY_LANES-1:0] dqs_rise;
    wire [PHY_LANES-1:0] dqs_fall;
    wire [PHY_LANES-1:0] rd_capturing;

    ddr3_line_lane_phy #(
        .CHANNELS(CHANNELS),
        .LANES(LANES),
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .i_wr_line_data(F_WR_DATA),
        .i_wr_line_mask(F_WR_MASK),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_channel_busy(channel_busy),
        .o_channel_error(channel_error),
        .o_lane_busy(lane_busy),
        .o_lane_error(lane_error),
        .o_dq_oe(dq_oe),
        .o_dm_oe(dm_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_rise),
        .o_dq_fall(dq_fall),
        .o_dm_rise(dm_rise),
        .o_dm_fall(dm_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid({PHY_LANES{1'b0}}),
        .i_dq_rise({(PHY_LANES*8){1'b0}}),
        .i_dq_fall({(PHY_LANES*8){1'b0}})
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 6'd0;
            f_started <= 1'b0;
            f_done <= 1'b0;
            f_pair <= 3'd0;
        end else begin
            if (f_cycle != 6'd63)
                f_cycle <= f_cycle + 6'd1;

            assert(channel_error == {CHANNELS{1'b0}});
            assert(rd_line_err == {CHANNELS{1'b0}});
            assert(lane_error == {PHY_LANES{1'b0}});
            assert(rd_line_valid == {CHANNELS{1'b0}});
            assert(rd_capturing == {PHY_LANES{1'b0}});

            if (start_write[0]) begin
                assert(channel_busy[0]);
                f_started <= 1'b1;
                f_pair <= 3'd0;
            end

            if (dq_oe[0]) begin
                assert(f_started);
                assert(dm_oe[0] && dqs_oe[0]);
                assert(dqs_rise[0] && !dqs_fall[0]);
                assert(f_pair < 3'd4);
                assert(dq_rise[7:0] == F_WR_DATA[(f_pair*16) +: 8]);
                assert(dq_fall[7:0] == F_WR_DATA[(f_pair*16) + 8 +: 8]);
                assert(dm_rise[0] == F_WR_MASK[f_pair*2]);
                assert(dm_fall[0] == F_WR_MASK[(f_pair*2) + 1]);

                if (f_pair == 3'd3) begin
                    f_done <= 1'b1;
                    f_started <= 1'b0;
                    f_pair <= 3'd0;
                end else begin
                    f_pair <= f_pair + 3'd1;
                end
            end

            if (f_cycle == 6'd24)
                assert(f_done);

            cover(f_done);
        end
    end
`endif
endmodule

module ddr3_line_lane_phy_read_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 1;
    localparam integer LANES = 1;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WRITE_LATENCY = 1;
    localparam integer READ_LATENCY = 1;

    (* anyseq *) wire [7:0] dq_in_rise_any;
    (* anyseq *) wire [7:0] dq_in_fall_any;

    reg [5:0]  f_cycle = 6'd0;
    reg [2:0]  f_capture_count = 3'd0;
    reg [63:0] f_rd_data = 64'd0;
    reg        f_done = 1'b0;
    reg        f_past_valid = 1'b0;

    wire [CHANNELS-1:0] wr_line_valid = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] start_write = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] start_read = (f_cycle == 6'd2);
    wire [CHANNELS-1:0] rd_line_ready = (f_cycle >= 6'd2);

    wire [CHANNELS-1:0] wr_line_ready;
    wire [CHANNELS-1:0] rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data;
    wire [CHANNELS-1:0] rd_line_err;
    wire [CHANNELS-1:0] channel_busy;
    wire [CHANNELS-1:0] channel_error;
    wire [PHY_LANES-1:0] lane_busy;
    wire [PHY_LANES-1:0] lane_error;
    wire [PHY_LANES-1:0] dq_oe;
    wire [PHY_LANES-1:0] dm_oe;
    wire [PHY_LANES-1:0] dqs_oe;
    wire [(PHY_LANES*8)-1:0] dq_rise;
    wire [(PHY_LANES*8)-1:0] dq_fall;
    wire [PHY_LANES-1:0] dm_rise;
    wire [PHY_LANES-1:0] dm_fall;
    wire [PHY_LANES-1:0] dqs_rise;
    wire [PHY_LANES-1:0] dqs_fall;
    wire [PHY_LANES-1:0] rd_capturing;

    wire [PHY_LANES-1:0] rd_sample_valid = rd_capturing;

    ddr3_line_lane_phy #(
        .CHANNELS(CHANNELS),
        .LANES(LANES),
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .i_wr_line_data({(CHANNELS*LINE_DATA_W){1'b0}}),
        .i_wr_line_mask({(CHANNELS*LINE_BYTES){1'b1}}),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_channel_busy(channel_busy),
        .o_channel_error(channel_error),
        .o_lane_busy(lane_busy),
        .o_lane_error(lane_error),
        .o_dq_oe(dq_oe),
        .o_dm_oe(dm_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_rise),
        .o_dq_fall(dq_fall),
        .o_dm_rise(dm_rise),
        .o_dm_fall(dm_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_in_rise_any),
        .i_dq_fall(dq_in_fall_any)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 6'd0;
            f_capture_count <= 3'd0;
            f_rd_data <= 64'd0;
            f_done <= 1'b0;
        end else begin
            if (f_cycle != 6'd63)
                f_cycle <= f_cycle + 6'd1;

            assert(channel_error == {CHANNELS{1'b0}});
            assert(rd_line_err == {CHANNELS{1'b0}});
            assert(lane_error == {PHY_LANES{1'b0}});
            assert(dq_oe == {PHY_LANES{1'b0}});
            assert(dm_oe == {PHY_LANES{1'b0}});
            assert(dqs_oe == {PHY_LANES{1'b0}});

            if (rd_capturing[0]) begin
                assert(f_capture_count < 3'd4);
                f_rd_data[(f_capture_count*16) +: 8] <= dq_in_rise_any;
                f_rd_data[(f_capture_count*16) + 8 +: 8] <=
                    dq_in_fall_any;
                f_capture_count <= f_capture_count + 3'd1;
            end

            if (rd_line_valid[0]) begin
                assert(f_capture_count == 3'd4);
                assert(rd_line_data[63:0] == f_rd_data);
                f_done <= 1'b1;
            end

            if (f_cycle == 6'd28)
                assert(f_done);

            cover(f_done);
        end
    end
`endif
endmodule

`default_nettype wire
