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

Registering the aggregate lane read-valid signal for full BL8 images keeps the
validated ratio-4 path unchanged and changes the full-speed seed-1 route
profile. `full-2ch-serdescmd-json` synthesizes to 16,847 cells with 22 `BUFG`,
178 `OSERDESE2`, 128 `IDDR`, 16 `IDELAYE2`, no `ISERDESE2`, 16 `RAMB36E1`, and
an estimated 3,811 logic cells. The paired
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still fails timing, with
142.03 MHz for `u_blu.i_clk_50`, 107.40 MHz for `clk_sys`, 818.33 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. This recovers the reported
high-speed DQ estimate above the 800 MHz DDR3-1600 intent, but the controller
clock remains the hard blocker.

Parameterizing the PHY calibration generators and passing the existing board
skip policy into both full-width PHY instances removes unused write-leveling and
read-leveling logic from the skipped-calibration full-speed target without
changing enabled-calibration builds. `full-2ch-serdescmd-json` now synthesizes
to 14,239 cells with 22 `BUFG`, 178 `OSERDESE2`, 128 `IDDR`, 16 `IDELAYE2`, no
`ISERDESE2`, 16 `RAMB36E1`, and an estimated 3,091 logic cells. The paired
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` seed-1 route still fails
timing, with 142.76 MHz for `u_blu.i_clk_50`, 110.41 MHz for `clk_sys`,
827.13 MHz for `clk_dq`, and 1557.63 MHz for `clk_phy_x4`. This is a useful
cleanup checkpoint: resource use is much lower and `clk_dq` remains above the
DDR3-1600 800 MHz intent, but `clk_sys` still blocks signoff.

Removing the redundant 512-bit `rmw_wr_data` staging register and its
`S_RMW_LATCH` state keeps the RMW behavior intact while reducing the full
hard-command image. `make -C ip/ddr3 sim-runtime-addr` still passes, and
`make -C boards/ypcb-00338 full-2ch-serdescmd-json` drops to 13,202 cells /
3,077 estimated logic cells, mainly by removing about one thousand FFs. This is
not a timing-signoff fix: the paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still fails at 138.89 MHz
`u_blu.i_clk_50`, 111.40 MHz `clk_sys`, 788.02 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`. The final `clk_sys` critical path is again lane-0
`i_rd_capture`, and the slow-net list still shows `phy_wr_valid`, burst-offset,
and RMW mask fanout.

`make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-ddronly-json` and the
paired bitstream target add `DDR3_JTAG_DDR_ONLY`, a narrow diagnostic that
keeps the hard-serialized command/address path but removes BRAM and the
BRAM/DDR3 decode mux from the 200 MHz fabric. Synthesis drops to 12,424 cells
and an estimated 2,590 logic cells, confirming the wrapper-side logic was a
real area contributor. The seed-1 route still fails timing, however: final
nextpnr estimates are 123.09 MHz for `u_blu.i_clk_50`, 110.52 MHz for
`clk_sys`, 705.22 MHz for `clk_dq`, and 1557.63 MHz for `clk_phy_x4`. Slow
nets remain dominated by controller/RMW state, `phy_wr_valid`, burst offset
and byte-mask fanout, and lane read-capture controls. This rules out the
BRAM/decode wrapper as the primary full-speed blocker; it is diagnostic
evidence only and is not a replacement for the normal validation image.

A targeted `ddr3_runtime` reset-split experiment also failed as a timing
cleanup path. Moving `!i_init_done` out of the wide runtime datapath reset
while keeping state, command, ack, and clear strobes idle passed
`make -C ip/ddr3 sim-runtime-addr`, but `full-2ch-serdescmd-json` grew to
14,241 cells and an estimated 3,662 logic cells. That change was reverted
without routing; do not repeat it without a more selective retiming plan.

Registering the `ddr3_ctrl` init-done handoff into a local
`init_done_runtime` control was also tried and reverted. It was cheap in
synthesis (`full-2ch-serdescmd-json` at 14,272 cells / 3,098 estimated logic
cells) and improved the seed-1 hard-command route's `clk_dq` estimate to
962.46 MHz, but `clk_sys` still failed and slipped slightly to 109.54 MHz.
The critical path moved into per-lane `i_rd_capture`, while the slow-net list
remained dominated by RMW state, burst-offset/mask fanout, `phy_wr_valid`, and
lane read-capture controls. Since `clk_sys` is the blocker and the baseline
already has `clk_dq` above the DDR3-1600 800 MHz intent, this is not worth
keeping as-is.

Removing the two wide `rd_data_sys` clears at the start of PHY read capture was
also tested and reverted. The functional reasoning was valid for the sys-domain
outputs because `rd_valid_q` is cleared at capture start, and
`make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 synth-phy-dq-ratio8`, and
`make -C boards/ypcb-00338 full-2ch-serdescmd-json` passed. Synthesis improved
to 13,240 cells and an estimated 2,795 logic cells, but seed-1 routing regressed:
`u_blu.i_clk_50` reached 133.73 MHz, `clk_sys` reached 109.77 MHz, and `clk_dq`
fell to 621.50 MHz. The same `i_rd_capture` fanout remained in DQS-lane CE/SR
paths, so the area win did not help the full-speed route and the change should
not be kept in this form.

Registering `ddr3_runtime.o_rd_capture` with a one-cycle lookahead was also
tested and reverted. It passed `make -C ip/ddr3 sim-runtime-addr`, and
`full-2ch-serdescmd-json` shrank slightly to 14,236 cells / 3,077 estimated
logic cells. The paired seed-1 hard-command route regressed to 118.37 MHz
`u_blu.i_clk_50`, 97.22 MHz `clk_sys`, 791.77 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`. The lane-array output register was already present, so this only
changed upstream logic; the post-route critical path still reported
per-lane `i_rd_capture` fanout. Do not keep this without a lane-local capture
control split.

Moving the read-capture staging from `ddr3_phy_lane_array` into each
`ddr3_phy_dq` byte lane was then tested and reverted. The idea was to place the
`clk_sys` capture-enable source closer to each DQS-domain sink while preserving
the existing one-cycle staging latency. It passed `make -C ip/ddr3
sim-runtime-addr`, `make -C ip/ddr3 synth-phy-dq-ratio8`, and `make -C
boards/ypcb-00338 full-2ch-serdescmd-json`; full-image synthesis was 14,254
cells / 3,083 estimated logic cells. Seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` still failed: final estimates
were 150.67 MHz for `u_blu.i_clk_50`, 116.58 MHz for `clk_sys`, 632.51 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. The old fanout issue simply moved
to the new kept `rd_capture_lane_q` nets, and `clk_dq` regressed below the
DDR3-1600 800 MHz intent, so this is not a viable full-speed path as-is.

Forcing `ddr3_runtime.state` to binary FSM encoding with
`(* fsm_encoding = "binary" *)` was also tested and reverted. It passed
`make -C ip/ddr3 sim-runtime-addr` and synthesized
`full-2ch-serdescmd-json`, but full-image synthesis grew to 14,253 cells /
3,432 estimated logic cells with a large LUT6 increase. The seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route failed at 140.73 MHz
`u_blu.i_clk_50`, 99.85 MHz `clk_sys`, 376.36 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`; the slow-net list still included burst-offset, write-valid, and
state fanout. Keep the default Yosys encoding unless a broader controller
pipeline split accompanies it.

An experimental `DDR3_RATIO8_CONTINUOUS_DQS_CAPTURE` define was tried and
reverted in the DQS-clocked RATIO8 read path. It removed the full-rate
`i_rd_capture` fanout from the per-bit IDDR/data-sampler enables while leaving
the ratio-4 default untouched. `make -C ip/ddr3 synth-phy-dq-ratio8` passed and
the full hard-command image synthesized to 14,235 cells / 3,090 estimated logic
cells. The seed-1 JTAG-only route still failed: final estimates were 138.45 MHz
for `u_blu.i_clk_50`, 112.55 MHz for `clk_sys`, 722.02 MHz for `clk_dq`, and
1557.63 MHz for `clk_phy_x4`. The main `clk_sys` critical path moved to
`ddr3_runtime.state[22]`, but the `clk_dq` regression below the DDR3-1600
800 MHz intent makes this a diagnostic only.

Splitting each lane's `i_rd_capture` fanout through kept per-bit `LUT1`
identity buffers was also tested and reverted. `make -C ip/ddr3
synth-phy-dq-ratio8` passed and the full hard-command image synthesized to
13,775 cells / 3,482 estimated logic cells with 128 explicit `LUT1`s, but the
seed-1 `full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route regressed to
132.38 MHz for `u_blu.i_clk_50`, 87.77 MHz for `clk_sys`, 408.66 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. The extra buffers increased area
and worsened routing, so explicit LUT fanout splitting is not a viable path.

