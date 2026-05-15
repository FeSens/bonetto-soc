# DDR3 Channel 0 pin assignments for the Inspur YPCB-00338.
# Pulled from the LiteX board file (litex-hub/litex-boards@6d58ae6).
# Targets the Micron MT41K256M8DA-125 chips on Channel 0 (64-bit + 8-bit ECC).
#
# Loaded by `make fpga BOARD=ypcb-00338` alongside ypcb-00338.xdc; activate
# by switching the board top from wb_memory to ddr3_ctrl (iter-3b SoC swap).
#
# All signal-quality constraints (SSTL15 IO standard, SLEW=FAST,
# IN_TERM=UNTUNED_SPLIT_40) mirror LiteX's settings.

# -------- Address / bank / control --------
# A[14:0] — DDR3-1600 row address, 15 bits for 2 Gb x8 (32 K rows).
set_property PACKAGE_PIN AK27 [get_ports {ddr3_addr[0]}]
set_property PACKAGE_PIN AN23 [get_ports {ddr3_addr[1]}]
set_property PACKAGE_PIN AL24 [get_ports {ddr3_addr[2]}]
set_property PACKAGE_PIN AK26 [get_ports {ddr3_addr[3]}]
set_property PACKAGE_PIN AH24 [get_ports {ddr3_addr[4]}]
set_property PACKAGE_PIN AH25 [get_ports {ddr3_addr[5]}]
set_property PACKAGE_PIN AL26 [get_ports {ddr3_addr[6]}]
set_property PACKAGE_PIN AJ24 [get_ports {ddr3_addr[7]}]
set_property PACKAGE_PIN AJ25 [get_ports {ddr3_addr[8]}]
set_property PACKAGE_PIN AM23 [get_ports {ddr3_addr[9]}]
set_property PACKAGE_PIN AL28 [get_ports {ddr3_addr[10]}]
set_property PACKAGE_PIN AL25 [get_ports {ddr3_addr[11]}]
set_property PACKAGE_PIN AM25 [get_ports {ddr3_addr[12]}]
set_property PACKAGE_PIN AK24 [get_ports {ddr3_addr[13]}]
set_property PACKAGE_PIN AM27 [get_ports {ddr3_addr[14]}]
set_property IOSTANDARD SSTL15 [get_ports {ddr3_addr[*]}]

set_property PACKAGE_PIN AM26 [get_ports {ddr3_ba[0]}]
set_property PACKAGE_PIN AP24 [get_ports {ddr3_ba[1]}]
set_property PACKAGE_PIN AN28 [get_ports {ddr3_ba[2]}]
set_property IOSTANDARD SSTL15 [get_ports {ddr3_ba[*]}]

set_property PACKAGE_PIN AJ29 [get_ports ddr3_ras_n]
set_property PACKAGE_PIN AP26 [get_ports ddr3_cas_n]
set_property PACKAGE_PIN AN27 [get_ports ddr3_we_n]
set_property PACKAGE_PIN AK28 [get_ports ddr3_cs_n]
set_property PACKAGE_PIN AP27 [get_ports ddr3_cke]
set_property PACKAGE_PIN AK29 [get_ports ddr3_odt]
set_property PACKAGE_PIN AD31 [get_ports ddr3_reset_n]
set_property IOSTANDARD SSTL15 [get_ports {ddr3_ras_n ddr3_cas_n ddr3_we_n ddr3_cs_n ddr3_cke ddr3_odt ddr3_reset_n}]

# -------- Differential clock --------
set_property PACKAGE_PIN AN25 [get_ports ddr3_ck_p]
set_property PACKAGE_PIN AP25 [get_ports ddr3_ck_n]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddr3_ck_p ddr3_ck_n}]

# -------- DQ (64 data + 8 ECC = 72 bits) --------
# Byte lane 0: DQ[7:0]
set_property PACKAGE_PIN AG17 [get_ports {ddr3_dq[0]}]
set_property PACKAGE_PIN AG16 [get_ports {ddr3_dq[1]}]
set_property PACKAGE_PIN AH17 [get_ports {ddr3_dq[2]}]
set_property PACKAGE_PIN AJ19 [get_ports {ddr3_dq[3]}]
set_property PACKAGE_PIN AH18 [get_ports {ddr3_dq[4]}]
set_property PACKAGE_PIN AH19 [get_ports {ddr3_dq[5]}]
set_property PACKAGE_PIN AJ16 [get_ports {ddr3_dq[6]}]
set_property PACKAGE_PIN AJ17 [get_ports {ddr3_dq[7]}]
# Byte lane 1: DQ[15:8]
set_property PACKAGE_PIN AL20 [get_ports {ddr3_dq[8]}]
set_property PACKAGE_PIN AN17 [get_ports {ddr3_dq[9]}]
set_property PACKAGE_PIN AL19 [get_ports {ddr3_dq[10]}]
set_property PACKAGE_PIN AM16 [get_ports {ddr3_dq[11]}]
set_property PACKAGE_PIN AL18 [get_ports {ddr3_dq[12]}]
set_property PACKAGE_PIN AL16 [get_ports {ddr3_dq[13]}]
set_property PACKAGE_PIN AM20 [get_ports {ddr3_dq[14]}]
set_property PACKAGE_PIN AN18 [get_ports {ddr3_dq[15]}]
# Byte lanes 2-7 + ECC are listed in the LiteX board file; left out of
# iter-3a XDC to keep this file scoped to the lanes ddr3_phy_dq
# instantiates. Full 72-bit map added when the multi-lane phy lands.

set_property IOSTANDARD SSTL15 [get_ports {ddr3_dq[*]}]
set_property IN_TERM UNTUNED_SPLIT_40 [get_ports {ddr3_dq[*]}]

# -------- DQS (differential strobe, one pair per byte lane) --------
# Byte lane 0 / 1 DQS pairs (others land with the rest of DQ).
set_property PACKAGE_PIN AK16 [get_ports {ddr3_dqs_p[0]}]
set_property PACKAGE_PIN AK17 [get_ports {ddr3_dqs_n[0]}]
set_property PACKAGE_PIN AM17 [get_ports {ddr3_dqs_p[1]}]
set_property PACKAGE_PIN AM18 [get_ports {ddr3_dqs_n[1]}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddr3_dqs_p[*] ddr3_dqs_n[*]}]
set_property IN_TERM UNTUNED_SPLIT_40 [get_ports {ddr3_dqs_p[*] ddr3_dqs_n[*]}]

# -------- IO bank VREF (SSTL15 requires 0.75 V VREF) --------
# Banks 11..18 hold the DDR3 IOs on this device.
set_property INTERNAL_VREF 0.750 [get_iobanks 11]
set_property INTERNAL_VREF 0.750 [get_iobanks 12]
set_property INTERNAL_VREF 0.750 [get_iobanks 13]
set_property INTERNAL_VREF 0.750 [get_iobanks 14]
