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

# 1. Patch top.v to SKIP_RDLVL=0 + bump version to 0x0009.
sed -i.bak -E 's|ddr3_cal_seq #\(\.SKIP_WLVL\(1\), \.SKIP_RDLVL\(1\)\)|ddr3_cal_seq #(.SKIP_WLVL(1), .SKIP_RDLVL(0))|' $TOP
sed -i.bak -E "s|\\{16'hB07E, 16'h0008\\}|{16'hB07E, 16'h0009}|" $TOP

# 2. Build.
(cd $BOARD && rm -f build/bonetto_soc_ypcb00338.bit build/post_synth.json && make build/bonetto_soc_ypcb00338.bit)

# 3. Save under a versioned name.
cp $BOARD/build/bonetto_soc_ypcb00338.bit $BOARD/build/bonetto_soc_iter9_rdlvl.bit

# 4. Revert top.v.
mv $TOP.bak $TOP
rm -f $BOARD/rtl/*.bak

# 5. Rebuild the iter-8 default so the working copy is back to baseline.
(cd $BOARD && rm -f build/bonetto_soc_ypcb00338.bit build/post_synth.json && make build/bonetto_soc_ypcb00338.bit)

echo
echo "OK: iter-9 saved as $BOARD/build/bonetto_soc_iter9_rdlvl.bit"
echo "    iter-8 restored as $BOARD/build/bonetto_soc_ypcb00338.bit"
echo "To flash iter-9 instead of iter-8:"
echo "  (cd $BOARD && make program BITSTREAM=build/bonetto_soc_iter9_rdlvl.bit)"
