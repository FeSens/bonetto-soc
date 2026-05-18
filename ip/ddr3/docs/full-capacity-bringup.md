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

When changing DDR3 pin maps or lane constraints, re-fetch the online UCF/MIG
references first and treat them as authoritative. Do not infer new pin mappings
from local XDC files alone.

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

`make -C boards/ypcb-00338 full-ch0-ddr800-bitstream` is the routed
single-channel full-width isolation image. Seed 2 routes this image at
105.15 MHz `clk_sys`, 145.45 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`
against the current 100 MHz nextpnr target. Hardware validation fails
immediately, including address-zero direct reads, while BRAM sanity passes.
That isolates the functional break to the 8-lane / BL8 data path before CH1 is
involved.

`make -C boards/ypcb-00338 full-2ch-json` is the build-only gate for the
first full installed-capacity image. It enables `DDR3_FULL_2CH` and
`DDR3_RATE_1600`, instantiates a second controller/PHY stack for CH1, reuses
the CH0-generated clocks for both channels, maps global DDR3 word address bit
29 as the channel select, and uses bits `[28:0]` as the per-channel word
address. CH0 and CH1 both use the online 72-bit pin maps with physical byte
lane 3 bypassed and the ECC byte lane used as data lane 7. This target has
passed synthesis only; it still needs route timing, programming, per-channel
debug visibility, and hardware memory validation.

`make -C boards/ypcb-00338 full-2ch-ddr800-bitstream` is the current
dual-channel staging gate. It uses both online CH0/CH1 DDR3 pin maps and the
same 30-bit global address decode, but keeps the DDR3-800 timing profile.
After replacing the generic BL8 word-offset muxing with a registered one-hot
fast path, seed 1 routes this image at 103.44 MHz `clk_sys`, 136.89 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4` against a 100 MHz target. This is route
evidence only: programming succeeds, but the 30-bit hardware validator fails
immediately at address zero and the autonomous DDR3 memtest error counter is
already nonzero.

The local XDC pin maps were compared against the online raw UCFs on
2026-05-17. CH0 and CH1 package pins matched the public references; the only
expected differences were scalar local ports for single-bit nets such as
`ddr3_ck_p[0]` -> `ddr3_ck_p`.

## Required RTL Deltas

1. Replace the current constant-DQ write/read shortcut with a true BL8 data
   path. `WB_BURST_WORD_BITS` now gives the runtime a BL8 word-offset address
   hook, read-word select, and read-modify-write merge path. The byte-lane PHY
   now has a `RATIO>=8` BL8 sample sequencer that synthesizes standalone, but
   the validated CH0 board image still keeps `WB_BURST_WORD_BITS=0` and
   `SERDES_RATIO=4` until a full-lane top-level build and hardware timing are
   proven.
2. Prove the CH0 64-bit data path in hardware. The `DDR3_FULL_CH0` image
   already remaps around physical byte lane 3 by using the ECC byte lane as
   data lane 7, and seed 2 routes at DDR3-800. Hardware validation currently
   fails immediately, so this cannot replace the validated 32-bit image.
3. Add a second controller/PHY instance, then decode one high address bit as
   channel select. `DDR3_FULL_2CH` now instantiates the second stack and routes
   bit 29 to CH0/CH1 selection. CH1 pin constraints are captured in
   `boards/ypcb-00338/constraints/ddr3_ch1.xdc`, converted from the online
   YPCB-00338-1P1 `MEMORY_CH1.ucf` reference. The default CH0-only board build
   still excludes CH1 constraints.
4. Add DDR3-1600 timing/clocking mode: 800 MHz CK, 200 MHz controller clock if
   the 1:4 command ratio is preserved. `DDR3_RATE_1600` now selects the JEDEC
   CL/CWL/MR values for the `-125` speed bin and the PHY PLL divisors now
   generate 200 MHz controller and 800 MHz CK/DQS clocks for that build. Full
   route timing closure still needs hardware proof.
5. Replace the current RATIO>=8 diagnostic PHY with a full hard-SERDES read and
   write path before full-speed signoff. The latest diagnostic uses OSERDESE2
   for DQ writes, but DQS and read capture are still route-sensitive fabric/IDDR
   logic. LiteDRAM/MIG-style hard-IO serialization and read capture remains the
   right next architecture.
6. Re-enable real write/read leveling for full-speed operation. The fixed
   DDR3-800 lane map is not sufficient evidence for DDR3-1600.

## Ratio-8 CH0 Diagnostic Notes

Latest hardware observations on the four-lane CH0 DDR3-800 `DDR3_RATIO8_CH0`
image:

- The OSERDESE2 DQ-write path routes and programs, but it has not passed direct
  JTAG/Wishbone readback.
- Global sample 0 made logical byte 3 track writes while the lower 24 bits
  mostly read back as `0x000080`.
- Global sample 7 made logical bytes 0-2 track writes while byte 3 read back as
  stale `0x55`.
- A constant lane sample map of `16'h0777` changed behavior but still failed:
  bytes 1-2 tracked, bytes 0 and 3 read back as stale `0x55`.
- With the wide debug status path gated back off, seed 2 routes at 123.87 MHz
  `clk_sys`, 580.38 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`, but direct
  writes still fail. Bytes 0, 1, and 3 track the write, while logical byte 2
  reads the autonomous-pattern value `0xA5 ^ addr[7:0]`; for example,
  address `0x1234`, write `0x11111111`, read `0x11911111`.
- A host-driven logical lane-2 DQS-input IDELAY sweep across taps 0-31 found no
  passing tap in the current RATIO8 image.
- `tools/phase_sweep.py` currently increments only the visible phase counter in
  the PLLE2 clocking path; it does not physically move DQS phase until the MMCM
  path is restored. Do not use a phase-sweep failure as evidence that global
  DQS phase is correct.
- A wide raw-`phy_rd_data` status latch was useful for diagnosis but perturbed
  routing enough to invalidate direct comparison with the narrower diagnostic
  images. Do not treat that image as validation evidence.

## Validation Gates

Full-capacity signoff requires hardware evidence, not just simulation:

| Gate | Evidence Required |
|---|---|
| PHY BL8 lane synthesis | `make -C ip/ddr3 synth-phy-dq-ratio8` passes |
| CH0 full-width synthesis | `make -C boards/ypcb-00338 full-ch0-json` passes |
| Dual-channel full-speed synthesis | `make -C boards/ypcb-00338 full-2ch-json` passes |
| CH0 full-width DDR3-800 route | `make -C boards/ypcb-00338 full-ch0-ddr800-bitstream` passes with seed 2 |
| Dual-channel DDR3-800 staging route | `make -C boards/ypcb-00338 full-2ch-ddr800-bitstream` passes with seed 1 |
| CH0 64-bit DDR3-800 | currently fails direct hardware validation at address zero |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
