#include "library.h"
#include <iostream>
#include <omp.h>
const int ThreadNUM = 16;
#pragma GCC optimize(3)
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
Matrix::Matrix(int row , int col,float * array) {
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
void Matrix::Strassen(Matrix* right,Matrix* result) {

}
void Matrix::N_do(Matrix* right, Matrix* result) {
    /*
     * ikj mode
     * */
    float r ;
    int i,j,k;
    int lrow,rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    for(i=0;i<lrow;++i){
        for(k = 0;k<rrow;++k){
            r = this->matrix[i*this->col+k];
            for(j=0;j<rcol;++j){
                result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
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

Matrix::Matrix(int row, int col) {
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
         printf("%-10f ",matrix[j+i*col]);
        }
        printf("\n");
    }
}
void Matrix::set(int row,int col,float element){
    matrix[(col-1)+(row-1)*this->col] = element;
}
void Matrix::clear() {
    delete [] matrix;
    col = 0;
    row = 0;
    mode = 0;
}

Matrix& Matrix::operator+(Matrix &right){
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return *new Matrix();
    } else{
        Matrix *m = new Matrix(this->row, this->col);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                 m->set(c+1,r+1,this->matrix[r*this->col+c]+right.matrix[r*right.col+c]);
            }
        }
        return *m;
    }
}
Matrix& Matrix::operator-(Matrix &right) {
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return *new Matrix();
    } else{
        Matrix *m= new Matrix(this->row, this->col);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                m->set(c+1,r+1,this->matrix[r*this->col+c]-right.matrix[r*right.col+c]);
            }
        }
        return *m;
    }
}
Matrix& Matrix::operator*(Matrix &right) {
    if (this->col != right.row){
        Error(1);
        return *new Matrix();
    }
    int mode = this->mode;

    Matrix *returnm= new Matrix(this->row,right.col);
    switch (mode) {
        case 0:
            N_do( &right,returnm);
            break;
        case 1:
            if((col!= row)|(right.col!=right.row)|(col!=right.col)|(isnum(col))){
                N_do(&right,returnm);
            }
            Strassen(&right,returnm);
            break;
        case 2:
            open_mp(&right,returnm);
            break;
        case 3:
            open_do(&right,returnm);
            break;
        case 4:
            Open_super(&right,returnm);
            break;
        case 5:
            break;

    }
    return *returnm;
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

void Matrix::open_do( Matrix *right, Matrix *result) {
    float r ;
    int i,j,k;
    int lrow,rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    #pragma omp parallel for num_threads(ThreadNUM)
    for(i=0;i<lrow;++i){
        for(k = 0;k<rrow;++k){
            r = this->matrix[i*this->col+k];
            for(j=0;j<rcol;++j){
                if (rcol-j>=8){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    j+=7;
                    continue;
                }
                result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
            }
        }
    }
}

void Matrix::open_mp( Matrix *right, Matrix *result) {
    float r ;
    int i,j,k;
    int lrow,rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    #pragma omp parallel for num_threads(ThreadNUM)
    for(i=0;i<lrow;++i){
        for(k = 0;k<rrow;++k){
            r = this->matrix[i*this->col+k];

            for(j=0;j<rcol;++j){
                result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
            }
        }
    }
}

void Matrix::Open_super( Matrix *right, Matrix *result) {
    float r ;
    int i,j,k;
    int lrow,rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    #pragma omp parallel for num_threads(ThreadNUM)
    for(i=0;i<lrow;++i){
        for(k = 0;k<rrow;++k){
            r = this->matrix[i*this->col+k];
            if(r==0){
                continue;
            }
            for(j=0;j<rcol;++j){
                if(rcol-j>=100){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    result->matrix[i*result->col+j+8] += (r*right->matrix[k*right->col+j+8]);
                    result->matrix[i*result->col+j+9] += (r*right->matrix[k*right->col+j+9]);
                    result->matrix[i*result->col+j+10] += (r*right->matrix[k*right->col+j+10]);
                    result->matrix[i*result->col+j+11] += (r*right->matrix[k*right->col+j+11]);
                    result->matrix[i*result->col+j+12] += (r*right->matrix[k*right->col+j+12]);
                    result->matrix[i*result->col+j+13] += (r*right->matrix[k*right->col+j+13]);
                    result->matrix[i*result->col+j+14] += (r*right->matrix[k*right->col+j+14]);
                    result->matrix[i*result->col+j+15] += (r*right->matrix[k*right->col+j+15]);
                    result->matrix[i*result->col+j+16] += (r*right->matrix[k*right->col+j+16]);
                    result->matrix[i*result->col+j+17] += (r*right->matrix[k*right->col+j+17]);
                    result->matrix[i*result->col+j+18] += (r*right->matrix[k*right->col+j+18]);
                    result->matrix[i*result->col+j+19] += (r*right->matrix[k*right->col+j+19]);
                    result->matrix[i*result->col+j+20] += (r*right->matrix[k*right->col+j+20]);
                    result->matrix[i*result->col+j+21] += (r*right->matrix[k*right->col+j+21]);
                    result->matrix[i*result->col+j+22] += (r*right->matrix[k*right->col+j+22]);
                    result->matrix[i*result->col+j+23] += (r*right->matrix[k*right->col+j+23]);
                    result->matrix[i*result->col+j+24] += (r*right->matrix[k*right->col+j+24]);
                    result->matrix[i*result->col+j+25] += (r*right->matrix[k*right->col+j+25]);
                    result->matrix[i*result->col+j+26] += (r*right->matrix[k*right->col+j+26]);
                    result->matrix[i*result->col+j+27] += (r*right->matrix[k*right->col+j+27]);
                    result->matrix[i*result->col+j+28] += (r*right->matrix[k*right->col+j+28]);
                    result->matrix[i*result->col+j+29] += (r*right->matrix[k*right->col+j+29]);
                    result->matrix[i*result->col+j+30] += (r*right->matrix[k*right->col+j+30]);
                    result->matrix[i*result->col+j+31] += (r*right->matrix[k*right->col+j+31]);
                    result->matrix[i*result->col+j+32] += (r*right->matrix[k*right->col+j+32]);
                    result->matrix[i*result->col+j+33] += (r*right->matrix[k*right->col+j+33]);
                    result->matrix[i*result->col+j+34] += (r*right->matrix[k*right->col+j+34]);
                    result->matrix[i*result->col+j+35] += (r*right->matrix[k*right->col+j+35]);
                    result->matrix[i*result->col+j+36] += (r*right->matrix[k*right->col+j+36]);
                    result->matrix[i*result->col+j+37] += (r*right->matrix[k*right->col+j+37]);
                    result->matrix[i*result->col+j+38] += (r*right->matrix[k*right->col+j+38]);
                    result->matrix[i*result->col+j+39] += (r*right->matrix[k*right->col+j+39]);
                    result->matrix[i*result->col+j+40] += (r*right->matrix[k*right->col+j+40]);
                    result->matrix[i*result->col+j+41] += (r*right->matrix[k*right->col+j+41]);
                    result->matrix[i*result->col+j+42] += (r*right->matrix[k*right->col+j+42]);
                    result->matrix[i*result->col+j+43] += (r*right->matrix[k*right->col+j+43]);
                    result->matrix[i*result->col+j+44] += (r*right->matrix[k*right->col+j+44]);
                    result->matrix[i*result->col+j+45] += (r*right->matrix[k*right->col+j+45]);
                    result->matrix[i*result->col+j+46] += (r*right->matrix[k*right->col+j+46]);
                    result->matrix[i*result->col+j+47] += (r*right->matrix[k*right->col+j+47]);
                    result->matrix[i*result->col+j+48] += (r*right->matrix[k*right->col+j+48]);
                    result->matrix[i*result->col+j+49] += (r*right->matrix[k*right->col+j+49]);
                    j+=50;
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    result->matrix[i*result->col+j+8] += (r*right->matrix[k*right->col+j+8]);
                    result->matrix[i*result->col+j+9] += (r*right->matrix[k*right->col+j+9]);
                    result->matrix[i*result->col+j+10] += (r*right->matrix[k*right->col+j+10]);
                    result->matrix[i*result->col+j+11] += (r*right->matrix[k*right->col+j+11]);
                    result->matrix[i*result->col+j+12] += (r*right->matrix[k*right->col+j+12]);
                    result->matrix[i*result->col+j+13] += (r*right->matrix[k*right->col+j+13]);
                    result->matrix[i*result->col+j+14] += (r*right->matrix[k*right->col+j+14]);
                    result->matrix[i*result->col+j+15] += (r*right->matrix[k*right->col+j+15]);
                    result->matrix[i*result->col+j+16] += (r*right->matrix[k*right->col+j+16]);
                    result->matrix[i*result->col+j+17] += (r*right->matrix[k*right->col+j+17]);
                    result->matrix[i*result->col+j+18] += (r*right->matrix[k*right->col+j+18]);
                    result->matrix[i*result->col+j+19] += (r*right->matrix[k*right->col+j+19]);
                    result->matrix[i*result->col+j+20] += (r*right->matrix[k*right->col+j+20]);
                    result->matrix[i*result->col+j+21] += (r*right->matrix[k*right->col+j+21]);
                    result->matrix[i*result->col+j+22] += (r*right->matrix[k*right->col+j+22]);
                    result->matrix[i*result->col+j+23] += (r*right->matrix[k*right->col+j+23]);
                    result->matrix[i*result->col+j+24] += (r*right->matrix[k*right->col+j+24]);
                    result->matrix[i*result->col+j+25] += (r*right->matrix[k*right->col+j+25]);
                    result->matrix[i*result->col+j+26] += (r*right->matrix[k*right->col+j+26]);
                    result->matrix[i*result->col+j+27] += (r*right->matrix[k*right->col+j+27]);
                    result->matrix[i*result->col+j+28] += (r*right->matrix[k*right->col+j+28]);
                    result->matrix[i*result->col+j+29] += (r*right->matrix[k*right->col+j+29]);
                    result->matrix[i*result->col+j+30] += (r*right->matrix[k*right->col+j+30]);
                    result->matrix[i*result->col+j+31] += (r*right->matrix[k*right->col+j+31]);
                    result->matrix[i*result->col+j+32] += (r*right->matrix[k*right->col+j+32]);
                    result->matrix[i*result->col+j+33] += (r*right->matrix[k*right->col+j+33]);
                    result->matrix[i*result->col+j+34] += (r*right->matrix[k*right->col+j+34]);
                    result->matrix[i*result->col+j+35] += (r*right->matrix[k*right->col+j+35]);
                    result->matrix[i*result->col+j+36] += (r*right->matrix[k*right->col+j+36]);
                    result->matrix[i*result->col+j+37] += (r*right->matrix[k*right->col+j+37]);
                    result->matrix[i*result->col+j+38] += (r*right->matrix[k*right->col+j+38]);
                    result->matrix[i*result->col+j+39] += (r*right->matrix[k*right->col+j+39]);
                    result->matrix[i*result->col+j+40] += (r*right->matrix[k*right->col+j+40]);
                    result->matrix[i*result->col+j+41] += (r*right->matrix[k*right->col+j+41]);
                    result->matrix[i*result->col+j+42] += (r*right->matrix[k*right->col+j+42]);
                    result->matrix[i*result->col+j+43] += (r*right->matrix[k*right->col+j+43]);
                    result->matrix[i*result->col+j+44] += (r*right->matrix[k*right->col+j+44]);
                    result->matrix[i*result->col+j+45] += (r*right->matrix[k*right->col+j+45]);
                    result->matrix[i*result->col+j+46] += (r*right->matrix[k*right->col+j+46]);
                    result->matrix[i*result->col+j+47] += (r*right->matrix[k*right->col+j+47]);
                    result->matrix[i*result->col+j+48] += (r*right->matrix[k*right->col+j+48]);
                    result->matrix[i*result->col+j+49] += (r*right->matrix[k*right->col+j+49]);
                    j+=49;
                    continue;
                }
                else if (rcol-j>=50){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    result->matrix[i*result->col+j+8] += (r*right->matrix[k*right->col+j+8]);
                    result->matrix[i*result->col+j+9] += (r*right->matrix[k*right->col+j+9]);
                    result->matrix[i*result->col+j+10] += (r*right->matrix[k*right->col+j+10]);
                    result->matrix[i*result->col+j+11] += (r*right->matrix[k*right->col+j+11]);
                    result->matrix[i*result->col+j+12] += (r*right->matrix[k*right->col+j+12]);
                    result->matrix[i*result->col+j+13] += (r*right->matrix[k*right->col+j+13]);
                    result->matrix[i*result->col+j+14] += (r*right->matrix[k*right->col+j+14]);
                    result->matrix[i*result->col+j+15] += (r*right->matrix[k*right->col+j+15]);
                    result->matrix[i*result->col+j+16] += (r*right->matrix[k*right->col+j+16]);
                    result->matrix[i*result->col+j+17] += (r*right->matrix[k*right->col+j+17]);
                    result->matrix[i*result->col+j+18] += (r*right->matrix[k*right->col+j+18]);
                    result->matrix[i*result->col+j+19] += (r*right->matrix[k*right->col+j+19]);
                    result->matrix[i*result->col+j+20] += (r*right->matrix[k*right->col+j+20]);
                    result->matrix[i*result->col+j+21] += (r*right->matrix[k*right->col+j+21]);
                    result->matrix[i*result->col+j+22] += (r*right->matrix[k*right->col+j+22]);
                    result->matrix[i*result->col+j+23] += (r*right->matrix[k*right->col+j+23]);
                    result->matrix[i*result->col+j+24] += (r*right->matrix[k*right->col+j+24]);
                    result->matrix[i*result->col+j+25] += (r*right->matrix[k*right->col+j+25]);
                    result->matrix[i*result->col+j+26] += (r*right->matrix[k*right->col+j+26]);
                    result->matrix[i*result->col+j+27] += (r*right->matrix[k*right->col+j+27]);
                    result->matrix[i*result->col+j+28] += (r*right->matrix[k*right->col+j+28]);
                    result->matrix[i*result->col+j+29] += (r*right->matrix[k*right->col+j+29]);
                    result->matrix[i*result->col+j+30] += (r*right->matrix[k*right->col+j+30]);
                    result->matrix[i*result->col+j+31] += (r*right->matrix[k*right->col+j+31]);
                    result->matrix[i*result->col+j+32] += (r*right->matrix[k*right->col+j+32]);
                    result->matrix[i*result->col+j+33] += (r*right->matrix[k*right->col+j+33]);
                    result->matrix[i*result->col+j+34] += (r*right->matrix[k*right->col+j+34]);
                    result->matrix[i*result->col+j+35] += (r*right->matrix[k*right->col+j+35]);
                    result->matrix[i*result->col+j+36] += (r*right->matrix[k*right->col+j+36]);
                    result->matrix[i*result->col+j+37] += (r*right->matrix[k*right->col+j+37]);
                    result->matrix[i*result->col+j+38] += (r*right->matrix[k*right->col+j+38]);
                    result->matrix[i*result->col+j+39] += (r*right->matrix[k*right->col+j+39]);
                    result->matrix[i*result->col+j+40] += (r*right->matrix[k*right->col+j+40]);
                    result->matrix[i*result->col+j+41] += (r*right->matrix[k*right->col+j+41]);
                    result->matrix[i*result->col+j+42] += (r*right->matrix[k*right->col+j+42]);
                    result->matrix[i*result->col+j+43] += (r*right->matrix[k*right->col+j+43]);
                    result->matrix[i*result->col+j+44] += (r*right->matrix[k*right->col+j+44]);
                    result->matrix[i*result->col+j+45] += (r*right->matrix[k*right->col+j+45]);
                    result->matrix[i*result->col+j+46] += (r*right->matrix[k*right->col+j+46]);
                    result->matrix[i*result->col+j+47] += (r*right->matrix[k*right->col+j+47]);
                    result->matrix[i*result->col+j+48] += (r*right->matrix[k*right->col+j+48]);
                    result->matrix[i*result->col+j+49] += (r*right->matrix[k*right->col+j+49]);
                    j+=49;
                    continue;
                }
                else if (rcol-j>=32){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    result->matrix[i*result->col+j+8] += (r*right->matrix[k*right->col+j+8]);
                    result->matrix[i*result->col+j+9] += (r*right->matrix[k*right->col+j+9]);
                    result->matrix[i*result->col+j+10] += (r*right->matrix[k*right->col+j+10]);
                    result->matrix[i*result->col+j+11] += (r*right->matrix[k*right->col+j+11]);
                    result->matrix[i*result->col+j+12] += (r*right->matrix[k*right->col+j+12]);
                    result->matrix[i*result->col+j+13] += (r*right->matrix[k*right->col+j+13]);
                    result->matrix[i*result->col+j+14] += (r*right->matrix[k*right->col+j+14]);
                    result->matrix[i*result->col+j+15] += (r*right->matrix[k*right->col+j+15]);
                    result->matrix[i*result->col+j+16] += (r*right->matrix[k*right->col+j+16]);
                    result->matrix[i*result->col+j+17] += (r*right->matrix[k*right->col+j+17]);
                    result->matrix[i*result->col+j+18] += (r*right->matrix[k*right->col+j+18]);
                    result->matrix[i*result->col+j+19] += (r*right->matrix[k*right->col+j+19]);
                    result->matrix[i*result->col+j+20] += (r*right->matrix[k*right->col+j+20]);
                    result->matrix[i*result->col+j+21] += (r*right->matrix[k*right->col+j+21]);
                    result->matrix[i*result->col+j+22] += (r*right->matrix[k*right->col+j+22]);
                    result->matrix[i*result->col+j+23] += (r*right->matrix[k*right->col+j+23]);
                    result->matrix[i*result->col+j+24] += (r*right->matrix[k*right->col+j+24]);
                    result->matrix[i*result->col+j+25] += (r*right->matrix[k*right->col+j+25]);
                    result->matrix[i*result->col+j+26] += (r*right->matrix[k*right->col+j+26]);
                    result->matrix[i*result->col+j+27] += (r*right->matrix[k*right->col+j+27]);
                    result->matrix[i*result->col+j+28] += (r*right->matrix[k*right->col+j+28]);
                    result->matrix[i*result->col+j+29] += (r*right->matrix[k*right->col+j+29]);
                    result->matrix[i*result->col+j+30] += (r*right->matrix[k*right->col+j+30]);
                    result->matrix[i*result->col+j+31] += (r*right->matrix[k*right->col+j+31]);
                    j+=31;
                    continue;
                } else if(rcol-j>=10){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    result->matrix[i*result->col+j+8] += (r*right->matrix[k*right->col+j+8]);
                    result->matrix[i*result->col+j+9] += (r*right->matrix[k*right->col+j+9]);
                    j+=9;
                    continue;
                }
                else if (rcol-j>=8){
                    result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
                    result->matrix[i*result->col+j+1] += (r*right->matrix[k*right->col+j+1]);
                    result->matrix[i*result->col+j+2] += (r*right->matrix[k*right->col+j+2]);
                    result->matrix[i*result->col+j+3] += (r*right->matrix[k*right->col+j+3]);
                    result->matrix[i*result->col+j+4] += (r*right->matrix[k*right->col+j+4]);
                    result->matrix[i*result->col+j+5] += (r*right->matrix[k*right->col+j+5]);
                    result->matrix[i*result->col+j+6] += (r*right->matrix[k*right->col+j+6]);
                    result->matrix[i*result->col+j+7] += (r*right->matrix[k*right->col+j+7]);
                    j+=7;
                    continue;
                }
                result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
            }
        }
    }
}
const int secondnum[30]={
        2,4
        ,8
        ,16
        ,32
        ,64
        ,128
        ,256
        ,512
        ,1024
        ,2048
        ,4096
        ,8192
        ,16384
        ,32768
        ,65536
        ,131072
        ,262144
        ,524288
        ,1048576
        ,2097152
        ,4194304
        ,8388608
        ,16777216
        ,33554432
        ,67108864
        ,134217728
        ,268435456
        ,536870912
        ,1073741824
};
bool Matrix::isnum(int num) {
    if(num==1){return true;}
    for(int i=0;i<30;i++){
        if(num == secondnum[i]){
            return true;
        }
    }
    return false;
}


