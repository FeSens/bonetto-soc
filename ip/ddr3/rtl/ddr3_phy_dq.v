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
// DQ OUTPUT path: direct from OSERDESE2 (no delay).
// DQS OUTPUT path: direct from OSERDESE2 on clk_dq (no programmable delay).

`default_nettype none

module ddr3_phy_dq #(
    parameter integer DQ_BITS = 8,
    parameter integer RATIO   = 4
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
    // Board bring-up path: avoid OSERDES/ISERDES clocking until the PHY has
    // per-bank BUFIO/BUFR resources. Runtime writes currently repeat each DQ
    // bit across the whole BL8 beat group, so a stable DQ level plus gated DQS
    // is sufficient for the 32-bit hardware validation path.
    reg  [DQ_BITS-1:0] dq_out_q;
    wire [DQ_BITS-1:0] dq_out_ddr;
    wire [DQ_BITS-1:0] dq_in_raw;

    localparam [2:0]
        WR_IDLE   = 3'd0,
        WR_PRE    = 3'd1,
        WR_BURST0 = 3'd2,
        WR_BURST1 = 3'd3,
        WR_POST   = 3'd4;

    reg [2:0] wr_phase = WR_IDLE;
    reg       wr_en_q  = 1'b0;
    wire      wr_start = i_wr_en && !wr_en_q;
    wire      dq_drive_en = (wr_phase != WR_IDLE);

    integer j;
    always @(posedge i_clk_sys or posedge i_rst) begin
        if (i_rst) begin
            dq_out_q <= {DQ_BITS{1'b0}};
            wr_phase <= WR_IDLE;
            wr_en_q  <= 1'b0;
        end else begin
            wr_en_q <= i_wr_en;
            if (wr_start) begin
                wr_phase <= WR_PRE;
            end else begin
                case (wr_phase)
                    WR_PRE:    wr_phase <= WR_BURST0;
                    WR_BURST0: wr_phase <= WR_BURST1;
                    WR_BURST1: wr_phase <= WR_POST;
                    WR_POST:   wr_phase <= WR_IDLE;
                    default:   wr_phase <= WR_IDLE;
                endcase
            end

            if (wr_start) begin
                for (j = 0; j < DQ_BITS; j = j + 1)
                    dq_out_q[j] <= i_wr_data[j*RATIO];
            end
        end
    end

    genvar i;
    generate
        for (i = 0; i < DQ_BITS; i = i + 1) begin : g_dq
            ODDR #(
                .DDR_CLK_EDGE("SAME_EDGE"),
                .INIT(1'b0),
                .SRTYPE("SYNC")
            ) u_oddr_dq (
                .Q  (dq_out_ddr[i]),
                .C  (i_clk_dq),
                .CE (1'b1),
                .D1 (dq_out_q[i]),
                .D2 (dq_out_q[i]),
                .R  (i_rst),
                .S  (1'b0)
            );

            IOBUF #(.SLEW("FAST")) u_dq_iobuf (
                .O  (dq_in_raw[i]),
                .IO (io_ddr3_dq[i]),
                .I  (dq_out_ddr[i]),
                .T  (~dq_drive_en)
            );
        end
    endgenerate

    // ===========================================================
    // DQS — differential strobe per byte lane.
    // No ODELAYE2 (HR-bank-only constraint on YPCB-00338).
    // DQS-out timing is fixed at 90° from CK via clk_dq.
    // ===========================================================
    wire dqs_in_raw;

    wire dqs_burst  = (wr_phase == WR_BURST0) || (wr_phase == WR_BURST1);
    wire dqs_drive  = dq_drive_en | i_cal_dqs_toggle_en;
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

    wire [DQ_BITS*RATIO-1:0] rd_data_dqs;
    reg [DQ_BITS*RATIO-1:0] rd_data_sys = {(DQ_BITS*RATIO){1'b0}};
    reg [7:0] dqs_edges_dqs = 8'd0;
    reg [7:0] dqs_edges_sys = 8'd0;
    reg       dqs_event_toggle = 1'b0;

    generate
        for (i = 0; i < DQ_BITS; i = i + 1) begin : g_rd_iddr
            wire rd_rise;
            wire rd_fall;

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

            assign rd_data_dqs[i*RATIO + 0] = rd_rise;
            assign rd_data_dqs[i*RATIO + 1] = rd_fall;
            assign rd_data_dqs[i*RATIO + 2] = rd_rise;
            assign rd_data_dqs[i*RATIO + 3] = rd_fall;
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
                if (i_rd_capture || rd_capture_q || dqs_event_sys)
                    rd_data_sys <= rd_data_dqs;

                if (dqs_event_sys)
                    dqs_seen_q <= 1'b1;

                if (!i_rd_capture && (dqs_seen_q || dqs_event_sys))
                    rd_valid_q <= 1'b1;
            end
        end
    end

    always @(posedge dqs_in_raw or posedge i_rst) begin
        if (i_rst) begin
            dqs_edges_dqs    <= 8'd0;
            dqs_event_toggle <= 1'b0;
        end else if (i_rd_capture && !dqs_drive) begin
            dqs_edges_dqs    <= dqs_edges_dqs + 8'd1;
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