Tying the full-BL8 IDDR `CE` inputs high while keeping the DQS-domain capture
window under `i_rd_capture` was also tested and reverted. `make -C ip/ddr3
synth-phy-dq-ratio8` passed and `full-2ch-serdescmd-json` synthesized to
13,217 cells / 3,086 estimated logic cells, but the seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still failed at
149.57 MHz for `u_blu.i_clk_50`, 106.59 MHz for `clk_sys`, 654.45 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. This removes one IDDR CE branch
but not the DQS-domain capture-window fanout, and it regresses the DDR3-1600
DQ clock margin.

The previous route checkpoint kept zero-latency lane-local `LUT1` copies of
the PHY write-valid/write-DQS-enable strobes in `ddr3_phy_lane_array`. This
reduces the global `phy_wr_valid` slow-net fanout from roughly 515 sinks to 9
sinks, but each lane-local copy still drives about 66 local sinks. Synthesis
grows to 13,545 cells / 3,157 estimated logic cells with 32 kept `LUT1`s, and
the seed-1 hard-command JTAG-only route still fails at 145.22 MHz for
`u_blu.i_clk_50`, 117.05 MHz for `clk_sys`, 807.10 MHz for `clk_dq`, and
1557.63 MHz for `clk_phy_x4`. This is a modest routing improvement, not a
signoff fix; the next cut still needs to reduce `state[21]`, burst-offset,
lane `i_rd_capture`, and lane-local write-enable fanout.

The current route checkpoint also keeps board-level `clk_sys` reset replicas
in `boards/ypcb-00338/rtl/top.v`. Each local copy releases one cycle after
`rst_sys` and drives one region: memtest, host CDC, JTAG master, bus/decode,
BRAM, debug command, status, and each DDR3 controller/calibration pair.
`full-2ch-serdescmd-json` still synthesizes cleanly at 13,550 cells / 3,151
estimated logic cells, so the reset split is essentially area-neutral. The
seed-1 `full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still fails, but
improves the current kept checkpoint to 138.41 MHz `u_blu.i_clk_50`,
123.72 MHz `clk_sys`, 844.59 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
The reset net is no longer the `clk_sys` critical path; the remaining blocker
is again lane-0 `i_rd_capture`/DQS capture-control routing. This is useful
progress, not DDR3-1600 signoff.

The latest kept PHY read-capture checkpoint makes the full-BL8 DQS-domain
sampler lane-local: IDDR `CE` is tied high only in full-BL8 mode, the DQS edge
counter arms locally from `i_rd_capture`, and full-BL8 DQS-domain sample/tail
registers no longer take the sys reset. The ratio-4 path keeps its existing
reset and capture behavior. `make -C ip/ddr3 synth-phy-dq-ratio8` and
`make -C ip/ddr3 sim-runtime-addr` still pass. The current
`full-2ch-serdescmd-json` image reports 13,606 cells / 3,216 estimated logic
cells, with 22 `BUFG`, 136 `CARRY4`, 2,479 `FDCE`, 4,673 `FDRE`, 128 `IDDR`,
16 `IDELAYE2`, 178 `OSERDESE2`, 1 `IDELAYCTRL`, 1 `PLLE2_ADV`, and
16 `RAMB36E1`. The paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still fails timing:
156.49 MHz `u_blu.i_clk_50`, 112.32 MHz `clk_sys`, 914.08 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`; all DQS raw clocks pass the current 200 MHz nextpnr
check. This improves high-speed DQ route margin but does not solve the
200 MHz controller-clock blocker. A follow-on experiment that added kept
lane-local sys-domain start/done pulses grew the image to 13,627 cells /
3,959 estimated logic cells and regressed route timing to 151.01 MHz
`u_blu.i_clk_50`, 98.22 MHz `clk_sys`, and 840.34 MHz `clk_dq`, so that pulse
split was reverted.

The next kept checkpoint moves the full-BL8 sys-domain data capture onto the
synchronized DQS event and stops clearing the wide `rd_data_sys` register at
capture start in full-BL8 mode. `rd_valid_q` is still cleared at capture start
and is only asserted after the capture window has completed, so stale data
remains hidden behind the valid handshake. This removes the wide data mux from
the lane-local `rd_capture_q` control path. `make -C ip/ddr3
synth-phy-dq-ratio8`, `make -C ip/ddr3 sim-runtime-addr`, and `make -C
ip/ddr3 sim` pass. The `full-2ch-serdescmd-json` image drops to 12,627 cells /
2,924 estimated logic cells, with 22 `BUFG`, 136 `CARRY4`, 2,479 `FDCE`,
4,673 `FDRE`, 128 `IDDR`, 16 `IDELAYE2`, 178 `OSERDESE2`, 1 `IDELAYCTRL`,
1 `PLLE2_ADV`, and 16 `RAMB36E1`. The paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still fails timing, but
improves to 160.44 MHz `u_blu.i_clk_50`, 127.02 MHz `clk_sys`, 813.67 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`; all DQS raw clocks pass the current
200 MHz nextpnr check. The `clk_sys` critical path has moved out of PHY
read-capture control and into CH1 runtime wait-counter/control logic. This is
useful route progress, not DDR3-1600 signoff.

Repeating the same hard-command JTAG-only diagnostic with seed 2 was worse:
final route timing was 136.84 MHz `u_blu.i_clk_50`, 111.53 MHz `clk_sys`,
761.61 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. Treat seed 1 as the current
best fixed-seed baseline unless a later source change invalidates this
comparison.

A follow-on experiment made the full-BL8 runtime emit a one-cycle
read-capture request and moved the read-capture window stretcher into
`ddr3_phy_lane_array` for RATIO8 builds. The intent was to keep the full-rate
capture control local to the PHY and remove the runtime's long level-style
`i_rd_capture` fanout. Fast checks passed: `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 synth-phy-dq-ratio8`,
`make -C ip/ddr3 sim-init`, `make -C ip/ddr3 sim-micron`, and
`make -C ip/ddr3 formal DEPTH=20`. The late-flat hard-command synthesis target
reported 11,562 cells / 2,641 estimated logic cells. The paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-lateflat-bitstream` route still failed
and regressed the controller clock: placement was 110.93 MHz
`u_blu.i_clk_50`, 73.91 MHz `clk_sys`, 662.25 MHz `clk_dq`, and 2500.00 MHz
`clk_phy_x4`; final timing was 140.31 MHz `u_blu.i_clk_50`, 113.20 MHz
`clk_sys`, 969.93 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final
`clk_sys` critical path returned to `rst_bram` into a runtime register set/reset
pin with 8.4 ns routing, while the slow-net list still included runtime state
and lane-local capture logic. The DQ margin was good, but the 200 MHz
controller target moved backward, so the RTL was reverted.

A follow-on reset-less runtime datapath split was tested and reverted. The
change moved saved request fields plus the wide read-data/sample/word registers
out of the reset branch, while keeping reset on the control/output FSM. The
intent was to remove the board reset replica from wide runtime datapath flops.
Fast checks passed: `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim-init`, `make -C ip/ddr3 sim-micron`, and `make -C ip/ddr3
formal DEPTH=20`. The late-flat hard-command synthesis image reported 10,321
cells / 2,528 estimated logic cells, with `ddr3_runtime` at 1,779 cells / 855
estimated logic cells. The seed-1 late-flat route still failed timing and
regressed the controller/50 MHz clocks: placement reported 104.38 MHz
`u_blu.i_clk_50`, 85.14 MHz `clk_sys`, 826.45 MHz `clk_dq`, and 2500.00 MHz
`clk_phy_x4`; final route reported 137.27 MHz `u_blu.i_clk_50`, 113.70 MHz
`clk_sys`, 961.54 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final
`clk_sys` critical path moved from reset into CH1 request-accept logic:
`jwb_grant`/`d3_ch1_stb` through runtime logic to a runtime set/reset pin with
7.6 ns routing. This again improves DQ margin but moves the 200 MHz controller
target backward, so do not repeat reset-less datapath splitting as a standalone
fix.

