set xlabel 'Time'
set ylabel 'Angle'
set autoscale
set style data lines
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'physical pendulum plot.pdf'

plot 'tableau.txt' using 1:2 title "general rk4", 'rk4.txt' using 1:2 title "rk4"