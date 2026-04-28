#include "library.h"
#include <iostream>
#include <omp.h>
#include <arm_neon.h>
#include <time.h>
#include <string.h>
using namespace std;
#define A(i,j) a[ (j)*lda + (i) ]
#define B(i,j) b[ (j)*ldb + (i) ]
#define C(i,j) c[ (j)*ldc + (i) ]
const int ThreadNUM = 16;
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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
        case -1:
            printf("Not support, this time will use mode 0 to do!\n");
            break;
        case 0:
            printf("Empty matrix\n");
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
    if(usethis==0){usethis++;}
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
    if(usethis==0){usethis++;}
    if(col==0||row==0){
        printf("please set the col and row number before you want to do something! ");
        return *this;
    } else{
        this->matrix = array;
        return *this;
    }
}

Matrix::Matrix(int row, int col,float num) {
    this->col = col;
    this->row =row;
    size_t len = (size_t)col*row;
    matrix = new float [len];
    for(size_t i=0;i<len;i++){
        matrix[i] =num;
    }
}
Matrix::Matrix(const Matrix& other) : row(other.row), col(other.col), mode(other.mode), usethis(1) {
    size_t len = (size_t)row * col;
    matrix = new float[len];
    memcpy(matrix, other.matrix, len * sizeof(float));
}
Matrix::Matrix() {
    row = 0;
    col = 0;
    usethis = 0;
}
Matrix::~Matrix() {
    if (usethis == 0){
        return;
    }
    if(usethis==1){
        delete [] matrix;
    }else{
        usethis--;
    }
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
    if(usethis==1){
        delete [] matrix;
        matrix = nullptr;
    }else{
        usethis--;
    }
    col = 0;
    row = 0;
    mode = 0;
}

Matrix Matrix::operator+(const Matrix &right) const {
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return Matrix();
    } else{
        Matrix m(this->row, this->col);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                m.set(c+1,r+1,this->matrix[r*this->col+c]+right.matrix[r*right.col+c]);
            }
        }
        return m;
    }
}
Matrix Matrix::operator-(const Matrix &right) const {
    if(this->row!=right.row||this->col!=right.col){
        Error(2);
        return Matrix();
    } else{
        Matrix m(this->row, this->col);
        for(int r=0;r<this->row;r++){
            for(int c=0;c<this->col;c++){
                m.set(c+1,r+1,this->matrix[r*this->col+c]-right.matrix[r*right.col+c]);
            }
        }
        return m;
    }
}
Matrix Matrix::operator*(Matrix &right) {
    if (this->col != right.row){
        Error(1);
        return Matrix();
    }
    int mode = this->mode;

    Matrix returnm(this->row,right.col);
    switch (mode) {
        case 0:
            N_do( &right,&returnm);
            break;
        case 1:
            Quick(&right,&returnm);
            break;
        case 2:
            open_mp(&right,&returnm);
            break;
        case 3:
            open_do(&right,&returnm);
            break;
        case 4:
            Open_super(&right,&returnm);
            break;
        case 5:
            Super_quick(&right,&returnm);
            break;
        default:
            Error(-2);
    }
    return returnm;
}
inline float Matrix::Getelement(int col, int row) {
    return matrix[(col-1)+(row-1)*this->col];
}

