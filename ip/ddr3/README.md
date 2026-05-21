# ddr3

Clean-sheet DDR3 controller workspace for Bonetto SoC.

The previous controller/PHY RTL was intentionally removed. Keep this directory
small and verification-first until the new design has a proven command core,
Micron-model simulation, and hardware evidence at each speed step.

The active board-level hardware baseline now has four YPCB-00338 pre-PHY
gates, two timing-clean full-bus route-only DQ/DQS probes, experimental
SERDES route probes, a route-only controller-to-SERDES full x9 dual-channel
image, a live init-only controller-to-SERDES full x9 image with DDR Wishbone
blocked, and one explicitly marked timing-failed PHY-clock experiment. The
line-controller
loopback keeps the BRAM-only JTAG/Wishbone proof alive and
routes traffic through the clean dual-channel line controller. The line-to-lane
loopback inserts the reusable `ddr3_line_to_lanes` RTL between the line
controller and internal lane memories. The command-probe image drives the board
command/reset/CKE/ODT/address pins. The command plus line-to-lane image combines
those board command pins with the reusable lane adapter and internal lane
memories. The DQ/DQS I/O-shell probe proves the full-pin 7-series ODDR/IDDR
and IOBUF/IOBUFDS shell can route at the 400 MHz DDR3-800 bit-clock target with
the DDR3 devices held in reset. The burst route probe puts one
`ddr3_x8_burst_io_sequencer` per physical byte lane in front of that shell, using
the sequencer's route-only fast-accept branch so the full board pinout is timed
with local BL8 write-launch traffic. The SERDES probe instantiates the
board-local OSERDESE2/ISERDESE2/IDELAYE2 x8 shell with a 200 MHz IDELAY
reference clock, IDELAYCTRL, a shared `DDR3_SERDES_PROBE` IODELAY group, and
LiteDRAM/UberDDR3-style SERDES clocking and tri-state parameters. The tight CH0
lane-0 bidirectional DDR3-800 diagnostic preserves 9 OSERDESE2, 9 ISERDESE2,
and 9 IDELAYE2 cells but stalls with fixed router2 overuse 18. The same netlist
routes and generates a bitstream with router1 at the 400 MHz route target, with
post-route `clk_idelay_ref` reported at 791.14 MHz and `clk_sys` at 1557.63
MHz. The full CH0 and CH1 SERDES probes also route independently with router1,
each preserving 81 OSERDESE2, 81 ISERDESE2, and 81 IDELAYE2 cells. CH0 reports
post-route `clk_idelay_ref` at 713.78 MHz and CH1 reports 781.86 MHz, both with
`clk_sys` at 1557.63 MHz against the 400 MHz target. The complete CH0+CH1
target now routes and generates a bitstream with router1 while preserving
162 OSERDESE2, 162 ISERDESE2, 162 IDELAYE2, and 6 IDELAYCTRL cells; post-route
timing reports `clk_idelay_ref` at 683.53 MHz and `clk_sys` at 1557.63 MHz. The
same complete target still stalls with router2 at overuse 324, so router
selection is currently part of the evidence. The controller-to-SERDES image
wires `ddr3_ctrl_line` through `ddr3_line_serdes_phy` into the board-local
OSERDESE2/ISERDESE2/IDELAYE2 shell across all x9 lanes on both channels while
holding DDR3 reset active and CKE low. The 2026-05-20 seed-1 router1 target
generates a bitstream with 162 OSERDESE2, 162 ISERDESE2, 162 IDELAYE2, 144 DQ
IOBUF, 18 DQS IOBUFDS, and 6 IDELAYCTRL cells. Post-route reports `SYS_CLK` at
58.09 MHz, `clk_sys` at 103.70 MHz, `clk_idelay_ref` at 792.39 MHz, and
`clk_dq`/`clk_ddr` at 1557.63 MHz. This target uses nextpnr's global frequency
check at the real 50 MHz board clock, then records the generated clock maxima;
using one global 400 MHz check falsely fails the slow controller/JTAG clocks.
The live SERDES init-only image enables DDR3 reset/CKE/ODT/CK/address/command
pins and keeps the full x9 SERDES/IDELAY shell on both channels, but blocks DDR
Wishbone accesses until calibrated storage traffic exists. It also includes a
debug raw SERDES capture bridge that snapshots the selected physical lane's
DQ[63:0] and DQS[7:0] ISERDES bits when a host IDELAY load command reaches
`clk_sys`. The 2026-05-20 router1 bitstream preserves 162 OSERDESE2,
162 ISERDESE2, 162 IDELAYE2, 144 DQ IOBUF, 18 DQS IOBUFDS, and 6 IDELAYCTRL
cells; post-route reports `SYS_CLK` at 113.53 MHz, `clk_sys` at 65.00 MHz,
`clk_idelay_ref` at 734.21 MHz, `clk_dq` at 668.90 MHz, and `clk_ddr` at
1557.63 MHz against the 50 MHz board-clock target. After a physical replug, the
image programmed successfully and `validate-ddr3-ctrl-line-serdes-init` passed
with DDR Wishbone blocked. Direct and legacy-mapped IDELAY load checks both
updated request/seen counters and the raw SERDES capture status; the idle
init-only DQ/DQS snapshots read back as zero.
The same tight lane routes and generates bitstreams when split into TX-only
OSERDESE2/IOBUF/IOBUFDS or RX-only IDELAYE2/ISERDESE2/IOBUF/IOBUFDS
diagnostics, both at the 400 MHz route target. The tight no-IDELAY
bidirectional diagnostic also routes and generates a bitstream with 9
OSERDESE2, 9 ISERDESE2, 0 IDELAYE2, and post-route `clk_sys` at 1557.63 MHz
against the 400 MHz target. Those diagnostics show the primitive topology is
usable, but router2 cannot currently finish the combined bidirectional SERDES
plus IDELAYE2 topology: lane0 stalls at overuse 18 and the full dual-channel
target stalls at overuse 324. A split-buffer experiment using separate
`OBUFT`/`IBUF` primitives is not a valid workaround in this openXC7/nextpnr
flow: nextpnr rejects shared top-level DDR3 pads before route, so the canonical
`IOBUF`/`IOBUFDS` representation remains the usable model. The D88 PHY-clock
bridge experiment is retained only as evidence that wide soft line/lane timing
fabric does not belong in that
bit-clock domain. External DDR3 storage is still not validated.

