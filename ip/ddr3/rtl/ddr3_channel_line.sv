// Full-channel DDR3 BL8 line packetizer.
//
// A 64-bit DDR3 channel is eight x8 byte lanes. Each BL8 transfer carries
// eight beats per byte lane, so one full-channel line is 512 data bits plus
// 64 byte-mask bits. This module composes eight byte-lane packetizers behind a
// single controller-side line interface and keeps per-lane PHY handshakes
// visible for the future board-specific DQS/DQ PHY.

`default_nettype none

module ddr3_channel_line #(
    parameter integer LANES = 8,
    localparam integer LINE_DATA_W = LANES * 64,
    localparam integer LINE_MASK_W = LANES * 8
) (
    input wire                       i_clk,
    input wire                       i_rst,

    input wire                       i_start,
    output wire                      o_ready,
    input wire                       i_write,
    input wire [LINE_DATA_W-1:0]     i_wr_data,
    input wire [LINE_MASK_W-1:0]     i_wr_mask,

    output wire                      o_busy,
    output reg                       o_done,
    output reg                       o_rd_valid,
    output reg [LINE_DATA_W-1:0]     o_rd_data,

    output wire [LANES-1:0]          o_phy_wr_valid,
    input wire [LANES-1:0]           i_phy_wr_ready,
    output wire [(LANES*8)-1:0]      o_phy_wr_data,
    output wire [LANES-1:0]          o_phy_wr_mask,
    output wire [LANES-1:0]          o_phy_wr_last,

    output wire [LANES-1:0]          o_phy_rd_ready,
    input wire [LANES-1:0]           i_phy_rd_valid,
    input wire [(LANES*8)-1:0]       i_phy_rd_data
);
    reg active;
    reg active_write;
    reg [LANES-1:0] done_mask;
    reg [LANES-1:0] rd_mask;
    reg [LINE_DATA_W-1:0] rd_data_hold;

    wire [LANES-1:0] lane_ready;
    wire [LANES-1:0] lane_busy;
    wire [LANES-1:0] lane_done;
    wire [LANES-1:0] lane_rd_valid;
    wire [LINE_DATA_W-1:0] lane_rd_data;

    wire all_lanes_ready = &lane_ready;
    wire accepted_start = i_start && o_ready;
    wire [LANES-1:0] next_done_mask = done_mask | lane_done;
    wire [LANES-1:0] next_rd_mask = rd_mask | lane_rd_valid;

    assign o_ready = !active && all_lanes_ready;
    assign o_busy = active || (|lane_busy);

    genvar lane;
    generate
        for (lane = 0; lane < LANES; lane = lane + 1) begin : gen_lanes
            ddr3_byte_lane u_lane (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_start(accepted_start),
                .o_ready(lane_ready[lane]),
                .i_write(i_write),
                .i_wr_data(i_wr_data[(lane * 64) +: 64]),
                .i_wr_mask(i_wr_mask[(lane * 8) +: 8]),
                .o_busy(lane_busy[lane]),
                .o_done(lane_done[lane]),
                .o_phy_wr_valid(o_phy_wr_valid[lane]),
                .i_phy_wr_ready(i_phy_wr_ready[lane]),
                .o_phy_wr_data(o_phy_wr_data[(lane * 8) +: 8]),
                .o_phy_wr_mask(o_phy_wr_mask[lane]),
                .o_phy_wr_last(o_phy_wr_last[lane]),
                .o_phy_rd_ready(o_phy_rd_ready[lane]),
                .i_phy_rd_valid(i_phy_rd_valid[lane]),
                .i_phy_rd_data(i_phy_rd_data[(lane * 8) +: 8]),
                .o_rd_valid(lane_rd_valid[lane]),
                .o_rd_data(lane_rd_data[(lane * 64) +: 64])
            );
        end
    endgenerate

    reg [LINE_DATA_W-1:0] rd_data_next;
    integer i;

    always @(*) begin
        rd_data_next = rd_data_hold;
        for (i = 0; i < LANES; i = i + 1) begin
            if (lane_rd_valid[i])
                rd_data_next[(i * 64) +: 64] = lane_rd_data[(i * 64) +: 64];
        end
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            active       <= 1'b0;
            active_write <= 1'b0;
            done_mask    <= {LANES{1'b0}};
            rd_mask      <= {LANES{1'b0}};
            rd_data_hold <= {LINE_DATA_W{1'b0}};
            o_done       <= 1'b0;
            o_rd_valid   <= 1'b0;
            o_rd_data    <= {LINE_DATA_W{1'b0}};
        end else begin
            o_done     <= 1'b0;
            o_rd_valid <= 1'b0;

            if (accepted_start) begin
                active       <= 1'b1;
                active_write <= i_write;
                done_mask    <= {LANES{1'b0}};
                rd_mask      <= {LANES{1'b0}};
                rd_data_hold <= {LINE_DATA_W{1'b0}};
            end else if (active) begin
                done_mask <= next_done_mask;
                rd_mask <= next_rd_mask;
                rd_data_hold <= rd_data_next;

                if (&next_done_mask) begin
                    active <= 1'b0;
                    o_done <= 1'b1;

                    if (!active_write) begin
                        o_rd_valid <= 1'b1;
                        o_rd_data <= rd_data_next;
                    end
                end
            end
        end
    end
endmodule

`default_nettype wire
