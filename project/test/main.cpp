#include <iostream>
#include "lib/library.h"
int main() {
    float ** matrix;
    int row=10,col = 10;
    matrix = new float*[row];
    for(int i=0;i<row;i++){
        matrix[i] = new float [col];
    }
    return 0;
}
