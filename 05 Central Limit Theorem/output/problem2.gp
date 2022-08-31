set xlabel 'Z'
set ylabel 'Frequency'
set autoscale
set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'problem2.pdf'

samplesize = 10000
binwidth = 0.3
bin(x, width) = width * floor(x / width)

plot 'problem2.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'sum of 5 variables'
