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

## Online Board References

Use the public YPCB-00338-1P1 reference files as the source of truth for board
pins and MIG geometry:

| Reference | Use |
|---|---|
| `https://github.com/TiferKing/ypcb_00338_1p1_hack` | Online board reverse-engineering archive |
| `constraints/MEMORY_CH0.ucf` | Channel-0 DDR3 pins |
| `constraints/MEMORY_CH1.ucf` | Channel-1 DDR3 pins |
| `constraints/ypcb003381p1.xdc` | Board-level system clock/reset pins |
| `ypcb003381p1/1.0/mig_0.prj` | Single-controller CH0 MIG reference |
| `ypcb003381p1/1.0/mig_1.prj` | Single-controller CH1 MIG reference |
| `ypcb003381p1/1.0/mig_01.prj` | Dual-controller MIG reference |

The dual-controller MIG reference confirms the board-file geometry to design
against: `MT41K256M8XX-125`, 72 DQ bits per channel, ECC enabled, no data mask,
15 row bits, 10 column bits, 3 bank bits, 2 GiB data capacity per channel, and
a 512-bit AXI/UI data width per channel. That 512-bit payload is the natural
full BL8 interface for one 64-bit channel.

Do not copy the MIG clocking target blindly for the DDR3-1600 goal. The online
MIG projects use `TimePeriod=1875` ps with a 4:1 PHY ratio and 200 MHz input
clock, which is a DDR3-1066-class reference rather than the 800 MHz CK /
1600 MT/s target. The pin and geometry data are still useful; the full-speed
PLL/MMCM, timing, and hardware validation need to be proven in this repo.

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

`make -C boards/ypcb-00338 full-ch0-json` is a build-only gate for the next
CH0 image. It enables `DDR3_FULL_CH0`, expands the top-level CH0 data ports to
the 72-bit online `MEMORY_CH0.ucf` pin map, instantiates an 8-lane / BL8 PHY
path, and maps logical data lanes 0,1,2,3,4,5,6,7 onto physical lanes
0,1,2,4,5,6,7,8. Physical byte lane 3 remains bypassed. This target does not
replace the hardware-proven default image and is not hardware signoff.

## Required RTL Deltas

1. Replace the current constant-DQ write/read shortcut with a true BL8 data
   path. `WB_BURST_WORD_BITS` now gives the runtime a BL8 word-offset address
   hook, read-word select, and read-modify-write merge path. The byte-lane PHY
   now has a `RATIO>=8` BL8 sample sequencer that synthesizes standalone, but
   the validated CH0 board image still keeps `WB_BURST_WORD_BITS=0` and
   `SERDES_RATIO=4` until a full-lane top-level build and hardware timing are
   proven.
2. Prove the CH0 64-bit data path in hardware. The build-only
   `DDR3_FULL_CH0` image already remaps around physical byte lane 3 by using
   the ECC byte lane as data lane 7. It still needs route timing, programming,
   and JTAG/Wishbone validation before it can replace the validated image.
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
| PHY BL8 lane synthesis | `make -C ip/ddr3 synth-phy-dq-ratio8` passes |
| CH0 full-width synthesis | `make -C boards/ypcb-00338 full-ch0-json` passes |
| CH0 64-bit DDR3-800 | deterministic, walking address/data, per-byte lane, checksum, and soak over unique BL8 offsets |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
