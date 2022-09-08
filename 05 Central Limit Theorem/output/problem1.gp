set xlabel 'Y1'
set ylabel '1/N dN/dY1'
set xrange [-5:5]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'problem1.pdf'

samplesize = 10000
binwidth = 0.3
bin(x, width) = width * floor(x / width) + width/2.0

plot 'problem1.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'Plot of Y1 distribution'
