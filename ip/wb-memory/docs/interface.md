# wb_memory — port interface

Top module: `wb_memory`

| Direction | Signal | Width | Notes |
|---|---|---|---|
| `parameter` | `WB_DATA_W` | int (default 32) | Data bus width in bits. |
| `parameter` | `WB_ADDR_W` | int (default 14) | Word-aligned address width. Depth = `1<<WB_ADDR_W` words. |
| `parameter` | `INIT_FILE` | string ("") | Optional `$readmemh` file for simulation init. |
| `input` | `i_clk` | 1 | SoC clock. |
| `input` | `i_rst` | 1 | Synchronous active-high reset. |
| `input` | `i_wb_cyc` | 1 | Wishbone CYC. |
| `input` | `i_wb_stb` | 1 | Wishbone STB. |
| `input` | `i_wb_we` | 1 | 1 = write, 0 = read. |
| `input` | `i_wb_adr` | `WB_ADDR_W` | Word address. |
| `input` | `i_wb_dat` | `WB_DATA_W` | Write data (ignored on read). |
| `input` | `i_wb_sel` | `WB_DATA_W/8` | Byte enables (write only). |
| `output` | `o_wb_stall` | 1 | Always 0 — slave never stalls. |
| `output` | `o_wb_ack` | 1 | Asserted one cycle after a successful STB. |
| `output` | `o_wb_dat` | `WB_DATA_W` | Read data, valid on the ACK cycle. |
| `output` | `o_wb_err` | 1 | Always 0 — slave never errors. |

## Timing

| Cycle | Master | Slave |
|---|---|---|
| 0 | drives `cyc=stb=1`, `we`, `adr`, `dat`/`sel` | sees them; latches |
| 1 | may drive next xact (pipelined) | drives `ack=1` + `dat` for cycle-0 xact |

`stall` is statically 0, so the master may push one xact per cycle indefinitely.

## Renames are contract changes

Any rename of any signal above is a contract-level change per INVARIANTS #4. If you need a different port set, add a new IP under `ip/<other-name>/` rather than mutating this one.
