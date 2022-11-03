#include <pybind11/embed.h> // everything needed for embedding

#include <iostream>
#include <fstream>
#include <array>
#include <map>

namespace py = pybind11;

constexpr size_t STEPS = 1000;  //number of steps

typedef std::map<double, double> solution;   //data type definition for storing the list of calculated values ((hash)map of time -> state)


int main() {
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    py::module_ calc = py::module_::import("diff_eqn");

    solution x_t;   //variable to store the calculations

    double t_0 = 0.0;   //initial time
    double t_1 = 1.0;   //final time
    double dt = (t_1 - t_0) / (STEPS - 1); //step size
    double x = 1.0;   //initial values for dependant variables

    //Step through the domain of the problem and store the solutions
    x_t[t_0] = x;   //store initial values
    for (size_t i = 1; i < STEPS; i++) {
        py::object result = calc.attr("dxdt")(x);
         x += result.cast<double>() * dt;  //store the calculation
         x_t[t_0 + i * dt] = x;
    }

    std::ofstream outfile;  //file handle to save the results in a file
    outfile.open("output.txt", std::ios::out | std::ios::trunc);
    for (auto const& temp : x_t) {
        outfile << temp.first << "\t" << temp.second << std::endl;
    }
    outfile.close();
}