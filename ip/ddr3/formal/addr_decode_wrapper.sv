// Formal harness for the Bonetto full-capacity DDR3 address map.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_addr_decode_wrapper;
    localparam integer CHANNELS = 2;
    localparam integer WORD_INDEX_BITS = 4;
    localparam integer CHANNEL_BITS = 1;
    localparam integer COL_LINE_BITS = `DDR3_COL_BITS - 3;
    localparam integer LINE_ADDR_W = `DDR3_BANK_BITS + `DDR3_ROW_BITS + COL_LINE_BITS;
    localparam integer LOCAL_WORD_ADDR_W = LINE_ADDR_W + WORD_INDEX_BITS;
    localparam integer GLOBAL_WORD_ADDR_W = CHANNEL_BITS + LOCAL_WORD_ADDR_W;

    (* anyseq *) wire [GLOBAL_WORD_ADDR_W-1:0] addr_a;
    (* anyseq *) wire [GLOBAL_WORD_ADDR_W-1:0] addr_b;

    wire [CHANNEL_BITS-1:0] channel_a;
    wire [LOCAL_WORD_ADDR_W-1:0] local_a;
    wire [LINE_ADDR_W-1:0] line_a;
    wire [WORD_INDEX_BITS-1:0] word_a;
    wire [`DDR3_BANK_BITS-1:0] bank_a;
    wire [`DDR3_ROW_BITS-1:0] row_a;
    wire [COL_LINE_BITS-1:0] col_line_a;
    wire [`DDR3_COL_BITS-1:0] col_a;

    wire [CHANNEL_BITS-1:0] channel_b;
    wire [LOCAL_WORD_ADDR_W-1:0] local_b;
    wire [LINE_ADDR_W-1:0] line_b;
    wire [WORD_INDEX_BITS-1:0] word_b;
    wire [`DDR3_BANK_BITS-1:0] bank_b;
    wire [`DDR3_ROW_BITS-1:0] row_b;
    wire [COL_LINE_BITS-1:0] col_line_b;
    wire [`DDR3_COL_BITS-1:0] col_b;

    ddr3_addr_decode #(
        .CHANNELS(CHANNELS),
        .WORD_INDEX_BITS(WORD_INDEX_BITS)
    ) dec_a (
        .i_word_addr(addr_a),
        .o_channel(channel_a),
        .o_local_word_addr(local_a),
        .o_line_addr(line_a),
        .o_word_index(word_a),
        .o_bank(bank_a),
        .o_row(row_a),
        .o_col_line(col_line_a),
        .o_col(col_a)
    );

    ddr3_addr_decode #(
        .CHANNELS(CHANNELS),
        .WORD_INDEX_BITS(WORD_INDEX_BITS)
    ) dec_b (
        .i_word_addr(addr_b),
        .o_channel(channel_b),
        .o_local_word_addr(local_b),
        .o_line_addr(line_b),
        .o_word_index(word_b),
        .o_bank(bank_b),
        .o_row(row_b),
        .o_col_line(col_line_b),
        .o_col(col_b)
    );

`ifdef FORMAL
    wire [GLOBAL_WORD_ADDR_W-1:0] repacked_a =
        {channel_a, bank_a, row_a, col_line_a, word_a};
    wire [GLOBAL_WORD_ADDR_W-1:0] repacked_b =
        {channel_b, bank_b, row_b, col_line_b, word_b};

    always @(*) begin
        assert(GLOBAL_WORD_ADDR_W == 30);
        assert(LOCAL_WORD_ADDR_W == 29);
        assert(LINE_ADDR_W == 25);

        assert(channel_a == addr_a[29]);
        assert(local_a == addr_a[28:0]);
        assert(bank_a == addr_a[28:26]);
        assert(row_a == addr_a[25:11]);
        assert(col_line_a == addr_a[10:4]);
        assert(word_a == addr_a[3:0]);
        assert(col_a == {col_line_a, 3'b000});
        assert(col_a[2:0] == 3'b000);
        assert(line_a == addr_a[28:4]);
        assert(repacked_a == addr_a);

        assert(channel_b == addr_b[29]);
        assert(local_b == addr_b[28:0]);
        assert(bank_b == addr_b[28:26]);
        assert(row_b == addr_b[25:11]);
        assert(col_line_b == addr_b[10:4]);
        assert(word_b == addr_b[3:0]);
        assert(col_b == {col_line_b, 3'b000});
        assert(col_b[2:0] == 3'b000);
        assert(line_b == addr_b[28:4]);
        assert(repacked_b == addr_b);

        if ((channel_a == channel_b) && (line_a == line_b) && (word_a == word_b))
            assert(addr_a == addr_b);

        if ((channel_a != channel_b) && (local_a == local_b))
            assert(line_a == line_b);
    end
`endif
endmodule

`default_nettype wire
