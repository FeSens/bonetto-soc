`default_nettype none
`timescale 1ns/1ps

module tb_byte_lane;
    localparam [63:0] WRITE_DATA = 64'h5a_c3_00_ff_96_69_3c_a5;
    localparam [7:0]  WRITE_MASK = 8'b0100_1001;
    localparam [63:0] READ_DATA  = 64'h11_22_33_44_55_66_77_88;

    reg clk = 1'b0;
    reg rst = 1'b1;
    reg start = 1'b0;
    reg write = 1'b0;
    reg [63:0] wr_data = 64'd0;
    reg [7:0] wr_mask = 8'd0;
    reg phy_wr_ready = 1'b0;
    reg phy_rd_valid = 1'b0;
    reg [7:0] phy_rd_data = 8'd0;

    wire ready;
    wire busy;
    wire done;
    wire phy_wr_valid;
    wire [7:0] phy_wr_data;
    wire phy_wr_mask;
    wire phy_wr_last;
    wire phy_rd_ready;
    wire rd_valid;
    wire [63:0] rd_data;

    always #5 clk = ~clk;

    ddr3_byte_lane dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_start(start),
        .o_ready(ready),
        .i_write(write),
        .i_wr_data(wr_data),
        .i_wr_mask(wr_mask),
        .o_busy(busy),
        .o_done(done),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data),
        .o_rd_valid(rd_valid),
        .o_rd_data(rd_data)
    );

    function [7:0] byte_at;
        input [63:0] data;
        input integer index;
        begin
            byte_at = data[index * 8 +: 8];
        end
    endfunction

    task start_write;
        begin
            @(negedge clk);
            wr_data = WRITE_DATA;
            wr_mask = WRITE_MASK;
            write = 1'b1;
            start = 1'b1;
            @(negedge clk);
            start = 1'b0;
        end
    endtask

    task start_read;
        begin
            @(negedge clk);
            write = 1'b0;
            start = 1'b1;
            @(negedge clk);
            start = 1'b0;
        end
    endtask

    integer i;
    integer accepted;
    reg stalled_once;

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        if (!ready) begin
            $display("[byte-lane] lane not ready after reset");
            $fatal(1);
        end

        start_write();
        accepted = 0;
        stalled_once = 1'b0;
        while (accepted < 8) begin
            @(negedge clk);
            if ((accepted == 2) && !stalled_once) begin
                phy_wr_ready = 1'b0;
                stalled_once = 1'b1;
            end else begin
                phy_wr_ready = 1'b1;
            end
            if (phy_wr_valid && phy_wr_ready) begin
                if (phy_wr_data !== byte_at(WRITE_DATA, accepted)) begin
                    $display("[byte-lane] write data mismatch beat=%0d expected=%02x got=%02x",
                             accepted, byte_at(WRITE_DATA, accepted), phy_wr_data);
                    $fatal(1);
                end
                if (phy_wr_mask !== WRITE_MASK[accepted]) begin
                    $display("[byte-lane] write mask mismatch beat=%0d expected=%0b got=%0b",
                             accepted, WRITE_MASK[accepted], phy_wr_mask);
                    $fatal(1);
                end
                if (phy_wr_last !== (accepted == 7)) begin
                    $display("[byte-lane] write last mismatch beat=%0d last=%0b",
                             accepted, phy_wr_last);
                    $fatal(1);
                end
                accepted = accepted + 1;
            end
        end
        @(negedge clk);
        phy_wr_ready = 1'b0;

        wait (done);
        @(posedge clk);
        if (!ready) begin
            $display("[byte-lane] lane did not return ready after write");
            $fatal(1);
        end

        start_read();
        for (i = 0; i < 8; i = i + 1) begin
            @(negedge clk);
            if (i == 3) begin
                phy_rd_valid = 1'b0;
                @(negedge clk);
            end
            if (!phy_rd_ready) begin
                $display("[byte-lane] read side not ready at beat=%0d", i);
                $fatal(1);
            end
            phy_rd_data = byte_at(READ_DATA, i);
            phy_rd_valid = 1'b1;
        end

        @(negedge clk);
        phy_rd_valid = 1'b0;
        phy_rd_data = 8'd0;

        wait (rd_valid);
        if (rd_data !== READ_DATA) begin
            $display("[byte-lane] read data mismatch expected=%h got=%h",
                     READ_DATA, rd_data);
            $fatal(1);
        end
        if (!done) begin
            $display("[byte-lane] read valid without done");
            $fatal(1);
        end

        $display("[byte-lane] write/read packetizer passed write=%h mask=%02x read=%h",
                 WRITE_DATA, WRITE_MASK, rd_data);
        $finish;
    end

    initial begin
        repeat (200) @(posedge clk);
        $display("[byte-lane] timeout ready=%0b busy=%0b done=%0b wr_valid=%0b rd_ready=%0b rd_valid=%0b",
                 ready, busy, done, phy_wr_valid, phy_rd_ready, rd_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire
