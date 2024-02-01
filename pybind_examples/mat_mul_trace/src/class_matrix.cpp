#include <iostream>
#include <vector>
using namespace std;
#include "class_matrix.h"

Matrix::Matrix(const std::vector<std::vector<int>>& input) : data(input) {}

Matrix::Matrix() {}

Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(std::vector<std::vector<int>>(data.size(), std::vector<int>(other.data[0].size(), 0)));

    #pragma omp parallel for
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < other.data[0].size(); ++j) {
            for (size_t k = 0; k < other.data.size(); ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

double Matrix::trace() const {
    double result = 0;
    
    for (size_t i = 0; i < data.size(); ++i) {
        result += data[i][i];
    }
    return result;
}


int main() {
    int n = 750;
    int m = 750;
    int l = 750;
    Matrix matrix1 (std::vector<std::vector<int>>(m, std::vector<int>(n, 10)));
    Matrix matrix2 (std::vector<std::vector<int>>(l, std::vector<int>(m, 10)));
    
    Matrix result = matrix1.multiply(matrix2);
    cout<<"Trace :"<< result.trace()<<endl;

    return 0;
}