## Status

| Area | State |
|---|---|
| Controller RTL | Full-capacity two-channel address decoder, DDR3-800 init sequencer, temporary single-bank command slices, one-bank row/timing machine, global scheduler timing/refresh slice, periodic refresh requester, controller-side x8 BL8 byte-lane packetizer, full 64-bit-channel BL8 line packetizer, line-to-x8-lane adapter, line-to-x8-burst adapter, explicit x8-data to x9-physical spare-lane adapter, x8 lane PHY timing core, fast-domain x8 burst I/O sequencer, x8 SERDES-domain BL8 lane adapter, x8 burst clock bridge, line-to-fast-burst PHY shell, line-to-SERDES PHY shell, line-to-lane PHY timing bridge, controller-to-PHY line clock bridge, board-local DQ/DQS ODDR/IDDR/IOBUF shell probe, single-outstanding line-level Wishbone bridge, line-backed Wishbone-to-full-channel bridge, dual-channel Wishbone dispatch bridge, single-channel BL8 scheduler adapter, and an init-gated dual-channel controller shell; no timing-clean calibrated read/write PHY yet |
| Formal | Live full-capacity address-map proof, command timing monitor self-check, init sequencer proof, single-read proof, single-write/read proof, bank-machine proof, scheduler timing/refresh proof, periodic idle-refresh proof, bounded active-traffic refresh proof, byte-lane packet proof, full-channel line packet proof, line-to-x8-lane adapter proof, line-to-x8-burst adapter proof, x8-data to x9-physical adapter proof, x8 lane PHY timing-core proof, fast-domain x8 burst I/O sequencer proof, x8 SERDES-domain BL8 lane-adapter proof, x8 burst clock-bridge proof, line-to-fast-burst PHY-shell proof, line-to-SERDES PHY-shell proof, line-to-lane PHY bridge proof, controller-to-PHY line clock bridge proof, IDELAY calibration command CDC proof, raw SERDES capture CDC proof, Wishbone frontend proof, line-level Wishbone proof including no-DM read-modify-write mode, Wishbone-to-channel bridge proof, dual-channel dispatch proof, BL8 line scheduler-adapter proof, and controller init-gate proof |
| Simulation | Live full-capacity address-map unit test, Micron DDR3 model smoke, byte-lane unit test, full-channel line unit test, line-to-x8-lane adapter unit test, line-to-x8-burst adapter unit test, x8-data to x9-physical adapter unit test, x8 lane PHY timing-core unit test, fast-domain x8 burst I/O sequencer unit test, x8 SERDES-domain BL8 lane-adapter unit test, x8 burst clock-bridge dual-clock unit test, line-to-fast-burst PHY shell unit test, line-to-SERDES PHY shell unit test with two x9 channels, line-to-lane PHY bridge unit test, controller-to-PHY line clock bridge dual-clock unit test, IDELAY calibration command CDC dual-clock unit test, raw SERDES capture CDC dual-clock unit test, Wishbone frontend unit test, Wishbone-to-channel bridge unit test, line-level Wishbone unit tests for mask-preserving and no-DM read-modify-write modes, dual-channel dispatch unit test, BL8 line scheduler-adapter unit test, init-gated dual-channel controller unit test, reference init, RTL init, RTL single-read command, x8 write/read loopback using the byte-lane packetizer, reusable x8 DQS/DQ/DM timing-agent coverage, and dual-channel full-width controller loopback through sixteen Micron x8 models |
| Reference notes | LiteDRAM/UberDDR3 lessons captured in `docs/learning-notes.md` |
| Active hardware gate | YPCB-00338 JTAG/Wishbone BRAM proof plus DDR3 line-controller loopback, line-to-lane loopback, command-probe, command plus line-to-lane loopback, route-only full-pin DQ/DQS I/O-shell timing proof, route-only full-pin x8 burst/DQ/DQS timing proof, route-only full dual-channel SERDES/IDELAY timing proof through router1, route-only full x9 controller-to-SERDES board wiring proof through router1, and hardware-validated live SERDES init-only status/blocked-DDR/IDELAY-load/raw-capture gate; D88 PHY-clock bridge is debug evidence only and its program target is refused by default because it misses the 400 MHz bit-clock target; not external DDR3 storage |

## Live Gates