An optional runtime auto-precharge experiment was tested and reverted. The
change set command A10 on normal READ/WRITE commands and skipped the explicit
PRE command afterward, while keeping the preliminary RMW read open and allowing
the final RMW write to auto-precharge. Fast checks passed: `git diff --check`,
default `make -C ip/ddr3 sim-runtime-addr`, and
`DDR3_DEFINES=-DDDR3_AUTO_PRECHARGE` runs of `sim-runtime-addr`, `sim-init`,
`sim-micron`, and `formal DEPTH=20`. The late-flat hard-command synthesis image
grew to 11,510 cells / 2,631 estimated logic cells, with `ddr3_runtime` at
2,370 cells / 906 estimated logic cells. The seed-1 late-flat route regressed
hard: placement reported 108.87 MHz `u_blu.i_clk_50`, 83.30 MHz `clk_sys`,
344.23 MHz `clk_dq`, and 2500.00 MHz `clk_phy_x4`; final route reported
129.27 MHz `u_blu.i_clk_50`, 104.80 MHz `clk_sys`, 469.70 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The final `clk_sys` critical path ran from
`rst_bram` into a runtime set/reset pin with 9.1 ns routing. This proves
auto-precharge is not useful as a local timing fix in the current runtime FSM.
A later retry using the macro name `DDR3_RUNTIME_AUTO_PRECHARGE` also passed
default `make -C ip/ddr3 sim-runtime-addr sim` and opt-in
`DDR3_DEFINES=-DDDR3_RUNTIME_AUTO_PRECHARGE make -C ip/ddr3 sim-runtime-addr
sim`, but the same seed-1 late-flat JTAG-only route still regressed versus the
current best. Final routed timing in
`boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_autopre_lateflat_seed1_route.log`
was 147.65 MHz `u_blu.i_clk_50`, 121.82 MHz `clk_sys`, 562.43 MHz `clk_dq`,
and 1557.63 MHz `clk_phy_x4`, below the current best 175.13 MHz
`u_blu.i_clk_50`, 143.97 MHz `clk_sys`, 820.34 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`.

A registered refresh-block experiment in `ddr3_runtime` was tested and
reverted. The change replaced direct `ref_pending` use in WB stall/IDLE
arbitration with a registered `ref_block`, allowing at most one accepted
transaction after `ref_pending` rises before forcing refresh service. Fast
checks passed: `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim`, `make -C ip/ddr3 formal DEPTH=20`, and the late-flat
JSON target. The late-flat hard-command synthesis image reported 11,498 cells
/ 2,640 estimated logic cells, with `ddr3_runtime` at 2,367 cells / 909
estimated logic cells. The seed-1 late-flat route regressed versus the clean
baseline: placement reported 117.16 MHz `u_blu.i_clk_50`, 86.28 MHz
`clk_sys`, 536.19 MHz `clk_dq`, and 2500.00 MHz `clk_phy_x4`; final route
reported 162.28 MHz `u_blu.i_clk_50`, 117.30 MHz `clk_sys`, 773.99 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final `clk_sys` critical path
moved into top-level/JTAG address decode feeding CH1 `burst_byte_mask`. This
confirms that moving the refresh/stall guard alone does not solve the 200 MHz
runtime scheduling path.

Adding `-dff` to the late-flatten `synth_xilinx -abc9` flow was tested as a
pure synthesis diagnostic and not carried. The JSON build did not explode:
`full-2ch-ddr1600-serdescmd-jtagonly-lateflat_dff` reported 11,542 cells /
2,494 estimated logic cells, with `ddr3_runtime` at 2,368 cells / 841
estimated logic cells. The seed-1 route still regressed versus the clean
late-flat baseline, however: final timing was 159.80 MHz `u_blu.i_clk_50`,
117.14 MHz `clk_sys`, 916.59 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
The `clk_sys` critical path moved from JTAG address/channel decode through
CH1 runtime enable logic, while reset fanout into the PHY became the dominant
cross-domain route. This proves `-dff` is not a timing-closure fix for the
200 MHz controller path.

The clean late-flat hard-command JTAG-only image was also spot-checked with
seed 2. It failed worse than the seed-1 comparison point: final timing was
146.20 MHz `u_blu.i_clk_50`, 114.22 MHz `clk_sys`, 977.52 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The `clk_sys` critical path was a long route from
`ddr3_runtime.state[21]` to a runtime state/data flop. Seed 1 remains the
fixed comparison seed; seed hunting does not address the structural 200 MHz
controller-clock problem.

A full-BL8 RMW mask-removal experiment in `ddr3_runtime` was tested and
reverted. The change removed the 64-bit kept `saved_burst_byte_mask` register
and derived RMW byte replacement from `saved_burst_word_onehot` plus
`saved_sel`, cutting accept-time mask decode while preserving behavior. Fast
checks passed: `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim`, and `make -C ip/ddr3 formal DEPTH=20`. The late-flat
JSON shrank to 11,264 cells / 2,534 estimated logic cells, with
`ddr3_runtime` at 2,254 cells / 855 estimated logic cells, but seed-1 routing
still regressed the controller path: final timing was 152.81 MHz
`u_blu.i_clk_50`, 125.33 MHz `clk_sys`, 893.66 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`. This improves DQ margin and area but loses `clk_sys` versus the
132.68 MHz clean baseline, so it should not be carried as a standalone timing
fix.

Pipelining the full-BL8 write-data bus at the PHY lane-array boundary plus a
one-cycle runtime `S_WR_PREP` state was tested and reverted. Fast checks still
passed: `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, and `make -C
ip/ddr3 sim`. The `full-2ch-serdescmd-json` image reported 13,647 cells /
2,936 estimated logic cells. The paired seed-1
`full-2ch-ddr1600-serdescmd-ddronly-bitstream` route still failed timing but
improved to 148.06 MHz `u_blu.i_clk_50`, 136.13 MHz `clk_sys`, 885.74 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`; the old write-data fanout path was
removed. The normal seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` diagnostic regressed versus
the current checkpoint to 161.84 MHz `u_blu.i_clk_50`, 124.29 MHz `clk_sys`,
783.70 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. Because this drops
`clk_dq` below the DDR3-1600 800 MHz intent and worsens the normal diagnostic,
do not repeat the write-data pipeline as a standalone timing cleanup.

A follow-on attempt to move the long refresh wait off `wait_ctr[5]` and onto a
small shift timer was also tested and reverted. `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, and `make -C ip/ddr3 sim` passed, but the
same DDR-only seed-1 route regressed to 156.62 MHz `u_blu.i_clk_50`,
127.70 MHz `clk_sys`, 838.93 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`, with
a reset-dominated `clk_sys` critical path. Do not repeat this as a standalone
cleanup.

A read-side selector split that duplicated `saved_burst_word_offset[3:1]` into
per-lane sample selectors was tested and reverted. `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, and `make -C ip/ddr3 sim` passed, and
`full-2ch-serdescmd-json` reported 12,632 cells / 2,910 estimated logic cells.
The normal seed-1 `full-2ch-ddr1600-serdescmd-jtagonly-bitstream` diagnostic
regressed to 154.08 MHz `u_blu.i_clk_50`, 116.66 MHz `clk_sys`, 761.03 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`. The duplicated selector costs little
area but worsens both controller timing and high-speed DQ margin, so do not
repeat it as a standalone offset-fanout cleanup.

Removing the `keep` attribute from `saved_burst_byte_mask` was tested and
reverted. `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, and `make -C
ip/ddr3 sim` passed. `full-2ch-serdescmd-json` reported 12,605 cells /
2,932 estimated logic cells. The normal seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` diagnostic still failed and
regressed the controller/50 MHz clocks to 141.26 MHz `u_blu.i_clk_50`,
123.33 MHz `clk_sys`, 853.97 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
The better DQ margin does not compensate for the lower controller timing, so
keep the preservation attribute until a broader RMW-mask rewrite is available.

Splitting the runtime `!i_init_done` reset gating out of several always-block
reset conditions was tested and reverted before route. `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, and `make -C ip/ddr3 sim` passed, but
`full-2ch-serdescmd-json` jumped to 12,643 cells / 3,948 estimated logic
cells. Although the current failed route can show `ctrl_init_done` in a
critical `clk_sys` SR path, moving that gating into local hold logic explodes
LUT pressure and is not a useful standalone fix.

Changing the shared runtime wait counter from count-up/equality-to-constant to
load-and-count-down was also tested and reverted. `git diff --check`, `make -C
ip/ddr3 sim-runtime-addr`, and `make -C ip/ddr3 sim` passed, and
`full-2ch-serdescmd-json` improved slightly to 12,613 cells / 2,911 estimated
logic cells. The paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still regressed to
151.42 MHz `u_blu.i_clk_50`, 121.14 MHz `clk_sys`, 895.26 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The higher DQ margin and small area reduction do not
compensate for the lower controller and 50 MHz clock timing, so keep the
current count-up wait FSM until the runtime control path is restructured more
deeply.

