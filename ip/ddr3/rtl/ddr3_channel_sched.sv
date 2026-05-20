// Single-channel BL8 command scheduler adapter.
//
// This block is the boundary between a channel-level BL8 line request and the
// DDR3 bank scheduler. It accepts one line command, translates the packed line
// address into bank/row/column fields, lets the scheduler perform ACT/PRE/RD/WR
// timing, and pulses o_xfer_start with o_xfer_write when the matching RD/WR
// command has issued.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_channel_sched #(
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer ROW_BITS  = `DDR3_ROW_BITS,
    parameter integer COL_BITS  = `DDR3_COL_BITS,
    parameter integer T_RCD     = `DDR3_800_TRCD_CYCLES,
    parameter integer T_RP      = `DDR3_800_TRP_CYCLES,
    parameter integer T_RAS     = `DDR3_800_TRAS_CYCLES,
    parameter integer T_RC      = `DDR3_800_TRC_CYCLES,
    parameter integer T_RTP     = `DDR3_800_TRTP_CYCLES,
    parameter integer T_WR      = `DDR3_800_TWR_CMD_CYCLES,
    parameter integer T_CCD     = `DDR3_800_TCCD_CYCLES,
    parameter integer T_WTR     = `DDR3_800_TWTR_CMD_CYCLES,
    parameter integer T_RRD     = `DDR3_800_TRRD_CYCLES,
    parameter integer T_FAW     = `DDR3_800_TFAW_CYCLES,
    parameter integer T_RFC     = `DDR3_800_TRFC_CYCLES,
    parameter integer T_REFI    = `DDR3_800_TREFI_CYCLES,
    parameter integer T_MARGIN  = `DDR3_800_REFRESH_MARGIN_CYCLES,
    localparam integer COL_LINE_BITS = COL_BITS - 3,
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS
) (
    input wire                        i_clk,
    input wire                        i_rst,

    input wire                        i_cmd_valid,
    output wire                       o_cmd_ready,
    input wire                        i_cmd_write,
    input wire [LINE_ADDR_W-1:0]      i_cmd_line_addr,
    output wire                       o_xfer_start,
    output wire                       o_xfer_write,

    input wire                        i_refresh_enable,
    output wire                       o_refresh_req,
    output wire                       o_refresh_ack,
    output wire                       o_refresh_busy,
    output wire                       o_refresh_late,
    output wire [15:0]                o_refresh_count,

    output wire                       o_req_pending,
    output wire [((1 << BANK_BITS)-1):0] o_bank_busy,
    output wire [((1 << BANK_BITS)-1):0] o_bank_open,

    output wire                       o_cmd_valid,
    output wire                       o_cs_n,
    output wire                       o_ras_n,
    output wire                       o_cas_n,
    output wire                       o_we_n,
    output wire [BANK_BITS-1:0]       o_ba,
    output wire [ADDR_BITS-1:0]       o_addr
);
    wire [BANK_BITS-1:0] req_bank =
        i_cmd_line_addr[LINE_ADDR_W-1 -: BANK_BITS];
    wire [ROW_BITS-1:0] req_row =
        i_cmd_line_addr[COL_LINE_BITS +: ROW_BITS];
    wire [COL_LINE_BITS-1:0] req_col_line =
        i_cmd_line_addr[COL_LINE_BITS-1:0];
    wire [ADDR_BITS-1:0] req_col =
        {{(ADDR_BITS-COL_BITS){1'b0}}, req_col_line, 3'b000};

    reg                  pending_valid;
    reg                  pending_write;
    reg [BANK_BITS-1:0]  pending_bank;

    wire scheduler_req_valid = i_cmd_valid && !pending_valid;
    wire scheduler_req_ready;
    wire scheduler_rsp_valid;
    wire scheduler_rsp_write;
    wire [BANK_BITS-1:0] scheduler_rsp_bank;
    wire scheduler_refresh_ack;

    wire command_accept = scheduler_req_valid && scheduler_req_ready;
    wire rsp_matches = pending_valid && scheduler_rsp_valid &&
                       (scheduler_rsp_write == pending_write) &&
                       (scheduler_rsp_bank == pending_bank);

    assign o_cmd_ready = command_accept;
    assign o_xfer_start = rsp_matches;
    assign o_xfer_write = pending_write;
    assign o_req_pending = pending_valid;
    assign o_refresh_ack = scheduler_refresh_ack;

    always @(posedge i_clk) begin
        if (i_rst) begin
            pending_valid <= 1'b0;
            pending_write <= 1'b0;
            pending_bank <= {BANK_BITS{1'b0}};
        end else begin
            if (command_accept) begin
                pending_valid <= 1'b1;
                pending_write <= i_cmd_write;
                pending_bank <= req_bank;
            end

            if (rsp_matches)
                pending_valid <= 1'b0;
        end
    end

    ddr3_refresh #(
        .T_REFI(T_REFI),
        .T_MARGIN(T_MARGIN)
    ) u_refresh (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_enable(i_refresh_enable),
        .i_refresh_ack(scheduler_refresh_ack),
        .o_refresh_req(o_refresh_req),
        .o_refresh_late(o_refresh_late),
        .o_refresh_window(),
        .o_cycles_to_deadline(),
        .o_refresh_count(o_refresh_count)
    );

    ddr3_scheduler #(
        .ADDR_BITS(ADDR_BITS),
        .ROW_BITS(ROW_BITS),
        .BANK_BITS(BANK_BITS),
        .T_RCD(T_RCD),
        .T_RP(T_RP),
        .T_RAS(T_RAS),
        .T_RC(T_RC),
        .T_RTP(T_RTP),
        .T_WR(T_WR),
        .T_CCD(T_CCD),
        .T_WTR(T_WTR),
        .T_RRD(T_RRD),
        .T_FAW(T_FAW),
        .T_RFC(T_RFC)
    ) u_scheduler (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_req_valid(scheduler_req_valid),
        .o_req_ready(scheduler_req_ready),
        .i_req_write(i_cmd_write),
        .i_req_bank(req_bank),
        .i_req_row(req_row),
        .i_req_col(req_col),
        .i_refresh_req(o_refresh_req),
        .o_refresh_ack(scheduler_refresh_ack),
        .o_refresh_busy(o_refresh_busy),
        .o_rsp_valid(scheduler_rsp_valid),
        .o_rsp_write(scheduler_rsp_write),
        .o_rsp_bank(scheduler_rsp_bank),
        .o_bank_busy(o_bank_busy),
        .o_bank_open(o_bank_open),
        .o_cmd_valid(o_cmd_valid),
        .o_cs_n(o_cs_n),
        .o_ras_n(o_ras_n),
        .o_cas_n(o_cas_n),
        .o_we_n(o_we_n),
        .o_ba(o_ba),
        .o_addr(o_addr)
    );
endmodule

`default_nettype wire
