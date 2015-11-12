# ECALDeadCell

#
# Making root histograms
#
root.exe -b -q 'fill_MET.C(0)'

# 0 can be 1,2,3,... depending on what sample you want to study

#
# Making plots
#
root.exe -b -q 'plot_MET.C(0)'

# 0 can be 1,2,3,... depending on what sample you want to study




