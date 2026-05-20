# DDR3 Interface Contract

`rtl/ddr3_ctrl.sv` is the packetized compatibility controller shell.
`rtl/ddr3_ctrl_line.sv` is the line-level pre-PHY controller shell intended for
the real board DQ/DQS PHY. This file defines the interfaces exposed today and
the remaining board/PHY contract that still must be implemented before DDR3
hardware validation.

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
the selected word slot inside a BL8 line, inverts `i_wb_sel` into DDR3 DM
polarity for the line byte mask, and selects the requested 32-bit word from a
backend read line. In that mask, `1` means suppress the byte and `0` means
write the byte. It is not the full controller-level `ddr3_ctrl`; downstream
scheduler, merge, PHY, calibration, and status integration live above or
beside this frontend.

`rtl/ddr3_wb_channel.sv` is the integrated bus/data slice. It now composes the
line-level Wishbone bridge with `ddr3_channel_line`: a write request presents a
complete 64-byte BL8 channel line before the scheduler can accept the command,
and a read request waits for a complete returned line before acknowledging
Wishbone. Its scheduler-facing handshake deliberately uses two events:

- `i_cmd_ready` accepts a line request only when the bridge and packetizer have
  a stable line-level contract for that request.
- `i_xfer_start` launches the full-channel data packetizer when the matching
  RD/WR command has actually issued.

This separation matters because an open-row miss, bank timing wait, refresh
window, or write-to-read turnaround can delay the RD/WR command after the
Wishbone request has already been accepted. The channel bridge still does not
own PHY timing, calibration, or partial-write read-modify-write.

`rtl/ddr3_wb_dual_channel.sv` is the first integrated global bus slice. It
wraps two `ddr3_wb_channel` instances behind `ddr3_addr_decode`, uses
`global[29]` as the channel select, routes `global[28:0]` to the selected
channel, and exposes independent command/data packet ports for channel 0 and
channel 1. It intentionally allows only one global Wishbone request outstanding
at a time; throughput pipelining should wait until scheduler and PHY timing are
hardware-proven.

`rtl/ddr3_wb_dual_channel_line.sv` is the hardware-facing version of that same
global bus slice. It wraps two `ddr3_wb_line_channel` instances directly, so
the selected channel exposes a complete write line and byte mask at request
acceptance and waits for a complete read line before responding.

`rtl/ddr3_channel_sched.sv` is the first scheduler-side adapter for one
channel. It consumes `{write, line_addr}`, decodes `{bank, row, column[9:3]}`,
feeds the refresh requester plus scheduler, reports request acceptance through
`o_cmd_ready`, and pulses `o_xfer_start` only when the scheduler emits the
matching RD or WR command. `o_xfer_write` is valid with that pulse and tells
the downstream PHY whether the data window belongs to a write or read.

`rtl/ddr3_ctrl.sv` ties those bus and scheduler pieces together for two
channels. It instantiates `ddr3_wb_dual_channel`, two `ddr3_init_seq` blocks,
and two `ddr3_channel_sched` blocks. Before both init sequencers finish, the
controller stalls Wishbone and drives each channel's DDR3 command pins from its
init sequencer. After init, the scheduler adapters own the runtime command pins
and start the packetized line data path only when a matching RD/WR command
issues. This is still a controller/PHY boundary, not a pin-level DQS/DQ PHY.

`rtl/ddr3_ctrl_line.sv` keeps the same init and scheduler ownership, but swaps
the bus dispatch block for `ddr3_wb_dual_channel_line`. A write request is
accepted only after the line-level PHY side can capture the full 512-bit BL8
payload and 64-bit mask. A read request does not acknowledge Wishbone until the
PHY side returns the full 512-bit captured line. The controller exposes
one-cycle `o_phy_start_write` and `o_phy_start_read` pulses aligned to the
scheduler's issued WR/RD command, which is the clean start contract consumed by
the reusable line-to-lane PHY bridge.

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

The controller-side logical PHY boundary is a complete BL8 channel line:

