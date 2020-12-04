#include "library.h"
#include <iostream>
#include <omp.h>
#include <immintrin.h>
#include <time.h>
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

Matrix::Matrix(int row, int col,float num) {
    this->col = col;
    this->row =row;
    int len = col*row;
    matrix = new float [len];
    for(int i=0;i<len;i++){
        matrix[i] =num;
    }
}
Matrix::Matrix() {
    row = 0;
    col = 0;
}
Matrix::~Matrix() {
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
    }else{
        usethis--;
    }
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

    Matrix *returnm= new Matrix(this->row,right.col);
    switch (mode) {
        case 0:
            N_do( &right,returnm);
            break;
        case 1:
            Quick(&right,returnm);
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
        default:
            Error(-2);
    }
    return *returnm;
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
                __m256 r;
                __m256 bt;
                __m256 c0;
                r = _mm256_loadu_ps(&matrix[i * col + k]);
                b0 = &right->matrix[k * right->col];
                for (int j = 0; j < rcol; ++j) {
                    if (rcol - j >= 8) {
                        r0 = &result->matrix[i * result->col];
                        c0 = _mm256_loadu_ps(r0 + j);
                        bt = _mm256_loadu_ps(b0 + j);
                        c0 += (r*bt);
                        _mm256_storeu_ps(r0 + j, c0);
                        j += 7;
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
                if(BLOCKSIZE - k>=8){
                    __m256 r;
                    __m256 bt;
                    __m256 c0;
                    r = _mm256_loadu_ps(&A[i*n]+k);
                    bt = _mm256_loadu_ps(&B[j]+k*n);
                    c0 += r*bt;
                    cij += (c0[1]+c0[2]+c0[0]+c0[3]+c0[4]+c0[5]+c0[6]+c0[7]);
                    k+=7;
                    continue;
                }
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
#pragma omp parallel for num_threads(8)
    for ( int sj = 0; sj < n; sj += BLOCKSIZE )
#pragma omp parallel for num_threads(8)
        for ( int si = 0; si < n; si += BLOCKSIZE )
#pragma omp parallel for num_threads(8)
            for ( int sk = 0; sk < n; sk += BLOCKSIZE )
                packMatrix(n, A+si*n+sk, B+sk*n+sj,  C+si*n+sj,BLOCKSIZE);

}
void Matrix::random() {
    if(row ==0|col ==0){Error(0);
        return;
    }
    int len = row*col;
    if(len>=10000){
        for(int i=0;i<len;i++){
            srand((unsigned)time(NULL));
            matrix[i] = rand();
        }
        return;
    }
    srand((unsigned)time(NULL));
    for(int i=0;i<len;i++){
        matrix[i] = rand();
    }
}
Matrix &Matrix::operator=(Matrix &right) {
    this->~Matrix();
    right.usethis++;
    this->matrix = right.matrix;
    this->usethis = right.usethis;
    this->row = right.row;
    this->col = right.col;
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