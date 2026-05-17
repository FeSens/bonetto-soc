#!/usr/bin/env python3
"""
DDR3 hardware validation for the YPCB-00338 bring-up bitstream.

The script expects an XVC server on the requested host/port. It uses the
JTAG-WB master to halt the autonomous memtest, performs direct DDR3 writes and
reads through the controller, then resumes memtest_lite for a timed soak.

Addressing:
  - Board-local WB address bit 14 still selects DDR3.
  - Command 0xE1 supplies DDR3 controller address bits [27:14] for JTAG-only
    debug accesses.
  - The tested DDR3 controller address space is 25 bits:
      {bank[2:0], row[14:0], col[9:3]}
"""

import argparse
import json
import os
import random
import sys
import time
from datetime import datetime, timezone

_SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
_PROJECT_ROOT = os.path.dirname(_SCRIPT_DIR)
sys.path.insert(0, _PROJECT_ROOT)

from tools.jtag_uart_read import (  # noqa: E402
    XVC,
    JWB_CMD_HALT,
    JWB_CMD_RESUME,
    decode_status_flags,
    jwb_cmd,
    jwb_wb_read,
    jwb_wb_write,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


DDR3_SELECT = 0x4000
DDR3_LOCAL_MASK = 0x3FFF
DDR3_ADDR_BITS = 25
DDR3_ADDR_MASK = (1 << DDR3_ADDR_BITS) - 1
DDR3_WORDS = DDR3_ADDR_MASK + 1


def ddr3_addr_parts(addr):
    addr &= DDR3_ADDR_MASK
    return DDR3_SELECT | (addr & DDR3_LOCAL_MASK), (addr >> 14) & 0x3FFF


def mix32(x):
    x &= 0xFFFFFFFF
    x ^= x >> 16
    x = (x * 0x7FEB352D) & 0xFFFFFFFF
    x ^= x >> 15
    x = (x * 0x846CA68B) & 0xFFFFFFFF
    x ^= x >> 16
    return x & 0xFFFFFFFF


def checksum_pattern(addr, index, seed):
    mixed = mix32(addr ^ seed ^ ((index * 0x9E3779B9) & 0xFFFFFFFF))
    data = 0
    for lane in range(4):
        addr_byte = (addr >> ((lane * 5) % DDR3_ADDR_BITS)) & 0xFF
        b = ((mixed >> (lane * 8)) & 0xFF) ^ addr_byte ^ ((index + lane * 0x5A) & 0xFF)
        data |= (b & 0xFF) << (lane * 8)
    return data & 0xFFFFFFFF


def require(cond, msg):
    if not cond:
        raise RuntimeError(msg)


class Validator:
    def __init__(self, xvc, verbose=False):
        self.xvc = xvc
        self.verbose = verbose
        self.failures = []
        self.results = {}

    def read_status(self):
        regs = {r: read_status_reg(self.xvc, r) for r in [
            0x00, 0x01, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
            0x09, 0x0A, 0x0B, 0x0C,
            0x10, 0x15, 0x16, 0x17, 0x19, 0x1A, 0x1C, 0xFE,
        ]}
        return regs

    def write_ddr3(self, addr, data):
        local, hi = ddr3_addr_parts(addr)
        return jwb_wb_write(self.xvc, local, data & 0xFFFFFFFF, hi)

    def read_ddr3(self, addr):
        local, hi = ddr3_addr_parts(addr)
        return jwb_wb_read(self.xvc, local, hi)

    def normalize_cases(self, cases):
        by_addr = {}
        for addr, data in cases:
            by_addr[addr & DDR3_ADDR_MASK] = data & 0xFFFFFFFF
        return list(by_addr.items())

    def check(self, name, cases):
        cases = self.normalize_cases(cases)
        start = time.monotonic()
        first_fail = None
        for addr, data in cases:
            self.write_ddr3(addr, data)
        for addr, data in cases:
            got = self.read_ddr3(addr)
            exp = data & 0xFFFFFFFF
            if got != exp:
                first_fail = {
                    "addr": f"0x{addr:07x}",
                    "expected": f"0x{exp:08x}",
                    "got": f"0x{got:08x}",
                }
                self.failures.append({"test": name, **first_fail})
                break
        elapsed = time.monotonic() - start
        ok = first_fail is None
        self.results[name] = {
            "ok": ok,
            "cases": len(cases),
            "elapsed_s": round(elapsed, 3),
            "first_fail": first_fail,
        }
        print(f"{name}: {'PASS' if ok else 'FAIL'} cases={len(cases)} elapsed={elapsed:.1f}s")
        if first_fail:
            print("  first_fail", first_fail)
        return ok

    def deterministic_patterns(self):
        addrs = [
            0x0000000, 0x0000001, 0x0000002, 0x0000003,
            0x000007E, 0x000007F, 0x0000080, 0x0000081,
            0x0003FFE, 0x0003FFF, 0x0004000, 0x0004001,
            0x03FFF80, 0x03FFFFF, 0x0400000, 0x0400001,
            0x07FFFFF, 0x0800000, 0x0C00000, 0x1000000,
            0x1400000, 0x1800000, 0x1C00000, 0x1FFFFFF,
        ]
        patterns = [
            0x00000000, 0xFFFFFFFF, 0xAAAAAAAA, 0x55555555,
            0x11223344, 0x89ABCDEF, 0x01020304, 0xF0E1D2C3,
        ]
        cases = []
        for i, addr in enumerate(addrs):
            cases.append((addr, patterns[i % len(patterns)] ^ mix32(addr)))
        return self.check("deterministic_boundary_patterns", cases)

    def address_walking(self):
        cases = [(0, 0x13572468)]
        for bit in range(DDR3_ADDR_BITS):
            addr = 1 << bit
            cases.append((addr, mix32(addr ^ 0xA5A50000)))
            if addr > 0:
                cases.append(((addr - 1) & DDR3_ADDR_MASK, mix32(addr ^ 0x5A5A0000)))
        return self.check("address_walking", cases)

    def data_bit_byte_lanes(self):
        cases = []
        for bit in range(32):
            cases.append((0x001000 + bit, 1 << bit))
            cases.append((0x002000 + bit, (~(1 << bit)) & 0xFFFFFFFF))
        for lane in range(4):
            byte_mask = 0xFF << (lane * 8)
            cases.append((0x003000 + lane, byte_mask))
            cases.append((0x003010 + lane, byte_mask ^ 0xFFFFFFFF))
        cases.extend([
            (0x003100, 0x00000000),
            (0x003101, 0xFFFFFFFF),
            (0x003102, 0xAAAAAAAA),
            (0x003103, 0x55555555),
            (0x003104, 0x00FF00FF),
            (0x003105, 0xFF00FF00),
        ])
        return self.check("data_bit_and_byte_lanes", cases)

    def contiguous_windows(self):
        cases = []
        bases = [0x0, 0x60, 0x3FC0, 0x3FFF0, 0x3FFFF0,
                 0x400000, 0x7FFFC0, 0x1FFFC0, 0x1FFFFC0]
        for base in bases:
            for off in range(64):
                addr = (base + off) & DDR3_ADDR_MASK
                cases.append((addr, mix32((base << 1) ^ off ^ 0xC001D00D)))
        return self.check("contiguous_burst_alignment_windows", cases)

    def randomized(self, count, seed):
        rng = random.Random(seed)
        addrs = set()
        while len(addrs) < count:
            addrs.add(rng.randrange(0, DDR3_ADDR_MASK + 1))
        cases = [(addr, mix32(addr ^ rng.getrandbits(32))) for addr in sorted(addrs)]
        return self.check("randomized_read_write", cases)

    def checksum_sweep(self, words, stride, seed, base=0):
        start = time.monotonic()
        words = max(0, min(words, DDR3_WORDS))
        stride &= DDR3_ADDR_MASK
        if stride == 0:
            stride = 1
        print(f"xor_checksum_sweep: words={words} bytes={words * 4} "
              f"base=0x{base & DDR3_ADDR_MASK:07x} stride={stride}")

        expected_xor = 0
        expected_byte_xor = [0, 0, 0, 0]
        got_xor = 0
        got_byte_xor = [0, 0, 0, 0]
        first_fail = None
        progress_every = max(1, words // 8)

        for i in range(words):
            addr = (base + i * stride) & DDR3_ADDR_MASK
            data = checksum_pattern(addr, i, seed)
            expected_xor ^= data
            for lane in range(4):
                expected_byte_xor[lane] ^= (data >> (lane * 8)) & 0xFF
            self.write_ddr3(addr, data)
            if self.verbose and ((i + 1) % progress_every == 0 or i + 1 == words):
                print(f"  wrote {i + 1}/{words}")

        for i in range(words):
            addr = (base + i * stride) & DDR3_ADDR_MASK
            exp = checksum_pattern(addr, i, seed)
            got = self.read_ddr3(addr)
            got_xor ^= got
            for lane in range(4):
                got_byte_xor[lane] ^= (got >> (lane * 8)) & 0xFF
            if got != exp and first_fail is None:
                first_fail = {
                    "addr": f"0x{addr:07x}",
                    "expected": f"0x{exp:08x}",
                    "got": f"0x{got:08x}",
                }
            if self.verbose and ((i + 1) % progress_every == 0 or i + 1 == words):
                print(f"  read {i + 1}/{words}")

        checksum_ok = (got_xor == expected_xor and got_byte_xor == expected_byte_xor)
        ok = first_fail is None and checksum_ok
        elapsed = time.monotonic() - start
        result = {
            "ok": ok,
            "words": words,
            "bytes": words * 4,
            "base": f"0x{base & DDR3_ADDR_MASK:07x}",
            "stride": stride,
            "seed": f"0x{seed & 0xFFFFFFFF:08x}",
            "full_controller_visible_space": bool(words == DDR3_WORDS and stride == 1),
            "expected_xor": f"0x{expected_xor:08x}",
            "got_xor": f"0x{got_xor:08x}",
            "expected_byte_xor": [f"0x{x:02x}" for x in expected_byte_xor],
            "got_byte_xor": [f"0x{x:02x}" for x in got_byte_xor],
            "elapsed_s": round(elapsed, 3),
            "first_fail": first_fail,
        }
        if not ok:
            self.failures.append({"test": "xor_checksum_sweep", **result})
        self.results["xor_checksum_sweep"] = result
        print(f"xor_checksum_sweep: {'PASS' if ok else 'FAIL'} "
              f"xor=0x{got_xor:08x}/0x{expected_xor:08x} elapsed={elapsed:.1f}s")
        if first_fail:
            print("  first_fail", first_fail)
        return ok

    def bram_sanity(self):
        cases = [(i, mix32(0xB00D0000 ^ i)) for i in range(32)]
        start = time.monotonic()
        first_fail = None
        for addr, data in cases:
            jwb_wb_write(self.xvc, addr, data)
        for addr, data in cases:
            got = jwb_wb_read(self.xvc, addr)
            if got != data:
                first_fail = {
                    "addr": f"0x{addr:04x}",
                    "expected": f"0x{data:08x}",
                    "got": f"0x{got:08x}",
                }
                self.failures.append({"test": "bram_sanity", **first_fail})
                break
        elapsed = time.monotonic() - start
        ok = first_fail is None
        self.results["bram_sanity"] = {
            "ok": ok,
            "cases": len(cases),
            "elapsed_s": round(elapsed, 3),
            "first_fail": first_fail,
        }
        print(f"bram_sanity: {'PASS' if ok else 'FAIL'} cases={len(cases)} elapsed={elapsed:.1f}s")
        return ok

    def soak_memtest(self, seconds, poll_interval):
        print(f"memtest_soak: running for {seconds}s")
        jwb_cmd(self.xvc, JWB_CMD_RESUME)
        start_regs = self.read_status()
        start = time.monotonic()
        last_regs = start_regs
        polls = []
        while True:
            now = time.monotonic()
            if now - start >= seconds:
                break
            time.sleep(min(poll_interval, seconds - (now - start)))
            regs = self.read_status()
            polls.append({
                "t_s": round(time.monotonic() - start, 3),
                "flags": f"0x{regs[0x00]:08x}",
                "err_ctr": regs[0x04],
                "ddr3_pass_ctr": regs[0x08],
            })
            print(f"  soak t={polls[-1]['t_s']:.0f}s "
                  f"ddr3_pass={regs[0x08]} err={regs[0x04]} flags=0x{regs[0x00]:08x}")
            last_regs = regs
            if (regs[0x00] >> 1) & 1 or regs[0x04] != 0:
                break
        end_regs = self.read_status()
        elapsed = time.monotonic() - start
        ok = (((end_regs[0x00] >> 1) & 1) == 0 and end_regs[0x04] == 0 and
              end_regs[0x08] > start_regs[0x08])
        result = {
            "ok": ok,
            "elapsed_s": round(elapsed, 3),
            "start_ddr3_pass_ctr": start_regs[0x08],
            "end_ddr3_pass_ctr": end_regs[0x08],
            "start_err_ctr": start_regs[0x04],
            "end_err_ctr": end_regs[0x04],
            "start_flags": f"0x{start_regs[0x00]:08x}",
            "end_flags": f"0x{end_regs[0x00]:08x}",
            "polls": polls,
        }
        if not ok:
            self.failures.append({"test": "memtest_soak", "end_regs": end_regs})
        self.results["memtest_soak"] = result
        print(f"memtest_soak: {'PASS' if ok else 'FAIL'} "
              f"ddr3_pass_delta={end_regs[0x08] - start_regs[0x08]} "
              f"err={end_regs[0x04]}")
        return ok


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--tck-ns", type=int, default=2000,
                    help="XVC TCK period; 2000 ns is 500 kHz")
    ap.add_argument("--random-count", type=int, default=512)
    ap.add_argument("--random-seed", type=lambda s: int(s, 0), default=0xD3D30001)
    ap.add_argument("--checksum-words", type=int, default=2048,
                    help="number of DDR3 words to cover with the host XOR checksum sweep")
    ap.add_argument("--checksum-stride", type=lambda s: int(s, 0), default=1)
    ap.add_argument("--checksum-base", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--checksum-seed", type=lambda s: int(s, 0), default=0xC3EC5A01)
    ap.add_argument("--full-controller-checksum", action="store_true",
                    help="run the host XOR checksum over all controller-visible DDR3 words; very slow over JTAG")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--soak-seconds", type=int, default=600)
    ap.add_argument("--poll-interval", type=float, default=30.0)
    ap.add_argument("--json", default=None,
                    help="optional output JSON path")
    args = ap.parse_args()

    started = datetime.now(timezone.utc).isoformat()
    evidence = {
        "started_utc": started,
        "host": args.host,
        "port": args.port,
        "tck_ns_requested": args.tck_ns,
        "random_count": args.random_count,
        "random_seed": f"0x{args.random_seed:08x}",
        "checksum_words": DDR3_WORDS if args.full_controller_checksum else args.checksum_words,
        "checksum_stride": args.checksum_stride,
        "checksum_base": f"0x{args.checksum_base & DDR3_ADDR_MASK:07x}",
        "checksum_seed": f"0x{args.checksum_seed & 0xFFFFFFFF:08x}",
        "soak_seconds": args.soak_seconds,
        "results": {},
    }

    xvc = XVC(args.host, args.port)
    try:
        actual_tck = xvc.settck(args.tck_ns)
        evidence["xvc_info"] = str(xvc.info)
        evidence["tck_ns_actual"] = actual_tck
        tap_reset_to_rti(xvc)
        select_user1(xvc)

        v = Validator(xvc, verbose=args.verbose)
        status = v.read_status()
        evidence["initial_status"] = {f"0x{k:02x}": f"0x{val:08x}" for k, val in status.items()}
        print("initial", decode_status_flags(status[0x00]))
        require((status[0xFE] >> 16) == 0xB07E, "status mux magic mismatch")
        require(((status[0x00] >> 5) & 1) == 1, "DDR3 clock PLL/MMCM is not locked")
        require(((status[0x00] >> 11) & 1) == 1, "DDR3 init_done is not asserted")
        require(((status[0x00] >> 15) & 1) == 1, "DDR3 cal_done is not asserted")
        require(((status[0x00] >> 14) & 1) == 0, "DDR3 cal_error is asserted")

        jwb_cmd(xvc, JWB_CMD_HALT)
        checks = [
            v.bram_sanity(),
            v.deterministic_patterns(),
            v.address_walking(),
            v.data_bit_byte_lanes(),
            v.contiguous_windows(),
            v.checksum_sweep(
                DDR3_WORDS if args.full_controller_checksum else args.checksum_words,
                args.checksum_stride,
                args.checksum_seed,
                args.checksum_base,
            ),
            v.randomized(args.random_count, args.random_seed),
            v.soak_memtest(args.soak_seconds, args.poll_interval),
        ]
        final_status = v.read_status()
        evidence["final_status"] = {f"0x{k:02x}": f"0x{val:08x}" for k, val in final_status.items()}
        evidence["results"] = v.results
        evidence["failures"] = v.failures
        evidence["completed_utc"] = datetime.now(timezone.utc).isoformat()
        ok = all(checks) and not v.failures
        evidence["ok"] = ok
        print("final", decode_status_flags(final_status[0x00]))
        print(f"DDR3_HW_VALIDATE_SUMMARY ok={int(ok)} failures={len(v.failures)} "
              f"ddr3_pass_ctr={final_status[0x08]} err_ctr={final_status[0x04]}")
    finally:
        xvc.close()

    if args.json:
        os.makedirs(os.path.dirname(os.path.abspath(args.json)), exist_ok=True)
        with open(args.json, "w", encoding="utf-8") as f:
            json.dump(evidence, f, indent=2, sort_keys=True)
            f.write("\n")

    return 0 if evidence.get("ok") else 1


if __name__ == "__main__":
    sys.exit(main())
