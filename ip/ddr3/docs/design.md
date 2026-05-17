# ddr3_ctrl — design

> Historical blueprint. The validated YPCB-00338 integration is now documented
> in `../README.md`, `interface.md`, `porting.md`, and
> `../../../boards/ypcb-00338/DDR3_VALIDATION.md`. Keep this file as design
> rationale, but use the validation notes for current signoff status.

A parameterisable DDR3 controller targeting JEDEC DDR3-{1066, 1333, 1600, 1866} chips. First target: **Micron MT41K256M8DA-125** (2 Gb, x8, DDR3-1600) — eight of them in 64-bit configuration on the Inspur YPCB-00338. The same RTL must serve other 7-series boards by reparameterising.

This document is the **engineering blueprint**: every RTL change is justified against the timing parameters, FSM, and verification plan below. Per `INVARIANTS.md` #6, all JEDEC timings declared here are enforced by formal cover properties in `ip/ddr3/formal/`.

---

## 1. Device targets (initial)

| Parameter | MT41K256M8DA-125 | Other targets |
|---|---|---|
| Density | 2 Gb (256 Mb × 8) | parameterised |
| Organization | x8 (8 DQ pins / chip) | x4 / x8 / x16 |
| Banks | 8 | 8 (DDR3 standard) |
| Rows × Cols | 32 K × 1 K | declared per part |
| Speed grade | -125 → DDR3-1600 | -107E (1866), -125 (1600), -15E (1333), -187E (1066) |
| Bus width on YPCB-00338 | 64 bits + 8 ECC | per board |

The board carries two channels (CH0/CH1) each 72 bits wide (64 data + 8 ECC). Iteration 2 targets a single 64-bit channel (CH0) with no ECC. Iteration 3 adds ECC; iteration 4 adds the second channel.

---

## 2. JEDEC DDR3-1600 timing parameters (-125 speed bin)

All values from JEDEC Standard No. 79-3F (DDR3 SDRAM Specification) and the MT41K datasheet. Declared in `ip/ddr3/rtl/ddr3_params.vh` and used by both the controller and the formal cover properties.

| Symbol | Meaning | Value | Units |
|---|---|---|---|
| `tCK`  | Clock period | 1.25 | ns |
| `tCL`  | CAS latency | 11 | tCK |
| `tCWL` | CAS write latency | 8 | tCK |
| `tRCD` | ACT→RD/WR | 13.75 | ns (≥11 tCK) |
| `tRP`  | PRECHARGE→ACT | 13.75 | ns (≥11 tCK) |
| `tRAS` | ACT→PRECHARGE (min) | 35 | ns (≥28 tCK) |
| `tRC`  | ACT→ACT (same bank) | 48.75 | ns (≥39 tCK) |
| `tRFC` | REF→any (refresh recovery) | 160 | ns (2Gb part) |
| `tREFI`| Avg refresh interval | 7.8 | µs (≤T<85°C) |
| `tWR`  | WR→PRECHARGE | 15 | ns (≥12 tCK) |
| `tWTR` | WR→RD (same rank) | 7.5 | ns (≥6 tCK) |
| `tRTP` | RD→PRECHARGE | 7.5 | ns (≥6 tCK) |
| `tRRD` | ACT→ACT (diff bank) | 7.5 | ns (≥6 tCK, 8-bank) |
| `tFAW` | 4-ACT rolling window | 40 | ns (≥32 tCK, 8-bank) |
| `tCCD` | CAS→CAS | 4 | tCK (burst-8 default) |
| `tMOD` | MRS→any non-MRS | 15 | ns (≥12 tCK) |
| `tMRD` | MRS→MRS | 4 | tCK |
| `tDLLK`| DLL re-lock | 512 | tCK |
| `tZQinit` | ZQCAL init duration | 512 | tCK |

Burst length is fixed at **BL8** (eight 64-bit transfers per command = 64 bytes at 64-bit interface). Half-burst (BC4) is not supported in iter 2.

---

## 3. Init sequence

JEDEC mandates a strict power-on order. The init FSM (`ddr3_init.v`) implements steps 1–7 below; on completion it raises `init_done` and hands off to the runtime FSM. Failure at any step is fatal — the FSM never retries silently; instead `init_error_code [3:0]` latches and `init_done` stays low for host inspection via JTAG-UART.

