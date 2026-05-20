`default_nettype none
`timescale 1ns/1ps

module tb_channel_line;
    localparam integer LANES = 8;
    localparam integer LINE_DATA_W = LANES * 64;
    localparam integer LINE_MASK_W = LANES * 8;

    reg clk = 1'b0;
    reg rst = 1'b1;
    reg start = 1'b0;
    reg write = 1'b0;
    reg [LINE_DATA_W-1:0] wr_data = {LINE_DATA_W{1'b0}};
    reg [LINE_MASK_W-1:0] wr_mask = {LINE_MASK_W{1'b0}};
    reg [LANES-1:0] phy_wr_ready = {LANES{1'b0}};
    reg [LANES-1:0] phy_rd_valid = {LANES{1'b0}};
    reg [(LANES*8)-1:0] phy_rd_data = {(LANES*8){1'b0}};

    wire ready;
    wire busy;
    wire done;
    wire rd_valid;
    wire [LINE_DATA_W-1:0] rd_data;
    wire [LANES-1:0] phy_wr_valid;
    wire [(LANES*8)-1:0] phy_wr_data;
    wire [LANES-1:0] phy_wr_mask;
    wire [LANES-1:0] phy_wr_last;
    wire [LANES-1:0] phy_rd_ready;

    reg [LINE_DATA_W-1:0] expected_read = {LINE_DATA_W{1'b0}};

    always #5 clk = ~clk;

    ddr3_channel_line #(
        .LANES(LANES)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_start(start),
        .o_ready(ready),
        .i_write(write),
        .i_wr_data(wr_data),
        .i_wr_mask(wr_mask),
        .o_busy(busy),
        .o_done(done),
        .o_rd_valid(rd_valid),
        .o_rd_data(rd_data),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data)
    );

    function [7:0] write_byte;
        input integer lane;
        input integer beat;
        begin
            write_byte = 8'h40 + (lane * 8) + beat;
        end
    endfunction

    function [7:0] read_byte;
        input integer lane;
        input integer beat;
        begin
            read_byte = 8'hA0 + (lane * 8) + beat;
        end
    endfunction

    function mask_bit;
        input integer lane;
        input integer beat;
        begin
            mask_bit = ((lane + beat) % 3) == 0;
        end
    endfunction

    integer lane;
    integer beat;
    integer write_count [0:LANES-1];
    integer read_count [0:LANES-1];
    integer total;
    reg write_stalled [0:LANES-1];
    reg read_stalled [0:LANES-1];

    task init_patterns;
        begin
            for (lane = 0; lane < LANES; lane = lane + 1) begin
                for (beat = 0; beat < 8; beat = beat + 1) begin
                    wr_data[(lane * 64) + (beat * 8) +: 8] = write_byte(lane, beat);
                    wr_mask[(lane * 8) + beat] = mask_bit(lane, beat);
                    expected_read[(lane * 64) + (beat * 8) +: 8] = read_byte(lane, beat);
                end
            end
        end
    endtask

    task start_op;
        input op_write;
        begin
            @(negedge clk);
            write = op_write;
            start = 1'b1;
            @(negedge clk);
            start = 1'b0;
        end
    endtask

    initial begin
        init_patterns();

        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (!ready) begin
            $display("[channel-line] not ready after reset");
            $fatal(1);
        end

        for (lane = 0; lane < LANES; lane = lane + 1)
            write_count[lane] = 0;
        for (lane = 0; lane < LANES; lane = lane + 1)
            write_stalled[lane] = 1'b0;

        start_op(1'b1);
        total = 0;
        while (total < LANES * 8) begin
            @(negedge clk);
            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (((lane == 2 && write_count[lane] == 3) ||
                     (lane == 5 && write_count[lane] == 1)) &&
                    !write_stalled[lane]) begin
                    phy_wr_ready[lane] = 1'b0;
                    write_stalled[lane] = 1'b1;
                end else begin
                    phy_wr_ready[lane] = 1'b1;
                end
            end

            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (phy_wr_valid[lane] && phy_wr_ready[lane]) begin
                    beat = write_count[lane];
                    if (phy_wr_data[(lane * 8) +: 8] !== write_byte(lane, beat)) begin
                        $display("[channel-line] write data mismatch lane=%0d beat=%0d got=%02x",
                                 lane, beat, phy_wr_data[(lane * 8) +: 8]);
                        $fatal(1);
                    end
                    if (phy_wr_mask[lane] !== mask_bit(lane, beat)) begin
                        $display("[channel-line] write mask mismatch lane=%0d beat=%0d got=%0b",
                                 lane, beat, phy_wr_mask[lane]);
                        $fatal(1);
                    end
                    if (phy_wr_last[lane] !== (beat == 7)) begin
                        $display("[channel-line] write last mismatch lane=%0d beat=%0d last=%0b",
                                 lane, beat, phy_wr_last[lane]);
                        $fatal(1);
                    end
                    write_count[lane] = write_count[lane] + 1;
                    total = total + 1;
                end
            end
        end

        @(negedge clk);
        phy_wr_ready = {LANES{1'b0}};
        wait (done);
        @(posedge clk);
        if (!ready) begin
            $display("[channel-line] did not return ready after write");
            $fatal(1);
        end

        for (lane = 0; lane < LANES; lane = lane + 1)
            read_count[lane] = 0;
        for (lane = 0; lane < LANES; lane = lane + 1)
            read_stalled[lane] = 1'b0;

        start_op(1'b0);
        total = 0;
        while (total < LANES * 8) begin
            @(negedge clk);
            phy_rd_valid = {LANES{1'b0}};
            phy_rd_data = {(LANES*8){1'b0}};
            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (phy_rd_ready[lane] && (read_count[lane] < 8) &&
                    ((lane == 1 && read_count[lane] == 4 && !read_stalled[lane]) ||
                     (lane == 6 && read_count[lane] == 2 && !read_stalled[lane]))) begin
                    read_stalled[lane] = 1'b1;
                end else if (phy_rd_ready[lane] && (read_count[lane] < 8)) begin
                    beat = read_count[lane];
                    phy_rd_valid[lane] = 1'b1;
                    phy_rd_data[(lane * 8) +: 8] = read_byte(lane, beat);
                    read_count[lane] = read_count[lane] + 1;
                    total = total + 1;
                end
            end
        end

        @(negedge clk);
        phy_rd_valid = {LANES{1'b0}};
        phy_rd_data = {(LANES*8){1'b0}};

        wait (rd_valid);
        if (!done) begin
            $display("[channel-line] read valid without done");
            $fatal(1);
        end
        if (rd_data !== expected_read) begin
            $display("[channel-line] read data mismatch expected=%h got=%h",
                     expected_read, rd_data);
            $fatal(1);
        end

        $display("[channel-line] full 64-bit channel packetizer passed");
        $finish;
    end

    initial begin
        repeat (400) @(posedge clk);
        $display("[channel-line] timeout ready=%0b busy=%0b done=%0b rd_valid=%0b",
                 ready, busy, done, rd_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire
