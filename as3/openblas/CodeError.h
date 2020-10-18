
#ifndef CUDA_CODEERROR_H
#define CUDA_CODEERROR_H
#include<iostream>
using namespace std;
void Wrongcmd(string cmd){
    cout<<"you command :"<<cmd<<"isn't command we can recognition, please try again"<<endl;
}
void Wronglinenum(long line){
    printf("Wrong line length, please try again");
}
void failtoread(){
    printf("fail to read: NO SUCH FILE");
    exit(2);
}



#endif //CUDA_CODEERROR_H
