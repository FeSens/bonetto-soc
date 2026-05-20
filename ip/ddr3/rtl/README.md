# DDR3 RTL Area

The active RTL slices are deliberately small and scheduler-facing:

- `ddr3_params.vh`: shared command encodings, mode registers, geometry, and
  DDR3-800 timing waits;
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
- `ddr3_byte_lane.sv`: controller-side x8 BL8 packetizer that emits ordered
  write data/mask beats and captures ordered read data beats;
- `ddr3_wb_frontend.sv`: single-outstanding Wishbone-to-BL8 frontend that
  splits word addresses into line address and word index, places write data and
  byte masks into a BL8 line, and selects read words from backend response
  lines.

The write/read slice proves command ordering and timing in RTL and is exercised
against one Micron x8 model with the byte-lane packetizer feeding an ideal
testbench DQS/DQ agent. The bank machine, scheduler, and refresh requester are
the first scheduler-owned blocks, and the refresh requester now has idle plus
focused active-traffic deadline proofs. There is still no pin-level
controller-owned DQS/DQ PHY, integrated controller, calibration, dual-channel
wrapper, or hardware-validated DDR3 path.

Rules for adding new RTL:

1. Add the formal contract or simulation harness in the same change.
2. Keep timing/geometry constants centralized and reviewable.
3. Keep controller scheduling separate from board-specific PHY pin work.
4. Preserve the BRAM JTAG/Wishbone hardware path until DDR3 has its own
   hardware evidence.

Recommended first RTL slices:

- typed mode-register field helpers,
- a real controller-owned PHY bridge from the byte-lane packet stream to DQS/DQ
  timing against one Micron x8 model,
- a backend merge/read-modify-write path connecting the Wishbone frontend to
  scheduler requests and byte-lane packets.
