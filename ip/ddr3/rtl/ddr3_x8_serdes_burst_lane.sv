// DDR3 x8 SERDES-domain BL8 lane adapter.
//
// This is the small controller/PHY timing block immediately in front of a
// board-specific OSERDES/ISERDES pin shell. It accepts one complete x8 BL8
// write burst as a 64-bit word, presents that word to the SERDES wrapper for
// one divided-clock cycle, and captures one returned 64-bit SERDES word for a
// read burst.
//
// The adapter deliberately does not instantiate Xilinx primitives. Board code
// owns the IOBUF/OSERDES/ISERDES/IDELAY details and read-leveling policy.

`default_nettype none

module ddr3_x8_serdes_burst_lane #(
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

    output wire [63:0] o_serdes_dq_bits,
    output wire [7:0]  o_serdes_dqs_bits,
    output wire [3:0]  o_serdes_dq_oe,
    output wire [3:0]  o_serdes_dqs_oe,
    input wire [63:0]  i_serdes_dq_bits,

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

    localparam integer WR_WAIT_BITS =
        (WRITE_LATENCY <= 1) ? 1 : $clog2(WRITE_LATENCY + 1);
    localparam integer RD_WAIT_BITS =
        (READ_LATENCY <= 1) ? 1 : $clog2(READ_LATENCY + 1);
    localparam [WR_WAIT_BITS-1:0] WR_WAIT_INIT = WRITE_LATENCY;
    localparam [RD_WAIT_BITS-1:0] RD_WAIT_INIT = READ_LATENCY;

    reg [63:0] wr_payload;
    reg        wr_loaded;
    reg [2:0]  wr_state;
    reg [WR_WAIT_BITS-1:0] wr_wait_count;

    reg [1:0]  rd_state;
    reg [RD_WAIT_BITS-1:0] rd_wait_count;

    wire wr_active = (wr_state != WR_IDLE);
    wire rd_active = (rd_state != RD_IDLE);
    wire wr_accept = i_wr_valid && o_wr_ready;
    wire write_data_cycle = (wr_state == WR_DATA);
    wire write_dqs_cycle =
        (wr_state == WR_PREAMBLE) ||
        (wr_state == WR_DATA) ||
        (wr_state == WR_POST);

    assign o_wr_ready = !wr_loaded && !wr_active && !rd_active && !o_rd_valid;
    assign o_wr_loaded = wr_loaded;
    assign o_busy = wr_active || rd_active || o_rd_valid;

    assign o_serdes_dq_bits = wr_payload;
    assign o_serdes_dqs_bits = write_data_cycle ? 8'b0101_0101 : 8'h00;
    assign o_serdes_dq_oe = {4{write_data_cycle}};
    assign o_serdes_dqs_oe = {4{write_dqs_cycle}};

    initial begin
        wr_payload = 64'd0;
        wr_loaded = 1'b0;
        wr_state = WR_IDLE;
        wr_wait_count = {WR_WAIT_BITS{1'b0}};
        rd_state = RD_IDLE;
        rd_wait_count = {RD_WAIT_BITS{1'b0}};
        o_error = 1'b0;
        o_rd_valid = 1'b0;
        o_rd_data = 64'd0;
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            wr_payload <= 64'd0;
            wr_loaded <= 1'b0;
            wr_state <= WR_IDLE;
            wr_wait_count <= {WR_WAIT_BITS{1'b0}};
            rd_state <= RD_IDLE;
            rd_wait_count <= {RD_WAIT_BITS{1'b0}};
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

            case (wr_state)
                WR_IDLE: begin
                    if (i_start_write && !i_start_read) begin
                        if (!wr_loaded || rd_active || o_rd_valid) begin
                            o_error <= 1'b1;
                        end else if (WRITE_LATENCY <= 0) begin
                            wr_state <= WR_PREAMBLE;
                        end else begin
                            wr_state <= WR_WAIT;
                            wr_wait_count <= WR_WAIT_INIT;
                        end
                    end
                end

                WR_WAIT: begin
                    if (wr_wait_count <= 1) begin
                        wr_state <= WR_PREAMBLE;
                        wr_wait_count <= {WR_WAIT_BITS{1'b0}};
                    end else begin
                        wr_wait_count <= wr_wait_count - 1'b1;
                    end
                end

                WR_PREAMBLE: begin
                    wr_state <= WR_DATA;
                end

                WR_DATA: begin
                    wr_state <= WR_POST;
                end

                WR_POST: begin
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
                            rd_state <= RD_CAPTURE;
                        end else begin
                            rd_state <= RD_WAIT;
                            rd_wait_count <= RD_WAIT_INIT;
                        end
                    end
                end

                RD_WAIT: begin
                    if (rd_wait_count <= 1) begin
                        rd_state <= RD_CAPTURE;
                        rd_wait_count <= {RD_WAIT_BITS{1'b0}};
                    end else begin
                        rd_wait_count <= rd_wait_count - 1'b1;
                    end
                end

                RD_CAPTURE: begin
                    o_rd_data <= i_serdes_dq_bits;
                    o_rd_valid <= 1'b1;
                    rd_state <= RD_DONE;
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
