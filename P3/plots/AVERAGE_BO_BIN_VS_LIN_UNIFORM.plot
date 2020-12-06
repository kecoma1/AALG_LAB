# Title
set title "Binary search VS Linear search - Average basic operations"

#Axis names
set xlabel "Size of the dictionary"
set ylabel "Basic operations"

#Range
#set xrange [1:400]
#set yrange [0:6000]

#fit lines
f(x) = a*log(x)+1
fit f(x) "Data/UNIFORM_KEY_BINARY_SEARCH.log" using 2:4 via a

g(x) = ( (2*x*b)/(c*log(x)) )
fit g(x) "Data/UNIFORM_KEY_LINEAR_SEARCH.log" using 2:4 via b, c

#Plotting
plot "Data/UNIFORM_KEY_BINARY_SEARCH.log" using 2:4 title "Average BO BS - log(N)+O(1)",\
"Data/UNIFORM_KEY_LINEAR_SEARCH.log" using 2:4 title "Average BO LS  (2*N)/log(N)",\
f(x) title "fit line BS",\
g(x) title "fit line LS"
