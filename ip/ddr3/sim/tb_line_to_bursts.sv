`default_nettype none
`timescale 1ns/1ps

module tb_line_to_bursts;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer LANE_DATA_W = 64;
    localparam integer LANE_MASK_W = 8;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg [CHANNELS-1:0] wr_line_valid = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] wr_line_ready;
    reg [(CHANNELS*LINE_DATA_W)-1:0] wr_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [(CHANNELS*LINE_BYTES)-1:0] wr_line_mask =
        {(CHANNELS*LINE_BYTES){1'b1}};

    reg [CHANNELS-1:0] rd_line_ready = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0] rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data;
    wire [CHANNELS-1:0] rd_line_err;

    wire [PHY_LANES-1:0] lane_wr_valid;
    reg [PHY_LANES-1:0] lane_wr_ready = {PHY_LANES{1'b0}};
    wire [(PHY_LANES*LANE_DATA_W)-1:0] lane_wr_data;
    wire [(PHY_LANES*LANE_MASK_W)-1:0] lane_wr_mask;

    wire [PHY_LANES-1:0] lane_rd_ready;
    reg [PHY_LANES-1:0] lane_rd_valid = {PHY_LANES{1'b0}};
    reg [(PHY_LANES*LANE_DATA_W)-1:0] lane_rd_data =
        {(PHY_LANES*LANE_DATA_W){1'b0}};

    reg [(CHANNELS*LINE_DATA_W)-1:0] expected_rd_line =
        {(CHANNELS*LINE_DATA_W){1'b0}};

    integer ch;
    integer lane;
    integer byte_i;
    integer phy;
    integer total;
    integer wr_count [0:PHY_LANES-1];
    integer rd_count [0:PHY_LANES-1];
    reg wr_stalled [0:PHY_LANES-1];
    reg rd_stalled [0:PHY_LANES-1];
    reg [CHANNELS-1:0] rd_seen;

    always #5 clk = ~clk;

    ddr3_line_to_bursts #(
        .CHANNELS(CHANNELS),
        .LANES(LANES)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .i_wr_line_data(wr_line_data),
        .i_wr_line_mask(wr_line_mask),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_lane_wr_valid(lane_wr_valid),
        .i_lane_wr_ready(lane_wr_ready),
        .o_lane_wr_data(lane_wr_data),
        .o_lane_wr_mask(lane_wr_mask),
        .o_lane_rd_ready(lane_rd_ready),
        .i_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_data(lane_rd_data)
    );

    function [7:0] write_byte;
        input integer channel;
        input integer index;
        begin
            write_byte = 8'h20 + (channel * 8'h40) + index;
        end
    endfunction

    function write_mask;
        input integer channel;
        input integer index;
        begin
            write_mask = ((channel + index) % 7) == 0;
        end
    endfunction

    function [7:0] read_byte;
        input integer channel;
        input integer index;
        begin
            read_byte = 8'h91 + (channel * 8'h33) + index;
        end
    endfunction

    function lane_should_stall_write;
        input integer lane_index;
        input integer count;
        begin
            lane_should_stall_write =
                ((lane_index == 2) && (count == 0)) ||
                ((lane_index == 13) && (count == 0));
        end
    endfunction

    function lane_should_stall_read;
        input integer lane_index;
        input integer count;
        begin
            lane_should_stall_read =
                ((lane_index == 5) && (count == 0)) ||
                ((lane_index == 10) && (count == 0));
        end
    endfunction

    function [LANE_DATA_W-1:0] expected_write_burst;
        input integer channel;
        input integer lane_index;
        integer b;
        begin
            expected_write_burst = {LANE_DATA_W{1'b0}};
            for (b = 0; b < 8; b = b + 1)
                expected_write_burst[b*8 +: 8] =
                    write_byte(channel, (lane_index * 8) + b);
        end
    endfunction

    function [LANE_MASK_W-1:0] expected_write_mask;
        input integer channel;
        input integer lane_index;
        integer b;
        begin
            expected_write_mask = {LANE_MASK_W{1'b0}};
            for (b = 0; b < 8; b = b + 1)
                expected_write_mask[b] =
                    write_mask(channel, (lane_index * 8) + b);
        end
    endfunction

    function [LANE_DATA_W-1:0] expected_read_burst;
        input integer channel;
        input integer lane_index;
        integer b;
        begin
            expected_read_burst = {LANE_DATA_W{1'b0}};
            for (b = 0; b < 8; b = b + 1)
                expected_read_burst[b*8 +: 8] =
                    read_byte(channel, (lane_index * 8) + b);
        end
    endfunction

    task init_lines;
        begin
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
                for (lane = 0; lane < LANES; lane = lane + 1) begin
                    for (byte_i = 0; byte_i < 8; byte_i = byte_i + 1) begin
                        wr_line_data[(ch*LINE_DATA_W) +
                                     ((lane*8 + byte_i)*8) +: 8] =
                            write_byte(ch, (lane * 8) + byte_i);
                        wr_line_mask[(ch*LINE_BYTES) +
                                     (lane*8 + byte_i)] =
                            write_mask(ch, (lane * 8) + byte_i);
                        expected_rd_line[(ch*LINE_DATA_W) +
                                         ((lane*8 + byte_i)*8) +: 8] =
                            read_byte(ch, (lane * 8) + byte_i);
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
            $display("[line-to-bursts] not write-ready after reset");
            $fatal(1);
        end

        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b1}};
        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b0}};

        total = 0;
        for (phy = 0; phy < PHY_LANES; phy = phy + 1) begin
            wr_count[phy] = 0;
            wr_stalled[phy] = 1'b0;
        end

        while (total < PHY_LANES) begin
            @(negedge clk);
            for (phy = 0; phy < PHY_LANES; phy = phy + 1) begin
                if (lane_should_stall_write(phy, wr_count[phy]) &&
                    !wr_stalled[phy]) begin
                    lane_wr_ready[phy] = 1'b0;
                    wr_stalled[phy] = 1'b1;
                end else begin
                    lane_wr_ready[phy] = 1'b1;
                end

                if (lane_wr_valid[phy] && lane_wr_ready[phy]) begin
                    ch = phy / LANES;
                    lane = phy % LANES;
                    if (lane_wr_data[phy*LANE_DATA_W +: LANE_DATA_W] !==
                        expected_write_burst(ch, lane)) begin
                        $display("[line-to-bursts] write burst mismatch phy=%0d",
                                 phy);
                        $fatal(1);
                    end
                    if (lane_wr_mask[phy*LANE_MASK_W +: LANE_MASK_W] !==
                        expected_write_mask(ch, lane)) begin
                        $display("[line-to-bursts] write mask mismatch phy=%0d",
                                 phy);
                        $fatal(1);
                    end
                    wr_count[phy] = wr_count[phy] + 1;
                    total = total + 1;
                end
            end
        end

        @(negedge clk);
        lane_wr_ready = {PHY_LANES{1'b0}};
        wait (wr_line_ready == {CHANNELS{1'b1}});

        total = 0;
        rd_seen = {CHANNELS{1'b0}};
        for (phy = 0; phy < PHY_LANES; phy = phy + 1) begin
            rd_count[phy] = 0;
            rd_stalled[phy] = 1'b0;
        end

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b1}};

        while (rd_seen != {CHANNELS{1'b1}}) begin
            @(negedge clk);
            lane_rd_valid = {PHY_LANES{1'b0}};
            lane_rd_data = {(PHY_LANES*LANE_DATA_W){1'b0}};

            for (phy = 0; phy < PHY_LANES; phy = phy + 1) begin
                if (lane_rd_ready[phy] && (rd_count[phy] == 0) &&
                    lane_should_stall_read(phy, rd_count[phy]) &&
                    !rd_stalled[phy]) begin
                    rd_stalled[phy] = 1'b1;
                end else if (lane_rd_ready[phy] && (rd_count[phy] == 0)) begin
                    ch = phy / LANES;
                    lane = phy % LANES;
                    lane_rd_valid[phy] = 1'b1;
                    lane_rd_data[phy*LANE_DATA_W +: LANE_DATA_W] =
                        expected_read_burst(ch, lane);
                    rd_count[phy] = 1;
                    total = total + 1;
                end
            end

            @(posedge clk);
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
                if (rd_line_valid[ch]) begin
                    if (rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W] !==
                        expected_rd_line[ch*LINE_DATA_W +: LINE_DATA_W]) begin
                        $display("[line-to-bursts] read line mismatch channel=%0d",
                                 ch);
                        $fatal(1);
                    end
                    rd_seen[ch] = 1'b1;
                end
            end
        end

        if (rd_line_err !== {CHANNELS{1'b0}}) begin
            $display("[line-to-bursts] unexpected read error bits %b", rd_line_err);
            $fatal(1);
        end

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b0}};
        lane_rd_valid = {PHY_LANES{1'b0}};

        $display("[line-to-bursts] dual-channel line-to-burst adapter passed");
        $finish;
    end

    initial begin
        repeat (120) @(posedge clk);
        $display("[line-to-bursts] timeout wr_ready=%b rd_valid=%b total=%0d",
                 wr_line_ready, rd_line_valid, total);
        $fatal(1);
    end
endmodule

`default_nettype wire
