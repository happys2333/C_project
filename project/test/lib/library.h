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
    bool isnum(int num);
    /*
    * The numerical mode represents the mode of operation required by the user
    * 0: normal mode(don't use any advanced method)
    * 1: quick mode(use Strassen if it is possible)
    * 2: open_MP mode(much powerful mode)
    * 3: open mode ( so tricks to speed up )
    * 4: open super (open mode with open MP)
    * 5: super MP_Strassen
    * */
    int mode = 0;
    void do_Strassen(float* left,float* right,int N,float *result);
    void Strassen(Matrix* right,Matrix* result);
    void open_do(Matrix* right,Matrix* result);
    void open_mp(Matrix* right,Matrix* result);
    void Open_super(Matrix* right,Matrix* result);
    void N_do(Matrix* right,Matrix* result);
    static void add(const float* left,const float* right,float* result,int N);
    static void Sub(const float* left,const float *right,float *result,int N);

public:
    //create an empty matrix
    Matrix();
    //Create an matrix with col and row and matrix itself
    Matrix(int row , int col,float * array);
    // Create an matrix with col and row
    Matrix(int row,int col);
    // Delect an matrix
    ~Matrix();
    // Some functions to use
    void print();//print this matrix
    void build(float* array);
    Matrix& operator*(Matrix& right);//multiple
    Matrix& operator=(float* array);//equal
    Matrix& operator+(Matrix& right);//add
    Matrix& operator-(Matrix& right);//minus
    float* operator[](int i);
    void clear();
    void set(int col,int row,float element);
    void setMode(int semode);
    inline float Getelement(int col,int row);

};

#endif //SOURCE_LIBRARY_H
