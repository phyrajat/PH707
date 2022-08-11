#include <iostream>
#include <fstream>
#include <vector>

//constant expressions appearing in the code
constexpr double PI = 3.14159265;   //pi
constexpr double rollnum = 2.26121014;  //my roll number

typedef double state_type;  //data type definition for dependant variable, just a double here - should be std::vector<> for multidimensional case
typedef std::vector<double> solution;   //data type definition for storing the solutions

//This is the differential Equation
void System(state_type& x, state_type& d2xdt2){
    d2xdt2 = - 4.0 * PI * PI * x;
}

//This sets the initial values x_0 and x_1 given the values of x(0) and x'(0) and step size
void initsolver(solution& x_values, const state_type& x0, const state_type& dx0dt, const double dt){
    x_values.push_back(x0); //store x(0)
    x_values.push_back(x0 + dx0dt * dt);    //store x_1 = x(0) + x'(0) * dt
}

//The stepper function, calculates x_{n+1} given the differential equation, list of past values and step size
void finite_diff_step(void (*System)(state_type& x, state_type& d2xdt2), solution& x_values, const double dt){
    state_type result = 0;  //temporary variable for storing x_{n+1}
    System(x_values[x_values.size()-1], result);    //calculate x''_{n}
    result *= dt * dt;  //multiply by step_size^2
    result += 2 * x_values[x_values.size()-1] - x_values[x_values.size()-2];    //add 2 * x_{n} - x_{n-1}. The final expression becomes x_{n+1} = x''_{n} * step_size^2 + 2 * x_{n} - x_{n-1} which is obtained from the expression drawn on whiteboard.
    x_values.push_back(result); //store x_{n+1} in the list of solutions
}


int main(){
    solution x_values;  //variable for storing the solutions
    int STEPS = 1000;   //define number of steps
    double dt = 1.0/STEPS;  //define stepsize
    initsolver(x_values, 0, rollnum, dt);   //initilize the list of solutions with x_{0} and x_{1}
    for (size_t i = 0; i < STEPS - 1; i++) { //step through the total number of steps and store the results
        finite_diff_step(System, x_values, dt);
    }

    std::ofstream outfile;  //save the results in a file named "solution for 1000 steps.txt"
    outfile.open("solution for 1000 steps.txt", std::ios::out | std::ios::trunc );
    for (size_t i = 0; i < x_values.size(); i++) {
        outfile << 0 + i * dt << "\t" << x_values[i] << "\n";
    }
    outfile.close();
}