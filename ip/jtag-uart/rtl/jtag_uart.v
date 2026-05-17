// jtag_uart — BSCANE2-based JTAG bridge with host-driven status mux.
//
// Iter-3: the FPGA-to-host word now comes from a port input (i_fpga_to_host)
// rather than a WB-written register. Top.v drives this with a status mux
// selected by the host's last-written value (o_host_to_fpga). The host's
// access pattern becomes:
//   1. write (dir=1) a register index → updates o_host_to_fpga
//   2. read  (dir=0) → captures i_fpga_to_host into jtag_sr on Capture-DR
//
// This iter also fixes the CAPTURE bug from iter-2: previously BSCANE2.CAPTURE
// was unconnected and jtag_sr never reloaded from the FPGA side, so the host
// only ever saw stale junk. Now we load on Capture-DR every read.
//
// JTAG protocol: BSCANE2 USER1 chain (IR opcode 0x02 on Xilinx 7-series).
//   - Host issues USER1 IR.
//   - Then shifts a 33-bit DR:
//       [32]    direction:  0 = read (return current FPGA-side value)
//                           1 = write (latch shifted value on UPDATE)
//       [31:0]  data
//   - On CAPTURE-DR, FPGA loads {1'b0, i_fpga_to_host} into the shift reg.
//   - On UPDATE-DR with [32]==1, host's value latches into o_host_to_fpga.
//
// WB slave kept for backwards compat with the existing cocotb tests:
//   adr 0:
//     READ:  returns o_host_to_fpga
//     WRITE: stored in a sim-only scratch reg, no JTAG effect.

`default_nettype none

module jtag_uart #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 2,
    parameter integer USER_CHAIN = 1     // BSCANE2 JTAG_CHAIN (1..4)
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    // Wishbone slave (legacy / sim test path)
    input  wire                     i_wb_cyc,
    input  wire                     i_wb_stb,
    input  wire                     i_wb_we,
    input  wire [WB_ADDR_W-1:0]     i_wb_adr,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]   i_wb_sel,
    output wire                     o_wb_stall,
    output reg                      o_wb_ack,
    output reg  [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err,

    // Status mux interface (iter-3)
    input  wire [WB_DATA_W-1:0]     i_fpga_to_host,   // current status word (mux output)
    output wire [WB_DATA_W-1:0]     o_host_to_fpga,   // host's last-written value (mux select)

    // iter-7: pulse on every UPDATE-DR with dir=1 (i.e. each host-to-FPGA
    // write). Consumers (e.g. jtag_wb_master) edge-trigger commands from it.
    output wire                     o_host_to_fpga_valid
);
    // --- BSCANE2 USER1 chain --------------------------------------------------
    wire        bscan_tdi;
    wire        bscan_drck;
    wire        bscan_capture;
    wire        bscan_shift;
    wire        bscan_update;
    wire        bscan_sel;
    reg         bscan_tdo;

`ifdef BONETTO_SOC_SIM
    assign bscan_tdi     = 1'b0;
    assign bscan_drck    = 1'b0;
    assign bscan_capture = 1'b0;
    assign bscan_shift   = 1'b0;
    assign bscan_update  = 1'b0;
    assign bscan_sel     = 1'b0;
`else
    (* keep = "true" *) BSCANE2 #(
        .JTAG_CHAIN(USER_CHAIN)
    ) u_bscan (
        .TDI    (bscan_tdi),
        .TDO    (bscan_tdo),
        .DRCK   (bscan_drck),
        .CAPTURE(bscan_capture),
        .SHIFT  (bscan_shift),
        .UPDATE (bscan_update),
        .SEL    (bscan_sel),
        .RUNTEST(),
        .RESET  (),
        .TCK    (),
        .TMS    ()
    );
`endif

    // --- 33-bit shift register on JTAG side ----------------------------------
    // [32] direction (1=write, 0=read), [31:0] data. Shifted LSB-first per JTAG.
    reg [32:0] jtag_sr = 33'd0;

    // FPGA-side host_to_fpga reg, in i_clk domain. The host's most recent
    // 32-bit write — used by top.v as the status-mux select.
    (* keep = "true" *) reg [WB_DATA_W-1:0] host_to_fpga = 0;

    // Synchronise i_fpga_to_host into the JTAG TCK domain. We only need the
    // value to be stable around the CAPTURE pulse; a 2-FF synchroniser on the
    // bscan_drck domain handles the (rare) update-during-capture race.
    reg [WB_DATA_W-1:0] fpga_to_host_jtag_q1 = 0;
    reg [WB_DATA_W-1:0] fpga_to_host_jtag_q2 = 0;
    always @(posedge bscan_drck) begin
        fpga_to_host_jtag_q1 <= i_fpga_to_host;
        fpga_to_host_jtag_q2 <= fpga_to_host_jtag_q1;
    end

    // Capture-DR loads the FPGA-side value into the shift register so the
    // next SHIFT-DR cycles shift it out LSB-first to TDO. We tag the
    // direction bit (MSB) as 0 on read — it's a don't-care from the FPGA
    // side but keeps the JTAG DR length predictable.
    //
    // Shift-DR shifts TDI into MSB-1 down to LSB on TDO. We use right-shift
    // (LSB-first) consistent with the existing host script.
    always @(posedge bscan_drck) begin
        if (bscan_sel && bscan_capture) begin
            jtag_sr <= {1'b0, fpga_to_host_jtag_q2};
        end else if (bscan_sel && bscan_shift) begin
            jtag_sr <= {bscan_tdi, jtag_sr[32:1]};
        end
    end

    // TDO from shift-register LSB (right-shift output).
    always @(*) bscan_tdo = jtag_sr[0];

    // --- UPDATE event sync to i_clk -----------------------------------------
    reg update_sync1 = 1'b0, update_sync2 = 1'b0, update_sync3 = 1'b0;
    always @(posedge i_clk) begin
        update_sync1 <= bscan_update;
        update_sync2 <= update_sync1;
        update_sync3 <= update_sync2;
    end
    wire update_pulse = update_sync2 && !update_sync3;   // rising edge in i_clk

    // On UPDATE, if the JTAG word was a write, latch into host_to_fpga
    // and fire a single-cycle valid pulse for downstream command consumers.
    reg host_to_fpga_valid_r = 1'b0;
    always @(posedge i_clk) begin
        if (i_rst) begin
            host_to_fpga         <= 0;
            host_to_fpga_valid_r <= 1'b0;
        end else begin
            host_to_fpga_valid_r <= 1'b0;
            if (update_pulse && jtag_sr[32]) begin
                host_to_fpga         <= jtag_sr[31:0];
                host_to_fpga_valid_r <= 1'b1;
            end
        end
    end

    assign o_host_to_fpga       = host_to_fpga;
    assign o_host_to_fpga_valid = host_to_fpga_valid_r;

    // --- Wishbone B4 pipelined slave -----------------------------------------
    // WB write path is legacy/no-op (i_fpga_to_host now drives JTAG capture
    // directly). WB read returns host_to_fpga so existing sim tests pass.
    assign o_wb_stall = 1'b0;
    assign o_wb_err   = 1'b0;

    wire accept = i_wb_cyc && i_wb_stb && !o_wb_stall;

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_wb_ack <= 1'b0;
            o_wb_dat <= 0;
        end else begin
            o_wb_ack <= accept && i_wb_cyc;
            if (accept && !i_wb_we) o_wb_dat <= host_to_fpga;
            if (!i_wb_cyc) o_wb_ack <= 1'b0;
        end
    end

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_adr, i_wb_sel, i_wb_dat, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
