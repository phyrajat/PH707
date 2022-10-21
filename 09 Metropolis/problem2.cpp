#include <array>
#include <random>
#include <fstream>

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 500000;

double f(double x){
    if (x <= 0){
        return 0;
    }else{
        return exp( - x );
    }
}

int main() {
    std::random_device dev; //Responsible for getting a random seed from OS
    std::mt19937_64 randomwalk(250);    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::mt19937_64 selector(350);    //Mersenne Twister engine with the seed for generating pseudo-random numbers
    std::uniform_real_distribution<double> randomwalkdist(-1, 1); // distribution in range [-1, 1]
    std::uniform_real_distribution<double> selectordist(0, 1); // distribution in range [0, 1]

    std::array<double, samplesize> positions = {};
    double position = 0;

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/metropolis exp.txt", std::ios::out | std::ios::trunc);

    for (auto& x : positions) {   //loop over number of samples to be drawn
        double proposed_position = position + randomwalkdist(randomwalk);

        if(selectordist(selector) <= std::min(1.0, f(proposed_position) / f(position))){
            position = proposed_position;
        }

        x = position;
        
        outfile << x << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}