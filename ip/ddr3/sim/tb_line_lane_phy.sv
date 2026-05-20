`default_nettype none
`timescale 1ns/1ps

module tb_line_lane_phy;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WRITE_LATENCY = 2;
    localparam integer READ_LATENCY = 2;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg [CHANNELS-1:0] wr_line_valid = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] wr_line_ready;
    reg [(CHANNELS*LINE_DATA_W)-1:0] wr_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [(CHANNELS*LINE_BYTES)-1:0] wr_line_mask =
        {(CHANNELS*LINE_BYTES){1'b1}};

    reg [CHANNELS-1:0] start_write = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] start_read = {CHANNELS{1'b0}};

    reg [CHANNELS-1:0] rd_line_ready = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data;
    wire [CHANNELS-1:0] rd_line_err;
    wire [CHANNELS-1:0] channel_busy;
    wire [CHANNELS-1:0] channel_error;

    wire [PHY_LANES-1:0] lane_busy;
    wire [PHY_LANES-1:0] lane_error;
    wire [PHY_LANES-1:0] dq_oe;
    wire [PHY_LANES-1:0] dm_oe;
    wire [PHY_LANES-1:0] dqs_oe;
    wire [(PHY_LANES*8)-1:0] dq_rise;
    wire [(PHY_LANES*8)-1:0] dq_fall;
    wire [PHY_LANES-1:0] dm_rise;
    wire [PHY_LANES-1:0] dm_fall;
    wire [PHY_LANES-1:0] dqs_rise;
    wire [PHY_LANES-1:0] dqs_fall;

    wire [PHY_LANES-1:0] rd_capturing;
    reg [PHY_LANES-1:0] rd_sample_valid = {PHY_LANES{1'b0}};
    reg [(PHY_LANES*8)-1:0] dq_in_rise = {(PHY_LANES*8){1'b0}};
    reg [(PHY_LANES*8)-1:0] dq_in_fall = {(PHY_LANES*8){1'b0}};

    reg [(CHANNELS*LINE_DATA_W)-1:0] expected_rd_line =
        {(CHANNELS*LINE_DATA_W){1'b0}};

    integer ch;
    integer lane;
    integer beat;
    integer idx;
    integer total;
    integer cycles;
    integer wr_pair_count [0:PHY_LANES-1];
    integer rd_pair_count [0:PHY_LANES-1];
    reg [CHANNELS-1:0] rd_seen;

    always #5 clk = ~clk;

    ddr3_line_lane_phy #(
        .CHANNELS(CHANNELS),
        .LANES(LANES),
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .i_wr_line_data(wr_line_data),
        .i_wr_line_mask(wr_line_mask),
        .i_start_write(start_write),
        .i_start_read(start_read),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_channel_busy(channel_busy),
        .o_channel_error(channel_error),
        .o_lane_busy(lane_busy),
        .o_lane_error(lane_error),
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
        .i_dq_fall(dq_in_fall)
    );

    function [7:0] write_byte;
        input integer channel;
        input integer byte_index;
        begin
            write_byte = 8'h10 + (channel * 8'h40) + byte_index;
        end
    endfunction

    function write_mask;
        input integer channel;
        input integer byte_index;
        begin
            write_mask = ((channel + byte_index) % 7) == 0;
        end
    endfunction

    function [7:0] read_byte;
        input integer channel;
        input integer byte_index;
        begin
            read_byte = 8'h80 + (channel * 8'h30) + byte_index;
        end
    endfunction

    task init_lines;
        begin
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
                for (lane = 0; lane < LANES; lane = lane + 1) begin
                    for (beat = 0; beat < 8; beat = beat + 1) begin
                        idx = (lane * 8) + beat;
                        wr_line_data[(ch*LINE_DATA_W) + (idx*8) +: 8] =
                            write_byte(ch, idx);
                        wr_line_mask[(ch*LINE_BYTES) + idx] =
                            write_mask(ch, idx);
                        expected_rd_line[(ch*LINE_DATA_W) + (idx*8) +: 8] =
                            read_byte(ch, idx);
                    end
                end
            end
        end
    endtask

    initial begin
        init_lines();

        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (wr_line_ready !== {CHANNELS{1'b1}}) begin
            $display("[line-lane-phy] not write-ready after reset");
            $fatal(1);
        end

        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b1}};
        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b0}};

        repeat (12) @(posedge clk);

        @(negedge clk);
        start_write = {CHANNELS{1'b1}};
        @(negedge clk);
        start_write = {CHANNELS{1'b0}};

        total = 0;
        cycles = 0;
        for (idx = 0; idx < PHY_LANES; idx = idx + 1)
            wr_pair_count[idx] = 0;

        while (total < PHY_LANES * 4) begin
            @(posedge clk);
            #1;
            cycles = cycles + 1;
            if (cycles > 80) begin
                $display("[line-lane-phy] timeout waiting for write launch");
                $fatal(1);
            end
            if (channel_error !== {CHANNELS{1'b0}}) begin
                $display("[line-lane-phy] unexpected channel write error %b",
                         channel_error);
                $fatal(1);
            end

            for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
                if (dq_oe[idx]) begin
                    ch = idx / LANES;
                    lane = idx % LANES;
                    beat = wr_pair_count[idx] * 2;

                    if (!dm_oe[idx] || !dqs_oe[idx] ||
                        !dqs_rise[idx] || dqs_fall[idx]) begin
                        $display("[line-lane-phy] bad write strobes lane=%0d",
                                 idx);
                        $fatal(1);
                    end

                    if (dq_rise[idx*8 +: 8] !==
                        write_byte(ch, (lane * 8) + beat)) begin
                        $display("[line-lane-phy] dq rise mismatch lane=%0d pair=%0d got=%02x",
                                 idx, wr_pair_count[idx],
                                 dq_rise[idx*8 +: 8]);
                        $fatal(1);
                    end
                    if (dq_fall[idx*8 +: 8] !==
                        write_byte(ch, (lane * 8) + beat + 1)) begin
                        $display("[line-lane-phy] dq fall mismatch lane=%0d pair=%0d got=%02x",
                                 idx, wr_pair_count[idx],
                                 dq_fall[idx*8 +: 8]);
                        $fatal(1);
                    end
                    if (dm_rise[idx] !==
                        write_mask(ch, (lane * 8) + beat)) begin
                        $display("[line-lane-phy] dm rise mismatch lane=%0d pair=%0d",
                                 idx, wr_pair_count[idx]);
                        $fatal(1);
                    end
                    if (dm_fall[idx] !==
                        write_mask(ch, (lane * 8) + beat + 1)) begin
                        $display("[line-lane-phy] dm fall mismatch lane=%0d pair=%0d",
                                 idx, wr_pair_count[idx]);
                        $fatal(1);
                    end

                    wr_pair_count[idx] = wr_pair_count[idx] + 1;
                    total = total + 1;
                end
            end
        end

        wait (channel_busy == {CHANNELS{1'b0}});
        if (wr_line_ready !== {CHANNELS{1'b1}}) begin
            $display("[line-lane-phy] write path did not return ready");
            $fatal(1);
        end

        for (idx = 0; idx < PHY_LANES; idx = idx + 1)
            rd_pair_count[idx] = 0;
        rd_seen = {CHANNELS{1'b0}};
        total = 0;
        cycles = 0;

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b1}};
        start_read = {CHANNELS{1'b1}};
        @(negedge clk);
        start_read = {CHANNELS{1'b0}};

        while (rd_seen != {CHANNELS{1'b1}}) begin
            @(negedge clk);
            rd_sample_valid = {PHY_LANES{1'b0}};
            dq_in_rise = {(PHY_LANES*8){1'b0}};
            dq_in_fall = {(PHY_LANES*8){1'b0}};

            for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
                if (rd_capturing[idx] && (rd_pair_count[idx] < 4)) begin
                    ch = idx / LANES;
                    lane = idx % LANES;
                    beat = rd_pair_count[idx] * 2;
                    rd_sample_valid[idx] = 1'b1;
                    dq_in_rise[idx*8 +: 8] =
                        read_byte(ch, (lane * 8) + beat);
                    dq_in_fall[idx*8 +: 8] =
                        read_byte(ch, (lane * 8) + beat + 1);
                end
            end

            @(posedge clk);
            #1;
            cycles = cycles + 1;
            if (cycles > 120) begin
                $display("[line-lane-phy] timeout waiting for read line");
                $fatal(1);
            end
            if (channel_error !== {CHANNELS{1'b0}}) begin
                $display("[line-lane-phy] unexpected channel read error %b",
                         channel_error);
                $fatal(1);
            end

            for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
                if (rd_sample_valid[idx]) begin
                    rd_pair_count[idx] = rd_pair_count[idx] + 1;
                    total = total + 1;
                end
            end

            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
                if (rd_line_valid[ch]) begin
                    if (rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W] !==
                        expected_rd_line[ch*LINE_DATA_W +: LINE_DATA_W]) begin
                        $display("[line-lane-phy] read line mismatch channel=%0d",
                                 ch);
                        $fatal(1);
                    end
                    rd_seen[ch] = 1'b1;
                end
            end
        end

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b0}};
        rd_sample_valid = {PHY_LANES{1'b0}};

        if (rd_line_err !== {CHANNELS{1'b0}} ||
            lane_error !== {PHY_LANES{1'b0}}) begin
            $display("[line-lane-phy] unexpected final errors channel=%b lane=%b",
                     rd_line_err, lane_error);
            $fatal(1);
        end

        $display("[line-lane-phy] dual-channel line-to-lane PHY bridge passed");
        $finish;
    end
endmodule

`default_nettype wire
