#include <random>
#include <array>
#include <cmath>
#include <fstream>

//Constant expressions appearing in the code
constexpr size_t samplesize = 10000;    //The sample size for plotting final distribution - this many numbers will be drawn
constexpr std::array<double, 4> numvars = {5, 10, 100, 2000};   //array of the number of random variables

int main()
{
    std::array<double, samplesize> Z{}; //array to store the values, in case we need

    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    double sigmainverse = sqrt(12.0);   // 1/(standard deviation) for the uniform distribution
    double mean = 0.5;  //mean of the uniform distribution

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/problem2_2000.txt", std::ios::out | std::ios::trunc);

    for(auto& Zi : Z){  //Loop through the array to store the values
        for (size_t i = 0; i < numvars[3]; i++) {   //loop through the number of variables to sum over
            Zi += sigmainverse * (dist(rng) - mean);    //calculate Yi and add to Z
        }
        Zi /= sqrt(numvars[3]); //divide by sqrt(n)
        outfile << Zi << std::endl; //write in the output file.
    }
    outfile.close();    //when done, close the file.
}