| Step | What | Duration | Verification |
|---|---|---|---|
| 1 | VDD/VDDQ ramp, CK stable, RESET# low | ≥200 µs after stable power | counted-cycle assert |
| 2 | RESET# released | ≥500 µs before CKE | counted-cycle assert |
| 3 | CKE asserted, NOP only | ≥`tXPR` = max(5 tCK, tRFC+10 ns) ≈ 170 ns | counted-cycle assert |
| 4 | MRS **MR2** (CWL, RTT_WR=disabled, ASR off) | tMRD = 4 tCK | formal: command sequence ordering |
| 5 | MRS **MR3** (MPR off) | tMRD | … |
| 6 | MRS **MR1** (DLL on, RTT_NOM=RZQ/6, output drive RZQ/7, AL=0) | tMRD | … |
| 7 | MRS **MR0** (BL=8, CL=11, DLL_RST=1, WR_RECOVERY=12) | tMOD | … |
| 8 | ZQCL (long calibration) | tZQinit = 512 tCK = 640 ns | Micron model checks DCI value |
| 9 | NOP wait until DLL locked | tDLLK = 512 tCK | … |
| 10 | First REF (recommended) | tRFC | … |
| 11 | `init_done <= 1` — controller enters NORMAL state | — | cover property |

Calibration (read levelling, write levelling, gate training, per-bit deskew) is **iter 3** and gates `init_done` separately.

---

## 4. Architecture

```
                                          +-------------------+
WB master --> wb_to_cmd ----+--+ cmd_q --> | bank state machines| --> phy --> DDR3 pins
                            |  |   ^      |  (8 in parallel)   |
                            |  |   |      +--------+-----------+
                            v  v   |               |
                       refresh_sched              JEDEC timing
                                ^                  arc tracking
                                | tREFI
                                |
                         (init FSM owns the bus until init_done)
```

### 4.1 `wb_to_cmd`

Translates Wishbone B4 pipelined transactions into `(bank, row, col, op)` commands. Burst translation: each WB write becomes one BL8 issue (BL8 = 64 bytes for a x64 interface = 16 × 32-bit words). For granular writes, partial-write support uses DDR3's data-mask pins. Read uses BL8 too; the controller buffers the burst and dribbles results back over Wishbone.

### 4.2 `cmd_queue`

Eight-deep FIFO of pending commands, arbitrated per-bank. Allows interleaving across banks while one is still in `tRC` recovery. Reorder strictly within FIFO (no out-of-order commits) to keep verification tractable in iter 2; iter 3 may add a simple oldest-first-with-bank-skip reorder.

### 4.3 Bank state machines

One instance per bank (8 total). Each tracks:

| State | Meaning |
|---|---|
| `IDLE` | No row open in this bank |
| `ACTIVATING` | ACT issued; counting down `tRCD` before RD/WR allowed |
| `OPEN` | Row open; can RD / WR / new commands |
| `PRECHARGING` | PRECHARGE issued; counting down `tRP` |
| `REFRESHING` | (whole device) REF in flight; bank inaccessible for `tRFC` |

Per-bank timers track `tRAS`, `tRC`, `tRCD`, `tWR`, `tRTP`. The bank FSM **never** issues a command that would violate any timing arc — the arc is asserted formal-style: `assert property (@(posedge clk) cmd_valid && cmd_act && (bank_state == OPEN) |-> bank_t_ras_met)`.

### 4.4 `refresh_sched`

A free-running counter tracks elapsed time since the last REF. When `time_since_ref ≥ tREFI`, the scheduler raises `refresh_pending`. The cmd_queue then drains, issues an all-bank PRECHARGE, REF, and waits `tRFC` before resuming normal commands. Postponable up to 8 REFs (JEDEC allowance) — iter-2 ignores postponement, issues at every tREFI tick.

### 4.5 `phy`

