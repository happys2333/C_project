#include <iostream>
#include <ctime>
#include "lib/library.h"
#pragma GCC optimize(3)
int main() {
    int n=1024;
    float * array = new float [n*n];
    float * array2 = new float [n*n];
    for(int i=0;i<n*n;i++){
        array[i] = 4;
        array2[i] = 2;
    }
    Matrix m1 (n,n,array),m2(n,n,array2);
    Matrix re;
    m1.setMode(1);
    clock_t start1 = clock();
    re =m1 * m2;
    clock_t ends1 = clock();

    printf("use about %lf s\n",(double)(ends1 - start1)/ CLOCKS_PER_SEC);
//    re.print();
    return 0;
}

//#include <omp.h>
//#include "iostream"
//#define COUNT 10
//
//int main(int argc, char* argv[])
//{
//    int sum = 0;		// Assign an initial value.
//#pragma omp parallel for num_threads(4) reduction(+:sum)
//    for(int i = 0;i < COUNT; i++)
//    {
//        sum += (i+1);
//        printf("i: %d\n",i+1);
//        printf("Sum: %d\n",sum);
//    }
//    printf("Sum: %d\n",sum);
//
//    return 0;
//}