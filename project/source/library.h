#ifndef SOURCE_LIBRARY_H
#define SOURCE_LIBRARY_H
//header your should include!
/*
 * normally open O3
 * */
#pragma GCC optimize(3)
/*
 * report error
 * */
inline void  Error(int type);
class Matrix{
private:
    int col;//column of the matrix
    int row;//row of the matrix
    float* matrix;//matrix itself
    /*
    * The numerical mode represents the mode of operation required by the user
    * 0: normal mode(don't use any advanced method)
    * 1: quick mode(use Strassen if it is possible)
    * 2: SIMD mode(much powerful mode)
    * 3: super mode (use quick and SIMD both)
    *
    * */
    int mode = 0;
    static inline bool cando(const Matrix& left,const Matrix& right);
    float N_dot(float* row,float* col,int rowlen ,int collen);
    void do_Strassen(float* left,float* right,int N,float *result);
    void Strassen(Matrix left,Matrix right,Matrix result);
    void N_do(Matrix left,Matrix right,Matrix result);
    void Q_do(Matrix left,Matrix right,Matrix result);
    static void add(const float* left,const float* right,float* result,int N);
    static void Sub(const float* left,const float *right,float *result,int N);

public:
    //create an empty matrix
    Matrix();
    //Create an matrix with col and row and matrix itself
    Matrix(int col , int row,float * array);
    // Create an matrix with col and row
    Matrix(int col,int row);
    // Delect an matrix
    ~Matrix();
    // Some functions to use
    void print();//print this matrix
    void build(float* array);
    void clear();
    void set(int col,int row,float element);
    void setMode(int semode);
    void GetCol(int col,float& colline);
    void Getrow(int row,float& rowline);
    float Getelement(int col,int row);

};

#endif //SOURCE_LIBRARY_H
