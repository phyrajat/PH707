#include <iostream>
#include <fstream>
#include <map>
#include "Eigen/Core"   //Very popular modern C++ library for linear algebra, used here for matrix multiplication and inversion
#include "Eigen/Dense"

//Constant expressions appearing in the problem
constexpr size_t dimension = 2;   //dimension of the reduced 1st-order problem
constexpr double PI = 3.14159265359;    //value of PI
constexpr double rollnum = 0.226121014;  //my roll number

//Definition of data types in the problem
typedef Eigen::Matrix<double, dimension, 1> state_type;  //data type definition for dependant variables - coloumn matrix of x_0, x_1, ... x_n
typedef std::map<double, state_type> solution;   //data type definition for storing the list of calculated values ((hash)map of time -> state)
typedef Eigen::Matrix<double, dimension, dimension> matrix; //data type definition for Jacobean matrix

//This is the differential Equation, reduced to first-order
void Pendulum(const state_type& x, state_type& dxdt){
    dxdt[0] = x[1];
    dxdt[1] = -4.0 * PI * PI * sin(x[0]);
}

//This is the Jacobean for the Multidimensional Newton
void PendulumJacobian(const state_type& x, matrix& Jx, const double& dt){
    Jx << -1.0/dt, 1.0,
        -4.0 * PI * PI * cos(x[0]), -1.0/dt;
}

//The stepper function, iteratively solves the implicit equation for x_{n+1} given the differential equation, Jacobean, x_{n} and step size
void implicit_Euler_step(void (*Diff_Equation)(const state_type& x, state_type& dxdt), void (*Jacobian)(const state_type& x, matrix& jacobean, const double& dt), state_type& x, const double& dt){
    state_type x_n = x; //store x seperately for Newton iteration
    state_type dxdt;    //variable for the derivative
    Diff_Equation(x, dxdt); //calculate the derivative according to the differential equations
    x_n = x_n + dt * dxdt;   //initial guess for Newton's method according to forward euler
    matrix Jx;  //variable for storing the Jacobean
    for (size_t i = 0; i < 10; i++) {
        Diff_Equation(x_n, dxdt);   //calculate the derivative at x_n
        Jacobian(x_n, Jx, dt);  //calculate the Jacobean at x_n
        x_n = x_n - Jx.inverse() * (dxdt - (x_n - x) / dt); //Newton iterations
    }
    x = x_n;    //replace x with the calculated solution when done
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
        implicit_Euler_step(Pendulum, PendulumJacobian, x, dt);    //step forward
        x_t[t_0 + i * dt] = x;  //store the calculation
    }

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("implicit.txt", std::ios::out | std::ios::trunc );
    for (auto const& temp : x_t){
        outfile << temp.first << "\t" << temp.second[0] << "\t" << temp.second[1] << std::endl;
    }
    outfile.close();
}