reset
set terminal png size 1000,600
set output 'Resources/graph.png'
set boxwidth 0.075
set style histogram
set style data histogram
set xrange [-1.2:1.2]
set xtics 0.1
plot 'Resources/histogram.dat' with boxes linetype rgb "orange" title "Sum of values"