Narrowing the shared runtime `wait_ctr` width to the computed maximum wait was
tested and reverted. `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
and `make -C ip/ddr3 sim` passed, and `full-2ch-serdescmd-json` improved to
12,603 cells / 2,909 estimated logic cells. The paired seed-1
`full-2ch-ddr1600-serdescmd-jtagonly-bitstream` route still failed timing at
164.42 MHz `u_blu.i_clk_50`, 133.49 MHz `clk_sys`, 743.49 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. Although controller timing improved modestly,
`clk_dq` dropped below the DDR3-1600 800 MHz intent, so do not repeat this as
a standalone wait-counter cleanup.

The same restored baseline was also routed with nextpnr's
`--placer-budgets` timing-budget placer option. This did not help: final
timing regressed to 143.66 MHz `u_blu.i_clk_50`, 125.19 MHz `clk_sys`,
752.45 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. Keep the default heap
placer settings unless a larger floorplanning or clock-domain split gives the
placer a structurally easier problem.

The hard-command JTAG-only image was also synthesized without the usual
`synth_xilinx -flatten` pass to check whether preserving hierarchy through
synthesis would help placement. A pure hierarchical JSON crashed
nextpnr-xilinx before placement with `std::out_of_range: vector`, so it is not
a usable flow today. A late-flatten diagnostic that runs `synth_xilinx -abc9`
and then `flatten` before `write_json` is reproducible with `make -C
boards/ypcb-00338
full-2ch-ddr1600-serdescmd-jtagonly-lateflat-bitstream`. It reduced synthesis
to 11,484 cells / 2,633 estimated logic cells and improved the seed-1 route
to 167.98 MHz `u_blu.i_clk_50`, 132.68 MHz `clk_sys`, 829.19 MHz `clk_dq`,
and 1557.63 MHz `clk_phy_x4`, but still misses the 200 MHz controller target.
Treat it as a comparison point for larger runtime/PHY-control changes, not as
a timing-closure fix.

A runtime experiment that registered the full BL8 write payload before issuing
WRITE was tested and reverted. The intent was to remove the always-live
512-bit RMW/direct-write merge from the PHY input path, but it increased the
late-flatten diagnostic to 12,528 cells / 3,013 estimated logic cells and
regressed the seed-1 route to 157.55 MHz `u_blu.i_clk_50`, 105.86 MHz
`clk_sys`, 593.82 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The extra
payload registers made congestion worse, so do not repeat this as a standalone
timing fix.

Adding a `fsm_encoding = "one-hot"` hint to `ddr3_runtime.state` was also
tested and reverted. The narrow runtime address/RMW sim passed and the
late-flatten diagnostic still synthesized to 11,484 cells / 2,633 estimated
logic cells, but the seed-1 route reproduced the same failing timing as the
baseline: 167.98 MHz `u_blu.i_clk_50`, 132.68 MHz `clk_sys`, 829.19 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`. This hint changes the runtime logic
mix but does not move the actual route result.

Disabling Yosys FSM extraction on `ddr3_runtime.state` with
`fsm_extract = "no"` was also tested and reverted. The narrow runtime
address/RMW sim passed, but the late-flatten diagnostic synthesized to the
same 11,484 cells / 2,633 estimated logic cells as the baseline. Since the
netlist summary did not move, this is a neutral synthesis-control diagnostic,
not a route-worthy timing fix.

Removing the redundant `!o_wb_stall` self-reference from the `S_IDLE`
Wishbone-accept condition was tested and reverted. The narrow runtime
address/RMW sim passed and the late-flatten diagnostic shrank to 11,475 cells
/ 2,494 estimated logic cells, but seed-1 routing regressed to 143.76 MHz
`u_blu.i_clk_50`, 96.26 MHz `clk_sys`, 934.58 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`. A seed-2 spot check still failed at 149.43 MHz `u_blu.i_clk_50`,
126.37 MHz `clk_sys`, 679.81 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
This removes one reported path in synthesis, but it perturbs placement badly
enough that it should not be carried without a larger reset/control split.

A one-entry Wishbone request buffer inside `ddr3_runtime` was also tested and
reverted. The intent was to break the `ref_pending -> rt_wb_stall -> runtime
state CE` path without changing the public WB port set. The predecoded-buffer
variant passed `make -C ip/ddr3 sim-runtime-addr` and synthesized to 11,742
cells / 2,620 estimated logic cells, but the seed-1 late-flat route regressed
to 152.56 MHz `u_blu.i_clk_50`, 106.42 MHz `clk_sys`, 425.17 MHz `clk_dq`,
and 1557.63 MHz `clk_phy_x4`; the new `clk_sys` critical path ran through
top-level grant/address decode into the request buffer's burst-byte-mask
registers. A narrower raw/sliced-buffer variant passed the same sim and
synthesized to 11,626 cells / 2,508 estimated logic cells, but still routed
worse than baseline at 138.47 MHz `u_blu.i_clk_50`, 123.66 MHz `clk_sys`,
713.78 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. Since both variants lose
the current late-flat `clk_sys` and `clk_dq` margins, do not repeat WB request
buffering as a standalone timing fix.

An unconditional `state <= state` default assignment in `ddr3_runtime` was
also tested and reverted. The intent was to stop the `S_IDLE` arbitration from
inferring a long state-register CE path. `make -C ip/ddr3 sim-runtime-addr`
passed, and the late-flatten diagnostic synthesized slightly smaller at 11,480
cells / 2,631 estimated logic cells, but the seed-1 route regressed to 152.25
MHz `u_blu.i_clk_50`, 120.12 MHz `clk_sys`, 833.33 MHz `clk_dq`, and 1557.63
MHz `clk_phy_x4`. The `clk_sys` critical path moved onto a reset/SR route into
`ddr3_runtime`, so this synthesis-style CE reshaping should not be repeated as
a standalone timing fix.

The next full-speed focus is the 1600/800/200 1:4 architecture, not more
standalone reshaping of the current monolithic runtime FSM. LiteDRAM and
UberDDR3 both keep the slow controller domain as a four-slot command/data
producer: command/address/control are packed into four DDR command phases per
controller cycle, read/write strobes are delay-line events, and refresh/bank
timing are scheduled before the PHY serializer boundary. Our PHY already has
the hard OSERDES pieces for command and DQ writes, but the controller still
presents one global `ref_pending -> wb_stall -> state CE` feedback path at
200 MHz. The next RTL step should therefore be a Bonetto-specific DFI-lite
phase boundary: phase 0 must reproduce today's scalar command behavior with
phases 1-3 as NOP, then later the runtime can move to per-bank/refresh command
sources that fill those slots without changing the locked Wishbone port set.

A no-refresh late-flat timing diagnostic was tested and reverted. The invalid
build defined `DDR3_DISABLE_RUNTIME_REFRESH` to force `ref_pending` low and
isolate whether the current refresh feedback path was the remaining 200 MHz
blocker. `git diff --check`, `make -C ip/ddr3 sim-runtime-addr
DDR3_DEFINES=-DDDR3_DISABLE_RUNTIME_REFRESH`, and `make -C ip/ddr3 sim
DDR3_DEFINES=-DDDR3_DISABLE_RUNTIME_REFRESH` passed. The late-flat JSON image
reported 4,862 packed cells / 2,507 estimated logic cells, and the seed-1
late-flat route still failed at 135.61 MHz `u_blu.i_clk_50`, 124.21 MHz
`clk_sys`, 903.34 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The `clk_sys`
critical path was `jwb_grant` / DDR fabric decode into CH1 runtime FSM CE
pattern-cache logic, with 1.4 ns logic and 6.7 ns routing. This rules out
removing refresh as a standalone fix: the DQ side can stay healthy, but the
controller path still needs the scheduler/request boundary to move the live
fabric grant and runtime state CE apart.

A JTAG-only constant-grant cleanup was tested and reverted. The idea was to
make `DDR3_JTAG_ONLY` behave like `DDR3_JTAG_DDR_ONLY` at the top arbiter,
since memtest is tied off and the priority-grant register should not be needed.
This removed the live `jwb_grant` mux from JTAG-only routing while preserving
BRAM/DDR address decode. `git diff --check` passed and the normal late-flat
JTAG-only hard-command route was rebuilt through `nix develop`. The change
regressed seed-1 timing: final estimates were 159.72 MHz `u_blu.i_clk_50`,
106.84 MHz `clk_sys`, 794.91 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
The `clk_sys` critical path moved wholly inside CH0 runtime state fanout,
from `u_ddr3_ctrl.u_runtime.state[21]` through pattern-cache/procmux logic,
with 0.4 ns logic and 9.0 ns routing. This is worse than the clean late-flat
baseline, so the top-level arbiter should not be simplified as a standalone
timing cleanup; the scheduler/request boundary still needs to absorb the
fabric request and runtime state fanout together.

A PHY-local phase-0 pack refactor of `DDR3_SERDES_CMD` was tested and reverted.
The change rewired the command OSERDES inputs through explicit four-phase
vectors while keeping phase 0 identical to today's command and phases 1-3 as
NOP. It passed `make -C ip/ddr3 sim-runtime-addr` and the late-flatten
diagnostic synthesized close to baseline at 11,472 cells / 2,636 estimated
logic cells, but the fixed seed-1 late-flat route regressed the system clock:
165.92 MHz `u_blu.i_clk_50`, 124.72 MHz `clk_sys`, 888.89 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The DQ-side improvement is useful signal, but the
200 MHz controller path still got worse. Do not carry a standalone PHY pack
refactor; the phase boundary needs to arrive with a real scheduler/control
split that removes the runtime CE path.

A registered-Wishbone-stall experiment in `ddr3_runtime` was tested and
reverted. The change replaced the combinational `o_wb_stall` with a
`wb_ready_q` flop and added a `ref_due_now` guard so the ready signal could not
remain asserted when refresh became due. It passed
`make -C ip/ddr3 sim-runtime-addr` and the late-flatten diagnostic synthesized
to 4,880 packed cells / 2,455 estimated logic cells, but seed-1 late-flat
routing regressed sharply: placement reported 119.33 MHz `u_blu.i_clk_50`,
94.34 MHz `clk_sys`, 621.12 MHz `clk_dq`, and 2500.00 MHz `clk_phy_x4`; final
route reported 136.28 MHz `u_blu.i_clk_50`, 102.86 MHz `clk_sys`, 843.88 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`. The slow-net list moved deeper into
runtime state, burst-offset, and saved byte-mask nets, so a registered stall
alone is another local reshaping that should not be carried.

