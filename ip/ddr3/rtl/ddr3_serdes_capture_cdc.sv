`default_nettype none

module ddr3_serdes_capture_cdc #(
    parameter integer PHY_LANES = 18,
    parameter integer TAP_W = 5,
    parameter integer COUNT_W = 8
) (
    input  wire                         i_phy_clk,
    input  wire                         i_phy_rst,
    input  wire                         i_ctrl_clk,
    input  wire                         i_ctrl_rst,

    input  wire [PHY_LANES-1:0]         i_phy_capture_lane,
    input  wire [PHY_LANES*TAP_W-1:0]   i_phy_tap,
    input  wire [PHY_LANES*64-1:0]      i_phy_dq_bits,
    input  wire [PHY_LANES*8-1:0]       i_phy_dqs_bits,
    input  wire [PHY_LANES*8-1:0]       i_phy_dqs_edge_rise_dq,
    input  wire [PHY_LANES*8-1:0]       i_phy_dqs_edge_fall_dq,
    input  wire [PHY_LANES*8-1:0]       i_phy_dqs_edge_rise_count,
    input  wire [PHY_LANES*8-1:0]       i_phy_dqs_edge_fall_count,

    output reg                          o_ctrl_valid,
    output reg  [4:0]                   o_ctrl_lane,
    output reg  [TAP_W-1:0]             o_ctrl_tap,
    output reg  [63:0]                  o_ctrl_dq_bits,
    output reg  [7:0]                   o_ctrl_dqs_bits,
    output reg  [7:0]                   o_ctrl_dqs_edge_rise_dq,
    output reg  [7:0]                   o_ctrl_dqs_edge_fall_dq,
    output reg  [7:0]                   o_ctrl_dqs_edge_rise_count,
    output reg  [7:0]                   o_ctrl_dqs_edge_fall_count,
    output reg  [COUNT_W-1:0]           o_ctrl_count
);
    localparam integer SNAP_W = 5 + TAP_W + 64 + 8 + 32 + COUNT_W;

    // Debug snapshot bridge for host-driven SET_CAL commands. The source
    // snapshot remains stable until the next JTAG tap-load request, so the
    // slow control domain can sample the wide payload after the toggle crosses.
    reg [COUNT_W-1:0] phy_count = {COUNT_W{1'b0}};
    reg [SNAP_W-1:0] phy_snapshot = {SNAP_W{1'b0}};
    reg phy_toggle = 1'b0;

    integer phy_lane_idx;
    always @(posedge i_phy_clk) begin
        if (i_phy_rst) begin
            phy_count <= {COUNT_W{1'b0}};
            phy_snapshot <= {SNAP_W{1'b0}};
            phy_toggle <= 1'b0;
        end else begin
            for (phy_lane_idx = 0; phy_lane_idx < PHY_LANES;
                 phy_lane_idx = phy_lane_idx + 1) begin
                if (i_phy_capture_lane[phy_lane_idx]) begin
                    phy_count <= phy_count + 1'b1;
                    phy_snapshot <= {
                        phy_lane_idx[4:0],
                        i_phy_tap[phy_lane_idx*TAP_W +: TAP_W],
                        i_phy_dq_bits[phy_lane_idx*64 +: 64],
                        i_phy_dqs_bits[phy_lane_idx*8 +: 8],
                        i_phy_dqs_edge_rise_dq[phy_lane_idx*8 +: 8],
                        i_phy_dqs_edge_fall_dq[phy_lane_idx*8 +: 8],
                        i_phy_dqs_edge_rise_count[phy_lane_idx*8 +: 8],
                        i_phy_dqs_edge_fall_count[phy_lane_idx*8 +: 8],
                        phy_count + 1'b1
                    };
                    phy_toggle <= !phy_toggle;
                end
            end
        end
    end

    reg ctrl_toggle_meta = 1'b0;
    reg ctrl_toggle_sync = 1'b0;
    reg ctrl_toggle_last = 1'b0;
    wire ctrl_seen = ctrl_toggle_last ^ ctrl_toggle_sync;

    reg [SNAP_W-1:0] ctrl_snapshot_meta = {SNAP_W{1'b0}};
    reg [SNAP_W-1:0] ctrl_snapshot_sync = {SNAP_W{1'b0}};

    always @(posedge i_ctrl_clk) begin
        if (i_ctrl_rst) begin
            ctrl_toggle_meta <= 1'b0;
            ctrl_toggle_sync <= 1'b0;
            ctrl_toggle_last <= 1'b0;
            ctrl_snapshot_meta <= {SNAP_W{1'b0}};
            ctrl_snapshot_sync <= {SNAP_W{1'b0}};
            o_ctrl_valid <= 1'b0;
            o_ctrl_lane <= 5'd0;
            o_ctrl_tap <= {TAP_W{1'b0}};
            o_ctrl_dq_bits <= 64'd0;
            o_ctrl_dqs_bits <= 8'd0;
            o_ctrl_dqs_edge_rise_dq <= 8'd0;
            o_ctrl_dqs_edge_fall_dq <= 8'd0;
            o_ctrl_dqs_edge_rise_count <= 8'd0;
            o_ctrl_dqs_edge_fall_count <= 8'd0;
            o_ctrl_count <= {COUNT_W{1'b0}};
        end else begin
            ctrl_toggle_meta <= phy_toggle;
            ctrl_toggle_sync <= ctrl_toggle_meta;
            ctrl_toggle_last <= ctrl_toggle_sync;
            ctrl_snapshot_meta <= phy_snapshot;
            ctrl_snapshot_sync <= ctrl_snapshot_meta;

            if (ctrl_seen) begin
                {
                    o_ctrl_lane,
                    o_ctrl_tap,
                    o_ctrl_dq_bits,
                    o_ctrl_dqs_bits,
                    o_ctrl_dqs_edge_rise_dq,
                    o_ctrl_dqs_edge_fall_dq,
                    o_ctrl_dqs_edge_rise_count,
                    o_ctrl_dqs_edge_fall_count,
                    o_ctrl_count
                } <= ctrl_snapshot_sync;
                o_ctrl_valid <= 1'b1;
            end
        end
    end
endmodule

`default_nettype wire
