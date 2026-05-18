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
// DQS OUTPUT path: direct ODDR on clk_dq (no programmable delay).

`default_nettype none

module ddr3_phy_dq #(
    parameter integer DQ_BITS = 8,
    parameter integer RATIO   = 4,
    parameter integer WR_DQS_DELAY_CK = 4
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

    // Board bring-up path. The legacy RATIO=4 mode keeps one stable DQ value
    // per bit for the validated narrow image. RATIO>=8 uses hard output
    // serialization for the eight BL8 DQ samples; DQS remains on the fixed
    // 90-degree clock because YPCB-00338 HR banks do not expose ODELAYE2.
    reg  [DQ_BITS-1:0] dq_rise_q;
    reg  [DQ_BITS-1:0] dq_fall_q;
    reg  [DQ_BITS*RATIO-1:0] wr_data_q;
    reg  [DQ_BITS*RATIO-1:0] wr_data_sys_q = {(DQ_BITS*RATIO){1'b0}};
    reg  [2:0] wr_oe_sys_sr = 3'b000;
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
    wire       dq_drive_oserdes = i_wr_dqs_en | (|wr_oe_sys_sr);
    wire [DQ_BITS*RATIO-1:0] wr_data_oserdes = wr_data_sys_q;

    integer j;
    always @(posedge i_clk_sys or posedge i_rst) begin
        if (i_rst) begin
            wr_data_sys_q <= {(DQ_BITS*RATIO){1'b0}};
            wr_oe_sys_sr  <= 3'b000;
        end else begin
            if (i_wr_dqs_en)
                wr_data_sys_q <= i_wr_data;
            wr_oe_sys_sr <= {wr_oe_sys_sr[1:0], i_wr_dqs_en};
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
        .O   (dqs_in_raw),
        .IO  (io_ddr3_dqs_p),
        .IOB (io_ddr3_dqs_n),
        .I   (dqs_out),
        .T   (~dqs_drive)
    );

    reg [DQ_BITS*RATIO-1:0] rd_data_dqs = {(DQ_BITS*RATIO){1'b0}};
    reg [DQ_BITS*RATIO-1:0] rd_data_sys = {(DQ_BITS*RATIO){1'b0}};
    reg [7:0] dqs_edges_dqs = 8'd0;
    reg [7:0] dqs_edges_sys = 8'd0;
    reg       dqs_event_toggle = 1'b0;
    wire [DQ_BITS*RATIO-1:0] rd_data_complete;

    generate
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
                assign rd_data_complete[i*RATIO + 6] = rd_rise;
                assign rd_data_complete[i*RATIO + 7] = rd_fall;
            end else begin : g_rd_complete_legacy
                assign rd_data_complete[i*RATIO +: RATIO] =
                    rd_data_dqs[i*RATIO +: RATIO];
            end

            IDDR #(
                .DDR_CLK_EDGE("SAME_EDGE"),
                .INIT_Q1(1'b0),
                .INIT_Q2(1'b0),
                .SRTYPE("SYNC")
            ) u_iddr_dq (
                .Q1 (rd_rise),
                .Q2 (rd_fall),
                .C  (dqs_in_raw),
                .CE (i_rd_capture),
                .D  (dq_in_raw[i]),
                .R  (i_rst),
                .S  (1'b0)
            );

            always @(posedge dqs_in_raw or posedge i_rst) begin
                if (i_rst) begin
                    rd_data_dqs[i*RATIO +: RATIO] <= {RATIO{1'b0}};
                end else if (i_rd_capture && !dqs_drive) begin
                    if (FULL_BL8_MODE) begin
                        case (dqs_edges_dqs[1:0])
                            2'd1: begin
                                rd_data_dqs[i*RATIO + 0] <= rd_rise;
                                rd_data_dqs[i*RATIO + 1] <= rd_fall;
                            end
                            2'd2: begin
                                rd_data_dqs[i*RATIO + 2] <= rd_rise;
                                rd_data_dqs[i*RATIO + 3] <= rd_fall;
                            end
                            2'd3: begin
                                rd_data_dqs[i*RATIO + 4] <= rd_rise;
                                rd_data_dqs[i*RATIO + 5] <= rd_fall;
                            end
                            default: begin end
                        endcase
                    end else begin
                        rd_data_dqs[i*RATIO + 0] <= rd_rise;
                        rd_data_dqs[i*RATIO + 1] <= rd_fall;
                        rd_data_dqs[i*RATIO + 2] <= rd_rise;
                        rd_data_dqs[i*RATIO + 3] <= rd_fall;
                    end
                end
            end
        end
    endgenerate

    reg       rd_capture_q = 1'b0;
    reg       rd_valid_q = 1'b0;
    reg       dqs_seen_q = 1'b0;
    reg [2:0] dqs_event_sync = 3'b000;

    wire dqs_event_sys = dqs_event_sync[2] ^ dqs_event_sync[1];

    always @(posedge i_clk_sys or posedge i_rst) begin
        if (i_rst) begin
            rd_data_sys    <= {(DQ_BITS*RATIO){1'b0}};
            dqs_edges_sys  <= 8'd0;
            rd_capture_q   <= 1'b0;
            rd_valid_q     <= 1'b0;
            dqs_seen_q     <= 1'b0;
            dqs_event_sync <= 3'b000;
        end else begin
            rd_capture_q   <= i_rd_capture;
            dqs_event_sync <= {dqs_event_sync[1:0], dqs_event_toggle};
            dqs_edges_sys  <= dqs_edges_dqs;

            if (i_rd_capture && !rd_capture_q) begin
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

                if (!i_rd_capture && (dqs_seen_q || dqs_event_sys))
                    rd_valid_q <= 1'b1;
            end
        end
    end

    always @(posedge dqs_in_raw or posedge i_rst or negedge i_rd_capture) begin
        if (i_rst) begin
            dqs_edges_dqs <= 8'd0;
        end else if (!i_rd_capture) begin
            dqs_edges_dqs <= 8'd0;
        end else if (!dqs_drive) begin
            dqs_edges_dqs <= dqs_edges_dqs + 8'd1;
        end
    end

    always @(posedge dqs_in_raw or posedge i_rst) begin
        if (i_rst) begin
            dqs_event_toggle <= 1'b0;
        end else if (i_rd_capture && !dqs_drive &&
                     (!FULL_BL8_MODE || (dqs_edges_dqs[1:0] == 2'd3))) begin
            dqs_event_toggle <= ~dqs_event_toggle;
        end
    end

    assign o_rd_data  = rd_data_sys;
    assign o_rd_valid = rd_valid_q;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_phy_x4,
                i_wr_dqs_en, dqs_edges_sys,
                i_cal_dq_load, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_in_load, i_cal_dqs_in_tap,
                i_cal_dqs_out_load, i_cal_dqs_out_tap, 1'b0};
    /* verilator lint_on UNUSED */
`endif
endmodule