A one-entry Wishbone front-end split in `ddr3_ctrl` was tested and reverted.
The change moved the external WB stall decision into `ddr3_ctrl` and presented
`ddr3_runtime` with a queued local request so runtime readiness did not feed
directly back into the interconnect. `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim-init sim-micron`,
`make -C ip/ddr3 formal DEPTH=20`, and the late-flat JSON target all passed.
The late-flatten diagnostic synthesized to 11,644 cells / 2,509 estimated
logic cells. Route timing still regressed: placement reported 119.55 MHz
`u_blu.i_clk_50`, 103.73 MHz `clk_sys`, 662.25 MHz `clk_dq`, and 2500.00 MHz
`clk_phy_x4`; final route reported 133.69 MHz `u_blu.i_clk_50`, 117.65 MHz
`clk_sys`, 877.96 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final
`clk_sys` critical path ran through `rst_bram` into a runtime FSM CE with 7.9
ns routing. This confirms that decoupling external WB stall alone can help DQ
placement but does not solve the controller scheduling path. Do not keep this
front-end split without a deeper scheduler/per-bank/timing pipeline split.

A split command-output register block in `ddr3_runtime` was tested and
reverted. The intent was to keep DDR command/address/write-valid flops outside
the scheduler state-update always block while preserving the same command issue
cycles. `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, `make -C
ip/ddr3 sim-init sim-micron`, `make -C ip/ddr3 formal DEPTH=20`, and the
late-flat JSON target all passed. The late-flatten diagnostic synthesized to
11,486 cells / 2,520 estimated logic cells, with `ddr3_runtime` at 2,359 cells
/ 846 estimated logic cells. The seed-1 late-flat route regressed to 144.68
MHz `u_blu.i_clk_50`, 103.96 MHz `clk_sys`, 660.94 MHz `clk_dq`, and 1557.63
MHz `clk_phy_x4`; placement estimates were 109.17 MHz `u_blu.i_clk_50`, 69.57
MHz `clk_sys`, 498.75 MHz `clk_dq`, and 2500.00 MHz `clk_phy_x4`. The final
`clk_sys` critical path ran from `jwb_grant`/`bram_adr[0]` into the CH1
runtime `burst_byte_mask` register with 8.6 ns routing, and cross-domain reset
paths also worsened. Do not repeat command-output block splitting without
first moving request decode and burst-mask generation behind a local scheduler
pipeline.

A one-cycle request-decode pipeline in `ddr3_runtime` was tested and
reverted. The change captured raw WB request fields in `S_IDLE`, then computed
bank/row/col, `saved_burst_word_onehot`, and `saved_burst_byte_mask` from
local request registers in a new `S_REQ_DECODE` state before ACT. This removed
the live bus-address-to-mask register path but added one controller cycle of
transaction latency. `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim-init sim-micron`, `make -C ip/ddr3 formal DEPTH=20`, and
the late-flat JSON target all passed. The late-flatten diagnostic synthesized
to 11,643 cells / 2,640 estimated logic cells, with `ddr3_runtime` at 2,432
cells / 905 estimated logic cells. The seed-1 late-flat route still regressed
from baseline: final timing was 155.69 MHz `u_blu.i_clk_50`, 129.63 MHz
`clk_sys`, 778.82 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`; placement
estimates were 119.55 MHz `u_blu.i_clk_50`, 95.65 MHz `clk_sys`, 602.41 MHz
`clk_dq`, and 2500.00 MHz `clk_phy_x4`. The final `clk_sys` critical path
fell back to `rst_bram` through runtime FSM pattern-cache CE with 7.1 ns
routing. The request decode stage is conceptually correct for a larger
scheduler, but it should not be carried as a standalone timing fix.

An idle-prefetch transaction-register experiment in `ddr3_runtime` was tested
and reverted. The change continuously preloaded the visible WB address, data,
select, burst offset, one-hot, and byte-mask fields while the scheduler was
idle, then let the accept branch only start ACT. This removed the clean
baseline's `ref_pending -> rt_wb_stall -> runtime CE` critical path, but it
only moved the route bottleneck. The resettable-preload variant passed
`git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`,
`make -C ip/ddr3 sim-init sim-micron`, and `make -C ip/ddr3 formal DEPTH=20`.
The late-flat JSON target reported 11,496 cells / 2,638 estimated logic cells,
and the seed-1 late-flat route regressed to 163.03 MHz `u_blu.i_clk_50`,
122.37 MHz `clk_sys`, 684.46 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`, with
the final `clk_sys` path dominated by reset into a runtime SR input. A
resetless-preload follow-up also passed `git diff --check`, `make -C ip/ddr3
sim-runtime-addr`, `make -C ip/ddr3 sim`, and `make -C ip/ddr3 formal
DEPTH=20`, and it shrank synthesis to 11,337 cells / 2,543 estimated logic
cells with `ddr3_runtime` at 2,290 cells / 858 estimated logic cells. Route
still regressed versus the clean late-flat baseline: 163.40 MHz
`u_blu.i_clk_50`, 128.53 MHz `clk_sys`, 747.94 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`, again with a reset-dominated runtime SR path. This confirms
that merely moving transaction-register enables off the WB accept path is not
enough; the next structural step needs to reduce the reset/control fanout and
scheduler state boundary together.

A local runtime-reset handoff experiment in `ddr3_ctrl` was also tested and
reverted. The change held `ddr3_runtime` in reset until init completed, then
presented the runtime with `i_init_done=1'b1` so wide runtime logic no longer
depended directly on the init-done input. Fast checks passed:
`git diff --check`, `make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim`, and `make -C ip/ddr3 formal DEPTH=20`. The late-flat
hard-command synthesis image reported 11,480 cells / 2,629 estimated logic
cells, with `ddr3_runtime` at 2,360 cells / 903 estimated logic cells. The
seed-1 late-flat route regressed badly: final timing was 146.80 MHz
`u_blu.i_clk_50`, 121.08 MHz `clk_sys`, 594.88 MHz `clk_dq`, and 1557.63 MHz
`clk_phy_x4`. The final `clk_sys` critical path moved into CH1 runtime
`wait_ctr[4]` to pattern-cache/control CE routing. This is worse than the clean
late-flat baseline, so do not repeat local runtime reset handoff as a
standalone timing fix.

An opt-in `DDR3_SPLIT_ACCEPT_CE` experiment split the WB accept condition into
kept control/address/data register enables outside the main runtime FSM block.
The intent was to stop the external `o_wb_stall` feedback net from feeding
every transaction register CE at once while keeping the public Wishbone
contract unchanged. Fast checks passed with the define:
`make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`,
`make -C ip/ddr3 formal DEPTH=20`, and the same runtime address sim without
the define. The late-flat hard-command synthesis image reported 11,527 cells /
2,516 estimated logic cells, with `ddr3_runtime` at 2,365 cells / 837
estimated logic cells. Seed-1 late-flat route still regressed versus the clean
baseline: final timing was 151.40 MHz `u_blu.i_clk_50`, 117.08 MHz `clk_sys`,
806.45 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final `clk_sys`
critical path moved to `rst_bram` through runtime reset/SR routing with
8.1 ns route delay. Do not repeat split accept-CE duplication as a standalone
timing fix.

A two-process next-state rewrite of `ddr3_runtime` was tested and reverted.
The change moved the large runtime case body into a combinational next-state
block and kept a smaller clocked register-update block. Fast checks passed:
`git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`,
and `make -C ip/ddr3 formal DEPTH=20`. Synthesis looked attractive: the
late-flat hard-command image reported 4,878 hierarchy cells / 2,454 estimated
logic cells, with `ddr3_runtime` at 1,472 cells / 825 estimated logic cells.
Route timing did not follow. Seed-1 late-flat placement was already worse at
116.82 MHz `u_blu.i_clk_50`, 87.30 MHz `clk_sys`, 625.00 MHz `clk_dq`, and
2500.00 MHz `clk_phy_x4`; final route failed at 150.40 MHz `u_blu.i_clk_50`,
119.13 MHz `clk_sys`, 875.66 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The
slow-net list moved to broad `*_next` runtime nets such as `rd_armed_next`,
pattern-cache logic, and `saved_burst_word_offset`. This is lower synthesis
area but worse 200 MHz controller timing than the clean late-flat baseline, so
do not repeat a generic two-process FSM rewrite without a real scheduler
partition.

