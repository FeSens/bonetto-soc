// ddr3_params.vh — JEDEC DDR3 timing parameters, per part.
//
// One `ifdef block per part. Select the active part with one of:
//   `define DDR3_PART_MT41K256M8DA_125    // 2 Gb, x8, DDR3-1600 -125 (YPCB-00338)
//   `define DDR3_PART_MT41K512M8DA_125    // 4 Gb, x8, DDR3-1600 -125
//   ... (add more here)
//
// Select the operating point with one of:
//   `define DDR3_RATE_800                  // validated YPCB-00338 point
//   `define DDR3_RATE_1600                 // full-speed -125 timing profile
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

// Default to the hardware-validated YPCB-00338 operating point.
`ifndef DDR3_RATE_800
  `ifndef DDR3_RATE_1600
    `define DDR3_RATE_800
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
// (400 MHz CK, 800 MT/s). The -125 speed bin also supports DDR3-1600
// (800 MHz CK, 1600 MT/s), selected with DDR3_RATE_1600.
// =============================================================================
`ifdef DDR3_PART_MT41K256M8DA_125

  // Geometry
  `define DDR3_BANK_BITS  3
  `define DDR3_ROW_BITS   15            // 32 K rows
  `define DDR3_COL_BITS   10            // 1 K columns
  `define DDR3_DQ_BITS    8             // per chip

  `ifdef DDR3_RATE_1600
    // Clock period in picoseconds — full -125 speed bin.
    `define DDR3_TCK_PS     1250        // 1.25 ns = 800 MHz DDR clock = 1600 MT/s
    `define DDR3_CK_PER_SYS 4           // 1:4 fabric-to-CK ratio => 200 MHz fabric

    // Latencies (in tCK)
    `define DDR3_CL         11
    `define DDR3_CWL        8
    `define DDR3_AL         0           // additive latency disabled

    // Core timing (in tCK, JEDEC max(n_tCK, n_ns/tCK) ceiling-rounded)
    `define DDR3_TRCD       11          // 13.75 ns
    `define DDR3_TRP        11          // 13.75 ns
    `define DDR3_TRAS_MIN   28          // 35 ns
    `define DDR3_TRC        39          // 48.75 ns
    `define DDR3_TRFC       128         // 160 ns (2 Gb part)
    `define DDR3_TREFI      6240        // 7.8 us avg at <=85 C
    `define DDR3_TWR        12          // 15 ns
    `define DDR3_TWTR       6           // max(4 tCK, 7.5 ns)
    `define DDR3_TRTP       6           // max(4 tCK, 7.5 ns)
    `define DDR3_TRRD       8           // 10 ns conservative low-speed bin
    `define DDR3_TFAW       32          // 40 ns (8-bank)
    `define DDR3_TCCD       4
    `define DDR3_TMOD       12          // max(12 tCK, 15 ns)
    `define DDR3_TMRD       4
    `define DDR3_TDLLK      512
    `define DDR3_TZQINIT    512
    `define DDR3_TXPR       136         // max(5 tCK, tRFC + 10 ns)

    // Power-on init timings (in tCK — 1 us = 800 cycles at 1.25 ns tCK)
    `define DDR3_TRESET_TCK     160000  // 200 us minimum
    `define DDR3_TCKE_LOW_TCK   400000  // 500 us CKE-low
  `else
    // Clock period in picoseconds — hardware-validated YPCB-00338 point.
    `define DDR3_TCK_PS     2500        // 2.5 ns = 400 MHz DDR clock = 800 MT/s
    `define DDR3_CK_PER_SYS 4           // 1:4 fabric-to-CK ratio => 100 MHz fabric

    // Latencies (in tCK)
    `define DDR3_CL         6
    `define DDR3_CWL        5
    `define DDR3_AL         0           // additive latency disabled

    // Core timing (in tCK, JEDEC max(n_tCK, n_ns/tCK) ceiling-rounded)
    `define DDR3_TRCD       6           // 13.75 ns
    `define DDR3_TRP        6           // 13.75 ns
    `define DDR3_TRAS_MIN   14          // 35 ns
    `define DDR3_TRC        20          // 48.75 ns
    `define DDR3_TRFC       64          // 160 ns (2 Gb part)
    `define DDR3_TREFI      3120        // 7.8 us avg at <=85 C
    `define DDR3_TWR        6           // 15 ns
    `define DDR3_TWTR       4           // max(4 tCK, 7.5 ns)
    `define DDR3_TRTP       4           // max(4 tCK, 7.5 ns)
    `define DDR3_TRRD       4           // 10 ns conservative low-speed bin
    `define DDR3_TFAW       16          // 40 ns (8-bank)
    `define DDR3_TCCD       4
    `define DDR3_TMOD       12          // 15 ns
    `define DDR3_TMRD       4
    `define DDR3_TDLLK      512
    `define DDR3_TZQINIT    512
    `define DDR3_TXPR       68          // max(5 tCK, tRFC + 10 ns)

    // Power-on init timings (in tCK — 1 us = 400 cycles at 2.5 ns tCK)
    `define DDR3_TRESET_TCK     80000   // 200 us minimum
    `define DDR3_TCKE_LOW_TCK   200000  // 500 us CKE-low
  `endif

  // ----- Mode register encodings -----
  // MR0 (BA=000):
  //   A[1:0]   BL       = 00     (BL=8 fixed)
  //   A[3]     BT       = 0      (sequential burst)
  //   A[6:4,2] CL field = profile-selected CL
  //   A[7]     TM       = 0      (normal mode)
  //   A[8]     DLL_RST  = 1      (reset DLL on init)
  //   A[11:9]  WR       = profile-selected write recovery
  //   A[12]    PD       = 0      (fast exit)
  `ifdef DDR3_RATE_1600
    `define DDR3_MR0_VAL  16'h0D70     // CL=11, WR=12
  `else
    `define DDR3_MR0_VAL  16'h0520     // CL=6, WR=6
  `endif

  // MR1 (BA=001) — DLL enabled, RZQ/6 ODS, RTT_NOM=RZQ/4 so the DRAM
  // can terminate FPGA writes while ODT is asserted, no levelling, no AL,
  // TDQS enabled (disables DM), output buffer enabled. Reserved bits
  // programmed to zero.
  //   A[0]     DLL      = 0      (DLL enabled)
  //   A[2]     RTT_NOM  = 1      (RZQ/4)
  //   A[11]    TDQS     = 1      (enabled; no external DM pins on board)
  `define DDR3_MR1_VAL    16'h0804

  // MR2 (BA=010):
  //   A[2:0]   PASR     = 000    (full array, normal temp range)
  //   A[5:3]   CWL      = profile-selected CWL
  //   A[6]     ASR      = 0      (auto self-refresh off)
  //   A[7]     SRT      = 0      (normal temp self-refresh)
  //   A[10:9]  RTT_WR   = 00     (disabled — required during write levelling)
  `ifdef DDR3_RATE_1600
    `define DDR3_MR2_VAL  16'h0018     // CWL=8
  `else
    `define DDR3_MR2_VAL  16'h0000     // CWL=5
  `endif

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
