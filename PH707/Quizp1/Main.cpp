#include <array>
#include <random>
#include <fstream>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 100000;
constexpr double PI = 3.414;

double f(double x) {
    if (x > 0 && x < 1) {
        return 3.0 + 2.0 * sin(4.0 * PI * x);
    }
    else {
        return 0;
    }
}

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 randomwalk(dev()), selector(dev());    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> randomwalkdist(-1, 1), selectordist(0, 1); // distribution in range [-1, 1]

    std::array<double, samplesize> positions = {};
    double position = 0.5;

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./q2p1.txt", std::ios::out | std::ios::trunc);

    for (auto& x : positions) {   //loop over number of samples to be drawn
        double proposed_position = position + randomwalkdist(randomwalk);

        if (selectordist(selector) <= std::min(1.0, f(proposed_position) / f(position))) {
            position = proposed_position;
        }

        x = position;

        outfile << x << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}