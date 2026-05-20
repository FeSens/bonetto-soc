// One DDR3 bank machine.
//
// This is the first reusable scheduler-owned RTL slice. It tracks the open row
// for one bank, accepts one request at a time, and emits only commands that are
// locally legal for that bank. Cross-bank arbitration and refresh live above
// this module.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_bank #(
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer ROW_BITS  = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer T_RCD     = `DDR3_800_TRCD_CYCLES,
    parameter integer T_RP      = `DDR3_800_TRP_CYCLES,
    parameter integer T_RAS     = `DDR3_800_TRAS_CYCLES,
    parameter integer T_RC      = `DDR3_800_TRC_CYCLES,
    parameter integer T_RTP     = `DDR3_800_TRTP_CYCLES,
    parameter integer T_WR      = `DDR3_800_TWR_CMD_CYCLES,
    parameter integer T_CCD     = `DDR3_800_TCCD_CYCLES,
    parameter integer T_WTR     = `DDR3_800_TWTR_CMD_CYCLES,
    parameter [BANK_BITS-1:0] BANK = {BANK_BITS{1'b0}}
) (
    input wire                 i_clk,
    input wire                 i_rst,

    input wire                 i_req_valid,
    output wire                o_req_ready,
    input wire                 i_req_write,
    input wire [ROW_BITS-1:0]  i_req_row,
    input wire [ADDR_BITS-1:0] i_req_col,

    output reg                 o_rsp_valid,
    output reg                 o_rsp_write,

    output reg [3:0]           o_state,
    output wire                o_busy,
    output wire                o_open,
    output wire [ROW_BITS-1:0] o_open_row,

    output reg                 o_cmd_valid,
    output reg                 o_cs_n,
    output reg                 o_ras_n,
    output reg                 o_cas_n,
    output reg                 o_we_n,
    output reg [BANK_BITS-1:0] o_ba,
    output reg [ADDR_BITS-1:0] o_addr
);
    localparam [3:0]
        ST_IDLE      = 4'd0,
        ST_WAIT_PRE  = 4'd1,
        ST_PRE       = 4'd2,
        ST_WAIT_ACT  = 4'd3,
        ST_ACT       = 4'd4,
        ST_WAIT_RCD  = 4'd5,
        ST_WAIT_DATA = 4'd6,
        ST_READ      = 4'd7,
        ST_WRITE     = 4'd8;

    reg                 bank_open;
    reg [ROW_BITS-1:0]  open_row;
    reg                 pending_write;
    reg [ROW_BITS-1:0]  pending_row;
    reg [ADDR_BITS-1:0] pending_col;

    reg [15:0] t_rcd_wait;
    reg [15:0] t_rp_wait;
    reg [15:0] t_ras_wait;
    reg [15:0] t_rc_wait;
    reg [15:0] t_rtp_wait;
    reg [15:0] t_wr_wait;
    reg [15:0] t_ccd_wait;
    reg [15:0] t_wtr_wait;

    wire pre_ready  = (t_ras_wait == 16'd0) &&
                      (t_rtp_wait == 16'd0) &&
                      (t_wr_wait  == 16'd0);
    wire act_ready  = (t_rp_wait == 16'd0) &&
                      (t_rc_wait == 16'd0);
    wire data_ready = (t_rcd_wait == 16'd0) &&
                      (t_ccd_wait == 16'd0) &&
                      (pending_write || (t_wtr_wait == 16'd0));

    assign o_req_ready = (o_state == ST_IDLE);
    assign o_busy      = (o_state != ST_IDLE);
    assign o_open      = bank_open;
    assign o_open_row  = open_row;

    function [15:0] load_wait;
        input integer cycles;
        begin
            load_wait = (cycles <= 1) ? 16'd0 : cycles[15:0] - 16'd1;
        end
    endfunction

    function [15:0] dec_wait;
        input [15:0] value;
        begin
            dec_wait = (value == 16'd0) ? 16'd0 : value - 16'd1;
        end
    endfunction

    task set_cmd;
        input [3:0] command;
        input [BANK_BITS-1:0] bank;
        input [ADDR_BITS-1:0] addr;
        begin
            o_cmd_valid <= 1'b1;
            o_cs_n      <= command[3];
            o_ras_n     <= command[2];
            o_cas_n     <= command[1];
            o_we_n      <= command[0];
            o_ba        <= bank;
            o_addr      <= addr;
        end
    endtask

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_state       <= ST_IDLE;
            bank_open    <= 1'b0;
            open_row     <= {ROW_BITS{1'b0}};
            pending_write <= 1'b0;
            pending_row   <= {ROW_BITS{1'b0}};
            pending_col   <= {ADDR_BITS{1'b0}};
            o_rsp_valid   <= 1'b0;
            o_rsp_write   <= 1'b0;
            t_rcd_wait    <= 16'd0;
            t_rp_wait     <= 16'd0;
            t_ras_wait    <= 16'd0;
            t_rc_wait     <= 16'd0;
            t_rtp_wait    <= 16'd0;
            t_wr_wait     <= 16'd0;
            t_ccd_wait    <= 16'd0;
            t_wtr_wait    <= 16'd0;
            set_cmd(`DDR3_CMD_NOP, BANK, {ADDR_BITS{1'b0}});
        end else begin
            set_cmd(`DDR3_CMD_NOP, BANK, {ADDR_BITS{1'b0}});
            o_rsp_valid <= 1'b0;

            t_rcd_wait <= dec_wait(t_rcd_wait);
            t_rp_wait  <= dec_wait(t_rp_wait);
            t_ras_wait <= dec_wait(t_ras_wait);
            t_rc_wait  <= dec_wait(t_rc_wait);
            t_rtp_wait <= dec_wait(t_rtp_wait);
            t_wr_wait  <= dec_wait(t_wr_wait);
            t_ccd_wait <= dec_wait(t_ccd_wait);
            t_wtr_wait <= dec_wait(t_wtr_wait);

            case (o_state)
                ST_IDLE: begin
                    if (i_req_valid) begin
                        pending_write <= i_req_write;
                        pending_row   <= i_req_row;
                        pending_col   <= i_req_col;

                        if (bank_open && (i_req_row == open_row))
                            o_state <= ST_WAIT_DATA;
                        else if (bank_open)
                            o_state <= ST_WAIT_PRE;
                        else
                            o_state <= ST_WAIT_ACT;
                    end
                end

                ST_WAIT_PRE: begin
                    if (pre_ready)
                        o_state <= ST_PRE;
                end

                ST_PRE: begin
                    set_cmd(`DDR3_CMD_PRE, BANK, {ADDR_BITS{1'b0}});
                    bank_open <= 1'b0;
                    t_rp_wait <= load_wait(T_RP);
                    o_state   <= ST_WAIT_ACT;
                end

                ST_WAIT_ACT: begin
                    if (act_ready)
                        o_state <= ST_ACT;
                end

                ST_ACT: begin
                    set_cmd(`DDR3_CMD_ACT, BANK, {{(ADDR_BITS-ROW_BITS){1'b0}}, pending_row});
                    bank_open    <= 1'b1;
                    open_row     <= pending_row;
                    t_rcd_wait   <= load_wait(T_RCD);
                    t_ras_wait   <= load_wait(T_RAS);
                    t_rc_wait    <= load_wait(T_RC);
                    o_state      <= ST_WAIT_RCD;
                end

                ST_WAIT_RCD: begin
                    if (t_rcd_wait == 16'd0)
                        o_state <= ST_WAIT_DATA;
                end

                ST_WAIT_DATA: begin
                    if (data_ready)
                        o_state <= pending_write ? ST_WRITE : ST_READ;
                end

                ST_READ: begin
                    set_cmd(`DDR3_CMD_RD, BANK, pending_col);
                    t_rtp_wait <= load_wait(T_RTP);
                    t_ccd_wait <= load_wait(T_CCD);
                    o_rsp_valid <= 1'b1;
                    o_rsp_write <= 1'b0;
                    o_state <= ST_IDLE;
                end

                ST_WRITE: begin
                    set_cmd(`DDR3_CMD_WR, BANK, pending_col);
                    t_wr_wait  <= load_wait(T_WR);
                    t_wtr_wait <= load_wait(T_WTR);
                    t_ccd_wait <= load_wait(T_CCD);
                    o_rsp_valid <= 1'b1;
                    o_rsp_write <= 1'b1;
                    o_state <= ST_IDLE;
                end

                default: begin
                    o_state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire
