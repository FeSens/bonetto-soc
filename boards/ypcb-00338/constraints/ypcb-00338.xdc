# Inspur YPCB-00338 -- xc7k480t-ffg1156-2 -- pin/timing constraints
# Pin assignments from LiteX board file (litex-hub/litex-boards@6d58ae6)
# and TiferKing/ypcb_00338_1p1_hack.

# 50 MHz system clock
set_property PACKAGE_PIN AA28 [get_ports clk_50]
set_property IOSTANDARD LVCMOS18 [get_ports clk_50]
create_clock -name sys_clk -period 20.000 [get_ports clk_50]

# LEDs (LVCMOS18)
# led[0] = P30  (red)
# led[1] = M30  (green)
# led[2] = N30  (yellow)
set_property PACKAGE_PIN P30 [get_ports {led[0]}]
set_property PACKAGE_PIN M30 [get_ports {led[1]}]
set_property PACKAGE_PIN N30 [get_ports {led[2]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led[0]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led[1]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led[2]}]
