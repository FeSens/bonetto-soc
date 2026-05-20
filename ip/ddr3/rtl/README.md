# DDR3 RTL Area

The active RTL slices are deliberately small and scheduler-facing:

- `ddr3_params.vh`: shared command encodings, mode registers, geometry, and
  DDR3-800 timing waits;
- `ddr3_init_seq.sv`: reset, CKE, MR2, MR3, MR1, MR0, ZQCL, first REF, and
  post-DLL-lock wait before `done`;
- `ddr3_single_read_seq.sv`: one conservative single-bank ACT, READ, PRE, REF
  command sequence after init;
- `ddr3_single_write_read_seq.sv`: one conservative single-bank ACT, WRITE,
  READ, PRE, REF command sequence after init.

The write/read slice proves command ordering and timing in RTL and is exercised
against one Micron x8 model with an ideal testbench DQS/DQ agent. There is still
no controller-owned data capture, real write datapath, runtime bank scheduler,
Wishbone frontend, PHY, calibration, dual-channel wrapper, or
hardware-validated DDR3 path.

Rules for adding new RTL:

1. Add the formal contract or simulation harness in the same change.
2. Keep timing/geometry constants centralized and reviewable.
3. Keep controller scheduling separate from board-specific PHY pin work.
4. Preserve the BRAM JTAG/Wishbone hardware path until DDR3 has its own
   hardware evidence.

Recommended first RTL slices:

- typed mode-register field helpers,
- a real controller-owned read/write byte-lane data slice against one Micron x8
  model,
- a single-bank open-row scheduler that reuses the command timing monitor.
