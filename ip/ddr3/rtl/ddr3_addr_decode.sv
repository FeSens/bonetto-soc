// Full-capacity DDR3 global word-address decoder.
//
// The Bonetto DDR3 memory map exposes two 64-bit channels. One BL8 transfer on
// one channel moves 64 bytes, or sixteen 32-bit Wishbone words. The low four
// word-address bits therefore select the word inside that BL8 line; the
// remaining local bits select column, row, and bank.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_addr_decode #(
    parameter integer CHANNELS = 2,
    parameter integer WORD_INDEX_BITS = 4,
    localparam integer CHANNEL_BITS = (CHANNELS <= 1) ? 1 : $clog2(CHANNELS),
    localparam integer COL_LINE_BITS = `DDR3_COL_BITS - 3,
    localparam integer LINE_ADDR_W = `DDR3_BANK_BITS + `DDR3_ROW_BITS + COL_LINE_BITS,
    localparam integer LOCAL_WORD_ADDR_W = LINE_ADDR_W + WORD_INDEX_BITS,
    localparam integer GLOBAL_WORD_ADDR_W = CHANNEL_BITS + LOCAL_WORD_ADDR_W
) (
    input wire [GLOBAL_WORD_ADDR_W-1:0] i_word_addr,

    output wire [CHANNEL_BITS-1:0]      o_channel,
    output wire [LOCAL_WORD_ADDR_W-1:0] o_local_word_addr,
    output wire [LINE_ADDR_W-1:0]       o_line_addr,
    output wire [WORD_INDEX_BITS-1:0]   o_word_index,
    output wire [`DDR3_BANK_BITS-1:0]   o_bank,
    output wire [`DDR3_ROW_BITS-1:0]    o_row,
    output wire [COL_LINE_BITS-1:0]     o_col_line,
    output wire [`DDR3_COL_BITS-1:0]    o_col
);
    assign o_channel = i_word_addr[GLOBAL_WORD_ADDR_W-1 -: CHANNEL_BITS];
    assign o_local_word_addr = i_word_addr[LOCAL_WORD_ADDR_W-1:0];

    assign o_word_index = o_local_word_addr[WORD_INDEX_BITS-1:0];
    assign o_col_line = o_local_word_addr[WORD_INDEX_BITS +: COL_LINE_BITS];
    assign o_row = o_local_word_addr[WORD_INDEX_BITS + COL_LINE_BITS +: `DDR3_ROW_BITS];
    assign o_bank = o_local_word_addr[LOCAL_WORD_ADDR_W-1 -: `DDR3_BANK_BITS];

    assign o_line_addr = {o_bank, o_row, o_col_line};
    assign o_col = {o_col_line, 3'b000};
endmodule

`default_nettype wire
