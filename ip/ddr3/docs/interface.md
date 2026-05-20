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

## Address Map

`rtl/ddr3_addr_decode.sv` defines the full-capacity global word-address map:

```text
global[29]      channel select
global[28:26]   bank
global[25:11]   row
global[10:4]    column[9:3]
global[3:0]     word inside the 64-byte BL8 line
```

For each channel this covers 8 banks, 32K rows, 128 BL8 column slots per row,
and 16 32-bit words per BL8 line. Across two full 64-bit channels this is a
30-bit 32-bit-word address space, or 4 GiB. The decoder also emits the
scheduler-facing line address `{bank, row, column[9:3]}` and the DDR3 command
column address `{column[9:3], 3'b000}`.

`rtl/ddr3_wb_frontend.sv` is the first live slice of this contract. It accepts
one 32-bit Wishbone request at a time, stalls while that request is outstanding,
splits the word address into `{line address, word index}`, packs write data into
the selected word slot inside a BL8 line, shifts `i_wb_sel` into a line byte
mask, and selects the requested 32-bit word from a backend read line. It is not
yet the full controller-level `ddr3_ctrl`; downstream scheduler, merge, PHY,
calibration, and status integration are still separate work.

`rtl/ddr3_wb_channel.sv` is the first integrated bus/data slice. It composes
the Wishbone frontend with `ddr3_channel_line`, emits one scheduler-facing BL8
line command `{write, line_addr}`, starts the full-channel data packetizer when
that command is accepted, and returns completed read lines to the frontend for
32-bit word selection. It still does not own a DDR3 command scheduler, row
machine selection, PHY timing, calibration, or partial-write read-modify-write.

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

For the 32-bit Wishbone frontend, reads select one word from the BL8 line. With
the final 64-bit channel line this means one of sixteen 32-bit words from a
512-bit line. The current frontend emits a byte mask for the selected word;
downstream logic must either preserve that byte mask through a proven PHY write
path or perform read-modify-write before partial writes are exposed as hardware
validated.

`rtl/ddr3_byte_lane.sv` implements the first x8 slice of this boundary: one
64-bit BL8 byte lane with eight write mask bits and an ordered read-capture
response. `rtl/ddr3_channel_line.sv` composes eight of those lanes into the
full 64-bit-channel packet boundary: one 512-bit BL8 line plus 64 byte-mask
bits, with per-lane PHY handshakes still visible for the future Xilinx 7-series
DQS/DQ bridge. `rtl/ddr3_wb_channel.sv` currently drives that packet boundary
from Wishbone requests and exposes the line command that the future scheduler
must pair with ACT/RD/WR/PRE timing.

## Debug/Status

Expose status registers through the board JTAG/Wishbone path before relying on
DDR3 data:

- init state and error code;
- calibration state and error code;
- command scheduler state;
- last accepted Wishbone address/data;
- last DDR3 command, bank, row, and column;
- per-channel pass/error counters for hardware validation.
