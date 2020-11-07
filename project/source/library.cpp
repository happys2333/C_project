#include "library.h"
#include <iostream>
#include "omp.h"
#define ThreadNum 4;
inline void Error(int type){
    printf("Error code : %d ",type);
    switch (type) {
        case 1:
            printf("You can't multiply these two matrices!\n");
            break;
        case 2:
            printf("you can't add those two matrices!\n");
            break;
        case 3:
            printf("you can't minus those two matrices!\n");
            break;
        case -2:
            printf("wrong mode number please check your code, this time will use mode 0 to do!\n");
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
    float A11[N][N],A12[N][N],A21[N][N],A22[N][N];
    float B11[N][N],B12[N][N],B21[N][N],B22[N][N];
    float C11[N][N],C12[N][N],C21[N][N],C22[N][N];
    float M1[N][N],M2[N][N],M3[N][N],M4[N][N],M5[N][N],M6[N][N],M7[N][N];
    float AA[N][N],BB[N][N];
    if(N==2){

    }
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
void Matrix::Strassen(Matrix* left,Matrix* right,Matrix* result) {

}
void Matrix::N_do(Matrix* left, Matrix* right, Matrix* result) {
    /*
     * ikj mode
     * */
    float r ;
    int i,j,k;
    for(i=0;i<left->row;i++){
        for(k = 0;k<right->row;k++){
            r = left->matrix[i*left->col+k];
            for(j=0;j<right->col;j++){
                result->matrix[i*right->col+j] = r*right->matrix[k*right->col+j];
            }
        }
    }
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
         printf("%-20f ",matrix[j+i*col]);
        }
        printf("\n");
    }
}
void Matrix::set(int col,int row,float element){
    matrix[(col-1)+(row-1)*this->col] = element;
}
void Matrix::clear() {
    delete [] matrix;
    col = 0;
    row = 0;
    mode = 0;
}

Matrix Matrix::operator+(Matrix &right) const {
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return *new Matrix();
    } else{
        Matrix m(this->col, this->row);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                 m.set(c+1,r+1,this->matrix[r*this->col+c]+right.matrix[r*right.col+c]);
            }
        }
        return m;
    }
}
Matrix Matrix::operator-(Matrix &right) {
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return *new Matrix();
    } else{
        Matrix m(this->col, this->row);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                m.set(c+1,r+1,this->matrix[r*this->col+c]-right.matrix[r*right.col+c]);
            }
        }
        return m;
    }
}
Matrix Matrix::operator*(Matrix &right) {
    if (cando(*this,right)){
        Error(1);
        return *new Matrix();
    }
    Matrix returnm(this->col,right.row);
    switch (mode) {
        case 0:
            N_do(this, &right, &returnm);
            return returnm;
        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

        default:
            Error(-2);
            N_do(this, &right, &returnm);
            return returnm;
    }
}
inline float Matrix::Getelement(int col, int row) {
    return matrix[(col-1)+(row-1)*this->col];
}

float* Matrix::operator[](int i) {
    auto *re = new float [this->col];
    for(int j=0;j<this->col;j++){
        re[j] = matrix[(i-1)*this->col+j];
    }
    return re;
}

void Matrix::open_do(Matrix *left, Matrix *right, Matrix *result) {

}

void Matrix::open_mp(Matrix *left, Matrix *right, Matrix *result) {
    #pragma omp parallel for num_threadsss(ThreadNum)
    float r ;
    int i,j,k;
    for(i=0;i<left->row;i++){
        for(k = 0;k<right->row;k++){
            r = left->matrix[i*left->col+k];
            for(j=0;j<right->col;j++){
                result->matrix[i*right->col+j] = r*right->matrix[k*right->col+j];
            }
        }
    }
}

void Matrix::Open_super(Matrix *left, Matrix *right, Matrix *result) {
    #pragma omp parallel for num_threadsss(ThreadNum)





}


