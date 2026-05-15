// soc_params.vh — SoC-wide constants. Per INVARIANTS.md item #3, changing
// any of these is a contract-level change, not a per-IP decision.
//
// Every IP that touches a Wishbone interface MUST `\`include` this file.

`ifndef SOC_PARAMS_VH
`define SOC_PARAMS_VH

// --- Wishbone bus dimensions -------------------------------------------------

`define WB_DATA_W       32         // data bus width, bits
`define WB_ADDR_W       30         // word-aligned address; byte addr = adr<<2
`define WB_SEL_W        (`WB_DATA_W / 8)

// --- SoC address map (word-aligned, top-of-byte addr space) ------------------

// wb-memory: BRAM-backed window, byte 0x0000_0000 – 0x0FFF_FFFF
`define MEM_BASE        30'h00000000
`define MEM_SIZE_WORDS  (1 << 28)   // 256 MB / 4

// ddr3: byte 0x4000_0000 – 0x7FFF_FFFF
`define DDR3_BASE       30'h10000000
`define DDR3_SIZE_WORDS (1 << 28)

// jtag-uart: byte 0xF000_0000 – 0xF000_FFFF
`define UART_BASE       30'h3C000000
`define UART_SIZE_WORDS (1 << 14)

// --- Clock and reset ---------------------------------------------------------

`define SYS_CLK_HZ      50_000_000

`endif
