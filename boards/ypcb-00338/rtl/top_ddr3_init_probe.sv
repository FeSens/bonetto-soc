// DDR3-800 full-pin init/refresh probe for YPCB-00338.
//
// This is the first board-facing image for the clean-sheet DDR3 controller.
// It deliberately stops before DQ/DQS data transfer:
//   * both 64-bit channels are present at the top-level pinout;
//   * the DDR3 CK, reset, CKE, command, address, and bank pins are driven;
//   * DQ and DQS pins are instantiated as input/high-Z I/O buffers;
//   * USER1 JTAG exposes PLL, init, refresh, and clock-liveness status.
//
// Passing this image proves the full board pin shell, clock generation, and
// JEDEC init command path are alive. It is not a DDR3 memory validation image.

`default_nettype none

`include "ddr3_params.vh"

module top_ddr3_init_probe (
    input  wire        SYS_CLK,
    input  wire        SYS_RSTN,
    output wire [2:0]  led_3bits_tri_o,

    output wire [14:0] ddr3_addr,
    output wire [2:0]  ddr3_ba,
    output wire        ddr3_ras_n,
    output wire        ddr3_cas_n,
    output wire        ddr3_we_n,
    output wire        ddr3_cs_n,
    output wire        ddr3_cke,
    output wire        ddr3_odt,
    output wire        ddr3_reset_n,
    output wire        ddr3_ck_p,
    output wire        ddr3_ck_n,
    inout  wire [71:0] ddr3_dq,
    inout  wire [8:0]  ddr3_dqs_p,
    inout  wire [8:0]  ddr3_dqs_n,

    output wire [14:0] ddr3_ch1_addr,
    output wire [2:0]  ddr3_ch1_ba,
    output wire        ddr3_ch1_ras_n,
    output wire        ddr3_ch1_cas_n,
    output wire        ddr3_ch1_we_n,
    output wire        ddr3_ch1_cs_n,
    output wire        ddr3_ch1_cke,
    output wire        ddr3_ch1_odt,
    output wire        ddr3_ch1_reset_n,
    output wire        ddr3_ch1_ck_p,
    output wire        ddr3_ch1_ck_n,
    inout  wire [71:0] ddr3_ch1_dq,
    inout  wire [8:0]  ddr3_ch1_dqs_p,
    inout  wire [8:0]  ddr3_ch1_dqs_n
);
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;

    reg [13:0] por_ctr = 14'h3fff;
    always @(posedge SYS_CLK) begin
        if (!SYS_RSTN)
            por_ctr <= 14'h3fff;
        else if (por_ctr != 14'd0)
            por_ctr <= por_ctr - 14'd1;
    end
    wire por_rst = !SYS_RSTN || (por_ctr != 14'd0);

    wire clk_sys;
    wire clk_ddr;
    wire clk_dq;
    wire pll_locked;

    ddr3_800_clocking u_clocking (
        .i_clk_50(SYS_CLK),
        .i_rst(por_rst),
        .o_clk_sys(clk_sys),
        .o_clk_ddr(clk_ddr),
        .o_clk_dq(clk_dq),
        .o_locked(pll_locked)
    );

    reg [4:0] rst_ddr_sr = 5'b1_1111;
    always @(posedge clk_ddr or posedge por_rst) begin
        if (por_rst)
            rst_ddr_sr <= 5'b1_1111;
        else if (!pll_locked)
            rst_ddr_sr <= 5'b1_1111;
        else
            rst_ddr_sr <= {rst_ddr_sr[3:0], 1'b0};
    end
    wire rst_ddr = rst_ddr_sr[4];

    reg [4:0] rst_sys_sr = 5'b1_1111;
    always @(posedge clk_sys or posedge por_rst) begin
        if (por_rst)
            rst_sys_sr <= 5'b1_1111;
        else if (!pll_locked)
            rst_sys_sr <= 5'b1_1111;
        else
            rst_sys_sr <= {rst_sys_sr[3:0], 1'b0};
    end
    wire rst_sys = rst_sys_sr[4];

    reg [4:0] rst_dq_sr = 5'b1_1111;
    always @(posedge clk_dq or posedge por_rst) begin
        if (por_rst)
            rst_dq_sr <= 5'b1_1111;
        else if (!pll_locked)
            rst_dq_sr <= 5'b1_1111;
        else
            rst_dq_sr <= {rst_dq_sr[3:0], 1'b0};
    end
    wire rst_dq = rst_dq_sr[4];

    wire [CHANNELS-1:0] init_done;
    wire [CHANNELS-1:0] init_busy;
    wire [CHANNELS*5-1:0] init_state;
    wire init_all_done;
    wire [CHANNELS-1:0] refresh_req;
    wire [CHANNELS-1:0] refresh_ack;
    wire [CHANNELS-1:0] refresh_busy;
    wire [CHANNELS-1:0] refresh_late;
    wire [CHANNELS*16-1:0] refresh_count;
    wire [CHANNELS-1:0] ctrl_reset_n;
    wire [CHANNELS-1:0] ctrl_cke;
    wire [CHANNELS-1:0] ctrl_odt;
    wire [CHANNELS-1:0] ctrl_cmd_valid;
    wire [CHANNELS-1:0] ctrl_cs_n;
    wire [CHANNELS-1:0] ctrl_ras_n;
    wire [CHANNELS-1:0] ctrl_cas_n;
    wire [CHANNELS-1:0] ctrl_we_n;
    wire [CHANNELS*BANK_BITS-1:0] ctrl_ba;
    wire [CHANNELS*ADDR_BITS-1:0] ctrl_addr;

    genvar ch;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_init_channel
            ddr3_init_refresh_probe_channel #(
                .ADDR_BITS(ADDR_BITS),
                .BANK_BITS(BANK_BITS)
            ) u_channel (
                .i_clk_ctrl(clk_sys),
                .i_clk_dq(clk_dq),
                .i_rst_ctrl(rst_sys),
                .i_rst_dq(rst_dq),
                .i_start(1'b1),
                .o_init_done(init_done[ch]),
                .o_init_busy(init_busy[ch]),
                .o_init_state(init_state[ch*5 +: 5]),
                .o_refresh_req(refresh_req[ch]),
                .o_refresh_ack(refresh_ack[ch]),
                .o_refresh_busy(refresh_busy[ch]),
                .o_refresh_late(refresh_late[ch]),
                .o_refresh_count(refresh_count[ch*16 +: 16]),
                .o_ddr_reset_n(ctrl_reset_n[ch]),
                .o_ddr_cke(ctrl_cke[ch]),
                .o_ddr_odt(ctrl_odt[ch]),
                .o_ddr_cmd_valid(ctrl_cmd_valid[ch]),
                .o_ddr_cs_n(ctrl_cs_n[ch]),
                .o_ddr_ras_n(ctrl_ras_n[ch]),
                .o_ddr_cas_n(ctrl_cas_n[ch]),
                .o_ddr_we_n(ctrl_we_n[ch]),
                .o_ddr_ba(ctrl_ba[ch*BANK_BITS +: BANK_BITS]),
                .o_ddr_addr(ctrl_addr[ch*ADDR_BITS +: ADDR_BITS])
            );
        end
    endgenerate

    assign init_all_done = &init_done;

    ddr3_cmd_pins_7series #(
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS)
    ) u_ch0_cmd (
        .i_clk_dq(clk_dq),
        .i_rst(rst_dq),
        .i_reset_n(ctrl_reset_n[0]),
        .i_cke(ctrl_cke[0]),
        .i_odt(ctrl_odt[0]),
        .i_cmd_valid(ctrl_cmd_valid[0]),
        .i_cs_n(ctrl_cs_n[0]),
        .i_ras_n(ctrl_ras_n[0]),
        .i_cas_n(ctrl_cas_n[0]),
        .i_we_n(ctrl_we_n[0]),
        .i_ba(ctrl_ba[0*BANK_BITS +: BANK_BITS]),
        .i_addr(ctrl_addr[0*ADDR_BITS +: ADDR_BITS]),
        .o_reset_n(ddr3_reset_n),
        .o_cke(ddr3_cke),
        .o_odt(ddr3_odt),
        .o_cs_n(ddr3_cs_n),
        .o_ras_n(ddr3_ras_n),
        .o_cas_n(ddr3_cas_n),
        .o_we_n(ddr3_we_n),
        .o_ba(ddr3_ba),
        .o_addr(ddr3_addr)
    );

    ddr3_cmd_pins_7series #(
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS)
    ) u_ch1_cmd (
        .i_clk_dq(clk_dq),
        .i_rst(rst_dq),
        .i_reset_n(ctrl_reset_n[1]),
        .i_cke(ctrl_cke[1]),
        .i_odt(ctrl_odt[1]),
        .i_cmd_valid(ctrl_cmd_valid[1]),
        .i_cs_n(ctrl_cs_n[1]),
        .i_ras_n(ctrl_ras_n[1]),
        .i_cas_n(ctrl_cas_n[1]),
        .i_we_n(ctrl_we_n[1]),
        .i_ba(ctrl_ba[1*BANK_BITS +: BANK_BITS]),
        .i_addr(ctrl_addr[1*ADDR_BITS +: ADDR_BITS]),
        .o_reset_n(ddr3_ch1_reset_n),
        .o_cke(ddr3_ch1_cke),
        .o_odt(ddr3_ch1_odt),
        .o_cs_n(ddr3_ch1_cs_n),
        .o_ras_n(ddr3_ch1_ras_n),
        .o_cas_n(ddr3_ch1_cas_n),
        .o_we_n(ddr3_ch1_we_n),
        .o_ba(ddr3_ch1_ba),
        .o_addr(ddr3_ch1_addr)
    );

    ddr3_ck_out_7series u_ch0_ck (
        .i_clk_ddr(clk_ddr),
        .i_rst(rst_ddr),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    ddr3_ck_out_7series u_ch1_ck (
        .i_clk_ddr(clk_ddr),
        .i_rst(rst_ddr),
        .o_ck_p(ddr3_ch1_ck_p),
        .o_ck_n(ddr3_ch1_ck_n)
    );

    ddr3_hiz_lanes_7series u_ch0_hiz (
        .io_dq(ddr3_dq),
        .io_dqs_p(ddr3_dqs_p),
        .io_dqs_n(ddr3_dqs_n)
    );

    ddr3_hiz_lanes_7series u_ch1_hiz (
        .io_dq(ddr3_ch1_dq),
        .io_dqs_p(ddr3_ch1_dqs_p),
        .io_dqs_n(ddr3_ch1_dqs_n)
    );

    wire clk_ref_alive;
    wire clk_ref_bit;
    wire [5:0] clk_ref_ticks;
    wire clk_sys_alive;
    wire clk_sys_bit;
    wire [5:0] clk_sys_ticks;
    wire clk_ddr_alive;
    wire clk_ddr_bit;
    wire [5:0] clk_ddr_ticks;
    wire clk_dq_alive;
    wire clk_dq_bit;
    wire [5:0] clk_dq_ticks;

    clk_liveness u_ref_live (
        .i_clk(SYS_CLK),
        .i_clk_obs(SYS_CLK),
        .o_alive(clk_ref_alive),
        .o_synced_bit(clk_ref_bit),
        .o_ticks_lo(clk_ref_ticks)
    );

    clk_liveness u_sys_live (
        .i_clk(clk_sys),
        .i_clk_obs(SYS_CLK),
        .o_alive(clk_sys_alive),
        .o_synced_bit(clk_sys_bit),
        .o_ticks_lo(clk_sys_ticks)
    );

    clk_liveness u_ddr_live (
        .i_clk(clk_ddr),
        .i_clk_obs(SYS_CLK),
        .o_alive(clk_ddr_alive),
        .o_synced_bit(clk_ddr_bit),
        .o_ticks_lo(clk_ddr_ticks)
    );

    clk_liveness u_dq_live (
        .i_clk(clk_dq),
        .i_clk_obs(SYS_CLK),
        .o_alive(clk_dq_alive),
        .o_synced_bit(clk_dq_bit),
        .o_ticks_lo(clk_dq_ticks)
    );

    reg [23:0] heartbeat = 24'd0;
    always @(posedge SYS_CLK) begin
        if (por_rst)
            heartbeat <= 24'd0;
        else
            heartbeat <= heartbeat + 24'd1;
    end

    wire refresh_any_late = |refresh_late;
    wire reset_any = rst_sys || rst_ddr || rst_dq;
    wire [31:0] status_flags_ddr = {
        16'hB07E,
        1'b0,              // no DQ calibration in this image
        1'b0,
        2'b00,
        init_all_done,
        1'b0,
        4'b0000,
        pll_locked,
        1'b0,              // no IDELAYCTRL in this image
        reset_any,
        1'b0,
        refresh_any_late,
        heartbeat[23]
    };

    wire [31:0] state_word_ddr = {
        6'd0,
        init_state[1*5 +: 5],
        init_state[0*5 +: 5],
        refresh_req,
        refresh_ack,
        refresh_busy,
        refresh_late,
        heartbeat[7:0]
    };

    reg [31:0] status_flags_meta;
    reg [31:0] status_flags_sync;
    reg [31:0] state_word_meta;
    reg [31:0] state_word_sync;
    reg [31:0] refresh0_meta;
    reg [31:0] refresh0_sync;
    reg [31:0] refresh1_meta;
    reg [31:0] refresh1_sync;

    always @(posedge SYS_CLK) begin
        status_flags_meta <= status_flags_ddr;
        status_flags_sync <= status_flags_meta;
        state_word_meta <= state_word_ddr;
        state_word_sync <= state_word_meta;
        refresh0_meta <= {16'hF0C0, refresh_count[0*16 +: 16]};
        refresh0_sync <= refresh0_meta;
        refresh1_meta <= {16'hF0C1, refresh_count[1*16 +: 16]};
        refresh1_sync <= refresh1_meta;
    end

    wire [31:0] clk_ref_status = {16'hC150, clk_ref_alive, clk_ref_bit, 8'd0,
                                  clk_ref_ticks};
    wire [31:0] clk_sys_status = {16'hC151, clk_sys_alive, clk_sys_bit, 8'd0,
                                  clk_sys_ticks};
    wire [31:0] clk_ddr_status = {16'hC152, clk_ddr_alive, clk_ddr_bit, 8'd0,
                                  clk_ddr_ticks};
    wire [31:0] clk_dq_status = {16'hC153, clk_dq_alive, clk_dq_bit, 8'd0,
                                 clk_dq_ticks};

    wire [31:0] host_to_fpga;
    wire host_to_fpga_valid;
    reg [31:0] status_word = 32'd0;

    jtag_uart #(
        .WB_DATA_W(32),
        .WB_ADDR_W(2),
        .USER_CHAIN(1)
    ) u_jtag_uart (
        .i_clk(SYS_CLK),
        .i_rst(por_rst),
        .i_wb_cyc(1'b0),
        .i_wb_stb(1'b0),
        .i_wb_we(1'b0),
        .i_wb_adr(2'b00),
        .i_wb_dat(32'd0),
        .i_wb_sel(4'h0),
        .o_wb_stall(),
        .o_wb_ack(),
        .o_wb_dat(),
        .o_wb_err(),
        .i_fpga_to_host(status_word),
        .o_host_to_fpga(host_to_fpga),
        .o_host_to_fpga_valid(host_to_fpga_valid)
    );

    reg [31:0] status_word_comb;
    always @(*) begin
        case (host_to_fpga[7:0])
            8'h00: status_word_comb = status_flags_sync;
            8'h01: status_word_comb = state_word_sync;
            8'h02: status_word_comb = {8'h00, heartbeat};
            8'h15: status_word_comb = clk_sys_status;
            8'h16: status_word_comb = clk_ddr_status;
            8'h17: status_word_comb = clk_dq_status;
            8'h18: status_word_comb = clk_ref_status;
            8'h20: status_word_comb = refresh0_sync;
            8'h21: status_word_comb = refresh1_sync;
            8'hFE: status_word_comb = 32'hB07E_0D80;
            8'hFF: status_word_comb = host_to_fpga;
            default: status_word_comb = {24'hD3AD80, host_to_fpga[7:0]};
        endcase
    end

    always @(posedge SYS_CLK) begin
        status_word <= status_word_comb;
    end

    assign led_3bits_tri_o[0] = heartbeat[23];
    assign led_3bits_tri_o[1] = init_all_done;
    assign led_3bits_tri_o[2] = !pll_locked || refresh_any_late;

    wire _unused = &{1'b0, host_to_fpga_valid, init_busy, clk_ref_status,
                     1'b0};
endmodule

module ddr3_init_refresh_probe_channel #(
    parameter integer ADDR_BITS = 15,
    parameter integer BANK_BITS = 3,
    parameter integer CTRL_DIV = 4,
    parameter integer RESET_LOW_CYCLES =
        (`DDR3_800_RESET_LOW_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer RESET_CKE_CYCLES =
        (`DDR3_800_RESET_CKE_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TXPR_CYCLES =
        (`DDR3_800_TXPR_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TMRD_CYCLES =
        (`DDR3_800_TMRD_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TMOD_CYCLES =
        (`DDR3_800_TMOD_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TZQINIT_CYCLES =
        (`DDR3_800_TZQINIT_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TRFC_CYCLES =
        (`DDR3_800_TRFC_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TDLLK_CYCLES =
        (`DDR3_800_TDLLK_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer TREFI_CYCLES =
        (`DDR3_800_TREFI_CYCLES + CTRL_DIV - 1) / CTRL_DIV,
    parameter integer REFRESH_MARGIN_CYCLES =
        (`DDR3_800_REFRESH_MARGIN_CYCLES + CTRL_DIV - 1) / CTRL_DIV
) (
    input  wire                  i_clk_ctrl,
    input  wire                  i_clk_dq,
    input  wire                  i_rst_ctrl,
    input  wire                  i_rst_dq,
    input  wire                  i_start,
    output wire                  o_init_done,
    output wire                  o_init_busy,
    output wire [4:0]            o_init_state,
    output wire                  o_refresh_req,
    output reg                   o_refresh_ack,
    output reg                   o_refresh_busy,
    output wire                  o_refresh_late,
    output wire [15:0]           o_refresh_count,
    output reg                   o_ddr_reset_n,
    output reg                   o_ddr_cke,
    output reg                   o_ddr_odt,
    output reg                   o_ddr_cmd_valid,
    output reg                   o_ddr_cs_n,
    output reg                   o_ddr_ras_n,
    output reg                   o_ddr_cas_n,
    output reg                   o_ddr_we_n,
    output reg  [BANK_BITS-1:0]  o_ddr_ba,
    output reg  [ADDR_BITS-1:0]  o_ddr_addr
);
    wire init_odt;
    wire init_cmd_valid;
    wire init_cs_n;
    wire init_ras_n;
    wire init_cas_n;
    wire init_we_n;
    wire [BANK_BITS-1:0] init_ba;
    wire [ADDR_BITS-1:0] init_addr;
    wire init_reset_n;
    wire init_cke;
    wire refresh_window;
    wire [15:0] refresh_deadline;
    reg [15:0] refresh_wait = 16'd0;
    reg cmd_toggle_ctrl = 1'b0;
    reg payload_cs_n = 1'b1;
    reg payload_ras_n = 1'b1;
    reg payload_cas_n = 1'b1;
    reg payload_we_n = 1'b1;
    reg [BANK_BITS-1:0] payload_ba = {BANK_BITS{1'b0}};
    reg [ADDR_BITS-1:0] payload_addr = {ADDR_BITS{1'b0}};
    reg [2:0] cmd_toggle_dq = 3'b000;
    reg [2:0] reset_n_dq = 3'b000;
    reg [2:0] cke_dq = 3'b000;
    reg [2:0] odt_dq = 3'b000;

    ddr3_init_seq #(
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS),
        .RESET_LOW_CYCLES(RESET_LOW_CYCLES),
        .RESET_CKE_CYCLES(RESET_CKE_CYCLES),
        .TXPR_CYCLES(TXPR_CYCLES),
        .TMRD_CYCLES(TMRD_CYCLES),
        .TMOD_CYCLES(TMOD_CYCLES),
        .TZQINIT_CYCLES(TZQINIT_CYCLES),
        .TRFC_CYCLES(TRFC_CYCLES),
        .TDLLK_CYCLES(TDLLK_CYCLES)
    ) u_init (
        .i_clk(i_clk_ctrl),
        .i_rst(i_rst_ctrl),
        .i_start(i_start),
        .o_busy(o_init_busy),
        .o_done(o_init_done),
        .o_state(o_init_state),
        .o_reset_n(init_reset_n),
        .o_cke(init_cke),
        .o_odt(init_odt),
        .o_cmd_valid(init_cmd_valid),
        .o_cs_n(init_cs_n),
        .o_ras_n(init_ras_n),
        .o_cas_n(init_cas_n),
        .o_we_n(init_we_n),
        .o_ba(init_ba),
        .o_addr(init_addr)
    );

    ddr3_refresh #(
        .COUNTER_BITS(16),
        .T_REFI(TREFI_CYCLES),
        .T_MARGIN(REFRESH_MARGIN_CYCLES)
    ) u_refresh (
        .i_clk(i_clk_ctrl),
        .i_rst(i_rst_ctrl),
        .i_enable(o_init_done),
        .i_refresh_ack(o_refresh_ack),
        .o_refresh_req(o_refresh_req),
        .o_refresh_late(o_refresh_late),
        .o_refresh_window(refresh_window),
        .o_cycles_to_deadline(refresh_deadline),
        .o_refresh_count(o_refresh_count)
    );

    function [15:0] load_refresh_wait;
        input integer cycles;
        begin
            load_refresh_wait = (cycles <= 1) ? 16'd0 : cycles[15:0] - 16'd1;
        end
    endfunction

    always @(posedge i_clk_ctrl) begin
        if (i_rst_ctrl) begin
            o_refresh_ack <= 1'b0;
            o_refresh_busy <= 1'b0;
            refresh_wait <= 16'd0;
            cmd_toggle_ctrl <= 1'b0;
            payload_cs_n <= 1'b1;
            payload_ras_n <= 1'b1;
            payload_cas_n <= 1'b1;
            payload_we_n <= 1'b1;
            payload_ba <= {BANK_BITS{1'b0}};
            payload_addr <= {ADDR_BITS{1'b0}};
        end else if (!o_init_done) begin
            o_refresh_ack <= 1'b0;
            o_refresh_busy <= 1'b0;
            refresh_wait <= 16'd0;
            if (init_cmd_valid && !init_cs_n) begin
                payload_cs_n <= init_cs_n;
                payload_ras_n <= init_ras_n;
                payload_cas_n <= init_cas_n;
                payload_we_n <= init_we_n;
                payload_ba <= init_ba;
                payload_addr <= init_addr;
                cmd_toggle_ctrl <= !cmd_toggle_ctrl;
            end
        end else begin
            o_refresh_ack <= 1'b0;
            if (refresh_wait != 16'd0) begin
                refresh_wait <= refresh_wait - 16'd1;
                o_refresh_busy <= 1'b1;
            end else if (o_refresh_req && !o_refresh_ack) begin
                o_refresh_ack <= 1'b1;
                o_refresh_busy <= 1'b1;
                refresh_wait <= load_refresh_wait(TRFC_CYCLES);
                payload_cs_n <= 1'b0;
                payload_ras_n <= 1'b0;
                payload_cas_n <= 1'b0;
                payload_we_n <= 1'b1;
                payload_ba <= {BANK_BITS{1'b0}};
                payload_addr <= {ADDR_BITS{1'b0}};
                cmd_toggle_ctrl <= !cmd_toggle_ctrl;
            end else begin
                o_refresh_busy <= 1'b0;
            end
        end
    end

    always @(posedge i_clk_dq) begin
        cmd_toggle_dq <= {cmd_toggle_dq[1:0], cmd_toggle_ctrl};
        reset_n_dq <= {reset_n_dq[1:0], init_reset_n};
        cke_dq <= {cke_dq[1:0], init_cke};
        odt_dq <= {odt_dq[1:0], init_odt};
        o_ddr_reset_n <= reset_n_dq[2];
        o_ddr_cke <= cke_dq[2];
        o_ddr_odt <= odt_dq[2];

        if (cmd_toggle_dq[2] ^ cmd_toggle_dq[1]) begin
            o_ddr_cmd_valid <= 1'b1;
            o_ddr_cs_n <= payload_cs_n;
            o_ddr_ras_n <= payload_ras_n;
            o_ddr_cas_n <= payload_cas_n;
            o_ddr_we_n <= payload_we_n;
            o_ddr_ba <= payload_ba;
            o_ddr_addr <= payload_addr;
        end else begin
            o_ddr_cmd_valid <= 1'b0;
            o_ddr_cs_n <= 1'b1;
            o_ddr_ras_n <= 1'b1;
            o_ddr_cas_n <= 1'b1;
            o_ddr_we_n <= 1'b1;
            o_ddr_ba <= {BANK_BITS{1'b0}};
            o_ddr_addr <= {ADDR_BITS{1'b0}};
        end
    end

    wire _unused = &{1'b0, i_rst_dq, refresh_window, refresh_deadline, 1'b0};
endmodule

module ddr3_800_clocking (
    input  wire i_clk_50,
    input  wire i_rst,
    output wire o_clk_sys,
    output wire o_clk_ddr,
    output wire o_clk_dq,
    output wire o_locked
);
    wire clkfb;
    wire clk_sys_raw;
    wire clk_ddr_raw;
    wire clk_dq_raw;

    PLLE2_ADV #(
        .CLKIN1_PERIOD(20.0),
        .CLKFBOUT_MULT(16),
        .DIVCLK_DIVIDE(1),
        .CLKOUT0_DIVIDE(8),
        .CLKOUT1_DIVIDE(2),
        .CLKOUT2_DIVIDE(2),
        .CLKOUT2_PHASE(90.0),
        .COMPENSATION("INTERNAL"),
        .STARTUP_WAIT("FALSE")
    ) u_pll (
        .CLKIN1(i_clk_50),
        .CLKIN2(1'b0),
        .CLKINSEL(1'b1),
        .RST(i_rst),
        .PWRDWN(1'b0),
        .CLKFBIN(clkfb),
        .CLKFBOUT(clkfb),
        .CLKOUT0(clk_sys_raw),
        .CLKOUT1(clk_ddr_raw),
        .CLKOUT2(clk_dq_raw),
        .CLKOUT3(),
        .CLKOUT4(),
        .CLKOUT5(),
        .LOCKED(o_locked),
        .DADDR(7'b0),
        .DCLK(1'b0),
        .DEN(1'b0),
        .DI(16'b0),
        .DWE(1'b0),
        .DO(),
        .DRDY()
    );

    BUFG u_bufg_sys (.I(clk_sys_raw), .O(o_clk_sys));
    BUFG u_bufg_ddr (.I(clk_ddr_raw), .O(o_clk_ddr));
    BUFG u_bufg_dq  (.I(clk_dq_raw),  .O(o_clk_dq));
endmodule

module ddr3_ck_out_7series (
    input  wire i_clk_ddr,
    input  wire i_rst,
    output wire o_ck_p,
    output wire o_ck_n
);
    wire ck_out;

    ODDR #(
        .DDR_CLK_EDGE("SAME_EDGE"),
        .INIT(1'b0),
        .SRTYPE("SYNC")
    ) u_oddr_ck (
        .Q(ck_out),
        .C(i_clk_ddr),
        .CE(1'b1),
        .D1(1'b1),
        .D2(1'b0),
        .R(i_rst),
        .S(1'b0)
    );

    OBUFDS u_obufds_ck (
        .I(ck_out),
        .O(o_ck_p),
        .OB(o_ck_n)
    );
endmodule

module ddr3_cmd_pins_7series #(
    parameter integer ADDR_BITS = 15,
    parameter integer BANK_BITS = 3
) (
    input  wire                  i_clk_dq,
    input  wire                  i_rst,
    input  wire                  i_reset_n,
    input  wire                  i_cke,
    input  wire                  i_odt,
    input  wire                  i_cmd_valid,
    input  wire                  i_cs_n,
    input  wire                  i_ras_n,
    input  wire                  i_cas_n,
    input  wire                  i_we_n,
    input  wire [BANK_BITS-1:0]  i_ba,
    input  wire [ADDR_BITS-1:0]  i_addr,
    output reg                   o_reset_n,
    output reg                   o_cke,
    output reg                   o_odt,
    output reg                   o_cs_n,
    output reg                   o_ras_n,
    output reg                   o_cas_n,
    output reg                   o_we_n,
    output reg  [BANK_BITS-1:0]  o_ba,
    output reg  [ADDR_BITS-1:0]  o_addr
);
    initial begin
        o_reset_n = 1'b0;
        o_cke = 1'b0;
        o_odt = 1'b0;
        o_cs_n = 1'b1;
        o_ras_n = 1'b1;
        o_cas_n = 1'b1;
        o_we_n = 1'b1;
        o_ba = {BANK_BITS{1'b0}};
        o_addr = {ADDR_BITS{1'b0}};
    end

    always @(posedge i_clk_dq) begin
        o_reset_n <= i_reset_n;
        o_cke     <= i_cke;
        o_odt     <= i_odt;
        if (i_cmd_valid) begin
            o_cs_n  <= i_cs_n;
            o_ras_n <= i_ras_n;
            o_cas_n <= i_cas_n;
            o_we_n  <= i_we_n;
            o_ba    <= i_ba;
            o_addr  <= i_addr;
        end else begin
            o_cs_n  <= 1'b1;
            o_ras_n <= 1'b1;
            o_cas_n <= 1'b1;
            o_we_n  <= 1'b1;
            o_ba    <= {BANK_BITS{1'b0}};
            o_addr  <= {ADDR_BITS{1'b0}};
        end
    end

    wire _unused = &{1'b0, i_rst, 1'b0};
endmodule

module ddr3_hiz_lanes_7series (
    inout wire [71:0] io_dq,
    inout wire [8:0]  io_dqs_p,
    inout wire [8:0]  io_dqs_n
);
    wire [71:0] dq_in;
    wire [8:0] dqs_in;

    genvar i;
    generate
        for (i = 0; i < 72; i = i + 1) begin : gen_dq_hiz
            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O(dq_in[i]),
                .IO(io_dq[i]),
                .I(1'b0),
                .T(1'b1)
            );
        end

        for (i = 0; i < 9; i = i + 1) begin : gen_dqs_hiz
            IOBUFDS u_dqs_iobuf (
                .O(dqs_in[i]),
                .IO(io_dqs_p[i]),
                .IOB(io_dqs_n[i]),
                .I(1'b0),
                .T(1'b1)
            );
        end
    endgenerate

    wire _unused = &{1'b0, dq_in, dqs_in, 1'b0};
endmodule

`default_nettype wire
