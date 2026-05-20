#!/usr/bin/env python3
"""Interactive BRAM echo terminal over XVC/JTAG-Wishbone.

Program the BRAM proof bitstream, start the board XVC server, then run this
tool. Each input line is written to BRAM through JTAG-Wishbone, read back from
the same addresses, and printed as the echoed text.
"""

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


PROOF_VERSION = 0xB07EB001
DEFAULT_BASE_ADDR = 0x0200
BRAM_ADDR_LIMIT = 0x8000


def pack_words(data: bytes) -> list[int]:
    words = []
    for offset in range(0, len(data), 4):
        chunk = data[offset:offset + 4]
        words.append(int.from_bytes(chunk.ljust(4, b"\x00"), "little"))
    return words


def unpack_words(words: list[int], n_bytes: int) -> bytes:
    out = bytearray()
    for word in words:
        out.extend((word & 0xFFFFFFFF).to_bytes(4, "little"))
    return bytes(out[:n_bytes])


def parse_text_arg(text: str) -> str:
    # Allows quick smoke tests like --once 'hello\nworld' without making the
    # interactive path interpret backslashes unexpectedly.
    return bytes(text, "utf-8").decode("unicode_escape")


def connect(args):
    xvc = XVC(args.host, args.port)
    print(f"connected to {args.host}:{args.port} - {xvc.info}")
    if args.tck_ns is not None:
        actual = xvc.settck(args.tck_ns)
        print(f"settck({args.tck_ns} ns) -> {actual} ns")

    tap_reset_to_rti(xvc)
    select_user1(xvc)

    version = read_status_reg(xvc, 0xFE)
    if version != PROOF_VERSION:
        xvc.close()
        raise RuntimeError(
            f"expected BRAM proof version 0x{PROOF_VERSION:08x}, "
            f"got 0x{version:08x}; program the jtag-bram bitstream first"
        )

    status = read_status_reg(xvc, 0x00)
    if (status >> 16) != 0xAB00:
        xvc.close()
        raise RuntimeError(f"BRAM proof status magic mismatch: 0x{status:08x}")

    return xvc


def memory_echo(xvc, text: str, base_addr: int, verbose: bool = False,
                transform: bool = False) -> str:
    payload = text.encode("utf-8")
    words = pack_words(payload)
    if base_addr < 0 or base_addr + len(words) > BRAM_ADDR_LIMIT:
        raise ValueError(
            f"message needs {len(words)} words starting at 0x{base_addr:04x}, "
            f"outside BRAM proof address range 0x0000..0x{BRAM_ADDR_LIMIT - 1:04x}"
        )

    for idx, word in enumerate(words):
        st = jwb_wb_write(xvc, base_addr + idx, word)
        if ((st >> 2) & 1) == 0 or ((st >> 1) & 1) != 0:
            raise RuntimeError(
                f"write failed at addr=0x{base_addr + idx:04x}: status=0x{st:08x}"
            )

    read_words = [jwb_wb_read(xvc, base_addr + idx) for idx in range(len(words))]
    echoed = unpack_words(read_words, len(payload))
    if not transform and echoed != payload:
        raise RuntimeError(
            f"BRAM echo mismatch: wrote {payload!r}, read {echoed!r}"
        )

    if verbose:
        for idx, (wrote, read) in enumerate(zip(words, read_words)):
            print(f"  [0x{base_addr + idx:04x}] write=0x{wrote:08x} read=0x{read:08x}")

    return echoed.decode("utf-8", errors="replace")


def repl(xvc, args):
    mode = "transform" if args.transform else "echo"
    print(f"BRAM {mode} terminal. Type text and press Enter; :quit exits.")
    while True:
        try:
            line = input("bram> ")
        except EOFError:
            print()
            break
        if line in (":q", ":quit", ":exit"):
            break
        echoed = memory_echo(xvc, line, args.base_addr, args.verbose, args.transform)
        print(f"echo> {echoed}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="localhost")
    parser.add_argument("--port", type=int, default=3721)
    parser.add_argument("--tck-ns", type=int, default=2000)
    parser.add_argument("--base-addr", type=lambda s: int(s, 0),
                        default=DEFAULT_BASE_ADDR,
                        help="scratch BRAM word address (default: 0x0200)")
    parser.add_argument("--once",
                        help="write/read one string and exit; backslash escapes are decoded")
    parser.add_argument("--verbose", action="store_true",
                        help="print every 32-bit memory word written/read")
    parser.add_argument("--transform", action="store_true",
                        help="print FPGA-returned data without requiring it to match the input")
    parser.add_argument("--resume-on-exit", action="store_true",
                        help="clear JTAG-WB halt_others before disconnecting")
    args = parser.parse_args()

    xvc = connect(args)
    try:
        if args.once is not None:
            echoed = memory_echo(xvc, parse_text_arg(args.once), args.base_addr,
                                 args.verbose, args.transform)
            print(f"echo> {echoed}")
        else:
            repl(xvc, args)
        if args.resume_on_exit:
            jwb_cmd(xvc, JWB_CMD_RESUME)
    finally:
        xvc.close()

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
