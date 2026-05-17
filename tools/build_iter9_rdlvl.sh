#!/usr/bin/env bash
# build_iter9_rdlvl.sh — build the YPCB-00338 bitstream variant with
# read-leveling actually enabled (SKIP_RDLVL=0).
#
# This is a contingency variant: the default bitstream (iter-8) ships with
# SKIP_RDLVL=1, which works only if the MMCM's static 90deg DQS phase +
# IDELAY_TAP=0 happen to land inside the DDR3 read window. If silicon
# shows DDR3 returning wrong data (rather than 0 or 0xAAAAAAAA), the cal
# is needed and this variant is what to flash.
#
# Produces:  boards/ypcb-00338/build/bonetto_soc_iter9_rdlvl.bit
# Leaves the source on main pointing at iter-8 (SKIP_RDLVL=1) unchanged.
set -euo pipefail

cd "$(dirname "$0")/.."
BOARD=boards/ypcb-00338
TOP=$BOARD/rtl/top.v

# 1. Patch top.v to SKIP_RDLVL=0 + tag version with 0x9XXX so the host
#    can tell an rdlvl-variant bitstream apart from the default. Matches
#    any current default version constant (iter-12: 0x000D, iter-13/13b:
#    0x000E, etc — uses the last byte from the current default).
#
#    Important: take a single pristine backup BEFORE editing, because
#    'sed -i.bak' overwrites the .bak file on each invocation.
cp $TOP $TOP.orig
sed -i.bak -E 's|ddr3_cal_seq #\(\.SKIP_WLVL\(1\), \.SKIP_RDLVL\(1\)\)|ddr3_cal_seq #(.SKIP_WLVL(1), .SKIP_RDLVL(0))|' $TOP
# Bump iter ID: 16'h00xx → 16'h90xx so host sees a clear "rdlvl variant" marker.
sed -i.bak -E "s|\\{16'hB07E, 16'h00([0-9A-Fa-f]{2})\\}|{16'hB07E, 16'h90\\1}|" $TOP

# 2. Build.
(cd $BOARD && rm -f build/bonetto_soc_ypcb00338.bit build/post_synth.json && make build/bonetto_soc_ypcb00338.bit)

# 3. Save under a versioned name.
cp $BOARD/build/bonetto_soc_ypcb00338.bit $BOARD/build/bonetto_soc_iter9_rdlvl.bit

# 4. Revert top.v from the pristine pre-edit copy.
mv $TOP.orig $TOP
rm -f $BOARD/rtl/*.bak

# 5. Rebuild the iter-8 default so the working copy is back to baseline.
(cd $BOARD && rm -f build/bonetto_soc_ypcb00338.bit build/post_synth.json && make build/bonetto_soc_ypcb00338.bit)

echo
echo "OK: rdlvl variant saved as $BOARD/build/bonetto_soc_iter9_rdlvl.bit"
echo "    default bitstream restored as $BOARD/build/bonetto_soc_ypcb00338.bit"
echo "To flash the rdlvl variant instead of the default:"
echo "  (cd $BOARD && make program BITSTREAM=build/bonetto_soc_iter9_rdlvl.bit)"
echo "The version register (0xFE) reads 0x90xx for the rdlvl variant vs 0x00xx default."
