#include <iostream>
#include <fstream>
#include <vector>
#include <complex>

//Types used in the problem
typedef std::vector<std::complex<double>> Complexlist;

//Constant expressions appearing in the problem
constexpr double pi = 3.14159265359;
constexpr std::complex<double> i(0, 1);

//This is the function to be taken DFT of
std::complex<double> function(double t) {
	if(t <= 8)
		return exp(2.0 * pi * i * t - t);
	else
		return (std::complex<double>) 0;
}

//Helper function to discretize the given function
Complexlist discretizer(std::complex<double>(*function)(double t), double starting_point, double ending_point, size_t STEPS) {
	Complexlist result(STEPS);
	for (size_t i = 0; i < STEPS; i++) {
		result[i] = function(starting_point + i * (ending_point - starting_point) / (STEPS - 1));
	}

	return result;
}

//FFT algorithm
Complexlist FFT(Complexlist P) {
	size_t n = P.size();

	if (n == 1) {
		return P;
	}

	//n roots of unity
	std::complex<double> w = std::exp(-2.0 * pi * i / (double)n);

	Complexlist Pe, Po;

	//Divide into odd and even polynomials
	for (size_t j = 0; j < n / 2; j++) {
		Pe.push_back(P[2 * j]);
		Po.push_back(P[2 * j + 1]);
	}

	//invoke recursion
	Complexlist ye = FFT(Pe), yo = FFT(Po), y(n);

	//tie up everything to complete
	for (size_t j = 0; j < n / 2; j++) {
		y[j] = ye[j] + pow(w, j) * yo[j];
		y[j + n / 2] = ye[j] - pow(w, j) * yo[j];
	}

	return y;
}

int main() {
	//Discretize given function in 2048 steps
	Complexlist coefficients = discretizer(function, 0, 10, 2048);

	//Calculate the FFT
	Complexlist values = FFT(coefficients);

	std::ofstream outfile;  //file handle to save the results in a file
	outfile.open("./output/FFT.txt", std::ios::out | std::ios::trunc);

	for (auto& value : values) {  //Loop through the array to store the values
		outfile << value.real() << "\t" << value.imag() << std::endl; //write to the output file
	}
	outfile.close();    //when done, close the file.

	return 0;
}