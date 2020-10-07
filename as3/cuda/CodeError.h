
#ifndef CUDA_CODEERROR_H
#define CUDA_CODEERROR_H
#include<iostream>
using namespace std;
void Wrongcmd(char* cmd){
    cout<<"you command :"<<cmd<<"isn't command we can recognition, please try again"<<endl;
}
void Wronglinenum(long line){
    printf("Wrong line length, please try again");
}
void unknownerror(int line,char *file){
    printf("Unknown error in file: %s, in line: %d",file,line);
    exit(1);
}




#endif //CUDA_CODEERROR_H
