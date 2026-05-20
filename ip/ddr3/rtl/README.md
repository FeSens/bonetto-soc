# DDR3 RTL Area

The only active RTL slice here is the DDR3-800 initialization sequencer:

- `ddr3_params.vh`: shared command encodings, mode registers, geometry, and
  DDR3-800 timing waits;
- `ddr3_init_seq.sv`: reset, CKE, MR2, MR3, MR1, MR0, ZQCL, first REF.

There is still no runtime bank scheduler, Wishbone frontend, PHY, calibration,
dual-channel wrapper, or hardware-validated DDR3 path.

Rules for adding new RTL:

1. Add the formal contract or simulation harness in the same change.
2. Keep timing/geometry constants centralized and reviewable.
3. Keep controller scheduling separate from board-specific PHY pin work.
4. Preserve the BRAM JTAG/Wishbone hardware path until DDR3 has its own
   hardware evidence.

Recommended first RTL slices:

- a typed DDR3 command encoder/decoder,
- a single-bank open-row scheduler wired into the command timing monitor.
