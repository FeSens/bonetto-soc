// Formal protocol harness for the controller-to-PHY line clock bridge.
//
// This proof ties both bridge clocks to one formal clock. It does not model
// metastability; the bridge implementation uses toggle synchronizers for that.
// The property focus here is payload integrity, single-outstanding handshakes,
// read-response return, and no spurious error flags under a legal environment.

`default_nettype none

module ddr3_line_phy_clock_bridge_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 1;
    localparam integer LINE_DATA_W = 64;
    localparam integer LINE_BYTES = 8;

    localparam [LINE_DATA_W-1:0] F_WR_DATA = 64'h0123_4567_89ab_cdef;
    localparam [LINE_BYTES-1:0]  F_WR_MASK = 8'b0101_1010;
    localparam [LINE_DATA_W-1:0] F_RD_DATA = 64'hf0e1_d2c3_b4a5_9687;

    reg [5:0] f_cycle = 6'd0;
    reg       f_phy_rd_pending = 1'b0;
    reg       f_saw_phy_write = 1'b0;
    reg       f_saw_start_write = 1'b0;
    reg       f_saw_start_read = 1'b0;
    reg       f_saw_ctrl_read = 1'b0;
    reg       f_past_valid = 1'b0;

    wire [CHANNELS-1:0] ctrl_wr_line_valid = (f_cycle == 6'd1);
    wire [CHANNELS-1:0] ctrl_start_write = (f_cycle == 6'd8);
    wire [CHANNELS-1:0] ctrl_start_read = (f_cycle == 6'd14);
    wire [CHANNELS-1:0] ctrl_rd_line_ready = {CHANNELS{1'b1}};

    wire [CHANNELS-1:0] ctrl_wr_line_ready;
    wire [CHANNELS-1:0] ctrl_rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] ctrl_rd_line_data;
    wire [CHANNELS-1:0] ctrl_rd_line_err;
    wire [CHANNELS-1:0] ctrl_error;
    wire [CHANNELS-1:0] ctrl_busy;

    wire [CHANNELS-1:0] phy_wr_line_valid;
    wire [CHANNELS-1:0] phy_wr_line_ready = {CHANNELS{1'b1}};
    wire [(CHANNELS*LINE_DATA_W)-1:0] phy_wr_line_data;
    wire [(CHANNELS*LINE_BYTES)-1:0] phy_wr_line_mask;
    wire [CHANNELS-1:0] phy_start_write;
    wire [CHANNELS-1:0] phy_start_read;
    wire [CHANNELS-1:0] phy_rd_line_ready;
    wire [CHANNELS-1:0] phy_rd_line_valid =
        f_phy_rd_pending ? phy_rd_line_ready : {CHANNELS{1'b0}};
    wire [(CHANNELS*LINE_DATA_W)-1:0] phy_rd_line_data = F_RD_DATA;
    wire [CHANNELS-1:0] phy_rd_line_err = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] phy_error;
    wire [CHANNELS-1:0] phy_busy;

    ddr3_line_phy_clock_bridge #(
        .CHANNELS(CHANNELS),
        .LINE_DATA_W(LINE_DATA_W),
        .LINE_BYTES(LINE_BYTES)
    ) dut (
        .i_ctrl_clk(clk),
        .i_ctrl_rst(rst),
        .i_phy_clk(clk),
        .i_phy_rst(rst),
        .i_ctrl_wr_line_valid(ctrl_wr_line_valid),
        .o_ctrl_wr_line_ready(ctrl_wr_line_ready),
        .i_ctrl_wr_line_data(F_WR_DATA),
        .i_ctrl_wr_line_mask(F_WR_MASK),
        .i_ctrl_start_write(ctrl_start_write),
        .i_ctrl_start_read(ctrl_start_read),
        .i_ctrl_rd_line_ready(ctrl_rd_line_ready),
        .o_ctrl_rd_line_valid(ctrl_rd_line_valid),
        .o_ctrl_rd_line_data(ctrl_rd_line_data),
        .o_ctrl_rd_line_err(ctrl_rd_line_err),
        .o_ctrl_error(ctrl_error),
        .o_ctrl_busy(ctrl_busy),
        .o_phy_wr_line_valid(phy_wr_line_valid),
        .i_phy_wr_line_ready(phy_wr_line_ready),
        .o_phy_wr_line_data(phy_wr_line_data),
        .o_phy_wr_line_mask(phy_wr_line_mask),
        .o_phy_start_write(phy_start_write),
        .o_phy_start_read(phy_start_read),
        .o_phy_rd_line_ready(phy_rd_line_ready),
        .i_phy_rd_line_valid(phy_rd_line_valid),
        .i_phy_rd_line_data(phy_rd_line_data),
        .i_phy_rd_line_err(phy_rd_line_err),
        .o_phy_error(phy_error),
        .o_phy_busy(phy_busy)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 6'd0;
            f_phy_rd_pending <= 1'b0;
            f_saw_phy_write <= 1'b0;
            f_saw_start_write <= 1'b0;
            f_saw_start_read <= 1'b0;
            f_saw_ctrl_read <= 1'b0;
        end else begin
            if (f_cycle != 6'd63)
                f_cycle <= f_cycle + 6'd1;

            assert(ctrl_error == {CHANNELS{1'b0}});
            assert(phy_error == {CHANNELS{1'b0}});
            assert(ctrl_rd_line_err == {CHANNELS{1'b0}});

            if (ctrl_wr_line_valid[0])
                assert(ctrl_wr_line_ready[0]);

            if (phy_wr_line_valid[0]) begin
                assert(phy_wr_line_data[0 +: LINE_DATA_W] == F_WR_DATA);
                assert(phy_wr_line_mask[0 +: LINE_BYTES] == F_WR_MASK);
                f_saw_phy_write <= 1'b1;
            end

            if (phy_start_write[0]) begin
                assert(f_saw_phy_write);
                f_saw_start_write <= 1'b1;
            end

            if (phy_start_read[0]) begin
                f_saw_start_read <= 1'b1;
                f_phy_rd_pending <= 1'b1;
            end

            if (phy_rd_line_valid[0] && phy_rd_line_ready[0])
                f_phy_rd_pending <= 1'b0;

            if (ctrl_rd_line_valid[0]) begin
                assert(ctrl_rd_line_data[0 +: LINE_DATA_W] == F_RD_DATA);
                f_saw_ctrl_read <= 1'b1;
            end

            if (f_cycle == 6'd28) begin
                assert(f_saw_phy_write);
                assert(f_saw_start_write);
                assert(f_saw_start_read);
                assert(f_saw_ctrl_read);
            end

            cover(f_saw_phy_write && f_saw_start_write &&
                  f_saw_start_read && f_saw_ctrl_read);
            cover(ctrl_busy == {CHANNELS{1'b0}} &&
                  phy_busy == {CHANNELS{1'b0}} &&
                  f_saw_ctrl_read);
        end
    end
`endif
endmodule

`default_nettype wire
