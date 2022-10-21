set xlabel 'Position'
set ylabel 'Freq'
#set xrange [0:5]

set ytics nomirror
set xtics nomirror

set terminal pdf font "Times New Roman-Bold"

set output 'metropolis exp.pdf'

samplesize = 500000
binwidth = 0.2
bin(x, width) = width * floor(x / width) + width/2.0

plot 'metropolis exp.txt' using (bin($1, binwidth)):(1.0 / (binwidth * samplesize)) smooth freq with boxes title 'Plot of Metropolis distribution', exp(-x) title "Exponential"
