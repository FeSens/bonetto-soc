#!/usr/bin/env python3
"""
mpr_tap_sweep.py - direct DDR3 MPR capture sweep over DQS IDELAY taps.

This uses the board-top debug commands added in bitstream iter 0x0012:

  * enable MR3 MPR mode
  * set a lane's DQS input IDELAY tap
  * issue one MPR read
  * read back either the compact fixed-lane capture register or the legacy
    wide PHY capture debug window

The script intentionally bypasses normal DDR3 memory traffic, so it remains
useful when read-leveling has failed and the Wishbone DDR3 path is not valid.
"""

import argparse
import os
import sys
import time

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.dirname(_SCRIPT_DIR)
sys.path.insert(0, _PROJECT_ROOT)

from tools.jtag_uart_read import (  # noqa: E402
    XVC,
    JWB_CMD_HALT,
    JWB_CMD_RESUME,
    jwb_cmd,
    jwb_mpr_disable,
    jwb_mpr_enable,
    jwb_mpr_read,
    jwb_select_rddbg,
    jwb_set_idelay,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


EXPECTED_MPR_BYTES = [0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF]


def parse_range(text):
    out = []
    for piece in text.split(","):
        if "-" in piece:
            first, last = piece.split("-", 1)
            out.extend(range(int(first, 0), int(last, 0) + 1))
        else:
            out.append(int(piece, 0))
    return out


def wait_mpr_idle(xvc, max_iters=64):
    last = 0
    for _ in range(max_iters):
        last = read_status_reg(xvc, 0x00)
        if ((last >> 2) & 1) == 0:
            return last
    raise RuntimeError(f"MPR path stayed busy: flags=0x{last:08x}")


def dbg_read(xvc, addr):
    read_status_reg(xvc, addr)
    return read_status_reg(xvc, addr)


def capture_words(xvc, n_words):
    return [dbg_read(xvc, 0x20 + i) for i in range(n_words)]


def decode_lane_word(value):
    samples = []
    for sample in range(8):
        byte = 0
        for bit in range(8):
            byte |= ((value >> (bit * 8 + sample)) & 1) << bit
        samples.append(byte)
    return samples


def capture_compact_lane(xvc, requested_lane=None, requested_channel=None):
    status = dbg_read(xvc, 0x6D)
    if (status >> 16) != 0xAB6D:
        raise RuntimeError(f"compact MPR debug register missing: 0x{status:08x}")
    if ((status >> 8) & 1) == 0:
        raise RuntimeError(f"compact MPR debug has no valid capture: 0x{status:08x}")
    actual_channel = (status >> 7) & 1
    actual_lane = status & 0x7
    if requested_channel is not None and actual_channel != requested_channel:
        raise RuntimeError(
            f"compact MPR debug captured channel {actual_channel}, "
            f"expected channel {requested_channel}: 0x{status:08x}"
        )
    if requested_lane is not None and actual_lane != requested_lane:
        raise RuntimeError(
            f"compact MPR debug bitstream is fixed to lane {actual_lane}, "
            f"requested lane {requested_lane}; rebuild with "
            f"-DDDR3_DEBUG_MPR_FIXED_LANE={requested_lane}"
        )
    lo = dbg_read(xvc, 0x6E)
    hi = dbg_read(xvc, 0x6F)
    return decode_lane_word(lo | (hi << 32))


def decode_lane_samples(words, n_lanes):
    val = 0
    for idx, word in enumerate(words):
        val |= (word & 0xFFFFFFFF) << (32 * idx)

    lanes = []
    for lane in range(n_lanes):
        samples = []
        for sample in range(8):
            byte = 0
            for bit in range(8):
                bit_idx = lane * 64 + bit * 8 + sample
                byte |= ((val >> bit_idx) & 1) << bit
            samples.append(byte)
        lanes.append(samples)
    return lanes


def score(samples):
    return sum(1 for got, exp in zip(samples, EXPECTED_MPR_BYTES) if got == exp)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--tck-ns", type=int, default=2000)
    ap.add_argument("--lanes", default="0-7")
    ap.add_argument("--taps", default="0-31")
    ap.add_argument("--n-lanes", type=int, default=8)
    ap.add_argument("--n-words", type=int, default=16)
    ap.add_argument("--mpr-addr", type=lambda s: int(s, 0), default=0x1000)
    ap.add_argument("--channel", type=int, choices=[0, 1], default=0)
    ap.add_argument("--wide-debug", action="store_true",
                    help="Use legacy 0x20-0x3f wide PHY debug words")
    args = ap.parse_args()

    lanes = parse_range(args.lanes)
    taps = parse_range(args.taps)

    xvc = XVC(args.host, args.port)
    print(f"connected: {xvc.info}")
    xvc.settck(args.tck_ns)
    tap_reset_to_rti(xvc)
    select_user1(xvc)

    version = read_status_reg(xvc, 0xFE)
    iter_num = version & 0xFFFF
    print(f"bitstream iter=0x{iter_num:04x}")
    if iter_num < 0x0012:
        raise RuntimeError(f"direct MPR debug requires iter 0x0012+, got 0x{iter_num:04x}")

    best = {}
    try:
        jwb_cmd(xvc, JWB_CMD_HALT)
        jwb_mpr_enable(xvc, args.channel)
        for _ in range(4):
            read_status_reg(xvc, 0x00)

        for lane in lanes:
            print(f"\n=== MPR sweep lane {lane} ===")
            jwb_select_rddbg(xvc, lane, args.channel)
            best_tap = None
            best_score = -1
            best_samples = None
            for tap in taps:
                jwb_select_rddbg(xvc, lane, args.channel)
                jwb_set_idelay(xvc, lane, tap, args.channel)
                for _ in range(3):
                    read_status_reg(xvc, 0x00)
                jwb_mpr_read(xvc, args.mpr_addr, args.channel)
                wait_mpr_idle(xvc)
                time.sleep(0.001)
                if args.wide_debug:
                    words = capture_words(xvc, args.n_words)
                    samples = decode_lane_samples(words, args.n_lanes)[lane]
                else:
                    samples = capture_compact_lane(
                        xvc,
                        requested_lane=lane,
                        requested_channel=args.channel,
                    )
                tap_score = score(samples)
                if tap_score > best_score:
                    best_tap = tap
                    best_score = tap_score
                    best_samples = samples
                sample_text = " ".join(f"{x:02x}" for x in samples)
                verdict = "PASS" if tap_score == len(EXPECTED_MPR_BYTES) else "FAIL"
                print(f"  tap={tap:2d}: {verdict} score={tap_score}/8 {sample_text}")

            best[lane] = (best_tap, best_score, best_samples)
            best_text = " ".join(f"{x:02x}" for x in best_samples)
            print(f"  -> lane {lane} best tap={best_tap} score={best_score}/8 {best_text}")

    finally:
        try:
            jwb_mpr_disable(xvc, args.channel)
            jwb_cmd(xvc, JWB_CMD_RESUME)
        finally:
            xvc.close()

    print("\nMPR_TAP_SWEEP_SUMMARY", end=" ")
    ok_all = True
    for lane in lanes:
        tap, tap_score, _ = best[lane]
        if tap_score == len(EXPECTED_MPR_BYTES):
            print(f"L{lane}={tap}", end=" ")
        else:
            ok_all = False
            print(f"L{lane}=FAIL({tap}:{tap_score}/8)", end=" ")
    print()
    return 0 if ok_all else 1


if __name__ == "__main__":
    raise SystemExit(main())
