# jtag_uart port interface

Top module: `jtag_uart`

The JTAG-UART IP is the primary host-debug channel. It wraps `BSCANE2` (Xilinx 7-series JTAG user-data primitive) inside a Wishbone slave so a host-side tool can poll TX/RX FIFOs over the existing programming cable — no extra physical pins required.

## Wishbone-slave register map (word-addressed)

| Offset | Name | R/W | Bits | Meaning |
|---|---|---|---|---|
| 0x00 | `TX` | W | [7:0] | Push one byte into the TX FIFO. |
| 0x04 | `RX` | R | [7:0] = byte; [8] = valid | Pop one byte from the RX FIFO. `valid=0` if empty. |
| 0x08 | `STATUS` | R | [0] tx_full; [1] tx_empty; [2] rx_full; [3] rx_empty | FIFO status. |
| 0x0C | `CONTROL` | W | [0] tx_reset; [1] rx_reset | Pulse to flush. |

## Wishbone ports

Same set as [wb_memory](../../wb-memory/docs/interface.md), with `WB_DATA_W=32` and `WB_ADDR_W=2` (4 word-addresses → 16 bytes).

## JTAG side

Internal — uses `BSCANE2` with `JTAG_CHAIN=1` (USER1 instruction). Host-side tool drives the USER1 chain via openFPGALoader's XVC mode or an openocd Tcl script. See `verification/common/jtag_uart_host.py` once it exists.

## JTAG-Wishbone master commands

`jtag_wb_master` consumes command words from the status-mux write path. The
upper byte is the command and the lower 24 bits are payload.

| Command | Name | Payload |
|---|---|---|
| `0xE0` | `SET_ADDR` | local Wishbone address in low bits |
| `0xE1` | `SET_ADDR_HI` | board debug high-address bits `[15:0]` |
| `0xE2` | `SET_DATA_LO` | write data `[15:0]` |
| `0xE3` | `SET_DATA_HI` | write data `[31:16]` |
| `0xE4` | `GO_WRITE` | issue a write with stored address/data/select |
| `0xE5` | `GO_READ` | issue a read with stored address |
| `0xE6` | `HALT_OTHERS` | request autonomous traffic to pause |
| `0xE7` | `RESUME` | clear the pause request |
| `0xE8` | `SET_CAL` | lane in low `$clog2(NUM_BYTE_LANES)` bits, tap `[12:8]`, channel `[16]` |
| `0xE9` | `PHASE_INC` | request one MMCM phase increment |
| `0xEA` | `PHASE_DEC` | request one MMCM phase decrement |
| `0xF0` | `SET_SEL` | byte enables in bits `[3:0]`; reset/default is `4'hf` |
