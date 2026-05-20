# DDR3 Porting Checklist

Use this checklist when the clean-sheet controller is wired into a board.

## 1. Identify The Memory

- Confirm density, speed grade, organization, row bits, column bits, bank bits,
  DQ width, and rank count from the board reference and datasheet.
- For YPCB-00338, the target part is Micron `MT41K256M8DA-125`, x8, 2Gb.
- Compile Micron model simulations with `-Dden2048Mb -Dsg125 -Dx8`.

## 2. Define The Address Map

- Document channel select, bank, row, column, and BL8 word-offset bits.
- Prove channel decode is one-hot.
- Prove local address bits are preserved through the board wrapper.

## 3. Wire The Controller

- Keep the Wishbone interface compatible with `docs/interface.md`.
- Keep the command scheduler observable by the timing monitor.
- Keep all board-specific lane swaps out of the scheduler.

## 4. Wire The PHY

- Make byte-lane maps explicit.
- Decide whether the ECC byte lane is data, ECC, or unused for the current
  image.
- Keep DQS/DQ delay and leveling state visible through debug/status registers.

## 5. Constrain And Route

- Import command/address, CK, CKE, ODT, reset, DQ, DQS, and optional DM pins.
- Record route seed and final timing lines.
- Do not call a speed grade validated until the board is programmed and the
  JTAG/Wishbone validator passes.

## 6. Validate

Cheap gates:

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
make validate-jtag-bram BOARD=ypcb-00338
```

Future controller gates:

```sh
make -C ip/ddr3 sim-init
make -C ip/ddr3 sim-runtime
make -C ip/ddr3 sim-channel
make -C ip/ddr3 formal-controller
```

Hardware gates must cover boundaries, address walking, every data bit, every
byte lane, contiguous windows, checksum sweep, randomized accesses, and soak.
