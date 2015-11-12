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

> 0 can be 1,2,3,... depending on what sample you want to study

>  0- 3 for V1 ntuples
> 20-23 for V2 ntuples
> 30-36 for V3 ntuples
> 40-43 for V4 ntuples

> For QCD MC datasets,   I used V1 (i.e. 3) and V4 (i.e. 43) mainly
> For Run2015C datasets, I used V3 (i.e.30) and V4 (i.e. 40) mainly

