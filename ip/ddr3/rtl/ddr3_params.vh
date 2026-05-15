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
// MT41K256M8DA-125 — 2 Gb, x8, DDR3-1600 (-125 speed bin)
// =============================================================================
`ifdef DDR3_PART_MT41K256M8DA_125

  // Geometry
  `define DDR3_BANK_BITS  3
  `define DDR3_ROW_BITS   15            // 32 K rows
  `define DDR3_COL_BITS   10            // 1 K columns
  `define DDR3_DQ_BITS    8             // per chip

  // Clock period in picoseconds — used by host-side tools, not RTL directly.
  `define DDR3_TCK_PS     1250          // 1.25 ns = 800 MHz DDR clock = 1600 MT/s

  // Latencies (in tCK)
  `define DDR3_CL         11
  `define DDR3_CWL        8
  `define DDR3_AL         0             // additive latency disabled

  // Core timing (in tCK, JEDEC max(n_tCK, n_ns/tCK) ceiling-rounded)
  `define DDR3_TRCD       11            // 13.75 ns
  `define DDR3_TRP        11            // 13.75 ns
  `define DDR3_TRAS_MIN   28            // 35 ns
  `define DDR3_TRC        39            // 48.75 ns
  `define DDR3_TRFC       128           // 160 ns (2 Gb part)
  `define DDR3_TREFI      6240          // 7.8 µs avg @ ≤T<85°C
  `define DDR3_TWR        12            // 15 ns
  `define DDR3_TWTR       6             // 7.5 ns
  `define DDR3_TRTP       6             // 7.5 ns
  `define DDR3_TRRD       6             // 7.5 ns (8-bank)
  `define DDR3_TFAW       32            // 40 ns (8-bank)
  `define DDR3_TCCD       4
  `define DDR3_TMOD       12            // 15 ns
  `define DDR3_TMRD       4
  `define DDR3_TDLLK      512
  `define DDR3_TZQINIT    512
  `define DDR3_TXPR       136           // max(5 tCK, tRFC + 10 ns) = 170 ns / 1.25 ns rounded up

  // Power-on init timings (in tCK — for our 1.25 ns tCK, 1 µs = 800 cycles)
  `define DDR3_TRESET_TCK     160000    // 200 µs minimum
  `define DDR3_TCKE_LOW_TCK   400000    // 500 µs CKE-low

  // ----- Mode register encodings -----
  // MR0 (BA=000):
  //   A[1:0]   BL       = 00     (BL=8 fixed)
  //   A[3]     BT       = 0      (sequential burst)
  //   A[6:4,2] CL field = 1110_0 → CL=11
  //   A[7]     TM       = 0      (normal mode)
  //   A[8]     DLL_RST  = 1      (reset DLL on init)
  //   A[11:9]  WR       = 110    (WR=12)
  //   A[12]    PD       = 0      (fast exit)
  `define DDR3_MR0_VAL    16'b0_0110_1_0_111_0_00_0   // A12..A0 = 0_110_1_0_111_0_00_0

  // MR1 (BA=001) — minimal config: DLL enabled, RZQ/6 ODS, no levelling,
  // no AL, no RTT_NOM, no TDQS, output buffer enabled. All reserved
  // bits programmed to zero (Micron model is strict about this).
  //   A[0]     DLL      = 0      (DLL enabled)
  //   everything else = 0
  `define DDR3_MR1_VAL    16'd0

  // MR2 (BA=010):
  //   A[2:0]   PASR     = 000    (full array, normal temp range)
  //   A[5:3]   CWL      = 011    (CWL = 8)
  //   A[6]     ASR      = 0      (auto self-refresh off)
  //   A[7]     SRT      = 0      (normal temp self-refresh)
  //   A[10:9]  RTT_WR   = 00     (disabled — required during write levelling)
  `define DDR3_MR2_VAL    16'b0_00_0_0_0_011_000

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
