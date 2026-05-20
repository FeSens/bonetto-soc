// DDR3 x8 lane PHY timing core.
//
// This is the reusable logic immediately before a board-specific 7-series
// DQ/DQS wrapper. It buffers one BL8 x8 write burst, launches it as four
// rise/fall DDR pin-data pairs after a write-transfer start, and reassembles
// four sampled read pairs into the existing one-byte-per-cycle lane stream.
//
// The module does not instantiate IOBUF, ODDR, IDDR, IDELAY, or BUFIO
// primitives. Board integration code owns those package and clocking details.

`default_nettype none

module ddr3_x8_lane_phy #(
    parameter integer WRITE_LATENCY = 5,
    parameter integer READ_LATENCY  = 6
) (
    input wire        i_clk,
    input wire        i_rst,

    input wire        i_lane_wr_valid,
    output wire       o_lane_wr_ready,
    input wire [7:0]  i_lane_wr_data,
    input wire        i_lane_wr_mask,
    input wire        i_lane_wr_last,
    output wire       o_wr_loaded,

    input wire        i_start_write,
    input wire        i_start_read,
    output wire       o_busy,
    output reg        o_error,

    output reg        o_dq_oe,
    output reg        o_dm_oe,
    output reg        o_dqs_oe,
    output reg [7:0]  o_dq_rise,
    output reg [7:0]  o_dq_fall,
    output reg        o_dm_rise,
    output reg        o_dm_fall,
    output reg        o_dqs_rise,
    output reg        o_dqs_fall,

    output wire       o_rd_capturing,
    input wire        i_rd_sample_valid,
    input wire [7:0]  i_dq_rise,
    input wire [7:0]  i_dq_fall,

    output wire       o_lane_rd_valid,
    input wire        i_lane_rd_ready,
    output wire [7:0] o_lane_rd_data
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
        RD_EMIT    = 2'd3;

    reg [7:0] wr_data [0:7];
    reg       wr_mask [0:7];
    reg [2:0] wr_load_index;
    reg       wr_loaded;

    reg [2:0] wr_state;
    reg [15:0] wr_wait_count;
    reg [1:0] wr_pair_index;

    reg [7:0] rd_data [0:7];
    reg [1:0] rd_state;
    reg [15:0] rd_wait_count;
    reg [1:0] rd_pair_index;
    reg [2:0] rd_emit_index;

    wire wr_launch_active = (wr_state != WR_IDLE);
    wire rd_active = (rd_state != RD_IDLE);
    wire wr_accept = i_lane_wr_valid && o_lane_wr_ready;

    assign o_lane_wr_ready = !wr_loaded && !wr_launch_active;
    assign o_wr_loaded = wr_loaded;
    assign o_busy = wr_launch_active || rd_active;
    assign o_rd_capturing = (rd_state == RD_CAPTURE);
    assign o_lane_rd_valid = (rd_state == RD_EMIT);
    assign o_lane_rd_data = rd_data[rd_emit_index];

    integer i;

    initial begin
        wr_load_index = 3'd0;
        wr_loaded = 1'b0;
        wr_state = WR_IDLE;
        wr_wait_count = 16'd0;
        wr_pair_index = 2'd0;
        rd_state = RD_IDLE;
        rd_wait_count = 16'd0;
        rd_pair_index = 2'd0;
        rd_emit_index = 3'd0;
        o_error = 1'b0;
        o_dq_oe = 1'b0;
        o_dm_oe = 1'b0;
        o_dqs_oe = 1'b0;
        o_dq_rise = 8'h00;
        o_dq_fall = 8'h00;
        o_dm_rise = 1'b1;
        o_dm_fall = 1'b1;
        o_dqs_rise = 1'b0;
        o_dqs_fall = 1'b0;
        for (i = 0; i < 8; i = i + 1) begin
            wr_data[i] = 8'h00;
            wr_mask[i] = 1'b1;
            rd_data[i] = 8'h00;
        end
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            wr_load_index <= 3'd0;
            wr_loaded <= 1'b0;
            wr_state <= WR_IDLE;
            wr_wait_count <= 16'd0;
            wr_pair_index <= 2'd0;
            rd_state <= RD_IDLE;
            rd_wait_count <= 16'd0;
            rd_pair_index <= 2'd0;
            rd_emit_index <= 3'd0;
            o_error <= 1'b0;
            o_dq_oe <= 1'b0;
            o_dm_oe <= 1'b0;
            o_dqs_oe <= 1'b0;
            o_dq_rise <= 8'h00;
            o_dq_fall <= 8'h00;
            o_dm_rise <= 1'b1;
            o_dm_fall <= 1'b1;
            o_dqs_rise <= 1'b0;
            o_dqs_fall <= 1'b0;
            for (i = 0; i < 8; i = i + 1) begin
                wr_data[i] <= 8'h00;
                wr_mask[i] <= 1'b1;
                rd_data[i] <= 8'h00;
            end
        end else begin
            o_dq_oe <= 1'b0;
            o_dm_oe <= 1'b0;
            o_dqs_oe <= 1'b0;
            o_dq_rise <= 8'h00;
            o_dq_fall <= 8'h00;
            o_dm_rise <= 1'b1;
            o_dm_fall <= 1'b1;
            o_dqs_rise <= 1'b0;
            o_dqs_fall <= 1'b0;

            if (i_start_write && i_start_read)
                o_error <= 1'b1;

            if (wr_accept) begin
                wr_data[wr_load_index] <= i_lane_wr_data;
                wr_mask[wr_load_index] <= i_lane_wr_mask;
                if (i_lane_wr_last != (wr_load_index == 3'd7))
                    o_error <= 1'b1;

                if (wr_load_index == 3'd7) begin
                    wr_load_index <= 3'd0;
                    wr_loaded <= 1'b1;
                end else begin
                    wr_load_index <= wr_load_index + 3'd1;
                end
            end

            case (wr_state)
                WR_IDLE: begin
                    if (i_start_write && !i_start_read) begin
                        if (!wr_loaded || rd_active) begin
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
                    o_dm_oe <= 1'b1;
                    o_dqs_oe <= 1'b1;
                    o_dq_rise <= wr_data[{wr_pair_index, 1'b0}];
                    o_dq_fall <= wr_data[{wr_pair_index, 1'b1}];
                    o_dm_rise <= wr_mask[{wr_pair_index, 1'b0}];
                    o_dm_fall <= wr_mask[{wr_pair_index, 1'b1}];
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
                        if (wr_launch_active) begin
                            o_error <= 1'b1;
                        end else if (READ_LATENCY <= 0) begin
                            rd_state <= RD_CAPTURE;
                            rd_pair_index <= 2'd0;
                        end else begin
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
                        rd_data[{rd_pair_index, 1'b0}] <= i_dq_rise;
                        rd_data[{rd_pair_index, 1'b1}] <= i_dq_fall;

                        if (rd_pair_index == 2'd3) begin
                            rd_pair_index <= 2'd0;
                            rd_emit_index <= 3'd0;
                            rd_state <= RD_EMIT;
                        end else begin
                            rd_pair_index <= rd_pair_index + 2'd1;
                        end
                    end
                end

                RD_EMIT: begin
                    if (i_lane_rd_ready) begin
                        if (rd_emit_index == 3'd7) begin
                            rd_emit_index <= 3'd0;
                            rd_state <= RD_IDLE;
                        end else begin
                            rd_emit_index <= rd_emit_index + 3'd1;
                        end
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
