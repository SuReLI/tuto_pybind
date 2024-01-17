#include "class_matrix.h"
#include "nanobind/nanobind.h"
#include <nanobind/stl/vector.h>

using namespace std;
namespace nb = nanobind;


NB_MODULE(c_matmultrace, m) {
    nb::class_<Matrix>(m, "Matrix")
        .def(nb::init<const std::vector<std::vector<int>>&>())
        .def(nb::init<>())
        .def("multiply", &Matrix::multiply)
        .def("trace", &Matrix::trace);
}