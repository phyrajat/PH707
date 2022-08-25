set xlabel 'Time'
set ylabel 'Angle'
set autoscale
set xrange [0:4 * pi]
#set style data linespoints
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output './pdfs/comparison rk4 taylor.pdf'

plot 'comparison rk4.txt' using 1:2 title "rk4 1000 steps" with lines, 'comparison Taylor.txt' using 1:2 title "4th order Taylor 1000 steps" with lines
