# Title
set title "QuickSort Best, Average and Worst cases"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Basic operations"

#Range
set xrange [0:100000]
set yrange [0:2700000]

#fit lines
f(x) = a*x*log(x*b)
fit f(x) "quicksort.log" using 2:4 via a, b

g(x) = c*x**2+d*x+e
fit g(x) "quicksort.log" using 2:6 via c, d, e

t(x) = f*x*log(x*g)
fit t(x) "quicksort.log" using 2:5 via f, g

#Plotting
plot "quicksort.log" using 2:4 title "Average BO  2·Nlog(N)+O(N)" with lines,\
f(x) title "fit line (Average)",\
"quicksort.log" using 2:5 title "Minimun BO  O(n·log(n))" with lines,\
t(x) title "fit line (Minimum)",\
"quicksort.log" using 2:6 title "Maximun BO  N²/2 - N/2" with lines,\
g(x) title "fit line (Maximum)"
