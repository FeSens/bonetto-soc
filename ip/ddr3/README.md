# ddr3

Parameterised DDR3 controller. Iteration 1 is a Wishbone-protocol-compliant **stub** so the board top-level wires the FPGA's DDR3 pins out today and the real controller drops in behind the same port set in iter 2.

**Locked in iter 1:**

- Wishbone B4 pipelined slave port set (`docs/interface.md`).
- Parameterisation surface (`DDR3_PART`, `SPEED_GRADE`, bus widths).
- Address window in `verification/common/soc_params.vh` (`DDR3_BASE`, `DDR3_SIZE_WORDS`).

**Lands in iter 2:**

- Init sequence (200 µs CKE-low, MR0/MR1/MR2/MR3 program, ZQCAL).
- Activate / read / write / precharge / refresh state machine with full JEDEC timing arc enforcement.
- DDR3 PHY (IDELAYE2 + ISERDESE2 + OSERDESE2 + write leveling).
- Read levelling, gate training, per-bit deskew.
- Micron MT41K SystemVerilog model as the formal/sim peer.

See `docs/interface.md` for the port contract and JEDEC parameter map.
