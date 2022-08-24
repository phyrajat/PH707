set xlabel 'Time'
set ylabel 'Angle'
set autoscale
set xrange [0:1]
#set style data linespoints
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'physical pendulum plot.pdf'

plot 'tableau.txt' using 1:2 title "rk1(2) adaptive stepzise" with linespoints, 'rk4.txt' using 1:2 title "rk4 with 1000 steps" with lines
