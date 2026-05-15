# jtag_uart — port interface (planned, iteration 2)

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

## Iteration 1 status

Stub only — RTL is not yet implemented. The wb-memory IP is the verification template; jtag-uart fills in once that template is solid.
