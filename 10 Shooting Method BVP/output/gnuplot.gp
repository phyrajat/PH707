set xlabel 'Time'
set ylabel 'Angle'
set autoscale
set xrange [0:1]
#set style data linespoints
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'rk4 BVP.pdf'

plot 'BVP.txt' using 1:2 title "rk4 1024 steps" with lines
