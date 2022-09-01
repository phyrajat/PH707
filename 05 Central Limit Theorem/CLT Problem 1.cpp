#include <random>
#include <array>
#include <cmath>
#include <fstream>

constexpr size_t samplesize = 10000;
constexpr std::array<double, 4> numvars = {5, 10, 100, 2000};

int main()
{
    std::array<double, samplesize> Z{};

    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    double sigmainverse = sqrt(12.0);
    double mean = 0.5;

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/problem2_2000.txt", std::ios::out | std::ios::trunc);

    for(auto& Zi : Z){
        for (size_t i = 0; i < numvars[3]; i++) {
            Zi += sigmainverse * (dist(rng) - mean);
        }
        Zi /= sqrt(numvars[3]);
        outfile << Zi << std::endl;
    }
    outfile.close();
}