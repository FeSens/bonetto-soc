# ddr3 controller interface

Top module: `ddr3_ctrl`

`ddr3_ctrl` is a controller-level block, not a complete board PHY wrapper. It
owns JEDEC init, runtime command scheduling, Wishbone responses, MPR reads, and
MRS rewrite requests. A board integration instantiates `ddr3_phy` beside it and
wires the PHY data/control ports to the physical pins.

## Parameters

| Parameter | Default | Notes |
|---|---:|---|
| `WB_DATA_W` | `32` | Wishbone data width. Current runtime is validated at 32 bits. |
| `WB_ADDR_W` | `28` | Word address width into `{bank,row,col[COL_BITS-1:3]}`. |
| `DDR3_PART` | `"MT41K256M8DA-125"` | Documentation guard for the selected timing block. The active RTL constants come from `ddr3_params.vh`. |
| `SPEED_GRADE` | `1600` | Documentation guard for the selected speed bin. |
| `ROW_BITS` | `DDR3_ROW_BITS` | From `ddr3_params.vh`; 15 for MT41K256M8. |
| `BANK_BITS` | `DDR3_BANK_BITS` | DDR3 is 3 bank bits. |
| `COL_BITS` | `DDR3_COL_BITS` | 10 for MT41K256M8. Bottom 3 column bits are absorbed by BL8. |
| `DQ_BITS` | `8` | Per-byte-lane DQ width. |
| `NUM_BYTE_LANES` | `9` | PHY-facing byte lanes. YPCB-00338 top uses 4 active lanes. |
| `SERDES_RATIO` | `4` | Fabric-to-DDR serialization ratio. Use `8` for a true BL8 byte lane once the board top enables the full-width PHY path. |
| `WB_BURST_WORD_BITS` | `0` | Low Wishbone word-address bits inside one BL8 burst. Keep `0` for the current validated CH0 image; use `4` for a 64-bit channel exposed as 32-bit words with the full burst-capable PHY path. |

Adding a new memory part means adding one timing/geometry block to
`rtl/ddr3_params.vh` and selecting it at compile time. Do not edit runtime
timing constants in board tops.

## Operating-Point Selection

`rtl/ddr3_params.vh` defaults to `DDR3_RATE_800`, matching the current
YPCB-00338 hardware evidence. The MT41K256M8DA-125 table can also be compiled
with `DDR3_RATE_1600` to select the full `-125` speed-bin timing profile:

```sh
make -C ip/ddr3 sim-init DDR3_DEFINES=-DDDR3_RATE_1600
make -C boards/ypcb-00338 build/bonetto_soc_ypcb00338.json DDR3_DEFINES=-DDDR3_RATE_1600
```

This switch changes the JEDEC constants and mode-register encodings consumed by
the controller. It does not by itself validate the board at DDR3-1600; the board
clocking, leveling, route timing, and hardware validation gates still decide
whether that profile is usable.

## Wishbone Slave

| Direction | Signal | Width | Notes |
|---|---|---:|---|
| input | `i_clk` | 1 | Wishbone response clock. On YPCB-00338 this is `clk_sys`. |
| input | `i_clk_phy` | 1 | Runtime command clock. Currently tied to `clk_sys`. |
| input | `i_rst` | 1 | Synchronous reset for controller/runtime. |
| input | `i_wb_cyc` | 1 | Wishbone cycle. |
| input | `i_wb_stb` | 1 | Wishbone strobe. |
| input | `i_wb_we` | 1 | Write when high, read when low. |
| input | `i_wb_adr` | `WB_ADDR_W` | Word address: `{bank,row,col[COL_BITS-1:3]}`. |
| input | `i_wb_dat` | `WB_DATA_W` | Write data. |
| input | `i_wb_sel` | `WB_DATA_W/8` | Byte enables; current board path drives all lanes enabled. |
| output | `o_wb_stall` | 1 | Stalls before init completes or while runtime is busy. |
| output | `o_wb_ack` | 1 | One-cycle response pulse. |
| output | `o_wb_dat` | `WB_DATA_W` | Read data. |
| output | `o_wb_err` | 1 | Currently tied low. |

## DDR3 Command Side

| Direction | Signal | Width | Notes |
|---|---|---:|---|
| output | `o_ddr3_reset_n` | 1 | DDR3 reset. |
| output | `o_ddr3_cke` | 1 | Clock enable. |
| output | `o_ddr3_odt` | 1 | ODT control. |
| output | `o_ddr3_cs_n` | 1 | Chip select. |
| output | `o_ddr3_ras_n` | 1 | RAS. |
| output | `o_ddr3_cas_n` | 1 | CAS. |
| output | `o_ddr3_we_n` | 1 | WE. |
| output | `o_ddr3_ba` | `BANK_BITS` | Bank address. |
| output | `o_ddr3_addr` | `ROW_BITS` | Row/column/mode address bus. |

## PHY Data Side

| Direction | Signal | Width | Notes |
|---|---|---:|---|
| input | `i_phy_rd_data` | `NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO` | Captured read burst data from PHY. |
| input | `i_phy_rd_valid` | 1 | Read data valid. |
| output | `o_phy_wr_data` | same | Serialized write burst payload for PHY. |
| output | `o_phy_wr_valid` | 1 | Write payload valid. |
| output | `o_phy_rd_capture` | 1 | PHY should capture incoming read burst. |

## Calibration And Debug

| Direction | Signal | Width | Notes |
|---|---|---:|---|
| input | `i_mpr_req` | 1 | Request an MPR read command. |
| input | `i_mpr_addr` | 13 | MPR read address bits. |
| output | `o_mpr_busy` | 1 | MPR request in flight. |
| input | `i_mrs_req` | 1 | Request an MRS rewrite. |
| input | `i_mrs_ba` | `BANK_BITS` | Mode register select. |
| input | `i_mrs_addr` | `ROW_BITS` | Mode register payload. |
| output | `o_mrs_busy` | 1 | MRS rewrite in flight. |
| output | `o_init_done` | 1 | JEDEC init completed. |
| output | `o_init_error` | 1 | Init FSM trapped. |
| output | `o_init_error_code` | 4 | Init error code. |
| output | `o_init_state` | 5 | Init FSM state for host debug. |

## Addressing

Runtime splits `i_wb_adr` as:

```text
burst-local address = {
  bank[BANK_BITS-1:0],
  row[ROW_BITS-1:0],
  col[COL_BITS-1:3],
  word_offset[WB_BURST_WORD_BITS-1:0]
}
```

The bottom three DDR3 column bits are fixed to zero because each command is a
BL8 burst. With the current validated YPCB-00338 image,
`WB_BURST_WORD_BITS=0`, so the MT41K256M8 geometry (`3 + 15 + 7` bits) exposes
25 word-address bits, or 128 MiB, through the 32-bit Wishbone aperture.

For a full 64-bit channel, one BL8 transfer carries 64 bytes, or sixteen
32-bit Wishbone words. That mode uses `WB_BURST_WORD_BITS=4`. In offset mode,
reads select the requested 32-bit word out of the captured BL8 payload. Writes
perform a runtime read-modify-write cycle: read the BL8 payload, merge
`i_wb_dat` according to `i_wb_sel`, and write the full payload back.

The current YPCB-00338 hardware image still uses `WB_BURST_WORD_BITS=0`
because the full-width `SERDES_RATIO=8` PHY path still needs top-level routing,
timing closure, and hardware proof.
If `WB_ADDR_W` is wider than the consumed channel-local address, the runtime
deliberately ignores the high bits; board-level dual-channel integration should
decode channel select outside each per-channel `ddr3_ctrl` instance.
