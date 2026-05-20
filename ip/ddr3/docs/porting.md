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
- If the board does not expose DM pins, set the line bridge for no-DM
  read-modify-write behavior before validating byte-select Wishbone writes in
  hardware.
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

Pre-PHY YPCB-00338 controller gate:

```sh
make -C boards/ypcb-00338 ddr3-ctrl-line-loopback-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-loopback-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-loopback
make -C boards/ypcb-00338 ddr3-ctrl-line-laneloop-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-laneloop-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-laneloop
make -C boards/ypcb-00338 ddr3-ctrl-line-cmdprobe-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdprobe-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdprobe
make -C boards/ypcb-00338 ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdlaneloop-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdlaneloop
```

The line-controller loopback proves the live JTAG/Wishbone path through the
clean controller, scheduler, and complete BL8 line boundary in FPGA fabric. It
does not prove external DDR3 storage because the board DQ/DQS pins remain
high-Z and the DDR3 devices are held in reset.

The line-to-lane loopback inserts the synthesizable `ddr3_line_to_lanes`
adapter after the line controller and before internal x8 lane memories. Passing
it proves the RTL boundary that a future DQ/DQS PHY should consume, still
without validating external DDR3 storage.

The command-probe gate is the next pre-PHY step. It drives reset, CKE, ODT, CK,
command, bank, and address pins on both physical DDR3 channels while keeping
DQ/DQS high-Z and returning data through the internal line loopback. On
YPCB-00338 this gate selects the no-DM read-modify-write line bridge, so
byte-select Wishbone writes are preserved without relying on missing external
DM pins. Passing it proves the controller command stream reaches the
board-facing pin domain, but it is still not external-memory validation.

The command plus line-to-lane loopback combines the command-probe path with
`ddr3_line_to_lanes` and internal x8 lane memories. Passing it is the current
pre-PHY evidence that the clean controller, command-pin CDC, complete BL8 line
boundary, and reusable lane adapter work together on the real FPGA. Do not call
DDR3-800 validated until the DQ/DQS PHY is connected, the 400 MHz paths close
without waivers, and the JTAG/Wishbone validator reads data back from real DDR3
storage.

Real external-memory hardware gates must cover boundaries, address walking,
every data bit, every byte lane, contiguous windows, checksum sweep,
randomized accesses, and soak.
