# Scalar DQS aliases for the single-lane SERDES diagnostic top.
#
# Yosys collapses one-bit vectors such as ddr3_dqs_p[0:0] into scalar ports in
# the JSON, while the full-board CH0 XDC constrains ddr3_dqs_p[0]. Keep this
# overlay local to the lane-only route target.

set_property PACKAGE_PIN AK16 [get_ports {ddr3_dqs_p}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddr3_dqs_p}]
set_property PACKAGE_PIN AK17 [get_ports {ddr3_dqs_n}]
set_property IOSTANDARD DIFF_SSTL15 [get_ports {ddr3_dqs_n}]