An opt-in `DDR3_CH1_LOCAL_CLOCKS` diagnostic was tested and reverted. It added
a single-outstanding Wishbone CDC bridge and ran the CH1 controller/calibration
logic from a second local PHY PLL instead of sharing CH0's `clk_sys`,
`clk_phy_x4`, and `clk_dq`. The first route failed with multiple default
`IDELAYCTRL` cells; after sharing CH0's IDELAYCTRL ready signal, the JSON image
reported 11,766 cells / 2,653 estimated logic cells, with 26 `BUFG`, 2
`PLLE2_ADV`, 1 `IDELAYCTRL`, and one `wb_cdc_single`. Seed-1 late-flat route
still failed: 148.06 MHz `u_blu.i_clk_50`, 130.28 MHz `clk_sys`,
140.94 MHz `ch1_clk_sys`, 726.22 MHz `clk_dq`, 662.69 MHz `clk_dq_ch1`, and
1557.63 MHz `clk_phy_x4`. Both controller domains still hit runtime
`wait_ctr[6]` through pattern-cache/control CE paths, and the high-speed DQ
domains lost the 800 MHz DDR3-1600 margin. Do not repeat CH1 local clocks as a
standalone timing split.

`make -C boards/ypcb-00338
full-2ch-ddr1600-serdescmd-jtagdirect-bitstream` adds a hard-command
direct-write diagnostic by combining `DDR3_SERDES_CMD` with
`DDR3_DIRECT_WRITE_NO_RMW`. This removes the normal BL8 RMW merge and writes
only the selected 32-bit word inside the burst, so it must not be treated as a
validation image. With the reset-split tree, seed 1 still fails timing at
137.97 MHz `u_blu.i_clk_50`, 108.72 MHz `clk_sys`, 677.51 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. That rules out the RMW write merge as the sole
current blocker; the full path still needs a structural read-capture/control
split.

A hard-command-only `DDR3_DISABLE_MPR_RUNTIME` diagnostic that pruned the
runtime MPR read states was tested and reverted. Default
`make -C ip/ddr3 sim-runtime-addr` still passed, and the pruned
`full-2ch-serdescmd-json` image synthesized to 13,481 cells / 3,185 estimated
logic cells. The seed-1 hard-command JTAG-only route still failed at
142.35 MHz for `u_blu.i_clk_50`, 119.83 MHz for `clk_sys`, 890.47 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. The small timing gain is not worth
the diagnostic-only build split and higher LUT pressure; the slow-net list
moved to reset/VCC/runtime state, burst-offset, lane `i_rd_capture`, and
lane-local write strobes.

Predecoding the BL8 read-sample select into a saved 8-bit one-hot was also
tested and reverted. It passed `make -C ip/ddr3 sim-runtime-addr`, and
`full-2ch-serdescmd-json` synthesized, but it grew the hard-command image to
13,674 cells / 3,227 estimated logic cells. The seed-1 hard-command JTAG-only
route regressed to 125.08 MHz for `u_blu.i_clk_50`, 110.73 MHz for `clk_sys`,
774.59 MHz for `clk_dq`, and 1557.63 MHz for `clk_phy_x4`. The new one-hot
nets became visible in the slow-net list at 64 sinks each, so the change adds
fanout without solving the 200 MHz controller-clock blocker.

A hard-command-only PHY reset fanout split was also tested and reverted. The
experiment kept the validated non-serialized path unchanged and inserted kept
`LUT1` reset copies for the CK, command-shadow, command-SERDES, and lane reset
paths under `DDR3_SERDES_CMD`. `full-2ch-serdescmd-json` synthesized to 13,572
cells / 3,152 estimated logic cells, slightly smaller than the current
checkpoint, but the paired seed-1 hard-command JTAG-only route still failed at
127.26 MHz for `u_blu.i_clk_50`, 116.78 MHz for `clk_sys`, 798.72 MHz for
`clk_dq`, and 1557.63 MHz for `clk_phy_x4`. Since the route does not improve
the controller-clock blocker and also loses the current `clk_dq` margin, the
split is not worth keeping as-is.

A `DDR3_REGISTERED_WAIT_DONE` experiment in `ddr3_runtime` was also tested and
reverted. The change registered long JEDEC wait expirations before state
transitions so shared `wait_ctr` equality logic would not feed runtime control
enables in the same cycle. Fast checks passed with the define:
`make -C ip/ddr3 sim-runtime-addr`,
`make -C ip/ddr3 sim`, and
`make -C ip/ddr3 formal DEPTH=20`. The late-flat hard-command synthesis image
reported 4,880 hierarchy cells / 2,515 estimated logic cells, with
`ddr3_runtime` at 1,473 cells / 848 estimated logic cells. Route timing did not
follow: the seed-1 late-flat route regressed to 142.43 MHz `u_blu.i_clk_50`,
111.67 MHz `clk_sys`, 755.86 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The
final `clk_sys` critical path moved from JTAG address/channel decode through
CH1 runtime pattern-cache/state CE routing. This loses both controller timing
and the DDR3-1600 `clk_dq` margin, so do not repeat registered wait expiry as a
standalone timing fix.

A `DDR3_JTAG_DDR_ONLY_PIPELINED` top-level diagnostic was also tested and
reverted. The change added a one-entry request stage between JTAG/Wishbone and
the DDR3-only fabric bus, keeping the default no-define late-flat image
unchanged. The opt-in late-flat JSON image synthesized to 4,876 hierarchy cells
/ 2,517 estimated logic cells, but route timing moved backward: the seed-1
late-flat route ended at 143.76 MHz `u_blu.i_clk_50`, 104.62 MHz `clk_sys`,
794.28 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final `clk_sys`
critical path became top-level JTAG grant/address decode into CH1 runtime
burst-byte-mask/pattern logic, with 1.0 ns logic and 8.6 ns routing. This loses
controller-clock timing and drops below the DDR3-1600 `clk_dq` target, so do
not repeat JTAG-only request pipelining as a standalone timing fix.

