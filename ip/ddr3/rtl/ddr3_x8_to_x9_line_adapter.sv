// Explicit x64-data to x72-physical DDR3 line adapter.
//
// The Wishbone-visible controller line remains eight x8 BL8 lanes
// (64 bytes/channel).  The board has a ninth x8 device per channel.  Until a
// real ECC encoder/checker is added, lane 8 is a deterministic spare lane:
// writes drive zeros and reads ignore that lane.

`default_nettype none

module ddr3_x8_to_x9_line_adapter #(
    parameter integer CHANNELS = 2,
    parameter [63:0] SPARE_WR_DATA = 64'h0,
    parameter [7:0]  SPARE_WR_MASK = 8'h00,
    localparam integer DATA_LANES = 8,
    localparam integer PHY_LANES = 9,
    localparam integer DATA_LINE_BYTES = DATA_LANES * 8,
    localparam integer DATA_LINE_DATA_W = DATA_LINE_BYTES * 8,
    localparam integer PHY_LINE_BYTES = PHY_LANES * 8,
    localparam integer PHY_LINE_DATA_W = PHY_LINE_BYTES * 8
) (
    input  wire [CHANNELS-1:0]                    i_ctrl_wr_line_valid,
    output wire [CHANNELS-1:0]                    o_ctrl_wr_line_ready,
    output wire [CHANNELS-1:0]                    o_ctrl_wr_line_loaded,
    input  wire [(CHANNELS*DATA_LINE_DATA_W)-1:0] i_ctrl_wr_line_data,
    input  wire [(CHANNELS*DATA_LINE_BYTES)-1:0]  i_ctrl_wr_line_mask,
    input  wire [CHANNELS-1:0]                    i_ctrl_rd_line_ready,
    output wire [CHANNELS-1:0]                    o_ctrl_rd_line_valid,
    output wire [(CHANNELS*DATA_LINE_DATA_W)-1:0] o_ctrl_rd_line_data,
    output wire [CHANNELS-1:0]                    o_ctrl_rd_line_err,

    output wire [CHANNELS-1:0]                    o_phy_wr_line_valid,
    input  wire [CHANNELS-1:0]                    i_phy_wr_line_ready,
    input  wire [CHANNELS-1:0]                    i_phy_wr_line_loaded,
    output wire [(CHANNELS*PHY_LINE_DATA_W)-1:0]  o_phy_wr_line_data,
    output wire [(CHANNELS*PHY_LINE_BYTES)-1:0]   o_phy_wr_line_mask,
    output wire [CHANNELS-1:0]                    o_phy_rd_line_ready,
    input  wire [CHANNELS-1:0]                    i_phy_rd_line_valid,
    input  wire [(CHANNELS*PHY_LINE_DATA_W)-1:0]  i_phy_rd_line_data,
    input  wire [CHANNELS-1:0]                    i_phy_rd_line_err
);
    assign o_phy_wr_line_valid = i_ctrl_wr_line_valid;
    assign o_ctrl_wr_line_ready = i_phy_wr_line_ready;
    assign o_ctrl_wr_line_loaded = i_phy_wr_line_loaded;

    assign o_phy_rd_line_ready = i_ctrl_rd_line_ready;
    assign o_ctrl_rd_line_valid = i_phy_rd_line_valid;
    assign o_ctrl_rd_line_err = i_phy_rd_line_err;

    genvar ch;
    genvar lane;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_channel
            localparam integer DATA_CH_DATA_BASE = ch * DATA_LINE_DATA_W;
            localparam integer DATA_CH_MASK_BASE = ch * DATA_LINE_BYTES;
            localparam integer PHY_CH_DATA_BASE = ch * PHY_LINE_DATA_W;
            localparam integer PHY_CH_MASK_BASE = ch * PHY_LINE_BYTES;

            for (lane = 0; lane < DATA_LANES; lane = lane + 1) begin : gen_data_lane
                assign o_phy_wr_line_data[
                    PHY_CH_DATA_BASE + lane*64 +: 64] =
                    i_ctrl_wr_line_data[
                        DATA_CH_DATA_BASE + lane*64 +: 64];
                assign o_phy_wr_line_mask[
                    PHY_CH_MASK_BASE + lane*8 +: 8] =
                    i_ctrl_wr_line_mask[
                        DATA_CH_MASK_BASE + lane*8 +: 8];
                assign o_ctrl_rd_line_data[
                    DATA_CH_DATA_BASE + lane*64 +: 64] =
                    i_phy_rd_line_data[
                        PHY_CH_DATA_BASE + lane*64 +: 64];
            end

            assign o_phy_wr_line_data[
                PHY_CH_DATA_BASE + DATA_LANES*64 +: 64] = SPARE_WR_DATA;
            assign o_phy_wr_line_mask[
                PHY_CH_MASK_BASE + DATA_LANES*8 +: 8] = SPARE_WR_MASK;
        end
    endgenerate
endmodule

`default_nettype wire
