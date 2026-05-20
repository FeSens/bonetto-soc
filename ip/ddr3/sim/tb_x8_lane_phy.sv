`default_nettype none
`timescale 1ns/1ps

module tb_x8_lane_phy;
    reg clk = 1'b0;
    reg rst = 1'b1;

    reg        lane_wr_valid = 1'b0;
    wire       lane_wr_ready;
    reg [7:0]  lane_wr_data = 8'h00;
    reg        lane_wr_mask = 1'b1;
    reg        lane_wr_last = 1'b0;
    wire       wr_loaded;

    reg        start_write = 1'b0;
    reg        start_read = 1'b0;
    wire       busy;
    wire       error;

    wire       dq_oe;
    wire       dm_oe;
    wire       dqs_oe;
    wire [7:0] dq_rise;
    wire [7:0] dq_fall;
    wire       dm_rise;
    wire       dm_fall;
    wire       dqs_rise;
    wire       dqs_fall;

    wire       rd_capturing;
    reg        rd_sample_valid = 1'b0;
    reg [7:0]  dq_in_rise = 8'h00;
    reg [7:0]  dq_in_fall = 8'h00;
    wire       lane_rd_valid;
    reg        lane_rd_ready = 1'b1;
    wire [7:0] lane_rd_data;

    integer i;
    integer pair;
    integer got_reads;

    reg [7:0] wr_bytes [0:7];
    reg       wr_masks [0:7];
    reg [7:0] rd_bytes [0:7];

    always #5 clk = ~clk;

    ddr3_x8_lane_phy #(
        .WRITE_LATENCY(2),
        .READ_LATENCY(2)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_lane_wr_valid(lane_wr_valid),
        .o_lane_wr_ready(lane_wr_ready),
        .i_lane_wr_data(lane_wr_data),
        .i_lane_wr_mask(lane_wr_mask),
        .i_lane_wr_last(lane_wr_last),
        .o_wr_loaded(wr_loaded),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .o_busy(busy),
        .o_error(error),
        .o_dq_oe(dq_oe),
        .o_dm_oe(dm_oe),
        .o_dqs_oe(dqs_oe),
        .o_dq_rise(dq_rise),
        .o_dq_fall(dq_fall),
        .o_dm_rise(dm_rise),
        .o_dm_fall(dm_fall),
        .o_dqs_rise(dqs_rise),
        .o_dqs_fall(dqs_fall),
        .o_rd_capturing(rd_capturing),
        .i_rd_sample_valid(rd_sample_valid),
        .i_dq_rise(dq_in_rise),
        .i_dq_fall(dq_in_fall),
        .o_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_ready(lane_rd_ready),
        .o_lane_rd_data(lane_rd_data)
    );

    task drive_write_beat;
        input integer beat;
        begin
            @(negedge clk);
            lane_wr_valid = 1'b1;
            lane_wr_data = wr_bytes[beat];
            lane_wr_mask = wr_masks[beat];
            lane_wr_last = (beat == 7);
            @(posedge clk);
            if (!lane_wr_ready) begin
                $display("[x8-lane-phy] write beat %0d was not accepted", beat);
                $fatal(1);
            end
            @(negedge clk);
            lane_wr_valid = 1'b0;
            lane_wr_last = 1'b0;
        end
    endtask

    task expect_write_pair;
        input integer pair_index;
        begin
            @(posedge clk);
            #1;
            if (!dq_oe || !dm_oe || !dqs_oe) begin
                $display("[x8-lane-phy] missing output enable on pair %0d",
                         pair_index);
                $fatal(1);
            end
            if ((dq_rise !== wr_bytes[pair_index*2]) ||
                (dq_fall !== wr_bytes[(pair_index*2)+1])) begin
                $display("[x8-lane-phy] write data pair %0d mismatch rise=%02x fall=%02x",
                         pair_index, dq_rise, dq_fall);
                $fatal(1);
            end
            if ((dm_rise !== wr_masks[pair_index*2]) ||
                (dm_fall !== wr_masks[(pair_index*2)+1])) begin
                $display("[x8-lane-phy] write mask pair %0d mismatch",
                         pair_index);
                $fatal(1);
            end
            if ((dqs_rise !== 1'b1) || (dqs_fall !== 1'b0)) begin
                $display("[x8-lane-phy] DQS data toggle mismatch");
                $fatal(1);
            end
        end
    endtask

    initial begin
        for (i = 0; i < 8; i = i + 1) begin
            wr_bytes[i] = 8'h30 + i[7:0];
            wr_masks[i] = (i == 2) || (i == 5);
            rd_bytes[i] = 8'h90 + i[7:0];
        end

        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (!lane_wr_ready || wr_loaded || busy || error) begin
            $display("[x8-lane-phy] unexpected reset state");
            $fatal(1);
        end

        for (i = 0; i < 8; i = i + 1)
            drive_write_beat(i);

        @(posedge clk);
        if (!wr_loaded || lane_wr_ready) begin
            $display("[x8-lane-phy] write burst did not preload");
            $fatal(1);
        end

        @(negedge clk);
        start_write = 1'b1;
        @(negedge clk);
        start_write = 1'b0;

        wait (dqs_oe && !dq_oe && !dm_oe);
        if (!dqs_oe || dq_oe || dm_oe || dqs_rise || dqs_fall) begin
            $display("[x8-lane-phy] write preamble mismatch");
            $fatal(1);
        end

        for (pair = 0; pair < 4; pair = pair + 1)
            expect_write_pair(pair);

        @(posedge clk);
        #1;
        if (!dqs_oe || dq_oe || dm_oe || dqs_rise || dqs_fall) begin
            $display("[x8-lane-phy] write postamble mismatch");
            $fatal(1);
        end

        @(posedge clk);
        #1;
        if (wr_loaded || busy || error) begin
            $display("[x8-lane-phy] write launch did not return idle");
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
            dq_in_rise = rd_bytes[pair*2];
            dq_in_fall = rd_bytes[(pair*2)+1];
            @(negedge clk);
            rd_sample_valid = 1'b0;
        end

        got_reads = 0;
        while (got_reads < 8) begin
            @(posedge clk);
            if (lane_rd_valid) begin
                if (lane_rd_data !== rd_bytes[got_reads]) begin
                    $display("[x8-lane-phy] read byte %0d mismatch got=%02x",
                             got_reads, lane_rd_data);
                    $fatal(1);
                end
                got_reads = got_reads + 1;
            end
        end

        @(posedge clk);
        if (busy || error) begin
            $display("[x8-lane-phy] read path did not return idle");
            $fatal(1);
        end

        $display("[x8-lane-phy] x8 lane PHY timing core passed");
        $finish;
    end
endmodule

`default_nettype wire
