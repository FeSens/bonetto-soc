// Formal harness for the DDR3 x8 BL8 byte-lane packetizer.

`default_nettype none

module ddr3_byte_lane_wrapper (
    input wire        clk,
    input wire        rst,
    input wire        start,
    input wire        write,
    input wire [63:0] wr_data,
    input wire [7:0]  wr_mask,
    input wire        phy_wr_ready,
    input wire        phy_rd_valid,
    input wire [7:0]  phy_rd_data
);
    wire        ready;
    wire        busy;
    wire        done;
    wire        phy_wr_valid;
    wire [7:0]  phy_wr_data;
    wire        phy_wr_mask;
    wire        phy_wr_last;
    wire        phy_rd_ready;
    wire        rd_valid;
    wire [63:0] rd_data;

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

`ifdef FORMAL
    reg f_past_valid = 1'b0;

    reg        f_wr_active = 1'b0;
    reg [2:0]  f_wr_index = 3'd0;
    reg [63:0] f_wr_data = 64'd0;
    reg [7:0]  f_wr_mask = 8'd0;

    reg        f_rd_active = 1'b0;
    reg [2:0]  f_rd_index = 3'd0;
    reg [63:0] f_rd_data = 64'd0;

    reg saw_write_done = 1'b0;
    reg saw_read_done = 1'b0;

    initial assume(rst);

    function [7:0] pick_byte;
        input [63:0] data;
        input [2:0] index;
        begin
            case (index)
                3'd0: pick_byte = data[7:0];
                3'd1: pick_byte = data[15:8];
                3'd2: pick_byte = data[23:16];
                3'd3: pick_byte = data[31:24];
                3'd4: pick_byte = data[39:32];
                3'd5: pick_byte = data[47:40];
                3'd6: pick_byte = data[55:48];
                default: pick_byte = data[63:56];
            endcase
        end
    endfunction

    function [63:0] put_byte;
        input [63:0] data;
        input [2:0] index;
        input [7:0] byte_value;
        begin
            put_byte = data;
            case (index)
                3'd0: put_byte[7:0] = byte_value;
                3'd1: put_byte[15:8] = byte_value;
                3'd2: put_byte[23:16] = byte_value;
                3'd3: put_byte[31:24] = byte_value;
                3'd4: put_byte[39:32] = byte_value;
                3'd5: put_byte[47:40] = byte_value;
                3'd6: put_byte[55:48] = byte_value;
                default: put_byte[63:56] = byte_value;
            endcase
        end
    endfunction

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wr_active <= 1'b0;
            f_wr_index <= 3'd0;
            f_wr_data <= 64'd0;
            f_wr_mask <= 8'd0;
            f_rd_active <= 1'b0;
            f_rd_index <= 3'd0;
            f_rd_data <= 64'd0;
            saw_write_done <= 1'b0;
            saw_read_done <= 1'b0;
        end else begin
            assert(ready == !busy);
            assert(!(phy_wr_valid && phy_rd_ready));
            assert(!rd_valid || done);

            if (start)
                assume(ready);
            if (phy_rd_valid)
                assume(phy_rd_ready);

            if (f_past_valid && $past(phy_wr_valid && !phy_wr_ready)) begin
                assert(phy_wr_valid);
                assert(phy_wr_data == $past(phy_wr_data));
                assert(phy_wr_mask == $past(phy_wr_mask));
                assert(phy_wr_last == $past(phy_wr_last));
            end

            if (start && ready) begin
                assert(!f_wr_active);
                assert(!f_rd_active);
                if (write) begin
                    f_wr_active <= 1'b1;
                    f_wr_index <= 3'd0;
                    f_wr_data <= wr_data;
                    f_wr_mask <= wr_mask;
                end else begin
                    f_rd_active <= 1'b1;
                    f_rd_index <= 3'd0;
                    f_rd_data <= 64'd0;
                end
            end

            if (phy_wr_valid) begin
                assert(f_wr_active);
                assert(phy_wr_data == pick_byte(f_wr_data, f_wr_index));
                assert(phy_wr_mask == f_wr_mask[f_wr_index]);
                assert(phy_wr_last == (f_wr_index == 3'd7));
            end

            if (phy_wr_valid && phy_wr_ready) begin
                if (f_wr_index == 3'd7) begin
                    f_wr_active <= 1'b0;
                    f_wr_index <= 3'd0;
                    saw_write_done <= 1'b1;
                end else begin
                    f_wr_index <= f_wr_index + 3'd1;
                end
            end

            if (phy_rd_valid) begin
                assert(f_rd_active);
                f_rd_data <= put_byte(f_rd_data, f_rd_index, phy_rd_data);
                if (f_rd_index == 3'd7) begin
                    f_rd_active <= 1'b0;
                    f_rd_index <= 3'd0;
                end else begin
                    f_rd_index <= f_rd_index + 3'd1;
                end
            end

            if (rd_valid) begin
                assert(!f_rd_active);
                assert(rd_data == f_rd_data);
                saw_read_done <= 1'b1;
            end

            if (done)
                assert(saw_write_done || rd_valid);

            cover(saw_write_done && saw_read_done);
        end
    end
`endif
endmodule

`default_nettype wire
