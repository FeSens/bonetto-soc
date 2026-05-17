# DDR3 Full-Capacity Bring-Up

Target: expose the installed YPCB-00338 DDR3 data capacity at the `-125`
DDR3-1600 speed bin.

## Target Configuration

| Item | Target |
|---|---:|
| Channels | 2 |
| Data width per channel | 64 bits |
| ECC lane | present on board, optional for the first full-capacity data image |
| DRAM part | Micron MT41K256M8DA-125 |
| Data capacity | 4 GiB across CH0 + CH1 |
| Raw capacity with ECC lanes | 4.5 GiB |
| DRAM clock | 800 MHz CK |
| Transfer rate | DDR3-1600, 1600 MT/s |
| Controller-visible word address | 30 bits of 32-bit words |

## Current Validated State

The hardware-proven image is intentionally narrower:

| Item | Current validated image |
|---|---:|
| Channels | CH0 only |
| Active data width | 32 bits |
| Active physical byte lanes | 0, 1, 2, 4 |
| DRAM clock | 400 MHz CK |
| Transfer rate | DDR3-800 |
| Controller-visible word address | 25 bits |
| Exposed capacity | 128 MiB |

The board/debug fabric can carry the SoC's 30-bit word-address contract, and
JTAG-WB can now supply DDR3 address bits `[29:14]`. Those bits are not yet a
capacity guarantee: the runtime and PHY still need to consume them.

## Required RTL Deltas

1. Replace the current constant-DQ write/read shortcut with a true BL8 data
   path. The runtime must use the BL8 word offset instead of treating each
   burst as one 32-bit word.
2. Expand CH0 to a 64-bit data path. On this board, either recover physical
   byte lane 3 or explicitly remap data lane 3 onto the ECC byte lane and run
   without ECC for the first 64-bit proof.
3. Add a second controller/PHY instance, then decode one high address bit as
   channel select. CH1 pin constraints are now captured in
   `boards/ypcb-00338/constraints/ddr3_ch1.xdc`, converted from the online
   YPCB-00338-1P1 `MEMORY_CH1.ucf` reference. The file is intentionally not in
   the current CH0-only board build until the top-level CH1 ports exist.
4. Add DDR3-1600 timing/clocking mode: 800 MHz CK, 200 MHz controller clock if
   the 1:4 command ratio is preserved. `DDR3_RATE_1600` now selects the JEDEC
   CL/CWL/MR values for the `-125` speed bin; the board clock generator and
   full-rate timing closure still need hardware proof.
5. Re-enable real write/read leveling for full-speed operation. The fixed
   DDR3-800 lane map is not sufficient evidence for DDR3-1600.

## Validation Gates

Full-capacity signoff requires hardware evidence, not just simulation:

| Gate | Evidence Required |
|---|---|
| CH0 64-bit DDR3-800 | deterministic, walking address/data, per-byte lane, checksum, and soak over unique BL8 offsets |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
