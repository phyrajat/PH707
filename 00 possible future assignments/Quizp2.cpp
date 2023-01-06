#include <iostream>
#include <random>

constexpr size_t N = 1000000;
constexpr double d = .01;

int main(){
    std::random_device dev;
    std::mt19937 x(dev()), y(dev()), z(dev());
    std::uniform_real_distribution<double> dist(0,1);

    size_t n = 0;

    for (size_t i = 0; i < N; i++){
        double xi = dist(x), yi = dist(y), zi = dist(z);
        double r = xi * xi + yi * yi + zi * zi;
        if(r < 1 && r > (1 - d) * (1 - d)){
            n++;
        }
    }

    double a = (double) n /(double) N;

    std::cout << "The area is " << 8.0 * a / d + 12.0 * a + 6.0 * a * d + a * d * d << std::endl;
    
}