float* Matrix::operator[](int i) {
    auto *re = &this->matrix[(i-1)*this->col];
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

    int i;
    int lrow;
    int rrow,rcol;
    lrow = this->row;
    rrow = right->row;
    rcol = right->col;
    float r;
    lrow = this->row;
#pragma omp parallel for num_threads(8)
    for(i=0;i<lrow;++i){
        if(i == lrow-1){
            float* b0,*r0,r;
            for(int k = 0;k<rrow;++k){
                r = this->matrix[i*this->col+k];
                if(r==0){
                    continue;
                }
                for(int j=0;j<rcol;++j){
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

        }else{
            const float* b0;
            float *r0;
            for(int k = 0;k<rrow;++k){
                float32x4_t bt,c0;
                float32x4_t r = vdupq_n_f32(matrix[i * col + k]);
                b0 = &right->matrix[k * right->col];
                for (int j = 0; j < rcol; ++j) {
                    if (rcol - j >= 4) {
                        r0 = &result->matrix[i * result->col]+j;
                        c0 = vld1q_f32(r0);
                        bt = vld1q_f32(b0);
                        c0 += (r*bt);
                        *r0=vgetq_lane_f32(c0,0);
                        r0++;
                        *r0=vgetq_lane_f32(c0,1);
                        r0++;
                        *r0=vgetq_lane_f32(c0,2);
                        r0++;
                        *r0=vgetq_lane_f32(c0,3);
                        j += 3;
                        b0+=4;
                    } else {
                        result->matrix[i * result->col + j] += (matrix[i * col + k] *
                                                                right->matrix[k * right->col + j]);
                    }
                }
            }
        }
    }
}
void Matrix::packMatrix(int n, float *A, float *B, float *C,int BLOCKSIZE) {
    for(int i = 0; i < BLOCKSIZE; i++)

    {
        for(int j = 0; j < BLOCKSIZE; j++)

        {
            float cij = C[i*n+j];
            for(int k = 0; k < BLOCKSIZE; k++ ){
                cij +=A[i*n+k] * B[k*n + j];
            }
            C[i*n+j] = cij;

        }

    }
}

void Matrix::Quick(Matrix *right, Matrix *result) {
    int BLOCKSIZE = 0;
    float *A,*B,*C;
    int n = result->col;
    A = matrix;
    B = right->matrix;
    C = result->matrix;
    if(n<1000){BLOCKSIZE = n;}
    else{
        if (n%200 ==0){BLOCKSIZE=200;}
        else if(n%160 == 0){BLOCKSIZE=160;}
        else if (n%80 == 0){BLOCKSIZE =80;}
        else if(n%40 == 0){BLOCKSIZE = 40;}
        else if(n%32 == 0){BLOCKSIZE = 32;}
        else if(n%24 == 0){BLOCKSIZE = 24;}
        else if(n%16 == 0){BLOCKSIZE = 16;}
        else if(n%10 == 0){BLOCKSIZE = 10;}
        else if(n%8 == 0){BLOCKSIZE = 8;}
        else if (n%5 == 0){BLOCKSIZE = 5;}
        else if (n%3 == 0){BLOCKSIZE = 3;}
       else if(n%2==0){BLOCKSIZE = 2;}
       else {
           Super_quick(right,result);
            return;
       }
    }
#pragma omp parallel for collapse(2) num_threads(8)
    for ( int sj = 0; sj < n; sj += BLOCKSIZE )
        for ( int si = 0; si < n; si += BLOCKSIZE )
            for ( int sk = 0; sk < n; sk += BLOCKSIZE )
                packMatrix(n, A+si*n+sk, B+sk*n+sj,  C+si*n+sj,BLOCKSIZE);

}

void Matrix::random() {
    if(row ==0||col ==0){Error(0);
        return;
    }
    size_t len = (size_t)row*col;
    srand((unsigned)time(NULL));
    for(size_t i=0;i<len;i++){
        matrix[i] = (float)rand() / RAND_MAX;
    }
}
Matrix &Matrix::operator=(const Matrix &right) {
    if (this == &right) return *this;
    if (usethis == 1) {
        delete[] matrix;
    }
    row = right.row;
    col = right.col;
    mode = right.mode;
    size_t len = (size_t)row * col;
    matrix = new float[len];
    memcpy(matrix, right.matrix, len * sizeof(float));
    usethis = 1;
    return *this;
}
#include <iomanip>
using namespace std;
ostream &operator<<(ostream &output, const Matrix &m) {
    int r = m.row;
    int c = m.col;
    float *matrix = m.matrix;
    output.flags(ios::left);
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            output<<setw(10)<<matrix[j+i*c];
        }
        output<<endl;
    }
    return output;
}

void Matrix::reshape(int newcol, int newrow) {
    if(newcol*newrow==col*row){
        col = newcol;
        row = newrow;
    }
    else{
        printf("wrong column and row number!\n");
    }
}

Matrix operator-(const Matrix &m) {
    int r = m.row,c=m.col;
    Matrix re(r,c);
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            re.matrix[i*c+j] = (-m.matrix[i*c+j]);
        }
    }
    return re;
}
