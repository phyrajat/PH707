#include <random>
#include <array>
#include <cmath>

constexpr size_t N = 1000;

int main()
{
    std::array<double, N> x;

    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    double sigmainverse = 1.0 / sqrt(12.0);
    double mean = 0.5;

    for (auto &xi : x) {
        xi = sigmainverse * (dist(rng) - mean);
    }
    
}