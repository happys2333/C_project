#include <ctime>
#include <cblas.h>
int main(){
    float  *array = new float[100000000];
    float  *array2 = new float[100000000];
    for(int i=0;i<100000000;i++){
        array[i] = 4;
        array2[i] = 3;
    }
    float *re = new float[100000000];
    clock_t begin_t  = clock();
    cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,10000,10000,10000,1,array,10000,array2,10000,0,re,10000);
    clock_t finish_t = clock();
    printf("time about: %lf s",(double )(finish_t - begin_t )/CLOCKS_PER_SEC);
}
