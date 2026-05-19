// ddr3_phy_dq — Single byte-lane DQ + DQS path for the DDR3 PHY.
//
// Iter-4 (HR-bank compatible): YPCB-00338's DDR3 DQS pins land on HR
// (high-range) banks of the xc7k480t — these don't support ODELAYE2.
// Write-leveling per JEDEC requires sweeping DQS output delay, so on
// this board we accept fixed 90° DQS-vs-CK timing from `clk_dq` (the
// MMCM's +90° output) and skip programmable DQS-out delay entirely.
//
// The cal interface still exposes DQS-out load/tap/toggle_en ports so
// upstream FSMs (wlvl) stay protocol-compatible; the load/tap inputs
// are simply ignored. The toggle_en still gates the OSERDESE2 T1 so
// wlvl-mode DQS toggling (for the future MMCM-phase-shift wlvl path)
// is possible without spurious lane interactions.
//
// DQ INPUT path: per-bit IDELAYE2 (rdlvl).
// DQS INPUT path: per-lane IDELAYE2 (rdlvl, gate-train).
// DQ OUTPUT path: RATIO4 uses fabric ODDR; RATIO8 normally uses OSERDESE2.
// `DDR3_RATIO8_ODDR_WR` keeps the RATIO8 read/capture path but forces the
// repeated-data diagnostic write path through the legacy ODDR launcher.
// `DDR3_RATIO8_ISERDES_RD` switches RATIO8 reads to the LiteDRAM-style
// IDELAYE2 + ISERDESE2 path clocked from the PHY high-speed clock. This avoids
// routing DQS as a fabric clock in the full-speed build.
// `DDR3_RATIO8_ISERDES_BUFIO_RDCLK` additionally inserts one BUFIO per byte
// lane for the ISERDES high-speed read clock as a routing diagnostic.
// DQS OUTPUT path: direct ODDR on clk_dq (no programmable delay).

