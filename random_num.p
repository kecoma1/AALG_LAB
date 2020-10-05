#Title
set title "Frequency histogram"

#Axis names

set xlabel "Numbers"
set ylabel "Frequency"

#Axis range

set xrange [1:20]
set yrange [450000:520000]

#Average line

plot "random_nums" with boxes, 500000 title "500000 (Average)"

set term png
set output "random_plot.png"
replot