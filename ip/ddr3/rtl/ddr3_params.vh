// ddr3_params.vh — JEDEC DDR3 timing parameters, per part.
//
// One `ifdef block per part. Select the active part with one of:
//   `define DDR3_PART_MT41K256M8DA_125    // 2 Gb, x8, DDR3-1600 -125 (YPCB-00338)
//   `define DDR3_PART_MT41K512M8DA_125    // 4 Gb, x8, DDR3-1600 -125
//   ... (add more here)
//
// All timing parameters are in **clock cycles of the DDR3 clock**
// (`tCK = 1/clk_phy`). Per INVARIANTS #6, every value here is enforced
// by formal cover/assertion in `ip/ddr3/formal/`.

`ifndef DDR3_PARAMS_VH
`define DDR3_PARAMS_VH

// Default to the YPCB-00338 part if no specific part was selected.
`ifndef DDR3_PART_MT41K256M8DA_125
  `ifndef DDR3_PART_MT41K512M8DA_125
    `define DDR3_PART_MT41K256M8DA_125
  `endif
`endif

// =============================================================================
// Common DDR3 architectural constants (every JEDEC-compliant DDR3 part)
// =============================================================================

`define DDR3_BANK_BITS_DEFAULT  3        // 8 banks
`define DDR3_BL                 8        // burst length (always BL8 here)
`define DDR3_NMRS               4        // MR0..MR3

// Mode-register opcodes (BA[2:0])
`define DDR3_MR0_BA             3'd0
`define DDR3_MR1_BA             3'd1
`define DDR3_MR2_BA             3'd2
`define DDR3_MR3_BA             3'd3


// =============================================================================
// MT41K256M8DA-125 — 2 Gb, x8. Current PHY bring-up point is DDR3-800
// (400 MHz CK, 800 MT/s), which keeps tCK within the DDR3 DLL-on max.
// =============================================================================
`ifdef DDR3_PART_MT41K256M8DA_125

  // Geometry
  `define DDR3_BANK_BITS  3
  `define DDR3_ROW_BITS   15            // 32 K rows
  `define DDR3_COL_BITS   10            // 1 K columns
  `define DDR3_DQ_BITS    8             // per chip

  // Clock period in picoseconds — used by host-side tools, not RTL directly.
  `define DDR3_TCK_PS     2500          // 2.5 ns = 400 MHz DDR clock = 800 MT/s
  `define DDR3_CK_PER_SYS 4             // LiteDRAM-style 1:4 fabric-to-CK ratio

  // Latencies (in tCK)
  `define DDR3_CL         6
  `define DDR3_CWL        5
  `define DDR3_AL         0             // additive latency disabled

  // Core timing (in tCK, JEDEC max(n_tCK, n_ns/tCK) ceiling-rounded)
  `define DDR3_TRCD       6             // 13.75 ns
  `define DDR3_TRP        6             // 13.75 ns
  `define DDR3_TRAS_MIN   14            // 35 ns
  `define DDR3_TRC        20            // 48.75 ns
  `define DDR3_TRFC       64            // 160 ns (2 Gb part)
  `define DDR3_TREFI      3120          // 7.8 us avg at <=85 C
  `define DDR3_TWR        6             // 15 ns
  `define DDR3_TWTR       4             // max(4 tCK, 7.5 ns)
  `define DDR3_TRTP       4             // max(4 tCK, 7.5 ns)
  `define DDR3_TRRD       4             // 10 ns conservative low-speed bin
  `define DDR3_TFAW       16            // 40 ns (8-bank)
  `define DDR3_TCCD       4
  `define DDR3_TMOD       12            // 15 ns
  `define DDR3_TMRD       4
  `define DDR3_TDLLK      512
  `define DDR3_TZQINIT    512
  `define DDR3_TXPR       68            // max(5 tCK, tRFC + 10 ns)

  // Power-on init timings (in tCK — for our 2.5 ns tCK, 1 us = 400 cycles)
  `define DDR3_TRESET_TCK     80000     // 200 us minimum
  `define DDR3_TCKE_LOW_TCK   200000    // 500 us CKE-low

  // ----- Mode register encodings -----
  // MR0 (BA=000):
  //   A[1:0]   BL       = 00     (BL=8 fixed)
  //   A[3]     BT       = 0      (sequential burst)
  //   A[6:4,2] CL field = 010_0  (CL=6)
  //   A[7]     TM       = 0      (normal mode)
  //   A[8]     DLL_RST  = 1      (reset DLL on init)
  //   A[11:9]  WR       = 010    (WR=6)
  //   A[12]    PD       = 0      (fast exit)
  `define DDR3_MR0_VAL    16'h0520

  // MR1 (BA=001) — DLL enabled, RZQ/6 ODS, RTT_NOM=RZQ/4 so the DRAM
  // can terminate FPGA writes while ODT is asserted, no levelling, no AL,
  // no TDQS, output buffer enabled. Reserved bits programmed to zero.
  //   A[0]     DLL      = 0      (DLL enabled)
  //   A[2]     RTT_NOM  = 1      (RZQ/4)
  `define DDR3_MR1_VAL    16'h0004

  // MR2 (BA=010):
  //   A[2:0]   PASR     = 000    (full array, normal temp range)
  //   A[5:3]   CWL      = 000    (CWL = 5)
  //   A[6]     ASR      = 0      (auto self-refresh off)
  //   A[7]     SRT      = 0      (normal temp self-refresh)
  //   A[10:9]  RTT_WR   = 00     (disabled — required during write levelling)
  `define DDR3_MR2_VAL    16'h0000

  // MR3 (BA=011):
  //   A[1:0]   MPR_LOC  = 00     (predefined pattern)
  //   A[2]     MPR      = 0      (MPR off — normal DRAM ops)
  `define DDR3_MR3_VAL    16'd0

`endif // DDR3_PART_MT41K256M8DA_125


// =============================================================================
// Future parts go in their own `ifdef block here, defining the same set of
// macros. The init FSM and bank state machines are part-agnostic.
// =============================================================================

`endif // DDR3_PARAMS_VH
