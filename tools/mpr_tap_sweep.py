#!/usr/bin/env python3
"""
mpr_tap_sweep.py - direct DDR3 MPR capture sweep over DQS IDELAY taps.

This uses the board-top debug commands in the DDR3 SERDES init gate:

  * enable MR3 MPR mode
  * set a lane's DQS input IDELAY tap
  * issue one MPR read
  * read back either the selected SERDES history frame or a DQS-clocked IDDR
    sample from the most recent DQS edge

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
    REG_DECODERS,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


EXPECTED_MPR_BYTES = [0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF]
PHASE_SWAPPED_MPR_BYTES = [0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00]


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
        last = read_status_reg(xvc, 0x2D)
        if (last >> 16) != 0xCA30:
            raise RuntimeError(f"MPR status register missing: 0x{last:08x}")
        if ((last >> 15) & 1) == 0:
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
            byte |= ((value >> (sample * 8 + bit)) & 1) << bit
        samples.append(byte)
    return samples


def capture_raw_serdes_lane(xvc, requested_lane=None, requested_channel=None):
    status = dbg_read(xvc, 0x29)
    if (status >> 16) != 0xCA20:
        raise RuntimeError(f"SERDES capture status missing: 0x{status:08x}")
    if ((status >> 15) & 1) == 0:
        raise RuntimeError(f"SERDES capture has no valid sample: 0x{status:08x}")
    actual_lane = (status >> 10) & 0x1F
    if requested_channel is not None and requested_lane is not None:
        expected_lane = requested_channel * 9 + requested_lane
        if actual_lane != expected_lane:
            raise RuntimeError(
                f"SERDES capture lane {actual_lane}, expected physical lane "
                f"{expected_lane} for channel {requested_channel} lane "
                f"{requested_lane}: 0x{status:08x}"
            )
    lo = dbg_read(xvc, 0x2A)
    hi = dbg_read(xvc, 0x2B)
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
                bit_idx = lane * 64 + sample * 8 + bit
                byte |= ((val >> bit_idx) & 1) << bit
            samples.append(byte)
        lanes.append(samples)
    return lanes


def score(samples):
    return sum(1 for got, exp in zip(samples, EXPECTED_MPR_BYTES) if got == exp)


def phase_swapped_score(samples):
    return sum(1 for got, exp in zip(samples, PHASE_SWAPPED_MPR_BYTES)
               if got == exp)


def classify_samples(samples):
    expected = score(samples)
    swapped = phase_swapped_score(samples)
    if expected == len(EXPECTED_MPR_BYTES):
        verdict = "PASS"
    elif swapped == len(PHASE_SWAPPED_MPR_BYTES):
        verdict = "PHASE_SWAP"
    elif all(sample == 0x00 for sample in samples):
        verdict = "ALL_ZERO"
    elif all(sample == 0xFF for sample in samples):
        verdict = "ALL_ONE"
    else:
        verdict = "FAIL"
    return verdict, expected, swapped


def verdict_rank(verdict):
    if verdict == "PASS":
        return 2
    if verdict == "PHASE_SWAP":
        return 1
    return 0


def dump_debug_regs(xvc, regs):
    for reg in regs:
        value = dbg_read(xvc, reg)
        name, decoder = REG_DECODERS.get(reg, (f"REG_{reg:02X}", lambda w: ""))
        print(f"  [{reg:#04x}] {name:<24s} = 0x{value:08x} {decoder(value)}")


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
    ap.add_argument("--delay", type=lambda s: int(s, 0), default=None,
                    help="Raw capture config byte; overrides --wait-cycles/--history-age")
    ap.add_argument("--wait-cycles", type=lambda s: int(s, 0), default=0,
                    help="Post-read wait in 50 MHz controller cycles, encoded in capture config bits [3:0]")
    ap.add_argument("--waits", default=None,
                    help="Comma/range list of post-read wait values to sweep; overrides --wait-cycles")
    ap.add_argument("--history-age", type=lambda s: int(s, 0), default=0,
                    help="clk_sys frames before the DQS edge to export in SERDES-edge mode; in experimental DQS burst-capture images this seeds the pair skip count")
    ap.add_argument("--skips", default=None,
                    help="Comma/range list of DQS pairs to skip before BL8 capture; only used by experimental --dqs-iddr burst-capture images")
    ap.add_argument("--swaps", default=None,
                    help="Comma/range list of runtime DQS edge-swap bits to sweep; only used with --dqs-iddr")
    ap.add_argument("--dqs-iddr", action="store_true",
                    help="Use the DQS-clocked IDDR probe instead of the global-clock SERDES edge-window capture")
    ap.add_argument("--wide-debug", action="store_true",
                    help="Use legacy 0x20-0x3f wide PHY debug words")
    args = ap.parse_args()

    lanes = parse_range(args.lanes)
    taps = parse_range(args.taps)
    waits = parse_range(args.waits) if args.waits is not None else [args.wait_cycles]
    skips = parse_range(args.skips) if args.skips is not None else [args.history_age]
    swaps = parse_range(args.swaps) if args.swaps is not None else [0]
    if args.delay is not None and args.waits is not None:
        raise SystemExit("--delay is a raw capture byte and cannot be combined with --waits")
    if args.skips is not None and not args.dqs_iddr:
        raise SystemExit("--skips only applies with --dqs-iddr")
    if args.swaps is not None and not args.dqs_iddr:
        raise SystemExit("--swaps only applies with --dqs-iddr")
    if args.delay is not None and args.skips is not None:
        raise SystemExit("--delay is a raw capture byte and cannot be combined with --skips")
    for wait in waits:
        if wait < 0 or wait > 15:
            raise SystemExit(f"capture wait must fit in 4 bits, got {wait}")
    for skip in skips:
        if skip < 0 or skip > 7:
            raise SystemExit(f"DQS skip count must fit in 3 bits, got {skip}")
    for swap in swaps:
        if swap not in (0, 1):
            raise SystemExit(f"DQS runtime swap must be 0 or 1, got {swap}")

    xvc = XVC(args.host, args.port)
    print(f"connected: {xvc.info}")
    xvc.settck(args.tck_ns)
    tap_reset_to_rti(xvc)
    select_user1(xvc)

    version = read_status_reg(xvc, 0xFE)
    iter_num = version & 0xFFFF
    print(f"bitstream iter=0x{iter_num:04x}")
    if iter_num < 0x0D8E:
        raise RuntimeError(f"direct MPR debug requires iter 0x0d8e+, got 0x{iter_num:04x}")
    if args.dqs_iddr and iter_num < 0x0D9B:
        raise RuntimeError(f"--dqs-iddr requires iter 0x0d9b+, got 0x{iter_num:04x}")
    if args.dqs_iddr:
        capture_cfg_status = dbg_read(xvc, 0x45)
        if ((capture_cfg_status >> 16) != 0xCA52) or (((capture_cfg_status >> 15) & 1) == 0):
            raise RuntimeError(
                "--dqs-iddr requested, but the flashed image does not expose "
                f"the DQS-clocked IDDR probe: 0x{capture_cfg_status:08x}"
            )
    fixed_capture_cfg = args.delay
    if fixed_capture_cfg is not None and args.dqs_iddr:
        fixed_capture_cfg |= 0x80
    source = "dqs-iddr" if (
        args.dqs_iddr or ((fixed_capture_cfg or 0) & 0x80)
    ) else "serdes-edge"
    if fixed_capture_cfg is None:
        print(
            f"capture_waits={','.join(str(w) for w in waits)} "
            f"history={args.history_age & 0x7} "
            f"skips={','.join(str(s) for s in skips)} "
            f"swaps={','.join(str(s) for s in swaps)} "
            f"source={source}"
        )
    else:
        print(
            f"capture_cfg=0x{fixed_capture_cfg:02x} "
            f"wait={fixed_capture_cfg & 0xF} "
            f"history={(fixed_capture_cfg >> 4) & 0x7} "
            f"swaps={','.join(str(s) for s in swaps)} "
            f"source={source}"
        )

    best = {}
    had_fail = False
    try:
        jwb_cmd(xvc, JWB_CMD_HALT)
        jwb_mpr_enable(xvc, args.channel)
        wait_mpr_idle(xvc)

        for lane in lanes:
            print(f"\n=== MPR sweep lane {lane} ===")
            best_tap = None
            best_wait = None
            best_skip = None
            best_swap = None
            best_score = -1
            best_phase_score = -1
            best_verdict = "FAIL"
            best_samples = None
            for tap in taps:
                for swap in swaps:
                    for skip in skips:
                        for wait in waits:
                            if fixed_capture_cfg is None:
                                cfg_high = skip if args.dqs_iddr else args.history_age
                                capture_cfg = ((cfg_high & 0x7) << 4) | (wait & 0xF)
                                if args.dqs_iddr:
                                    capture_cfg |= 0x80
                            else:
                                capture_cfg = fixed_capture_cfg
                                skip = (capture_cfg >> 4) & 0x7
                            jwb_select_rddbg(
                                xvc, lane, args.channel, capture_cfg,
                                swap_edges=bool(swap),
                            )
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
                                samples = capture_raw_serdes_lane(
                                    xvc,
                                    requested_lane=lane,
                                    requested_channel=args.channel,
                                )
                            verdict, tap_score, tap_phase_score = classify_samples(samples)
                            tap_quality = max(tap_score, tap_phase_score)
                            best_quality = max(best_score, best_phase_score)
                            if ((verdict_rank(verdict), tap_quality) >
                                    (verdict_rank(best_verdict), best_quality)):
                                best_tap = tap
                                best_wait = wait if fixed_capture_cfg is None else (capture_cfg & 0xF)
                                best_skip = skip
                                best_swap = swap
                                best_score = tap_score
                                best_phase_score = tap_phase_score
                                best_verdict = verdict
                                best_samples = samples
                            sample_text = " ".join(f"{x:02x}" for x in samples)
                            skip_text = f" skip={skip:1d}" if args.dqs_iddr else ""
                            swap_text = f" swap={swap}" if args.dqs_iddr else ""
                            print(
                                f"  tap={tap:2d} wait={capture_cfg & 0xF:2d}"
                                f"{skip_text}{swap_text}: "
                                f"{verdict:<10s} "
                                f"score={tap_score}/8 phase={tap_phase_score}/8 "
                                f"{sample_text}"
                            )

            best[lane] = (best_tap, best_wait, best_skip, best_swap,
                          best_score, best_phase_score,
                          best_verdict, best_samples)
            best_text = " ".join(f"{x:02x}" for x in best_samples)
            if best_verdict != "PASS":
                had_fail = True
            print(
                f"  -> lane {lane} best tap={best_tap} wait={best_wait} "
                f"skip={best_skip} swap={best_swap} "
                f"verdict={best_verdict} "
                f"score={best_score}/8 phase={best_phase_score}/8 {best_text}"
            )

        if had_fail:
            print("\nDebug before MPR disable:")
            dump_debug_regs(xvc, [0x2D, 0x2E, 0x2F, 0x32, 0x33, 0x34,
                                  0x35, 0x36, 0x37, 0x38, 0x39, 0x3A,
                                  0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40,
                                  0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
                                  0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C,
                                  0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x29, 0x2A,
                                  0x2B, 0x2C])

    finally:
        try:
            jwb_mpr_disable(xvc, args.channel)
            wait_mpr_idle(xvc)
            jwb_cmd(xvc, JWB_CMD_RESUME)
        finally:
            xvc.close()

    print("\nMPR_TAP_SWEEP_SUMMARY", end=" ")
    ok_all = True
    for lane in lanes:
        tap, wait, skip, swap, tap_score, tap_phase_score, verdict, _ = best[lane]
        suffix = f",skip={skip},swap={swap}" if args.dqs_iddr else ""
        if tap_score == len(EXPECTED_MPR_BYTES):
            print(f"L{lane}={tap}@{wait}{suffix}", end=" ")
        elif tap_phase_score == len(PHASE_SWAPPED_MPR_BYTES):
            ok_all = False
            print(f"L{lane}=PHASE_SWAP({tap}@{wait}{suffix})", end=" ")
        else:
            ok_all = False
            print(
                f"L{lane}={verdict}({tap}@{wait}{suffix}:"
                f"{tap_score}/8,phase={tap_phase_score}/8)",
                end=" "
            )
    print()
    return 0 if ok_all else 1


if __name__ == "__main__":
    raise SystemExit(main())
