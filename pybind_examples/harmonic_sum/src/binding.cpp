#include "harmonic_sum.h"
#include "pybind11/pybind11.h"

using namespace std;
namespace py = pybind11;

PYBIND11_MODULE(c_harmonic, mod) {
    mod.def("c_harmonicsum", &fct_harmonic_sum, "Harmonic sum algorithm.");
}