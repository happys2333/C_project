/**
 * encode:UTF8
 * language: C++
 * platform: Windows macOS Linux
 * date : 2020-10-6
 * **/
#include "CodeError.h"
#include "cross_system.h"
using namespace std;

int main(){
    changetheconsle();
    printf("欢迎使用向量点乘计算器，这是C++版本的程序\n"
    "我们建议在您的数据量较少且对运算效率不要求的情况下使用这个最基础的版本\n"
    "");
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
