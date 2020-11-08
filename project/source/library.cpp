#include "library.h"
#include <iostream>
#include <omp.h>
#include <immintrin.h>
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

Matrix::Matrix(int row , int col,float * array) {
    this->col = col;
    this->matrix = array;
    this->row = row;
}

void Matrix::setMode(int semode) {
    this->mode = semode;
}
void Matrix::build(float *array) {
    this->matrix = array;
}
void Matrix::Intel(Matrix* right,Matrix* result) {

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
            Intel(&right,returnm);
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
            Super_quick(&right,returnm);
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
    float* b0,*r0,r;
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
                    b0 = &right->matrix[k*right->col+j];
                    r0 = &result->matrix[i*result->col+j];
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
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
    float* b0,*r0,r;
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
                if (rcol-j>=16){
                    b0 = &right->matrix[k*right->col+j];
                    r0 = &result->matrix[i*result->col+j];
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    j+=15;
                    continue;
                }
                else if (rcol-j>=8){
                    b0 = &right->matrix[k*right->col+j];
                    r0 = &result->matrix[i*result->col+j];
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    *r0 += (r * *b0++);
                    r0++;
                    j+=7;
                    continue;
                }
                result->matrix[i*result->col+j] += (r*right->matrix[k*right->col+j]);
            }
        }
    }
}

void Matrix::Super_quick(Matrix *right, Matrix *result) {
    float* b0;
    float *r0;
    float rt;
    int i,j,k;
    int lrow,rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    __m256 r,bt,c0 = _mm256_setzero_ps();
#pragma omp parallel for num_threads(ThreadNUM)
    for(i=0;i<lrow;++i){
        for(k = 0;k<rrow;++k){
            if(rrow-k>=8){
                r = _mm256_load_ps(&matrix[i*col+k]);
                b0 = &right->matrix[k*right->col];
                r0 = &result->matrix[i*result->col];
                for(j=0;j<rcol;++j){
                    if(rcol-j>=8){
                        c0 = _mm256_load_ps(r0+j);
                        bt = _mm256_load_ps(b0+j);
                        c0 =_mm256_add_ps(c0,_mm256_mul_ps(r,bt));
                        _mm256_store_ps(r0+j,c0);
                        j+=7;
                    } else{
                        result->matrix[i*result->col+j] += (matrix[i*col+k]*right->matrix[k*right->col+j]);
                    }
                }
                k+=7;
        }
            for(j=0;j<rcol;++j){
                if (rcol-j>=8){
                    b0 = &right->matrix[k*right->col+j];
                    r0 = &result->matrix[i*result->col+j];
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    r0++;
                    *r0 += (rt * *b0++);
                    j+=7;
                    continue;
                }
                result->matrix[i*result->col+j] += (rt*right->matrix[k*right->col+j]);
            }
        }
    }
}

