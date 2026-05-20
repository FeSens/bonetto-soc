// Formal protocol harness for the x8 burst clock bridge.
//
// This ties both clocks to one formal clock. The implementation uses toggle
// synchronizers for the real CDC path; this proof focuses on legal
// single-outstanding protocol, payload integrity, read return, and no spurious
// error flags.

`default_nettype none

module ddr3_x8_burst_clock_bridge_wrapper (
    input wire clk,
    input wire rst
);
    localparam [63:0] F_WR_DATA = 64'h0123_4567_89ab_cdef;
    localparam [7:0]  F_WR_MASK = 8'b0101_1010;
    localparam [63:0] F_RD_DATA = 64'hf0e1_d2c3_b4a5_9687;

    reg [5:0] f_cycle = 6'd0;
    reg       f_phy_rd_pending = 1'b0;
    reg       f_saw_phy_write = 1'b0;
    reg       f_saw_start_write = 1'b0;
    reg       f_saw_start_read = 1'b0;
    reg       f_saw_ctrl_read = 1'b0;
    reg       f_past_valid = 1'b0;

    wire ctrl_wr_valid = (f_cycle == 6'd1);
    wire ctrl_start_write = (f_cycle == 6'd8);
    wire ctrl_start_read = (f_cycle == 6'd14);
    wire ctrl_rd_ready = 1'b1;

    wire        ctrl_wr_ready;
    wire        ctrl_rd_valid;
    wire [63:0] ctrl_rd_data;
    wire        ctrl_rd_err;
    wire        ctrl_error;
    wire        ctrl_busy;

    wire        phy_wr_valid;
    wire        phy_wr_ready = 1'b1;
    wire [63:0] phy_wr_data;
    wire [7:0]  phy_wr_mask;
    wire        phy_start_write;
    wire        phy_start_read;
    wire        phy_rd_ready;
    wire        phy_rd_valid = f_phy_rd_pending ? phy_rd_ready : 1'b0;
    wire [63:0] phy_rd_data = F_RD_DATA;
    wire        phy_rd_err = 1'b0;
    wire        phy_error;
    wire        phy_busy;

    ddr3_x8_burst_clock_bridge dut (
        .i_ctrl_clk(clk),
        .i_ctrl_rst(rst),
        .i_phy_clk(clk),
        .i_phy_rst(rst),
        .i_ctrl_wr_valid(ctrl_wr_valid),
        .o_ctrl_wr_ready(ctrl_wr_ready),
        .i_ctrl_wr_data(F_WR_DATA),
        .i_ctrl_wr_mask(F_WR_MASK),
        .i_ctrl_start_write(ctrl_start_write),
        .i_ctrl_start_read(ctrl_start_read),
        .i_ctrl_rd_ready(ctrl_rd_ready),
        .o_ctrl_rd_valid(ctrl_rd_valid),
        .o_ctrl_rd_data(ctrl_rd_data),
        .o_ctrl_rd_err(ctrl_rd_err),
        .o_ctrl_error(ctrl_error),
        .o_ctrl_busy(ctrl_busy),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_start_write(phy_start_write),
        .o_phy_start_read(phy_start_read),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data),
        .i_phy_rd_err(phy_rd_err),
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

            assert(!ctrl_error);
            assert(!phy_error);
            assert(!ctrl_rd_err);

            if (ctrl_wr_valid)
                assert(ctrl_wr_ready);

            if (phy_wr_valid) begin
                assert(phy_wr_data == F_WR_DATA);
                assert(phy_wr_mask == F_WR_MASK);
                f_saw_phy_write <= 1'b1;
            end

            if (phy_start_write) begin
                assert(f_saw_phy_write);
                f_saw_start_write <= 1'b1;
            end

            if (phy_start_read) begin
                f_saw_start_read <= 1'b1;
                f_phy_rd_pending <= 1'b1;
            end

            if (phy_rd_valid && phy_rd_ready)
                f_phy_rd_pending <= 1'b0;

            if (ctrl_rd_valid) begin
                assert(ctrl_rd_data == F_RD_DATA);
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
            cover(!ctrl_busy && !phy_busy && f_saw_ctrl_read);
        end
    end
`endif
endmodule

`default_nettype wire
