set xlabel 'Position'
set ylabel 'Freq'
set xrange [0:1]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'blind calculation.pdf'

samplesize = 1000000
binwidth = 0.05
bin(x, width) = width * floor(x / width) + width/2.0

plot 'q2p1.txt' using (bin($1, binwidth)):(10.0 / (binwidth * samplesize)) smooth freq with boxes title 'Plot of Metropolis distribution', (1 + 2 * sin(4 * pi * x))
