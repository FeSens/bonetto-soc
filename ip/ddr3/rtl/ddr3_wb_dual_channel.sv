// Dual-channel Wishbone-to-DDR3 BL8 bridge.
//
// This block is the bus-facing full-capacity integration slice. It accepts one
// global 32-bit Wishbone word request at a time, decodes bit 29 as the DDR3
// channel, and routes the lower 29 word-address bits into one full-width
// channel bridge. Each channel then emits one aligned BL8 line command and
// drives its own 64-bit-channel data packetizer.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_wb_dual_channel #(
    parameter integer LANES     = 8,
    parameter integer WB_DATA_W = 32,
    localparam integer CHANNELS = 2,
    localparam integer CHANNEL_BITS = 1,
    localparam integer WORD_INDEX_BITS = 4,
    localparam integer COL_LINE_BITS = `DDR3_COL_BITS - 3,
    localparam integer LINE_ADDR_W =
        `DDR3_BANK_BITS + `DDR3_ROW_BITS + COL_LINE_BITS,
    localparam integer LOCAL_WORD_ADDR_W = LINE_ADDR_W + WORD_INDEX_BITS,
    localparam integer GLOBAL_WORD_ADDR_W =
        CHANNEL_BITS + LOCAL_WORD_ADDR_W,
    localparam integer PHY_DATA_W = LANES * 8
) (
    input wire                         i_clk,
    input wire                         i_rst,

    input wire                         i_wb_cyc,
    input wire                         i_wb_stb,
    input wire                         i_wb_we,
    input wire [GLOBAL_WORD_ADDR_W-1:0] i_wb_adr,
    input wire [WB_DATA_W-1:0]         i_wb_dat,
    input wire [(WB_DATA_W/8)-1:0]     i_wb_sel,
    output wire                        o_wb_stall,
    output wire                        o_wb_ack,
    output wire [WB_DATA_W-1:0]        o_wb_dat,
    output wire                        o_wb_err,

    output wire [CHANNELS-1:0]         o_cmd_valid,
    input wire [CHANNELS-1:0]          i_cmd_ready,
    output wire [CHANNELS-1:0]         o_cmd_write,
    output wire [(CHANNELS*LINE_ADDR_W)-1:0] o_cmd_line_addr,

    output wire [CHANNELS-1:0]         o_busy,
    output wire [CHANNELS-1:0]         o_line_done,
    output wire [CHANNELS-1:0]         o_line_rd_valid,

    output wire [(CHANNELS*LANES)-1:0] o_phy_wr_valid,
    input wire [(CHANNELS*LANES)-1:0]  i_phy_wr_ready,
    output wire [(CHANNELS*PHY_DATA_W)-1:0] o_phy_wr_data,
    output wire [(CHANNELS*LANES)-1:0] o_phy_wr_mask,
    output wire [(CHANNELS*LANES)-1:0] o_phy_wr_last,

    output wire [(CHANNELS*LANES)-1:0] o_phy_rd_ready,
    input wire [(CHANNELS*LANES)-1:0]  i_phy_rd_valid,
    input wire [(CHANNELS*PHY_DATA_W)-1:0] i_phy_rd_data
);
    wire [CHANNEL_BITS-1:0]      decoded_channel;
    wire [LOCAL_WORD_ADDR_W-1:0] decoded_local_word_addr;

    wire [LINE_ADDR_W-1:0] decoded_line_addr_unused;
    wire [WORD_INDEX_BITS-1:0] decoded_word_index_unused;
    wire [`DDR3_BANK_BITS-1:0] decoded_bank_unused;
    wire [`DDR3_ROW_BITS-1:0] decoded_row_unused;
    wire [COL_LINE_BITS-1:0] decoded_col_line_unused;
    wire [`DDR3_COL_BITS-1:0] decoded_col_unused;

    reg owner_valid;
    reg owner_channel;

    wire ch0_selected = !decoded_channel[0];
    wire ch1_selected = decoded_channel[0];

    wire ch0_wb_cyc = i_wb_cyc &&
        ((owner_valid && !owner_channel) || (!owner_valid && ch0_selected));
    wire ch1_wb_cyc = i_wb_cyc &&
        ((owner_valid && owner_channel) || (!owner_valid && ch1_selected));
    wire ch0_wb_stb = i_wb_stb && !owner_valid && ch0_selected;
    wire ch1_wb_stb = i_wb_stb && !owner_valid && ch1_selected;

    wire ch0_wb_stall;
    wire ch0_wb_ack;
    wire [WB_DATA_W-1:0] ch0_wb_dat;
    wire ch0_wb_err;

    wire ch1_wb_stall;
    wire ch1_wb_ack;
    wire [WB_DATA_W-1:0] ch1_wb_dat;
    wire ch1_wb_err;

    wire owner_rsp = owner_channel ? (ch1_wb_ack || ch1_wb_err)
                                   : (ch0_wb_ack || ch0_wb_err);

    assign o_wb_stall = owner_valid ? 1'b1 :
        (decoded_channel[0] ? ch1_wb_stall : ch0_wb_stall);
    assign o_wb_ack = owner_valid ? (owner_channel ? ch1_wb_ack : ch0_wb_ack)
                                  : 1'b0;
    assign o_wb_dat = owner_channel ? ch1_wb_dat : ch0_wb_dat;
    assign o_wb_err = owner_valid ? (owner_channel ? ch1_wb_err : ch0_wb_err)
                                  : 1'b0;

    wire wb_accept = i_wb_cyc && i_wb_stb && !o_wb_stall;

    ddr3_addr_decode u_addr_decode (
        .i_word_addr(i_wb_adr),
        .o_channel(decoded_channel),
        .o_local_word_addr(decoded_local_word_addr),
        .o_line_addr(decoded_line_addr_unused),
        .o_word_index(decoded_word_index_unused),
        .o_bank(decoded_bank_unused),
        .o_row(decoded_row_unused),
        .o_col_line(decoded_col_line_unused),
        .o_col(decoded_col_unused)
    );

    always @(posedge i_clk) begin
        if (i_rst || !i_wb_cyc) begin
            owner_valid <= 1'b0;
            owner_channel <= 1'b0;
        end else if (!owner_valid && wb_accept) begin
            owner_valid <= 1'b1;
            owner_channel <= decoded_channel[0];
        end else if (owner_valid && owner_rsp) begin
            owner_valid <= 1'b0;
        end
    end

    ddr3_wb_channel #(
        .WB_ADDR_W(LOCAL_WORD_ADDR_W),
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W)
    ) u_ch0 (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wb_cyc(ch0_wb_cyc),
        .i_wb_stb(ch0_wb_stb),
        .i_wb_we(i_wb_we),
        .i_wb_adr(decoded_local_word_addr),
        .i_wb_dat(i_wb_dat),
        .i_wb_sel(i_wb_sel),
        .o_wb_stall(ch0_wb_stall),
        .o_wb_ack(ch0_wb_ack),
        .o_wb_dat(ch0_wb_dat),
        .o_wb_err(ch0_wb_err),
        .o_cmd_valid(o_cmd_valid[0]),
        .i_cmd_ready(i_cmd_ready[0]),
        .o_cmd_write(o_cmd_write[0]),
        .o_cmd_line_addr(o_cmd_line_addr[0 +: LINE_ADDR_W]),
        .o_busy(o_busy[0]),
        .o_line_done(o_line_done[0]),
        .o_line_rd_valid(o_line_rd_valid[0]),
        .o_phy_wr_valid(o_phy_wr_valid[0 +: LANES]),
        .i_phy_wr_ready(i_phy_wr_ready[0 +: LANES]),
        .o_phy_wr_data(o_phy_wr_data[0 +: PHY_DATA_W]),
        .o_phy_wr_mask(o_phy_wr_mask[0 +: LANES]),
        .o_phy_wr_last(o_phy_wr_last[0 +: LANES]),
        .o_phy_rd_ready(o_phy_rd_ready[0 +: LANES]),
        .i_phy_rd_valid(i_phy_rd_valid[0 +: LANES]),
        .i_phy_rd_data(i_phy_rd_data[0 +: PHY_DATA_W])
    );

    ddr3_wb_channel #(
        .WB_ADDR_W(LOCAL_WORD_ADDR_W),
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W)
    ) u_ch1 (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wb_cyc(ch1_wb_cyc),
        .i_wb_stb(ch1_wb_stb),
        .i_wb_we(i_wb_we),
        .i_wb_adr(decoded_local_word_addr),
        .i_wb_dat(i_wb_dat),
        .i_wb_sel(i_wb_sel),
        .o_wb_stall(ch1_wb_stall),
        .o_wb_ack(ch1_wb_ack),
        .o_wb_dat(ch1_wb_dat),
        .o_wb_err(ch1_wb_err),
        .o_cmd_valid(o_cmd_valid[1]),
        .i_cmd_ready(i_cmd_ready[1]),
        .o_cmd_write(o_cmd_write[1]),
        .o_cmd_line_addr(o_cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W]),
        .o_busy(o_busy[1]),
        .o_line_done(o_line_done[1]),
        .o_line_rd_valid(o_line_rd_valid[1]),
        .o_phy_wr_valid(o_phy_wr_valid[LANES +: LANES]),
        .i_phy_wr_ready(i_phy_wr_ready[LANES +: LANES]),
        .o_phy_wr_data(o_phy_wr_data[PHY_DATA_W +: PHY_DATA_W]),
        .o_phy_wr_mask(o_phy_wr_mask[LANES +: LANES]),
        .o_phy_wr_last(o_phy_wr_last[LANES +: LANES]),
        .o_phy_rd_ready(o_phy_rd_ready[LANES +: LANES]),
        .i_phy_rd_valid(i_phy_rd_valid[LANES +: LANES]),
        .i_phy_rd_data(i_phy_rd_data[PHY_DATA_W +: PHY_DATA_W])
    );
endmodule

`default_nettype wire
