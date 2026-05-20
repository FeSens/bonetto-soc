// Single-channel Wishbone-to-DDR3 BL8 data bridge.
//
// This block keeps the existing packetized PHY-side interface, but the bus and
// scheduler boundary is now line based. A write request must present the whole
// 64-byte BL8 channel line before the scheduler can accept the command. The
// packetizer then serializes that already-captured line when the scheduler
// reaches the matching RD/WR data window.

`default_nettype none

module ddr3_wb_channel #(
    parameter integer WB_ADDR_W = 8,
    parameter integer LANES     = 8,
    parameter integer WB_DATA_W = 32,
    localparam integer LINE_BYTES     = LANES * 8,
    localparam integer LINE_DATA_W    = LINE_BYTES * 8,
    localparam integer LINE_MASK_W    = LINE_BYTES,
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8),
    localparam integer WORD_INDEX_W =
        (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE),
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W
) (
    input wire                     i_clk,
    input wire                     i_rst,

    input wire                     i_wb_cyc,
    input wire                     i_wb_stb,
    input wire                     i_wb_we,
    input wire [WB_ADDR_W-1:0]     i_wb_adr,
    input wire [WB_DATA_W-1:0]     i_wb_dat,
    input wire [(WB_DATA_W/8)-1:0] i_wb_sel,
    output wire                    o_wb_stall,
    output wire                    o_wb_ack,
    output wire [WB_DATA_W-1:0]    o_wb_dat,
    output wire                    o_wb_err,

    output wire                    o_cmd_valid,
    input wire                     i_cmd_ready,
    output wire                    o_cmd_write,
    output wire [LINE_ADDR_W-1:0]  o_cmd_line_addr,
    input wire                     i_xfer_start,

    output wire                    o_busy,
    output wire                    o_line_done,
    output wire                    o_line_rd_valid,

    output wire [LANES-1:0]        o_phy_wr_valid,
    input wire [LANES-1:0]         i_phy_wr_ready,
    output wire [(LANES*8)-1:0]    o_phy_wr_data,
    output wire [LANES-1:0]        o_phy_wr_mask,
    output wire [LANES-1:0]        o_phy_wr_last,

    output wire [LANES-1:0]        o_phy_rd_ready,
    input wire [LANES-1:0]         i_phy_rd_valid,
    input wire [(LANES*8)-1:0]     i_phy_rd_data
);
    wire bridge_wb_stall;
    wire bridge_cmd_valid;
    wire bridge_cmd_write;
    wire [LINE_ADDR_W-1:0] bridge_cmd_line_addr;
    wire [LINE_DATA_W-1:0] bridge_wr_line_data;
    wire [LINE_MASK_W-1:0] bridge_wr_line_mask;

    wire line_ready;
    wire line_busy;
    wire line_rd_valid;
    wire [LINE_DATA_W-1:0] line_rd_data;

    reg pending_xfer;
    reg pending_write;
    reg [LINE_DATA_W-1:0] pending_wr_data;
    reg [LINE_MASK_W-1:0] pending_wr_mask;

    wire adapter_ready = line_ready && !pending_xfer;
    wire bridge_wb_stb = i_wb_stb && adapter_ready;
    wire cmd_accept = bridge_cmd_valid && i_cmd_ready;
    wire line_start = i_xfer_start && line_ready &&
                      (pending_xfer || cmd_accept);
    wire line_write = pending_xfer ? pending_write : bridge_cmd_write;
    wire [LINE_DATA_W-1:0] line_wr_data =
        pending_xfer ? pending_wr_data : bridge_wr_line_data;
    wire [LINE_MASK_W-1:0] line_wr_mask =
        pending_xfer ? pending_wr_mask : bridge_wr_line_mask;

    assign o_wb_stall = bridge_wb_stall || !adapter_ready;
    assign o_cmd_valid = bridge_cmd_valid;
    assign o_cmd_write = bridge_cmd_write;
    assign o_cmd_line_addr = bridge_cmd_line_addr;
    assign o_busy = bridge_wb_stall || pending_xfer || line_busy;
    assign o_line_rd_valid = line_rd_valid;

    always @(posedge i_clk) begin
        if (i_rst) begin
            pending_xfer <= 1'b0;
            pending_write <= 1'b0;
            pending_wr_data <= {LINE_DATA_W{1'b0}};
            pending_wr_mask <= {LINE_MASK_W{1'b1}};
        end else begin
            if (cmd_accept && !line_start) begin
                pending_xfer <= 1'b1;
                pending_write <= bridge_cmd_write;
                pending_wr_data <= bridge_wr_line_data;
                pending_wr_mask <= bridge_wr_line_mask;
            end else if (line_start) begin
                pending_xfer <= 1'b0;
            end
        end
    end

    ddr3_wb_line_channel #(
        .WB_ADDR_W(WB_ADDR_W),
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W)
    ) u_bridge (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wb_cyc(i_wb_cyc),
        .i_wb_stb(bridge_wb_stb),
        .i_wb_we(i_wb_we),
        .i_wb_adr(i_wb_adr),
        .i_wb_dat(i_wb_dat),
        .i_wb_sel(i_wb_sel),
        .o_wb_stall(bridge_wb_stall),
        .o_wb_ack(o_wb_ack),
        .o_wb_dat(o_wb_dat),
        .o_wb_err(o_wb_err),
        .o_cmd_valid(bridge_cmd_valid),
        .i_cmd_ready(i_cmd_ready),
        .o_cmd_write(bridge_cmd_write),
        .o_cmd_line_addr(bridge_cmd_line_addr),
        .i_xfer_start(line_start),
        .o_phy_wr_line_valid(),
        .i_phy_wr_line_ready(adapter_ready),
        .i_phy_wr_line_loaded(1'b1),
        .o_phy_wr_line_data(bridge_wr_line_data),
        .o_phy_wr_line_mask(bridge_wr_line_mask),
        .o_phy_rd_line_ready(),
        .i_phy_rd_line_valid(line_rd_valid),
        .i_phy_rd_line_data(line_rd_data),
        .i_phy_rd_line_err(1'b0)
    );

    ddr3_channel_line #(
        .LANES(LANES)
    ) u_line (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_start(line_start),
        .o_ready(line_ready),
        .i_write(line_write),
        .i_wr_data(line_wr_data),
        .i_wr_mask(line_wr_mask),
        .o_busy(line_busy),
        .o_done(o_line_done),
        .o_rd_valid(line_rd_valid),
        .o_rd_data(line_rd_data),
        .o_phy_wr_valid(o_phy_wr_valid),
        .i_phy_wr_ready(i_phy_wr_ready),
        .o_phy_wr_data(o_phy_wr_data),
        .o_phy_wr_mask(o_phy_wr_mask),
        .o_phy_wr_last(o_phy_wr_last),
        .o_phy_rd_ready(o_phy_rd_ready),
        .i_phy_rd_valid(i_phy_rd_valid),
        .i_phy_rd_data(i_phy_rd_data)
    );
endmodule

`default_nettype wire
