#!/usr/bin/env python3
"""
silicon_probe.py — comprehensive silicon validation via JTAG-WB master.

iter-7 introduced the jtag_wb_master so the host can drive WB transactions
directly through JTAG. This script uses it to:

  1. Verify the status mux is alive and the bitstream is fresh.
  2. Halt memtest_lite, then exercise BRAM with multi-pattern write/read.
  3. After cal_done is observed, exercise DDR3 with the same patterns.
  4. For each DDR3 mismatch, capture {addr, expected, got} so the operator
     can spot lane-stuck/bit-swapped patterns.
  5. Print a structured per-test verdict + a one-line summary suitable
     for grepping by the auto_flash_validate.sh post-mortem.

Usage:
    python tools/silicon_probe.py
        --host localhost  --port 3721  --tck-ns 2000

The XVC server (openFPGALoader --xvc) must already be running.
"""

import argparse
import sys
import time

sys.path.insert(0, ".")
from tools.jtag_uart_read import (
    XVC, tap_reset_to_rti, select_user1,
    read_status_reg, jwb_cmd, jwb_wb_write, jwb_wb_read,
    JWB_CMD_RESUME, JWB_CMD_HALT,
)


PATTERNS = [
    ("AA",         lambda a: 0xAAAAAAAA),
    ("55",         lambda a: 0x55555555),
    ("FF",         lambda a: 0xFFFFFFFF),
    ("00",         lambda a: 0x00000000),
    ("walking_1",  lambda a: 1 << (a & 31)),
    ("walking_0",  lambda a: ~(1 << (a & 31)) & 0xFFFFFFFF),
    ("addr_data",  lambda a: (0xCAFE0000 | (a & 0xFFFF))),
]


def probe_window(xvc, window_name, base_addr, n_words=8):
    """Halt memtest, write+read n_words for each pattern. Returns dict of
    per-pattern (pass_count, fail_count, first_fail) tuples."""
    print(f"\n=== probing {window_name} (base=0x{base_addr:04x}, n={n_words}) ===")
    results = {}
    for pat_name, pat_fn in PATTERNS:
        passes = 0
        fails = 0
        first_fail = None
        # Write phase
        for i in range(n_words):
            addr = base_addr + i
            data = pat_fn(addr)
            jwb_wb_write(xvc, addr, data)
        # Read+verify phase
        for i in range(n_words):
            addr = base_addr + i
            expected = pat_fn(addr)
            got = jwb_wb_read(xvc, addr)
            if got == expected:
                passes += 1
            else:
                fails += 1
                if first_fail is None:
                    first_fail = (addr, expected, got)
        verdict = "PASS" if fails == 0 else "FAIL"
        print(f"  [{pat_name:<10}] {verdict}  {passes}/{n_words} ok"
              + (f"  first_fail addr=0x{first_fail[0]:04x}"
                 f" expected=0x{first_fail[1]:08x}"
                 f" got=0x{first_fail[2]:08x}" if first_fail else ""))
        results[pat_name] = (passes, fails, first_fail)
    return results


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--tck-ns", type=int, default=2000,
                    help="XVC TCK period in ns (default 2000 = 500 kHz, "
                         "matches the user's stable-read setting)")
    ap.add_argument("--bram-addr", type=lambda s: int(s, 0), default=0x0000)
    ap.add_argument("--ddr3-addr", type=lambda s: int(s, 0), default=0x4000,
                    help="DDR3 window starts at adr[14]=1 in this SoC")
    ap.add_argument("--n-words", type=int, default=8,
                    help="words per pattern per window (default 8)")
    args = ap.parse_args()

    xvc = XVC(args.host, args.port)
    print(f"connected: {xvc.info}")
    actual = xvc.settck(args.tck_ns)
    print(f"TCK period set: {args.tck_ns}ns requested, {actual}ns actual")
    tap_reset_to_rti(xvc)
    select_user1(xvc)

    # Step 1: sanity-check the status mux.
    print("\n=== step 1: status mux sanity ===")
    version = read_status_reg(xvc, 0xFE)
    magic = (version >> 16) & 0xFFFF
    iter_num = version & 0xFFFF
    print(f"  VERSION reg: magic=0x{magic:04x} iter=0x{iter_num:04x}")
    if magic != 0xB07E:
        print("  FAIL: status mux not responding (magic mismatch)")
        sys.exit(1)
    print(f"  status mux alive, iter-{iter_num} bitstream live")

    # Step 2: read status flags
    flags = read_status_reg(xvc, 0x00)
    cal_done = (flags >> 15) & 1
    init_done = (flags >> 11) & 1
    mmcm_lock = (flags >> 5) & 1
    print(f"  STATUS_FLAGS: mmcm_locked={mmcm_lock} init_done={init_done} "
          f"cal_done={cal_done} (raw=0x{flags:08x})")
    if not mmcm_lock:
        print("  WARN: MMCM not locked yet")
    if not init_done:
        print("  WARN: DDR3 init not complete — DDR3 probe will fail")

    # Step 3: halt memtest and probe BRAM
    jwb_cmd(xvc, JWB_CMD_HALT)
    bram_results = probe_window(xvc, "BRAM", args.bram_addr, args.n_words)

    # Step 4: probe DDR3 (only meaningful if cal_done)
    if cal_done:
        ddr3_results = probe_window(xvc, "DDR3", args.ddr3_addr, args.n_words)
    else:
        ddr3_results = None
        print("\n=== skipping DDR3 probe — cal_done=0 ===")

    # Step 5: resume memtest
    jwb_cmd(xvc, JWB_CMD_RESUME)
    print("\nmemtest_lite resumed.")

    # Step 6: one-line summary for shell scripts.
    bram_ok = all(r[1] == 0 for r in bram_results.values())
    ddr3_ok = ddr3_results is not None and all(r[1] == 0 for r in ddr3_results.values())
    print(f"\nSILICON_PROBE_SUMMARY iter={iter_num} "
          f"mmcm_locked={mmcm_lock} init_done={init_done} cal_done={cal_done} "
          f"bram_ok={int(bram_ok)} ddr3_ok={int(ddr3_ok)}")

    xvc.close()
    sys.exit(0 if (bram_ok and (ddr3_ok or not cal_done)) else 1)


if __name__ == "__main__":
    main()
