// Dual-clock bridge between the controller line interface and the PHY clock.
//
// The controller side is single-outstanding per channel. Each multi-bit payload
// is held stable until the opposite clock domain acknowledges the matching
// toggle, which keeps the CDC contract explicit and easy to inspect.

`default_nettype none

module ddr3_line_phy_clock_bridge #(
    parameter integer CHANNELS = 2,
    parameter integer LINE_DATA_W = 512,
    parameter integer LINE_BYTES = 64
) (
    input  wire                              i_ctrl_clk,
    input  wire                              i_ctrl_rst,
    input  wire                              i_phy_clk,
    input  wire                              i_phy_rst,

    input  wire [CHANNELS-1:0]               i_ctrl_wr_line_valid,
    output wire [CHANNELS-1:0]               o_ctrl_wr_line_ready,
    input  wire [(CHANNELS*LINE_DATA_W)-1:0] i_ctrl_wr_line_data,
    input  wire [(CHANNELS*LINE_BYTES)-1:0]  i_ctrl_wr_line_mask,
    input  wire [CHANNELS-1:0]               i_ctrl_start_write,
    input  wire [CHANNELS-1:0]               i_ctrl_start_read,
    input  wire [CHANNELS-1:0]               i_ctrl_rd_line_ready,
    output wire [CHANNELS-1:0]               o_ctrl_rd_line_valid,
    output wire [(CHANNELS*LINE_DATA_W)-1:0] o_ctrl_rd_line_data,
    output wire [CHANNELS-1:0]               o_ctrl_rd_line_err,
    output wire [CHANNELS-1:0]               o_ctrl_error,
    output wire [CHANNELS-1:0]               o_ctrl_busy,

    output wire [CHANNELS-1:0]               o_phy_wr_line_valid,
    input  wire [CHANNELS-1:0]               i_phy_wr_line_ready,
    output wire [(CHANNELS*LINE_DATA_W)-1:0] o_phy_wr_line_data,
    output wire [(CHANNELS*LINE_BYTES)-1:0]  o_phy_wr_line_mask,
    output wire [CHANNELS-1:0]               o_phy_start_write,
    output wire [CHANNELS-1:0]               o_phy_start_read,
    output wire [CHANNELS-1:0]               o_phy_rd_line_ready,
    input  wire [CHANNELS-1:0]               i_phy_rd_line_valid,
    input  wire [(CHANNELS*LINE_DATA_W)-1:0] i_phy_rd_line_data,
    input  wire [CHANNELS-1:0]               i_phy_rd_line_err,
    output wire [CHANNELS-1:0]               o_phy_error,
    output wire [CHANNELS-1:0]               o_phy_busy
);
    localparam integer WR_PAYLOAD_W = LINE_DATA_W + LINE_BYTES;
    localparam integer RD_PAYLOAD_W = LINE_DATA_W + 1;

    genvar ch;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_channel
            reg [WR_PAYLOAD_W-1:0] ctrl_wr_payload = {WR_PAYLOAD_W{1'b0}};
            reg                    ctrl_wr_req_tog = 1'b0;
            reg                    ctrl_wr_busy = 1'b0;
            reg                    ctrl_wr_ack_seen = 1'b0;
            reg [2:0]              ctrl_wr_ack_sync = 3'b000;

            reg                    ctrl_sw_req_tog = 1'b0;
            reg                    ctrl_sw_busy = 1'b0;
            reg                    ctrl_sw_ack_seen = 1'b0;
            reg [2:0]              ctrl_sw_ack_sync = 3'b000;

            reg                    ctrl_sr_req_tog = 1'b0;
            reg                    ctrl_sr_busy = 1'b0;
            reg                    ctrl_sr_ack_seen = 1'b0;
            reg [2:0]              ctrl_sr_ack_sync = 3'b000;

            reg [RD_PAYLOAD_W-1:0] ctrl_rd_payload = {RD_PAYLOAD_W{1'b0}};
            reg                    ctrl_rd_valid = 1'b0;
            reg                    ctrl_rd_ack_tog = 1'b0;
            reg                    ctrl_rd_req_seen = 1'b0;
            reg [2:0]              ctrl_rd_req_sync = 3'b000;
            reg                    ctrl_error = 1'b0;

            reg [2:0]              phy_wr_req_sync = 3'b000;
            reg                    phy_wr_req_seen = 1'b0;
            reg [WR_PAYLOAD_W-1:0] phy_wr_payload = {WR_PAYLOAD_W{1'b0}};
            reg                    phy_wr_valid = 1'b0;
            reg                    phy_wr_ack_tog = 1'b0;
            reg                    phy_wr_ready_q = 1'b0;

            reg [2:0]              phy_sw_req_sync = 3'b000;
            reg                    phy_sw_req_seen = 1'b0;
            reg                    phy_sw_ack_tog = 1'b0;
            reg                    phy_start_write = 1'b0;

            reg [2:0]              phy_sr_req_sync = 3'b000;
            reg                    phy_sr_req_seen = 1'b0;
            reg                    phy_sr_ack_tog = 1'b0;
            reg                    phy_start_read = 1'b0;

            reg [RD_PAYLOAD_W-1:0] phy_rd_payload = {RD_PAYLOAD_W{1'b0}};
            reg                    phy_rd_req_tog = 1'b0;
            reg                    phy_rd_busy = 1'b0;
            reg                    phy_rd_ack_seen = 1'b0;
            reg [2:0]              phy_rd_ack_sync = 3'b000;
            reg                    phy_rd_line_valid_q = 1'b0;
            reg [LINE_DATA_W-1:0]  phy_rd_line_data_q = {LINE_DATA_W{1'b0}};
            reg                    phy_rd_line_err_q = 1'b0;
            reg                    phy_error = 1'b0;

            wire ctrl_wr_accept =
                i_ctrl_wr_line_valid[ch] && o_ctrl_wr_line_ready[ch];
            wire ctrl_rd_accept =
                ctrl_rd_valid && i_ctrl_rd_line_ready[ch];
            wire phy_wr_accept =
                phy_wr_valid && phy_wr_ready_q;
            wire phy_rd_accept =
                phy_rd_line_valid_q && o_phy_rd_line_ready[ch];

            assign o_ctrl_wr_line_ready[ch] = !ctrl_wr_busy;
            assign o_ctrl_rd_line_valid[ch] = ctrl_rd_valid;
            assign o_ctrl_rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W] =
                ctrl_rd_payload[0 +: LINE_DATA_W];
            assign o_ctrl_rd_line_err[ch] = ctrl_rd_payload[LINE_DATA_W];
            assign o_ctrl_error[ch] = ctrl_error;
            assign o_ctrl_busy[ch] =
                ctrl_wr_busy || ctrl_sw_busy || ctrl_sr_busy || ctrl_rd_valid;

            assign o_phy_wr_line_valid[ch] = phy_wr_valid;
            assign o_phy_wr_line_data[ch*LINE_DATA_W +: LINE_DATA_W] =
                phy_wr_payload[0 +: LINE_DATA_W];
            assign o_phy_wr_line_mask[ch*LINE_BYTES +: LINE_BYTES] =
                phy_wr_payload[LINE_DATA_W +: LINE_BYTES];
            assign o_phy_start_write[ch] = phy_start_write;
            assign o_phy_start_read[ch] = phy_start_read;
            assign o_phy_rd_line_ready[ch] = !phy_rd_busy;
            assign o_phy_error[ch] = phy_error;
            assign o_phy_busy[ch] =
                phy_wr_valid || phy_rd_busy ||
                (phy_sw_req_sync[2] != phy_sw_req_seen) ||
                (phy_sr_req_sync[2] != phy_sr_req_seen);

            always @(posedge i_ctrl_clk) begin
                if (i_ctrl_rst) begin
                    ctrl_wr_payload <= {WR_PAYLOAD_W{1'b0}};
                    ctrl_wr_req_tog <= 1'b0;
                    ctrl_wr_busy <= 1'b0;
                    ctrl_wr_ack_seen <= 1'b0;
                    ctrl_wr_ack_sync <= 3'b000;
                    ctrl_sw_req_tog <= 1'b0;
                    ctrl_sw_busy <= 1'b0;
                    ctrl_sw_ack_seen <= 1'b0;
                    ctrl_sw_ack_sync <= 3'b000;
                    ctrl_sr_req_tog <= 1'b0;
                    ctrl_sr_busy <= 1'b0;
                    ctrl_sr_ack_seen <= 1'b0;
                    ctrl_sr_ack_sync <= 3'b000;
                    ctrl_rd_payload <= {RD_PAYLOAD_W{1'b0}};
                    ctrl_rd_valid <= 1'b0;
                    ctrl_rd_ack_tog <= 1'b0;
                    ctrl_rd_req_seen <= 1'b0;
                    ctrl_rd_req_sync <= 3'b000;
                    ctrl_error <= 1'b0;
                end else begin
                    ctrl_wr_ack_sync <= {ctrl_wr_ack_sync[1:0],
                                         phy_wr_ack_tog};
                    ctrl_sw_ack_sync <= {ctrl_sw_ack_sync[1:0],
                                         phy_sw_ack_tog};
                    ctrl_sr_ack_sync <= {ctrl_sr_ack_sync[1:0],
                                         phy_sr_ack_tog};
                    ctrl_rd_req_sync <= {ctrl_rd_req_sync[1:0],
                                         phy_rd_req_tog};

                    if (ctrl_wr_ack_sync[2] != ctrl_wr_ack_seen) begin
                        ctrl_wr_ack_seen <= ctrl_wr_ack_sync[2];
                        ctrl_wr_busy <= 1'b0;
                    end

                    if (ctrl_sw_ack_sync[2] != ctrl_sw_ack_seen) begin
                        ctrl_sw_ack_seen <= ctrl_sw_ack_sync[2];
                        ctrl_sw_busy <= 1'b0;
                    end

                    if (ctrl_sr_ack_sync[2] != ctrl_sr_ack_seen) begin
                        ctrl_sr_ack_seen <= ctrl_sr_ack_sync[2];
                        ctrl_sr_busy <= 1'b0;
                    end

                    if (ctrl_wr_accept) begin
                        ctrl_wr_payload <= {
                            i_ctrl_wr_line_mask[ch*LINE_BYTES +: LINE_BYTES],
                            i_ctrl_wr_line_data[ch*LINE_DATA_W +: LINE_DATA_W]
                        };
                        ctrl_wr_req_tog <= !ctrl_wr_req_tog;
                        ctrl_wr_busy <= 1'b1;
                    end

                    if (i_ctrl_start_write[ch]) begin
                        if (ctrl_sw_busy) begin
                            ctrl_error <= 1'b1;
                        end else begin
                            ctrl_sw_req_tog <= !ctrl_sw_req_tog;
                            ctrl_sw_busy <= 1'b1;
                        end
                    end

                    if (i_ctrl_start_read[ch]) begin
                        if (ctrl_sr_busy) begin
                            ctrl_error <= 1'b1;
                        end else begin
                            ctrl_sr_req_tog <= !ctrl_sr_req_tog;
                            ctrl_sr_busy <= 1'b1;
                        end
                    end

                    if ((ctrl_rd_req_sync[2] != ctrl_rd_req_seen) &&
                        !ctrl_rd_valid) begin
                        ctrl_rd_req_seen <= ctrl_rd_req_sync[2];
                        ctrl_rd_payload <= phy_rd_payload;
                        ctrl_rd_valid <= 1'b1;
                    end else if ((ctrl_rd_req_sync[2] != ctrl_rd_req_seen) &&
                                 ctrl_rd_valid) begin
                        ctrl_error <= 1'b1;
                    end

                    if (ctrl_rd_accept) begin
                        ctrl_rd_valid <= 1'b0;
                        ctrl_rd_ack_tog <= !ctrl_rd_ack_tog;
                    end
                end
            end

            always @(posedge i_phy_clk) begin
                if (i_phy_rst) begin
                    phy_wr_req_sync <= 3'b000;
                    phy_wr_req_seen <= 1'b0;
                    phy_wr_payload <= {WR_PAYLOAD_W{1'b0}};
                    phy_wr_valid <= 1'b0;
                    phy_wr_ack_tog <= 1'b0;
                    phy_wr_ready_q <= 1'b0;
                    phy_sw_req_sync <= 3'b000;
                    phy_sw_req_seen <= 1'b0;
                    phy_sw_ack_tog <= 1'b0;
                    phy_start_write <= 1'b0;
                    phy_sr_req_sync <= 3'b000;
                    phy_sr_req_seen <= 1'b0;
                    phy_sr_ack_tog <= 1'b0;
                    phy_start_read <= 1'b0;
                    phy_rd_payload <= {RD_PAYLOAD_W{1'b0}};
                    phy_rd_req_tog <= 1'b0;
                    phy_rd_busy <= 1'b0;
                    phy_rd_ack_seen <= 1'b0;
                    phy_rd_ack_sync <= 3'b000;
                    phy_rd_line_valid_q <= 1'b0;
                    phy_rd_line_data_q <= {LINE_DATA_W{1'b0}};
                    phy_rd_line_err_q <= 1'b0;
                    phy_error <= 1'b0;
                end else begin
                    phy_start_write <= 1'b0;
                    phy_start_read <= 1'b0;
                    phy_wr_ready_q <= i_phy_wr_line_ready[ch];
                    phy_rd_line_valid_q <= i_phy_rd_line_valid[ch];
                    phy_rd_line_data_q <=
                        i_phy_rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W];
                    phy_rd_line_err_q <= i_phy_rd_line_err[ch];
                    phy_wr_req_sync <= {phy_wr_req_sync[1:0],
                                        ctrl_wr_req_tog};
                    phy_sw_req_sync <= {phy_sw_req_sync[1:0],
                                        ctrl_sw_req_tog};
                    phy_sr_req_sync <= {phy_sr_req_sync[1:0],
                                        ctrl_sr_req_tog};
                    phy_rd_ack_sync <= {phy_rd_ack_sync[1:0],
                                        ctrl_rd_ack_tog};

                    if (phy_wr_req_sync[2] != phy_wr_req_seen) begin
                        if (phy_wr_valid) begin
                            phy_error <= 1'b1;
                        end else begin
                            phy_wr_req_seen <= phy_wr_req_sync[2];
                            phy_wr_payload <= ctrl_wr_payload;
                            phy_wr_valid <= 1'b1;
                        end
                    end

                    if (phy_wr_accept) begin
                        phy_wr_valid <= 1'b0;
                        phy_wr_ack_tog <= !phy_wr_ack_tog;
                    end

                    if (phy_sw_req_sync[2] != phy_sw_req_seen) begin
                        phy_sw_req_seen <= phy_sw_req_sync[2];
                        phy_start_write <= 1'b1;
                        phy_sw_ack_tog <= !phy_sw_ack_tog;
                    end

                    if (phy_sr_req_sync[2] != phy_sr_req_seen) begin
                        phy_sr_req_seen <= phy_sr_req_sync[2];
                        phy_start_read <= 1'b1;
                        phy_sr_ack_tog <= !phy_sr_ack_tog;
                    end

                    if (phy_rd_accept) begin
                        phy_rd_payload <= {
                            phy_rd_line_err_q,
                            phy_rd_line_data_q
                        };
                        phy_rd_req_tog <= !phy_rd_req_tog;
                        phy_rd_busy <= 1'b1;
                    end

                    if (phy_rd_ack_sync[2] != phy_rd_ack_seen) begin
                        phy_rd_ack_seen <= phy_rd_ack_sync[2];
                        phy_rd_busy <= 1'b0;
                    end
                end
            end
        end
    endgenerate
endmodule

`default_nettype wire
