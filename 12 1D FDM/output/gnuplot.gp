set xlabel 'Time'
set ylabel 'Angle'
set xrange [0:1]
set yrange [0:1.8]
#set style data linespoints
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'Comparison.pdf'

plot 'relaxation.txt' using 1:2 title "Finite difference relaxation method 50 steps" with lines,'BVP.txt' using 1:2 title "Shooting method RK4 1024 steps" with lines
