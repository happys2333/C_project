/**
 * CUDA核心模块，这里进行并行运算处理
 *
 * 默认同时运算核心数目为：960
 *
 *
 * ***/
#include <iostream>
#include "GPU.h"
#include "CodeError.h"
__global__ void test(int i) {
    int tix = threadIdx.x;
    int tiy=threadIdx.y;
    printf("%d %d\n",tix,tiy+i);

}
int main() {

    printf("Welcome to the vector dot product calculator, you are using the CUDA version.\n"
           "We strongly recommend that you use this program with a lot of data, and if you have less data, try the other two versions\n"
           "This program supports to read in the relevant content through the file, instructions are only allowed to run in accordance with the normal command line\n");
    printGPUInfo();
    printf("Input-q exits, input -f enters file read mode, or input -c enters command line mode\n");
    char* cmd;
    scanf("%s", &cmd);
    while(cmd!="-q"){
     if(cmd[0]!='-'){
         Wrongcmd(cmd);
     }else if(cmd[1]=='c'){
         printf("This is command line mode\n");
         commandmode();
     }else if(cmd[1]=='f'){
        printf("This is file mode\n");
     }else{
         Wrongcmd(cmd);
     }
    }
}
