#include <iostream>
#include <ctime>
#include "lib/library.h"
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
int main() {
    int n=10000;
    auto * array = new float [n*n];
    auto * array2 = new float [n*n];
    for(int i=0;i<n*n;i++){
        array[i] = 4;
        array2[i] = 2;
    }
    Matrix m1 (n,n,array),m2(n,n,array2);
    Matrix re;
    m1.setMode(6);
    clock_t start1 = clock();
    re =m1 * m2;
//    don(array,array2,n,array3);
    clock_t ends1 = clock();

    printf("use about %lf s\n",(double)(ends1 - start1)/ CLOCKS_PER_SEC);
//    re.print();
    return 0;
}
//#include <iostream>
//#include <ctime>
//int main() {
//    int n=10000;
//    auto * array = new double [n*n];
//    auto * array2 = new double [n*n];
//    auto * array3 = new double [n*n];
//    for(int i=0;i<n*n;i++){
//        array[i] = 4;
//        array2[i] = 2;
//    }
//
//    clock_t start1 = clock();
//    MY_MMult(n,n,n,array,n,array2,n,array3,n);
////    don(array,array2,n,array3);
//    clock_t ends1 = clock();
//
//    printf("use about %lf s\n",(double)(ends1 - start1)/ CLOCKS_PER_SEC);
////    re.print();
//    return 0;
//}