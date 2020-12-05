#include <iostream>
using namespace std;
#include "lib/library.h"
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
int main() {
    int n=10;
    Matrix m1 (n,n,2),m2(n,n,4);
    Matrix re;

    m1.setMode(Matrix_super_MP_mode);
    re =m1 * m2;
    cout<<re;
    re = m2-m1;
    cout<<re;
    re = m1+m2;
    cout<<re;
    re = (-m1);
    cout<<re;
}
