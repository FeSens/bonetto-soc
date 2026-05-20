`default_nettype none
`timescale 1ps/1ps

module tb_line_phy_clock_bridge;
    localparam integer CHANNELS = 2;
    localparam integer LINE_DATA_W = 128;
    localparam integer LINE_BYTES = 16;

    reg ctrl_clk = 1'b0;
    reg phy_clk = 1'b0;
    reg ctrl_rst = 1'b1;
    reg phy_rst = 1'b1;

    always #10000 ctrl_clk = !ctrl_clk;
    always #1250 phy_clk = !phy_clk;

    reg [CHANNELS-1:0] ctrl_wr_valid = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] ctrl_wr_ready;
    reg [CHANNELS*LINE_DATA_W-1:0] ctrl_wr_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [CHANNELS*LINE_BYTES-1:0] ctrl_wr_mask =
        {(CHANNELS*LINE_BYTES){1'b0}};
    reg [CHANNELS-1:0] ctrl_start_write = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] ctrl_start_read = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] ctrl_rd_ready = {CHANNELS{1'b1}};
    wire [CHANNELS-1:0] ctrl_rd_valid;
    wire [CHANNELS*LINE_DATA_W-1:0] ctrl_rd_data;
    wire [CHANNELS-1:0] ctrl_rd_err;
    wire [CHANNELS-1:0] ctrl_error;
    wire [CHANNELS-1:0] ctrl_busy;

    wire [CHANNELS-1:0] phy_wr_valid;
    reg [CHANNELS-1:0] phy_wr_ready = {CHANNELS{1'b1}};
    wire [CHANNELS*LINE_DATA_W-1:0] phy_wr_data;
    wire [CHANNELS*LINE_BYTES-1:0] phy_wr_mask;
    wire [CHANNELS-1:0] phy_start_write;
    wire [CHANNELS-1:0] phy_start_read;
    wire [CHANNELS-1:0] phy_rd_ready;
    reg [CHANNELS-1:0] phy_rd_valid = {CHANNELS{1'b0}};
    reg [CHANNELS*LINE_DATA_W-1:0] phy_rd_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [CHANNELS-1:0] phy_rd_err = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] phy_error;
    wire [CHANNELS-1:0] phy_busy;

    ddr3_line_phy_clock_bridge #(
        .CHANNELS(CHANNELS),
        .LINE_DATA_W(LINE_DATA_W),
        .LINE_BYTES(LINE_BYTES)
    ) dut (
        .i_ctrl_clk(ctrl_clk),
        .i_ctrl_rst(ctrl_rst),
        .i_phy_clk(phy_clk),
        .i_phy_rst(phy_rst),
        .i_ctrl_wr_line_valid(ctrl_wr_valid),
        .o_ctrl_wr_line_ready(ctrl_wr_ready),
        .i_ctrl_wr_line_data(ctrl_wr_data),
        .i_ctrl_wr_line_mask(ctrl_wr_mask),
        .i_ctrl_start_write(ctrl_start_write),
        .i_ctrl_start_read(ctrl_start_read),
        .i_ctrl_rd_line_ready(ctrl_rd_ready),
        .o_ctrl_rd_line_valid(ctrl_rd_valid),
        .o_ctrl_rd_line_data(ctrl_rd_data),
        .o_ctrl_rd_line_err(ctrl_rd_err),
        .o_ctrl_error(ctrl_error),
        .o_ctrl_busy(ctrl_busy),
        .o_phy_wr_line_valid(phy_wr_valid),
        .i_phy_wr_line_ready(phy_wr_ready),
        .o_phy_wr_line_data(phy_wr_data),
        .o_phy_wr_line_mask(phy_wr_mask),
        .o_phy_start_write(phy_start_write),
        .o_phy_start_read(phy_start_read),
        .o_phy_rd_line_ready(phy_rd_ready),
        .i_phy_rd_line_valid(phy_rd_valid),
        .i_phy_rd_line_data(phy_rd_data),
        .i_phy_rd_line_err(phy_rd_err),
        .o_phy_error(phy_error),
        .o_phy_busy(phy_busy)
    );

    task ctrl_write_line;
        input integer ch;
        input [LINE_DATA_W-1:0] data;
        input [LINE_BYTES-1:0] mask;
        begin
            @(negedge ctrl_clk);
            ctrl_wr_data[ch*LINE_DATA_W +: LINE_DATA_W] = data;
            ctrl_wr_mask[ch*LINE_BYTES +: LINE_BYTES] = mask;
            ctrl_wr_valid[ch] = 1'b1;
            wait (ctrl_wr_ready[ch]);
            @(negedge ctrl_clk);
            ctrl_wr_valid[ch] = 1'b0;
        end
    endtask

    task expect_phy_write_line;
        input integer ch;
        input [LINE_DATA_W-1:0] data;
        input [LINE_BYTES-1:0] mask;
        begin
            wait (phy_wr_valid[ch]);
            if (phy_wr_data[ch*LINE_DATA_W +: LINE_DATA_W] !== data ||
                phy_wr_mask[ch*LINE_BYTES +: LINE_BYTES] !== mask) begin
                $display("[line-phy-cdc] write payload mismatch ch=%0d", ch);
                $fatal(1);
            end
            @(posedge phy_clk);
        end
    endtask

    task pulse_ctrl_start_write;
        input integer ch;
        begin
            @(negedge ctrl_clk);
            ctrl_start_write[ch] = 1'b1;
            @(negedge ctrl_clk);
            ctrl_start_write[ch] = 1'b0;
        end
    endtask

    task pulse_ctrl_start_read;
        input integer ch;
        begin
            @(negedge ctrl_clk);
            ctrl_start_read[ch] = 1'b1;
            @(negedge ctrl_clk);
            ctrl_start_read[ch] = 1'b0;
        end
    endtask

    task expect_phy_start;
        input integer ch;
        input write;
        integer timeout;
        begin
            timeout = 0;
            while (((write && !phy_start_write[ch]) ||
                    (!write && !phy_start_read[ch])) && timeout < 80) begin
                timeout = timeout + 1;
                @(posedge phy_clk);
            end
            if (timeout >= 80) begin
                $display("[line-phy-cdc] missing %s start ch=%0d",
                         write ? "write" : "read", ch);
                $fatal(1);
            end
        end
    endtask

    task phy_return_line;
        input integer ch;
        input [LINE_DATA_W-1:0] data;
        input err;
        begin
            wait (phy_rd_ready[ch]);
            @(negedge phy_clk);
            phy_rd_data[ch*LINE_DATA_W +: LINE_DATA_W] = data;
            phy_rd_err[ch] = err;
            phy_rd_valid[ch] = 1'b1;
            @(negedge phy_clk);
            phy_rd_valid[ch] = 1'b0;
            phy_rd_err[ch] = 1'b0;
        end
    endtask

    task expect_ctrl_read_line;
        input integer ch;
        input [LINE_DATA_W-1:0] data;
        input err;
        begin
            wait (ctrl_rd_valid[ch]);
            if (ctrl_rd_data[ch*LINE_DATA_W +: LINE_DATA_W] !== data ||
                ctrl_rd_err[ch] !== err) begin
                $display("[line-phy-cdc] read payload mismatch ch=%0d", ch);
                $fatal(1);
            end
            @(posedge ctrl_clk);
        end
    endtask

    initial begin
        repeat (5) @(posedge ctrl_clk);
        ctrl_rst = 1'b0;
        phy_rst = 1'b0;
        repeat (5) @(posedge ctrl_clk);

        fork
            ctrl_write_line(0, 128'h0011_2233_4455_6677_8899_aabb_ccdd_eeff,
                            16'h00f3);
            expect_phy_write_line(
                0, 128'h0011_2233_4455_6677_8899_aabb_ccdd_eeff, 16'h00f3);
        join

        fork
            begin
                pulse_ctrl_start_write(0);
                expect_phy_start(0, 1'b1);
            end
            begin
                pulse_ctrl_start_read(1);
                expect_phy_start(1, 1'b0);
            end
        join

        fork
            phy_return_line(1, 128'hf0e1_d2c3_b4a5_9687_7869_5a4b_3c2d_1e0f,
                            1'b0);
            expect_ctrl_read_line(
                1, 128'hf0e1_d2c3_b4a5_9687_7869_5a4b_3c2d_1e0f, 1'b0);
        join

        repeat (20) @(posedge ctrl_clk);
        if (ctrl_error || phy_error) begin
            $display("[line-phy-cdc] unexpected error ctrl=%b phy=%b",
                     ctrl_error, phy_error);
            $fatal(1);
        end
        if (ctrl_busy || phy_busy) begin
            $display("[line-phy-cdc] bridge still busy ctrl=%b phy=%b",
                     ctrl_busy, phy_busy);
            $fatal(1);
        end

        $display("[line-phy-cdc] dual-clock line PHY bridge passed");
        $finish;
    end
endmodule

`default_nettype wire
