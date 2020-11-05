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
    * 0: normal mode
    * 1: Strassen mode
    * 2:
    *
    *
    *
    * */
    int mode = 0;
    inline bool cando(Matrix left,Matrix right);
    float N_dot(float* row,float* col,int rowlen ,int collen);
    float Q_dot(float* row,float* col,int rowlen ,int collen);
    Matrix Strassen(Matrix left,Matrix right);
    Matrix N_do(Matrix left,Matrix right);
    Matrix Q_do(Matrix left, Matrix right);
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
    void setMode(int mode);
    void GetCol(int col,float& colline);
    void Getrow(int row,float& rowline);
    float Getelement(int col,int row);

};

#endif //SOURCE_LIBRARY_H
