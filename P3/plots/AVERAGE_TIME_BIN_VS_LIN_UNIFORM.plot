# Title
set title "Binary search VS Linear search - Average time"

#Axis names
set xlabel "Size of the dictionary"
set ylabel "Execution time"

#Range
set xrange [1000:50000]
#set yrange [0:30000]

# Leyenda
set key left top
set grid

#fit lines
f(x) = a*log(b*x)+x*f
fit f(x) "Data/Uniform_key_generator/UNIFORM_KEY_BINARY_SEARCH.log" using 2:3 via a, b, f

g(x) = ( (2*x*c)/(d*log(x*e)) )
fit g(x) "Data/Uniform_key_generator/UNIFORM_KEY_LINEAR_SEARCH.log" using 2:3 via c, d, e

#Plotting
plot "Data/Uniform_key_generator/UNIFORM_KEY_BINARY_SEARCH.log" using 2:3 title "Average time BS - log(N)+O(1)",\
"Data/Uniform_key_generator/UNIFORM_KEY_LINEAR_SEARCH.log" using 2:3 title "Average time LS  (2*N)/log(N)",\
f(x) title "fit line BS",\
g(x) title "fit line LS"
