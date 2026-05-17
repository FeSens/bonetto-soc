#!/usr/bin/env python3
"""
idelay_sweep.py — host-driven DQS IDELAY sweep via JTAG-WB master (iter-10).

Bypasses the FPGA-side rdlvl/MPR-mode path entirely. For each candidate
IDELAYE2 tap on each byte lane, the script:

  1. halts memtest_lite
  2. issues JWB_CMD_SET_CAL to set the IDELAY tap on the target lane
  3. JWB-writes a known data pattern into a small DDR3 window
  4. JWB-reads back, counts hits / misses
  5. moves on to the next tap

Output: per-lane eye-tap bitmap, recommended centre tap, plus a summary
line for shell scripts.

Usage:
    python tools/idelay_sweep.py --tck-ns 2000 [--lanes 0,1] [--taps 0-31]

XVC server (openFPGALoader --xvc) must already be running.
"""

import argparse
import os
import sys
import time

# Prefer relative-to-script imports so the script works regardless of cwd.
_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.dirname(_SCRIPT_DIR)
sys.path.insert(0, _PROJECT_ROOT)
from tools.jtag_uart_read import (
    XVC, tap_reset_to_rti, select_user1,
    read_status_reg, jwb_cmd, jwb_wb_write, jwb_wb_read,
    jwb_set_idelay,
    JWB_CMD_HALT, JWB_CMD_RESUME,
)


SWEEP_PATTERNS = [
    0xAAAAAAAA,
    0x55555555,
    0xCAFEBABE,
    0xDEADBEEF,
]


def parse_range(s):
    """Parse strings like '0-31' or '0,3,5' into a list of ints."""
    out = []
    for piece in s.split(","):
        if "-" in piece:
            a, b = piece.split("-")
            out.extend(range(int(a), int(b) + 1))
        else:
            out.append(int(piece))
    return out


def measure_tap(xvc, base_addr, n_words, patterns):
    """At the currently-loaded tap, return (passes, fails) across all patterns."""
    passes = 0
    fails = 0
    for pat in patterns:
        # Write
        for i in range(n_words):
            jwb_wb_write(xvc, base_addr + i, pat ^ ((i * 0x1010101) & 0xFFFFFFFF))
        # Read
        for i in range(n_words):
            expected = pat ^ ((i * 0x1010101) & 0xFFFFFFFF)
            got = jwb_wb_read(xvc, base_addr + i)
            if got == expected:
                passes += 1
            else:
                fails += 1
    return passes, fails


def centre_of_largest_run(bitmap):
    """Given a list of pass/fail booleans, find the centre of the longest run."""
    best_start = -1
    best_len = 0
    cur_start = -1
    cur_len = 0
    for i, ok in enumerate(bitmap):
        if ok:
            if cur_len == 0:
                cur_start = i
            cur_len += 1
            if cur_len > best_len:
                best_len = cur_len
                best_start = cur_start
        else:
            cur_len = 0
    if best_len == 0:
        return None
    return best_start + best_len // 2


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--tck-ns", type=int, default=2000)
    ap.add_argument("--lanes", default="0-8",
                    help="comma-separated lane indices or ranges (default 0-8)")
    ap.add_argument("--taps", default="0-31",
                    help="tap range to sweep (default full 0-31)")
    ap.add_argument("--ddr3-addr", type=lambda s: int(s, 0), default=0x4000)
    ap.add_argument("--n-words", type=int, default=4,
                    help="words per pattern per tap")
    args = ap.parse_args()

    lanes = parse_range(args.lanes)
    taps  = parse_range(args.taps)

    xvc = XVC(args.host, args.port)
    print(f"connected: {xvc.info}")
    xvc.settck(args.tck_ns)
    tap_reset_to_rti(xvc)
    select_user1(xvc)

    # Verify alive
    version = read_status_reg(xvc, 0xFE)
    iter_num = version & 0xFFFF
    print(f"bitstream iter=0x{iter_num:04x}")
    if iter_num < 0x000A:
        print(f"WARN: SET_CAL command requires iter-10+ bitstream (iter=0x{iter_num:04x})")

    jwb_cmd(xvc, JWB_CMD_HALT)

    results = {}
    for lane in lanes:
        print(f"\n=== sweep lane {lane} ===")
        per_tap = []
        for t in taps:
            jwb_set_idelay(xvc, lane, t)
            # Tiny settle delay before issuing reads
            for _ in range(3):
                read_status_reg(xvc, 0x10)
            passes, fails = measure_tap(xvc, args.ddr3_addr, args.n_words, SWEEP_PATTERNS)
            ok = (fails == 0)
            per_tap.append(ok)
            print(f"  tap={t:2d}: {'PASS' if ok else 'FAIL'} ({passes}/{passes+fails} ok)")
        centre = centre_of_largest_run(per_tap)
        results[lane] = (per_tap, centre)
        if centre is not None:
            print(f"  -> lane {lane} centre tap = {taps[centre] if 0 <= centre < len(taps) else centre}")
            jwb_set_idelay(xvc, lane, taps[centre])
        else:
            print(f"  -> lane {lane} NO PASS TAP FOUND")

    print("\nIDELAY_SWEEP_SUMMARY", end=" ")
    for lane, (bitmap, centre) in results.items():
        if centre is None:
            print(f"L{lane}=FAIL", end=" ")
        else:
            print(f"L{lane}={taps[centre]}", end=" ")
    print()

    jwb_cmd(xvc, JWB_CMD_RESUME)
    xvc.close()
    ok_all = all(c is not None for (_, c) in results.values())
    sys.exit(0 if ok_all else 1)


if __name__ == "__main__":
    main()
