set xlabel 'Position'
set ylabel 'Freq'
#set xrange [-50:50]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'random walk.pdf'

samplesize = 1000000
binwidth = 5.0
bin(x, width) = width * floor(x / width) + width/2.0

plot 'random walk.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'Plot of RW distribution'
