# DDR3 Porting Checklist

Use this when moving `ip/ddr3` into another board or project.

## 1. Select The Memory Geometry

- Add or select a part block in `rtl/ddr3_params.vh`.
- Confirm `ROW_BITS`, `COL_BITS`, `BANK_BITS`, `DQ_BITS`, `CL`, `CWL`,
  `tRCD`, `tRP`, `tRFC`, `tREFI`, `tWR`, and mode register values against the
  part datasheet.
- Keep timing constants in tCK units. The controller converts tCK waits to the
  fabric clock using `DDR3_CK_PER_SYS`.

## 2. Wire The Controller

- Instantiate `ddr3_ctrl` with the desired `WB_DATA_W`, `WB_ADDR_W`,
  `ROW_BITS`, `BANK_BITS`, `COL_BITS`, `DQ_BITS`, `NUM_BYTE_LANES`, and
  `SERDES_RATIO`.
- Drive `i_wb_adr` as `{bank,row,col[COL_BITS-1:3]}`.
- Keep the Wishbone clock and runtime command clock synchronous unless the
  wrapper adds a real CDC bridge.
- Do not change the Wishbone signal names or response semantics.

## 3. Wire The PHY

- Instantiate `ddr3_phy` for Xilinx 7-series targets.
- Keep the primary generated clocks observable during bring-up. On
  YPCB-00338, `clk_sys`, `clk_dq`, and `clk_phy_x4` are exposed through status
  registers before trusting memory failures.
- Map byte lanes explicitly in the board top. YPCB-00338 uses logical lanes
  0,1,2,3 mapped to physical lanes 0,1,2,4 because physical lane 3 reads as
  stuck zero on the tested board.
- Decide whether the board uses DM or TDQS. YPCB-00338 enables TDQS and leaves
  DM unbonded.

## 4. Constrain And Route

- Add board pin constraints for command/address, DQ, DQS, CK, reset, CKE, ODT,
  and any active DM pins.
- Route with a fixed seed once timing closes and record the seed and final
  nextpnr clock lines.
- Require at least the intended DDR clock on `clk_dq`; for the validated
  YPCB-00338 DDR3-800 point, `clk_dq >= 400 MHz` and `clk_sys >= 100 MHz`.

## 5. Validate

Run the cheap gates first:

```sh
make -C ip/ddr3 cocotb
make -C ip/ddr3 sim-micron
make -C ip/ddr3 formal
```

Then run board-level gates:

```sh
make -C boards/<board>/sim -f Makefile.memtest
cd boards/<board>/formal && sby -f memtest_lite.sby
```

On hardware:

```sh
make -C boards/<board> program
make -C boards/<board> xvc
make -C boards/<board> validate-ddr3
```

The hardware validator should cover deterministic boundaries, address walking,
every data bit and byte lane, contiguous windows, an XOR checksum sweep, random
accesses, and an autonomous soak with no memtest errors.

## 6. Record Evidence

Commit a board validation note with:

- git commits under test,
- route seed and final timing lines,
- bitstream/program command,
- validation command and JSON path,
- final status flags and error counter,
- any board-specific lane map or calibration bypasses.
