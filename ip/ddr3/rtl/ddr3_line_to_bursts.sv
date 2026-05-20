// DDR3 BL8 line-to-x8-burst adapter.
//
// The Wishbone/controller side works in complete 64-byte BL8 cache lines per
// 64-bit DDR3 channel. The timing-critical I/O side should work in one narrow
// x8 burst per physical byte lane. This adapter keeps that boundary explicit:
// each accepted channel line is split into eight independent 64-bit lane
// bursts, and eight returned lane bursts are reassembled into the original
// channel line shape.

`default_nettype none

module ddr3_line_to_bursts #(
    parameter integer CHANNELS = 2,
    parameter integer LANES = 8,
    localparam integer PHY_LANES = CHANNELS * LANES,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8,
    localparam integer LANE_DATA_W = 64,
    localparam integer LANE_MASK_W = 8
) (
    input wire i_clk,
    input wire i_rst,

    input wire [CHANNELS-1:0]               i_wr_line_valid,
    output wire [CHANNELS-1:0]              o_wr_line_ready,
    input wire [(CHANNELS*LINE_DATA_W)-1:0] i_wr_line_data,
    input wire [(CHANNELS*LINE_BYTES)-1:0]  i_wr_line_mask,

    input wire [CHANNELS-1:0]               i_rd_line_ready,
    output reg [CHANNELS-1:0]               o_rd_line_valid,
    output reg [(CHANNELS*LINE_DATA_W)-1:0] o_rd_line_data,
    output wire [CHANNELS-1:0]              o_rd_line_err,

    output reg [PHY_LANES-1:0]                  o_lane_wr_valid,
    input wire [PHY_LANES-1:0]                  i_lane_wr_ready,
    output reg [(PHY_LANES*LANE_DATA_W)-1:0]    o_lane_wr_data,
    output reg [(PHY_LANES*LANE_MASK_W)-1:0]    o_lane_wr_mask,

    output wire [PHY_LANES-1:0]                 o_lane_rd_ready,
    input wire [PHY_LANES-1:0]                  i_lane_rd_valid,
    input wire [(PHY_LANES*LANE_DATA_W)-1:0]    i_lane_rd_data
);
    reg [LINE_DATA_W-1:0] wr_line [0:CHANNELS-1];
    reg [LINE_BYTES-1:0]  wr_mask [0:CHANNELS-1];
    reg                   wr_buf_valid [0:CHANNELS-1];
    reg [PHY_LANES-1:0]   wr_pending;
    reg [PHY_LANES-1:0]   rd_seen;
    reg [CHANNELS-1:0]    rd_complete;
    reg [CHANNELS-1:0]    wr_channel_done;
    reg [CHANNELS-1:0]    rd_channel_done;

    genvar ch_g;
    genvar lane_g;
    generate
        for (ch_g = 0; ch_g < CHANNELS; ch_g = ch_g + 1) begin : gen_channel
            assign o_wr_line_ready[ch_g] = !wr_buf_valid[ch_g];

            for (lane_g = 0; lane_g < LANES; lane_g = lane_g + 1) begin : gen_lane
                localparam integer PHY_INDEX = (ch_g * LANES) + lane_g;
                assign o_lane_rd_ready[PHY_INDEX] =
                    i_rd_line_ready[ch_g] && !rd_complete[ch_g] &&
                    !rd_seen[PHY_INDEX];
            end
        end
    endgenerate

    assign o_rd_line_err = {CHANNELS{1'b0}};

    integer comb_ch_i;
    integer comb_lane_i;
    integer comb_phy_i;
    integer seq_ch_i;
    integer seq_lane_i;
    integer seq_phy_i;

    always @(*) begin
        o_lane_wr_valid = {PHY_LANES{1'b0}};
        o_lane_wr_data = {(PHY_LANES*LANE_DATA_W){1'b0}};
        o_lane_wr_mask = {(PHY_LANES*LANE_MASK_W){1'b1}};
        wr_channel_done = {CHANNELS{1'b1}};
        rd_channel_done = {CHANNELS{1'b1}};

        for (comb_ch_i = 0; comb_ch_i < CHANNELS;
             comb_ch_i = comb_ch_i + 1) begin
            for (comb_lane_i = 0; comb_lane_i < LANES;
                 comb_lane_i = comb_lane_i + 1) begin
                comb_phy_i = (comb_ch_i * LANES) + comb_lane_i;

                if (wr_pending[comb_phy_i])
                    wr_channel_done[comb_ch_i] = 1'b0;
                if (!rd_seen[comb_phy_i])
                    rd_channel_done[comb_ch_i] = 1'b0;

                if (wr_buf_valid[comb_ch_i] &&
                    wr_pending[comb_phy_i]) begin
                    o_lane_wr_valid[comb_phy_i] = 1'b1;
                    o_lane_wr_data[comb_phy_i*LANE_DATA_W +: LANE_DATA_W] =
                        wr_line[comb_ch_i][comb_lane_i*LANE_DATA_W +: LANE_DATA_W];
                    o_lane_wr_mask[comb_phy_i*LANE_MASK_W +: LANE_MASK_W] =
                        wr_mask[comb_ch_i][comb_lane_i*LANE_MASK_W +: LANE_MASK_W];
                end
            end
        end
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_rd_line_valid <= {CHANNELS{1'b0}};
            o_rd_line_data <= {(CHANNELS*LINE_DATA_W){1'b0}};
            wr_pending <= {PHY_LANES{1'b0}};
            rd_seen <= {PHY_LANES{1'b0}};
            rd_complete <= {CHANNELS{1'b0}};
            for (seq_ch_i = 0; seq_ch_i < CHANNELS;
                 seq_ch_i = seq_ch_i + 1) begin
                wr_line[seq_ch_i] <= {LINE_DATA_W{1'b0}};
                wr_mask[seq_ch_i] <= {LINE_BYTES{1'b1}};
                wr_buf_valid[seq_ch_i] <= 1'b0;
            end
        end else begin
            o_rd_line_valid <= {CHANNELS{1'b0}};

            for (seq_ch_i = 0; seq_ch_i < CHANNELS;
                 seq_ch_i = seq_ch_i + 1) begin
                if (i_wr_line_valid[seq_ch_i] &&
                    o_wr_line_ready[seq_ch_i]) begin
                    wr_line[seq_ch_i] <=
                        i_wr_line_data[seq_ch_i*LINE_DATA_W +: LINE_DATA_W];
                    wr_mask[seq_ch_i] <=
                        i_wr_line_mask[seq_ch_i*LINE_BYTES +: LINE_BYTES];
                    wr_buf_valid[seq_ch_i] <= 1'b1;
                    for (seq_lane_i = 0; seq_lane_i < LANES;
                         seq_lane_i = seq_lane_i + 1)
                        wr_pending[(seq_ch_i * LANES) + seq_lane_i] <= 1'b1;
                end

                if (!i_rd_line_ready[seq_ch_i]) begin
                    rd_complete[seq_ch_i] <= 1'b0;
                    for (seq_lane_i = 0; seq_lane_i < LANES;
                         seq_lane_i = seq_lane_i + 1)
                        rd_seen[(seq_ch_i * LANES) + seq_lane_i] <= 1'b0;
                end
            end

            for (seq_phy_i = 0; seq_phy_i < PHY_LANES;
                 seq_phy_i = seq_phy_i + 1) begin
                if (o_lane_wr_valid[seq_phy_i] &&
                    i_lane_wr_ready[seq_phy_i])
                    wr_pending[seq_phy_i] <= 1'b0;

                if (o_lane_rd_ready[seq_phy_i] &&
                    i_lane_rd_valid[seq_phy_i]) begin
                    seq_ch_i = seq_phy_i / LANES;
                    seq_lane_i = seq_phy_i % LANES;
                    o_rd_line_data[(seq_ch_i*LINE_DATA_W) +
                                   (seq_lane_i*LANE_DATA_W) +: LANE_DATA_W] <=
                        i_lane_rd_data[seq_phy_i*LANE_DATA_W +: LANE_DATA_W];
                    rd_seen[seq_phy_i] <= 1'b1;
                end
            end

            for (seq_ch_i = 0; seq_ch_i < CHANNELS;
                 seq_ch_i = seq_ch_i + 1) begin
                if (wr_buf_valid[seq_ch_i] && wr_channel_done[seq_ch_i])
                    wr_buf_valid[seq_ch_i] <= 1'b0;

                if (i_rd_line_ready[seq_ch_i] &&
                    !rd_complete[seq_ch_i] &&
                    rd_channel_done[seq_ch_i]) begin
                    o_rd_line_valid[seq_ch_i] <= 1'b1;
                    rd_complete[seq_ch_i] <= 1'b1;
                end
            end
        end
    end
endmodule

`default_nettype wire
