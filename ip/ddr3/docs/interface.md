# ddr3 — controller interface (planned)

Top module: `ddr3_ctrl`

## Bus side (Wishbone B4 pipelined slave)

Same port set as [wb_memory](../../wb-memory/docs/interface.md). The board top can substitute `ddr3_ctrl` for `wb_memory` without changing any other RTL.

| Direction | Signal | Width | Notes |
|---|---|---|---|
| `parameter` | `WB_DATA_W` | int (default 32) | |
| `parameter` | `WB_ADDR_W` | int | word-aligned within the DDR3 window |
| `parameter` | `DDR3_PART` | string | e.g. `"MT41K256M8DA-125"` for our YPCB-00338; sets timing & geometry |
| `parameter` | `SPEED_GRADE` | int | 1066 / 1333 / 1600 / 1866 (MT/s) |
| ... | ... | ... | (CL, BL, ECC enable, refresh interval — derived from DDR3_PART by default, overridable) |

The Wishbone-side signal set is identical to wb_memory.

## DDR3 side (planned)

| Direction | Signal | Width | Notes |
|---|---|---|---|
| `output` | `ddr3_ck_p`, `ddr3_ck_n` | 1 each | differential clock |
| `output` | `ddr3_addr` | 16 | row/column mux |
| `output` | `ddr3_ba` | 3 | bank |
| `output` | `ddr3_cs_n`, `ddr3_ras_n`, `ddr3_cas_n`, `ddr3_we_n` | 1 each | command |
| `output` | `ddr3_cke`, `ddr3_odt`, `ddr3_reset_n` | 1 each | control |
| `inout` | `ddr3_dq` | data width (per the part — 8/16/32/64) | data |
| `inout` | `ddr3_dqs_p`, `ddr3_dqs_n` | DQ/8 each | data strobe |
| `output` | `ddr3_dm` | DQ/8 | data mask |

## Iteration 1 status

Stub satisfying the Wishbone-side contract only. The DDR3 PHY side will be empty / unconnected in iteration 1. The board top routes the DDR3 pins to the YPCB-00338 BGA pins (from the LiteX board file) but they are tied off internally until iter 2.

## JEDEC compliance

Per INVARIANTS #6: tRC / tRAS / tRP / tCK / tCWL / tCL / tRCD enforced by parameter values derived from `DDR3_PART`. Refresh deadline (tREFI) covered by a formal property. Micron's MT41K SystemVerilog model is the simulation peer.
