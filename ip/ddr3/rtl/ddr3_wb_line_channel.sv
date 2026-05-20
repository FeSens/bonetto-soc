// Wishbone-to-DDR3 line bridge with a line-level PHY contract.
//
// A real DDR3 PHY cannot accept one byte per slow controller cycle after the
// WR command has already issued. This bridge keeps the bus and scheduler
// contract single-outstanding, but presents the whole BL8 channel line before
// the scheduler may accept the WR command. The PHY then reports when the line
// is staged in the write-data path, so the scheduler's WR command cannot run
// ahead of the DDR write data.

`default_nettype none

module ddr3_wb_line_channel #(
    parameter integer WB_ADDR_W  = 8,
    parameter integer LANES      = 8,
    parameter integer WB_DATA_W  = 32,
    parameter integer PHY_HAS_BYTE_MASK = 1,
    localparam integer LINE_BYTES     = LANES * 8,
    localparam integer LINE_DATA_W    = LINE_BYTES * 8,
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8),
    localparam integer WORD_INDEX_W   =
        (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE),
    localparam integer LINE_ADDR_W    = WB_ADDR_W - WORD_INDEX_W
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
    output reg                     o_wb_ack,
    output reg [WB_DATA_W-1:0]     o_wb_dat,
    output reg                     o_wb_err,

    output wire                    o_cmd_valid,
    input wire                     i_cmd_ready,
    output wire                    o_cmd_write,
    output wire [LINE_ADDR_W-1:0]  o_cmd_line_addr,
    input wire                     i_xfer_start,

    output wire                    o_phy_wr_line_valid,
    input wire                     i_phy_wr_line_ready,
    input wire                     i_phy_wr_line_loaded,
    output wire [LINE_DATA_W-1:0]  o_phy_wr_line_data,
    output wire [LINE_BYTES-1:0]   o_phy_wr_line_mask,

    output wire                    o_phy_rd_line_ready,
    input wire                     i_phy_rd_line_valid,
    input wire [LINE_DATA_W-1:0]   i_phy_rd_line_data,
    input wire                     i_phy_rd_line_err
);
    localparam integer WB_BYTES = WB_DATA_W / 8;

    localparam [2:0]
        ST_IDLE         = 3'd0,
        ST_CMD          = 3'd1,
        ST_WAIT_RD_XFER = 3'd2,
        ST_WAIT_RD_DATA = 3'd3,
        ST_RMW_CMD      = 3'd4;

    reg [2:0] state;
    reg req_write;
    reg [LINE_ADDR_W-1:0] req_line_addr;
    reg [WORD_INDEX_W-1:0] req_word_index;
    reg [LINE_DATA_W-1:0] req_wr_data;
    reg [LINE_BYTES-1:0] req_wr_mask;
    reg wr_line_sent;
    reg wr_line_loaded;

    wire wb_accept = i_wb_cyc && i_wb_stb && !o_wb_stall;
    wire cmd_is_write = (state == ST_RMW_CMD) ||
        ((state == ST_CMD) && req_write && (PHY_HAS_BYTE_MASK != 0));
    wire cmd_can_issue = !cmd_is_write || wr_line_loaded;
    wire cmd_accept = o_cmd_valid && i_cmd_ready;
    wire wr_line_accept =
        o_phy_wr_line_valid && i_phy_wr_line_ready;

    assign o_wb_stall = (state != ST_IDLE);
    assign o_cmd_valid =
        ((state == ST_CMD) || (state == ST_RMW_CMD)) && cmd_can_issue;
    assign o_cmd_write = cmd_is_write;
    assign o_cmd_line_addr = req_line_addr;

    assign o_phy_wr_line_valid = cmd_is_write && !wr_line_sent;
    assign o_phy_wr_line_data = req_wr_data;
    assign o_phy_wr_line_mask = (PHY_HAS_BYTE_MASK != 0)
        ? req_wr_mask : {LINE_BYTES{1'b0}};

    // Some PHYs sample read-line readiness on the same cycle as the scheduler's
    // RD transfer-start pulse, before this bridge advances into WAIT_RD_DATA.
    assign o_phy_rd_line_ready =
        i_wb_cyc &&
        ((state == ST_WAIT_RD_DATA) ||
         ((state == ST_WAIT_RD_XFER) && i_xfer_start));

    function [LINE_DATA_W-1:0] place_word_data;
        input [WB_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            place_word_data = {LINE_DATA_W{1'b0}};
            for (i = 0; i < WB_BYTES; i = i + 1)
                place_word_data[(word_index * WB_DATA_W) + (i * 8) +: 8] =
                    data[(i * 8) +: 8];
        end
    endfunction

    function [LINE_BYTES-1:0] place_word_mask;
        input [(WB_DATA_W/8)-1:0] sel;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            place_word_mask = {LINE_BYTES{1'b1}};
            for (i = 0; i < WB_BYTES; i = i + 1)
                place_word_mask[(word_index * WB_BYTES) + i] = ~sel[i];
        end
    endfunction

    function [WB_DATA_W-1:0] pick_word_data;
        input [LINE_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            pick_word_data = data[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    function [LINE_DATA_W-1:0] merge_word_data;
        input [LINE_DATA_W-1:0] old_line;
        input [WB_DATA_W-1:0] data;
        input [(WB_DATA_W/8)-1:0] sel;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            merge_word_data = old_line;
            for (i = 0; i < WB_BYTES; i = i + 1) begin
                if (sel[i])
                    merge_word_data[(word_index * WB_DATA_W) +
                                    (i * 8) +: 8] =
                        data[(i * 8) +: 8];
            end
        end
    endfunction

    always @(posedge i_clk) begin
        if (i_rst) begin
            state <= ST_IDLE;
            req_write <= 1'b0;
            req_line_addr <= {LINE_ADDR_W{1'b0}};
            req_word_index <= {WORD_INDEX_W{1'b0}};
            req_wr_data <= {LINE_DATA_W{1'b0}};
            req_wr_mask <= {LINE_BYTES{1'b1}};
            wr_line_sent <= 1'b0;
            wr_line_loaded <= 1'b0;
            o_wb_ack <= 1'b0;
            o_wb_dat <= {WB_DATA_W{1'b0}};
            o_wb_err <= 1'b0;
        end else begin
            o_wb_ack <= 1'b0;
            o_wb_err <= 1'b0;

            if (cmd_is_write) begin
                if (wr_line_accept) begin
                    wr_line_sent <= 1'b1;
                    wr_line_loaded <= i_phy_wr_line_loaded;
                end else if (wr_line_sent && i_phy_wr_line_loaded) begin
                    wr_line_loaded <= 1'b1;
                end
            end

            case (state)
                ST_IDLE: begin
                    if (wb_accept) begin
                        req_write <= i_wb_we;
                        req_line_addr <= i_wb_adr[WB_ADDR_W-1:WORD_INDEX_W];
                        req_word_index <= i_wb_adr[WORD_INDEX_W-1:0];
                        req_wr_data <= place_word_data(
                            i_wb_dat, i_wb_adr[WORD_INDEX_W-1:0]);
                        req_wr_mask <= place_word_mask(
                            i_wb_sel, i_wb_adr[WORD_INDEX_W-1:0]);
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_CMD;
                    end
                end

                ST_CMD: begin
                    if (!i_wb_cyc) begin
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_IDLE;
                    end else if (cmd_accept) begin
                        if (req_write) begin
                            if (PHY_HAS_BYTE_MASK != 0) begin
                                o_wb_ack <= 1'b1;
                                wr_line_sent <= 1'b0;
                                wr_line_loaded <= 1'b0;
                                state <= ST_IDLE;
                            end else begin
                                state <= i_xfer_start ? ST_WAIT_RD_DATA
                                                       : ST_WAIT_RD_XFER;
                            end
                        end else begin
                            state <= i_xfer_start ? ST_WAIT_RD_DATA
                                                   : ST_WAIT_RD_XFER;
                        end
                    end
                end

                ST_WAIT_RD_XFER: begin
                    if (!i_wb_cyc) begin
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_IDLE;
                    end else if (i_xfer_start) begin
                        state <= ST_WAIT_RD_DATA;
                    end
                end

                ST_WAIT_RD_DATA: begin
                    if (!i_wb_cyc) begin
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_IDLE;
                    end else if (i_phy_rd_line_valid) begin
                        if (req_write && (PHY_HAS_BYTE_MASK == 0)) begin
                            if (i_phy_rd_line_err) begin
                                o_wb_ack <= 1'b1;
                                o_wb_err <= 1'b1;
                                wr_line_sent <= 1'b0;
                                wr_line_loaded <= 1'b0;
                                state <= ST_IDLE;
                            end else begin
                                req_wr_data <= merge_word_data(
                                    i_phy_rd_line_data, req_wr_data[
                                        req_word_index * WB_DATA_W +: WB_DATA_W],
                                    ~req_wr_mask[
                                        req_word_index * WB_BYTES +: WB_BYTES],
                                    req_word_index);
                                req_wr_mask <= {LINE_BYTES{1'b0}};
                                wr_line_sent <= 1'b0;
                                wr_line_loaded <= 1'b0;
                                state <= ST_RMW_CMD;
                            end
                        end else begin
                            o_wb_ack <= 1'b1;
                            o_wb_err <= i_phy_rd_line_err;
                            o_wb_dat <= pick_word_data(
                                i_phy_rd_line_data, req_word_index);
                            wr_line_sent <= 1'b0;
                            wr_line_loaded <= 1'b0;
                            state <= ST_IDLE;
                        end
                    end
                end

                ST_RMW_CMD: begin
                    if (!i_wb_cyc) begin
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_IDLE;
                    end else if (cmd_accept) begin
                        o_wb_ack <= 1'b1;
                        wr_line_sent <= 1'b0;
                        wr_line_loaded <= 1'b0;
                        state <= ST_IDLE;
                    end
                end

                default: begin
                    wr_line_sent <= 1'b0;
                    wr_line_loaded <= 1'b0;
                    state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire
