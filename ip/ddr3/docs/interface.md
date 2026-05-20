# DDR3 Interface Contract

No active `ddr3_ctrl` RTL exists yet. This file defines the interface the new
controller should implement so board integration and JTAG/Wishbone validation
can be planned before RTL lands.

## Wishbone Slave

The controller-level block should expose the same basic B4-style slave shape as
`ip/wb-memory`:

| Direction | Signal | Width | Meaning |
|---|---|---:|---|
| input | `i_clk` | 1 | Wishbone/control clock. |
| input | `i_rst` | 1 | Synchronous reset. |
| input | `i_wb_cyc` | 1 | Cycle valid. |
| input | `i_wb_stb` | 1 | Request valid. |
| input | `i_wb_we` | 1 | Write when high. |
| input | `i_wb_adr` | parameterized | 32-bit word address. |
| input | `i_wb_dat` | 32 | Write data. |
| input | `i_wb_sel` | 4 | Byte enables. |
| output | `o_wb_stall` | 1 | Backpressure. |
| output | `o_wb_ack` | 1 | One-cycle response. |
| output | `o_wb_dat` | 32 | Read data. |
| output | `o_wb_err` | 1 | Protocol or unmapped error. |

Formal requirement: every implementation must pass `fwb_slave` before it is
connected to the board top.

## DDR3 Command Pins

Controller or PHY boundary must eventually drive:

| Signal | Width |
|---|---:|
| `reset_n` | 1 |
| `cke` | per rank/channel |
| `odt` | per rank/channel |
| `cs_n` | per rank/channel |
| `ras_n`, `cas_n`, `we_n` | 1 each |
| `ba` | 3 |
| `addr` | 15 |

The scheduler-visible command stream must be monitorable by
`formal/ddr3_cmd_timing_monitor.sv`.

## PHY Data Boundary

Keep the PHY boundary packetized around BL8:

| Direction | Signal | Width | Meaning |
|---|---|---:|---|
| controller to PHY | write payload | 512 | One 64-bit BL8 channel line. |
| controller to PHY | write mask | 64 | Byte mask for one BL8 line. |
| controller to PHY | write valid | 1 | Payload accepted by PHY side. |
| controller to PHY | read capture | 1 | Request a read capture. |
| PHY to controller | read payload | 512 | One captured BL8 line. |
| PHY to controller | read valid | 1 | Read payload valid. |

For the 32-bit Wishbone frontend, reads select one of sixteen words from the
512-bit line. Partial writes perform read-modify-write until byte-mask writes
are proven through the PHY.

## Debug/Status

Expose status registers through the board JTAG/Wishbone path before relying on
DDR3 data:

- init state and error code;
- calibration state and error code;
- command scheduler state;
- last accepted Wishbone address/data;
- last DDR3 command, bank, row, and column;
- per-channel pass/error counters for hardware validation.