Iter-2 PHY is **synchronous** — uses the 50 MHz system clock divided/multiplied to generate the DDR3 clock. No IDELAYE2/ISERDESE2; uses ordinary IOB FFs. This sacrifices speed (we'll only achieve DDR3-400 or similar) but lets us validate the controller against the Micron model without dealing with FPGA-specific calibration.

Iter-3 PHY introduces:
- MMCM-generated 800 MHz CK + 90° phase-shifted DQS
- OSERDESE2 for DQ writes, ISERDESE2 for DQ reads
- IDELAYE2 for per-bit timing tuning during read levelling
- Write levelling (DDR3 mode register `MR1`)
- Read gate training (per-byte DQS gate alignment)

### 4.6 ECC (iter 3)

YPCB-00338 has 8 ECC bits per 64-bit word. SECDED Hamming(72,64) gives single-error correction and double-error detection. Encoding/decoding lives in `ip/ddr3/rtl/ddr3_ecc.v`.

---

## 5. Wishbone interface (locked in iter 1)

Same port set as [wb_memory](../../wb-memory/docs/interface.md). The board top can swap `wb_memory` for `ddr3_ctrl` with **no other RTL changes**. See `ip/ddr3/docs/interface.md` for the locked port list.

Parameter additions for `ddr3_ctrl`:

| Parameter | Default | Description |
|---|---|---|
| `DDR3_PART` | `"MT41K256M8DA-125"` | string; selects the timing parameter set |
| `SPEED_GRADE` | 1600 | MT/s; cross-checks DDR3_PART speed bin |
| `BUS_WIDTH` | 64 | DQ width in bits (8 × x8 chips) |
| `BANK_COUNT` | 8 | JEDEC fixed at 8 for DDR3 |
| `ROW_BITS` | 15 | log2(rows per bank) |
| `COL_BITS` | 10 | log2(columns per row) |
| `CL` / `CWL` | 11 / 8 | derived from DDR3_PART; overridable for testing |

`ddr3_params.vh` provides `localparam` defaults for every supported part — adding a new chip is a one-block insert.

---

## 6. Verification (per INVARIANTS #5 #6 #9)

### 6.1 Formal

- **Wishbone protocol compliance** — wrap `ddr3_ctrl`'s WB slave in `fwb_slave.v` exactly as `wb_memory` does today. Identical pattern.
- **JEDEC timing arcs** — assertions on the bank FSM:
  ```
  assert property (@(posedge clk_phy)
    cmd_valid && cmd_is_act && (bank_state[i] == OPEN)
    |-> bank_t_rc_counter[i] == 0);
  ```
  One per timing parameter (tRC, tRAS, tRP, tRCD, tWR, tWTR, tRTP, tRRD, tFAW, tCCD).
- **Refresh deadline** — cover property:
  ```
  cover property (@(posedge clk)
    time_since_last_ref < tREFI && cmd_is_ref);
  ```
  Reverse-cover (must never happen): `time_since_last_ref > tREFI`.

### 6.2 Simulation

Verilator + Micron's MT41K SystemVerilog behavioral model (vendored at `ip/ddr3/sim/vendor/ddr3.v`). Testbench (`tb_ddr3_init.cpp`) instantiates `ddr3_ctrl` + one `ddr3` instance per byte lane, drives a Wishbone master that:

1. Holds reset 250 µs.
2. Waits `init_done`.
3. Writes a known pattern to 1 K random addresses across the bank space.
4. Reads it back.
5. Asserts every read matches every write.

The Micron model asserts JEDEC protocol violations natively — any timing miss aborts the sim with a SystemVerilog `$display` + non-zero exit code.

### 6.3 Hardware

Final witness on the YPCB-00338: `make program` then `tools/jtag_uart_read.py` polls `pass_count` from the memtest harness. Identical to iter-2 wb_memory bring-up, but reading 64-bit DDR3 instead of 1-cycle BRAM.

---

## 7. Roadmap

| Iter | Deliverable |
|---|---|
| **1** | wb_memory stand-in, contract locked. ✅ shipped |
| **2** | `ddr3_init.v` + Wishbone slave + sync PHY at DDR3-400; formal-passing init; Verilator vs Micron model passing |
| **3** | High-speed PHY (MMCM + ISERDES/OSERDES + IDELAY), write/read levelling, gate training |
| **4** | ECC, second channel (CH1), bandwidth optimisation (cmd reorder) |
| **5** | Other boards — Arty A7, KC705, anything 7-series with MT41K — proves parameterisation |

Each step gates on formal + sim + hardware as today.

---

## 8. References

- JEDEC No. 79-3F — DDR3 SDRAM Standard (2012)
- Micron MT41K256M8 datasheet — `ip/ddr3/sim/vendor/README-MICRON.txt` for the model's own docs
- Micron TN-41-07 — "DDR3 Power-Up, Initialization and Reset Routine"
- Xilinx UG586 — "7 Series MIS DDR3 SDRAM" (PHY techniques only — we don't use their MIG IP)
- LiteDRAM — reference open-source implementation: https://github.com/enjoy-digital/litedram
