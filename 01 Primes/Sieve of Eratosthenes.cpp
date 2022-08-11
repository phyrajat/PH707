#include <memory>
#include <iostream>

size_t SieveOfEratosthenes(size_t n){
    size_t upperbound = n * n;
    auto tags = std::make_unique<bool[]>(upperbound);
    for (size_t i = 2; i * i < upperbound; i++) {
        if(!tags[i]){
            for(size_t multiplier = i; i * multiplier < upperbound; multiplier++){
                tags[i * multiplier] = true;
            }
        }
    }

    size_t count = 0;

    for(size_t i = 2; i < upperbound; i++){
        if(!tags[i]){
            count++;
            if(count == n)
                return i;
        }
    }
}


int main(){
    int n = 100;
    for(int i = 5; i <= n; i++)
        std::cout << "The " << i << "-th prime is " << SieveOfEratosthenes(i) << std::endl;

    return 0;
}