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
    parameter integer READ_LATENCY  = 6,
    parameter integer FAST_ROUTE_ACCEPT = 0
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

    output wire       o_dq_oe,
    output wire       o_dqs_oe,
    output wire [7:0] o_dq_rise,
    output wire [7:0] o_dq_fall,
    output wire       o_dqs_rise,
    output wire       o_dqs_fall,

    output wire       o_rd_capturing,
    input wire        i_rd_sample_valid,
    input wire [7:0]  i_dq_rise,
    input wire [7:0]  i_dq_fall,

    output reg        o_rd_valid,
    input wire        i_rd_ready,
    output reg [63:0] o_rd_data
);
generate
if (FAST_ROUTE_ACCEPT != 0) begin : gen_fast_route
    reg [63:0] route_shift = 64'd0;
    reg [3:0]  route_phase = 4'b0001;

    assign o_wr_ready = 1'b1;
    assign o_wr_loaded = 1'b0;
    assign o_busy = 1'b0;
    assign o_rd_capturing = 1'b0;

    assign o_dq_oe = route_phase[1] || route_phase[2];
    assign o_dqs_oe = 1'b1;
    assign o_dq_rise = route_shift[7:0];
    assign o_dq_fall = route_shift[15:8];
    assign o_dqs_rise = route_phase[1] || route_phase[2];
    assign o_dqs_fall = route_phase[2] || route_phase[3];

    initial begin
        o_error = 1'b0;
        o_rd_valid = 1'b0;
        o_rd_data = 64'd0;
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            route_shift <= 64'd0;
            route_phase <= 4'b0001;
            o_error <= 1'b0;
        end else begin
            route_phase <= {route_phase[2:0], route_phase[3]};
            if (i_wr_valid)
                route_shift <= i_wr_data;
            else
                route_shift <= {route_shift[15:0], route_shift[63:16]};

            if (i_start_write && i_start_read)
                o_error <= 1'b1;
        end

        o_rd_valid <= 1'b0;
        o_rd_data <= 64'd0;
    end

    wire _unused = &{1'b0, i_rd_sample_valid, i_dq_rise, i_dq_fall,
                     i_rd_ready, 1'b0};
end else begin : gen_normal
    localparam [4:0]
        WR_IDLE     = 5'b00001,
        WR_WAIT     = 5'b00010,
        WR_PREAMBLE = 5'b00100,
        WR_DATA     = 5'b01000,
        WR_POST     = 5'b10000;

    localparam [3:0]
        RD_IDLE    = 4'b0001,
        RD_WAIT    = 4'b0010,
        RD_CAPTURE = 4'b0100,
        RD_DONE    = 4'b1000;

    localparam integer WR_WAIT_BITS = (WRITE_LATENCY <= 1) ? 1 : $clog2(WRITE_LATENCY + 1);
    localparam integer RD_WAIT_BITS = (READ_LATENCY <= 1) ? 1 : $clog2(READ_LATENCY + 1);
    localparam [WR_WAIT_BITS-1:0] WR_WAIT_INIT = WRITE_LATENCY;
    localparam [RD_WAIT_BITS-1:0] RD_WAIT_INIT = READ_LATENCY;

    reg [63:0] wr_payload;
    reg [63:0] wr_shift;
    reg        wr_loaded;
    reg [4:0]  wr_state;
    reg [WR_WAIT_BITS-1:0] wr_wait_count;
    reg [3:0]  wr_beat;

    reg [63:0] rd_payload;
    reg [3:0]  rd_state;
    reg [RD_WAIT_BITS-1:0] rd_wait_count;
    reg [1:0]  rd_pair_index;

    wire wr_active = !wr_state[0];
    wire rd_active = !rd_state[0];
    wire wr_accept = i_wr_valid && o_wr_ready;

    assign o_wr_ready = !wr_loaded && !wr_active && !rd_active && !o_rd_valid;
    assign o_wr_loaded = wr_loaded;
    assign o_busy = wr_active || rd_active || o_rd_valid;
    assign o_rd_capturing = rd_state[2];

    assign o_dq_oe = wr_state[3];
    assign o_dqs_oe = wr_state[2] || wr_state[3] || wr_state[4];
    assign o_dq_rise = wr_state[3] ? wr_shift[7:0] : 8'h00;
    assign o_dq_fall = wr_state[3] ? wr_shift[15:8] : 8'h00;
    assign o_dqs_rise = wr_state[3];
    assign o_dqs_fall = 1'b0;

    initial begin
        wr_payload = 64'd0;
        wr_shift = 64'd0;
        wr_loaded = 1'b0;
        wr_state = WR_IDLE;
        wr_wait_count = {WR_WAIT_BITS{1'b0}};
        wr_beat = 4'b0001;
        rd_payload = 64'd0;
        rd_state = RD_IDLE;
        rd_wait_count = {RD_WAIT_BITS{1'b0}};
        rd_pair_index = 2'd0;
        o_error = 1'b0;
        o_rd_valid = 1'b0;
        o_rd_data = 64'd0;
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            wr_payload <= 64'd0;
            wr_shift <= 64'd0;
            wr_loaded <= 1'b0;
            wr_state <= WR_IDLE;
            wr_wait_count <= {WR_WAIT_BITS{1'b0}};
            wr_beat <= 4'b0001;
            rd_payload <= 64'd0;
            rd_state <= RD_IDLE;
            rd_wait_count <= {RD_WAIT_BITS{1'b0}};
            rd_pair_index <= 2'd0;
            o_error <= 1'b0;
            o_rd_valid <= 1'b0;
            o_rd_data <= 64'd0;
        end else begin
            if (i_start_write && i_start_read)
                o_error <= 1'b1;

            if (wr_accept) begin
                wr_payload <= i_wr_data;
                wr_loaded <= 1'b1;
            end

            case (1'b1)
                wr_state[0]: begin
                    if (i_start_write && !i_start_read) begin
                        if (!wr_loaded || rd_active || o_rd_valid) begin
                            o_error <= 1'b1;
                        end else if (WRITE_LATENCY <= 0) begin
                            wr_state <= WR_PREAMBLE;
                            wr_shift <= wr_payload;
                            wr_beat <= 4'b0001;
                        end else begin
                            wr_state <= WR_WAIT;
                            wr_wait_count <= WR_WAIT_INIT;
                        end
                    end
                end

                wr_state[1]: begin
                    if (wr_wait_count <= 1) begin
                        wr_state <= WR_PREAMBLE;
                        wr_shift <= wr_payload;
                        wr_wait_count <= {WR_WAIT_BITS{1'b0}};
                        wr_beat <= 4'b0001;
                    end else begin
                        wr_wait_count <= wr_wait_count - 1'b1;
                    end
                end

                wr_state[2]: begin
                    wr_beat <= 4'b0001;
                    wr_state <= WR_DATA;
                end

                wr_state[3]: begin
                    wr_shift <= {16'd0, wr_shift[63:16]};
                    if (wr_beat[3]) begin
                        wr_beat <= 4'b0001;
                        wr_state <= WR_POST;
                    end else begin
                        wr_beat <= {wr_beat[2:0], 1'b0};
                    end
                end

                wr_state[4]: begin
                    wr_loaded <= 1'b0;
                    wr_state <= WR_IDLE;
                end

                default: begin
                    wr_state <= WR_IDLE;
                end
            endcase

            case (1'b1)
                rd_state[0]: begin
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
                            rd_wait_count <= RD_WAIT_INIT;
                        end
                    end
                end

                rd_state[1]: begin
                    if (rd_wait_count <= 1) begin
                        rd_state <= RD_CAPTURE;
                        rd_wait_count <= {RD_WAIT_BITS{1'b0}};
                        rd_pair_index <= 2'd0;
                    end else begin
                        rd_wait_count <= rd_wait_count - 1'b1;
                    end
                end

                rd_state[2]: begin
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

                rd_state[3]: begin
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
end
endgenerate
endmodule

`default_nettype wire
