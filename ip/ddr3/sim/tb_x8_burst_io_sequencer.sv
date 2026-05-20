`default_nettype none
`timescale 1ns/1ps

module tb_x8_burst_io_sequencer;
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

    wire        dq_oe;
    wire        dqs_oe;
    wire [7:0]  dq_rise;
    wire [7:0]  dq_fall;
    wire        dqs_rise;
    wire        dqs_fall;

    wire        rd_capturing;
    reg         rd_sample_valid = 1'b0;
    reg  [7:0]  dq_in_rise = 8'h00;
    reg  [7:0]  dq_in_fall = 8'h00;
    wire        rd_valid;
    reg         rd_ready = 1'b0;
    wire [63:0] rd_data;

    integer pair;
    reg [63:0] expected_write = 64'hf7_e6_d5_c4_b3_a2_91_80;
    reg [63:0] expected_read = 64'h77_66_55_44_33_22_11_00;

    always #5 clk = ~clk;

    ddr3_x8_burst_io_sequencer #(
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
        .o_dq_oe(dq_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_rise),
        .o_dq_fall(dq_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_in_rise),
        .i_dq_fall(dq_in_fall),
        .o_rd_valid(rd_valid),
        .i_rd_ready(rd_ready),
        .o_rd_data(rd_data)
    );

    task expect_write_pair;
        input integer pair_index;
        reg [7:0] expected_rise;
        reg [7:0] expected_fall;
        begin
            expected_rise = expected_write[(pair_index * 16) +: 8];
            expected_fall = expected_write[(pair_index * 16) + 8 +: 8];

            @(posedge clk);
            #1;
            if (!dq_oe || !dqs_oe) begin
                $display("[x8-burst-io] missing output enable on pair %0d",
                         pair_index);
                $fatal(1);
            end
            if ((dq_rise !== expected_rise) || (dq_fall !== expected_fall)) begin
                $display("[x8-burst-io] write pair %0d mismatch rise=%02x fall=%02x",
                         pair_index, dq_rise, dq_fall);
                $fatal(1);
            end
            if ((dqs_rise !== 1'b1) || (dqs_fall !== 1'b0)) begin
                $display("[x8-burst-io] DQS data toggle mismatch");
                $fatal(1);
            end
        end
    endtask

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (!wr_ready || wr_loaded || busy || error || rd_valid) begin
            $display("[x8-burst-io] unexpected reset state");
            $fatal(1);
        end

        @(negedge clk);
        wr_data = expected_write;
        wr_valid = 1'b1;
        @(posedge clk);
        if (!wr_ready) begin
            $display("[x8-burst-io] write payload was not accepted");
            $fatal(1);
        end
        @(negedge clk);
        wr_valid = 1'b0;

        @(posedge clk);
        #1;
        if (!wr_loaded || wr_ready) begin
            $display("[x8-burst-io] write burst did not preload");
            $fatal(1);
        end

        @(negedge clk);
        start_write = 1'b1;
        @(negedge clk);
        start_write = 1'b0;

        wait (dqs_oe && !dq_oe);
        if (!dqs_oe || dq_oe || dqs_rise || dqs_fall) begin
            $display("[x8-burst-io] write preamble mismatch");
            $fatal(1);
        end

        for (pair = 0; pair < 4; pair = pair + 1)
            expect_write_pair(pair);

        @(posedge clk);
        #1;
        if (!dqs_oe || dq_oe || dqs_rise || dqs_fall) begin
            $display("[x8-burst-io] write postamble mismatch");
            $fatal(1);
        end

        @(posedge clk);
        #1;
        if (wr_loaded || busy || error || !wr_ready) begin
            $display("[x8-burst-io] write path did not return idle");
            $fatal(1);
        end

        @(negedge clk);
        start_read = 1'b1;
        @(negedge clk);
        start_read = 1'b0;

        wait (rd_capturing);
        for (pair = 0; pair < 4; pair = pair + 1) begin
            @(negedge clk);
            rd_sample_valid = 1'b1;
            dq_in_rise = expected_read[(pair * 16) +: 8];
            dq_in_fall = expected_read[(pair * 16) + 8 +: 8];
            @(negedge clk);
            rd_sample_valid = 1'b0;
        end

        wait (rd_valid);
        #1;
        if (rd_data !== expected_read) begin
            $display("[x8-burst-io] read burst mismatch got=%016x expected=%016x",
                     rd_data, expected_read);
            $fatal(1);
        end

        @(negedge clk);
        rd_ready = 1'b1;
        @(negedge clk);
        rd_ready = 1'b0;

        @(posedge clk);
        #1;
        if (busy || error || rd_valid || !wr_ready) begin
            $display("[x8-burst-io] read path did not return idle");
            $fatal(1);
        end

        $display("[x8-burst-io] x8 fast burst I/O sequencer passed");
        $finish;
    end
endmodule

`default_nettype wire
