#ifndef SOURCE_LIBRARY_H
#define SOURCE_LIBRARY_H
//header your should include!
/*
 * normally open O3
 * */
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define Matrix_normal_mode 0
#define Matrix_quick_mode 1
#define Matrix_openMP_mode 2
#define Matrix_open_mode 3
#define Matrix_openSuper_mode 4
#define Matrix_super_MP_mode 5
/*
 * report error
 * */
inline void  Error(int type);
class Matrix{
private:
    int col;//column of the matrix
    int row;//row of the matrix
    float* matrix;//matrix itself
    int usethis = 1;
    /*
    * The numerical mode represents the mode of operation required by the user
    * 0: normal mode(don't use any advanced method)
    * 1: quick mode
    * 2: open_MP mode(much powerful mode)
    * 3: open mode ( so tricks to speed up )
    * 4: open super (open mode with open MP)
    * 5: super MP_Quick mode
    * */
    int mode = 0;
    void Quick(Matrix* right,Matrix* result);
    void packMatrix(int n, float *A, float *B, float *C,int BLOCKSIZE);
    void open_do(Matrix* right,Matrix* result);
    void open_mp(Matrix* right,Matrix* result);
    void Open_super(Matrix* right,Matrix* result);
    void Super_quick(Matrix* right,Matrix* result);
    void N_do(Matrix* right,Matrix* result);
public:
    //create an empty matrix
    Matrix();
    //Create an matrix with col and row and matrix itself
    Matrix(int row , int col,float * array);
    // Create an matrix with col and row
    Matrix(int row,int col,float num=0);
    // Delect an matrix
    ~Matrix();
    // Some functions to use
    void print();//print this matrix
    void rand();//create a random matrix
    string toString();
    void build(float* array);
    Matrix& operator*(Matrix& right);//multiple
    Matrix& operator=(float* array);//equal
    Matrix& operator=(Matrix& right);//equal
    Matrix& operator+(Matrix& right);//add
    Matrix& operator-(Matrix& right);//minus
    float* operator[](int i);//get the line array
    friend ostream &operator<<(ostream &output, const Matrix& m)
    void rand();
    void clear();
    void set(int col,int row,float element);
    //set your mode
    void setMode(int semode);
    inline float Getelement(int col,int row);

};

#endif //SOURCE_LIBRARY_H
