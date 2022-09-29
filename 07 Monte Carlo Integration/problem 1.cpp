#include <iostream>
#include <random>
#include <fstream>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 100000;

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 rng(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> dist(0,1); // distribution in range [0, 1]

    double Sn = 0;  //counter for points inside circle

    for (size_t i = 0; i < samplesize; i++) {   //loop over number of samples to be drawn
        double x = dist(rng), y = dist(rng);    //random (x,y) coordinates
        if (x * x + y * y < 1) {    //check if inside circle, in first quadrant
            Sn++;   //increase counter
        }
    }

    std::cout << "Area of circle with radius 1: " << 4.0 * Sn / samplesize << std::endl;
}