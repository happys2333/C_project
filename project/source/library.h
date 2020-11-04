#ifndef SOURCE_LIBRARY_H
#define SOURCE_LIBRARY_H
//header your should include!
void hello();
class Matrix{
private:
    int col;//column of the matrix
    int row;//row of the matrix
    float** matrix;//matrix itself
    float N_dot(float *r1,float *r2);
    float Q_dot(float *r1,float *r2);
    float Fast_dot(float *r1,float *r2);
    float Big_dot(float *r1,float *r2);
public:
    // Create an matrix with col and row
    Matrix(int col,int row);
    // Delect an matrix
    ~Matrix();
    // Some new function to use
    void print();

};

#endif //SOURCE_LIBRARY_H
