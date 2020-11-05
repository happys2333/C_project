#include "library.h"
#include <iostream>

inline void Error(int type){

}
void Matrix::setMode(int mode) {
    this->mode = mode;
}
void Matrix::build(float *array) {
    this->matrix = array;
}
inline bool Matrix::cando(Matrix left, Matrix right) {
    return left.col == right.row;
}
Matrix Matrix::Strassen(Matrix left, Matrix right) {

}
float Matrix::N_dot(float *row, float *col, int rowlen, int collen) {

}
float Matrix::Q_dot(float *row, float *col, int rowlen, int collen) {

}
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
    matrix[col+row*this->col] = element;
}
void Matrix::GetCol(int col,float& colline){

}
void Matrix::Getrow(int row,float& rowline){

}
float Getelement(int col,int row){
    return
}
void Matrix::clear() {
    delete [] matrix;
    col = 0;
    row = 0;
    mode = 0;
}