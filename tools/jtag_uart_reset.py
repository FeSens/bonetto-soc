#!/usr/bin/env python3
"""
jtag_uart_reset.py — attempts a libusb-level USB reset of the
Xilinx Platform Cable USB II.

Useful when the cable's FX2 firmware state appears wedged
(detect times out reading "constant", openFPGALoader hangs in
displayCableVersion).

Requirements:
  pip install pyusb

Limitations:
  If the cable's FX2 microcontroller has stopped responding to
  control transfers entirely (LIBUSB_ERROR_TIMEOUT on reset),
  there is no software fix. Physical unplug is required.

Usage:
  python3 tools/jtag_uart_reset.py
"""
import sys

try:
    import usb.core
    import usb.util
except ImportError:
    sys.exit("pyusb not installed. Run: pip install pyusb")


XPCU_VID = 0x03FD
XPCU_PIDS = [0x0013, 0x0008]   # pre- and post-firmware enumeration


def find_cable():
    for pid in XPCU_PIDS:
        dev = usb.core.find(idVendor=XPCU_VID, idProduct=pid)
        if dev is not None:
            return dev, pid
    return None, None


def main():
    dev, pid = find_cable()
    if dev is None:
        print(f"no XPCU cable found (looked for VID=0x{XPCU_VID:04x} "
              f"PID in {[hex(p) for p in XPCU_PIDS]})")
        return 1

    print(f"found XPCU cable at VID=0x{XPCU_VID:04x} PID=0x{pid:04x}")
    try:
        dev.reset()
        print("USB reset issued (libusb_reset_device). Cable should "
              "re-enumerate; retry your operation.")
        return 0
    except usb.core.USBError as e:
        print(f"reset failed: {e}")
        print("The FX2 microcontroller is unresponsive to control "
              "transfers — physical unplug-replug is required.")
        return 1


if __name__ == "__main__":
    sys.exit(main())
