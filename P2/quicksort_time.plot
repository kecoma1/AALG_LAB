# Title
set title "QuickSort time performance"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Time spent"

#Range
set xrange [1000:100000]
set yrange [0:0.01]

#fit line
f(x) = a*x*log(x*b)
fit f(x) "quick_sort.log" using 2:3 via a, b

#Plotting
plot "quick_sort.log" using 2:3 title "Average Time spent",\
f(x) title "fit line (Average case) - a*x*log(x*b)"
