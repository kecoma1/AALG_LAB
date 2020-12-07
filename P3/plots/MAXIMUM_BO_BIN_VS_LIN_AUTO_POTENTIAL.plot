# Title
set title "Binary search VS Linear auto search - Maximun basic operations - Potential key generator"

#Axis names
set xlabel "Size of the dictionary"
set ylabel "Basic operations"

#Range
set xrange [1000:50000]
#set yrange [0:100]

# Leyenda
set key left top
set grid

#fit lines
f(x) = a*log(b*x)+x*f
fit f(x) "Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_1.log" using 2:6 via a, b, f

g(x) = g*log(b*h)+x*i
fit g(x) "Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_100.log" using 2:6 via g, h, i

h(x) = j*log(k*x)+x*l
fit h(x) "Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_10000.log" using 2:6 via j, k, l

i(x) = ( (2*x*c)/(d*log(x*e)) )
fit i(x) "Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_1.log" using 2:6 via c, d, e

j(x) = ( (2*x*m)/(o*log(x*n)) )
fit j(x) "Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_100.log" using 2:6 via m, n, o

k(x) = ( (2*x*p)/(q*log(x*r)) )
fit k(x) "Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_10000.log" using 2:6 via p, q, r

#Plotting
plot "Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_1.log" using 2:6 title "Maximun BO BS n-times=1 - log(N)+O(1)",\
"Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_100.log" using 2:6 title "Maximun BO BS n-times=100 - log(N)+O(1)",\
"Data/Potential_key_generator/POTENTIAL_KEY_BINARY_SEARCH_10000.log" using 2:6 title "Maximun BO BS n-times=10000 - log(N)+O(1)",\
"Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_1.log" using 2:6 title "Maximun BO LAS n-times=1 - (2*N)/log(N)",\
"Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_100.log" using 2:6 title "Maximun BO LAS n-times=100 - (2*N)/log(N)",\
"Data/Potential_key_generator/POTENTIAL_KEY_LIN_AUTO_SEARCH_10000.log" using 2:6 title "Maximun BO LAS n-times=10000 - (2*N)/log(N)",\
f(x) title "fit line BS n-times=1",\
g(x) title "fit line BS n-times=100",\
h(x) title "fit line BS n-times=10000",\
i(x) title "fit line LAS n-times=1",\
j(x) title "fit line LAS n-times=100",\
k(x) title "fit line LAS n-times=10000"
