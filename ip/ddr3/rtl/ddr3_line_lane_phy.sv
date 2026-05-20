// DDR3 line-to-lane PHY timing bridge.
//
// This composes the line-to-x8-lane adapter with one reusable x8 PHY timing
// core per byte lane. The output is still an abstract DDR pin-timing contract:
// board code owns the 7-series ODDR/IDDR/IOBUF/IDELAY primitives and pin map.

`default_nettype none

module ddr3_line_lane_phy #(
    parameter integer CHANNELS = 2,
    parameter integer LANES = 8,
    parameter integer WRITE_LATENCY = 5,
    parameter integer READ_LATENCY = 6,
    localparam integer PHY_LANES = CHANNELS * LANES,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8
) (
    input wire i_clk,
    input wire i_rst,

    input wire [CHANNELS-1:0]               i_wr_line_valid,
    output wire [CHANNELS-1:0]              o_wr_line_ready,
    input wire [(CHANNELS*LINE_DATA_W)-1:0] i_wr_line_data,
    input wire [(CHANNELS*LINE_BYTES)-1:0]  i_wr_line_mask,

    input wire [CHANNELS-1:0]               i_start_write,
    input wire [CHANNELS-1:0]               i_start_read,

    input wire [CHANNELS-1:0]               i_rd_line_ready,
    output wire [CHANNELS-1:0]              o_rd_line_valid,
    output wire [(CHANNELS*LINE_DATA_W)-1:0] o_rd_line_data,
    output wire [CHANNELS-1:0]              o_rd_line_err,

    output wire [CHANNELS-1:0]              o_channel_busy,
    output wire [CHANNELS-1:0]              o_channel_error,
    output wire [PHY_LANES-1:0]             o_lane_busy,
    output wire [PHY_LANES-1:0]             o_lane_error,

    output wire [PHY_LANES-1:0]             o_dq_oe,
    output wire [PHY_LANES-1:0]             o_dm_oe,
    output wire [PHY_LANES-1:0]             o_dqs_oe,
    output wire [(PHY_LANES*8)-1:0]         o_dq_rise,
    output wire [(PHY_LANES*8)-1:0]         o_dq_fall,
    output wire [PHY_LANES-1:0]             o_dm_rise,
    output wire [PHY_LANES-1:0]             o_dm_fall,
    output wire [PHY_LANES-1:0]             o_dqs_rise,
    output wire [PHY_LANES-1:0]             o_dqs_fall,

    output wire [PHY_LANES-1:0]             o_rd_capturing,
    input wire [PHY_LANES-1:0]              i_rd_sample_valid,
    input wire [(PHY_LANES*8)-1:0]          i_dq_rise,
    input wire [(PHY_LANES*8)-1:0]          i_dq_fall
);
    wire [CHANNELS-1:0]               adapter_wr_line_ready;
    wire [CHANNELS-1:0]               adapter_rd_line_err;
    wire [CHANNELS-1:0]               adapter_rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] adapter_rd_line_data;

    wire [PHY_LANES-1:0]              lane_wr_valid;
    wire [PHY_LANES-1:0]              lane_wr_ready;
    wire [(PHY_LANES*8)-1:0]          lane_wr_data;
    wire [PHY_LANES-1:0]              lane_wr_mask;
    wire [PHY_LANES-1:0]              lane_wr_last;
    wire [PHY_LANES-1:0]              lane_wr_loaded;

    wire [PHY_LANES-1:0]              lane_rd_ready;
    wire [PHY_LANES-1:0]              lane_rd_valid;
    wire [(PHY_LANES*8)-1:0]          lane_rd_data;

    reg [CHANNELS-1:0]                pending_write;
    reg [CHANNELS-1:0]                pending_read;
    reg [CHANNELS-1:0]                read_inflight;
    reg [CHANNELS-1:0]                channel_error;
    reg [PHY_LANES-1:0]               lane_start_write;
    reg [PHY_LANES-1:0]               lane_start_read;

    reg [CHANNELS-1:0]                lane_busy_any;
    reg [CHANNELS-1:0]                lane_error_any;
    reg [CHANNELS-1:0]                lane_loaded_any;
    reg [CHANNELS-1:0]                lane_loaded_all;
    reg [CHANNELS-1:0]                fire_write;
    reg [CHANNELS-1:0]                fire_read;

    integer comb_ch_i;
    integer comb_lane_i;
    integer comb_phy_i;
    integer seq_ch_i;
    integer seq_lane_i;
    integer seq_phy_i;

    always @(*) begin
        lane_busy_any = {CHANNELS{1'b0}};
        lane_error_any = {CHANNELS{1'b0}};
        lane_loaded_any = {CHANNELS{1'b0}};
        lane_loaded_all = {CHANNELS{1'b1}};
        fire_write = {CHANNELS{1'b0}};
        fire_read = {CHANNELS{1'b0}};

        for (comb_ch_i = 0; comb_ch_i < CHANNELS;
             comb_ch_i = comb_ch_i + 1) begin
            for (comb_lane_i = 0; comb_lane_i < LANES;
                 comb_lane_i = comb_lane_i + 1) begin
                comb_phy_i = (comb_ch_i * LANES) + comb_lane_i;
                lane_busy_any[comb_ch_i] =
                    lane_busy_any[comb_ch_i] | o_lane_busy[comb_phy_i];
                lane_error_any[comb_ch_i] =
                    lane_error_any[comb_ch_i] | o_lane_error[comb_phy_i];
                lane_loaded_any[comb_ch_i] =
                    lane_loaded_any[comb_ch_i] | lane_wr_loaded[comb_phy_i];
                lane_loaded_all[comb_ch_i] =
                    lane_loaded_all[comb_ch_i] & lane_wr_loaded[comb_phy_i];
            end

            fire_write[comb_ch_i] =
                pending_write[comb_ch_i] &&
                lane_loaded_all[comb_ch_i] &&
                !lane_busy_any[comb_ch_i] &&
                !pending_read[comb_ch_i] &&
                !read_inflight[comb_ch_i];

            fire_read[comb_ch_i] =
                pending_read[comb_ch_i] &&
                adapter_wr_line_ready[comb_ch_i] &&
                !lane_loaded_any[comb_ch_i] &&
                !lane_busy_any[comb_ch_i] &&
                !pending_write[comb_ch_i] &&
                !read_inflight[comb_ch_i];
        end
    end

    genvar ch_g;
    generate
        for (ch_g = 0; ch_g < CHANNELS; ch_g = ch_g + 1) begin : gen_ready
            assign o_wr_line_ready[ch_g] =
                adapter_wr_line_ready[ch_g] &&
                !pending_write[ch_g] &&
                !pending_read[ch_g] &&
                !read_inflight[ch_g] &&
                !lane_busy_any[ch_g] &&
                !lane_loaded_any[ch_g];

            assign o_channel_busy[ch_g] =
                !adapter_wr_line_ready[ch_g] ||
                pending_write[ch_g] ||
                pending_read[ch_g] ||
                read_inflight[ch_g] ||
                lane_busy_any[ch_g] ||
                lane_loaded_any[ch_g];

            assign o_channel_error[ch_g] =
                channel_error[ch_g] ||
                adapter_rd_line_err[ch_g] ||
                lane_error_any[ch_g];

            assign o_rd_line_err[ch_g] = o_channel_error[ch_g];
        end
    endgenerate

    assign o_rd_line_valid = adapter_rd_line_valid;
    assign o_rd_line_data = adapter_rd_line_data;

    wire [CHANNELS-1:0] adapter_wr_line_valid =
        i_wr_line_valid & o_wr_line_ready;
    wire [CHANNELS-1:0] adapter_rd_line_ready =
        i_rd_line_ready & (pending_read | read_inflight | fire_read);

    ddr3_line_to_lanes #(
        .CHANNELS(CHANNELS),
        .LANES(LANES)
    ) u_line_to_lanes (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wr_line_valid(adapter_wr_line_valid),
        .o_wr_line_ready(adapter_wr_line_ready),
        .i_wr_line_data(i_wr_line_data),
        .i_wr_line_mask(i_wr_line_mask),
        .i_rd_line_ready(adapter_rd_line_ready),
        .o_rd_line_valid(adapter_rd_line_valid),
        .o_rd_line_data(adapter_rd_line_data),
        .o_rd_line_err(adapter_rd_line_err),
        .o_lane_wr_valid(lane_wr_valid),
        .i_lane_wr_ready(lane_wr_ready),
        .o_lane_wr_data(lane_wr_data),
        .o_lane_wr_mask(lane_wr_mask),
        .o_lane_wr_last(lane_wr_last),
        .o_lane_rd_ready(lane_rd_ready),
        .i_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_data(lane_rd_data)
    );

    genvar lane_g;
    generate
        for (lane_g = 0; lane_g < PHY_LANES; lane_g = lane_g + 1) begin : gen_lane_phy
            ddr3_x8_lane_phy #(
                .WRITE_LATENCY(WRITE_LATENCY),
                .READ_LATENCY(READ_LATENCY)
            ) u_lane_phy (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_lane_wr_valid(lane_wr_valid[lane_g]),
                .o_lane_wr_ready(lane_wr_ready[lane_g]),
                .i_lane_wr_data(lane_wr_data[lane_g*8 +: 8]),
                .i_lane_wr_mask(lane_wr_mask[lane_g]),
                .i_lane_wr_last(lane_wr_last[lane_g]),
                .o_wr_loaded(lane_wr_loaded[lane_g]),
                .i_start_write(lane_start_write[lane_g]),
                .i_start_read(lane_start_read[lane_g]),
                .o_busy(o_lane_busy[lane_g]),
                .o_error(o_lane_error[lane_g]),
                .o_dq_oe(o_dq_oe[lane_g]),
                .o_dm_oe(o_dm_oe[lane_g]),
                .o_dqs_oe(o_dqs_oe[lane_g]),
                .o_dq_rise(o_dq_rise[lane_g*8 +: 8]),
                .o_dq_fall(o_dq_fall[lane_g*8 +: 8]),
                .o_dm_rise(o_dm_rise[lane_g]),
                .o_dm_fall(o_dm_fall[lane_g]),
                .o_dqs_rise(o_dqs_rise[lane_g]),
                .o_dqs_fall(o_dqs_fall[lane_g]),
                .o_rd_capturing(o_rd_capturing[lane_g]),
                .i_rd_sample_valid(i_rd_sample_valid[lane_g]),
                .i_dq_rise(i_dq_rise[lane_g*8 +: 8]),
                .i_dq_fall(i_dq_fall[lane_g*8 +: 8]),
                .o_lane_rd_valid(lane_rd_valid[lane_g]),
                .i_lane_rd_ready(lane_rd_ready[lane_g]),
                .o_lane_rd_data(lane_rd_data[lane_g*8 +: 8])
            );
        end
    endgenerate

    always @(posedge i_clk) begin
        if (i_rst) begin
            pending_write <= {CHANNELS{1'b0}};
            pending_read <= {CHANNELS{1'b0}};
            read_inflight <= {CHANNELS{1'b0}};
            channel_error <= {CHANNELS{1'b0}};
            lane_start_write <= {PHY_LANES{1'b0}};
            lane_start_read <= {PHY_LANES{1'b0}};
        end else begin
            lane_start_write <= {PHY_LANES{1'b0}};
            lane_start_read <= {PHY_LANES{1'b0}};

            for (seq_ch_i = 0; seq_ch_i < CHANNELS;
                 seq_ch_i = seq_ch_i + 1) begin
                if (i_start_write[seq_ch_i] && i_start_read[seq_ch_i]) begin
                    channel_error[seq_ch_i] <= 1'b1;
                end else begin
                    if (i_start_write[seq_ch_i]) begin
                        if ((adapter_wr_line_ready[seq_ch_i] &&
                             !lane_loaded_any[seq_ch_i]) ||
                            pending_write[seq_ch_i] ||
                            pending_read[seq_ch_i] ||
                            read_inflight[seq_ch_i] ||
                            lane_busy_any[seq_ch_i]) begin
                            channel_error[seq_ch_i] <= 1'b1;
                        end else begin
                            pending_write[seq_ch_i] <= 1'b1;
                        end
                    end

                    if (i_start_read[seq_ch_i]) begin
                        if (!i_rd_line_ready[seq_ch_i] ||
                            !adapter_wr_line_ready[seq_ch_i] ||
                            pending_write[seq_ch_i] ||
                            pending_read[seq_ch_i] ||
                            read_inflight[seq_ch_i] ||
                            lane_busy_any[seq_ch_i] ||
                            lane_loaded_any[seq_ch_i]) begin
                            channel_error[seq_ch_i] <= 1'b1;
                        end else begin
                            pending_read[seq_ch_i] <= 1'b1;
                        end
                    end
                end

                if (read_inflight[seq_ch_i] &&
                    !i_rd_line_ready[seq_ch_i])
                    channel_error[seq_ch_i] <= 1'b1;

                if (fire_write[seq_ch_i]) begin
                    pending_write[seq_ch_i] <= 1'b0;
                    for (seq_lane_i = 0; seq_lane_i < LANES;
                         seq_lane_i = seq_lane_i + 1) begin
                        seq_phy_i = (seq_ch_i * LANES) + seq_lane_i;
                        lane_start_write[seq_phy_i] <= 1'b1;
                    end
                end

                if (fire_read[seq_ch_i]) begin
                    pending_read[seq_ch_i] <= 1'b0;
                    read_inflight[seq_ch_i] <= 1'b1;
                    for (seq_lane_i = 0; seq_lane_i < LANES;
                         seq_lane_i = seq_lane_i + 1) begin
                        seq_phy_i = (seq_ch_i * LANES) + seq_lane_i;
                        lane_start_read[seq_phy_i] <= 1'b1;
                    end
                end

                if (adapter_rd_line_valid[seq_ch_i])
                    read_inflight[seq_ch_i] <= 1'b0;
            end
        end
    end
endmodule

`default_nettype wire