`default_nettype none

module ddr3_phy_dq #(
    parameter integer DQ_BITS = 8,
    parameter integer RATIO   = 4,
    parameter integer WR_DQS_DELAY_CK = 4,
    parameter integer WR_DQ_OE_DELAY_SYS = 0,
    parameter integer WR_DQ_OE_HOLD_SYS = 4
) (
    input  wire                     i_clk_sys,
    input  wire                     i_clk_phy_x4,
    input  wire                     i_clk_dq,
    input  wire                     i_rst,

    input  wire                     i_wr_en,
    input  wire [DQ_BITS*RATIO-1:0] i_wr_data,
    input  wire                     i_wr_dqs_en,
    input  wire                     i_rd_capture,

    output wire [DQ_BITS*RATIO-1:0] o_rd_data,
    output wire                     o_rd_valid,
    output wire                     o_dqs_edge_event,

    input  wire                     i_cal_dq_load,
    input  wire [DQ_BITS-1:0]       i_cal_dq_sel,
    input  wire [4:0]               i_cal_dq_tap,

    input  wire                     i_cal_dqs_in_load,
    input  wire [4:0]               i_cal_dqs_in_tap,

    // DQS-out cal interface kept for source-compat — ignored on HR banks.
    input  wire                     i_cal_dqs_out_load,
    input  wire [4:0]               i_cal_dqs_out_tap,
    input  wire                     i_cal_dqs_toggle_en,

    inout  wire [DQ_BITS-1:0]       io_ddr3_dq,
    inout  wire                     io_ddr3_dqs_p,
    inout  wire                     io_ddr3_dqs_n,
    output wire                     o_ddr3_dm
);
    assign o_ddr3_dm = 1'b0;

`ifdef BONETTO_SOC_SIM
    assign io_ddr3_dq    = {DQ_BITS{1'bz}};
    assign io_ddr3_dqs_p = 1'bz;
    assign io_ddr3_dqs_n = 1'bz;
    assign o_rd_data     = {(DQ_BITS*RATIO){1'b0}};
    assign o_rd_valid    = 1'b0;
    assign o_dqs_edge_event = 1'b0;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_sys, i_clk_phy_x4, i_clk_dq, i_rst,
                i_wr_en, i_wr_data, i_wr_dqs_en, i_rd_capture,
                i_cal_dq_load, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_in_load, i_cal_dqs_in_tap,
                i_cal_dqs_out_load, i_cal_dqs_out_tap, i_cal_dqs_toggle_en,
                1'b0};
    /* verilator lint_on UNUSED */
`else
    localparam integer FULL_BL8_MODE = (RATIO >= 8);
`ifdef DDR3_RATIO8_ODDR_WR
    localparam integer USE_DQ_OSERDES = 0;
`else
    localparam integer USE_DQ_OSERDES = FULL_BL8_MODE;
`endif
`ifdef DDR3_RATIO8_ISERDES_RD
    localparam integer USE_ISERDES_RD = FULL_BL8_MODE;
`else
    localparam integer USE_ISERDES_RD = 0;
`endif

    // Board bring-up path. The legacy RATIO=4 mode keeps one stable DQ value
    // per bit for the validated narrow image. RATIO>=8 uses hard output
    // serialization for the eight BL8 DQ samples; DQS remains on the fixed
    // 90-degree clock because YPCB-00338 HR banks do not expose ODELAYE2.
    reg  [DQ_BITS-1:0] dq_rise_q;
    reg  [DQ_BITS-1:0] dq_fall_q;
    reg  [DQ_BITS*RATIO-1:0] wr_data_q;
    reg  [DQ_BITS*RATIO-1:0] wr_data_sys_q = {(DQ_BITS*RATIO){1'b0}};
    localparam integer WR_DQ_OE_PIPE_BITS =
        WR_DQ_OE_DELAY_SYS + WR_DQ_OE_HOLD_SYS;
    localparam integer WR_DQ_OE_WINDOW_START =
        (WR_DQ_OE_DELAY_SYS > 0) ? (WR_DQ_OE_DELAY_SYS - 1) : 0;
    localparam integer WR_DQ_OE_SHIFT_HOLD =
        (WR_DQ_OE_DELAY_SYS > 0) ? WR_DQ_OE_HOLD_SYS : (WR_DQ_OE_HOLD_SYS - 1);

    reg  [WR_DQ_OE_PIPE_BITS-1:0] wr_oe_sys_sr = {WR_DQ_OE_PIPE_BITS{1'b0}};
    wire [DQ_BITS-1:0] dq_out_ddr;
    wire [DQ_BITS-1:0] dq_in_raw;

    reg        wr_en_dq_q  = 1'b0;
    reg [WR_DQS_DELAY_CK:0] wr_start_sr = {(WR_DQS_DELAY_CK+1){1'b0}};
    reg [5:0]  dqs_seq_sr = 6'b000000;
    reg        dq_drive_q  = 1'b0;

    wire       wr_start_dq = i_wr_en && !wr_en_dq_q;
    wire       wr_delay_fire = wr_start_sr[WR_DQS_DELAY_CK];
    wire       dq_drive_en = dq_drive_q;
    wire [DQ_BITS-1:0] dq_t;
    wire       dqs_drive_window = |dqs_seq_sr;
    wire       dqs_burst = |dqs_seq_sr[4:1];
    wire       dqs_seq_done = dqs_seq_sr[5];
    wire       dq_drive_oserdes =
        ((WR_DQ_OE_DELAY_SYS == 0) ? i_wr_dqs_en : 1'b0) |
        (|wr_oe_sys_sr[WR_DQ_OE_WINDOW_START +: WR_DQ_OE_SHIFT_HOLD]);
    wire [DQ_BITS*RATIO-1:0] wr_data_oserdes = wr_data_sys_q;

    integer j;
    always @(posedge i_clk_sys or posedge i_rst) begin
        if (i_rst) begin
            wr_data_sys_q <= {(DQ_BITS*RATIO){1'b0}};
            wr_oe_sys_sr  <= {WR_DQ_OE_PIPE_BITS{1'b0}};
        end else begin
            if (i_wr_dqs_en)
                wr_data_sys_q <= i_wr_data;
            wr_oe_sys_sr <= {wr_oe_sys_sr[WR_DQ_OE_PIPE_BITS-2:0], i_wr_dqs_en};
        end
    end

    always @(posedge i_clk_dq or posedge i_rst) begin
        if (i_rst) begin
            dq_rise_q  <= {DQ_BITS{1'b0}};
            dq_fall_q  <= {DQ_BITS{1'b0}};
            wr_data_q  <= {(DQ_BITS*RATIO){1'b0}};
            wr_en_dq_q <= 1'b0;
            wr_start_sr <= {(WR_DQS_DELAY_CK+1){1'b0}};
            dqs_seq_sr <= 6'b000000;
            dq_drive_q  <= 1'b0;
        end else begin
            wr_en_dq_q <= i_wr_en;
            wr_start_sr <= {wr_start_sr[WR_DQS_DELAY_CK-1:0], wr_start_dq};
            if (wr_start_dq) begin
                dq_drive_q <= 1'b1;
                wr_data_q <= i_wr_data;
                for (j = 0; j < DQ_BITS; j = j + 1) begin
                    dq_rise_q[j] <= i_wr_data[j*RATIO + 0];
                    dq_fall_q[j] <= FULL_BL8_MODE ? i_wr_data[j*RATIO + 1] :
                                                     i_wr_data[j*RATIO + 0];
                end
            end

            if (wr_delay_fire) begin
                dqs_seq_sr <= 6'b000001;
                if (FULL_BL8_MODE) begin
                    for (j = 0; j < DQ_BITS; j = j + 1) begin
                        dq_rise_q[j] <= wr_data_q[j*RATIO + 0];
                        dq_fall_q[j] <= wr_data_q[j*RATIO + 1];
                    end
                end
            end else begin
                dqs_seq_sr <= {dqs_seq_sr[4:0], 1'b0};
            end
            if (FULL_BL8_MODE) begin
                if (dqs_seq_sr[1]) begin
                    for (j = 0; j < DQ_BITS; j = j + 1) begin
                        dq_rise_q[j] <= wr_data_q[j*RATIO + 2];
                        dq_fall_q[j] <= wr_data_q[j*RATIO + 3];
                    end
                end else if (dqs_seq_sr[2]) begin
                    for (j = 0; j < DQ_BITS; j = j + 1) begin
                        dq_rise_q[j] <= wr_data_q[j*RATIO + 4];
                        dq_fall_q[j] <= wr_data_q[j*RATIO + 5];
                    end
                end else if (dqs_seq_sr[3]) begin
                    for (j = 0; j < DQ_BITS; j = j + 1) begin
                        dq_rise_q[j] <= wr_data_q[j*RATIO + 6];
                        dq_fall_q[j] <= wr_data_q[j*RATIO + 7];
                    end
                end
            end
            if (dqs_seq_done)
                dq_drive_q <= 1'b0;
        end
    end

    genvar i;
    generate
        for (i = 0; i < DQ_BITS; i = i + 1) begin : g_dq
            if (USE_DQ_OSERDES) begin : g_dq_oserdes
                OSERDESE2 #(
                    .SERDES_MODE ("MASTER"),
                    .DATA_WIDTH  (8),
                    .TRISTATE_WIDTH(1),
                    .DATA_RATE_OQ("DDR"),
                    .DATA_RATE_TQ("BUF"),
                    .INIT_OQ     (1'b0),
                    .INIT_TQ     (1'b1),
                    .SRVAL_OQ    (1'b0),
                    .SRVAL_TQ    (1'b1)
                ) u_oserdes_dq (
                    .OFB       (),
                    .OQ        (dq_out_ddr[i]),
                    .SHIFTOUT1 (),
                    .SHIFTOUT2 (),
                    .TBYTEOUT  (),
                    .TFB       (),
                    .TQ        (dq_t[i]),
                    .CLK       (i_clk_phy_x4),
                    .CLKDIV    (i_clk_sys),
                    .D1        (wr_data_oserdes[i*RATIO + 0]),
                    .D2        (wr_data_oserdes[i*RATIO + 1]),
                    .D3        (wr_data_oserdes[i*RATIO + 2]),
                    .D4        (wr_data_oserdes[i*RATIO + 3]),
                    .D5        (wr_data_oserdes[i*RATIO + 4]),
                    .D6        (wr_data_oserdes[i*RATIO + 5]),
                    .D7        (wr_data_oserdes[i*RATIO + 6]),
                    .D8        (wr_data_oserdes[i*RATIO + 7]),
                    .OCE       (1'b1),
                    .RST       (i_rst),
                    .SHIFTIN1  (1'b0),
                    .SHIFTIN2  (1'b0),
                    .T1        (~dq_drive_oserdes),
                    .T2        (~dq_drive_oserdes),
                    .T3        (~dq_drive_oserdes),
                    .T4        (~dq_drive_oserdes),
                    .TBYTEIN   (1'b0),
                    .TCE       (1'b1)
                );
            end else begin : g_dq_oddr
                assign dq_t[i] = ~dq_drive_en;

                ODDR #(
                    .DDR_CLK_EDGE("SAME_EDGE"),
                    .INIT(1'b0),
                    .SRTYPE("SYNC")
                ) u_oddr_dq (
                    .Q  (dq_out_ddr[i]),
                    .C  (i_clk_dq),
                    .CE (1'b1),
                    .D1 (dq_rise_q[i]),
                    .D2 (dq_fall_q[i]),
                    .R  (i_rst),
                    .S  (1'b0)
                );
            end

            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O  (dq_in_raw[i]),
                .IO (io_ddr3_dq[i]),
                .I  (dq_out_ddr[i]),
                .T  (dq_t[i])
            );
        end
    endgenerate

    // ===========================================================
    // DQS — differential strobe per byte lane.
    // No ODELAYE2 (HR-bank-only constraint on YPCB-00338).
    // DQS-out timing is fixed at 90° from CK via clk_dq.
    // ===========================================================
    wire dqs_in_ibuf;
    wire dqs_in_raw;

    wire dqs_drive  = dqs_drive_window | i_cal_dqs_toggle_en;
    wire dqs_active = dqs_burst || i_cal_dqs_toggle_en;
    wire dqs_out;

    ODDR #(
        .DDR_CLK_EDGE("SAME_EDGE"),
        .INIT(1'b0),
        .SRTYPE("SYNC")
    ) u_oddr_dqs (
        .Q  (dqs_out),
        .C  (i_clk_dq),
        .CE (1'b1),
        .D1 (dqs_active),
        .D2 (1'b0),
        .R  (i_rst),
        .S  (1'b0)
    );

    IOBUFDS #(.SLEW("FAST")) u_dqs_iobuf (
        .O   (dqs_in_ibuf),
        .IO  (io_ddr3_dqs_p),
        .IOB (io_ddr3_dqs_n),
        .I   (dqs_out),
        .T   (~dqs_drive)
    );

    IDELAYE2 #(
        .CINVCTRL_SEL          ("FALSE"),
        .DELAY_SRC             ("IDATAIN"),
        .HIGH_PERFORMANCE_MODE ("TRUE"),
        .IDELAY_TYPE           ("VAR_LOAD"),
        .IDELAY_VALUE          (0),
        .PIPE_SEL              ("FALSE"),
        .REFCLK_FREQUENCY      (200.0),
        .SIGNAL_PATTERN        ("CLOCK")
    ) u_dqs_idelay (
        .CNTVALUEOUT (),
        .DATAOUT     (dqs_in_raw),
        .C           (i_clk_sys),
        .CE          (1'b0),
        .CINVCTRL    (1'b0),
        .CNTVALUEIN  (i_cal_dqs_in_tap),
        .DATAIN      (1'b0),
        .IDATAIN     (dqs_in_ibuf),
        .INC         (1'b0),
        .LD          (i_cal_dqs_in_load),
        .LDPIPEEN    (1'b0),
        .REGRST      (i_rst)
    );

    generate
        if (USE_ISERDES_RD) begin : g_read_iserdes
            wire [DQ_BITS*RATIO-1:0] rd_data_iserdes;
            wire                     rd_iserdes_clk;
            reg  [DQ_BITS*RATIO-1:0] rd_data_sys = {(DQ_BITS*RATIO){1'b0}};
            reg                      rd_capture_q = 1'b0;
            reg                      rd_valid_q = 1'b0;

`ifdef DDR3_RATIO8_ISERDES_BUFIO_RDCLK
            BUFIO u_rd_iserdes_bufio (
                .O (rd_iserdes_clk),
                .I (i_clk_phy_x4)
            );
`else
            assign rd_iserdes_clk = i_clk_phy_x4;
`endif

            for (i = 0; i < DQ_BITS; i = i + 1) begin : g_rd_iserdes_bit
                wire       dq_in_delayed;
                wire [7:0] dq_i_data;

                IDELAYE2 #(
                    .CINVCTRL_SEL          ("FALSE"),
                    .DELAY_SRC             ("IDATAIN"),
                    .HIGH_PERFORMANCE_MODE ("TRUE"),
                    .IDELAY_TYPE           ("VAR_LOAD"),
                    .IDELAY_VALUE          (0),
                    .PIPE_SEL              ("FALSE"),
                    .REFCLK_FREQUENCY      (200.0),
                    .SIGNAL_PATTERN        ("DATA")
                ) u_dq_idelay (
                    .CNTVALUEOUT (),
                    .DATAOUT     (dq_in_delayed),
                    .C           (i_clk_sys),
                    .CE          (1'b0),
                    .CINVCTRL    (1'b0),
                    .CNTVALUEIN  (i_cal_dq_tap),
                    .DATAIN      (1'b0),
                    .IDATAIN     (dq_in_raw[i]),
                    .INC         (1'b0),
                    .LD          (i_cal_dq_load & i_cal_dq_sel[i]),
                    .LDPIPEEN    (1'b0),
                    .REGRST      (i_rst)
                );

                ISERDESE2 #(
                    .SERDES_MODE   ("MASTER"),
                    .INTERFACE_TYPE("NETWORKING"),
                    .DATA_WIDTH    (8),
                    .DATA_RATE     ("DDR"),
                    .NUM_CE        (1),
                    .IOBDELAY      ("IFD"),
                    .IS_CLKB_INVERTED(1'b1),
                    .INIT_Q1       (1'b0),
                    .INIT_Q2       (1'b0),
                    .INIT_Q3       (1'b0),
                    .INIT_Q4       (1'b0),
                    .SRVAL_Q1      (1'b0),
                    .SRVAL_Q2      (1'b0),
                    .SRVAL_Q3      (1'b0),
                    .SRVAL_Q4      (1'b0)
                ) u_iserdes_dq (
                    .O          (),
                    .Q1         (dq_i_data[7]),
                    .Q2         (dq_i_data[6]),
                    .Q3         (dq_i_data[5]),
                    .Q4         (dq_i_data[4]),
                    .Q5         (dq_i_data[3]),
                    .Q6         (dq_i_data[2]),
                    .Q7         (dq_i_data[1]),
                    .Q8         (dq_i_data[0]),
                    .SHIFTOUT1  (),
                    .SHIFTOUT2  (),
                    .BITSLIP    (1'b0),
                    .CE1        (1'b1),
                    .CE2        (1'b1),
                    .CLK        (rd_iserdes_clk),
                    .CLKB       (rd_iserdes_clk),
                    .CLKDIV     (i_clk_sys),
                    .D          (1'b0),
                    .DDLY       (dq_in_delayed),
                    .DYNCLKDIVSEL(1'b0),
                    .DYNCLKSEL  (1'b0),
                    .OFB        (1'b0),
                    .RST        (i_rst),
                    .SHIFTIN1   (1'b0),
                    .SHIFTIN2   (1'b0)
                );

                assign rd_data_iserdes[i*RATIO +: RATIO] = dq_i_data;
            end

            always @(posedge i_clk_sys or posedge i_rst) begin
                if (i_rst) begin
                    rd_data_sys  <= {(DQ_BITS*RATIO){1'b0}};
                    rd_capture_q <= 1'b0;
                    rd_valid_q   <= 1'b0;
                end else begin
                    rd_capture_q <= i_rd_capture;
                    if (i_rd_capture && !rd_capture_q) begin
                        rd_data_sys <= {(DQ_BITS*RATIO){1'b0}};
                        rd_valid_q  <= 1'b0;
                    end else if (rd_capture_q && !i_rd_capture) begin
                        rd_data_sys <= rd_data_iserdes;
                        rd_valid_q  <= 1'b1;
                    end
                end
            end

            assign o_rd_data  = rd_data_sys;
            assign o_rd_valid = rd_valid_q;
            assign o_dqs_edge_event = 1'b0;
        end else begin : g_read_dqs
            reg [DQ_BITS*RATIO-1:0] rd_data_dqs = {(DQ_BITS*RATIO){1'b0}};
            reg [DQ_BITS*RATIO-1:0] rd_data_sys = {(DQ_BITS*RATIO){1'b0}};
            reg [DQ_BITS-1:0]       rd_tail_rise_dqs = {DQ_BITS{1'b0}};
            reg [DQ_BITS-1:0]       rd_tail_fall_dqs = {DQ_BITS{1'b0}};
            reg [7:0] dqs_edges_dqs = 8'd0;
            reg [7:0] dqs_edges_sys = 8'd0;
            reg       dqs_event_toggle = 1'b0;
            reg       dqs_first_edge_toggle = 1'b0;
            wire [DQ_BITS*RATIO-1:0] rd_data_complete;
            wire rd_iddr_ce;
            wire rd_dqs_sample_en;

            for (i = 0; i < DQ_BITS; i = i + 1) begin : g_rd_iddr
                wire rd_rise;
                wire rd_fall;

                if (FULL_BL8_MODE) begin : g_rd_complete_full
                    assign rd_data_complete[i*RATIO + 0] = rd_data_dqs[i*RATIO + 0];
                    assign rd_data_complete[i*RATIO + 1] = rd_data_dqs[i*RATIO + 1];
                    assign rd_data_complete[i*RATIO + 2] = rd_data_dqs[i*RATIO + 2];
                    assign rd_data_complete[i*RATIO + 3] = rd_data_dqs[i*RATIO + 3];
                    assign rd_data_complete[i*RATIO + 4] = rd_data_dqs[i*RATIO + 4];
                    assign rd_data_complete[i*RATIO + 5] = rd_data_dqs[i*RATIO + 5];
                    assign rd_data_complete[i*RATIO + 6] = rd_tail_rise_dqs[i];
                    assign rd_data_complete[i*RATIO + 7] = rd_tail_fall_dqs[i];

                    IDDR #(
                        .DDR_CLK_EDGE("SAME_EDGE"),
                        .INIT_Q1(1'b0),
                        .INIT_Q2(1'b0),
                        .SRTYPE("SYNC")
                    ) u_iddr_dq (
                        .Q1 (rd_rise),
                        .Q2 (rd_fall),
                        .C  (dqs_in_raw),
                        .CE (rd_iddr_ce),
                        .D  (dq_in_raw[i]),
                        .R  (1'b0),
                        .S  (1'b0)
                    );

                    always @(posedge dqs_in_raw) begin
                        if (rd_dqs_sample_en) begin
                            // IDDR outputs are visible to fabric one DQS rising edge
                            // after the corresponding input pair. Use IDDR for the
                            // first three pairs and sample only the final pair directly.
                            case (dqs_edges_dqs[2:0])
                                3'd1: begin
                                    rd_data_dqs[i*RATIO + 0] <= rd_rise;
                                    rd_data_dqs[i*RATIO + 1] <= rd_fall;
                                end
                                3'd2: begin
                                    rd_data_dqs[i*RATIO + 2] <= rd_rise;
                                    rd_data_dqs[i*RATIO + 3] <= rd_fall;
                                end
                                3'd3: begin
                                    rd_data_dqs[i*RATIO + 4] <= rd_rise;
                                    rd_data_dqs[i*RATIO + 5] <= rd_fall;
                                    rd_tail_rise_dqs[i]      <= dq_in_raw[i];
                                end
                                default: begin end
                            endcase
                        end
                    end

                    always @(negedge dqs_in_raw) begin
                        if (rd_dqs_sample_en) begin
                            if (dqs_edges_dqs[2:0] == 3'd4)
                                rd_tail_fall_dqs[i] <= dq_in_raw[i];
                        end
                    end
                end else begin : g_rd_complete_legacy
                    assign rd_data_complete[i*RATIO +: RATIO] =
                        rd_data_dqs[i*RATIO +: RATIO];

                    IDDR #(
                        .DDR_CLK_EDGE("SAME_EDGE"),
                        .INIT_Q1(1'b0),
                        .INIT_Q2(1'b0),
                        .SRTYPE("SYNC")
                    ) u_iddr_dq (
                        .Q1 (rd_rise),
                        .Q2 (rd_fall),
                        .C  (dqs_in_raw),
                        .CE (rd_iddr_ce),
                        .D  (dq_in_raw[i]),
                        .R  (i_rst),
                        .S  (1'b0)
                    );

                    always @(posedge dqs_in_raw or posedge i_rst) begin
                        if (i_rst) begin
                            rd_data_dqs[i*RATIO +: RATIO] <= {RATIO{1'b0}};
                        end else if (rd_dqs_sample_en) begin
                            rd_data_dqs[i*RATIO + 0] <= rd_rise;
                            rd_data_dqs[i*RATIO + 1] <= rd_fall;
                            rd_data_dqs[i*RATIO + 2] <= rd_rise;
                            rd_data_dqs[i*RATIO + 3] <= rd_fall;
                        end
                    end
                end
            end

            if (FULL_BL8_MODE) begin : g_full_bl8_dqs_arm
                reg  rd_arm_dqs = 1'b0;
                reg  dqs_first_edge_seen_dqs = 1'b0;
                wire rd_capture_dqs_en = i_rd_capture;

                assign rd_iddr_ce = 1'b1;
                assign rd_dqs_sample_en = rd_arm_dqs && !dqs_drive;

                always @(posedge dqs_in_raw or negedge rd_capture_dqs_en) begin
                    if (!rd_capture_dqs_en) begin
                        rd_arm_dqs <= 1'b0;
                        dqs_edges_dqs <= 8'd0;
                        dqs_first_edge_seen_dqs <= 1'b0;
                    end else if (!dqs_drive) begin
                        if (!dqs_first_edge_seen_dqs) begin
                            dqs_first_edge_seen_dqs <= 1'b1;
                            dqs_first_edge_toggle <= ~dqs_first_edge_toggle;
                        end
                        rd_arm_dqs <= 1'b1;
                        dqs_edges_dqs <= rd_arm_dqs ? (dqs_edges_dqs + 8'd1) : 8'd1;
                    end
                end

                always @(posedge dqs_in_raw) begin
                    if (rd_arm_dqs && !dqs_drive && (dqs_edges_dqs[2:0] == 3'd3)) begin
                        dqs_event_toggle <= ~dqs_event_toggle;
                    end
                end
            end else begin : g_legacy_dqs_arm
                reg dqs_first_edge_seen_dqs = 1'b0;

                assign rd_iddr_ce = i_rd_capture;
                assign rd_dqs_sample_en = i_rd_capture && !dqs_drive;

                always @(posedge dqs_in_raw or posedge i_rst or negedge i_rd_capture) begin
                    if (i_rst) begin
                        dqs_edges_dqs <= 8'd0;
                        dqs_first_edge_seen_dqs <= 1'b0;
                    end else if (!i_rd_capture) begin
                        dqs_edges_dqs <= 8'd0;
                        dqs_first_edge_seen_dqs <= 1'b0;
                    end else if (!dqs_drive) begin
                        if (!dqs_first_edge_seen_dqs) begin
                            dqs_first_edge_seen_dqs <= 1'b1;
                            dqs_first_edge_toggle <= ~dqs_first_edge_toggle;
                        end
                        dqs_edges_dqs <= dqs_edges_dqs + 8'd1;
                    end
                end

                always @(posedge dqs_in_raw or posedge i_rst) begin
                    if (i_rst) begin
                        dqs_event_toggle <= 1'b0;
                    end else if (i_rd_capture && !dqs_drive) begin
                        dqs_event_toggle <= ~dqs_event_toggle;
                    end
                end
            end

            reg       rd_capture_q = 1'b0;
            reg       rd_capture_qq = 1'b0;
            reg       rd_valid_q = 1'b0;
            reg       dqs_seen_q = 1'b0;
            reg [2:0] dqs_event_sync = 3'b000;
            reg [2:0] dqs_first_edge_sync = 3'b000;

            wire dqs_event_sys = dqs_event_sync[2] ^ dqs_event_sync[1];
            wire dqs_first_edge_sys =
                dqs_first_edge_sync[2] ^ dqs_first_edge_sync[1];
            wire rd_capture_start_sys = FULL_BL8_MODE ? (rd_capture_q && !rd_capture_qq) :
                                                         (i_rd_capture && !rd_capture_q);
            wire rd_capture_done_sys = FULL_BL8_MODE ? (!rd_capture_q && rd_capture_qq) :
                                                        !i_rd_capture;

            always @(posedge i_clk_sys or posedge i_rst) begin
                if (i_rst) begin
                    rd_data_sys    <= {(DQ_BITS*RATIO){1'b0}};
                    dqs_edges_sys  <= 8'd0;
                    rd_capture_q   <= 1'b0;
                    rd_capture_qq  <= 1'b0;
                    rd_valid_q     <= 1'b0;
                    dqs_seen_q     <= 1'b0;
                    dqs_event_sync <= 3'b000;
                    dqs_first_edge_sync <= 3'b000;
                end else begin
                    rd_capture_q   <= i_rd_capture;
                    rd_capture_qq  <= rd_capture_q;
                    dqs_event_sync <= {dqs_event_sync[1:0], dqs_event_toggle};
                    dqs_first_edge_sync <= {
                        dqs_first_edge_sync[1:0], dqs_first_edge_toggle
                    };
                    dqs_edges_sys  <= dqs_edges_dqs;

                    if (rd_capture_start_sys) begin
                        if (!FULL_BL8_MODE)
                            rd_data_sys <= {(DQ_BITS*RATIO){1'b0}};
                        rd_valid_q  <= 1'b0;
                        dqs_seen_q  <= 1'b0;
                    end else begin
                        if (FULL_BL8_MODE) begin
                            if (dqs_event_sys)
                                rd_data_sys <= rd_data_complete;
                        end else if (i_rd_capture || rd_capture_q || dqs_event_sys) begin
                            rd_data_sys <= rd_data_complete;
                        end

                        if (dqs_event_sys)
                            dqs_seen_q <= 1'b1;

                        if (rd_capture_done_sys && (dqs_seen_q || dqs_event_sys))
                            rd_valid_q <= 1'b1;
                    end
                end
            end

            assign o_rd_data  = rd_data_sys;
            assign o_rd_valid = rd_valid_q;
            assign o_dqs_edge_event = dqs_first_edge_sys;
        end
    endgenerate

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_phy_x4,
                i_wr_dqs_en, dqs_in_raw,
                i_cal_dq_load, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_in_load, i_cal_dqs_in_tap,
                i_cal_dqs_out_load, i_cal_dqs_out_tap, 1'b0};
    /* verilator lint_on UNUSED */
`endif
endmodule
