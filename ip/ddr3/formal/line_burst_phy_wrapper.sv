// Formal harness for the line-to-fast-burst PHY shell.

`default_nettype none

module ddr3_line_burst_phy_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 1;
    localparam integer LANES = 1;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam [LINE_DATA_W-1:0] F_WR_DATA = 64'h0123_4567_89ab_cdef;
    localparam [LINE_BYTES-1:0]  F_WR_MASK = 8'b0101_1010;
    localparam [LINE_DATA_W-1:0] F_RD_DATA = 64'hf0e1_d2c3_b4a5_9687;

    reg [6:0] f_cycle = 7'd0;
    reg [2:0] f_write_pair = 3'd0;
    reg       f_write_active = 1'b0;
    reg [2:0] f_read_pair = 3'd0;
    reg       f_saw_read_line = 1'b0;
    reg       f_past_valid = 1'b0;

    wire [CHANNELS-1:0] wr_line_valid = (f_cycle == 7'd1);
    wire [CHANNELS-1:0] start_write = (f_cycle == 7'd16);
    wire [CHANNELS-1:0] start_read = (f_cycle == 7'd36);
    wire [CHANNELS-1:0] rd_line_ready = {CHANNELS{1'b1}};

    wire [CHANNELS-1:0] wr_line_ready;
    wire [CHANNELS-1:0] wr_line_loaded;
    wire [CHANNELS-1:0] rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data;
    wire [CHANNELS-1:0] rd_line_err;
    wire [CHANNELS-1:0] error;
    wire [CHANNELS-1:0] busy;

    wire [PHY_LANES-1:0] dq_oe;
    wire [PHY_LANES-1:0] dqs_oe;
    wire [(PHY_LANES*8)-1:0] dq_rise;
    wire [(PHY_LANES*8)-1:0] dq_fall;
    wire [PHY_LANES-1:0] dqs_rise;
    wire [PHY_LANES-1:0] dqs_fall;
    wire [PHY_LANES-1:0] rd_capturing;
    wire [PHY_LANES-1:0] rd_sample_valid = rd_capturing;
    wire [5:0] f_read_base = (f_read_pair < 3'd4) ?
                              ({3'd0, f_read_pair} * 6'd16) : 6'd0;
    wire [(PHY_LANES*8)-1:0] dq_in_rise =
        F_RD_DATA[f_read_base +: 8];
    wire [(PHY_LANES*8)-1:0] dq_in_fall =
        F_RD_DATA[f_read_base + 6'd8 +: 8];

    ddr3_line_burst_phy #(
        .CHANNELS(CHANNELS),
        .LANES(LANES),
        .WRITE_LATENCY(2),
        .READ_LATENCY(2)
    ) dut (
        .i_ctrl_clk(clk),
        .i_ctrl_rst(rst),
        .i_phy_clk(clk),
        .i_phy_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .o_wr_line_loaded(wr_line_loaded),
        .i_wr_line_data(F_WR_DATA),
        .i_wr_line_mask(F_WR_MASK),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_error(error),
        .o_busy(busy),
        .o_dq_oe(dq_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_rise),
        .o_dq_fall(dq_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_in_rise),
        .i_dq_fall(dq_in_fall)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 7'd0;
            f_write_pair <= 3'd0;
            f_write_active <= 1'b0;
            f_read_pair <= 3'd0;
            f_saw_read_line <= 1'b0;
        end else begin
            if (f_cycle != 7'd127)
                f_cycle <= f_cycle + 7'd1;

            assert(error == {CHANNELS{1'b0}});
            assert(rd_line_err == {CHANNELS{1'b0}});

            if (wr_line_valid[0])
                assert(wr_line_ready[0]);

            if (start_write[0])
                f_write_active <= 1'b1;

            if (dq_oe[0]) begin
                assert(f_write_active);
                assert(f_write_pair < 3'd4);
                assert(dqs_oe[0]);
                assert(dqs_rise[0]);
                assert(!dqs_fall[0]);
                assert(dq_rise[0 +: 8] ==
                       F_WR_DATA[(f_write_pair * 16) +: 8]);
                assert(dq_fall[0 +: 8] ==
                       F_WR_DATA[(f_write_pair * 16) + 8 +: 8]);

                if (f_write_pair == 3'd3) begin
                    f_write_pair <= 3'd0;
                    f_write_active <= 1'b0;
                end else begin
                    f_write_pair <= f_write_pair + 3'd1;
                end
            end

            if (start_read[0])
                f_read_pair <= 3'd0;

            if (rd_capturing[0])
                f_read_pair <= f_read_pair + 3'd1;

            if (rd_line_valid[0]) begin
                assert(rd_line_data[0 +: LINE_DATA_W] == F_RD_DATA);
                f_saw_read_line <= 1'b1;
            end

            if (f_cycle == 7'd80)
                assert(f_saw_read_line);

            cover(dq_oe[0] && (f_write_pair == 3'd3));
            cover(rd_line_valid[0]);
        end
    end
`endif
endmodule

`default_nettype wire
