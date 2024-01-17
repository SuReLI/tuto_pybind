#include <iostream>
using namespace std;
#include <cmath>
#include "harmonic_sum.h"

double fct_harmonic_sum(int power, double harmonic){
    for(double i=1; i<=pow(10,power); i++) 
        harmonic += 1.0/i;
    return harmonic;
}
/* Segmentation fault car la variable est détruite car définit dans le bloc dans la fonction */



