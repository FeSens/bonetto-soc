# wishbone — interfaces

This IP is the shared substrate. There's no single "top module" — instead, it provides the macros every other IP includes and the future bus-fabric modules (arbiter, crossbar) that compose IPs together.

## Macros (`rtl/wb_types.vh`)

| Macro | Expands to |
|---|---|
| `WB_SLAVE_PORTS(AW, DW)` | Full Wishbone-slave port list (cyc / stb / we / adr / dat / sel inputs + stall / ack / dat / err outputs). |
| `WB_MASTER_PORTS(AW, DW)` | Mirror: master outputs + slave-side inputs. |
| `WB_DEFAULT_DATA_W` | Default data width (32). |
| `WB_DEFAULT_ADDR_W` | Default word-address width (30). |
| `WB_DEFAULT_SEL_W` | `DATA_W / 8`. |

## Future modules (placeholder)

- `wb_arbiter` — N-master round-robin arbiter onto one slave port.
- `wb_xbar` — M-master × N-slave crossbar with address decoding from `soc_params.vh`.
- `wb_clock_crossing` — async-FIFO CDC for slaves on a different clock domain (DDR3 PHY in particular).

Each of these arrives with its own formal harness and counted in INVARIANTS #1.
