// Synthesizable controller-side DDR3 PHY loopback for board bring-up.
//
// This is not a real DQ/DQS PHY. It decodes the controller's ACT/RD/WR
// command stream, captures packetized BL8 writes, and returns packetized BL8
// reads from a small internal memory. The purpose is to validate the live
// JTAG/Wishbone -> clean DDR3 controller -> scheduler -> line packetizer path
// in FPGA fabric before the external DQ/DQS PHY is connected.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_ctrl_loopback_phy #(
    parameter integer LANES = 8,
    parameter integer ROW_BITS = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS = `DDR3_COL_BITS,
    parameter integer DEPTH_LOG2 = 8,
    localparam integer BANKS = (1 << BANK_BITS),
    localparam integer COL_LINE_BITS = COL_BITS - 3,
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS,
    localparam integer LINE_DATA_W = LANES * 64,
    localparam integer PHY_DATA_W = LANES * 8,
    localparam integer DEPTH = (1 << DEPTH_LOG2)
) (
    input  wire                      i_clk,
    input  wire                      i_rst,

    input  wire                      i_cmd_valid,
    input  wire                      i_cs_n,
    input  wire                      i_ras_n,
    input  wire                      i_cas_n,
    input  wire                      i_we_n,
    input  wire [BANK_BITS-1:0]      i_ba,
    input  wire [ROW_BITS-1:0]       i_addr,

    input  wire [LANES-1:0]          i_phy_wr_valid,
    output wire [LANES-1:0]          o_phy_wr_ready,
    input  wire [PHY_DATA_W-1:0]     i_phy_wr_data,
    input  wire [LANES-1:0]          i_phy_wr_mask,
    input  wire [LANES-1:0]          i_phy_wr_last,

    input  wire [LANES-1:0]          i_phy_rd_ready,
    output wire [LANES-1:0]          o_phy_rd_valid,
    output wire [PHY_DATA_W-1:0]     o_phy_rd_data,

    output reg [31:0]                o_wr_count,
    output reg [31:0]                o_rd_count,
    output reg [LINE_ADDR_W-1:0]     o_last_line_addr
);
    reg [LINE_DATA_W-1:0] mem [0:DEPTH-1];
    reg [ROW_BITS-1:0] open_row [0:BANKS-1];

    reg wr_active;
    reg [2:0] wr_beat;
    reg [DEPTH_LOG2-1:0] wr_index;

    reg rd_active;
    reg [2:0] rd_beat;
    reg [LINE_DATA_W-1:0] rd_line;

    wire cmd_active = i_cmd_valid && !i_cs_n;
    wire cmd_act = cmd_active && !i_ras_n && i_cas_n && i_we_n;
    wire cmd_wr = cmd_active && i_ras_n && !i_cas_n && !i_we_n;
    wire cmd_rd = cmd_active && i_ras_n && !i_cas_n && i_we_n;

    wire [COL_LINE_BITS-1:0] cmd_col_line = i_addr[COL_BITS-1:3];
    wire [LINE_ADDR_W-1:0] cmd_line_addr =
        {i_ba, open_row[i_ba], cmd_col_line};
    wire [DEPTH_LOG2-1:0] cmd_index =
        cmd_line_addr[DEPTH_LOG2-1:0];

    wire wr_advance = wr_active && (&i_phy_wr_valid);
    wire rd_advance = rd_active && (&i_phy_rd_ready);

    assign o_phy_wr_ready = {LANES{wr_active}};
    assign o_phy_rd_valid = {LANES{rd_advance}};

    genvar lane;
    generate
        for (lane = 0; lane < LANES; lane = lane + 1) begin : gen_rd_data
            assign o_phy_rd_data[lane*8 +: 8] =
                rd_line[(lane * 64) + (rd_beat * 8) +: 8];
        end
    endgenerate

    integer bank_i;
    integer lane_i;
    always @(posedge i_clk) begin
        if (i_rst) begin
            for (bank_i = 0; bank_i < BANKS; bank_i = bank_i + 1)
                open_row[bank_i] <= {ROW_BITS{1'b0}};
            wr_active <= 1'b0;
            wr_beat <= 3'd0;
            wr_index <= {DEPTH_LOG2{1'b0}};
            rd_active <= 1'b0;
            rd_beat <= 3'd0;
            rd_line <= {LINE_DATA_W{1'b0}};
            o_wr_count <= 32'd0;
            o_rd_count <= 32'd0;
            o_last_line_addr <= {LINE_ADDR_W{1'b0}};
        end else begin
            if (cmd_act)
                open_row[i_ba] <= i_addr[ROW_BITS-1:0];

            if (cmd_wr && !wr_active) begin
                wr_active <= 1'b1;
                wr_beat <= 3'd0;
                wr_index <= cmd_index;
                o_last_line_addr <= cmd_line_addr;
            end

            if (cmd_rd && !rd_active) begin
                rd_active <= 1'b1;
                rd_beat <= 3'd0;
                rd_line <= mem[cmd_index];
                o_last_line_addr <= cmd_line_addr;
            end

            if (wr_advance) begin
                for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1) begin
                    if (!i_phy_wr_mask[lane_i])
                        mem[wr_index][(lane_i * 64) + (wr_beat * 8) +: 8] <=
                            i_phy_wr_data[lane_i * 8 +: 8];
                end

                if ((wr_beat == 3'd7) || (&i_phy_wr_last)) begin
                    wr_active <= 1'b0;
                    wr_beat <= 3'd0;
                    o_wr_count <= o_wr_count + 32'd1;
                end else begin
                    wr_beat <= wr_beat + 3'd1;
                end
            end

            if (rd_advance) begin
                if (rd_beat == 3'd7) begin
                    rd_active <= 1'b0;
                    rd_beat <= 3'd0;
                    o_rd_count <= o_rd_count + 32'd1;
                end else begin
                    rd_beat <= rd_beat + 3'd1;
                end
            end
        end
    end
endmodule

`default_nettype wire
