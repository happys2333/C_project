#include "library.h"
#include <iostream>
inline void Error(int type){
    printf("Error code : %d ",type);
    switch (type) {
        case 1:
            printf("You can't multiply these two matrices!\n");
            break;
        case 2:
            printf("you can't add those two matrices!\n");
            break;
        default:
            printf("unknown error!\n");
    }
}
void Matrix::add(const float *left, const float *right, float* result, int N) {
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            result[i*N+j] = left[i*N+j]+right[i*N+j];
        }
    }
}
Matrix::Matrix(int col , int row,float * array) {
    this->col = col;
    this->matrix = array;
    this->row = row;
}
void Matrix::Sub(const float *left, const float *right, float *result, int N) {
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            result[i*N+j] = left[i*N+j]-right[i*N+j];
        }
    }
}
void Matrix::do_Strassen(float *left, float *right, int N, float *result) {

}
void Matrix::setMode(int semode) {
    this->mode = semode;
}
void Matrix::build(float *array) {
    this->matrix = array;
}
inline bool Matrix::cando(const Matrix& left, const Matrix& right) {
    return left.col == right.row;
}
void Matrix::Strassen(Matrix left,Matrix right,Matrix result) {

}
float Matrix::N_dot(float *row, float *col, int rowlen, int collen) {

}
void Matrix::Q_do(Matrix left, Matrix right, Matrix result) {

}
Matrix& Matrix::operator=(float *array) {
    if(col==0||row==0){
        printf("please set the col and row number before you want to do something! ");
        return *new Matrix();
    } else{
        this->matrix = array;
        return *this;
    }
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
    matrix[(col-1)+(row-1)*this->col] = element;
}
void Matrix::GetCol(int col,float& colline){
    float *re = new float [row];
    for(int i=0;i<row;i++){

    }
}
void Matrix::Getrow(int row,float& rowline){

}
void Matrix::clear() {
    delete [] matrix;
    col = 0;
    row = 0;
    mode = 0;
}

Matrix &Matrix::operator+(Matrix &right) {

}

Matrix &Matrix::operator*(Matrix &right) {

}
float Matrix::Getelement(int col, int row) {
    return matrix[(col-1)+(row-1)*this->col];
}
