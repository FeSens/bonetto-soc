#!/usr/bin/env python3
"""Validate the BRAM-only JTAG/Wishbone hardware path over XVC."""

import argparse
import pathlib
import sys


sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from jtag_uart_read import (  # noqa: E402
    JWB_CMD_RESUME,
    XVC,
    jwb_cmd,
    jwb_wb_read,
    jwb_wb_write,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


TEST_VECTORS = [
    (0x0000, 0x13579BDF),
    (0x0001, 0x2468ACE0),
    (0x0010, 0xA5A55A5A),
    (0x3FFF, 0x0BADF00D),
    (0x4000, 0xDEADBEEF),
    (0x4001, 0xCAFEBABE),
    (0x4010, 0x55AA33CC),
    (0x7FFF, 0x10203040),
]


def require(cond, msg):
    if not cond:
        raise RuntimeError(msg)


def validate(args):
    xvc = XVC(args.host, args.port)
    try:
        print(f"connected to {args.host}:{args.port} - {xvc.info}")
        if args.tck_ns is not None:
            actual = xvc.settck(args.tck_ns)
            print(f"settck({args.tck_ns} ns) -> {actual} ns")

        tap_reset_to_rti(xvc)
        select_user1(xvc)

        version = read_status_reg(xvc, 0xFE)
        status0 = read_status_reg(xvc, 0x00)
        print(f"version=0x{version:08x} status0=0x{status0:08x}")
        require(version == 0xB07EB001,
                f"expected BRAM proof version 0xB07EB001, got 0x{version:08x}")
        require((status0 >> 16) == 0xAB00,
                f"status magic mismatch: 0x{status0:08x}")

        for addr, data in TEST_VECTORS:
            st = jwb_wb_write(xvc, addr, data)
            require(((st >> 2) & 1) == 1,
                    f"write addr=0x{addr:04x} did not ack: status=0x{st:08x}")
            require(((st >> 1) & 1) == 0,
                    f"write addr=0x{addr:04x} reported err: status=0x{st:08x}")

        for addr, expected in TEST_VECTORS:
            got = jwb_wb_read(xvc, addr)
            print(f"read addr=0x{addr:04x} got=0x{got:08x} expected=0x{expected:08x}")
            require(got == expected,
                    f"readback mismatch at addr=0x{addr:04x}: got 0x{got:08x}, expected 0x{expected:08x}")

        # Explicit decoder isolation: these two addresses alias if SEL_BIT[14]
        # is ignored by the fabric.
        jwb_wb_write(xvc, 0x0000, 0x11112222)
        jwb_wb_write(xvc, 0x4000, 0x33334444)
        low = jwb_wb_read(xvc, 0x0000)
        high = jwb_wb_read(xvc, 0x4000)
        print(f"decode isolation low=0x{low:08x} high=0x{high:08x}")
        require(low == 0x11112222 and high == 0x33334444,
                "BRAM banks are not isolated by Wishbone decode bit 14")

        final_status = read_status_reg(xvc, 0x10)
        print(f"final_jwb_status=0x{final_status:08x}")
        require((final_status >> 16) == 0xAB10,
                f"JWB status magic mismatch: 0x{final_status:08x}")
        require(((final_status >> 3) & 1) == 0,
                f"JWB is still busy: 0x{final_status:08x}")
        require(((final_status >> 2) & 1) == 1,
                f"last JWB operation did not ack: 0x{final_status:08x}")
        require(((final_status >> 1) & 1) == 0,
                f"last JWB operation reported err: 0x{final_status:08x}")

        if args.resume:
            jwb_cmd(xvc, JWB_CMD_RESUME)

        print("RESULT PASS")
    finally:
        xvc.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="localhost")
    parser.add_argument("--port", type=int, default=3721)
    parser.add_argument("--tck-ns", type=int, default=None)
    parser.add_argument("--resume", action="store_true",
                        help="clear JTAG-WB halt_others before exiting")
    args = parser.parse_args()
    validate(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
