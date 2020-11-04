#include "library.h"

#include <iostream>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}
Matrix::Matrix(int col, int row) {
    this->col = col;
    this->row =row;
    matrix = new float*[row];
    for(int i=0;i<row;i++){
        matrix[i] = new float [col];
    }
}
Matrix::~Matrix() {
    for (int i=0;i<row;i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}
void Matrix::print() {
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
         printf("%f",matrix[i][j]);
        }
    }
}
float Matrix::N_dot(float *r1, float *r2) {

}