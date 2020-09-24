/* **********************************************************
 * Project name :Assignment 2
 * author: happys
 * date: 2020-9-23
 * file name: main.h
 * purpose : provide some function for main function to use
 * **********************************************************/
#ifndef C___FIND_H
#define C___FIND_H
#include "string"
#include <vector>
#include "arraylist.h"
using namespace std;
//报错板块
void error(int code,string filename,int line){
    switch (code) {
        case -1:
            printf("Error: unsupported system please use other system and try again.\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            exit(-1);
        case -2:
            printf("Error: unsupported system please use other system and try again.\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            exit(-2);
        default:
            printf("Error: Unknown error, please connect with the author \n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            exit(2);
    }
}
//快速读取
inline string readlinecmd(){
    string a;
    char ch=getchar();
    while (ch!='\n'){
        a+=ch;
        ch=getchar();
    }
    return a;
}

/* 这部分函数负责对平台进行识别，如果发现是windows平台就会更改控制台为UTF-8编码，以此来实现中文支持
 * */
#if defined(__APPLE__)
# include <TargetConditionals.h>
#include <vector>

# if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#   define MAC
# endif
#elif defined(__linux__) || defined(__linux)
#   define LINUX
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
# define WIN32
#endif
string findout()
{
#if defined MAC
    return "mac";
#elif defined WIN32
    return "windows";
#elif defined LINUX
    return "linux";
#else
    return "unknown";
#endif
}
void changetheconsle(){
    string sy=findout();
    if(sy=="windows"){
        system("chcp 65001");
    }
    if (sy=="unknown"){
        error(-1,__FILE_NAME__,__LINE__);
    }
    printf("您的系统是：%s\n",sy.c_str());
    printf("欢迎使用科学计算器中文版 版本号：1.0");
}
//计算器主要区域：包括整个对数据的分析与处理，计算的内容等。
class Calculator{
private:
    ArrayList<string> num;
    string cmd;
    ArrayList<string> dosome;
    string result;
    int mode=0;
public:
    string addzeros(string str,int begin,int end){
        for (int i=begin;i<end;i++){
            str+="0";
        }
        return str;
    }
    
    string add(string a1,string a2){
        string temp= a1;
        for(int i=0;i<a1.length();++i){
            a1[i]=temp[a1.length()-i-1];
        }
        temp=a2;
        for(int i=0;i<a2.length();++i){
            a2[i]=temp[a2.length()-i-1];
        }
        a1+="0";a2+="0";
        int maxlength= a1.length()>a2.length()?a1.length():a2.length();
        a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
        string result,tempstr;
        int add;
        for(int i=0;i<maxlength;i++){
            add=a1[i]+a2[i]-'0'-'0';
            if (add>=10){
                a1[i+1]+=1;
                add-=10;
            }
            tempstr=(char(add) + '0');
            result.insert(0, tempstr);
        }
        if(result[0]=='0'){
            result.erase(0,1);
        }
        return result;
    }
    string minus
    void finish(){
        num.clear();
        dosome.clear();
        cmd="";
        result="";
        mode=0;
    }
    void setcmd(string command){

    }

}calculator;
void gethelp(){
    printf("");
}
void mainloop(){
    string cmd="";
    printf("本程序是一款高级智能的计算器，采用c++编写而成，通过控制台指令进行操控，如果您想获取帮助请输入-h，如果您想退出请输入-q\n");
    while (cmd!="-q"){

    }
}


#endif //C___FIND_H
