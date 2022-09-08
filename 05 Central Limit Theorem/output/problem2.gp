set xlabel 'Z'
set ylabel '1/N dN/dZ'
set xrange [-10:10]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'problem2_2000.pdf'

samplesize = 10000
binwidth = 0.3
bin(x, width) = width * floor(x / width) + width/2.0

plot 'problem2_2000.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'sum of 2000 variables', exp(-x * x/2)/sqrt(2 * pi) title "Gaussian"
