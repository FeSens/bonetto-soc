`default_nettype none

module ddr3_idelay_cal_cdc #(
    parameter integer PHY_LANES = 18,
    parameter integer PHY_BYTE_LANES = 9,
    parameter integer TAP_W = 5,
    parameter integer COUNT_W = 8
) (
    input  wire                         i_ctrl_clk,
    input  wire                         i_ctrl_rst,
    input  wire                         i_phy_clk,
    input  wire                         i_phy_rst,

    input  wire [PHY_LANES-1:0]         i_ctrl_load_lane,
    input  wire [TAP_W-1:0]             i_ctrl_tap,
    input  wire                         i_ctrl_channel,

    output wire [PHY_LANES-1:0]         o_phy_load,
    output wire [PHY_LANES*TAP_W-1:0]   o_phy_tap,

    output reg  [4:0]                   o_ctrl_req_lane,
    output reg  [TAP_W-1:0]             o_ctrl_req_tap,
    output reg                          o_ctrl_req_channel,
    output reg  [COUNT_W-1:0]           o_ctrl_req_count,
    output reg  [4:0]                   o_ctrl_seen_lane,
    output reg  [TAP_W-1:0]             o_ctrl_seen_tap,
    output reg  [COUNT_W-1:0]           o_ctrl_seen_count,
    output wire                         o_ctrl_pending
);
    wire [PHY_LANES-1:0] ctrl_load_phy_lane;
    reg  [PHY_LANES-1:0] ctrl_toggle = {PHY_LANES{1'b0}};
    reg  [PHY_LANES*TAP_W-1:0] ctrl_tap = {(PHY_LANES*TAP_W){1'b0}};

    genvar map_lane;
    generate
        for (map_lane = 0; map_lane < PHY_LANES;
             map_lane = map_lane + 1) begin : gen_lane_map
            localparam integer MAP_CH = map_lane / PHY_BYTE_LANES;
            localparam integer MAP_BYTE = map_lane % PHY_BYTE_LANES;
            if (MAP_CH == 0) begin : gen_ch0
                assign ctrl_load_phy_lane[map_lane] =
                    !i_ctrl_channel && i_ctrl_load_lane[map_lane];
            end else begin : gen_ch1
                assign ctrl_load_phy_lane[map_lane] =
                    i_ctrl_channel ? i_ctrl_load_lane[MAP_BYTE] :
                                     i_ctrl_load_lane[map_lane];
            end
        end
    endgenerate

    reg [PHY_LANES-1:0] phy_toggle_meta = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] phy_toggle_sync = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] phy_toggle_last = {PHY_LANES{1'b0}};
    wire [PHY_LANES-1:0] phy_toggle_seen =
        phy_toggle_last ^ phy_toggle_sync;

    reg [PHY_LANES*TAP_W-1:0] phy_tap_meta = {(PHY_LANES*TAP_W){1'b0}};
    reg [PHY_LANES*TAP_W-1:0] phy_tap_sync = {(PHY_LANES*TAP_W){1'b0}};
    reg [PHY_LANES*TAP_W-1:0] phy_tap_load = {(PHY_LANES*TAP_W){1'b0}};
    reg [PHY_LANES-1:0] phy_load_pending = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] phy_load = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] phy_ack_toggle = {PHY_LANES{1'b0}};

    assign o_phy_load = phy_load;
    assign o_phy_tap = phy_tap_load;

    reg [PHY_LANES-1:0] ctrl_ack_meta = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] ctrl_ack_sync = {PHY_LANES{1'b0}};
    reg [PHY_LANES-1:0] ctrl_ack_last = {PHY_LANES{1'b0}};
    wire [PHY_LANES-1:0] ctrl_ack_seen = ctrl_ack_last ^ ctrl_ack_sync;

    assign o_ctrl_pending = |(ctrl_toggle ^ ctrl_ack_last);

    integer ctrl_lane_idx;
    always @(posedge i_ctrl_clk) begin
        if (i_ctrl_rst) begin
            ctrl_toggle <= {PHY_LANES{1'b0}};
            ctrl_tap <= {(PHY_LANES*TAP_W){1'b0}};
            ctrl_ack_meta <= {PHY_LANES{1'b0}};
            ctrl_ack_sync <= {PHY_LANES{1'b0}};
            ctrl_ack_last <= {PHY_LANES{1'b0}};
            o_ctrl_req_lane <= 5'd0;
            o_ctrl_req_tap <= {TAP_W{1'b0}};
            o_ctrl_req_channel <= 1'b0;
            o_ctrl_req_count <= {COUNT_W{1'b0}};
            o_ctrl_seen_lane <= 5'd0;
            o_ctrl_seen_tap <= {TAP_W{1'b0}};
            o_ctrl_seen_count <= {COUNT_W{1'b0}};
        end else begin
            ctrl_ack_meta <= phy_ack_toggle;
            ctrl_ack_sync <= ctrl_ack_meta;
            ctrl_ack_last <= ctrl_ack_sync;

            for (ctrl_lane_idx = 0; ctrl_lane_idx < PHY_LANES;
                 ctrl_lane_idx = ctrl_lane_idx + 1) begin
                if (ctrl_load_phy_lane[ctrl_lane_idx]) begin
                    ctrl_toggle[ctrl_lane_idx] <=
                        !ctrl_toggle[ctrl_lane_idx];
                    ctrl_tap[ctrl_lane_idx*TAP_W +: TAP_W] <= i_ctrl_tap;
                    o_ctrl_req_lane <= ctrl_lane_idx[4:0];
                    o_ctrl_req_tap <= i_ctrl_tap;
                    o_ctrl_req_channel <= i_ctrl_channel;
                    o_ctrl_req_count <= o_ctrl_req_count + 1'b1;
                end

                if (ctrl_ack_seen[ctrl_lane_idx]) begin
                    o_ctrl_seen_lane <= ctrl_lane_idx[4:0];
                    o_ctrl_seen_tap <=
                        ctrl_tap[ctrl_lane_idx*TAP_W +: TAP_W];
                    o_ctrl_seen_count <= o_ctrl_seen_count + 1'b1;
                end
            end
        end
    end

    integer phy_lane_idx;
    always @(posedge i_phy_clk) begin
        if (i_phy_rst) begin
            phy_toggle_meta <= {PHY_LANES{1'b0}};
            phy_toggle_sync <= {PHY_LANES{1'b0}};
            phy_toggle_last <= {PHY_LANES{1'b0}};
            phy_tap_meta <= {(PHY_LANES*TAP_W){1'b0}};
            phy_tap_sync <= {(PHY_LANES*TAP_W){1'b0}};
            phy_tap_load <= {(PHY_LANES*TAP_W){1'b0}};
            phy_load_pending <= {PHY_LANES{1'b0}};
            phy_load <= {PHY_LANES{1'b0}};
            phy_ack_toggle <= {PHY_LANES{1'b0}};
        end else begin
            phy_toggle_meta <= ctrl_toggle;
            phy_toggle_sync <= phy_toggle_meta;
            phy_toggle_last <= phy_toggle_sync;
            phy_tap_meta <= ctrl_tap;
            phy_tap_sync <= phy_tap_meta;
            phy_load_pending <= phy_toggle_seen;
            phy_load <= phy_load_pending;

            for (phy_lane_idx = 0; phy_lane_idx < PHY_LANES;
                 phy_lane_idx = phy_lane_idx + 1) begin
                if (phy_toggle_seen[phy_lane_idx])
                    phy_tap_load[phy_lane_idx*TAP_W +: TAP_W] <=
                        phy_tap_sync[phy_lane_idx*TAP_W +: TAP_W];

                if (phy_load[phy_lane_idx])
                    phy_ack_toggle[phy_lane_idx] <=
                        phy_toggle_last[phy_lane_idx];
            end
        end
    end
endmodule

`default_nettype wire
