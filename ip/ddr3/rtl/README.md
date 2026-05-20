# DDR3 RTL Reset

The previous DDR3 controller and PHY implementation was intentionally removed.
Keep new DDR3 RTL out of this directory until the BRAM-only JTAG/Wishbone proof
flow is the baseline and the next implementation plan is explicit.

The formal harnesses, board pin references, and bring-up notes remain outside
this directory so the next controller can be built against preserved checks
rather than inherited timing/debug debt.
