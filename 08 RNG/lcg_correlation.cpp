#include <array>
#include <cmath>
#include <fstream>

unsigned long state = 5;
constexpr unsigned long a = 100019;
constexpr unsigned long b = 10067;
constexpr unsigned long my_rand_max = 107;

unsigned long random(){
    state = (state * a + b) % my_rand_max;
    return state;
}

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 1000;

int main() {
    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/lcg samples for correlation.txt", std::ios::out | std::ios::trunc);

    for (size_t i = 0; i < samplesize; i++) {
        double x_0 = state / (double) my_rand_max;
        double x_1 = random() / (double) my_rand_max;

        outfile << x_0 << "\t" << x_1 << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}