`default_nettype none
`timescale 1ps/1ps

module tb_line_burst_phy;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 2;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;

    reg ctrl_clk = 1'b0;
    reg phy_clk = 1'b0;
    reg ctrl_rst = 1'b1;
    reg phy_rst = 1'b1;

    always #10000 ctrl_clk = !ctrl_clk;
    always #1250 phy_clk = !phy_clk;

    reg [CHANNELS-1:0] wr_line_valid = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] wr_line_ready;
    wire [CHANNELS-1:0] wr_line_loaded;
    reg [(CHANNELS*LINE_DATA_W)-1:0] wr_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [(CHANNELS*LINE_BYTES)-1:0] wr_line_mask =
        {(CHANNELS*LINE_BYTES){1'b0}};
    reg [CHANNELS-1:0] start_write = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] start_read = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] rd_line_ready = {CHANNELS{1'b0}};
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
    reg [PHY_LANES-1:0] rd_sample_valid = {PHY_LANES{1'b0}};
    reg [(PHY_LANES*8)-1:0] dq_in_rise = {(PHY_LANES*8){1'b0}};
    reg [(PHY_LANES*8)-1:0] dq_in_fall = {(PHY_LANES*8){1'b0}};

    reg [LINE_DATA_W-1:0] write_line = {LINE_DATA_W{1'b0}};
    reg [LINE_DATA_W-1:0] read_line = {LINE_DATA_W{1'b0}};
    integer pair_count [0:PHY_LANES-1];
    integer read_pair_count [0:PHY_LANES-1];
    integer phy;
    integer lane;
    integer pair;
    integer complete;
    integer timeout;

    ddr3_line_burst_phy #(
        .CHANNELS(CHANNELS),
        .LANES(LANES),
        .WRITE_LATENCY(2),
        .READ_LATENCY(2)
    ) dut (
        .i_ctrl_clk(ctrl_clk),
        .i_ctrl_rst(ctrl_rst),
        .i_phy_clk(phy_clk),
        .i_phy_rst(phy_rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .o_wr_line_loaded(wr_line_loaded),
        .i_wr_line_data(wr_line_data),
        .i_wr_line_mask(wr_line_mask),
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

    function [63:0] lane_write_burst;
        input integer lane_index;
        begin
            lane_write_burst = 64'h1011_1213_1415_1617 +
                               (lane_index * 64'h2020_2020_2020_2020);
        end
    endfunction

    function [63:0] lane_read_burst;
        input integer lane_index;
        begin
            lane_read_burst = 64'ha0a1_a2a3_a4a5_a6a7 +
                              (lane_index * 64'h1111_1111_1111_1111);
        end
    endfunction

    task init_lines;
        begin
            for (lane = 0; lane < LANES; lane = lane + 1) begin
                write_line[lane*64 +: 64] = lane_write_burst(lane);
                read_line[lane*64 +: 64] = lane_read_burst(lane);
            end
        end
    endtask

    task write_channel_line;
        input integer channel;
        begin
            @(negedge ctrl_clk);
            wr_line_data[channel*LINE_DATA_W +: LINE_DATA_W] = write_line;
            wr_line_mask[channel*LINE_BYTES +: LINE_BYTES] = 16'h00f3;
            wr_line_valid[channel] = 1'b1;
            wait (wr_line_ready[channel]);
            @(negedge ctrl_clk);
            wr_line_valid[channel] = 1'b0;
        end
    endtask

    task pulse_start_write;
        input integer channel;
        begin
            @(negedge ctrl_clk);
            start_write[channel] = 1'b1;
            @(negedge ctrl_clk);
            start_write[channel] = 1'b0;
        end
    endtask

    task pulse_start_read;
        input integer channel;
        begin
            @(negedge ctrl_clk);
            start_read[channel] = 1'b1;
            @(negedge ctrl_clk);
            start_read[channel] = 1'b0;
        end
    endtask

    task expect_channel_write_launch;
        input integer channel;
        reg [63:0] expected;
        begin
            for (phy = 0; phy < PHY_LANES; phy = phy + 1)
                pair_count[phy] = 0;

            complete = 0;
            timeout = 0;
            while (complete < LANES && timeout < 300) begin
                @(posedge phy_clk);
                timeout = timeout + 1;

                for (lane = 0; lane < LANES; lane = lane + 1) begin
                    phy = (channel * LANES) + lane;
                    if (dq_oe[phy]) begin
                        pair = pair_count[phy];
                        expected = lane_write_burst(lane);
                        if (!dqs_oe[phy] || !dqs_rise[phy] || dqs_fall[phy]) begin
                            $display("[line-burst-phy] DQS mismatch phy=%0d", phy);
                            $fatal(1);
                        end
                        if (dq_rise[phy*8 +: 8] !== expected[pair*16 +: 8] ||
                            dq_fall[phy*8 +: 8] !== expected[(pair*16)+8 +: 8]) begin
                            $display("[line-burst-phy] write pair mismatch phy=%0d pair=%0d",
                                     phy, pair);
                            $fatal(1);
                        end

                        pair_count[phy] = pair_count[phy] + 1;
                        if (pair_count[phy] == 4)
                            complete = complete + 1;
                    end
                end
            end

            if (timeout >= 300) begin
                $display("[line-burst-phy] write launch timeout complete=%0d",
                         complete);
                $fatal(1);
            end
        end
    endtask

    task drive_channel_read_samples;
        input integer channel;
        reg [63:0] expected;
        begin
            for (phy = 0; phy < PHY_LANES; phy = phy + 1)
                read_pair_count[phy] = 0;

            complete = 0;
            timeout = 0;
            while (complete < LANES && timeout < 300) begin
                @(negedge phy_clk);
                timeout = timeout + 1;
                rd_sample_valid = {PHY_LANES{1'b0}};
                dq_in_rise = {(PHY_LANES*8){1'b0}};
                dq_in_fall = {(PHY_LANES*8){1'b0}};

                for (lane = 0; lane < LANES; lane = lane + 1) begin
                    phy = (channel * LANES) + lane;
                    if (rd_capturing[phy] && read_pair_count[phy] < 4) begin
                        pair = read_pair_count[phy];
                        expected = lane_read_burst(lane);
                        rd_sample_valid[phy] = 1'b1;
                        dq_in_rise[phy*8 +: 8] =
                            expected[pair*16 +: 8];
                        dq_in_fall[phy*8 +: 8] =
                            expected[(pair*16)+8 +: 8];
                        read_pair_count[phy] = read_pair_count[phy] + 1;
                        if (read_pair_count[phy] == 4)
                            complete = complete + 1;
                    end
                end
            end

            @(negedge phy_clk);
            rd_sample_valid = {PHY_LANES{1'b0}};
            dq_in_rise = {(PHY_LANES*8){1'b0}};
            dq_in_fall = {(PHY_LANES*8){1'b0}};

            if (timeout >= 300) begin
                $display("[line-burst-phy] read sample timeout complete=%0d",
                         complete);
                $fatal(1);
            end
        end
    endtask

    task expect_channel_read_line;
        input integer channel;
        begin
            wait (rd_line_valid[channel]);
            if (rd_line_data[channel*LINE_DATA_W +: LINE_DATA_W] !== read_line ||
                rd_line_err[channel]) begin
                $display("[line-burst-phy] read line mismatch channel=%0d",
                         channel);
                $fatal(1);
            end
        end
    endtask

    initial begin
        init_lines();

        repeat (5) @(posedge ctrl_clk);
        ctrl_rst = 1'b0;
        phy_rst = 1'b0;
        repeat (5) @(posedge ctrl_clk);

        write_channel_line(0);
        wait (wr_line_ready[0]);
        repeat (8) @(posedge ctrl_clk);

        fork
            pulse_start_write(0);
            expect_channel_write_launch(0);
        join

        rd_line_ready[1] = 1'b1;
        fork
            begin
                pulse_start_read(1);
                drive_channel_read_samples(1);
            end
            expect_channel_read_line(1);
        join

        @(negedge ctrl_clk);
        rd_line_ready[1] = 1'b0;
        repeat (20) @(posedge ctrl_clk);

        if (error) begin
            $display("[line-burst-phy] unexpected error %b", error);
            $fatal(1);
        end

        $display("[line-burst-phy] line-to-fast-burst PHY shell passed");
        $finish;
    end

    initial begin
        repeat (1000) @(posedge ctrl_clk);
        $display("[line-burst-phy] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire
