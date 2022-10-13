set xlabel 'x_{n}'
set ylabel 'x_{n+1}'
set xrange [0:1]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'correlation mt.pdf'

plot 'mt samples for correlation.txt' using 1:2 with points pt 0 ps 1 title 'mersenne twister correlation plot'
