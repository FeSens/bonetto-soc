// Synthesizable line-level DDR3 PHY loopback for board bring-up.
//
// This is still not a real DQ/DQS PHY. It consumes the clean controller's
// complete BL8 write-line contract, watches the scheduled RD/WR command stream,
// and returns complete BL8 read lines from a small internal memory. The purpose
// is to validate the live JTAG/Wishbone -> ddr3_ctrl_line -> scheduler ->
// line-level PHY boundary in FPGA fabric before external DQ/DQS is connected.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_line_loopback_phy #(
    parameter integer LANES = 8,
    parameter integer ROW_BITS = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS = `DDR3_COL_BITS,
    parameter integer DEPTH_LOG2 = 8,
    localparam integer BANKS = (1 << BANK_BITS),
    localparam integer COL_LINE_BITS = COL_BITS - 3,
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8,
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

    input  wire                      i_wr_line_valid,
    output wire                      o_wr_line_ready,
    input  wire [LINE_DATA_W-1:0]    i_wr_line_data,
    input  wire [LINE_BYTES-1:0]     i_wr_line_mask,

    input  wire                      i_rd_line_ready,
    output wire                      o_rd_line_valid,
    output wire [LINE_DATA_W-1:0]    o_rd_line_data,
    output wire                      o_rd_line_err,

    output reg [31:0]                o_wr_count,
    output reg [31:0]                o_rd_count,
    output reg [LINE_ADDR_W-1:0]     o_last_line_addr
);
    reg [LINE_DATA_W-1:0] mem [0:DEPTH-1];
    reg [ROW_BITS-1:0] open_row [0:BANKS-1];

    reg wr_buf_valid;
    reg [LINE_DATA_W-1:0] wr_buf_data;
    reg [LINE_BYTES-1:0] wr_buf_mask;

    reg rd_valid;
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

    wire wr_line_accept = i_wr_line_valid && o_wr_line_ready;
    wire wr_line_available = wr_buf_valid || wr_line_accept;
    wire [LINE_DATA_W-1:0] wr_line_data =
        wr_buf_valid ? wr_buf_data : i_wr_line_data;
    wire [LINE_BYTES-1:0] wr_line_mask =
        wr_buf_valid ? wr_buf_mask : i_wr_line_mask;

    assign o_wr_line_ready = !wr_buf_valid;
    assign o_rd_line_valid = rd_valid;
    assign o_rd_line_data = rd_line;
    assign o_rd_line_err = 1'b0;

    integer bank_i;
    integer byte_i;
    always @(posedge i_clk) begin
        if (i_rst) begin
            for (bank_i = 0; bank_i < BANKS; bank_i = bank_i + 1)
                open_row[bank_i] <= {ROW_BITS{1'b0}};
            wr_buf_valid <= 1'b0;
            wr_buf_data <= {LINE_DATA_W{1'b0}};
            wr_buf_mask <= {LINE_BYTES{1'b1}};
            rd_valid <= 1'b0;
            rd_line <= {LINE_DATA_W{1'b0}};
            o_wr_count <= 32'd0;
            o_rd_count <= 32'd0;
            o_last_line_addr <= {LINE_ADDR_W{1'b0}};
        end else begin
            if (cmd_act)
                open_row[i_ba] <= i_addr[ROW_BITS-1:0];

            if (wr_line_accept) begin
                wr_buf_valid <= 1'b1;
                wr_buf_data <= i_wr_line_data;
                wr_buf_mask <= i_wr_line_mask;
            end

            if (cmd_wr && wr_line_available) begin
                for (byte_i = 0; byte_i < LINE_BYTES; byte_i = byte_i + 1) begin
                    if (!wr_line_mask[byte_i])
                        mem[cmd_index][byte_i*8 +: 8] <=
                            wr_line_data[byte_i*8 +: 8];
                end

                wr_buf_valid <= 1'b0;
                o_wr_count <= o_wr_count + 32'd1;
                o_last_line_addr <= cmd_line_addr;
            end

            if (rd_valid && i_rd_line_ready) begin
                rd_valid <= 1'b0;
                o_rd_count <= o_rd_count + 32'd1;
            end

            if (cmd_rd) begin
                rd_valid <= 1'b1;
                rd_line <= mem[cmd_index];
                o_last_line_addr <= cmd_line_addr;
            end
        end
    end
endmodule

`default_nettype wire
