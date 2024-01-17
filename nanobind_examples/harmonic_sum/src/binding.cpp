#include "harmonic_sum.h"
#include "nanobind/nanobind.h"
using namespace std;
namespace nb = nanobind;

NB_MODULE(c_harmonic, mod) {
    mod.def("c_harmonicsum", &fct_harmonic_sum, "Harmonic sum algorithm.");
}