#include <random>
#include <array>
#include <cmath>
#include <fstream>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 1000;

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/mt samples for correlation.txt", std::ios::out | std::ios::trunc);

    double x_0 = 0.0, x_1 = 0.0;

    for (size_t i = 0; i < samplesize; i++) {
        x_0 = x_1;
        x_1 = dist(rng);

        outfile << x_0 << "\t" << x_1 << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}