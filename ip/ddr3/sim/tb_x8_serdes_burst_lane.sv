`default_nettype none
`timescale 1ns/1ps

module tb_x8_serdes_burst_lane;
    reg clk = 1'b0;
    reg rst = 1'b1;

    reg         wr_valid = 1'b0;
    wire        wr_ready;
    reg  [63:0] wr_data = 64'd0;
    wire        wr_loaded;

    reg         start_write = 1'b0;
    reg         start_read = 1'b0;
    wire        busy;
    wire        error;

    wire [63:0] serdes_dq_bits;
    wire [7:0]  serdes_dqs_bits;
    wire [3:0]  serdes_dq_oe;
    wire [3:0]  serdes_dqs_oe;
    reg  [63:0] serdes_dq_in = 64'd0;

    wire        rd_valid;
    reg         rd_ready = 1'b0;
    wire [63:0] rd_data;

    reg [63:0] expected_write = 64'hf7_e6_d5_c4_b3_a2_91_80;
    reg [63:0] expected_read = 64'h77_66_55_44_33_22_11_00;

    always #5 clk = ~clk;

    ddr3_x8_serdes_burst_lane #(
        .WRITE_LATENCY(2),
        .READ_LATENCY(2)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_valid(wr_valid),
        .o_wr_ready(wr_ready),
        .i_wr_data(wr_data),
        .o_wr_loaded(wr_loaded),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .o_busy(busy),
        .o_error(error),
        .o_serdes_dq_bits(serdes_dq_bits),
        .o_serdes_dqs_bits(serdes_dqs_bits),
        .o_serdes_dq_oe(serdes_dq_oe),
        .o_serdes_dqs_oe(serdes_dqs_oe),
        .i_serdes_dq_bits(serdes_dq_in),
        .o_rd_valid(rd_valid),
        .i_rd_ready(rd_ready),
        .o_rd_data(rd_data)
    );

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (!wr_ready || wr_loaded || busy || error || rd_valid) begin
            $display("[x8-serdes-lane] unexpected reset state");
            $fatal(1);
        end

        @(negedge clk);
        wr_data = expected_write;
        wr_valid = 1'b1;
        @(posedge clk);
        if (!wr_ready) begin
            $display("[x8-serdes-lane] write payload was not accepted");
            $fatal(1);
        end
        @(negedge clk);
        wr_valid = 1'b0;

        @(posedge clk);
        #1;
        if (!wr_loaded || wr_ready) begin
            $display("[x8-serdes-lane] write burst did not preload");
            $fatal(1);
        end

        @(negedge clk);
        start_write = 1'b1;
        @(negedge clk);
        start_write = 1'b0;

        wait (serdes_dqs_oe && !serdes_dq_oe);
        #1;
        if ((serdes_dqs_oe !== 4'hf) || (serdes_dq_oe !== 4'h0) ||
            (serdes_dqs_bits !== 8'h00)) begin
            $display("[x8-serdes-lane] write preamble mismatch");
            $fatal(1);
        end

        @(posedge clk);
        #1;
        if ((serdes_dqs_oe !== 4'hf) || (serdes_dq_oe !== 4'hf) ||
            (serdes_dqs_bits !== 8'b0101_0101) ||
            (serdes_dq_bits !== expected_write)) begin
            $display("[x8-serdes-lane] write data cycle mismatch");
            $fatal(1);
        end

        @(posedge clk);
        #1;
        if ((serdes_dqs_oe !== 4'hf) || (serdes_dq_oe !== 4'h0) ||
            (serdes_dqs_bits !== 8'h00)) begin
            $display("[x8-serdes-lane] write postamble mismatch");
            $fatal(1);
        end

        @(posedge clk);
        #1;
        if (wr_loaded || busy || error || !wr_ready) begin
            $display("[x8-serdes-lane] write path did not return idle");
            $fatal(1);
        end

        @(negedge clk);
        start_read = 1'b1;
        @(negedge clk);
        start_read = 1'b0;

        @(negedge clk);
        serdes_dq_in = expected_read;
        wait (rd_valid);
        #1;
        if (rd_data !== expected_read) begin
            $display("[x8-serdes-lane] read mismatch got=%016x expected=%016x",
                     rd_data, expected_read);
            $fatal(1);
        end

        @(negedge clk);
        rd_ready = 1'b1;
        @(negedge clk);
        rd_ready = 1'b0;

        @(posedge clk);
        #1;
        if (rd_valid || busy || error || !wr_ready) begin
            $display("[x8-serdes-lane] read path did not return idle");
            $fatal(1);
        end

        $display("[x8-serdes-lane] PASS");
        $finish;
    end
endmodule

`default_nettype wire
