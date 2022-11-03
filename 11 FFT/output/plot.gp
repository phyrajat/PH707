set xlabel 'k'
set ylabel 'X(k)'
set xrange [0:2]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

time = 10
sample = 2048

set output '10s_2048samples.pdf'

plot 'FFT.txt' using ($0/time):($1/sqrt(sample)) with lines title 'Real Part', 'FFT.txt' using ($0/time):($2/sqrt(sample)) with lines title 'Imaginary Part'
