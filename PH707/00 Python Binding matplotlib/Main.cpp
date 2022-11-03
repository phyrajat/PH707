#include <pybind11/embed.h>

#include <iostream>

namespace py = pybind11;

int main()
{
	py::scoped_interpreter guard{};
	py::module sys = py::module::import("sys");
	py::print(sys.attr("path"));


	try {
		auto np = py::module::import("numpy");
	}
	catch (std::exception e) {
		std::cout << "[Numpy] " << e.what();
	}
	
	return 0;
}