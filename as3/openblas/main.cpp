/****
 *
 * normal version for the dot vectors
 * speed : not so fast
 * difficulty to use : easy
 * system :Windows Linux Mac OS
 * author : happys
 * date : 2020-10-11
 * ****/
#include <iostream>
#include "cross_system.h"
#include "main.h"

int main() {
    changetheconsle();
    printf("欢迎使用向量点乘计算器，您正在使用的版本是 C++ 版本\n"
           "我们强烈建议您在数据量较小，且不要求很快的情况下使用本程序\n"
           "如果您要求精准度请使用Julia版本，如果您要求速度请使用cuda版本\n"
           "请输入指令，-q退出程序，-c命令行模式，-f文件模式，所有结果会在本程序的相同目录中生成result.txt文件保存\n");
    string cmd;
    cin>>cmd;
    while(cmd!="-q"){
        if(cmd[0]!='-'){
            Wrongcmd(cmd);
        }else if(cmd[1]=='c'){
            printf("欢迎使用命令行模式\n");
            commandmode();
        }else if(cmd[1]=='f'){
            printf("欢迎使用文件读取模式\n");
            fileMode();
        }else{
            Wrongcmd(cmd);
        }
        printf("请输入您的命令：\n");
        cin>>cmd;
    }
}