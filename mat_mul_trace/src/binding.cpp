#include "class_matrix.h"
#include "pybind11/pybind11.h"
#include <pybind11/stl.h> // Allows to Pybind11 to work with C++ STL such as std::vector

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(c_matmultrace, m) {
    py::class_<Matrix>(m, "Matrix")
        .def(py::init<const std::vector<std::vector<int>>&>())
        .def(py::init<>())
        .def("multiply", &Matrix::multiply)
        .def("trace", &Matrix::trace);
}