| Direction | Signal | Width | Meaning |
|---|---|---:|---|
| controller to PHY | write payload | 512 | One 64-bit BL8 channel line. |
| controller to PHY | write mask | 64 | DDR3 DM byte mask for one BL8 line; `1` suppresses a byte. |
| controller to PHY | write valid | 1 | Payload accepted by PHY side. |
| controller to PHY | read capture | 1 | Request a read capture. |
| PHY to controller | read payload | 512 | One captured BL8 line. |
| PHY to controller | read valid | 1 | Read payload valid. |

For the 32-bit Wishbone frontend, reads select one word from the BL8 line. With
the final 64-bit channel line this means one of sixteen 32-bit words from a
512-bit line. The current frontend emits a byte mask for the selected word. A
PHY with DDR3 DM support can preserve that mask directly. On YPCB-00338, the
active constraints expose DQ/DQS but no DM pins, so the line bridge also has a
`PHY_HAS_BYTE_MASK=0` mode: writes issue a read of the target BL8 line, merge
the selected Wishbone bytes into the returned 512-bit line, then issue a full
all-active write. This mode is the intended path before masked Wishbone writes
are exposed as hardware validated on the board.

`rtl/ddr3_byte_lane.sv` implements the first x8 slice of this boundary: one
64-bit BL8 byte lane with eight write mask bits and an ordered read-capture
response. `rtl/ddr3_channel_line.sv` composes eight of those lanes into the
full 64-bit-channel packet boundary: one 512-bit BL8 line plus 64 byte-mask
bits, with per-lane compatibility handshakes still visible until the Xilinx
7-series DQS/DQ PHY replaces that simulation-facing packetizer.
`rtl/ddr3_wb_channel.sv` captures the complete line before scheduler command
acceptance, then waits for the scheduler adapter's transfer-start pulse before
driving the packet flow. `rtl/ddr3_wb_dual_channel.sv` replicates that
packetized compatibility boundary once per channel. `rtl/ddr3_wb_line_channel.sv`
owns the mask-preserving and no-DM RMW line contracts.
`rtl/ddr3_wb_dual_channel_line.sv` and `rtl/ddr3_ctrl_line.sv` expose that
line contract directly as the intended top-level boundary for the real DQS/DQ
PHY.

`rtl/ddr3_line_to_lanes.sv` is the reusable bridge from the controller's
two-channel line contract to sixteen independent x8 lane streams.
`rtl/ddr3_x8_lane_phy.sv` is the first synthesizable lane timing core after
that bridge: it accepts eight write bytes plus masks before a WR data window,
launches four DDR rise/fall pin-data pairs with DQ/DM/DQS output enables, then
captures four read sample pairs and returns eight lane bytes. Board-specific
IOBUF, ODDR/IDDR, IDELAY, DQS clocking, training, and calibration still belong
outside this core.

`rtl/ddr3_line_lane_phy.sv` composes those two reusable contracts. It accepts
complete channel BL8 lines, queues explicit scheduler transfer-start pulses,
starts all x8 lane PHYs for the selected channel together once write bytes are
loaded or a read window is ready, and exposes abstract per-lane DDR DQ/DQS/DM
rise/fall timing signals. It is the intended input to a future YPCB-00338
7-series primitive wrapper, but it is still not pin-level hardware validation.

`rtl/ddr3_line_phy_clock_bridge.sv` is a deliberately narrow bridge between
the slow controller line contract and a faster PHY-side clock domain. It is
single-outstanding per channel and holds each multi-bit payload stable until
the receiving side has acknowledged the matching toggle. The bridge has a
simulation and a bounded protocol proof, but the first board experiment that
placed the whole abstract line-lane PHY behind this bridge did not meet the
DDR3-800 400 MHz `clk_dq` target. The useful architecture lesson is that this
bridge is a control/data boundary; it is not permission to move wide soft
line assembly, lane arbitration, or pin-pair checking into the bit clock domain.
Those pieces should remain in slow fabric. The fast domain should eventually
contain only the minimum 7-series I/O shell: DQ/DQS output/input registers,
delay/calibration, and tightly local per-bit capture/launch logic.

## Debug/Status

Expose status registers through the board JTAG/Wishbone path before relying on
DDR3 data:

- init state and error code;
- calibration state and error code;
- command scheduler state;
- last accepted Wishbone address/data;
- last DDR3 command, bank, row, and column;
- per-channel pass/error counters for hardware validation.
