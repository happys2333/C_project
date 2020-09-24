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
            printf("Error: unsupported command, please check your input\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            break;
        case -3:
            printf("Error: wrong command please try again\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            break;
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
    ArrayList<string> split(string original,string need){
        ArrayList<string> result;
        string temp,pattern;
        size_t len=need.length();
        for(size_t i = 0; i < original.length(); i++)
        {
            if(need[0] == original[i])
            {
                pattern = original.substr(i, len);
                if(pattern == need)
                {
                    i += len - 1;
                    if(!temp.empty())
                    {
                        result.add(temp);
                        temp.clear();
                    }
                }
                else
                {
                    temp.push_back(original[i]);
                }
            }
            else
            {
                temp.push_back(original[i]);
            }
        }

        if(!temp.empty())
        {
            result.add(temp);
        }

        return result;
    }
    string changetonormal(string a1){
        if (a1.find('e')){
            ArrayList<string> num=split(a1,"e");
            if (num.size()!=2) {
                error(-2,__FILE_NAME__,__LINE__);
                return "wrong";
            }
            if (a1.find('.')){

            } else{

            }
        }
    }
    string add(string s1,string s2){

    }
    string minus(string s1,string s2){

    }
    string multiple(string s1,string s2){

    }
    string mod(string s1,string s2){

    }
    string divide(string s1,string s2){
        string s = "", t = "";
        int n = s1.length(), m = s2.length();
        bool flag = false;
        for (int i = 0; i < n; i ++) {
            s += s1[i];
            int num = 0;
            while (cmp(s, s2) == false) {
                num ++;
                s = sub(s, s2);
            }
            if (num > 0) {
                flag = true;
                char c = (char)(num + '0');
                t += c;
            }
            else if (flag) {
                t += '0';
            }
        }
        if (t.length() == 0) t = "0";
        while (s[0] == '0' && s.length() > 1) s = s.substr(1);
        return make_pair(t, s);
    }
    void finish(){
        num.clear();
        dosome.clear();
        cmd="";
        result="";
        mode=0;
    }

}calculator;
void onlyline(string cmd){
    string needsovle="";
    for (int i=2;i<cmd.length();i++){
        needsovle[i-3]=cmd[i];
    }
    printf("正在计算您的表达式： %s 请稍后",needsovle.c_str());
}
void multiline(){

}
void gethelp(){
    printf("本程序由开心制作\n"
           "版本：1.0\n"
           "相关可以操控的指令如下：\n"
           "-h 获取计算器帮助\n"
           "-c 表达式 进行简单的单行计算，支持（）和常用函数表达式\n"
           "-s 进入多行表达式模式，在进入后会给予提示，请在进入后进行输入\n"
           "-q 退出本程序\n");
}
void mainloop(){
    string cmd="";
    printf("本程序是一款高级智能的计算器，采用c++编写而成，通过控制台指令进行操控，如果您想获取帮助请输入-h，如果您想退出请输入-q\n");
    while (cmd!="-q"){
        printf("请输入您的指令>>>");
        cmd=readlinecmd();
        if (cmd[0]!='-'){
            error(-3,__FILE_NAME__,__LINE__);
            continue;
        } else if (cmd=="-h") gethelp();
        else if (cmd[1]=='c') onlyline(cmd);
        else if (cmd[1]=='s') multiline();
    }
    printf("感谢您的使用");
}


#endif //C___FIND_H
