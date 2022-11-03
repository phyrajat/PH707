set xlabel 'k'
set ylabel 'X_k'
set xrange [0:50]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'FFT.pdf'

plot 'FFT.txt' using 1 with lines title 'Real Part', 'FFT.txt' using 2 with lines title 'Imaginary Part'
