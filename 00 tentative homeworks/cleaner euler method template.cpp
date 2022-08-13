#include <iostream>
#include <fstream>
#include <array>
#include <vector>

constexpr size_t dim = 2;   //dimension of the reduced 1st-order problem

typedef std::array<double, dim> state_type;  //data type definition for dependant variables
typedef std::vector<state_type> solution;   //data type definition for storing the list of calculated values

//This is the differential Equation, reduced to first-order
void System(const state_type& x, state_type& dxdt){
    //fill in...
}

//The stepper function, calculates x_{n+1} given the differential equation, x_{n} and step size
void finite_diff_step(void (*System)(state_type& x, state_type& dxdt), solution& x_values, const double dt){
    //fill in...
}


int main(){
    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("data for plotting.txt", std::ios::out | std::ios::trunc );
    
    outfile.close();
}