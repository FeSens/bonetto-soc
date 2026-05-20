# Tool-compatible active subset of vendor/ypcb003381p1.xdc.
#
# The raw vendor file stays checked in next to this file. This subset is for
# nextpnr builds that only expose the active board ports; it avoids inventing
# dummy PCIe/flash/sensor ports just to satisfy constraints.

# 50 MHz system clock
set_property PACKAGE_PIN AA28 [get_ports SYS_CLK]
set_property IOSTANDARD LVCMOS18 [get_ports SYS_CLK]
create_clock -name sys_clk -period 20.000 [get_ports SYS_CLK]

# Board reset
set_property PACKAGE_PIN R28 [get_ports SYS_RSTN]
set_property IOSTANDARD LVCMOS18 [get_ports SYS_RSTN]

# LEDs
set_property PACKAGE_PIN P30 [get_ports {led_3bits_tri_o[0]}]
set_property PACKAGE_PIN M30 [get_ports {led_3bits_tri_o[1]}]
set_property PACKAGE_PIN N30 [get_ports {led_3bits_tri_o[2]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led_3bits_tri_o[0]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led_3bits_tri_o[1]}]
set_property IOSTANDARD LVCMOS18 [get_ports {led_3bits_tri_o[2]}]
