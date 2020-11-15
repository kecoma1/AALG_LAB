# Title
set title "MergeSort Best, Average and Worst cases"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Basic operations"

#Range
set xrange [0:100000]
set yrange [0:2000000]

#fit lines
f(x) = a*x*log(x*b)
fit f(x) "mergesort.log" using 2:4 via a, b

g(x) = c*x*log(x*d)
fit g(x) "mergesort.log" using 2:6 via c, d

t(x) = f*x*log(x*g)
fit t(x) "mergesort.log" using 2:5 via f, g

#Plotting
plot "mergesort.log" using 2:4 title "Average BO  Θ(N·log(N))",\
"mergesort.log" using 2:5 title "Minimun BO  (1/2)·N·log(N)",\
"mergesort.log" using 2:6 title "Maximun BO  N·log(N)+O(N)",\
t(x) title "fit line (Minimum)",\
f(x) title "fit line (Average)",\
g(x) title "fit line (Maximum)"
