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

plot 'metropolis exp.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'Plot of Metropolis distribution'
