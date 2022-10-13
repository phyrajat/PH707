#include <random>
#include <array>
#include <cmath>
#include <fstream>

double state = 5.0;

double random(){
    state = fmod(state * 100019 + 10067, 101) * 1.0 / 101.0;
    return state;
}

//The sample size for plotting final distribution - this many numbers will be drawn
constexpr size_t samplesize = 100;

typedef std::array<double, samplesize> Smaples;

double characteristic_function(Smaples samples, double lambda){
    double sum = 0;
    for(auto& sample : samples){  //Loop through the array
        sum += exp(- sample * lambda);
    }
    sum /= samplesize;
    return sum;
}

int main()
{
    Smaples Z{}; //array to store the values, in case we need

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("./output/samples.txt", std::ios::out | std::ios::trunc);

    for(auto& Zi : Z){  //Loop through the array to store the values
        Zi = random();    //   calculate Y1 and store in the array
        outfile << Zi << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.

    outfile.open("./output/computed characteristic function.txt", std::ios::out | std::ios::trunc);

    double a = 0, b = 5, N = 10000;

    for (size_t i = 0; i < N; i++) {
        outfile << a + (b - a) / N * i << "\t" << characteristic_function(Z, a + (b - a) / N * i) << std::endl; //write to the output file
    }

    outfile.close();    //when done, close the file.
}