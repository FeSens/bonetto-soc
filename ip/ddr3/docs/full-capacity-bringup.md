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
| Dual-channel DDR3-1600 hard-command direct-write diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-jtagdirect-bitstream` isolates no-RMW writes under the hard-command path |
| Dual-channel DDR3-1600 hard-command DDR-only diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-ddronly-bitstream` removes BRAM/decode but still fails timing with seed 1 |
| Dual-channel DDR3-1600 hard-command/ISERDES diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream` still hits the ISERDES overuse plateau |
| Dual-channel DDR3-1600 direct-write diagnostic | `make -C boards/ypcb-00338 full-2ch-ddr1600-jtagdirect-bitstream` isolates the old no-RMW write path |
| CH0 64-bit DDR3-800 | currently fails direct hardware validation at address zero |
| CH1 64-bit DDR3-800 | same checks on the second channel |
| Dual-channel address map | boundary tests across the channel-select bit and top-of-memory |
| DDR3-1600 timing | routed timing for `clk_sys`, CK, DQ/DQS domains at the full-rate target |
| DDR3-1600 hardware | same direct JTAG/Wishbone validation plus timed soak on both channels |
