# DDR3 Verification Plan

This directory is now verification-first. New RTL is not done when it
elaborates; it is done when the relevant formal, simulation, route, and hardware
gate has evidence.

## Current Live Gates

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
```

Current coverage:

- `formal`: proves the full-capacity two-channel address map, including
  channel/bank/row/column/word split, line-address recomposition, BL8 column
  alignment, and no alias for matching `{channel, line, word}` fields. It also
  proves the reusable DDR3 command timing monitor is internally consistent on a
  legal ACT/RD/PRE/REF/WR/ZQ trace, and proves the controller-owned init
  sequencer emits reset, MRS, ZQCL, and REF in order with
  minimum waits plus the post-DLL-lock wait. It also proves the single-bank
  runtime slices emit ACT, READ, PRE, REF and ACT, WRITE, READ, PRE, REF in
  order through the monitor. The bank-machine proof wraps arbitrary serialized
  bank requests with the same monitor to prove open-row decisions and local
  timing waits. The scheduler proof wraps the shared command bus and proves the
  first cross-bank tRRD/tFAW/tCCD/write-to-read arbitration slice for bounded
  traffic on two active banks. It also proves the request-driven refresh slice
  issues REF only after all banks are closed and tRP-safe, then waits tRFC. The
  periodic refresh proof drives the scheduler from a tREFI requester in an idle
  path and enables the monitor's refresh-deadline assertion. A second focused
  refresh proof uses a two-bank scheduler instance with nondeterministic normal
  requests to prove the refresh window backpressures new requests, drains
  in-flight traffic, closes banks, and still reaches REF before the monitor's
  tREFI deadline. The byte-lane proof covers the controller-side x8 BL8 packet
  boundary: write beats preserve data/mask order under PHY backpressure, read
  beats are captured in order, and the read-valid response reports the exact
  64-bit line accepted from the PHY side. The Wishbone frontend proof covers a
  single-outstanding `fwb_slave` adapter, backend request stability under
  backpressure, abort/drain behavior, write acknowledgement, and read
  data/error return from the selected word in a BL8 line. The full-channel line
  proof composes eight byte lanes and checks 512-bit write data placement,
  64-bit byte-mask placement, and read-line reassembly at the channel boundary.
  The Wishbone-to-channel bridge proof connects those two contracts and checks
  command emission, command stability under scheduler backpressure, full-width
  write word/mask placement, and read word return from a completed channel line.
  The dual-channel dispatch proof composes two channel bridges behind the
  global address decoder and checks that each accepted request selects exactly
  one channel while preserving `global[28:4]` as that channel's BL8 line
  address. The BL8 line scheduler-adapter proof connects one channel command
  port to the refresh requester plus scheduler and checks that request
  acceptance is separate from the RD/WR transfer-start pulse, that the transfer
  starts only for the matching pending request, and that issued command bank and
  column fields match the accepted line address. The controller shell proof
  checks the top-level init gate: before both init sequencers are done,
  Wishbone requests remain stalled, no response is produced, refresh/scheduler
  traffic is quiet, and no PHY-side packet transfer starts.
- `sim`: runs a unit bench for the full-capacity address map, then compiles and
  runs the vendored Micron x8 2Gb DDR3 model at a valid DDR3-800 clock. It
  drives both a handwritten reset/MRS/ZQ/REF reference script and the RTL init
  sequencer through the model. It also drives the RTL init sequencer into one
  single-bank READ command sequence and one single-bank WRITE/READ loopback
  using the byte-lane packetizer for one BL8 payload plus an ideal x8 DQS/DQ
  testbench agent. A reusable x8 DQS/DQ/DM timing-agent bench also performs two
  writes with active-high DDR3 DM masking and reads the merged line back through
  the byte-lane packetizer. It also runs a unit bench for the full-channel line
  packetizer with independent per-lane stalls, plus a unit bench for the
  Wishbone frontend address split, write data/mask placement, and read word
  selection. The Wishbone-to-channel unit bench drives one write and one read
  from the bus through all eight byte lanes. The dual-channel dispatch unit
  bench drives a channel-0 write and a channel-1 read through independent
  command/data ports. The scheduler-adapter unit bench issues write/read/write
  line requests across different rows and banks and checks that `o_xfer_start`
  coincides with the expected RD/WR command. The controller shell unit bench
  waits for both init sequencers, then runs a channel-0 write and channel-1
  read through scheduler-issued DDR3 WR/RD commands and the full-channel packet
  data path. The protocol benches fail if the model reports timing or protocol
  errors or warnings.

Current non-coverage:

- no pin-level controller-owned DQS/DQ PHY, calibration, Micron-model runtime
  loopback through `ddr3_ctrl`, or full memory data path exists yet;
- no PHY, board DQS/DQ, leveling, or hardware DDR3 path is validated by these
  gates.

## Formal Ladder

Every new RTL slice should add or extend one of these harnesses:

| Stage | Required proof |
|---|---|
| Address decode | Full 4 GiB word-address space splits into channel, bank, row, BL8 column, line address, and word index without aliasing. First proof exists. |
| Command definitions | All command encodings decode uniquely; NOP/DES are harmless. |
| Init sequencer | Reset, CKE, MRS, ZQCL, DLL wait, and first REF occur in order with minimum waits. |
| Bank machine | No ACT/RD/WR/PRE violates tRC, tRAS, tRP, tRCD, tWR, tRTP, tCCD, or write-to-read wait. |
| Global scheduler | No cross-bank violation of tRRD, tFAW, tCCD, or tWTR. First bounded proof exists. |
| Refresh scheduler | No tRFC violation and no refresh before all banks are precharged. Request-driven proof exists; periodic idle deadline proof exists; focused active-traffic deadline proof exists. |
| Byte lane | BL8 x8 write data/mask ordering, read capture ordering, and ready/valid stability under PHY backpressure. First proof exists. |
| Full channel line | Eight x8 byte lanes compose into one 512-bit line plus 64 byte-mask bits. First proof exists; per-lane stall simulation exists. |
| Wishbone frontend | ZipCPU `fwb_slave` contract; no ack without accepted request; no lost request. First single-outstanding proof exists. |
| Wishbone channel bridge | One Wishbone word request maps to exactly one BL8 line command and one full-channel data transfer. First proof exists. |
| Channel scheduler adapter | One BL8 line command is accepted by the scheduler, then starts data only when the matching RD/WR command issues. First proof exists. |
| Controller shell | Wishbone is gated until both init sequencers finish, then requests flow through two scheduler adapters. First gate proof and scheduler-connected unit simulation exist. |
| Read/write merge | Byte enables update exactly the selected 32-bit word inside one BL8 line. Frontend byte-mask generation now uses active-high DDR3 DM polarity; downstream merge or mask-preserving PHY write is still pending. |
| Dual channel decode | Channel select bit routes to exactly one channel and preserves local address. First proof exists through `ddr3_wb_dual_channel`. |

The command timing monitor in `formal/ddr3_cmd_timing_monitor.sv` is the first
reusable assertion block. Future controller proofs should instantiate it around
the actual command bus instead of reimplementing these assertions locally.

## Micron Simulation Ladder

Use the real Micron model for protocol validation:

| Stage | Model stack | Pass condition |
|---|---|---|
| Address map unit | combinational decoder | boundary and mixed addresses decode to the documented full-capacity fields |
| Smoke | one x8 model, held in reset | model compiles and clocks with selected defines |
| Reference init | handwritten script + one x8 model | reset/MRS/ZQ/REF completes without model timing errors |
| Controller init | controller + one x8 model | controller init completes without model timing errors |
| Single READ command | controller + one x8 model | ACT/READ/PRE/REF command sequence completes without model errors or warnings |
| Single WRITE/READ command | controller + one x8 model + byte-lane packetizer + ideal DQS/DQ agent | deterministic BL8 x8 write/read pattern passes |
| Reusable x8 timing agent | init sequencer + byte-lane packetizer + x8 DQS/DQ/DM timing agent + one x8 model | two writes with active-high DM masking merge correctly and read back through the byte-lane path |
| Full-channel line unit | eight byte-lane packetizers behind one channel interface | 512-bit write mapping, 64-bit mask mapping, per-lane stalls, and read reassembly pass |
| Wishbone frontend unit | Wishbone frontend + backend line handshake model | address split, write data/mask placement, and read word selection pass |
| Wishbone channel unit | Wishbone frontend + full-channel line packetizer | one bus write and one bus read traverse all eight byte lanes with correct command and word mapping |
| Wishbone dual-channel unit | address decoder + two Wishbone channel bridges | channel-0 write and channel-1 read dispatch to independent command/data ports |
| Channel scheduler unit | scheduler adapter + refresh requester + scheduler | line requests produce matching RD/WR command issue and transfer-start pulses |
| Controller shell unit | init + dual-channel Wishbone dispatch + two scheduler adapters + packetized line ports | pre-init bus stall plus post-init channel-0 write and channel-1 read through scheduler-issued RD/WR |
| Runtime x8 | controller + one x8 model | controller-owned DQS/DQ write/read patterns pass |
| Full channel | controller + eight x8 models | every 64 data bits and byte lane pass |
| Dual channel | two full-channel stacks | both channels pass independent and interleaved traffic |

Compile defines for the YPCB-00338 part:

```text
-Dden2048Mb -Dsg125 -Dx8
```

The Micron model must run with `timescale 1ps / 1ps`. DDR3-800 uses a 400 MHz
CK (`tCK = 2500 ps`) and is the slowest normal hardware target because the
model rejects clocks slower than `TCK_MAX = 3300 ps` with DLL enabled.

## Hardware Ladder

Each speed step must have a separate evidence note:

1. DDR3-800
2. DDR3-1066
3. DDR3-1333
4. DDR3-1600

For each step record:

- exact commit;
- board target and route seed;
- final nextpnr timing lines for system and DDR clocks;
- programming command and `done` status;
- JTAG/Wishbone validator command;
- boundary, walking, lane, window, checksum, random, and soak results;
- final status flags and error counters.

Do not promote a speed grade because simulation passed. Hardware validation is
the gate.