Run these from the repo root:

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
make -C ip/ddr3 sim-line-to-bursts formal-line-to-bursts
make -C ip/ddr3 sim-x8-burst-io-sequencer formal-x8-burst-io-sequencer
make -C ip/ddr3 sim-x8-serdes-burst-lane formal-x8-serdes-burst-lane
make -C ip/ddr3 sim-x8-burst-clock-bridge formal-x8-burst-clock-bridge
make -C ip/ddr3 sim-line-burst-phy formal-line-burst-phy
make -C ip/ddr3 sim-line-serdes-phy formal-line-serdes-phy
make -C ip/ddr3 sim-idelay-cal-cdc formal-idelay-cal-cdc
make -C ip/ddr3 sim-serdes-capture-cdc formal-serdes-capture-cdc
make validate-jtag-bram BOARD=ypcb-00338
make -C boards/ypcb-00338 ddr3-ctrl-line-loopback-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-loopback-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-loopback
make -C boards/ypcb-00338 ddr3-ctrl-line-laneloop-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-laneloop-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-laneloop
make -C boards/ypcb-00338 ddr3-ctrl-line-cmdprobe-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdprobe-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdprobe
make -C boards/ypcb-00338 ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdlaneloop-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdlaneloop
make -C boards/ypcb-00338 ddr3-dq-dqs-iobuf-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-burst-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-ch0-router1-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-ch1-router1-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-dq-dqs-serdes-router1-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-ctrl-line-serdes-router1-ddr800-bitstream
make -C boards/ypcb-00338 ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-serdes-init-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-serdes-init
```

Debug-only artifact:

```sh
make -C boards/ypcb-00338 ddr3-ctrl-line-phyclkloop-ddr800-bitstream
```

The matching `program-ddr3-ctrl-line-phyclkloop-ddr800` target is refused by
default. It is a timing-failed D88 experiment, not a validation gate.

What these mean today:

- `formal` proves the full-capacity address map for two 64-bit channels and
  proves the reusable DDR3 command timing monitor against a legal
  trace and proves the controller-owned init sequencer emits reset, MRS, ZQCL,
  REF, and post-DLL-lock wait in order with minimum waits. It also proves the
  single-bank runtime slices emit ACT/READ/PRE/REF and
  ACT/WRITE/READ/PRE/REF in order through the same timing monitor. The
  reusable bank-machine proof accepts arbitrary one-at-a-time read/write
  requests and proves emitted ACT/PRE/RD/WR commands stay inside the monitor's
  local row/timing contract. The scheduler proof wraps the shared command bus
  and proves the first cross-bank tRRD/tFAW/tCCD/write-to-read arbitration
  slice for bounded traffic on two active banks, plus request-driven refresh
  after all banks are precharged and tRP-safe. The refresh proofs connect the
  periodic tREFI requester to the scheduler in both an idle path and a focused
  two-bank active-traffic path, enabling the monitor's refresh-deadline check
  while requests may still be in flight when the refresh window opens.
- The byte-lane proof and unit simulation cover the controller-side BL8 x8
  packet boundary: writes emit eight ordered data/mask beats, and reads capture
  eight ordered data beats into one 64-bit line. The Micron write/read loopback
  now uses this packetizer for the BL8 payload before the ideal testbench DQS/DQ
  agent drives or samples the model pins.
- The full-channel line proof and unit simulation compose eight x8 lanes into
  one 512-bit BL8 line with 64 byte-mask bits. The proof checks lane data/mask
  mapping and read-line reassembly with all lanes advancing together; the unit
  bench adds independent per-lane stalls before the future DQS/DQ PHY.
- The line-to-x8-lane adapter proof and unit simulation cover the next reusable
  PHY boundary: two complete channel lines are serialized into sixteen x8 lane
  streams with independent per-lane backpressure, and read beats from all lanes
  are reassembled into channel lines only after every lane has delivered eight
  beats. This replaces the old simulation-only bridge in the line-level Micron
  regression.
- The line-to-x8-burst adapter proof and unit simulation cover the hardware
  boundary needed before the fast DQ/DQS sequencers: two complete channel lines
  split into sixteen independent 64-bit x8 BL8 lane bursts with independent
  backpressure, and returned lane bursts are reassembled into complete channel
  lines only after every lane has delivered its burst. This keeps wide line
  assembly in slow fabric and gives the future fast I/O shell preloaded per-lane
  payloads.
- The x8-data to x9-physical adapter proof and unit simulation make the board
  width policy explicit. Controller-visible lanes 0..7 pass through unchanged;
  physical lane 8 is deterministic zero-filled ECC/spare data on writes and is
  ignored on reads until a real ECC encoder/checker is added.
- The x8 lane PHY timing-core proof and unit simulation cover the first
  synthesizable DQ/DQS-facing slice. It buffers one BL8 x8 write burst,
  launches four rise/fall DDR pin-data pairs after write transfer start,
  controls DQ/DM/DQS output enables, and reassembles four sampled read pairs
  back into the lane stream. Board-specific IOBUF, ODDR/IDDR, IDELAY, and
  calibration are still outside this module.
- The x8 fast burst I/O sequencer proof and unit simulation cover the narrower
  fast-domain contract learned from the D88 timing failure. A complete 64-bit
  x8 BL8 payload is already preloaded before the bit-clock domain sees it; the
  sequencer only emits four local DDR rise/fall DQ pairs with DQS strobes and
  captures four sampled read pairs back into one 64-bit word. It deliberately
  omits Wishbone, line packing, RMW policy, lane arbitration, and calibration.
- The x8 SERDES-domain BL8 lane-adapter proof and unit simulation cover the
  next boundary between the controller burst contract and the board-local
  OSERDES/ISERDES shell. It accepts one preloaded 64-bit x8 write burst, emits
  one divided-clock SERDES data word plus DQS/DQ output-enable shape, captures
  one returned 64-bit SERDES read word, and leaves IOBUF, IDELAY, calibration,
  and read leveling to the YPCB-00338 wrapper.
- The x8 burst clock-bridge proof and dual-clock unit simulation cover the
  narrow slow/fast transport intended to feed that sequencer. It crosses one
  preloaded 64-bit x8 burst plus 8 mask bits, write/read start pulses, and one
  returned 64-bit read burst without moving full-line arbitration into the
  bit-clock domain.
- The line-to-fast-burst PHY shell proof and unit simulation compose the
  slow-fabric line-to-burst adapter, one narrow clock bridge per physical byte
  lane, and one fast-domain x8 burst sequencer per lane. The shell keeps
  complete 512-bit line assembly in the controller clock domain, synchronizes
  aggregate fast-domain status back to the controller clock, launches all lanes
  in a selected channel together, and reassembles read bursts into complete
  channel lines. It is still an abstract DQ/DQS shell, not board primitives,
  calibration, or external DDR3 storage.
- The line-to-SERDES PHY shell proof and unit simulation compose the same
  slow-fabric line-to-burst adapter and per-lane clock bridges with
  `ddr3_x8_serdes_burst_lane` instances. The unit simulation runs the full
  physical two-channel x9 lane shape, so the future board wrapper can consume
  one 64-bit SERDES word plus DQS/DQ output-enable vectors per physical lane.
  This is still before board OSERDES/ISERDES/IDELAY, calibration, read
  leveling, and external DDR3 storage validation.
- The IDELAY calibration command CDC proof and dual-clock unit simulation cover
  the host-loadable tap path used by the live SERDES init-only image. They
  check direct physical-lane requests, the legacy CH1 byte-lane map, tap
  integrity, one-cycle `LD` pulses in `clk_sys`, and request/observed-load
  counters.
- The raw SERDES capture CDC proof and dual-clock unit simulation cover the
  debug observation path used by the same host tap-load command. A selected
  physical lane's tap, DQ[63:0], DQS[7:0], and capture count cross back to the
  JTAG/control clock so software can inspect raw ISERDES snapshots during
  future MPR/read-leveling work.
- The line-to-lane PHY bridge proof and unit simulation compose the complete
  channel-line contract with one x8 lane PHY per physical byte lane. The bridge
  queues scheduler transfer-start pulses, starts all lanes in a channel
  together, checks abstract DDR DQ/DQS/DM write timing, and reassembles read
  samples through the same line boundary. It still stops before the 7-series
  primitive and calibration layer.
- The controller-to-PHY line clock bridge proof and dual-clock unit simulation
  cover the single-outstanding control/data crossing between slow controller
  fabric and a future faster PHY-side shell. The first D88 board experiment put
  too much soft line/lane timing fabric in the 400 MHz `clk_dq` domain and
  routed only to roughly 107 MHz, so that target is kept as debug evidence and
  refused for normal programming. The next real PHY split must keep wide line
  assembly and lane arbitration in slow fabric and move only a tiny 7-series
  I/O shell plus local x8 burst stepping into the fast domain.
- The YPCB-00338 board-local DQ/DQS I/O-shell probe wraps both physical
  channels with 144 DQ IOBUFs, 18 DQS IOBUFDS instances, 164 ODDR outputs, and
  162 IDDR inputs. The route-only DDR3-800 bitstream target holds the DDR3
  devices in reset, drives no memory commands, and checks that the tiny
  primitive shell itself routes at the 400 MHz bit-clock target before any
  controller data path is attached.
- The Wishbone frontend proof checks the ZipCPU `fwb_slave` contract for a
  single-outstanding request adapter, stable backend request fields under
  backpressure, abort handling, write acknowledgement on backend acceptance, and
  read data/error return from the selected 32-bit word inside a BL8 line. Its
  unit simulation checks address decode, active-high DDR3 DM mask placement
  from Wishbone byte enables, write data placement, and read word selection.
- The line-level Wishbone proof checks that write command acceptance is gated
  until the complete 512-bit/64-mask BL8 line has been accepted and reported
  loaded by the PHY side, and that reads wait for transfer-start plus a
  complete returned line before acknowledging the bus. This keeps the
  scheduler's WR command from outrunning a fast DDR write-data preloader. The
  no-DM variant first reads the target BL8 line, merges the selected Wishbone
  bytes, and then writes a full all-active line so boards without DM pins do
  not corrupt neighboring bytes.
- The Wishbone-to-channel bridge proof connects that line bridge to the full
  eight-lane line packetizer. It checks that a Wishbone request emits the
  expected BL8 line command, holds that command stable under backpressure, maps
  the selected 32-bit write word and inverted byte enables into the
  active-high 512-bit/64-mask channel line before command acceptance, and
  returns the selected read word from a completed channel line. Its unit
  simulation exercises one full-width write and one full-width read through all
  eight lanes.
- The dual-channel dispatch proof composes two full-channel bridges behind the
  global word-address decoder. It checks that channel bit 29 routes each
  accepted Wishbone request to exactly one channel and preserves the lower
  29-bit local address as the scheduler-facing BL8 line address. Its unit
  simulation drives a channel-0 write and a channel-1 read through independent
  command/data ports.
- The BL8 line scheduler-adapter proof connects one channel command port to the
  refresh requester plus scheduler. It checks that request acceptance is
  separate from the data-transfer start, that `o_xfer_start` only pulses when
  the matching RD/WR command issues, and that bank/column command fields match
  the accepted line address. Its unit simulation drives write/read/write
  traffic through different banks and rows.
- The controller shell proof checks the top-level init gate: Wishbone requests
  are stalled and cannot acknowledge or start PHY-side packet traffic until both
  channel init sequencers are done. Its unit simulation then runs post-init
  channel-0 write and channel-1 read traffic through the real scheduler command
  stream and verifies the line data path starts only on the issued RD/WR.
- The dual-channel Micron controller simulation wires `ddr3_ctrl` through
  sixteen x8 Micron models using the reusable timing agent. It performs a
  full-width write/read loopback on each channel and caught the scheduler's
  one-cycle replay hazard on registered bank-machine command outputs.
- `sim` compiles the vendored Micron DDR3 model, runs a smoke bench, and runs a
  DDR3-800 reset/MRS/ZQ/REF reference script plus the RTL init sequencer against
  the model. It also runs the RTL init sequencer followed by one single-bank
  READ command sequence, one single-bank WRITE/READ loopback, and a reusable x8
  DQS/DQ/DM timing-agent bench that performs two writes with active-high DDR3
  DM masking and reads the merged line back through the byte-lane packetizer.
  The controller-level Micron bench then runs channel-0 and channel-1
  write/read loopbacks through the full Wishbone, scheduler, and packetized data
  path. The line-level Micron bench uses the synthesizable line-to-x8-lane
  adapter before the simulation-only x8 timing agents, so the controller-facing
  line boundary is now shared by unit, formal, and Micron-model coverage. Model
  errors, and warnings on the protocol benches, are promoted to make failures.
  This is not board PHY validation yet; it keeps the real Micron BFM,
  initialization assumptions, runtime command timing, and full-width data
  loopback coverage in the live gate.
- `validate-jtag-bram` remains the narrow hardware confidence check for
  JTAG/Wishbone and the board BRAM target.
- `ddr3-ctrl-line-loopback-ddr800-bitstream` routes the clean line-controller
  board image with the full CH0 + CH1 DDR3 pinout constrained. The controller,
  scheduler, JTAG bridge, Wishbone bus, and fabric loopback PHY run in the
  50 MHz board-clock domain; CK is generated, DQ/DQS are high-Z, and external
  DDR3 reset is held low.
- `program-ddr3-ctrl-line-loopback-ddr800` and
  `validate-ddr3-ctrl-line-loopback` are the current hardware gate for the
  clean controller fabric path. Passing them proves live JTAG/Wishbone writes
  and reads through the two-channel line controller and scheduled BL8 line
  boundary. It is not DDR3-800 speed signoff because no external DQ/DQS PHY or
  real memory storage is validated yet.
- `ddr3-ctrl-line-laneloop-ddr800-bitstream` inserts the synthesizable
  `ddr3_line_to_lanes` adapter between the line controller and internal x8 lane
  memories. It keeps DDR3 command pins inactive and DQ/DQS high-Z, so it is a
  data-boundary hardware gate rather than an external-memory gate.
- `program-ddr3-ctrl-line-laneloop-ddr800` and
  `validate-ddr3-ctrl-line-laneloop` prove live JTAG/Wishbone writes and reads
  through the line controller, scheduler, complete BL8 line boundary, and
  reusable line-to-lane RTL in FPGA fabric.
- `ddr3-ctrl-line-cmdprobe-ddr800-bitstream` enables the next board-facing
  probe: reset, CKE, ODT, CK, command, bank, and address pins are driven on both
  physical DDR3 channels while DQ/DQS stay high-Z and read data returns through
  the internal line loopback. Since the board path has no DDR3 DM pins, this
  image selects the no-DM read-modify-write line bridge and validates
  byte-select writes through that path. This routes with `--timing-allow-fail`
  because `nextpnr-xilinx` has one global frequency setting for both the real
  50 MHz SYS_CLK domain and the 400 MHz DDR command-pin domain. It is a
  command-path smoke gate, not a DDR3-800 timing signoff.
- `program-ddr3-ctrl-line-cmdprobe-ddr800` and
  `validate-ddr3-ctrl-line-cmdprobe` validate the clean controller plus board
  command-pin path. Passing them proves live
  JTAG/Wishbone writes and reads through the line controller, scheduler,
  command-pin CDC, and scheduled BL8 line boundary on the real FPGA. External
  DDR3 storage remains unvalidated until a real DQ/DQS PHY is connected and
  timing-closed.
- `ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream` combines the command-probe and
  line-to-lane gates: board reset, CKE, ODT, CK, command, bank, and address
  pins are driven on both physical channels, while `ddr3_line_to_lanes`
  serializes complete controller lines into sixteen internal x8 lane memories.
  DQ/DQS remain high-Z.
- `program-ddr3-ctrl-line-cmdlaneloop-ddr800` and
  `validate-ddr3-ctrl-line-cmdlaneloop` are the current pre-PHY hardware gate.
  Passing them proves live JTAG/Wishbone writes and reads through the line
  controller, scheduler, command-pin CDC, complete BL8 line boundary, and
  reusable line-to-lane adapter together on the real FPGA.
- `ddr3-ctrl-line-phyclkloop-ddr800-bitstream` is intentionally not a live
  validation gate. It preserves the D88 timing-failed bridge experiment so the
  next PHY iteration does not repeat the mistake of routing wide lane/control
  muxing in the DDR bit-clock domain.
- `ddr3-dq-dqs-iobuf-ddr800-bitstream` is the current fast-I/O route gate. The
  2026-05-20 seed-1 route met the 400 MHz `clk_dq` target without
  `--timing-allow-fail`, with the routed fast-domain max reported around
  1.42 GHz. It is still not memory validation: DDR3 reset stays asserted, CKE
  stays low, and no JTAG/Wishbone storage test is possible on this image.
- `ddr3-dq-dqs-burst-ddr800-bitstream` is the current fast-I/O datapath route
  gate. It uses the full active YPCB-00338 constraints, both DDR3 channels, and
  one per-lane x8 burst sequencer in route-only fast-accept mode. The 2026-05-20
  seed-1 route met the 400 MHz `clk_dq` target without `--timing-allow-fail`;
  nextpnr reported 448.43 MHz. DDR3 reset still stays asserted and CKE low, so
  this proves route shape for local BL8 DQ/DQS launch, not external storage.
- `ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-bitstream` and
  `ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-bitstream` are focused
  diagnostics for the future SERDES PHY shell. Both generated bitstreams at the
  400 MHz route target on 2026-05-20. The combined tight bidirectional lane0
  target stalls with fixed router2 overuse 18, but the same netlist routes with
  router1 and generates a bitstream, so the open issue is router2 handling of
  the shared bidirectional DQ/DQS IOB topology when TX, RX, and IDELAYE2 are all
  live.
- `ddr3-dq-dqs-serdes-ch0-router1-ddr800-bitstream`,
  `ddr3-dq-dqs-serdes-ch1-router1-ddr800-bitstream`, and
  `ddr3-dq-dqs-serdes-router1-ddr800-bitstream` are route-only DDR3-800 SERDES
  scale gates. On 2026-05-20, CH0 and CH1 each generated bitstreams with
  81 OSERDESE2, 81 ISERDESE2, and 81 IDELAYE2 cells. The full CH0+CH1 target
  generated a bitstream with 162 OSERDESE2, 162 ISERDESE2, 162 IDELAYE2, and
  6 IDELAYCTRL cells; post-route timing reported `clk_idelay_ref` at 683.53 MHz
  and `clk_sys` at 1557.63 MHz against the 400 MHz route target. This remains a
  route/timing proof only: DDR3 reset stays asserted, CKE stays low, and no
  external read/write storage is validated.
- `ddr3-ctrl-line-serdes-router1-ddr800-bitstream` is the first route-only
  board image that wires the line-level controller path through
  the explicit x8-data to x9-physical adapter, `ddr3_line_serdes_phy`, and all
  physical x9 DQ/DQS SERDES lanes on both channels. The 2026-05-20 seed-1 route
  generated a bitstream with 162 OSERDESE2, 162 ISERDESE2, 162 IDELAYE2,
  144 DQ IOBUF, 18 DQS IOBUFDS, and 6 IDELAYCTRL cells. Post-route max
  frequencies were `SYS_CLK` 71.28 MHz, `clk_sys` 155.26 MHz,
  `clk_idelay_ref` 759.88 MHz, and `clk_dq`/`clk_ddr` 1557.63 MHz. This target
  intentionally uses nextpnr's global `--freq 50` check because nextpnr applies
  that one number to every clock; the DDR3-800 evidence is the per-clock
  max-frequency report. It is not a storage validation target: DDR3 reset stays
  asserted, CKE stays low, and lane 8 is currently a zero-filled ECC/spare lane
  rather than a checked ECC datapath.
- `ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream` is the first live
  init-only board image with the controller-to-SERDES full x9 shell present.
  It drives DDR3 reset/CKE/ODT/CK/address/command pins and blocks DDR Wishbone
  access so uncalibrated external storage traffic cannot be launched. Its XVC
  validator requires the block flag and performs one blocked DDR write/read
  check, expecting `ack+err` and the blocked-read sentinel. The DQ/DQS
  IDELAYE2 cells are host-loadable through `SET_CAL`, with per-lane request
  toggles crossing safely from the JTAG/Wishbone clock domain into `clk_sys`
  before IDELAY `LD` is asserted. The 2026-05-20 seed-1 route generated a
  bitstream with 162 OSERDESE2,
  162 ISERDESE2, 162 IDELAYE2, 144 DQ IOBUF, 18 DQS IOBUFDS, and
  6 IDELAYCTRL cells. Post-route max frequencies were `SYS_CLK` 112.84 MHz,
  `clk_sys` 133.87 MHz, `clk_idelay_ref` 834.72 MHz, `clk_dq` 684.93 MHz, and
  `clk_ddr` 1557.63 MHz. Hardware programming succeeded after a DLC10 replug,
  and XVC validation passed with version `0xB07E0D89`, init done, all generated
  clocks alive, DDR Wishbone blocked with the `0xD15A_B1ED` read sentinel, and
  IDELAY request/seen counters matching for both direct physical-lane and
  legacy CH1 byte-lane addressing.

## Directory Map

| Path | Role |
|---|---|
| `rtl/ddr3_params.vh` | Shared command encodings, mode registers, geometry, and DDR3-800 waits. |
| `rtl/ddr3_addr_decode.sv` | Full-capacity two-channel word-address decoder for channel, bank, row, column, BL8 line, and word index. |
| `rtl/ddr3_init_seq.sv` | DDR3-800 reset/MRS/ZQ/REF initialization sequencer. |
| `rtl/ddr3_single_read_seq.sv` | Command-only single-bank ACT/READ/PRE/REF runtime slice. |
| `rtl/ddr3_single_write_read_seq.sv` | Single-bank ACT/WRITE/READ/PRE/REF runtime slice for timing and x8 model bring-up. |
| `rtl/ddr3_bank.sv` | Reusable one-bank open-row and local timing machine. |
| `rtl/ddr3_scheduler.sv` | First global command scheduler slice for cross-bank timing gates and request-driven refresh. |
| `rtl/ddr3_refresh.sv` | Periodic tREFI refresh requester that feeds the scheduler. |
| `rtl/ddr3_channel_sched.sv` | Single-channel adapter from BL8 line requests into refresh plus scheduler command issue, with an explicit transfer-start pulse. |
| `rtl/ddr3_byte_lane.sv` | Controller-side x8 BL8 byte-lane packetizer for ordered write/read data beats. |
| `rtl/ddr3_channel_line.sv` | Full 64-bit-channel BL8 line packetizer composed from eight x8 byte lanes. |
| `rtl/ddr3_line_to_lanes.sv` | Reusable line-to-x8-lane adapter for serializing complete channel BL8 lines into sixteen x8 lane streams and reassembling read lanes. |
| `rtl/ddr3_line_to_bursts.sv` | Reusable line-to-x8-burst adapter for splitting complete channel BL8 lines into preloaded 64-bit x8 burst payloads and reassembling returned bursts. |
| `rtl/ddr3_x8_to_x9_line_adapter.sv` | Explicit x64-data to x72-physical adapter; lanes 0..7 pass through, lane 8 is zero-filled ECC/spare data until real ECC exists. |
| `rtl/ddr3_x8_lane_phy.sv` | Reusable synthesizable x8 lane PHY timing core that turns lane beats into DDR rise/fall pin data and read samples back into lane beats. |
| `rtl/ddr3_x8_burst_io_sequencer.sv` | Small fast-domain x8 BL8 burst sequencer for preloaded write payload launch and sampled read-pair reassembly in front of the board I/O shell. |
| `rtl/ddr3_x8_serdes_burst_lane.sv` | Pure RTL x8 SERDES-domain BL8 lane adapter that presents one 64-bit write/read burst word to the board OSERDES/ISERDES shell without instantiating Xilinx primitives. |
| `rtl/ddr3_line_serdes_phy.sv` | Line-to-SERDES PHY shell that composes the line-to-burst adapter, per-lane clock bridges, and x8 SERDES-domain lane adapters before board primitives. |
| `rtl/ddr3_serdes_capture_cdc.sv` | Debug CDC bridge that snapshots one physical lane's raw board-shell ISERDES DQ/DQS bits on a host IDELAY-load event and returns the snapshot to JTAG/control status registers. |
| `rtl/ddr3_line_lane_phy.sv` | Integration bridge from complete channel BL8 lines through all x8 lane PHY timing cores, exposing abstract per-lane DQ/DQS/DM timing signals for the future board primitive wrapper. |
| `rtl/ddr3_line_phy_clock_bridge.sv` | Single-outstanding controller/PHY clock bridge for complete BL8 line payloads and transfer-start/read-return handshakes; useful boundary, not a full DDR bit-clock PHY. |
| `../../boards/ypcb-00338/rtl/ddr3_board_io.sv` | Board-local 7-series clock, command, high-Z, and DQ/DQS primitive wrappers for staged hardware bring-up. |
| `../../boards/ypcb-00338/rtl/ddr3_serdes_io.sv` | Board-local 7-series x8 OSERDESE2/ISERDESE2/IDELAYE2 pin shell for route-probing the future DQ/DQS PHY boundary. |
| `../../boards/ypcb-00338/rtl/top_ddr3_dq_dqs_iobuf_probe.sv` | Route-only full-pin DDR3-800 DQ/DQS ODDR/IDDR/IOBUF probe with DDR3 reset held active. |
| `../../boards/ypcb-00338/rtl/top_ddr3_dq_dqs_burst_probe.sv` | Route-only full-pin DDR3-800 probe with one x8 burst sequencer per byte lane driving the DQ/DQS shell while DDR3 reset stays active. |
| `../../boards/ypcb-00338/rtl/top_ddr3_dq_dqs_serdes_probe.sv` | Experimental route-only DDR3-800 SERDES primitive probe for full-top and full dual-channel route diagnostics. The bidirectional dual-channel target preserves 162 OSERDESE2, 162 ISERDESE2, and 162 IDELAYE2 cells; router2 stalls with overuse 324, while router1 routes and generates a timing-clean bitstream. |
| `../../boards/ypcb-00338/rtl/top_ddr3_dq_dqs_serdes_lane_probe.sv` | Tighter CH0 lane-0 SERDES diagnostic that exposes only the CH0 command pins plus one x8 DQ/DQS lane. Bidirectional TX+RX preserves 9 OSERDESE2, 9 ISERDESE2, and 9 IDELAYE2 cells; router2 stalls with overuse 18, router1 routes and generates a bitstream, and TX-only/RX-only split diagnostics each route and generate bitstreams at 400 MHz. |
| `../../boards/ypcb-00338/rtl/top_ddr3_ctrl_line_serdes.sv` | Route-only DDR3-800 controller-to-SERDES board top. It connects `ddr3_ctrl_line` through the x8-data to x9-physical adapter and `ddr3_line_serdes_phy` to all x9 CH0+CH1 OSERDES/ISERDES/IDELAY DQ/DQS lanes while holding DDR3 reset active and CKE low. |
| `../../boards/ypcb-00338/constraints/ddr3_ch0_lane0_scalar_dqs.xdc` | Scalar DQS overlay for the one-lane SERDES diagnostic, needed because a `[0:0]` SystemVerilog port is emitted as scalar `ddr3_dqs_p`/`ddr3_dqs_n`. |
| `rtl/ddr3_wb_frontend.sv` | Single-outstanding Wishbone-to-BL8 frontend for 32-bit word packing, byte masks, and read word selection; retained for focused frontend proof coverage. |
| `rtl/ddr3_wb_line_channel.sv` | Line-level Wishbone bridge that presents a complete write line before scheduler command acceptance and acknowledges reads only after a returned line; optional no-DM mode performs read-modify-write before full-line writes. |
| `rtl/ddr3_wb_channel.sv` | Integration slice tying the line-level Wishbone bridge to the full-channel line packetizer and exposing one BL8 line command. |
| `rtl/ddr3_wb_dual_channel.sv` | Full-capacity dual-channel Wishbone dispatch bridge built from two channel bridges and the global address decoder. |
| `rtl/ddr3_ctrl.sv` | Init-gated dual-channel controller shell connecting Wishbone dispatch, two init sequencers, two scheduler adapters, command pins, and packetized PHY-side data ports. |
| `rtl/ddr3_wb_dual_channel_line.sv` | Line-level dual-channel Wishbone dispatch bridge for a controller-owned BL8 line PHY boundary. |
| `rtl/ddr3_ctrl_line.sv` | Init-gated dual-channel controller shell that exposes complete BL8 write/read lines instead of byte-lane DQ/DQS packets. |
| `formal/ddr3_cmd_timing_monitor.sv` | Reusable JEDEC command/timing assertion block. |
| `formal/addr_decode_wrapper.sv` | Formal harness for the full-capacity two-channel address map and alias checks. |
| `formal/timing_monitor_wrapper.sv` | Self-check harness for the timing monitor. |
| `formal/init_seq_wrapper.sv` | Formal harness for init sequencer ordering and waits. |
| `formal/single_read_wrapper.sv` | Formal harness for the single-bank runtime command slice. |
| `formal/single_write_read_wrapper.sv` | Formal harness for the single-bank write/read runtime command slice. |
| `formal/bank_wrapper.sv` | Formal harness for the one-bank row/timing machine. |
| `formal/scheduler_wrapper.sv` | Formal harness for the scheduler timing/refresh slice. |
| `formal/refresh_wrapper.sv` | Formal harness for periodic idle refresh through the scheduler and timing monitor. |
| `formal/refresh_traffic_wrapper.sv` | Formal harness for periodic refresh with bounded in-flight scheduler traffic. |
| `formal/byte_lane_wrapper.sv` | Formal harness for BL8 x8 byte-lane data/mask ordering and read capture. |
| `formal/channel_line_wrapper.sv` | Formal harness for full-channel lane composition, byte-mask mapping, and read-line reassembly. |
| `formal/line_to_lanes_wrapper.sv` | Formal harness for the reusable line-to-x8-lane adapter boundary. |
| `formal/line_to_bursts_wrapper.sv` | Formal harness for the reusable line-to-x8-burst adapter boundary. |
| `formal/x8_to_x9_line_adapter_wrapper.sv` | Formal harness for x8-data to x9-physical lane mapping and spare-lane policy. |
| `formal/x8_lane_phy_wrapper.sv` | Bounded formal harness for x8 lane PHY write-pair launch, read-pair capture, and output-enable invariants. |
| `formal/x8_serdes_burst_lane_wrapper.sv` | Bounded formal harness for the x8 SERDES-domain BL8 lane-adapter data, output-enable, and read-valid contract. |
| `formal/line_serdes_phy_wrapper.sv` | Bounded formal harness for the line-to-SERDES PHY shell over one representative lane. |
| `formal/line_phy_clock_bridge_wrapper.sv` | Bounded formal harness for the controller-to-PHY line clock bridge request, transfer-start, and read-return protocol. |
| `formal/wb_frontend_wrapper.sv` | Formal harness for Wishbone protocol, backend request stability, and BL8 word mapping. |
| `formal/wb_line_channel_wrapper.sv` | Formal harness for the line-level Wishbone bridge contract. |
| `formal/wb_channel_wrapper.sv` | Formal harness for the Wishbone-to-full-channel bridge command/data mapping. |
| `formal/wb_dual_channel_wrapper.sv` | Formal harness for global Wishbone channel selection and local address preservation. |
| `formal/channel_sched_wrapper.sv` | Formal harness for BL8 line request acceptance, scheduler command issue, and transfer-start timing. |
| `formal/ctrl_wrapper.sv` | Formal harness for the controller-level init gate and pre-init Wishbone/data quiescence. |
| `formal/ctrl_line_wrapper.sv` | Formal harness for the line-level controller init gate and pre-init PHY-line quiescence. |
| `sim/vendor/` | Vendored Micron DDR3 model and parameters. |
| `sim/tb_addr_decode.sv` | Unit bench for boundary and mixed full-capacity address decoding. |
| `sim/tb_byte_lane.sv` | Unit bench for the byte-lane packetizer. |
| `sim/tb_channel_line.sv` | Unit bench for the full-channel BL8 line packetizer with per-lane stalls. |
| `sim/tb_line_to_lanes.sv` | Unit bench for dual-channel line-to-x8-lane serialization and read reassembly with skewed lane stalls. |
| `sim/tb_line_to_bursts.sv` | Unit bench for dual-channel line-to-x8-burst preload and read reassembly with skewed lane stalls. |
| `sim/tb_x8_to_x9_line_adapter.sv` | Unit bench for x8-data to x9-physical passthrough plus deterministic spare-lane writes. |
| `sim/tb_x8_lane_phy.sv` | Unit bench for x8 lane PHY BL8 write preload, DDR rise/fall launch, and read-pair reassembly. |
| `sim/tb_x8_serdes_burst_lane.sv` | Unit bench for x8 SERDES-domain write preamble/data/postamble shape and one-word read capture. |
| `sim/tb_line_serdes_phy.sv` | Unit bench for the line-to-SERDES PHY shell using two physical x9 channels. |
| `sim/tb_line_phy_clock_bridge.sv` | Dual-clock unit bench for the controller-to-PHY line bridge. |
| `sim/tb_wb_frontend.sv` | Unit bench for the Wishbone-to-BL8 frontend. |
| `sim/tb_wb_line_channel.sv` | Unit bench for the line-level Wishbone bridge. |
| `sim/tb_wb_channel.sv` | Unit bench for the Wishbone-to-full-channel bridge. |
| `sim/tb_wb_dual_channel.sv` | Unit bench for channel-0 write dispatch and channel-1 read dispatch. |
| `sim/tb_channel_sched.sv` | Unit bench for BL8 line requests issuing through the scheduler adapter. |
| `sim/tb_ctrl.sv` | Unit bench for init-gated dual-channel controller integration through scheduler-issued RD/WR transfer starts. |
| `sim/tb_ctrl_line.sv` | Unit bench for init-gated line-level controller integration through scheduler-issued RD/WR transfer starts. |
| `sim/ddr3_x8_phy_agent.sv` | Simulation-only reusable x8 DQS/DQ/DM timing agent that bridges byte-lane packets to a Micron x8 model. |
| `sim/tb_micron_model_smoke.sv` | Minimal Micron model compile/run smoke bench. |
| `sim/tb_micron_init_script.sv` | Handwritten DDR3-800 reset/MRS/ZQ/REF script against the Micron model. |
| `sim/tb_micron_init_seq.sv` | RTL init sequencer bench against the Micron model. |
| `sim/tb_micron_single_read.sv` | RTL init plus single-bank READ command bench against the Micron model. |
| `sim/tb_micron_single_write_read.sv` | RTL init plus single-bank WRITE/READ x8 loopback bench using the byte-lane packetizer and an ideal testbench DQS/DQ agent. |
| `sim/tb_micron_x8_phy_agent.sv` | Regression for the reusable x8 timing agent, including active-high DM masked write merge through the Micron model. |
| `sim/tb_micron_ctrl_dual_channel.sv` | Dual-channel full-width `ddr3_ctrl` loopback through sixteen Micron x8 models using the reusable timing agents. |
| `sim/tb_micron_ctrl_line_dual_channel.sv` | Dual-channel line-level `ddr3_ctrl_line` loopback through the RTL line-to-lanes adapter and sixteen Micron x8 models. |
| `docs/verification-plan.md` | Required formal and simulation ladder for new RTL. |
| `docs/learning-notes.md` | Reference lessons from LiteDRAM and UberDDR3. |
