#ifndef CLASS_MATRIX_H
#define CLASS_MATRIX_H
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    // Parameter
    std::vector<std::vector<int>> data;
    
    Matrix(const std::vector<std::vector<int>>& input);

    Matrix();/* Constuctor*/

    // Functions
    Matrix multiply(const Matrix& other) const;
    double trace() const;

};
#endif 