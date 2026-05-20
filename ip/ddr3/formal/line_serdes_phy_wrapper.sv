// Formal harness for the line-to-SERDES PHY boundary.

`default_nettype none

module ddr3_line_serdes_phy_wrapper (
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
    reg       f_saw_write_data = 1'b0;
    reg       f_saw_write_dqs = 1'b0;
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

    wire [(PHY_LANES*64)-1:0] serdes_dq_bits;
    wire [(PHY_LANES*8)-1:0] serdes_dqs_bits;
    wire [(PHY_LANES*4)-1:0] serdes_dq_oe;
    wire [(PHY_LANES*4)-1:0] serdes_dqs_oe;
    wire [(PHY_LANES*64)-1:0] serdes_dq_in = F_RD_DATA;

    ddr3_line_serdes_phy #(
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
        .o_serdes_dq_bits(serdes_dq_bits),
        .o_serdes_dqs_bits(serdes_dqs_bits),
        .o_serdes_dq_oe(serdes_dq_oe),
        .o_serdes_dqs_oe(serdes_dqs_oe),
        .i_serdes_dq_bits(serdes_dq_in)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 7'd0;
            f_saw_write_data <= 1'b0;
            f_saw_write_dqs <= 1'b0;
            f_saw_read_line <= 1'b0;
        end else begin
            if (f_cycle != 7'd127)
                f_cycle <= f_cycle + 7'd1;

            assert(error == {CHANNELS{1'b0}});
            assert(rd_line_err == {CHANNELS{1'b0}});

            if (wr_line_valid[0])
                assert(wr_line_ready[0]);

            if (|serdes_dqs_oe[0 +: 4]) begin
                assert(serdes_dqs_oe[0 +: 4] == 4'hf);
                f_saw_write_dqs <= 1'b1;
            end

            if (|serdes_dq_oe[0 +: 4]) begin
                assert(serdes_dq_oe[0 +: 4] == 4'hf);
                assert(serdes_dqs_oe[0 +: 4] == 4'hf);
                assert(serdes_dqs_bits[0 +: 8] == 8'b0101_0101);
                assert(serdes_dq_bits[0 +: 64] == F_WR_DATA);
                f_saw_write_data <= 1'b1;
            end

            if (rd_line_valid[0]) begin
                assert(rd_line_data[0 +: LINE_DATA_W] == F_RD_DATA);
                f_saw_read_line <= 1'b1;
            end

            if (f_cycle == 7'd80) begin
                assert(f_saw_write_dqs);
                assert(f_saw_write_data);
                assert(f_saw_read_line);
            end

            cover(|serdes_dq_oe[0 +: 4]);
            cover(rd_line_valid[0]);
        end
    end
`endif
endmodule

`default_nettype wire
