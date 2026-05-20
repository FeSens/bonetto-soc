// BRAM-only hardware proof for the YPCB-00338 JTAG/Wishbone path.
//
// This top intentionally excludes all DDR3 RTL. It validates:
//   BSCANE2 USER1 -> jtag_uart -> jtag_wb_master -> wb_decode2 -> BRAM banks
// using only SYS_CLK, SYS_RSTN, and the board LEDs.

`default_nettype none

module top_jtag_bram (
    input  wire       SYS_CLK,
    input  wire       SYS_RSTN,
    output wire [2:0] led_3bits_tri_o
);
    localparam integer WB_DATA_W = 32;
    localparam integer WB_ADDR_W = 15;

    reg [13:0] por_ctr = 14'h3fff;
    always @(posedge SYS_CLK) begin
        if (!SYS_RSTN)
            por_ctr <= 14'h3fff;
        else if (por_ctr != 14'd0)
            por_ctr <= por_ctr - 14'd1;
    end
    wire rst = !SYS_RSTN || (por_ctr != 14'd0);

    reg [23:0] heartbeat = 24'd0;
    always @(posedge SYS_CLK) begin
        if (rst)
            heartbeat <= 24'd0;
        else
            heartbeat <= heartbeat + 24'd1;
    end

    wire [31:0] host_to_fpga;
    wire        host_to_fpga_valid;
    reg  [31:0] status_word = 32'd0;

    jtag_uart #(
        .WB_DATA_W  (WB_DATA_W),
        .WB_ADDR_W  (2),
        .USER_CHAIN (1)
    ) u_jtag_uart (
        .i_clk                (SYS_CLK),
        .i_rst                (rst),
        .i_wb_cyc             (1'b0),
        .i_wb_stb             (1'b0),
        .i_wb_we              (1'b0),
        .i_wb_adr             (2'b00),
        .i_wb_dat             (32'd0),
        .i_wb_sel             (4'h0),
        .o_wb_stall           (),
        .o_wb_ack             (),
        .o_wb_dat             (),
        .o_wb_err             (),
        .i_fpga_to_host       (status_word),
        .o_host_to_fpga       (host_to_fpga),
        .o_host_to_fpga_valid (host_to_fpga_valid)
    );

    wire                    jwb_cyc;
    wire                    jwb_stb;
    wire                    jwb_we;
    wire [WB_ADDR_W-1:0]    jwb_adr;
    wire [WB_DATA_W-1:0]    jwb_dat_w;
    wire [WB_DATA_W/8-1:0]  jwb_sel;
    wire                    jwb_stall;
    wire                    jwb_ack;
    wire [WB_DATA_W-1:0]    jwb_dat_r;
    wire                    jwb_err;
    wire                    jwb_busy;
    wire                    jwb_last_ack;
    wire                    jwb_last_err;
    wire [WB_ADDR_W-1:0]    jwb_addr_echo;
    wire [15:0]             jwb_addr_hi_echo;
    wire [WB_DATA_W-1:0]    jwb_data_echo;
    wire [WB_DATA_W-1:0]    jwb_rd_data;
    wire                    jwb_halt_others;

    jtag_wb_master #(
        .WB_ADDR_W      (WB_ADDR_W),
        .WB_DATA_W      (WB_DATA_W),
        .NUM_BYTE_LANES (9)
    ) u_jtag_wb_master (
        .i_clk             (SYS_CLK),
        .i_rst             (rst),
        .i_cmd_word        (host_to_fpga),
        .i_cmd_valid       (host_to_fpga_valid),
        .o_wb_cyc          (jwb_cyc),
        .o_wb_stb          (jwb_stb),
        .o_wb_we           (jwb_we),
        .o_wb_adr          (jwb_adr),
        .o_wb_dat          (jwb_dat_w),
        .o_wb_sel          (jwb_sel),
        .i_wb_stall        (jwb_stall),
        .i_wb_ack          (jwb_ack),
        .i_wb_dat          (jwb_dat_r),
        .i_wb_err          (jwb_err),
        .o_busy            (jwb_busy),
        .o_last_ack        (jwb_last_ack),
        .o_last_err        (jwb_last_err),
        .o_addr            (jwb_addr_echo),
        .o_addr_hi         (jwb_addr_hi_echo),
        .o_data            (jwb_data_echo),
        .o_rd_data         (jwb_rd_data),
        .o_halt_others     (jwb_halt_others),
        .o_cal_load_lane   (),
        .o_cal_tap         (),
        .o_cal_channel     (),
        .o_phase_req       (),
        .o_phase_inc       ()
    );

    wire                    s0_cyc;
    wire                    s0_stb;
    wire                    s0_we;
    wire [WB_ADDR_W-1:0]    s0_adr;
    wire [WB_DATA_W-1:0]    s0_dat_w;
    wire [WB_DATA_W/8-1:0]  s0_sel;
    wire                    s0_stall;
    wire                    s0_ack;
    wire [WB_DATA_W-1:0]    s0_dat_r;
    wire                    s0_err;

    wire                    s1_cyc;
    wire                    s1_stb;
    wire                    s1_we;
    wire [WB_ADDR_W-1:0]    s1_adr;
    wire [WB_DATA_W-1:0]    s1_dat_w;
    wire [WB_DATA_W/8-1:0]  s1_sel;
    wire                    s1_stall;
    wire                    s1_ack;
    wire [WB_DATA_W-1:0]    s1_dat_r;
    wire                    s1_err;

    wb_decode2 #(
        .WB_DATA_W (WB_DATA_W),
        .WB_ADDR_W (WB_ADDR_W),
        .SEL_BIT   (14)
    ) u_decode (
        .i_clk       (SYS_CLK),
        .i_rst       (rst),
        .i_wb_cyc    (jwb_cyc),
        .i_wb_stb    (jwb_stb),
        .i_wb_we     (jwb_we),
        .i_wb_adr    (jwb_adr),
        .i_wb_dat    (jwb_dat_w),
        .i_wb_sel    (jwb_sel),
        .o_wb_stall  (jwb_stall),
        .o_wb_ack    (jwb_ack),
        .o_wb_dat    (jwb_dat_r),
        .o_wb_err    (jwb_err),
        .o_s0_cyc    (s0_cyc),
        .o_s0_stb    (s0_stb),
        .o_s0_we     (s0_we),
        .o_s0_adr    (s0_adr),
        .o_s0_dat    (s0_dat_w),
        .o_s0_sel    (s0_sel),
        .i_s0_stall  (s0_stall),
        .i_s0_ack    (s0_ack),
        .i_s0_dat    (s0_dat_r),
        .i_s0_err    (s0_err),
        .o_s1_cyc    (s1_cyc),
        .o_s1_stb    (s1_stb),
        .o_s1_we     (s1_we),
        .o_s1_adr    (s1_adr),
        .o_s1_dat    (s1_dat_w),
        .o_s1_sel    (s1_sel),
        .i_s1_stall  (s1_stall),
        .i_s1_ack    (s1_ack),
        .i_s1_dat    (s1_dat_r),
        .i_s1_err    (s1_err)
    );

    wb_memory #(
        .WB_DATA_W (WB_DATA_W),
        .WB_ADDR_W (14)
    ) u_bram0 (
        .i_clk      (SYS_CLK),
        .i_rst      (rst),
        .i_wb_cyc   (s0_cyc),
        .i_wb_stb   (s0_stb),
        .i_wb_we    (s0_we),
        .i_wb_adr   (s0_adr[13:0]),
        .i_wb_dat   (s0_dat_w),
        .i_wb_sel   (s0_sel),
        .o_wb_stall (s0_stall),
        .o_wb_ack   (s0_ack),
        .o_wb_dat   (s0_dat_r),
        .o_wb_err   (s0_err)
    );

    wb_memory #(
        .WB_DATA_W (WB_DATA_W),
        .WB_ADDR_W (14)
    ) u_bram1 (
        .i_clk      (SYS_CLK),
        .i_rst      (rst),
        .i_wb_cyc   (s1_cyc),
        .i_wb_stb   (s1_stb),
        .i_wb_we    (s1_we),
        .i_wb_adr   (s1_adr[13:0]),
        .i_wb_dat   (s1_dat_w),
        .i_wb_sel   (s1_sel),
        .o_wb_stall (s1_stall),
        .o_wb_ack   (s1_ack),
        .o_wb_dat   (s1_dat_r),
        .o_wb_err   (s1_err)
    );

    wire [31:0] status_flags = {
        16'hAB00,
        10'd0,
        rst,
        jwb_busy,
        jwb_last_ack,
        jwb_last_err,
        jwb_halt_others,
        heartbeat[23]
    };

    reg [31:0] status_word_comb;
    always @(*) begin
        case (host_to_fpga[7:0])
            8'h00:   status_word_comb = status_flags;
            8'h02:   status_word_comb = {8'h00, heartbeat};
            8'h10:   status_word_comb = {16'hAB10, 12'd0,
                                          jwb_busy, jwb_last_ack,
                                          jwb_last_err, jwb_halt_others};
            8'h11:   status_word_comb = {17'd0, jwb_addr_echo};
            8'h12:   status_word_comb = jwb_data_echo;
            8'h13:   status_word_comb = jwb_rd_data;
            8'h1A:   status_word_comb = {16'hAB1A, jwb_addr_hi_echo};
            8'hFE:   status_word_comb = {16'hB07E, 16'hB001};
            8'hFF:   status_word_comb = host_to_fpga;
            default: status_word_comb = {24'hDEADBA, host_to_fpga[7:0]};
        endcase
    end

    always @(posedge SYS_CLK) begin
        status_word <= status_word_comb;
    end

    assign led_3bits_tri_o[0] = heartbeat[23];
    assign led_3bits_tri_o[1] = jwb_last_ack;
    assign led_3bits_tri_o[2] = jwb_last_err;
endmodule
