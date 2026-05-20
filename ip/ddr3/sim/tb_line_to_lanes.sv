`default_nettype none
`timescale 1ns/1ps

module tb_line_to_lanes;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;

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
    wire [(PHY_LANES*8)-1:0] lane_wr_data;
    wire [PHY_LANES-1:0] lane_wr_mask;
    wire [PHY_LANES-1:0] lane_wr_last;

    wire [PHY_LANES-1:0] lane_rd_ready;
    reg [PHY_LANES-1:0] lane_rd_valid = {PHY_LANES{1'b0}};
    reg [(PHY_LANES*8)-1:0] lane_rd_data = {(PHY_LANES*8){1'b0}};

    reg [(CHANNELS*LINE_DATA_W)-1:0] expected_rd_line =
        {(CHANNELS*LINE_DATA_W){1'b0}};

    integer ch;
    integer lane;
    integer beat;
    integer idx;
    integer total;
    integer wr_count [0:PHY_LANES-1];
    integer rd_count [0:PHY_LANES-1];
    reg wr_stalled [0:PHY_LANES-1];
    reg rd_stalled [0:PHY_LANES-1];
    reg [CHANNELS-1:0] rd_seen;

    always #5 clk = ~clk;

    ddr3_line_to_lanes #(
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
        .o_lane_wr_last(lane_wr_last),
        .o_lane_rd_ready(lane_rd_ready),
        .i_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_data(lane_rd_data)
    );

    function [7:0] write_byte;
        input integer channel;
        input integer byte_index;
        begin
            write_byte = 8'h20 + (channel * 8'h40) + byte_index;
        end
    endfunction

    function write_mask;
        input integer channel;
        input integer byte_index;
        begin
            write_mask = ((channel + byte_index) % 5) == 0;
        end
    endfunction

    function [7:0] read_byte;
        input integer channel;
        input integer byte_index;
        begin
            read_byte = 8'h90 + (channel * 8'h30) + byte_index;
        end
    endfunction

    function lane_should_stall_write;
        input integer phy;
        input integer count;
        begin
            lane_should_stall_write =
                ((phy == 3) && (count == 2)) ||
                ((phy == 11) && (count == 5));
        end
    endfunction

    function lane_should_stall_read;
        input integer phy;
        input integer count;
        begin
            lane_should_stall_read =
                ((phy == 1) && (count == 3)) ||
                ((phy == 14) && (count == 4));
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
            $display("[line-to-lanes] not write-ready after reset");
            $fatal(1);
        end

        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b1}};
        @(negedge clk);
        wr_line_valid = {CHANNELS{1'b0}};

        total = 0;
        for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
            wr_count[idx] = 0;
            wr_stalled[idx] = 1'b0;
        end

        while (total < PHY_LANES * 8) begin
            @(negedge clk);
            for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
                if (lane_should_stall_write(idx, wr_count[idx]) &&
                    !wr_stalled[idx]) begin
                    lane_wr_ready[idx] = 1'b0;
                    wr_stalled[idx] = 1'b1;
                end else begin
                    lane_wr_ready[idx] = 1'b1;
                end

                if (lane_wr_valid[idx] && lane_wr_ready[idx]) begin
                    ch = idx / LANES;
                    lane = idx % LANES;
                    beat = wr_count[idx];
                    if (lane_wr_data[idx*8 +: 8] !==
                        write_byte(ch, (lane * 8) + beat)) begin
                        $display("[line-to-lanes] write data mismatch phy=%0d beat=%0d got=%02x",
                                 idx, beat, lane_wr_data[idx*8 +: 8]);
                        $fatal(1);
                    end
                    if (lane_wr_mask[idx] !==
                        write_mask(ch, (lane * 8) + beat)) begin
                        $display("[line-to-lanes] write mask mismatch phy=%0d beat=%0d got=%0b",
                                 idx, beat, lane_wr_mask[idx]);
                        $fatal(1);
                    end
                    if (lane_wr_last[idx] !== (beat == 7)) begin
                        $display("[line-to-lanes] write last mismatch phy=%0d beat=%0d last=%0b",
                                 idx, beat, lane_wr_last[idx]);
                        $fatal(1);
                    end
                    wr_count[idx] = wr_count[idx] + 1;
                    total = total + 1;
                end
            end
        end

        @(negedge clk);
        lane_wr_ready = {PHY_LANES{1'b0}};
        wait (wr_line_ready == {CHANNELS{1'b1}});

        total = 0;
        rd_seen = {CHANNELS{1'b0}};
        for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
            rd_count[idx] = 0;
            rd_stalled[idx] = 1'b0;
        end

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b1}};

        while (rd_seen != {CHANNELS{1'b1}}) begin
            @(negedge clk);
            lane_rd_valid = {PHY_LANES{1'b0}};
            lane_rd_data = {(PHY_LANES*8){1'b0}};

            for (idx = 0; idx < PHY_LANES; idx = idx + 1) begin
                if (lane_rd_ready[idx] && (rd_count[idx] < 8) &&
                    lane_should_stall_read(idx, rd_count[idx]) &&
                    !rd_stalled[idx]) begin
                    rd_stalled[idx] = 1'b1;
                end else if (lane_rd_ready[idx] && (rd_count[idx] < 8)) begin
                    ch = idx / LANES;
                    lane = idx % LANES;
                    beat = rd_count[idx];
                    lane_rd_valid[idx] = 1'b1;
                    lane_rd_data[idx*8 +: 8] =
                        read_byte(ch, (lane * 8) + beat);
                    rd_count[idx] = rd_count[idx] + 1;
                    total = total + 1;
                end
            end

            @(posedge clk);
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
                if (rd_line_valid[ch]) begin
                    if (rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W] !==
                        expected_rd_line[ch*LINE_DATA_W +: LINE_DATA_W]) begin
                        $display("[line-to-lanes] read line mismatch channel=%0d",
                                 ch);
                        $fatal(1);
                    end
                    rd_seen[ch] = 1'b1;
                end
            end
        end

        if (rd_line_err !== {CHANNELS{1'b0}}) begin
            $display("[line-to-lanes] unexpected read error bits %b", rd_line_err);
            $fatal(1);
        end

        @(negedge clk);
        rd_line_ready = {CHANNELS{1'b0}};
        lane_rd_valid = {PHY_LANES{1'b0}};

        $display("[line-to-lanes] dual-channel line-to-lane adapter passed");
        $finish;
    end

    initial begin
        repeat (300) @(posedge clk);
        $display("[line-to-lanes] timeout wr_ready=%b rd_valid=%b total=%0d",
                 wr_line_ready, rd_line_valid, total);
        $fatal(1);
    end
endmodule

`default_nettype wire
