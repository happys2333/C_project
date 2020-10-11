#include "GPU.h"

int main() {
    printf("Welcome to the vector dot product calculator, you are using the CUDA version.\n"
           "We strongly recommend that you use this program in situations where data operations are complex, but you have a good graphics card with a large amount of data.\n"
           "If your data volume is relatively low, use the base version or The Julia version\n");
    printGPUInfo();
    printf("Input-q exits, input -f enters file read mode, or input -c enters command line mode\n");
    string cmd;
    cin>>cmd;
    while(cmd!="-q"){
     if(cmd[0]!='-'){
         Wrongcmd(cmd);
     }else if(cmd[1]=='c'){
         printf("This is command line mode\n");
         commandmode();
     }else if(cmd[1]=='f'){
        printf("This is file mode\n");
        fileMode();
     }else{
         Wrongcmd(cmd);
     }
     printf("please enter your command\n");
     cin>>cmd;
    }
}