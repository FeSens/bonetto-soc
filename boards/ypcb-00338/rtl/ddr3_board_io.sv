// YPCB-00338 DDR3 board I/O helpers.
//
// These modules are intentionally board-local. They wrap the 7-series
// primitives used by staged DDR3 bring-up images so controller RTL can stay
// free of package-pin and openXC7 primitive details.

`default_nettype none

module ddr3_800_clocking (
    input  wire i_clk_50,
    input  wire i_rst,
    output wire o_clk_sys,
    output wire o_clk_ddr,
    output wire o_clk_dq,
    output wire o_clk_idelay_ref,
    output wire o_locked
);
    wire clkfb;
    wire clk_sys_raw;
    wire clk_ddr_raw;
    wire clk_dq_raw;
    wire clk_idelay_ref_raw;

    PLLE2_ADV #(
        .CLKIN1_PERIOD(20.0),
        .CLKFBOUT_MULT(16),
        .DIVCLK_DIVIDE(1),
        .CLKOUT0_DIVIDE(8),
        .CLKOUT1_DIVIDE(2),
        .CLKOUT2_DIVIDE(2),
        .CLKOUT2_PHASE(90.0),
        .CLKOUT3_DIVIDE(4),
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
        .CLKOUT3(clk_idelay_ref_raw),
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
    BUFG u_bufg_idelay_ref (.I(clk_idelay_ref_raw), .O(o_clk_idelay_ref));
endmodule

module ddr3_idelayctrl_7series (
    input  wire i_clk_ref,
    input  wire i_rst,
    output wire o_ready
);
    reg [5:0] rst_ctr = 6'h3f;

    always @(posedge i_clk_ref) begin
        if (i_rst) begin
            rst_ctr <= 6'h3f;
        end else if (rst_ctr != 6'd0) begin
            rst_ctr <= rst_ctr - 6'd1;
        end
    end

    (* IODELAY_GROUP = "DDR3_SERDES_PROBE" *)
    IDELAYCTRL u_idelayctrl (
        .RDY(o_ready),
        .REFCLK(i_clk_ref),
        .RST(i_rst || (rst_ctr != 6'd0))
    );
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

module ddr3_cmd_cdc_7series #(
    parameter integer ADDR_BITS = 15,
    parameter integer BANK_BITS = 3
) (
    input  wire                  i_clk_ctrl,
    input  wire                  i_rst_ctrl,
    input  wire                  i_clk_dq,
    input  wire                  i_rst_dq,

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
    output reg                   o_cmd_valid,
    output reg                   o_cs_n,
    output reg                   o_ras_n,
    output reg                   o_cas_n,
    output reg                   o_we_n,
    output reg  [BANK_BITS-1:0]  o_ba,
    output reg  [ADDR_BITS-1:0]  o_addr
);
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

    initial begin
        o_reset_n = 1'b0;
        o_cke = 1'b0;
        o_odt = 1'b0;
        o_cmd_valid = 1'b0;
        o_cs_n = 1'b1;
        o_ras_n = 1'b1;
        o_cas_n = 1'b1;
        o_we_n = 1'b1;
        o_ba = {BANK_BITS{1'b0}};
        o_addr = {ADDR_BITS{1'b0}};
    end

    always @(posedge i_clk_ctrl) begin
        if (i_rst_ctrl) begin
            cmd_toggle_ctrl <= 1'b0;
            payload_cs_n <= 1'b1;
            payload_ras_n <= 1'b1;
            payload_cas_n <= 1'b1;
            payload_we_n <= 1'b1;
            payload_ba <= {BANK_BITS{1'b0}};
            payload_addr <= {ADDR_BITS{1'b0}};
        end else if (i_cmd_valid && !i_cs_n) begin
            payload_cs_n <= i_cs_n;
            payload_ras_n <= i_ras_n;
            payload_cas_n <= i_cas_n;
            payload_we_n <= i_we_n;
            payload_ba <= i_ba;
            payload_addr <= i_addr;
            cmd_toggle_ctrl <= !cmd_toggle_ctrl;
        end
    end

    always @(posedge i_clk_dq) begin
        cmd_toggle_dq <= {cmd_toggle_dq[1:0], cmd_toggle_ctrl};
        reset_n_dq <= {reset_n_dq[1:0], i_reset_n};
        cke_dq <= {cke_dq[1:0], i_cke};
        odt_dq <= {odt_dq[1:0], i_odt};
        o_reset_n <= reset_n_dq[2];
        o_cke <= cke_dq[2];
        o_odt <= odt_dq[2];

        if (cmd_toggle_dq[2] ^ cmd_toggle_dq[1]) begin
            o_cmd_valid <= 1'b1;
            o_cs_n <= payload_cs_n;
            o_ras_n <= payload_ras_n;
            o_cas_n <= payload_cas_n;
            o_we_n <= payload_we_n;
            o_ba <= payload_ba;
            o_addr <= payload_addr;
        end else begin
            o_cmd_valid <= 1'b0;
            o_cs_n <= 1'b1;
            o_ras_n <= 1'b1;
            o_cas_n <= 1'b1;
            o_we_n <= 1'b1;
            o_ba <= {BANK_BITS{1'b0}};
            o_addr <= {ADDR_BITS{1'b0}};
        end
    end

    wire _unused = &{1'b0, i_rst_dq, 1'b0};
endmodule

module ddr3_dq_dqs_io_7series #(
    parameter integer LANES = 9,
    parameter integer DQ_PER_LANE = 8
) (
    input  wire                              i_clk_dq,
    input  wire                              i_rst,

    input  wire [LANES-1:0]                 i_dq_oe,
    input  wire [LANES-1:0]                 i_dqs_oe,
    input  wire [(LANES*DQ_PER_LANE)-1:0]   i_dq_rise,
    input  wire [(LANES*DQ_PER_LANE)-1:0]   i_dq_fall,
    input  wire [LANES-1:0]                 i_dqs_rise,
    input  wire [LANES-1:0]                 i_dqs_fall,

    output wire [(LANES*DQ_PER_LANE)-1:0]   o_dq_rise,
    output wire [(LANES*DQ_PER_LANE)-1:0]   o_dq_fall,
    output wire [LANES-1:0]                 o_dqs_rise,
    output wire [LANES-1:0]                 o_dqs_fall,

    inout  wire [(LANES*DQ_PER_LANE)-1:0]   io_dq,
    inout  wire [LANES-1:0]                 io_dqs_p,
    inout  wire [LANES-1:0]                 io_dqs_n
);
    localparam integer DQ_BITS = LANES * DQ_PER_LANE;

    wire [DQ_BITS-1:0] dq_out;
    wire [DQ_BITS-1:0] dq_in;
    wire [LANES-1:0] dqs_out;
    wire [LANES-1:0] dqs_in;

    genvar lane_i;
    genvar bit_i;
    generate
        for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1) begin : gen_lane
            localparam integer DQ_BASE = lane_i * DQ_PER_LANE;

            for (bit_i = 0; bit_i < DQ_PER_LANE; bit_i = bit_i + 1) begin : gen_dq
                localparam integer DQ_IDX = DQ_BASE + bit_i;

                (* keep = "true", DONT_TOUCH = "true" *)
                ODDR #(
                    .DDR_CLK_EDGE("SAME_EDGE"),
                    .INIT(1'b0),
                    .SRTYPE("SYNC")
                ) u_dq_oddr (
                    .Q(dq_out[DQ_IDX]),
                    .C(i_clk_dq),
                    .CE(1'b1),
                    .D1(i_dq_rise[DQ_IDX]),
                    .D2(i_dq_fall[DQ_IDX]),
                    .R(i_rst),
                    .S(1'b0)
                );

                (* keep = "true", DONT_TOUCH = "true" *)
                IOBUF #(
                    .SLEW("FAST")
                ) u_dq_iobuf (
                    .O(dq_in[DQ_IDX]),
                    .IO(io_dq[DQ_IDX]),
                    .I(dq_out[DQ_IDX]),
                    .T(!i_dq_oe[lane_i])
                );

                (* keep = "true", DONT_TOUCH = "true" *)
                IDDR #(
                    .DDR_CLK_EDGE("SAME_EDGE"),
                    .INIT_Q1(1'b0),
                    .INIT_Q2(1'b0),
                    .SRTYPE("SYNC")
                ) u_dq_iddr (
                    .Q1(o_dq_rise[DQ_IDX]),
                    .Q2(o_dq_fall[DQ_IDX]),
                    .C(i_clk_dq),
                    .CE(1'b1),
                    .D(dq_in[DQ_IDX]),
                    .R(i_rst),
                    .S(1'b0)
                );
            end

            (* keep = "true", DONT_TOUCH = "true" *)
            ODDR #(
                .DDR_CLK_EDGE("SAME_EDGE"),
                .INIT(1'b0),
                .SRTYPE("SYNC")
            ) u_dqs_oddr (
                .Q(dqs_out[lane_i]),
                .C(i_clk_dq),
                .CE(1'b1),
                .D1(i_dqs_rise[lane_i]),
                .D2(i_dqs_fall[lane_i]),
                .R(i_rst),
                .S(1'b0)
            );

            (* keep = "true", DONT_TOUCH = "true" *)
            IOBUFDS u_dqs_iobuf (
                .O(dqs_in[lane_i]),
                .IO(io_dqs_p[lane_i]),
                .IOB(io_dqs_n[lane_i]),
                .I(dqs_out[lane_i]),
                .T(!i_dqs_oe[lane_i])
            );

            (* keep = "true", DONT_TOUCH = "true" *)
            IDDR #(
                .DDR_CLK_EDGE("SAME_EDGE"),
                .INIT_Q1(1'b0),
                .INIT_Q2(1'b0),
                .SRTYPE("SYNC")
            ) u_dqs_iddr (
                .Q1(o_dqs_rise[lane_i]),
                .Q2(o_dqs_fall[lane_i]),
                .C(i_clk_dq),
                .CE(1'b1),
                .D(dqs_in[lane_i]),
                .R(i_rst),
                .S(1'b0)
            );
        end
    endgenerate
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