A `DDR3_NATIVE_BL8_DIAG` full-burst diagnostic, inspired by LiteDRAM/UberDDR3
style native burst interfaces, was also tested and reverted. The opt-in build
forced `WB_BURST_WORD_BITS=0`, widened the controller-facing Wishbone data
path to `DDR3_PHY_DATA_W`, replicated each 32-bit JTAG write across the full
BL8 payload at the top-level adapter, and bypassed the runtime's 16-way
word-offset/RMW selector. The experiment passed `git diff --check`,
`make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`, the default
no-define late-flat JSON build, and the opt-in native-BL8 late-flat JSON build.
The opt-in image synthesized to 4,226 hierarchy cells / 2,514 estimated logic
cells, with `ddr3_runtime` at 1,151 cells / 850 estimated logic cells, versus
4,866 hierarchy cells / 2,514 estimated logic cells for the default image.
Route timing moved sharply backward: the seed-1 native-BL8 late-flat route
failed at 129.42 MHz `u_blu.i_clk_50`, 83.31 MHz `clk_sys`, 634.92 MHz
`clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final `clk_sys` critical path was
almost entirely routing, from `jwb_grant` through `bram_dat_w[7]` into CH1
runtime state, with 0.4 ns logic and 11.6 ns routing. The slow-net list still
showed global reset/VCC pressure plus 539-sink runtime pattern-cache nets in
both controllers. Do not repeat this as a simple width-adapter diagnostic; a
future native-burst direction needs a real registered bridge/FIFO or cacheline
boundary instead of fanning a 32-bit JTAG word across the full PHY payload.

A second native-BL8 bridge diagnostic was tested and reverted. This split the
controller into a 32-bit Wishbone-to-BL8 adapter plus a native full-BL8 runtime,
with the runtime owning only ACT/RD/WR/PRE, refresh, MPR, and MRS sequencing.
The architectural boundary is closer to the LiteDRAM/UberDDR3 direction, and
`make -C ip/ddr3 sim-init DDR3_DEFINES="-DDDR3_BL8_BRIDGE"` plus
`make -C ip/ddr3 sim-micron DDR3_DEFINES="-DDDR3_BL8_BRIDGE"` passed. Cocotb
aborted in the simulator/VPI startup path (`Abort trap: 6`), so it provided no
useful behavioral evidence. The opt-in late-flat JSON image synthesized to
15,379 cells / 3,324 estimated logic cells, with `ddr3_runtime_bl8` alone at
2,848 cells / 600 estimated logic cells; packing used 6,099 LUTs, 9,272 FFs,
178 `OSERDESE2`, 16 `IDELAYE2`, 6 `IDELAYCTRL`, 22 `BUFGCTRL`, and 16
`RAMB36E1`. Seed-1 late-flat route regressed to 168.29 MHz
`u_blu.i_clk_50`, 108.13 MHz `clk_sys`, 423.91 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. Router slow-net output showed the bridge's dynamic
full-burst word extraction/merge functions creating wide `$shiftx`/mux logic
around `burst_put_word`, `saved_word_offset`, and `saved_sel`. Do not carry
this bridge as-is; if revisiting the native-burst boundary, replace the dynamic
512-bit word mux/merge functions with static per-word buffer banks or generated
lane/sample muxes before spending more route time.

A full-width CH0-only DDR3-1600 hard-command isolation route was also run to
separate per-channel timing from dual-channel congestion. The seed-1
`bonetto_soc_ypcb00338_full_ch0_ddr1600_serdescmd_jtagonly` image used the
online CH0 pin map, `DDR3_FULL_CH0`, `DDR3_RATE_1600`, `DDR3_JTAG_ONLY`,
`DDR3_SERDES_CMD`, `-abc9`, and the late flatten pass. Route still failed at
183.35 MHz `u_blu.i_clk_50`, 154.77 MHz `clk_sys`, 783.09 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. This shows dual-channel duplication and congestion
cost roughly 27 MHz of `clk_sys` versus the current full-2ch hard-command
checkpoint, but one full-width channel still misses both the 200 MHz controller
target and the DDR3-1600 DQ target. The next useful work is therefore not a
pure two-channel floorplan tweak; the per-channel runtime/PHY-control boundary
also needs to be shortened.

A broader `DDR3_DISABLE_RUNTIME_MPR_MRS` diagnostic that pruned both runtime
MPR and MRS pending latches was tested and reverted. Default and opt-in
`make -C ip/ddr3 sim-runtime-addr` checks passed. The clean late-flat JSON
image reported 4,874 hierarchy cells / 2,452 estimated logic cells, while the
opt-in no-MPR/MRS JSON image reported 4,846 hierarchy cells / 2,504 estimated
logic cells, so the small cell-count drop did not translate into lower LUT
pressure. Seed-1 late-flat route regressed badly: final timing was
149.68 MHz `u_blu.i_clk_50`, 112.16 MHz `clk_sys`, 667.56 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The `clk_sys` critical path was top-level JTAG
grant/address decode into CH1 runtime `burst_byte_mask` logic, with 1.0 ns
logic and 7.9 ns routing. This confirms calibration-latch pruning is not a
standalone timing fix for the 1:4 DDR3-1600 target.

An opt-in `DDR3_MICRO_RUNTIME` diagnostic was tested and reverted. It cloned
the runtime into a one-hot microsequenced implementation while preserving the
default runtime and the public `ddr3_ctrl` port contract. `git diff --check`,
default `make -C ip/ddr3 sim-runtime-addr`, and
`make -C ip/ddr3 sim-init DDR3_DEFINES=-DDDR3_MICRO_RUNTIME` passed. The
late-flat micro JSON image was much larger than the default late-flat image:
11,810 hierarchy cells / 3,885 estimated logic cells overall, with
`ddr3_runtime_micro` alone at 2,506 cells / 1,513 estimated logic cells. Seed-1
late-flat route also regressed: final timing was 148.81 MHz
`u_blu.i_clk_50`, 114.78 MHz `clk_sys`, 769.23 MHz `clk_dq`, and
1557.63 MHz `clk_phy_x4`. The `clk_sys` critical path still stayed inside CH1
runtime control, from `wait_ctr[7]` through synthesized state-decision logic,
with 1.2 ns logic and 7.5 ns routing. This rules out a local one-hot clone of
the existing FSM as the next step; a useful LiteDRAM/UberDDR3-style direction
needs a real registered scheduler/data pipeline boundary, not a wider encoding
of the same control cone.

A kept-hierarchy `ddr3_read_capture` helper diagnostic was tested and reverted.
The intent was to move the full BL8 read-data capture and valid-arming logic
out of the main runtime FSM without changing the `ddr3_ctrl` port contract.
After fixing a first-cycle start-pulse bug, the default `sim-runtime-addr`
check and `make -C ip/ddr3 sim` passed. The late-flat helper JSON stayed in
range at about 11,509 cells / 2,512 estimated logic cells, and Yosys preserved
the helper through flatten. Route timing still regressed. With `o_data` masked
by `seen`, seed-1 late-flat route ended at 157.55 MHz `u_blu.i_clk_50`,
113.75 MHz `clk_sys`, 706.71 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`;
`rd_cap_seen` became a 516-sink mux-control net. Clearing the wide data
register on read start improved only to 122.67 MHz `clk_sys` and 728.33 MHz
`clk_dq`, with reset/clear routing into the helper's wide register. Removing
the wide data reset/clear reached 171.32 MHz `u_blu.i_clk_50`, 124.69 MHz
`clk_sys`, 603.86 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. This confirms
that wrapping the existing read capture in its own module is not the needed
boundary; the next cut has to change ownership and placement of the full-burst
buffer and command scheduler rather than only where the current capture flops
are declared.

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

## DDR3-1600 Timing Diagnostics

The current full-capacity target is still the dual-channel DDR3-1600
hard-command JTAG-only late-flatten build: 200 MHz `clk_sys`, 800 MHz `clk_dq`,
and 1600 MT/s data on both 64-bit channels. Seed 1 is the comparison seed unless
otherwise noted.

- Rebuilding the clean late-flatten source after the BL8 bridge diagnostics gave
  4,876 total cells / 2,517 estimated LCs after synthesis. The route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lateflat_clean_reroute_seed1_route.log`
  failed at 143.76 MHz `u_blu.i_clk_50`, 104.62 MHz `clk_sys`,
  794.28 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The top `clk_sys`
  path ran from the JTAG/BRAM address accept path into the runtime's
  64-bit saved BL8 byte-mask register.
- Removing the runtime's saved 64-bit BL8 byte-mask register and deriving the
  RMW replacement bit from the saved one-hot word offset plus saved byte select
  reduced synthesis to 4,746 total cells / 2,388 estimated LCs. The route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lateflat_nomask_seed1_route.log`
  still failed timing, but improved to 156.59 MHz `u_blu.i_clk_50`,
  126.31 MHz `clk_sys`, 803.86 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`.
  The new top `clk_sys` path is CH1 runtime wait-counter/state-enable logic,
  and the slow-net list is dominated by runtime state and saved BL8 select
  fanout rather than the old byte-mask accept path.
- Splitting the captured BL8 read buffer into its own narrow-enable always
  block, removing the reset/clear on that 512-bit data register, and refusing
  to launch an RMW write after a read-timeout miss passed `git diff --check`,
  `make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`, and the late-flat
  JSON synthesis gate. Synthesis reported 3,736 total cells / 2,388 estimated
  LCs, with `ddr3_runtime` at 901 cells / 825 estimated LCs. The seed-1 route
  log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lateflat_rdcapfire_seed1_route.log`
  still failed timing, but moved `clk_sys` forward to 136.20 MHz and restored
  high-speed margin to 970.87 MHz `clk_dq`; final route timing was 146.61 MHz
  `u_blu.i_clk_50`, 136.20 MHz `clk_sys`, 970.87 MHz `clk_dq`, and
  1557.63 MHz `clk_phy_x4`. The remaining slow nets are now the global
  `rd_capture_fire` enable at 513 sinks per channel plus `rst_bram` and saved
  word/select fanout, so the next useful experiment is localizing or
  partitioning those enables rather than adding more data muxing.
- Making the board-level `clk_sys` reset replicas physically distinct with
  small release pipes passed `git diff --check` and the same late-flat JSON
  synthesis gate. Synthesis reported 3,729 total cells / 2,386 estimated LCs,
  with `ddr3_runtime` at 900 cells / 825 estimated LCs. The seed-1 route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lateflat_resetpipe_seed1_route.log`
  still failed timing, but improved the main DDR controller path to
  143.12 MHz `clk_sys` and 984.25 MHz `clk_dq`; final route timing was
  134.32 MHz `u_blu.i_clk_50`, 143.12 MHz `clk_sys`, 984.25 MHz `clk_dq`,
  and 1557.63 MHz `clk_phy_x4`. The top `clk_sys` critical path moved off
  `rst_bram` and onto runtime `beat_ctr`/FSM clock-enable routing, which makes
  this useful progress for the 200 MHz controller target despite the worse
  diagnostic JTAG/50 MHz clock estimate.
- Narrowing the runtime `beat_ctr` to the exact read-timeout width passed
  `git diff --check`, `make -C ip/ddr3 sim-runtime-addr`, `make -C ip/ddr3 sim`,
  and the late-flat JSON synthesis gate. Synthesis reported 3,705 total cells /
  2,392 estimated LCs, with `ddr3_runtime` at 893 cells / 826 estimated LCs.
  The seed-1 route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lateflat_beatw_seed1_route.log`
  still failed timing, but nudged `clk_sys` to 143.97 MHz and recovered the
  diagnostic `u_blu.i_clk_50` path to 175.13 MHz. Final route timing was
  175.13 MHz `u_blu.i_clk_50`, 143.97 MHz `clk_sys`, 820.34 MHz `clk_dq`, and
  1557.63 MHz `clk_phy_x4`. The tradeoff is reduced DQ margin, though it still
  clears the DDR3-1600 800 MHz intent. The new `clk_sys` critical path is now
  CH1 init-done/stall propagation into the JTAG Wishbone CE, so the next
  structural lever is a registered stall/accept boundary.
