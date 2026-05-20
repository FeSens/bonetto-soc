# DDR3 RTL Area

The active RTL slices are deliberately small and scheduler-facing:

- `ddr3_params.vh`: shared command encodings, mode registers, geometry, and
  DDR3-800 timing waits;
- `ddr3_addr_decode.sv`: full-capacity two-channel word-address decoder that
  emits channel, local word address, BL8 line address, bank, row, aligned
  column, and word index;
- `ddr3_init_seq.sv`: reset, CKE, MR2, MR3, MR1, MR0, ZQCL, first REF, and
  post-DLL-lock wait before `done`;
- `ddr3_single_read_seq.sv`: one conservative single-bank ACT, READ, PRE, REF
  command sequence after init;
- `ddr3_single_write_read_seq.sv`: one conservative single-bank ACT, WRITE,
  READ, PRE, REF command sequence after init;
- `ddr3_bank.sv`: one reusable bank machine with open-row tracking and local
  timing waits for ACT, PRE, READ, and WRITE;
- `ddr3_scheduler.sv`: first global scheduler slice, instantiating one bank
  machine per bank, gating the shared command bus for tRRD, tFAW, tCCD, and
  write-to-read timing, and handling request-driven refresh by closing banks
  before REF;
- `ddr3_refresh.sv`: periodic tREFI requester that raises refresh requests
  early enough to give the scheduler a drain/close margin before the JEDEC
  deadline;
- `ddr3_channel_sched.sv`: single-channel adapter that feeds BL8 line requests
  into the refresh requester plus scheduler, reports scheduler request
  acceptance, and emits an explicit transfer-start pulse plus transfer type
  when the matching RD/WR command issues;
- `ddr3_byte_lane.sv`: controller-side x8 BL8 packetizer that emits ordered
  write data/mask beats and captures ordered read data beats;
- `ddr3_channel_line.sv`: full 64-bit-channel BL8 line packetizer that composes
  eight byte lanes into one 512-bit line plus 64 byte-mask bits while keeping
  per-lane PHY handshakes visible;
- `ddr3_line_to_lanes.sv`: two-channel bridge from the controller line contract
  to sixteen independent x8 lane streams;
- `ddr3_line_to_bursts.sv`: two-channel bridge from complete controller lines
  to sixteen independent preloaded 64-bit x8 BL8 lane bursts, keeping wide line
  assembly in slow fabric before the fast DQ/DQS sequencers;
- `ddr3_x8_lane_phy.sv`: synthesizable x8 lane timing core that buffers one BL8
  write burst, launches registered DDR rise/fall DQ/DM/DQS pairs, captures
  read sample pairs, and reassembles ordered lane bytes;
- `ddr3_x8_burst_io_sequencer.sv`: smaller fast-domain x8 sequencer that
  accepts one preloaded 64-bit BL8 payload, launches four DDR rise/fall DQ
  pairs with DQS strobes, and returns one 64-bit captured read payload; it also
  has a route-only fast-accept branch used by the YPCB-00338 full-pin burst
  route probe;
- `ddr3_x8_burst_clock_bridge.sv`: narrow dual-clock bridge for one preloaded
  x8 burst lane, crossing 64 data bits, 8 mask bits, write/read starts, and one
  returned read burst between slow fabric and the fast sequencer domain;
- `ddr3_line_burst_phy.sv`: line-to-fast-burst PHY shell that composes
  `ddr3_line_to_bursts`, one `ddr3_x8_burst_clock_bridge` per physical byte
  lane, and one fast-domain `ddr3_x8_burst_io_sequencer` per lane, exposing an
  abstract DQ/DQS contract while keeping complete line assembly in slow fabric;
- `ddr3_line_lane_phy.sv`: reusable bridge that composes
  `ddr3_line_to_lanes` with one `ddr3_x8_lane_phy` per physical byte lane,
  exposing abstract per-lane DQ/DQS/DM timing signals for the future
  board-specific 7-series primitive wrapper;
- `ddr3_wb_frontend.sv`: single-outstanding Wishbone-to-BL8 frontend that
  splits word addresses into line address and word index, places write data and
  byte masks into a BL8 line, and selects read words from backend response
  lines;
- `ddr3_wb_line_channel.sv`: line-level Wishbone bridge that presents a full
  BL8 write line before scheduler command acceptance and acknowledges reads only
  after transfer-start plus a complete returned line;
- `ddr3_wb_channel.sv`: integration slice connecting the line-level Wishbone
  bridge to the full-channel BL8 line packetizer, exposing a scheduler-facing
  line command, and keeping scheduler request acceptance separate from the
  later data-transfer start;
- `ddr3_wb_dual_channel.sv`: full-capacity dual-channel dispatch slice that
  decodes the global word address and routes one Wishbone request to exactly
  one full-channel bridge;
- `ddr3_wb_dual_channel_line.sv`: full-capacity dual-channel dispatch slice
  with line-level backend contracts, including mask-preserving and no-DM RMW
  modes;
- `ddr3_ctrl.sv`: init-gated dual-channel controller shell that connects the
  dispatch bridge to two init sequencers and two scheduler adapters, muxes init
  versus runtime command pins, and exposes packetized compatibility data ports
  until the board DQS/DQ PHY consumes the line-level contract directly;
- `ddr3_ctrl_line.sv`: init-gated dual-channel controller shell that exposes the
  full line-level PHY contract directly, including write/read transfer-start
  pulses aligned to issued scheduler commands.

The write/read slice proves command ordering and timing in RTL and is exercised
against one Micron x8 model with the byte-lane packetizer feeding an ideal
testbench DQS/DQ agent. The bank machine, scheduler, refresh requester, and
single-channel scheduler adapter are the first scheduler-owned blocks, and the
refresh requester now has idle plus focused active-traffic deadline proofs. The
data boundary has one x8 lane packetizer, one full 64-bit-channel line
packetizer, a line-to-x8-lane adapter, a line-to-x8-burst adapter, one x8 lane
PHY timing core, one fast-domain x8 burst sequencer, one x8 burst clock bridge,
one line-to-fast-burst PHY shell, one line-to-lane PHY timing bridge, a
line-backed Wishbone-to-channel bridge, and a pre-PHY controller shell tying
those pieces to the dual-channel command path. The full-capacity address map is
explicit and formally checked. The board has route-proven DQ/DQS primitive and
local x8 burst-launch probes, but there is still no calibrated
hardware-validated DDR3 read/write path.

Rules for adding new RTL:

1. Add the formal contract or simulation harness in the same change.
2. Keep timing/geometry constants centralized and reviewable.
3. Keep controller scheduling separate from board-specific PHY pin work.
4. Preserve the BRAM JTAG/Wishbone hardware path until DDR3 has its own
   hardware evidence.

Recommended first RTL slices:

- typed mode-register field helpers,
- a controller-side bridge that feeds preloaded x8 burst sequencers without
  pulling wide line arbitration into `clk_dq`,
- a Micron-model runtime loopback that drives `ddr3_ctrl` through the future
  PHY bridge,
- a backend merge/read-modify-write path before partial writes are exposed as
  hardware validated.
