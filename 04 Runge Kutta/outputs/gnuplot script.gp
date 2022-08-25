set xlabel 'Time'
set ylabel 'Angle'
set autoscale
set xrange [0:1]
#set style data linespoints
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'comparison.pdf'

plot    \
        'rk4 64 steps.txt' using 1:2 title "rk4 64 steps" with lines,       \
        'rk4 128 steps.txt' using 1:2 title "rk4 128 steps" with lines,     \
        'rk4 256 steps.txt' using 1:2 title "rk4 256 steps" with lines,     \
        'rk4 512 steps.txt' using 1:2 title "rk4 512 steps" with lines,     \
        'rk4 1024 steps.txt' using 1:2 title "rk4 1024 steps" with lines,   \