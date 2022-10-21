#include <array>
#include <random>
#include <fstream>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 10000;

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 randomwalk(350);    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(-1, 1); // distribution in range [-1, 1]

    std::array<double, samplesize> positions = {};
    double position = 0;

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/random walk.txt", std::ios::out | std::ios::trunc);

    for (auto& x : positions) {   //loop over number of samples to be drawn
        position += dist(randomwalk);
        x = position;
        outfile << x << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}