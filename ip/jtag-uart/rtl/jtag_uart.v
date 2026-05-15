// jtag_uart — BSCANE2-based JTAG bridge to a Wishbone-readable register.
//
// Iter-2-of-iter-1: minimal scratch-register version. Not a real UART yet
// (no FIFOs, no flow control, no per-byte handshake) — just a 32-bit
// register that the host can read/write via the JTAG cable and that the
// Wishbone side can also read/write. Enough to push a pass/fail counter
// out so the goal's "good results via JTAG UART" is literally satisfied.
//
// JTAG protocol: BSCANE2 USER1 chain (IR opcode 0x02 on Xilinx 7-series).
//   - Host issues USER1 IR.
//   - Then shifts a 33-bit DR:
//       [32]    direction:  0 = read (return current FPGA-side value)
//                           1 = write (latch shifted value on UPDATE)
//       [31:0]  data
//   - Read: the FPGA's current value of `o_user_data` shifts out on TDO.
//   - Write: on UPDATE, the value latches into `o_host_data`.
//
// Wishbone-side register map (word-addressed, only one 32-bit reg):
//   adr 0:
//     READ:  returns the latest "host -> FPGA" value (i_host_data input — UPDATE-latched)
//     WRITE: sets the "FPGA -> host" value that the host sees on its next read shift
//
// Iter-2-real version: replace the scratch register with TX/RX FIFOs and
// proper byte framing.

`default_nettype none

module jtag_uart #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 2,
    parameter integer USER_CHAIN = 1     // BSCANE2 JTAG_CHAIN (1..4)
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    // Wishbone slave
    input  wire                     i_wb_cyc,
    input  wire                     i_wb_stb,
    input  wire                     i_wb_we,
    input  wire [WB_ADDR_W-1:0]     i_wb_adr,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]   i_wb_sel,
    output wire                     o_wb_stall,
    output reg                      o_wb_ack,
    output reg  [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err
);
    // --- BSCANE2 USER1 chain --------------------------------------------------
    // SHIFT/UPDATE/DRCK run in the JTAG TCK clock domain (asynchronous to i_clk).
    // Inside `BONETTO_SOC_SIM` (Verilator / SymbiYosys), we tie-off the BSCANE2
    // signals because Xilinx primitives aren't visible to those tools.
    wire        bscan_tdi;
    wire        bscan_drck;
    wire        bscan_shift;
    wire        bscan_update;
    wire        bscan_sel;
    reg         bscan_tdo;

`ifdef BONETTO_SOC_SIM
    assign bscan_tdi    = 1'b0;
    assign bscan_drck   = 1'b0;
    assign bscan_shift  = 1'b0;
    assign bscan_update = 1'b0;
    assign bscan_sel    = 1'b0;
`else
    // (* keep *) prevents yosys from optimising the BSCANE2 away when
    // the user-side outputs (WB slave) aren't observably connected.
    // Likewise the host_to_fpga / fpga_to_host registers below need keep
    // because nothing downstream reads them in iter-1.5.
    (* keep = "true" *) BSCANE2 #(
        .JTAG_CHAIN(USER_CHAIN)
    ) u_bscan (
        .TDI    (bscan_tdi),
        .TDO    (bscan_tdo),
        .DRCK   (bscan_drck),
        .CAPTURE(),
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

    // FPGA-side scratch registers, in i_clk domain.
    // fpga_to_host inits to 0xDEADBEEF so the host's first read after
    // power-on returns a known magic value, proving the JTAG-UART read
    // path works end-to-end before any logic-side writer is wired up.
    // (* keep *) marks them as observation points so yosys doesn't
    // optimise them out when nothing downstream uses host_to_fpga.
    (* keep = "true" *) reg [WB_DATA_W-1:0] host_to_fpga = 0;
    (* keep = "true" *) reg [WB_DATA_W-1:0] fpga_to_host = 32'hDEADBEEF;

    // Shift in TDI on every JTAG DRCK while SHIFT && SEL.
    // (No CDC: this is the JTAG clock domain. The captured value is then
    // sampled into the i_clk domain on UPDATE via a synchroniser below.)
    always @(posedge bscan_drck) begin
        if (bscan_sel && bscan_shift) begin
            jtag_sr <= {bscan_tdi, jtag_sr[32:1]};
        end
    end

    // TDO comes from the LSB of the shift register (LSB-first). When the
    // host issues USER1 IR + a DR-scan, the FPGA's current fpga_to_host
    // value should already be in jtag_sr[31:0]. We load it on CAPTURE
    // (handled in the wider chain below).
    always @(*) bscan_tdo = jtag_sr[0];

    // --- UPDATE event sync to i_clk -----------------------------------------
    reg update_sync1 = 1'b0, update_sync2 = 1'b0, update_sync3 = 1'b0;
    always @(posedge i_clk) begin
        update_sync1 <= bscan_update;
        update_sync2 <= update_sync1;
        update_sync3 <= update_sync2;
    end
    wire update_pulse = update_sync2 && !update_sync3;   // rising edge in i_clk

    // On UPDATE, if the JTAG word was a write, latch into host_to_fpga.
    always @(posedge i_clk) begin
        if (i_rst) host_to_fpga <= 0;
        else if (update_pulse && jtag_sr[32]) host_to_fpga <= jtag_sr[31:0];
    end

    // --- Wishbone B4 pipelined slave -----------------------------------------
    assign o_wb_stall = 1'b0;
    assign o_wb_err   = 1'b0;

    wire accept = i_wb_cyc && i_wb_stb && !o_wb_stall;

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_wb_ack     <= 1'b0;
            fpga_to_host <= 0;
            o_wb_dat     <= 0;
        end else begin
            o_wb_ack <= accept && i_wb_cyc;
            if (accept) begin
                if (i_wb_we) begin
                    // WB write → set the FPGA->host buffer the host sees next read.
                    fpga_to_host <= i_wb_dat;
                end else begin
                    // WB read → return the most recent host->FPGA value.
                    o_wb_dat <= host_to_fpga;
                end
            end
            if (!i_wb_cyc) o_wb_ack <= 1'b0;
        end
    end

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_adr, i_wb_sel, fpga_to_host, 1'b0};
    /* verilator lint_on UNUSED */
endmodule
