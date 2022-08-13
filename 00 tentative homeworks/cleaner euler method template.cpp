#include <iostream>
#include <fstream>
#include <array>
#include <vector>

constexpr size_t dim = 2;   //dimension of the reduced 1st-order problem

typedef std::array<double, dim> state_type;  //data type definition for dependant variables - array of x_0, x_1, ... x_n
typedef std::vector<state_type> solution;   //data type definition for storing the list of calculated values

//This is the differential Equation, reduced to first-order
void Pendulum(const state_type& x, state_type& dxdt){
    dxdt[0] = x[1];
    dxdt[1] = -sin(x[0]);
}

//The stepper function, calculates x_{n+1} given the differential equation, x_{n} and step size
void euler_step(void (*System)(const state_type& x, state_type& dxdt), state_type& x, const double dt){
    state_type dxdt;    //
    System(x, dxdt);
    for (size_t i = 0; i < dim; i++) {
        x[i] = x[i] + dxdt[i] * dt;
    }
}


int main(){
    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("data for plotting.txt", std::ios::out | std::ios::trunc );
    
    state_type x = {0, 0.01};
    for (size_t i = 0; i < 1000; i++) {
        euler_step(Pendulum, x, 0.01);
        outfile << x[0] << "\t" << x[1] << "\n";
    }
    
    outfile.close();
}