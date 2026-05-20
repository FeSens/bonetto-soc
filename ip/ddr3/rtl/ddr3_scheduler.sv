// Global DDR3 command scheduler.
//
// This slice instantiates one row/timing machine per bank, accepts one request
// per bank at a time, and gates the shared command bus with the first global
// timing rules that cross bank boundaries. It also owns the first refresh path:
// stop accepting requests, ask every bank to close, issue one REF, then wait
// tRFC before normal traffic resumes.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_scheduler #(
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
    parameter integer T_RRD     = `DDR3_800_TRRD_CYCLES,
    parameter integer T_FAW     = `DDR3_800_TFAW_CYCLES,
    parameter integer T_RFC     = `DDR3_800_TRFC_CYCLES
) (
    input wire                 i_clk,
    input wire                 i_rst,

    input wire                 i_req_valid,
    output wire                o_req_ready,
    input wire                 i_req_write,
    input wire [BANK_BITS-1:0] i_req_bank,
    input wire [ROW_BITS-1:0]  i_req_row,
    input wire [ADDR_BITS-1:0] i_req_col,

    input wire                 i_refresh_req,
    output reg                 o_refresh_ack,
    output wire                o_refresh_busy,

    output reg                 o_rsp_valid,
    output reg                 o_rsp_write,
    output reg [BANK_BITS-1:0] o_rsp_bank,

    output wire [((1 << BANK_BITS)-1):0] o_bank_busy,
    output wire [((1 << BANK_BITS)-1):0] o_bank_open,

    output reg                 o_cmd_valid,
    output reg                 o_cs_n,
    output reg                 o_ras_n,
    output reg                 o_cas_n,
    output reg                 o_we_n,
    output reg [BANK_BITS-1:0] o_ba,
    output reg [ADDR_BITS-1:0] o_addr
);
    localparam integer BANKS = 1 << BANK_BITS;
    localparam [3:0] CMD_ACT = `DDR3_CMD_ACT;
    localparam [3:0] CMD_REF = `DDR3_CMD_REF;
    localparam [3:0] CMD_RD  = `DDR3_CMD_RD;
    localparam [3:0] CMD_WR  = `DDR3_CMD_WR;
    localparam [3:0] CMD_NOP = `DDR3_CMD_NOP;
    localparam [3:0] CMD_DES = `DDR3_CMD_DES;

    wire [BANKS-1:0] bank_req_ready;
    wire [BANKS-1:0] bank_rsp_valid;
    wire [BANKS-1:0] bank_rsp_write;
    wire [BANKS-1:0] bank_cmd_ready;
    wire [BANKS-1:0] bank_close_ready;
    wire [BANKS-1:0] bank_cmd_valid;
    wire [BANKS-1:0] bank_cs_n;
    wire [BANKS-1:0] bank_ras_n;
    wire [BANKS-1:0] bank_cas_n;
    wire [BANKS-1:0] bank_we_n;

    wire [3:0] bank_state [0:BANKS-1];
    wire [BANK_BITS-1:0] bank_ba [0:BANKS-1];
    wire [ADDR_BITS-1:0] bank_addr [0:BANKS-1];
    wire [ROW_BITS-1:0] bank_open_row [0:BANKS-1];

    reg [7:0] t_rrd_wait;
    reg [7:0] t_ccd_wait;
    reg [7:0] t_wtr_wait;
    reg [7:0] t_rfc_wait;
    reg [T_FAW-1:0] act_window;

    reg issue_valid;
    reg [BANK_BITS-1:0] issue_bank;
    reg [1:0] refresh_state;

    localparam [1:0]
        REF_IDLE  = 2'd0,
        REF_CLOSE = 2'd1,
        REF_ISSUE = 2'd2,
        REF_WAIT  = 2'd3;

    integer k;
    genvar g;

    wire all_banks_closed = &bank_close_ready;
    wire refresh_issue = (refresh_state == REF_ISSUE);
    wire bank_issue_allowed_state = (refresh_state == REF_IDLE) ||
                                    (refresh_state == REF_CLOSE);

    assign o_refresh_busy = (refresh_state != REF_IDLE);
    assign o_req_ready = (refresh_state == REF_IDLE) &&
                         !i_refresh_req &&
                         bank_req_ready[i_req_bank];

    function [7:0] load_wait;
        input integer cycles;
        begin
            load_wait = (cycles <= 1) ? 8'd0 : cycles[7:0] - 8'd1;
        end
    endfunction

    function [7:0] dec_wait;
        input [7:0] value;
        begin
            dec_wait = (value == 8'd0) ? 8'd0 : value - 8'd1;
        end
    endfunction

    function [7:0] count_activates;
        input [T_FAW-1:0] window;
        integer i;
        begin
            count_activates = 8'd0;
            for (i = 0; i < T_FAW; i = i + 1)
                count_activates = count_activates + {7'd0, window[i]};
        end
    endfunction

    function global_ready;
        input [3:0] command;
        begin
            if (command == CMD_ACT)
                global_ready = (t_rrd_wait == 8'd0) &&
                               (count_activates(act_window) < 8'd4);
            else if (command == CMD_RD)
                global_ready = (t_ccd_wait == 8'd0) &&
                               (t_wtr_wait == 8'd0);
            else if (command == CMD_WR)
                global_ready = (t_ccd_wait == 8'd0);
            else
                global_ready = 1'b1;
        end
    endfunction

    generate
        for (g = 0; g < BANKS; g = g + 1) begin : gen_bank
            localparam [BANK_BITS-1:0] BANK_ID = g;
            wire target_req = i_req_valid && o_req_ready &&
                              (i_req_bank == BANK_ID);

            ddr3_bank #(
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
                .BANK(BANK_ID)
            ) bank (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_req_valid(target_req),
                .o_req_ready(bank_req_ready[g]),
                .i_req_write(i_req_write),
                .i_req_row(i_req_row),
                .i_req_col(i_req_col),
                .i_cmd_ready(bank_cmd_ready[g]),
                .i_close_req(refresh_state == REF_CLOSE),
                .o_close_ready(bank_close_ready[g]),
                .o_rsp_valid(bank_rsp_valid[g]),
                .o_rsp_write(bank_rsp_write[g]),
                .o_state(bank_state[g]),
                .o_busy(o_bank_busy[g]),
                .o_open(o_bank_open[g]),
                .o_open_row(bank_open_row[g]),
                .o_cmd_valid(bank_cmd_valid[g]),
                .o_cs_n(bank_cs_n[g]),
                .o_ras_n(bank_ras_n[g]),
                .o_cas_n(bank_cas_n[g]),
                .o_we_n(bank_we_n[g]),
                .o_ba(bank_ba[g]),
                .o_addr(bank_addr[g])
            );

            assign bank_cmd_ready[g] = bank_issue_allowed_state &&
                                       issue_valid &&
                                       (issue_bank == BANK_ID);
        end
    endgenerate

    always @(*) begin
        issue_valid = 1'b0;
        issue_bank  = {BANK_BITS{1'b0}};

        for (k = 0; k < BANKS; k = k + 1) begin
            if (!issue_valid &&
                bank_cmd_valid[k] &&
                ({bank_cs_n[k], bank_ras_n[k], bank_cas_n[k], bank_we_n[k]} != CMD_NOP) &&
                ({bank_cs_n[k], bank_ras_n[k], bank_cas_n[k], bank_we_n[k]} != CMD_DES) &&
                global_ready({bank_cs_n[k], bank_ras_n[k], bank_cas_n[k], bank_we_n[k]})) begin
                issue_valid = 1'b1;
                issue_bank  = k;
            end
        end
    end

    always @(*) begin
        o_rsp_valid = 1'b0;
        o_rsp_write = 1'b0;
        o_rsp_bank  = {BANK_BITS{1'b0}};

        for (k = 0; k < BANKS; k = k + 1) begin
            if (bank_rsp_valid[k]) begin
                o_rsp_valid = 1'b1;
                o_rsp_write = bank_rsp_write[k];
                o_rsp_bank  = k;
            end
        end
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            t_rrd_wait <= 8'd0;
            t_ccd_wait <= 8'd0;
            t_wtr_wait <= 8'd0;
            t_rfc_wait <= 8'd0;
            act_window <= {T_FAW{1'b0}};
            refresh_state <= REF_IDLE;
            o_refresh_ack <= 1'b0;
            o_cmd_valid <= 1'b1;
            o_cs_n      <= CMD_NOP[3];
            o_ras_n     <= CMD_NOP[2];
            o_cas_n     <= CMD_NOP[1];
            o_we_n      <= CMD_NOP[0];
            o_ba        <= {BANK_BITS{1'b0}};
            o_addr      <= {ADDR_BITS{1'b0}};
        end else begin
            t_rrd_wait <= dec_wait(t_rrd_wait);
            t_ccd_wait <= dec_wait(t_ccd_wait);
            t_wtr_wait <= dec_wait(t_wtr_wait);
            act_window <= {act_window[T_FAW-2:0], 1'b0};
            o_refresh_ack <= 1'b0;

            o_cmd_valid <= 1'b1;
            o_cs_n      <= CMD_NOP[3];
            o_ras_n     <= CMD_NOP[2];
            o_cas_n     <= CMD_NOP[1];
            o_we_n      <= CMD_NOP[0];
            o_ba        <= {BANK_BITS{1'b0}};
            o_addr      <= {ADDR_BITS{1'b0}};

            case (refresh_state)
                REF_IDLE: begin
                    if (i_refresh_req)
                        refresh_state <= REF_CLOSE;
                end

                REF_CLOSE: begin
                    if (all_banks_closed)
                        refresh_state <= REF_ISSUE;
                end

                REF_ISSUE: begin
                    o_cs_n      <= CMD_REF[3];
                    o_ras_n     <= CMD_REF[2];
                    o_cas_n     <= CMD_REF[1];
                    o_we_n      <= CMD_REF[0];
                    o_ba        <= {BANK_BITS{1'b0}};
                    o_addr      <= {ADDR_BITS{1'b0}};
                    o_refresh_ack <= 1'b1;
                    t_rfc_wait <= load_wait(T_RFC);
                    refresh_state <= REF_WAIT;
                end

                REF_WAIT: begin
                    if (t_rfc_wait == 8'd0)
                        refresh_state <= REF_IDLE;
                    else
                        t_rfc_wait <= dec_wait(t_rfc_wait);
                end

                default: begin
                    refresh_state <= REF_IDLE;
                end
            endcase

            if (bank_issue_allowed_state && issue_valid) begin
                o_cs_n  <= bank_cs_n[issue_bank];
                o_ras_n <= bank_ras_n[issue_bank];
                o_cas_n <= bank_cas_n[issue_bank];
                o_we_n  <= bank_we_n[issue_bank];
                o_ba    <= bank_ba[issue_bank];
                o_addr  <= bank_addr[issue_bank];

                if ({bank_cs_n[issue_bank], bank_ras_n[issue_bank],
                     bank_cas_n[issue_bank], bank_we_n[issue_bank]} == CMD_ACT) begin
                    t_rrd_wait <= load_wait(T_RRD);
                    act_window <= {act_window[T_FAW-2:0], 1'b1};
                end

                if (({bank_cs_n[issue_bank], bank_ras_n[issue_bank],
                      bank_cas_n[issue_bank], bank_we_n[issue_bank]} == CMD_RD) ||
                    ({bank_cs_n[issue_bank], bank_ras_n[issue_bank],
                      bank_cas_n[issue_bank], bank_we_n[issue_bank]} == CMD_WR)) begin
                    t_ccd_wait <= load_wait(T_CCD);
                end

                if ({bank_cs_n[issue_bank], bank_ras_n[issue_bank],
                     bank_cas_n[issue_bank], bank_we_n[issue_bank]} == CMD_WR)
                    t_wtr_wait <= load_wait(T_WTR);
            end
        end
    end
endmodule

`default_nettype wire
