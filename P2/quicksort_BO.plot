# Title
set title "QuickSort Best, Average and Worst cases"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Basic operations"

#Range
set xrange [1000:100000]
set yrange [0:2700000]

#fit lines
f(x) = a*x*log(x*b)
fit f(x) "quicksort.log" using 2:4 via a, b

g(x) = c*x**2+d*x+e
fit g(x) "quicksort.log" using 2:6 via c, d, e

t(x) = f*x*log(x*g)
fit t(x) "quicksort.log" using 2:5 via f, g

#Plotting
plot "quicksort.log" using 2:4 title "Average BO" with lines,\
f(x) title "fit line (Average) - a*x*log(x*b)",\
"quicksort.log" using 2:5 title "Minimun BO" with lines,\
t(x) title "fit line (Minimum) - f*x*log(x*g)",\
"quicksort.log" using 2:6 title "Maximun BO" with lines,\
g(x) title "fit line (Maximum) - c*x**2+d*x+e"
