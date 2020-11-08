#include <iostream>
#include <ctime>
#include "lib/library.h"
#pragma GCC optimize(3)
int main() {
    float * array = new float [100000000];
    float * array2 = new float [100000000];
    for(int i=0;i<100000000;i++){
        array[i] = 4;
        array2[i] = 3;
    }
    Matrix m1 (10000,10000,array),m2(10000,10000,array2);
    Matrix re;
    m1.setMode(3);
    clock_t start = clock();
    re =m1 * m2;
    clock_t ends = clock();
    printf("use about %lf s\n",(double)(ends - start)/ CLOCKS_PER_SEC);

    return 0;
}
