#include <iostream>
#include <cmath>
#include <random>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 100000;

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    double Sn = 0;  //Counter for total 

    for (size_t i = 0; i < samplesize; i++) {
        double x = dist(rng), y = dist(rng);
        if (y < exp(- x * x)) {
            Sn++;
        }
    }

    std::cout << "The integration value is: " << Sn / samplesize << std::endl;
}