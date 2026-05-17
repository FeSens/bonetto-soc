#!/usr/bin/env bash
# auto_cable_watcher.sh — polls for XPCU re-enumeration, triggers flash+validate.
#
# Usage:
#   nix develop --command bash tools/auto_cable_watcher.sh
#
# Polls ioreg every 5s. When idVendor=1021 (Xilinx 0x03fd) becomes visible
# AND we haven't already triggered, runs auto_flash_validate.sh.
set -uo pipefail

cd "$(dirname "$0")/.."
LOG=/tmp/auto_cable_watcher.log
STAMP=/tmp/auto_cable_watcher.stamp
: > "$LOG"

echo "== auto_cable_watcher started $(date) ==" | tee -a "$LOG"

prev=0
while true; do
    cur=$(ioreg -p IOUSB -l 2>/dev/null | awk '/"idVendor" = 1021/{found=1} END{print found+0}')
    if [ "$cur" != "$prev" ]; then
        echo "$(date) cable visible=$cur (was $prev)" | tee -a "$LOG"
        if [ "$cur" = "1" ]; then
            echo "  triggering auto_flash_validate.sh" | tee -a "$LOG"
            bash tools/auto_flash_validate.sh 2>&1 | tee -a "$LOG"
            echo "  flash+validate complete; see /tmp/silicon_next_steps.txt" | tee -a "$LOG"
        else
            echo "  cable disappeared; re-armed for next plug" | tee -a "$LOG"
        fi
        prev=$cur
    fi
    sleep 5
done
