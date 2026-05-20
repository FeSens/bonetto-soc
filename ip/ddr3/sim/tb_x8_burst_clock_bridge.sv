`default_nettype none
`timescale 1ps/1ps

module tb_x8_burst_clock_bridge;
    reg ctrl_clk = 1'b0;
    reg phy_clk = 1'b0;
    reg ctrl_rst = 1'b1;
    reg phy_rst = 1'b1;

    always #10000 ctrl_clk = !ctrl_clk;
    always #1250 phy_clk = !phy_clk;

    reg         ctrl_wr_valid = 1'b0;
    wire        ctrl_wr_ready;
    reg  [63:0] ctrl_wr_data = 64'd0;
    reg  [7:0]  ctrl_wr_mask = 8'd0;
    reg         ctrl_start_write = 1'b0;
    reg         ctrl_start_read = 1'b0;
    reg         ctrl_rd_ready = 1'b1;
    wire        ctrl_rd_valid;
    wire [63:0] ctrl_rd_data;
    wire        ctrl_rd_err;
    wire        ctrl_error;
    wire        ctrl_busy;

    wire        phy_wr_valid;
    reg         phy_wr_ready = 1'b0;
    wire [63:0] phy_wr_data;
    wire [7:0]  phy_wr_mask;
    wire        phy_start_write;
    wire        phy_start_read;
    wire        phy_rd_ready;
    reg         phy_rd_valid = 1'b0;
    reg  [63:0] phy_rd_data = 64'd0;
    reg         phy_rd_err = 1'b0;
    wire        phy_error;
    wire        phy_busy;

    ddr3_x8_burst_clock_bridge dut (
        .i_ctrl_clk(ctrl_clk),
        .i_ctrl_rst(ctrl_rst),
        .i_phy_clk(phy_clk),
        .i_phy_rst(phy_rst),
        .i_ctrl_wr_valid(ctrl_wr_valid),
        .o_ctrl_wr_ready(ctrl_wr_ready),
        .i_ctrl_wr_data(ctrl_wr_data),
        .i_ctrl_wr_mask(ctrl_wr_mask),
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

    task ctrl_write_burst;
        input [63:0] data;
        input [7:0] mask;
        begin
            @(negedge ctrl_clk);
            ctrl_wr_data = data;
            ctrl_wr_mask = mask;
            ctrl_wr_valid = 1'b1;
            wait (ctrl_wr_ready);
            @(negedge ctrl_clk);
            ctrl_wr_valid = 1'b0;
        end
    endtask

    task expect_phy_write_burst;
        input [63:0] data;
        input [7:0] mask;
        begin
            wait (phy_wr_valid);
            repeat (3) @(posedge phy_clk);
            if (phy_wr_data !== data || phy_wr_mask !== mask) begin
                $display("[x8-burst-cdc] write payload changed under backpressure");
                $fatal(1);
            end
            phy_wr_ready = 1'b1;
            @(posedge phy_clk);
            phy_wr_ready = 1'b0;
        end
    endtask

    task pulse_ctrl_start_write;
        begin
            @(negedge ctrl_clk);
            ctrl_start_write = 1'b1;
            @(negedge ctrl_clk);
            ctrl_start_write = 1'b0;
        end
    endtask

    task pulse_ctrl_start_read;
        begin
            @(negedge ctrl_clk);
            ctrl_start_read = 1'b1;
            @(negedge ctrl_clk);
            ctrl_start_read = 1'b0;
        end
    endtask

    task expect_phy_start;
        input write;
        integer timeout;
        begin
            timeout = 0;
            while (((write && !phy_start_write) ||
                    (!write && !phy_start_read)) && timeout < 80) begin
                timeout = timeout + 1;
                @(posedge phy_clk);
            end
            if (timeout >= 80) begin
                $display("[x8-burst-cdc] missing %s start",
                         write ? "write" : "read");
                $fatal(1);
            end
        end
    endtask

    task phy_return_burst;
        input [63:0] data;
        input err;
        begin
            wait (phy_rd_ready);
            @(negedge phy_clk);
            phy_rd_data = data;
            phy_rd_err = err;
            phy_rd_valid = 1'b1;
            @(negedge phy_clk);
            phy_rd_valid = 1'b0;
            phy_rd_err = 1'b0;
        end
    endtask

    task expect_ctrl_read_burst;
        input [63:0] data;
        input err;
        begin
            wait (ctrl_rd_valid);
            if (ctrl_rd_data !== data || ctrl_rd_err !== err) begin
                $display("[x8-burst-cdc] read payload mismatch");
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
            ctrl_write_burst(64'h0011_2233_4455_6677, 8'b1010_0101);
            expect_phy_write_burst(64'h0011_2233_4455_6677, 8'b1010_0101);
        join

        fork
            begin
                pulse_ctrl_start_write();
                expect_phy_start(1'b1);
            end
            begin
                repeat (8) @(posedge ctrl_clk);
                pulse_ctrl_start_read();
                expect_phy_start(1'b0);
            end
        join

        fork
            phy_return_burst(64'hf0e1_d2c3_b4a5_9687, 1'b0);
            expect_ctrl_read_burst(64'hf0e1_d2c3_b4a5_9687, 1'b0);
        join

        repeat (20) @(posedge ctrl_clk);
        if (ctrl_error || phy_error) begin
            $display("[x8-burst-cdc] unexpected error ctrl=%0b phy=%0b",
                     ctrl_error, phy_error);
            $fatal(1);
        end
        if (ctrl_busy || phy_busy) begin
            $display("[x8-burst-cdc] bridge still busy ctrl=%0b phy=%0b",
                     ctrl_busy, phy_busy);
            $fatal(1);
        end

        $display("[x8-burst-cdc] dual-clock x8 burst bridge passed");
        $finish;
    end

    initial begin
        repeat (200) @(posedge ctrl_clk);
        $display("[x8-burst-cdc] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire
