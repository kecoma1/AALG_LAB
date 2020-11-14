# Title
set title "QuickSort time performance - Normal vs No tail recursion"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Time spent"

#Range
set xrange [0:100000]
set yrange [0:0.01]

#fit line
f(x) = a*x*log(x*b)
fit f(x) "quicksort.log" using 2:3 via a, b

#Plotting
plot "quicksort.log" using 2:3 title "Average Time spent (NORMAL)  2·Nlog(N)+O(N)",\
"quicksort_ntr.log" using 2:3 title "Average Time spent (No tail recursion)  2·Nlog(N)+O(N)",\
f(x) title "fit line (Average case)"

