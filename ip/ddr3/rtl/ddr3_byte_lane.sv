// DDR3 x8 BL8 byte-lane packetizer.
//
// This is the controller-side byte-lane contract before a board-specific PHY:
// one accepted BL8 write emits eight ordered x8 beats with one DM bit per beat,
// and one accepted BL8 read captures eight ordered x8 beats into a 64-bit line.

`default_nettype none

module ddr3_byte_lane (
    input wire         i_clk,
    input wire         i_rst,

    input wire         i_start,
    output wire        o_ready,
    input wire         i_write,
    input wire [63:0]  i_wr_data,
    input wire [7:0]   i_wr_mask,

    output wire        o_busy,
    output reg         o_done,

    output wire        o_phy_wr_valid,
    input wire         i_phy_wr_ready,
    output wire [7:0]  o_phy_wr_data,
    output wire        o_phy_wr_mask,
    output wire        o_phy_wr_last,

    output wire        o_phy_rd_ready,
    input wire         i_phy_rd_valid,
    input wire [7:0]   i_phy_rd_data,
    output reg         o_rd_valid,
    output reg [63:0]  o_rd_data
);
    localparam [2:0] LAST_BEAT = 3'd7;

    reg        active;
    reg        active_write;
    reg [2:0]  beat_index;
    reg [63:0] wr_data;
    reg [7:0]  wr_mask;
    reg [63:0] rd_shift;

    assign o_busy = active;
    assign o_ready = !active;

    assign o_phy_wr_valid = active && active_write;
    assign o_phy_wr_data = pick_byte(wr_data, beat_index);
    assign o_phy_wr_mask = wr_mask[beat_index];
    assign o_phy_wr_last = o_phy_wr_valid && (beat_index == LAST_BEAT);

    assign o_phy_rd_ready = active && !active_write;

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

    always @(posedge i_clk) begin
        if (i_rst) begin
            active       <= 1'b0;
            active_write <= 1'b0;
            beat_index   <= 3'd0;
            wr_data      <= 64'd0;
            wr_mask      <= 8'd0;
            rd_shift     <= 64'd0;
            o_done       <= 1'b0;
            o_rd_valid   <= 1'b0;
            o_rd_data    <= 64'd0;
        end else begin
            o_done     <= 1'b0;
            o_rd_valid <= 1'b0;

            if (active) begin
                if (active_write) begin
                    if (i_phy_wr_ready) begin
                        if (beat_index == LAST_BEAT) begin
                            active     <= 1'b0;
                            beat_index <= 3'd0;
                            o_done     <= 1'b1;
                        end else begin
                            beat_index <= beat_index + 3'd1;
                        end
                    end
                end else if (i_phy_rd_valid) begin
                    rd_shift <= put_byte(rd_shift, beat_index, i_phy_rd_data);

                    if (beat_index == LAST_BEAT) begin
                        active     <= 1'b0;
                        beat_index <= 3'd0;
                        o_done     <= 1'b1;
                        o_rd_valid <= 1'b1;
                        o_rd_data  <= put_byte(rd_shift, beat_index, i_phy_rd_data);
                    end else begin
                        beat_index <= beat_index + 3'd1;
                    end
                end
            end else if (i_start) begin
                active       <= 1'b1;
                active_write <= i_write;
                beat_index   <= 3'd0;
                wr_data      <= i_wr_data;
                wr_mask      <= i_wr_mask;
                rd_shift     <= 64'd0;
            end
        end
    end
endmodule

`default_nettype wire
