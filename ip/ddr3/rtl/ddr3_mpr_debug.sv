// Host-driven DDR3 MPR debug command sequencer.
//
// This block is intentionally narrow.  It does not expose normal memory
// storage traffic; it only lets the host enable/disable MR3 MPR mode, issue one
// MPR READ, and request a raw SERDES capture after a programmable slow-clock
// delay.  The board top muxes these commands onto the live command pins while
// DDR Wishbone remains blocked.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_mpr_debug #(
    parameter integer CHANNELS = 2,
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer PHY_LANES_PER_CHANNEL = 9,
    parameter integer MRS_WAIT_CYCLES = 2,
    parameter integer QUIET_SETTLE_CYCLES = 8,
    parameter integer CAPTURE_DELAY_CYCLES = 4
) (
    input  wire                         i_clk,
    input  wire                         i_rst,

    input  wire [31:0]                  i_cmd_word,
    input  wire                         i_cmd_valid,
    input  wire                         i_init_done,
    input  wire [CHANNELS-1:0]          i_ctrl_cmd_active,

    output reg  [CHANNELS-1:0]          o_cmd_valid,
    output reg  [CHANNELS-1:0]          o_cs_n,
    output reg  [CHANNELS-1:0]          o_ras_n,
    output reg  [CHANNELS-1:0]          o_cas_n,
    output reg  [CHANNELS-1:0]          o_we_n,
    output reg  [CHANNELS*BANK_BITS-1:0] o_ba,
    output reg  [CHANNELS*ADDR_BITS-1:0] o_addr,

    output reg                          o_capture_pulse,
    output reg  [4:0]                   o_capture_lane,

    output wire                         o_busy,
    output reg                          o_error,
    output reg  [CHANNELS-1:0]          o_mpr_enabled,
    output reg  [3:0]                   o_state,
    output reg  [4:0]                   o_selected_lane,
    output reg  [7:0]                   o_capture_delay,
    output reg  [7:0]                   o_cmd_count,
    output reg  [7:0]                   o_read_count,
    output reg  [7:0]                   o_capture_count,
    output reg  [12:0]                  o_read_addr
);
    localparam [7:0]
        CMD_MPR_EN       = 8'hEB,
        CMD_MPR_DIS      = 8'hEC,
        CMD_MPR_READ     = 8'hED,
        CMD_RDDBG_SEL    = 8'hEE,
        CMD_CLEAR_RDDBG  = 8'hEF;

    localparam [1:0]
        OP_NONE = 2'd0,
        OP_EN   = 2'd1,
        OP_DIS  = 2'd2,
        OP_READ = 2'd3;

    localparam [3:0]
        ST_IDLE         = 4'd0,
        ST_WAIT_QUIET   = 4'd1,
        ST_ISSUE        = 4'd2,
        ST_WAIT_MRS     = 4'd3,
        ST_WAIT_CAPTURE = 4'd4,
        ST_CAPTURE      = 4'd5;

    localparam integer WAIT_W = 8;
    localparam [4:0] PHY_LANES_PER_CHANNEL_L = PHY_LANES_PER_CHANNEL;
    localparam [7:0] CAPTURE_DELAY_INIT = CAPTURE_DELAY_CYCLES;
    localparam [WAIT_W-1:0] QUIET_SETTLE_INIT = QUIET_SETTLE_CYCLES;
    localparam [WAIT_W-1:0] MRS_WAIT_INIT = MRS_WAIT_CYCLES;

    reg [1:0] op;
    reg target_channel;
    reg [WAIT_W-1:0] wait_left;

    wire [7:0] cmd = i_cmd_word[31:24];
    wire cmd_mpr_en = i_cmd_valid && (cmd == CMD_MPR_EN);
    wire cmd_mpr_dis = i_cmd_valid && (cmd == CMD_MPR_DIS);
    wire cmd_mpr_read = i_cmd_valid && (cmd == CMD_MPR_READ);
    wire cmd_rddbg_sel = i_cmd_valid && (cmd == CMD_RDDBG_SEL);
    wire cmd_clear_rddbg = i_cmd_valid && (cmd == CMD_CLEAR_RDDBG);
    wire cmd_starts_op = cmd_mpr_en || cmd_mpr_dis || cmd_mpr_read;
    wire payload_channel = i_cmd_word[16];
    wire [4:0] payload_lane = i_cmd_word[4:0];
    wire [7:0] payload_delay = i_cmd_word[15:8];
    wire [12:0] payload_addr = i_cmd_word[12:0];
    function [4:0] to_physical_lane;
        input channel;
        input [4:0] local_lane;
        integer base;
        begin
            base = channel ? PHY_LANES_PER_CHANNEL : 0;
            to_physical_lane = base[4:0] + local_lane;
        end
    endfunction

    function [ADDR_BITS-1:0] read_addr;
        input [12:0] addr;
        begin
            read_addr = {{(ADDR_BITS-13){1'b0}}, (addr | 13'h1000)};
        end
    endfunction

    assign o_busy = (o_state != ST_IDLE);

    task clear_cmd_outputs;
        begin
            o_cmd_valid <= {CHANNELS{1'b0}};
            o_cs_n <= {CHANNELS{1'b1}};
            o_ras_n <= {CHANNELS{1'b1}};
            o_cas_n <= {CHANNELS{1'b1}};
            o_we_n <= {CHANNELS{1'b1}};
            o_ba <= {(CHANNELS*BANK_BITS){1'b0}};
            o_addr <= {(CHANNELS*ADDR_BITS){1'b0}};
        end
    endtask

    task issue_cmd;
        input channel;
        input [3:0] ddr_cmd;
        input [BANK_BITS-1:0] bank;
        input [ADDR_BITS-1:0] addr;
        begin
            o_cmd_valid[channel] <= 1'b1;
            o_cs_n[channel] <= ddr_cmd[3];
            o_ras_n[channel] <= ddr_cmd[2];
            o_cas_n[channel] <= ddr_cmd[1];
            o_we_n[channel] <= ddr_cmd[0];
            o_ba[channel*BANK_BITS +: BANK_BITS] <= bank;
            o_addr[channel*ADDR_BITS +: ADDR_BITS] <= addr;
        end
    endtask

    initial begin
        o_capture_pulse = 1'b0;
        o_capture_lane = 5'd0;
        o_error = 1'b0;
        o_mpr_enabled = {CHANNELS{1'b0}};
        o_state = ST_IDLE;
        o_selected_lane = 5'd0;
        o_capture_delay = CAPTURE_DELAY_INIT;
        o_cmd_count = 8'd0;
        o_read_count = 8'd0;
        o_capture_count = 8'd0;
        o_read_addr = 13'h1000;
        op = OP_NONE;
        target_channel = 1'b0;
        wait_left = {WAIT_W{1'b0}};
        clear_cmd_outputs();
    end

    always @(posedge i_clk) begin
        if (i_rst) begin
            clear_cmd_outputs();
            o_capture_pulse <= 1'b0;
            o_capture_lane <= 5'd0;
            o_error <= 1'b0;
            o_mpr_enabled <= {CHANNELS{1'b0}};
            o_state <= ST_IDLE;
            o_selected_lane <= 5'd0;
            o_capture_delay <= CAPTURE_DELAY_INIT;
            o_cmd_count <= 8'd0;
            o_read_count <= 8'd0;
            o_capture_count <= 8'd0;
            o_read_addr <= 13'h1000;
            op <= OP_NONE;
            target_channel <= 1'b0;
            wait_left <= {WAIT_W{1'b0}};
        end else begin
            clear_cmd_outputs();
            o_capture_pulse <= 1'b0;

            if (cmd_clear_rddbg && !o_busy) begin
                o_error <= 1'b0;
                o_cmd_count <= 8'd0;
                o_read_count <= 8'd0;
                o_capture_count <= 8'd0;
            end

            if (cmd_rddbg_sel && !o_busy) begin
                if (payload_lane < PHY_LANES_PER_CHANNEL_L) begin
                    target_channel <= payload_channel;
                    o_selected_lane <= to_physical_lane(
                        payload_channel, payload_lane);
                    o_capture_delay <= payload_delay;
                end else begin
                    o_error <= 1'b1;
                end
            end else if (cmd_rddbg_sel && o_busy) begin
                o_error <= 1'b1;
            end

            if (cmd_starts_op) begin
                if (o_busy || !i_init_done) begin
                    o_error <= 1'b1;
                end else begin
                    target_channel <= payload_channel;
                    if (cmd_mpr_en) begin
                        op <= OP_EN;
                        wait_left <= QUIET_SETTLE_INIT;
                        o_state <= ST_WAIT_QUIET;
                    end else if (cmd_mpr_dis) begin
                        op <= OP_DIS;
                        wait_left <= QUIET_SETTLE_INIT;
                        o_state <= ST_WAIT_QUIET;
                    end else if (!o_mpr_enabled[payload_channel]) begin
                        o_error <= 1'b1;
                    end else begin
                        op <= OP_READ;
                        o_read_addr <= payload_addr | 13'h1000;
                        wait_left <= QUIET_SETTLE_INIT;
                        o_state <= ST_WAIT_QUIET;
                    end
                end
            end

            case (o_state)
                ST_IDLE: begin
                    if (!cmd_starts_op)
                        op <= OP_NONE;
                end

                ST_WAIT_QUIET: begin
                    if (i_ctrl_cmd_active[target_channel]) begin
                        wait_left <= QUIET_SETTLE_INIT;
                    end else if (wait_left == {WAIT_W{1'b0}}) begin
                        o_state <= ST_ISSUE;
                    end else begin
                        wait_left <= wait_left - 1'b1;
                    end
                end

                ST_ISSUE: begin
                    o_cmd_count <= o_cmd_count + 8'd1;
                    if (op == OP_EN) begin
                        issue_cmd(target_channel, `DDR3_CMD_MRS,
                                  {{(BANK_BITS-2){1'b0}}, 2'd3},
                                  {{(ADDR_BITS-3){1'b0}}, 3'b100});
                        wait_left <= MRS_WAIT_INIT;
                        o_mpr_enabled[target_channel] <= 1'b1;
                        o_state <= ST_WAIT_MRS;
                    end else if (op == OP_DIS) begin
                        issue_cmd(target_channel, `DDR3_CMD_MRS,
                                  {{(BANK_BITS-2){1'b0}}, 2'd3},
                                  {ADDR_BITS{1'b0}});
                        wait_left <= MRS_WAIT_INIT;
                        o_mpr_enabled[target_channel] <= 1'b0;
                        o_state <= ST_WAIT_MRS;
                    end else if (op == OP_READ) begin
                        issue_cmd(target_channel, `DDR3_CMD_RD,
                                  {BANK_BITS{1'b0}}, read_addr(o_read_addr));
                        o_capture_pulse <= 1'b1;
                        o_capture_lane <= o_selected_lane;
                        o_capture_count <= o_capture_count + 8'd1;
                        o_read_count <= o_read_count + 8'd1;
                        wait_left <= MRS_WAIT_INIT;
                        o_state <= ST_WAIT_MRS;
                    end else begin
                        o_state <= ST_IDLE;
                    end
                end

                ST_WAIT_MRS: begin
                    if (wait_left == {WAIT_W{1'b0}})
                        o_state <= ST_IDLE;
                    else
                        wait_left <= wait_left - 1'b1;
                end

                default: begin
                    o_state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire
