#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <map>

//Constant expressions appearing in the problem
constexpr size_t dim = 2;   //dimension of the reduced 1st-order problem
constexpr double PI = 3.14159265359;    //value of PI
constexpr double rollnum = 0.226121014;  //my roll number

//Definition of data types in the problem
typedef std::array<double, dim> state_type;  //data type definition for dependant variables - array of x_0, x_1, ... x_n
typedef std::map<double, state_type> solution;   //data type definition for storing the list of calculated values ((hash)map of time -> state)

//This is the differential Equation, reduced to first-order
void Pendulum(const state_type& x, state_type& dxdt){
    dxdt[0] = x[1];
    dxdt[1] = -4.0 * PI * PI * sin(x[0]);
}

//The stepper function, calculates x_{n+1} given the differential equation, x_{n} and step size
void euler_step_forward(void (*Diff_Equation)(const state_type& x, state_type& dxdt), state_type& x, const double dt){
    state_type dxdt;    //temporary variable for storing dx/dt
    Diff_Equation(x, dxdt); //calculate dxdt from the differential equation
    for (size_t i = 0; i < dim; i++) {
        x[i] = x[i] + dxdt[i] * dt; //Euler forward difference formula
    }
}

int main(){
    solution x_t;   //variable to store the calculations

    size_t STEPS = 1000;  //number of steps
    double t_0 = 0.0;   //initial time
    double t_1 = 1.0;   //final time
    double dt = (t_1 - t_0) / (STEPS - 1); //step size
    state_type x = {0.0, rollnum};   //initial values for dependant variables

    //Step through the domain of the problem and store the solutions
    x_t[t_0] = x;   //store initial values
    for (size_t i = 0; i < STEPS; i++) {
        euler_step_forward(Pendulum, x, dt);    //step forward
        x_t[t_0 + i * dt] = x;  //store the calculation
    }

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("data for plotting.txt", std::ios::out | std::ios::trunc );
    for (auto const& temp : x_t){
        outfile << temp.first << "\t" << temp.second[0] << "\t" << temp.second[1] << std::endl;
    }
    outfile.close();
}