- Moving the JTAG Wishbone parser back to `clk_50` and adding an opt-in
  single-outstanding CDC bridge into `clk_sys` was tested and reverted. The
  bridge did remove the old direct JTAG CE path, but it added 419 CDC
  flip-flops and damaged placement enough that seed-1 route regressed badly.
  The route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagcdc_lateflat_seed1_route.log`
  failed at 136.15 MHz `jwb_master_clk` (the 50 MHz JTAG parser clock still
  checked against the global 200 MHz constraint), 106.78 MHz `clk_sys`,
  520.29 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. Do not repeat this as a
  standalone timing fix; the accept/stall cut needs to be local to the DDR3
  scheduler/runtime path, not a top-level debug bridge.
- Registering the JTAG Wishbone master's view of `i_wb_stall` with an opt-in
  `DDR3_JTAG_REGISTER_STALL` / `JTAG_WB_REGISTER_STALL` diagnostic was also
  tested and reverted. The change kept default behavior unchanged and passed
  `make -C ip/jtag-uart/sim -f Makefile.jwb`,
  `JTAG_WB_DEFINES=-DJTAG_WB_REGISTER_STALL make -C ip/jtag-uart/sim -f
  Makefile.jwb SIM_BUILD=sim_build_jwb_regstall`, and `make -C ip/ddr3
  sim-runtime-addr sim`. It removed the immediate combinational stall sample
  from the JTAG master, but placement and route regressed badly:
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_regstall_lateflat_seed1_route.log`
  reported final timing of 147.71 MHz `u_blu.i_clk_50`, 123.99 MHz `clk_sys`,
  531.63 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. This confirms the local
  stall sampler is another placement perturbation, not a useful route to the
  200 MHz controller target.
- Registering runtime ownership one command-clock cycle after init and
  replacing the fast full-width read-select helper with the existing static
  one-hot read word selector were tested and reverted. The registered-init
  variant passed `make -C ip/ddr3 sim-runtime-addr sim-init` and `make -C
  ip/ddr3 sim`, but route only nudged `clk_sys` to 144.63 MHz while dropping
  `clk_dq` below the DDR3-1600 intent at 781.25 MHz; see
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_rtinitq_lateflat_seed1_route.log`.
  The combined registered-init/static-read route recovered DQ margin at
  901.71 MHz but regressed `clk_sys` to 140.96 MHz; see
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_rtinitq_staticrd_lateflat_seed1_route.log`.
  The static-read variant alone was worse at 113.28 MHz `clk_sys` and
  706.71 MHz `clk_dq`; see
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_staticrd_lateflat_seed1_route.log`.
  Do not keep these local read-select/init-release reshapes; they confirm the
  next useful split has to change the scheduler/runtime ownership boundary
  rather than only moving individual muxes or init gating.
- Adding an opt-in one-entry same-clock JTAG-to-DDR Wishbone queue in the board
  top was tested and reverted. It captured `jwb_adr`, `jwb_addr_hi_echo`, write
  data, and byte enables before driving the DDR path, but this moved the
  bottleneck rather than improving placement. The seed-1 route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_wbq_lateflat_seed1_route.log`
  reported final timing of 125.11 MHz `u_blu.i_clk_50`, 143.43 MHz `clk_sys`,
  576.37 MHz `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The top `clk_sys`
  critical path still started at `jwb_adr[14]` and reached CH1 runtime enable
  logic through `d3_stb`, while `clk_dq` margin collapsed. Do not repeat this
  as a board-top queue; the next useful cut needs to be inside the DDR
  controller/scheduler boundary.
- Removing the post-init gate from the Wishbone stall cone with an opt-in
  diagnostic parameter was tested and reverted. Default `make -C ip/ddr3
  sim-runtime-addr sim` still passed, but the seed-1 route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_noinitstall_lateflat_seed1_route.log`
  regressed to 159.77 MHz `u_blu.i_clk_50`, 136.33 MHz `clk_sys`, 436.87 MHz
  `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The final `clk_sys` critical path
  moved to `saved_sel[2]` through `o_wr_data[136]` into a PHY lane flop with
  6.9 ns routing, so the init-done appearance in the previous critical path
  was not a safe standalone timing target.
- Duplicating the saved Wishbone byte enables into lane-local select flops was
  tested and reverted. The intent was to reduce the `saved_sel` fanout exposed
  by the no-init-stall diagnostic without reintroducing a full-width byte mask.
  Default `make -C ip/ddr3 sim-runtime-addr sim` passed, but the seed-1 route
  log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_lanesel_lateflat_seed1_route.log`
  reported 182.92 MHz `u_blu.i_clk_50`, 137.23 MHz `clk_sys`, 972.76 MHz
  `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The DQ margin improved, but the
  controller clock regressed below the 143.97 MHz late-flat baseline. The
  final `clk_sys` critical path was still JTAG/Wishbone grant/strobe into CH1
  runtime CE, with 1.4 ns logic and 5.9 ns routing. Do not repeat this as a
  standalone byte-enable fix; any write-data fanout work needs to be paired
  with a scheduler/runtime command boundary split.
- Adding an opt-in same-clock Wishbone request buffer inside `ddr3_runtime`
  and skipping reset on the wide saved/read data registers under that same
  option is the current best late-flat timing diagnostic. The kept RTL is gated
  by `DDR3_RUNTIME_REQ_BUFFER`, and the board target
  `full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-nrdata-lateflat-bitstream`
  reproduces the seed-1 build. Default `make -C ip/ddr3 sim-runtime-addr sim`
  and opt-in `make -C ip/ddr3 DDR3_DEFINES="-DDDR3_RUNTIME_REQ_BUFFER" sim-runtime-addr sim`
  both passed. The route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_reqbuf_nrdata_lateflat_seed1_route.log`
  still fails the 200 MHz controller target, but improves the main DDR clocks
  over the previous 143.97 MHz / 820.34 MHz late-flat baseline: final timing is
  151.88 MHz `u_blu.i_clk_50`, 149.37 MHz `clk_sys`, 958.77 MHz `clk_dq`, and
  1557.63 MHz `clk_phy_x4`. The new `clk_sys` critical path is
  `saved_sel[0]` into `o_wr_data[9]` / the PHY write-data flop, with 0.4 ns
  logic and 6.3 ns routing. A combined request-buffer plus lane-local select
  experiment passed the same simulations but regressed route timing to
  168.35 MHz `u_blu.i_clk_50`, 116.63 MHz `clk_sys`, 826.45 MHz `clk_dq`, and
  1557.63 MHz `clk_phy_x4`; keep the request buffer, but do not reintroduce
  lane-select duplication as the next lever.
- Registering the merged full-BL8 write payload inside `ddr3_runtime` one
  controller cycle before the WRITE command was tested and reverted. The intent
  matched the staged write-data sideband used by DFI-style designs, but it
  perturbed placement badly in this netlist. Opt-in `make -C ip/ddr3
  DDR3_DEFINES="-DDDR3_RUNTIME_REQ_BUFFER -DDDR3_RUNTIME_WR_DATA_REG"
  sim-runtime-addr sim` passed, but the seed-1 route log
  `boards/ypcb-00338/build/full_2ch_ddr1600_serdescmd_jtagonly_reqbuf_wrdatareg_lateflat_seed1_route.log`
  regressed to 162.34 MHz `u_blu.i_clk_50`, 124.63 MHz `clk_sys`, 764.53 MHz
  `clk_dq`, and 1557.63 MHz `clk_phy_x4`. The critical path moved back to
  JTAG/Wishbone grant/strobe through CH1 `wb_req_fire` into a request-buffer
  clock enable, while DQ fell below the DDR3-1600 800 MHz intent. Do not keep
  this as a one-register write-data staging fix.

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
| Dual-channel DDR3-1600 hard-command direct-write diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-jtagdirect-bitstream` isolates no-RMW writes under the hard-command path |
| Dual-channel DDR3-1600 request-buffer diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-nrdata-lateflat-bitstream` is the current best seed-1 route, still failing at 149.37 MHz `clk_sys` |
| Dual-channel DDR3-1600 hard-command DDR-only diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-ddronly-bitstream` removes BRAM/decode but still fails timing with seed 1 |
| Dual-channel DDR3-1600 hard-command/ISERDES diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream` still hits the ISERDES overuse plateau |
| Dual-channel DDR3-1600 direct-write diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-jtagdirect-bitstream` isolates the old no-RMW write path |
| CH0 64-bit DDR3-800 | currently fails direct hardware validation at address zero |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
