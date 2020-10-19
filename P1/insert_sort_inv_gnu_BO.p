# Title
set title "Insert Sort Inv Best, Average and Worst cases"

#Axis names
set xlabel "Size of the permutation"
set ylabel "Basic operations"

#Range
set xrange [100:500]
set yrange [2000:75000]

#fit line
f(x) = a*x**2 +b*x + c
fit f(x) "exercise5_inv.log" using 2:4 via a, b, c

#Plotting
plot "exercise5_inv.log" using 2:4 title "Average BO",\
"exercise5_inv.log" using 2:5 title "Minimun BO",\
"exercise5_inv.log" using 2:6 title "Maximun BO",\
f(x) title "fit line - a*x**2 + b*x + c"

