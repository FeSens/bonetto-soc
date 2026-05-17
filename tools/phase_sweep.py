#!/usr/bin/env python3
"""
phase_sweep.py — host-driven DQS-out (clk_dq) MMCM phase shift sweep
(iter-11).

For boards whose HR-bank DQS pins block ODELAYE2 write-leveling, this
script uses the MMCM PSEN port — wired into the FPGA via JWB cmd
0xE9/0xEA — to walk CLKOUT2's phase across one full 360deg rotation (56
steps @ 800 MHz VCO = 22.3 ps each). At each step it issues writes,
reads them back, and counts hits.

The phase that yields stable round-trip reads is the correct DQS-CK
alignment. The script lands the FPGA at the centre of the longest pass
run and resumes memtest.

Usage:
    python tools/phase_sweep.py --tck-ns 2000 [--steps 56]

XVC server (openFPGALoader --xvc) must already be running.
"""

import argparse
import os
import sys

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.dirname(_SCRIPT_DIR)
sys.path.insert(0, _PROJECT_ROOT)
from tools.jtag_uart_read import (
    XVC, tap_reset_to_rti, select_user1,
    read_status_reg, jwb_cmd, jwb_wb_write, jwb_wb_read,
    jwb_phase_shift,
    JWB_CMD_HALT, JWB_CMD_RESUME,
)

PATTERNS = [0xAAAAAAAA, 0x55555555, 0xCAFEBABE, 0xDEADBEEF]


def measure_at_current_phase(xvc, base_addr, n_words):
    passes = 0
    fails = 0
    for pat in PATTERNS:
        for i in range(n_words):
            jwb_wb_write(xvc, base_addr + i, pat ^ ((i * 0x10101010) & 0xFFFFFFFF))
        for i in range(n_words):
            expected = pat ^ ((i * 0x10101010) & 0xFFFFFFFF)
            got = jwb_wb_read(xvc, base_addr + i)
            if got == expected:
                passes += 1
            else:
                fails += 1
    return passes, fails


def centre_of_longest_run(ok_list):
    best_start = best_len = -1
    cur_start = cur_len = 0
    for i, ok in enumerate(ok_list):
        if ok:
            if cur_len == 0:
                cur_start = i
            cur_len += 1
            if cur_len > best_len:
                best_len = cur_len
                best_start = cur_start
        else:
            cur_len = 0
    if best_len <= 0:
        return None
    return best_start + best_len // 2


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--tck-ns", type=int, default=2000)
    ap.add_argument("--steps", type=int, default=56,
                    help="number of phase-shift steps to sweep (default 56 = full rotation)")
    ap.add_argument("--ddr3-addr", type=lambda s: int(s, 0), default=0x4000)
    ap.add_argument("--n-words", type=int, default=2,
                    help="words per pattern per step")
    args = ap.parse_args()

    xvc = XVC(args.host, args.port)
    print(f"connected: {xvc.info}")
    xvc.settck(args.tck_ns)
    tap_reset_to_rti(xvc)
    select_user1(xvc)

    version = read_status_reg(xvc, 0xFE)
    iter_num = version & 0xFFFF
    print(f"bitstream iter=0x{iter_num:04x}")
    if iter_num < 0x000B:
        print(f"WARN: phase shift commands require iter-11+ (current 0x{iter_num:04x})")

    jwb_cmd(xvc, JWB_CMD_HALT)

    ok_per_step = []
    for step in range(args.steps):
        passes, fails = measure_at_current_phase(xvc, args.ddr3_addr, args.n_words)
        ok = (fails == 0)
        st = read_status_reg(xvc, 0x14)
        count = st & 0xFF
        if count >= 0x80:
            count -= 0x100
        print(f"  step={step:2d} phase_count={count:+d}: {'PASS' if ok else 'FAIL'} ({passes}/{passes+fails} ok)")
        ok_per_step.append(ok)
        if step != args.steps - 1:
            jwb_phase_shift(xvc, +1)

    # Centre of the longest pass run is our target. Phase counter wraps,
    # so absolute count is less interesting than the offset from current.
    centre = centre_of_longest_run(ok_per_step)
    if centre is None:
        print("\nFAIL: no passing phase found across full rotation")
        print(f"PHASE_SWEEP_SUMMARY centre=FAIL")
        jwb_cmd(xvc, JWB_CMD_RESUME)
        xvc.close()
        sys.exit(1)

    # We're now at step (args.steps - 1). Step back to `centre`.
    delta = centre - (args.steps - 1)
    print(f"\nlongest pass run centre = step {centre}, delta from current = {delta}")
    if delta != 0:
        jwb_phase_shift(xvc, delta)
    st = read_status_reg(xvc, 0x14)
    final_count = st & 0xFF
    if final_count >= 0x80:
        final_count -= 0x100
    print(f"landed at phase_count={final_count:+d}")
    print(f"PHASE_SWEEP_SUMMARY centre={centre} final_count={final_count}")

    jwb_cmd(xvc, JWB_CMD_RESUME)
    xvc.close()


if __name__ == "__main__":
    main()
