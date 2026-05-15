# jtag-uart

BSCANE2-based UART exposed as a Wishbone B4 slave. The host (Mac) writes/reads bytes through the same JTAG cable that programs the FPGA. Primary debug channel for the on-board memory test.

**Iteration 1 status:** stub. The real BSCANE2 + FIFO implementation lands in iteration 2. The port set is locked in `docs/interface.md` now so the board top-level can wire it without churn later.

See `docs/interface.md` for the register map.
