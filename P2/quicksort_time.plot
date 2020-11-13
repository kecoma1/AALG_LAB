# Title
set title "QuickSort time performance"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Time spent"

#Range
set xrange [1000:100000]
set yrange [0:0.009]

#fit line
f(x) = a*x*log(x*b)
fit f(x) "quicksort.log" using 2:3 via a, b

#Plotting
plot "quicksort.log" using 2:3 title "Average Time spent  2·Nlog(N)+O(N)" with line,\
f(x) title "fit line (Average case)"
