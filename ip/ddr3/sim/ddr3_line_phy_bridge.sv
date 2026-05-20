// Simulation-only bridge from the controller's line-level PHY contract to the
// existing x8 DQS/DQ Micron timing agents.

`default_nettype none
`timescale 1ps/1ps

module ddr3_line_phy_bridge #(
    parameter integer CHANNELS = 2,
    parameter integer LANES = 8,
    localparam integer PHY_LANES = CHANNELS * LANES,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8
) (
    input wire i_clk,
    input wire i_rst,

    input wire [CHANNELS-1:0] i_wr_line_valid,
    output wire [CHANNELS-1:0] o_wr_line_ready,
    input wire [(CHANNELS*LINE_DATA_W)-1:0] i_wr_line_data,
    input wire [(CHANNELS*LINE_BYTES)-1:0] i_wr_line_mask,

    input wire [CHANNELS-1:0] i_rd_line_ready,
    output reg [CHANNELS-1:0] o_rd_line_valid,
    output reg [(CHANNELS*LINE_DATA_W)-1:0] o_rd_line_data,
    output wire [CHANNELS-1:0] o_rd_line_err,

    output reg [PHY_LANES-1:0] o_lane_wr_valid,
    input wire [PHY_LANES-1:0] i_lane_wr_ready,
    output reg [(PHY_LANES*8)-1:0] o_lane_wr_data,
    output reg [PHY_LANES-1:0] o_lane_wr_mask,
    output reg [PHY_LANES-1:0] o_lane_wr_last,

    output wire [PHY_LANES-1:0] o_lane_rd_ready,
    input wire [PHY_LANES-1:0] i_lane_rd_valid,
    input wire [(PHY_LANES*8)-1:0] i_lane_rd_data
);
    reg [LINE_DATA_W-1:0] wr_line [0:CHANNELS-1];
    reg [LINE_BYTES-1:0] wr_mask [0:CHANNELS-1];
    reg wr_buf_valid [0:CHANNELS-1];
    reg [3:0] wr_beat [0:PHY_LANES-1];

    reg [3:0] rd_beat [0:PHY_LANES-1];
    reg rd_complete [0:CHANNELS-1];

    integer ch_i;
    integer lane_i;
    integer idx_i;
    integer byte_i;

    genvar ch_g;
    genvar lane_g;
    generate
        for (ch_g = 0; ch_g < CHANNELS; ch_g = ch_g + 1) begin : gen_ready
            assign o_wr_line_ready[ch_g] = !wr_buf_valid[ch_g];

            for (lane_g = 0; lane_g < LANES; lane_g = lane_g + 1) begin : gen_lane_ready
                localparam integer PHY_INDEX = (ch_g * LANES) + lane_g;
                assign o_lane_rd_ready[PHY_INDEX] =
                    i_rd_line_ready[ch_g] && !rd_complete[ch_g] &&
                    (rd_beat[PHY_INDEX] < 4'd8);
            end
        end
    endgenerate

    assign o_rd_line_err = {CHANNELS{1'b0}};

    always @(*) begin
        o_lane_wr_valid = {PHY_LANES{1'b0}};
        o_lane_wr_data = {(PHY_LANES*8){1'b0}};
        o_lane_wr_mask = {PHY_LANES{1'b1}};
        o_lane_wr_last = {PHY_LANES{1'b0}};

        for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
            for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1) begin
                idx_i = (ch_i * LANES) + lane_i;
                byte_i = (lane_i * 8) + wr_beat[idx_i];

                if (wr_buf_valid[ch_i] && (wr_beat[idx_i] < 4'd8)) begin
                    o_lane_wr_valid[idx_i] = 1'b1;
                    o_lane_wr_data[idx_i*8 +: 8] =
                        wr_line[ch_i][byte_i*8 +: 8];
                    o_lane_wr_mask[idx_i] = wr_mask[ch_i][byte_i];
                    o_lane_wr_last[idx_i] = (wr_beat[idx_i] == 4'd7);
                end
            end
        end
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_rd_line_valid <= {CHANNELS{1'b0}};
            o_rd_line_data <= {(CHANNELS*LINE_DATA_W){1'b0}};
            for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
                wr_line[ch_i] <= {LINE_DATA_W{1'b0}};
                wr_mask[ch_i] <= {LINE_BYTES{1'b1}};
                wr_buf_valid[ch_i] <= 1'b0;
                rd_complete[ch_i] <= 1'b0;
            end
            for (idx_i = 0; idx_i < PHY_LANES; idx_i = idx_i + 1) begin
                wr_beat[idx_i] <= 4'd0;
                rd_beat[idx_i] <= 4'd0;
            end
        end else begin
            o_rd_line_valid <= {CHANNELS{1'b0}};

            for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
                if (i_wr_line_valid[ch_i] && o_wr_line_ready[ch_i]) begin
                    wr_line[ch_i] <=
                        i_wr_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W];
                    wr_mask[ch_i] <=
                        i_wr_line_mask[ch_i*LINE_BYTES +: LINE_BYTES];
                    wr_buf_valid[ch_i] <= 1'b1;
                    for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1)
                        wr_beat[(ch_i * LANES) + lane_i] <= 4'd0;
                end

                if (!i_rd_line_ready[ch_i]) begin
                    rd_complete[ch_i] <= 1'b0;
                    for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1)
                        rd_beat[(ch_i * LANES) + lane_i] <= 4'd0;
                end
            end

            for (idx_i = 0; idx_i < PHY_LANES; idx_i = idx_i + 1) begin
                if (o_lane_wr_valid[idx_i] && i_lane_wr_ready[idx_i])
                    wr_beat[idx_i] <= wr_beat[idx_i] + 4'd1;

                if (o_lane_rd_ready[idx_i] && i_lane_rd_valid[idx_i]) begin
                    ch_i = idx_i / LANES;
                    lane_i = idx_i % LANES;
                    byte_i = (lane_i * 8) + rd_beat[idx_i];
                    o_rd_line_data[(ch_i*LINE_DATA_W) + (byte_i*8) +: 8] <=
                        i_lane_rd_data[idx_i*8 +: 8];
                    rd_beat[idx_i] <= rd_beat[idx_i] + 4'd1;
                end
            end

            for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
                if (wr_buf_valid[ch_i]) begin
                    if ((wr_beat[(ch_i*LANES) + 0] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 1] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 2] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 3] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 4] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 5] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 6] == 4'd8) &&
                        (wr_beat[(ch_i*LANES) + 7] == 4'd8)) begin
                        wr_buf_valid[ch_i] <= 1'b0;
                    end
                end

                if (i_rd_line_ready[ch_i] && !rd_complete[ch_i]) begin
                    if ((rd_beat[(ch_i*LANES) + 0] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 1] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 2] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 3] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 4] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 5] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 6] == 4'd8) &&
                        (rd_beat[(ch_i*LANES) + 7] == 4'd8)) begin
                        o_rd_line_valid[ch_i] <= 1'b1;
                        rd_complete[ch_i] <= 1'b1;
                    end
                end
            end
        end
    end
endmodule

`default_nettype wire
