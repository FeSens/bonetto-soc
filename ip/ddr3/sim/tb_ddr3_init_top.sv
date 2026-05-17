// tb_ddr3_init_top.sv — SystemVerilog top wiring ddr3_ctrl to the
// Micron MT41K behavioural model. The C++ harness (tb_ddr3_init.cpp
// for ctrl-only, tb_ddr3_init_micron.cpp for the full integration)
// instantiates this and just ticks the clock.
//
// Pins:
//   - ck / ck_n: differential clock (we drive ck = clk_phy, ck_n = ~clk_phy)
//   - cs_n / ras_n / cas_n / we_n / ba / addr / cke / odt / rst_n:
//     direct from ddr3_ctrl
//   - dq / dqs / dqs_n / dm_tdqs: inout, left floating during init
//
// `define MICRON_TOP enables the Micron model. Without it, this tb
// runs ddr3_ctrl standalone (matches the iter-2 cycle-only sim).

`default_nettype none

`timescale 1ps / 1ps

module tb_ddr3_init_top (
    output wire done_or_err     // pulses high when sim should stop
);
    // ------------------------------------------------------------------
    // Clock generation — must use real #delays so the Micron model's
    // timing checks see proper inter-edge spacing.
    // tCK = 1250 ps for DDR3-1600.
    // ------------------------------------------------------------------
    reg clk_phy = 0;
    always #625 clk_phy = ~clk_phy;  // 625 ps half-period -> 1250 ps period

    // The SoC clock (i_clk) is 50 MHz on the YPCB-00338 = 20 ns period.
    // For sim we run it at the same rate as clk_phy (cycle-precise init
    // doesn't depend on clk vs clk_phy ratio — iter-3 introduces an MMCM).
    wire clk_50 = clk_phy;

    // Reset: hold high for 16 cycles (20 ns), then drop. Numbers are
    // in picoseconds now (timescale 1ps/1ps).
    reg rst = 1;
    initial begin
        #20000 rst = 0;        // release after 20 ns = 16 tCK
    end
    // -------- ddr3_ctrl + Micron model wiring --------
    localparam integer ROW_BITS  = 15;
    localparam integer BANK_BITS = 3;
    localparam integer DQ_BITS   = 8;
    localparam integer DM_BITS   = DQ_BITS / 8;
    localparam integer DQS_BITS  = DQ_BITS / 8;
    localparam integer ADDR_BITS = 16;  // Micron model uses 16, we use 15

    wire                       reset_n;
    wire                       cke;
    wire                       odt;
    wire                       cs_n, ras_n, cas_n, we_n;
    wire [BANK_BITS-1:0]       ba;
    wire [ROW_BITS-1:0]        addr;

    wire                       init_done;
    wire                       init_error;
    wire [3:0]                 init_error_code;
    wire [4:0]                 init_state;

    // iter-8 MR3-rewrite handshake between cal_seq and ddr3_ctrl.
    wire                       mrs_req;
    wire [BANK_BITS-1:0]       mrs_ba;
    wire [ROW_BITS-1:0]        mrs_addr;
    wire                       mrs_busy;

    // cal_seq status (mainly cal_done for the testbench).
    wire                       cal_done;
    wire                       cal_error;
    wire [1:0]                 cal_error_code;
    wire [3:0]                 cal_seq_state;
    wire                       wlvl_start, rdlvl_start;

    ddr3_ctrl #(
        .WB_DATA_W (32),
        .WB_ADDR_W (28),
        .ROW_BITS  (ROW_BITS),
        .BANK_BITS (BANK_BITS),
        .COL_BITS  (10),
        .DQ_BITS   (DQ_BITS)
    ) u_dut (
        .i_clk      (clk_50),
        .i_clk_phy  (clk_phy),
        .i_rst      (rst),
        // WB tied off — sim watches init only.
        .i_wb_cyc   (1'b0),
        .i_wb_stb   (1'b0),
        .i_wb_we    (1'b0),
        .i_wb_adr   (28'd0),
        .i_wb_dat   (32'd0),
        .i_wb_sel   (4'd0),
        .o_wb_stall (),
        .o_wb_ack   (),
        .o_wb_dat   (),
        .o_wb_err   (),
        // DDR3 pins
        .o_ddr3_reset_n (reset_n),
        .o_ddr3_cke     (cke),
        .o_ddr3_odt     (odt),
        .o_ddr3_cs_n    (cs_n),
        .o_ddr3_ras_n   (ras_n),
        .o_ddr3_cas_n   (cas_n),
        .o_ddr3_we_n    (we_n),
        .o_ddr3_ba      (ba),
        .o_ddr3_addr    (addr),
        .i_phy_rd_data   (288'd0),
        .i_phy_rd_valid  (1'b1),
        .o_phy_wr_data   (),
        .o_phy_wr_valid  (),
        .o_phy_rd_capture(),
        // MPR-req tied off — we don't drive MPR reads from this tb.
        .i_mpr_req   (1'b0),
        .i_mpr_addr  (13'd0),
        .o_mpr_busy  (),
        // MRS-rewrite from cal_seq.
        .i_mrs_req   (mrs_req),
        .i_mrs_ba    (mrs_ba),
        .i_mrs_addr  (mrs_addr),
        .o_mrs_busy  (mrs_busy),
        // Status
        .o_init_done       (init_done),
        .o_init_error      (init_error),
        .o_init_error_code (init_error_code),
        .o_init_state      (init_state)
    );

    ddr3_cal_seq #(.SKIP_WLVL(1), .SKIP_RDLVL(1)) u_cal_seq (
        .i_clk            (clk_50),
        .i_rst            (rst),
        .i_init_done      (init_done),
        .o_wlvl_start     (wlvl_start),
        .i_wlvl_done      (1'b0),
        .i_wlvl_error     (1'b0),
        .o_rdlvl_start    (rdlvl_start),
        .i_rdlvl_done     (1'b0),
        .i_rdlvl_error    (1'b0),
        .o_mrs_req        (mrs_req),
        .o_mrs_ba         (mrs_ba),
        .o_mrs_addr       (mrs_addr),
        .i_mrs_busy       (mrs_busy),
        .o_cal_done       (cal_done),
        .o_cal_error      (cal_error),
        .o_cal_error_code (cal_error_code),
        .o_state          (cal_seq_state)
    );

`ifdef WITH_MICRON
    // Micron model needs a 16-bit addr; pad our 15-bit with a 0.
    wire [ADDR_BITS-1:0] addr_padded = {1'b0, addr};

    // ck_n = inverted ck for differential clock.
    wire ck_n = ~clk_phy;

    // DQ / DQS / DM unused during init (no read/write). Wire them as
    // dangling inout nets; Verilator will warn-but-not-error if we
    // suppress the lint.
    wire [DQ_BITS-1:0]  dq;
    wire [DQS_BITS-1:0] dqs;
    wire [DQS_BITS-1:0] dqs_n;
    wire [DM_BITS-1:0]  dm_tdqs;
    wire [DQS_BITS-1:0] tdqs_n;

    // Pull-up resistors that DDR3 chips expect on the bus during init.
    // Without them, Verilator x-propagates undriven nets and the Micron
    // model trips checks that aren't actually violated by our controller.
    pullup p_dq[DQ_BITS-1:0]   (dq);
    pullup p_dqs[DQS_BITS-1:0] (dqs);

    ddr3 u_micron (
        .rst_n  (reset_n),
        .ck     (clk_phy),
        .ck_n   (ck_n),
        .cke    (cke),
        .cs_n   (cs_n),
        .ras_n  (ras_n),
        .cas_n  (cas_n),
        .we_n   (we_n),
        .dm_tdqs(dm_tdqs),
        .ba     (ba),
        .addr   (addr_padded),
        .dq     (dq),
        .dqs    (dqs),
        .dqs_n  (dqs_n),
        .tdqs_n (tdqs_n),
        .odt    (odt)
    );
`endif

    // ------------------------------------------------------------------
    // Sim stop condition: trip done_or_err when init completes / fails,
    // OR after a hard cap (1 ms simulated time).
    // ------------------------------------------------------------------
    // Sim completes when cal_done fires (after init_done) OR any error.
    assign done_or_err = cal_done | init_error | cal_error;

    initial begin
        // Hard timeout in ps. Full init takes ~700 µs (tRESET + tCKE_LOW
        // + MR programming + ZQinit + tDLLK + tRP + tRFC). Cap at 800 µs
        // to give a safety margin.
        #800_000_000 $display("[tb] timeout reached at 800 us sim time");
        $finish;
    end

    // Per-state debug print so we see init progress in stdout.
    reg [4:0] prev_state = 5'h1F;
    integer   tick = 0;
    always @(posedge clk_phy) begin
        if (init_state != prev_state) begin
            $display("[tb] t=%0t  state=%0d (tick=%0d)", $time, init_state, tick);
            prev_state <= init_state;
        end
        tick <= tick + 1;
        // Heartbeat every 50,000 cycles so we know sim is alive.
        if (tick % 50000 == 0)
            $display("[tb] heartbeat tick=%0d  t=%0t  state=%0d  rst=%b",
                     tick, $time, init_state, rst);
    end

    initial begin
        @(posedge init_done);
        $display("[tb] *** init_done asserted at time %0t ps ***", $time);
    end

    initial begin
        @(posedge cal_done);
        $display("[tb] *** cal_done asserted at time %0t ps ***", $time);
        $display("[tb] cal_seq_state=%0d cal_error=%0b code=%0d",
                 cal_seq_state, cal_error, cal_error_code);
        #100 $finish;
    end

    initial begin
        @(posedge init_error);
        $display("[tb] *** init_error asserted, code=%0d ***", init_error_code);
        #100 $finish;
    end

    initial begin
        @(posedge cal_error);
        $display("[tb] *** cal_error asserted, code=%0d ***", cal_error_code);
        #100 $finish;
    end
endmodule
