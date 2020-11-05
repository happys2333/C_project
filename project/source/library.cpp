#include "library.h"

#include <iostream>

Matrix::Matrix(int col, int row) {
    this->col = col;
    this->row =row;
    int len = col*row;

    matrix = new float [len];
    for(int i=0;i<len;i++){
        matrix[i] =0;
    }
}
Matrix::Matrix() {
    row = 0;
    col = 0;
}
Matrix::~Matrix() {
    delete [] matrix;
}
void Matrix::print() {
    for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
         printf("%f ",matrix[j+i*col]);
        }
        printf("\n");
    }
}
void Matrix::set(int col,int row,float element){
    matrix
}
int GetCol();
int Getrow();
float Getelement(int col,int row);