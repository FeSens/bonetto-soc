# DDR3 RTL Restart Area

No active DDR3 controller or PHY RTL lives here yet.

Rules for adding new RTL:

1. Add the formal contract or simulation harness in the same change.
2. Keep timing/geometry constants centralized and reviewable.
3. Keep controller scheduling separate from board-specific PHY pin work.
4. Preserve the BRAM JTAG/Wishbone hardware path until DDR3 has its own
   hardware evidence.

Recommended first RTL slices:

- a typed DDR3 command encoder/decoder,
- a JEDEC init sequencer that can pass the Micron model,
- a single-bank open-row scheduler wired into the command timing monitor.
