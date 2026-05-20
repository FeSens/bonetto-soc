# DDR3 Full-Capacity Bring-Up Plan

The current repository state is a DDR3 clean-sheet restart. This file describes
the target evidence ladder, not an already working DDR3 image.

## Final Target

| Item | Target |
|---|---:|
| Board | YPCB-00338 |
| FPGA | Kintex-7 `xc7k480t-ffg1156-2` |
| Channels | 2 |
| Data width per channel | 64 bits |
| Optional ECC lane | 8 bits per channel |
| DRAM part | Micron MT41K256M8DA-125 |
| Data capacity | 4 GiB across CH0 + CH1 |
| Final transfer rate | DDR3-1600 |
| Final CK | 800 MHz |

## Address Map

The live RTL now uses this 30-bit 32-bit-word address map:

```text
global[29]      channel select
global[28:26]   bank
global[25:11]   row
global[10:4]    column[9:3]
global[3:0]     word inside the 64-byte BL8 line
```

This keeps each 64-byte full-channel BL8 transfer contiguous in the Wishbone
word address space and covers the full 4 GiB installed data capacity across the
two 64-bit channels. The map is implemented in `rtl/ddr3_addr_decode.sv` and
covered by `formal/addr_decode_wrapper.sv` plus `sim/tb_addr_decode.sv`.
`rtl/ddr3_wb_dual_channel.sv` now uses this decoder to route global Wishbone
requests into channel 0 or channel 1, with formal and simulation coverage for
single-outstanding channel dispatch. This is still pre-PHY and pre-hardware; it
only proves the bus-facing channel split.

`rtl/ddr3_channel_sched.sv` is the first scheduler-side consumer of the same
line address. It proves the next boundary: a BL8 line request can be accepted
by the scheduler before the matching RD/WR command issues, and the data path
must wait for the explicit transfer-start pulse.

`rtl/ddr3_ctrl.sv` is the current pre-PHY top-level controller boundary. It
combines the dual-channel Wishbone dispatch bridge, two init sequencers, and
two scheduler adapters. The live unit bench checks the first integrated path:
pre-init Wishbone stalls, then a channel-0 write and channel-1 read pass
through scheduler-issued WR/RD commands into the full-channel packet ports.

## Speed Ladder

Do not skip rungs:

| Gate | CK | Transfer rate | Approx controller clock with 1:4 ratio |
|---|---:|---:|---:|
| DDR3-800 | 400 MHz | 800 MT/s | 100 MHz |
| DDR3-1066 | 533 MHz | 1066 MT/s | 133 MHz |
| DDR3-1333 | 667 MHz | 1333 MT/s | 167 MHz |
| DDR3-1600 | 800 MHz | 1600 MT/s | 200 MHz |

DDR3-800 is the slowest normal validation point because the Micron model's
2Gb `-125` parameters reject `tCK` slower than 3300 ps with DLL enabled, and
the model states DLL-off mode is not fully modeled.

## Board Sources Of Truth

Use the public YPCB-00338 reference files for pin and geometry checks before
changing board constraints:

| Reference | Use |
|---|---|
| `https://github.com/TiferKing/ypcb_00338_1p1_hack` | Board reverse-engineering archive |
| `constraints/MEMORY_CH0.ucf` | Channel-0 DDR3 pins |
| `constraints/MEMORY_CH1.ucf` | Channel-1 DDR3 pins |
| `ypcb003381p1/1.0/mig_0.prj` | CH0 MIG geometry reference |
| `ypcb003381p1/1.0/mig_1.prj` | CH1 MIG geometry reference |
| `ypcb003381p1/1.0/mig_01.prj` | Dual-controller MIG geometry reference |

The MIG references are geometry and pin references, not proof that our open
flow reaches the same speed.

## Required Evidence Per Rung

For each speed grade:

1. Formal proof of the relevant controller slice.
2. Micron model simulation at that speed.
3. Route with fixed seed and recorded timing.
4. FPGA programming with `done`.
5. JTAG/Wishbone memory validator on both channels.
6. Evidence note with final status flags and first-failure fields if any.

Hardware validation must include:

- deterministic boundary patterns;
- address walking;
- every 32-bit data bit and byte lane;
- contiguous alignment/window coverage;
- random unique addresses;
- XOR checksum sweep;
- autonomous soak with zero errors.

## Historical Caution

The previous full-width experiments showed that route timing and hardware
behavior can diverge quickly when command serialization, read capture, and RMW
logic are changed together. Keep future steps narrow: one architectural change,
one formal/sim extension, one hardware gate.
