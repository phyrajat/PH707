set xlabel 't'
set ylabel '<e^{-xt}>'
set xrange [0:5]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'characteristic func.pdf'

plot 'manual characteristic function.txt' using 1:2 with lines title 'hand generated characteristic function', 'computed characteristic function.txt' using 1:2 with lines title 'computer generated characteristic function', (1 - exp(-x )) / x title "exact characteristic function"
