# Title
set title "Insert Sort Best, Average and Worst cases"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Time spent"

#Range
set xrange [100:500]
set yrange [0:0.0002]

#fit line
f(x) = a*x**2 +b*x + c
fit f(x) "exercise5_inv.log" using 2:3 via a, b, c

#Plotting
plot "exercise5_inv.log" using 2:3 title "Average Time spent",\
f(x) title "fit line - a*x**2 + b*x + c"

