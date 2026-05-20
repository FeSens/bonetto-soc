// DDR3 x8 fast-domain burst I/O sequencer.
//
// This module is the narrow timing core intended to sit directly in front of
// the board-specific DQ/DQS I/O primitive wrapper. It accepts one complete BL8
// x8 write burst as a 64-bit word, launches four DDR rise/fall DQ pairs with
// DQS strobes, and reassembles four sampled read pairs back into a 64-bit word.
//
// It deliberately does not know about Wishbone, line packing, read-modify-write
// policy, or cross-clock transport. Those stay in slower fabric so the 400 MHz
// path remains a small per-lane sequencer.

`default_nettype none

module ddr3_x8_burst_io_sequencer #(
    parameter integer WRITE_LATENCY = 5,
    parameter integer READ_LATENCY  = 6
) (
    input wire        i_clk,
    input wire        i_rst,

    input wire        i_wr_valid,
    output wire       o_wr_ready,
    input wire [63:0] i_wr_data,
    output wire       o_wr_loaded,

    input wire        i_start_write,
    input wire        i_start_read,
    output wire       o_busy,
    output reg        o_error,

    output reg        o_dq_oe,
    output reg        o_dqs_oe,
    output reg [7:0]  o_dq_rise,
    output reg [7:0]  o_dq_fall,
    output reg        o_dqs_rise,
    output reg        o_dqs_fall,

    output wire       o_rd_capturing,
    input wire        i_rd_sample_valid,
    input wire [7:0]  i_dq_rise,
    input wire [7:0]  i_dq_fall,

    output reg        o_rd_valid,
    input wire        i_rd_ready,
    output reg [63:0] o_rd_data
);
    localparam [2:0]
        WR_IDLE     = 3'd0,
        WR_WAIT     = 3'd1,
        WR_PREAMBLE = 3'd2,
        WR_DATA     = 3'd3,
        WR_POST     = 3'd4;

    localparam [1:0]
        RD_IDLE    = 2'd0,
        RD_WAIT    = 2'd1,
        RD_CAPTURE = 2'd2,
        RD_DONE    = 2'd3;

    reg [63:0] wr_payload;
    reg        wr_loaded;
    reg [2:0]  wr_state;
    reg [15:0] wr_wait_count;
    reg [1:0]  wr_pair_index;

    reg [63:0] rd_payload;
    reg [1:0]  rd_state;
    reg [15:0] rd_wait_count;
    reg [1:0]  rd_pair_index;

    wire wr_active = (wr_state != WR_IDLE);
    wire rd_active = (rd_state != RD_IDLE);
    wire wr_accept = i_wr_valid && o_wr_ready;

    assign o_wr_ready = !wr_loaded && !wr_active && !rd_active && !o_rd_valid;
    assign o_wr_loaded = wr_loaded;
    assign o_busy = wr_active || rd_active || o_rd_valid;
    assign o_rd_capturing = (rd_state == RD_CAPTURE);

    initial begin
        wr_payload = 64'd0;
        wr_loaded = 1'b0;
        wr_state = WR_IDLE;
        wr_wait_count = 16'd0;
        wr_pair_index = 2'd0;
        rd_payload = 64'd0;
        rd_state = RD_IDLE;
        rd_wait_count = 16'd0;
        rd_pair_index = 2'd0;
        o_error = 1'b0;
        o_dq_oe = 1'b0;
        o_dqs_oe = 1'b0;
        o_dq_rise = 8'h00;
        o_dq_fall = 8'h00;
        o_dqs_rise = 1'b0;
        o_dqs_fall = 1'b0;
        o_rd_valid = 1'b0;
        o_rd_data = 64'd0;
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            wr_payload <= 64'd0;
            wr_loaded <= 1'b0;
            wr_state <= WR_IDLE;
            wr_wait_count <= 16'd0;
            wr_pair_index <= 2'd0;
            rd_payload <= 64'd0;
            rd_state <= RD_IDLE;
            rd_wait_count <= 16'd0;
            rd_pair_index <= 2'd0;
            o_error <= 1'b0;
            o_dq_oe <= 1'b0;
            o_dqs_oe <= 1'b0;
            o_dq_rise <= 8'h00;
            o_dq_fall <= 8'h00;
            o_dqs_rise <= 1'b0;
            o_dqs_fall <= 1'b0;
            o_rd_valid <= 1'b0;
            o_rd_data <= 64'd0;
        end else begin
            o_dq_oe <= 1'b0;
            o_dqs_oe <= 1'b0;
            o_dq_rise <= 8'h00;
            o_dq_fall <= 8'h00;
            o_dqs_rise <= 1'b0;
            o_dqs_fall <= 1'b0;

            if (i_start_write && i_start_read)
                o_error <= 1'b1;

            if (wr_accept) begin
                wr_payload <= i_wr_data;
                wr_loaded <= 1'b1;
            end

            case (wr_state)
                WR_IDLE: begin
                    if (i_start_write && !i_start_read) begin
                        if (!wr_loaded || rd_active || o_rd_valid) begin
                            o_error <= 1'b1;
                        end else if (WRITE_LATENCY <= 0) begin
                            wr_state <= WR_PREAMBLE;
                        end else begin
                            wr_state <= WR_WAIT;
                            wr_wait_count <= WRITE_LATENCY[15:0];
                        end
                    end
                end

                WR_WAIT: begin
                    if (wr_wait_count <= 16'd1) begin
                        wr_state <= WR_PREAMBLE;
                        wr_wait_count <= 16'd0;
                    end else begin
                        wr_wait_count <= wr_wait_count - 16'd1;
                    end
                end

                WR_PREAMBLE: begin
                    o_dqs_oe <= 1'b1;
                    o_dqs_rise <= 1'b0;
                    o_dqs_fall <= 1'b0;
                    wr_pair_index <= 2'd0;
                    wr_state <= WR_DATA;
                end

                WR_DATA: begin
                    o_dq_oe <= 1'b1;
                    o_dqs_oe <= 1'b1;
                    o_dq_rise <= wr_payload[(wr_pair_index * 16) +: 8];
                    o_dq_fall <= wr_payload[(wr_pair_index * 16) + 8 +: 8];
                    o_dqs_rise <= 1'b1;
                    o_dqs_fall <= 1'b0;

                    if (wr_pair_index == 2'd3) begin
                        wr_pair_index <= 2'd0;
                        wr_state <= WR_POST;
                    end else begin
                        wr_pair_index <= wr_pair_index + 2'd1;
                    end
                end

                WR_POST: begin
                    o_dqs_oe <= 1'b1;
                    o_dqs_rise <= 1'b0;
                    o_dqs_fall <= 1'b0;
                    wr_loaded <= 1'b0;
                    wr_state <= WR_IDLE;
                end

                default: begin
                    wr_state <= WR_IDLE;
                end
            endcase

            case (rd_state)
                RD_IDLE: begin
                    if (i_start_read && !i_start_write) begin
                        if (wr_active || o_rd_valid) begin
                            o_error <= 1'b1;
                        end else if (READ_LATENCY <= 0) begin
                            rd_payload <= 64'd0;
                            rd_pair_index <= 2'd0;
                            rd_state <= RD_CAPTURE;
                        end else begin
                            rd_payload <= 64'd0;
                            rd_state <= RD_WAIT;
                            rd_wait_count <= READ_LATENCY[15:0];
                        end
                    end
                end

                RD_WAIT: begin
                    if (rd_wait_count <= 16'd1) begin
                        rd_state <= RD_CAPTURE;
                        rd_wait_count <= 16'd0;
                        rd_pair_index <= 2'd0;
                    end else begin
                        rd_wait_count <= rd_wait_count - 16'd1;
                    end
                end

                RD_CAPTURE: begin
                    if (i_rd_sample_valid) begin
                        rd_payload[(rd_pair_index * 16) +: 8] <= i_dq_rise;
                        rd_payload[(rd_pair_index * 16) + 8 +: 8] <= i_dq_fall;

                        if (rd_pair_index == 2'd3) begin
                            o_rd_data <= {i_dq_fall, i_dq_rise, rd_payload[47:0]};
                            o_rd_valid <= 1'b1;
                            rd_pair_index <= 2'd0;
                            rd_state <= RD_DONE;
                        end else begin
                            rd_pair_index <= rd_pair_index + 2'd1;
                        end
                    end
                end

                RD_DONE: begin
                    if (i_rd_ready) begin
                        o_rd_valid <= 1'b0;
                        rd_state <= RD_IDLE;
                    end
                end

                default: begin
                    rd_state <= RD_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire
