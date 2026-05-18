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

`make -C boards/ypcb-00338 full-ch0-oddrwr-ddr800-bitstream` is a
full-width diagnostic that keeps the 8-lane / BL8 read path but forces DQ
writes back through the legacy repeated-data ODDR launcher. Seed 2 failed
timing and did not produce a bitstream. Seed 3 produced a bitstream at
107.26 MHz `clk_sys`, 146.54 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`,
so the DQ write path is still far below the DDR3-800 400 MHz operating point.
Programming succeeded (`init 1 done 1`), but direct JTAG/Wishbone DDR3
readback failed immediately and the short hardware validator failed all DDR3
checks after BRAM sanity. First deterministic failure was address `0x00000000`,
expected `0xd0f56b4a`, got `0x00000000`; final summary was
`DDR3_HW_VALIDATE_SUMMARY ok=0 failures=7 ddr3_pass_ctr=89286466 err_ctr=89278405`.
This confirms the full-width fabric/ODDR diagnostic is not a viable
capacity-validation path.

`make -C boards/ypcb-00338 full-2ch-json` is the build-only gate for the
first full installed-capacity image. It enables `DDR3_FULL_2CH` and
`DDR3_RATE_1600`, instantiates a second controller/PHY stack for CH1, reuses
the CH0-generated clocks for both channels, maps global DDR3 word address bit
29 as the channel select, and uses bits `[28:0]` as the per-channel word
address. CH0 and CH1 both use the online 72-bit pin maps with physical byte
lane 3 bypassed and the ECC byte lane used as data lane 7. This target has
passed synthesis only; it still needs route timing, programming, per-channel
debug visibility, and hardware memory validation.

After splitting the experimental hard-IO read path out of the default target,
the normal full 2-channel DDR3-1600 synthesis gate reports 16,716 cells and an
estimated 3,892 logic cells. Notable primitive use is 22 BUFG, 196 CARRY4,
3,237 FDCE, 6,007 FDRE, 128 IDDR, 16 IDELAYE2, 128 OSERDESE2, 1 PLLE2_ADV, and
16 RAMB36E1.

`make -C boards/ypcb-00338 full-2ch-iserdes-json` is an experimental
synthesis-only gate for a LiteDRAM-inspired RATIO8 read path. It defines
`DDR3_RATIO8_ISERDES_RD`, leaves the validated narrow image untouched, and
replaces the RATIO8 DQS-clocked fabric/IDDR capture path with per-DQ
`IDELAYE2` + `ISERDESE2` read capture. The synthesis evidence is directionally
useful: the full-speed 2-channel image uses 6 BUFG instead of 22, 128
`ISERDESE2`, 128 DQ `IDELAYE2`, 128 `OSERDESE2`, and an estimated 4,621 logic
cells. This is not yet a routeable full-speed target. A seed-1 JTAG-only route
diagnostic with the same define placed at 119.26 MHz `u_blu.i_clk_50`,
74.07 MHz `clk_sys`, 265.60 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`, then
router2 plateaued at 256 overused wires and was terminated. The stable overuse
points to missing/incorrect 7-series IO-clock packing for the ISERDES cut, so
the normal full-speed bitstream targets intentionally remain on the existing
fabric read-capture path until the hard-IO clocking is solved.

`make -C boards/ypcb-00338 full-2ch-serdescmd-iserdes-json` adds
`DDR3_SERDES_CMD` to the ISERDES read experiment. This LiteDRAM-style
diagnostic hard-serializes the command, address, CKE, reset, and ODT pins with
OSERDESE2 while keeping the controller-visible 1:4 command contract and
inserting NOP slots in the other CK positions. It synthesizes to 15,391 cells
with 178 `OSERDESE2`, 128 `ISERDESE2`, 128 DQ `IDELAYE2`, 16 `RAMB36E1`, and an
estimated 4,616 logic cells. The paired seeded route target,
`make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream`,
still does not route: placement improved `clk_dq` to 655.74 MHz, but `clk_sys`
was still 68.59 MHz and router2 plateaued from iteration 12 through 41 at 256
overused wires before the run was interrupted. This proves command/address
hard-serialization is syntactically viable and reduces high-speed fabric
pressure, but it is not enough without a legal 7-series IO-clock partition for
the ISERDES/DQS side and further `clk_sys` cleanup.

`make -C boards/ypcb-00338 full-2ch-serdescmd-json` is the matching
command/address-only diagnostic. It defines `DDR3_SERDES_CMD` without the
experimental ISERDES read-capture path, so it keeps the default DQS-clocked
IDDR read path and isolates the value of hard-serializing the command/control
pins. It synthesizes to 16,731 cells with 22 `BUFG`, 178 `OSERDESE2`, 128
`IDDR`, 16 `IDELAYE2`, no `ISERDESE2`, 16 `RAMB36E1`, and an estimated 3,890
logic cells before preserving the RMW byte-mask register, and 16,742 cells /
3,900 estimated logic cells after preserving it. The paired seed-1 JTAG-only
route target,
`make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-jtagonly-bitstream`,
routes to completion but still fails timing. Before preserving the RMW byte
mask, final nextpnr estimates were 137.61 MHz for `u_blu.i_clk_50`, 96.62 MHz
for `clk_sys`, 521.10 MHz for `clk_dq`, and 1557.63 MHz for `clk_phy_x4`.
After preserving the byte mask, the same target reports 171.23 MHz for
`u_blu.i_clk_50`, 97.25 MHz for `clk_sys`, 914.91 MHz for `clk_dq`, and
1557.63 MHz for `clk_phy_x4`. The DQS raw clocks all pass the current 200 MHz
nextpnr check. Compared with the non-serialized JTAG-only RMW target, this
avoids the ISERDES overuse plateau and closes the reported `clk_dq` estimate
above 800 MHz, but `clk_sys` is still far below the 200 MHz controller target.
The new `clk_sys` critical path moved from `saved_burst_word_onehot` RMW merge
logic to read-capture control fanout around lane-0 `i_rd_capture`; it is still
route-failure evidence, not a hardware-signoff bitstream.

After splitting the fast full-width read select into two registered stages
(first the 64-bit BL8 sample, then the 32-bit lane group), the same
`full-2ch-serdescmd-json` diagnostic synthesizes to 16,826 cells with 22
`BUFG`, 178 `OSERDESE2`, 128 `IDDR`, 16 `IDELAYE2`, no `ISERDESE2`, 16
`RAMB36E1`, and an estimated 3,828 logic cells. The paired seed-1 route still
fails timing, but `clk_sys` improves to 107.22 MHz while `clk_dq` reports
651.04 MHz and `clk_phy_x4` remains 1557.63 MHz. This replaces the
`saved_burst_word_onehot` read-select critical path with a `phy_rd_valid_ch1`
/ read-capture fanout path. It is a useful routed checkpoint for the controller
datapath, but still does not meet the 200 MHz controller target or the 800 MHz
DDR3-1600 CK/DQ intent.

`make -C boards/ypcb-00338 full-2ch-iserdes-bufio-json` adds
`DDR3_RATIO8_ISERDES_BUFIO_RDCLK`, a narrow routing diagnostic that inserts one
BUFIO per active byte lane for the experimental ISERDES read clock. It
synthesizes to 15,457 cells with 16 `BUFIO`, 128 `ISERDESE2`, 128 DQ
`IDELAYE2`, 128 `OSERDESE2`, and an estimated 4,609 logic cells. This does not
fix the route: `make -C boards/ypcb-00338
full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream` fails during placement with
`Unable to place cell 'u_ddr3_phy.u_lanes.g_lane[0].u_lane.g_read_iserdes.u_rd_iserdes_bufio',
no Bels remaining of type 'BUFIO'`. That rules out simply dropping lane-local
BUFIOs behind the existing global `clk_phy_x4`; the next hard-IO attempt needs
to originate the ISERDES clock from the CMT/HPC side and likely partition it by
7-series IO clock region.

`make -C boards/ypcb-00338 full-2ch-ddr800-bitstream` is the current
dual-channel staging gate. It uses both online CH0/CH1 DDR3 pin maps and the
same 30-bit global address decode, but keeps the DDR3-800 timing profile.
After replacing the generic BL8 word-offset muxing with a registered one-hot
fast path, seed 1 routes this image at 103.44 MHz `clk_sys`, 136.89 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4` against a 100 MHz target. This is route
evidence only: programming succeeds, but the 30-bit hardware validator fails
immediately at address zero and the autonomous DDR3 memtest error counter is
already nonzero.

`make -C boards/ypcb-00338 full-2ch-ddr1600-bitstream` is the current
full-speed route gate. Seed 1 does not close timing after commit `a98f6dc`:
final nextpnr estimates are 85.19 MHz for `u_blu.i_clk_50` against the
200 MHz route target, 76.80 MHz for `clk_sys` against the 200 MHz controller
target, 511.51 MHz for `clk_dq`, and 1557.63 MHz for `clk_phy_x4`.
`clk_dq` passes the current 200 MHz nextpnr check but remains below the
800 MHz CK/DQS intent for DDR3-1600. The slow-net report is dominated by
global reset/control fanout, `saved_burst_word_onehot` fanout in both runtime
instances, `phy_*_valid`, memtest state, and fabric read-capture paths. This
is route-failure evidence only; there is no full-speed hardware bitstream.

`make -C boards/ypcb-00338 full-2ch-ddr1600-jtagonly-bitstream` removes the
autonomous memtest master and keeps only JTAG/Wishbone access for a full-speed
timing diagnostic while preserving the same read-modify-write datapath used by
the autonomous target. Seed 1 still fails timing: final nextpnr estimates are
123.03 MHz for `u_blu.i_clk_50`, 95.02 MHz for `clk_sys`, 409.00 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. The critical `clk_sys` path is in
the RMW merge around `saved_burst_word_onehot`, and the slow-net report is
still dominated by reset/control fanout, `phy_*_valid`, lane read-capture
controls, and both runtime instances.

`make -C boards/ypcb-00338 full-2ch-ddr1600-jtagdirect-bitstream` is the older
JTAG-only diagnostic that explicitly defines `DDR3_DIRECT_WRITE_NO_RMW` and
writes a selected 32-bit word inside a BL8 burst without preserving the rest of
the burst. The last seed-1 direct-write diagnostic reached 136.69 MHz for
`u_blu.i_clk_50`, 114.43 MHz for `clk_sys`, 285.55 MHz for `clk_dq`, and
1557.63 MHz for `clk_phy_x4`, but it is no longer representative of the normal
full-speed write path.

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
   write path before full-speed signoff. The latest diagnostics use OSERDESE2
   for DQ writes and can also hard-serialize command/address with
   `DDR3_SERDES_CMD`. The `DDR3_RATIO8_ISERDES_RD` experiment proves the read
   path can synthesize as hard IO, but it does not route yet in openXC7 because
   the ISERDES high-speed clocking still needs the right 7-series IO clock
   network. A lane-local BUFIO behind the existing global clock is not
   legal/placeable in nextpnr; LiteDRAM/MIG-style hard-IO serialization and read
   capture with CMT or IO-region clocking remains the right next architecture.
6. Re-enable real write/read leveling for full-speed operation. The fixed
   DDR3-800 lane map is not sufficient evidence for DDR3-1600.

## Ratio-8 CH0 Diagnostic Notes

Hardware observations and current status for the four-lane CH0 DDR3-800
`DDR3_RATIO8_CH0` image:

- The OSERDESE2 DQ-write path now passes the four-lane CH0 DDR3-800 hardware
  validator when the write vector is continuously registered on `clk_sys` and
  OSERDES tri-state is driven from the sys-domain write-data strobe. Seed 2
  routes at 126.97 MHz `clk_sys`, 516.00 MHz `clk_dq`, and 1557.63 MHz
  `clk_phy_x4`. The 60 second validator passed BRAM sanity, deterministic
  boundary patterns, address walking, every 32-bit data bit and byte lane,
  contiguous alignment windows, a 1024-word XOR checksum sweep, 128 randomized
  writes, and autonomous memtest soak:
  `DDR3_HW_VALIDATE_SUMMARY ok=1 failures=0 ddr3_pass_ctr=474271898 err_ctr=0`.
- Earlier, global sample 0 made logical byte 3 track writes while the lower 24 bits
  mostly read back as `0x000080`.
- Earlier, global sample 7 made logical bytes 0-2 track writes while byte 3 read back as
  stale `0x55`.
- Earlier, a constant lane sample map of `16'h0777` changed behavior but still failed:
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
- `make -C boards/ypcb-00338 ratio8-ch0-oddrwr-ddr800-bitstream` forces the
  RATIO8 repeated-data diagnostic write path back through the legacy ODDR
  launcher while keeping the RATIO8 read/sample path. Seed 2 routed and
  programmed, but `clk_dq` estimated only 312.89 MHz, below the 400 MHz
  DDR3-800 operating point. Direct JTAG/Wishbone validation passed the
  deterministic, address-walking, data-bit/byte-lane, contiguous-window,
  1024-word XOR checksum, and 128-random-address checks. Autonomous soak still
  failed with a rising memtest error counter. This localizes the latest
  repeated-write failure to the OSERDESE2 DQ write path or its OE/load behavior,
  but it is not timing-clean validation evidence.
- The same ODDR-write diagnostic does not scale to the full eight logical CH0
  byte lanes. Seed 3 can produce a bitstream, but it routes only
  107.26 MHz `clk_sys` and 146.54 MHz `clk_dq`; direct DDR3 readback and the
  bounded validator both fail immediately after BRAM sanity.
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
| Dual-channel DDR3-1600 target route | `make -C boards/ypcb-00338 full-2ch-ddr1600-bitstream` currently fails timing with seed 1 |
| Dual-channel DDR3-1600 JTAG-only route | `make -C boards/ypcb-00338 full-2ch-ddr1600-jtagonly-bitstream` currently fails timing with seed 1 while preserving RMW |
| Dual-channel DDR3-1600 hard-command diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-jtagonly-bitstream` routes to completion but fails timing with seed 1 |
| Dual-channel DDR3-1600 hard-command/ISERDES diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream` still hits the ISERDES overuse plateau |
| Dual-channel DDR3-1600 direct-write diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-jtagdirect-bitstream` isolates the old no-RMW write path |
| CH0 64-bit DDR3-800 | currently fails direct hardware validation at address zero |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
