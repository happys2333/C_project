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
#include <algorithm>
#include "mathsin.h"
using namespace std;
/* 这里是一些常用的科学函数
 * */
#define M_exp "2.71828182845904523536028747135"
#define M_sqrt_2 "1.41421356237309504880168872421"
#define M_pi "3.14159265358979323846264338328"
#define M_sqrt_pi "1.77245385090551602729816748334"
#define M_pi_2 "1.57079632679489661923132169164"
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
            exit(-2);
        case -3:
            printf("Error: wrong command please try again\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            exit(-3);
        case -4:
            printf("There is an error in the expression you typed, please retype it\n"
                   "Error reports: in file %s in line %d",filename.c_str(),line);
            exit(-4);
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
string delblock(string s1){
    string result;
    for (int i=0;i<s1.length();i++){
        if (s1[i]==' '){continue;}
        result+=s1[i];
    }
    return s1;
}
class Fuction{
public:
    string delremin(string s1){
        if(s1.find('.')==-1){
            error(2,__FILE_NAME__,__LINE__);
        }
        int len=s1.length();
        for (int i=len-1;i>s1.find('.');i--){
            if (s1[i]=='0'||s1[i]=='.'){
                s1.pop_back();
            } else{
                break;
            }
        }
        if(s1=="0."){
            return "0";
        }
        return s1;
    }
    string doubletostr(long double num,int len){
        ostringstream out;
        if (len>20){
            error(-4,__FILE_NAME__,__LINE__);
            return "wrong";
        }
        out.precision(len+1);
        out<<num;
        return delremin(out.str());
    }
    string changetonormal(string a1){
        int point=a1.find('e');
        string temp;
        for(int i=point+1;i<a1.length();i++){
            if(a1[i]<='9'&&a1[i]>='0') temp+=a1[i];
        }
        stringstream ss(a1),s2(temp);
        int len;
        long double d;
        ss>>d;
        s2>>len;
        if (a1.find('-')!=-1){
            int len2=a1.find('.');
            if (len-len2>3){
                error(-4,__FILE_NAME__,__LINE__);
                return "wrong";
            }
        }
        return doubletostr(d,len);
    }
    string addzeros(string str,int begin,int end){
        for (int i=begin;i<end;i++){
            str+="0";
        }
        return str;
    }
    string add(string a1,string a2){
        int a1len=a1.length()-a1.find('.')-1,a2len=a2.length()-a2.find('.')-1;
        if (a1.find('.')==-1){
            a1+='.';
            for (int i=0;i<a2len;i++){
                a1+='0';
            }
        }
        if (a2.find('.')==-1){
            a2+='.';
            for (int i=0;i<a1len;i++){
                a2+='0';
            }
        }
        if (a1len==a2len) {}
        else{
            if (a1len>a2len){
                for (int i=0;i<a1len-a2len;i++){
                    a2+='0';
                }
            } else{
                for (int i=0;i<a2len-a1len;i++){
                    a1+='0';
                }
            }
        }
        string temp= a1;
        for(int i=0;i<a1.length();++i){
            a1[i]=temp[a1.length()-i-1];
        }
        temp=a2;
        for(int i=0;i<a2.length();++i){
            a2[i]=temp[a2.length()-i-1];
        }
        int maxlength= a1.length()>a2.length()?a1.length():a2.length();
        a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
        a1+="0";a2+="0";
        string result,tempstr;
        int add;
        for(int i=0;i<maxlength;i++){
            add=a1[i]+a2[i]-'0'-'0';
            if (add>=10){
                if (a1[i+1]=='.'){
                    a1[i+2]+=1;
                    add-=10;
                    tempstr=(char(add) + '0');
                    result.insert(0, tempstr);
                    result.insert(0,".");
                    i++;
                    continue;
                }
                a1[i+1]+=1;
                add-=10;
            }
            if (a1[i+1]=='.'){
                tempstr=(char(add) + '0');
                result.insert(0, tempstr);
                result.insert(0,".");
                i++;
                continue;
            }
            tempstr=(char(add) + '0');
            result.insert(0, tempstr);
        }
        if(result[0]=='0'&&result[1]!='.'){
            result.erase(0,1);
        }
        result=delremin(result);
        return result;
    }
    bool big(string str1,string str2){
        if(str1.find('.')>str2.find('.')){
            return true;
        }else if(str1.find('.')<str2.find('.')){
            return false;
        }else{
            int len1 = str1.length(),len2 = str2.length();
            int len=min(len1,len2);
            for(int i=0;i<len;i++){
                if(str1<str2){
                    return false;
                }
                else if (str1>str2){
                    return true;
                }
            }
            if (len1>=len2) return true;
            else return false;
        }
    }
    string minusnum(string a1,string a2){
        bool positve;
        big(a1,a2)?positve=true:positve=false;
        int a1len=a1.length()-a1.find('.')-1,a2len=a2.length()-a2.find('.')-1;
        if (a1.find('.')==-1){
            a1+='.';
            for (int i=0;i<a2len;i++){
                a1+='0';
            }
        }
        if (a2.find('.')==-1){
            a2+='.';
            for (int i=0;i<a1len;i++){
                a2+='0';
            }
        }
        if (a1len==a2len) {}
        else{
            if (a1len>a2len){
                for (int i=0;i<a1len-a2len;i++){
                    a2+='0';
                }
            } else{
                for (int i=0;i<a2len-a1len;i++){
                    a1+='0';
                }
            }
        }
        if (!positve){
            string t=a1;
            a1=a2;
            a2=t;
        }
        string temp= a1;
        for(int i=0;i<a1.length();++i){
            a1[i]=temp[a1.length()-i-1];
        }
        temp=a2;
        for(int i=0;i<a2.length();++i){
            a2[i]=temp[a2.length()-i-1];
        }
        int maxlength= a1.length()>a2.length()?a1.length():a2.length();
        a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
        a1+="0";a2+="0";
        string result,tempstr;
        int add;
        for(int i=0;i<maxlength;i++){
            add=a1[i]-a2[i];
            if (add<0){
                if (a1[i+1]=='.'){
                    a1[i+2]-=1;
                    add+=10;
                    tempstr=(char(add) + '0');
                    result.insert(0, tempstr);
                    result.insert(0,".");
                    i++;
                    continue;
                }
                a1[i+1]-=1;
                add+=10;
            }
            if (a1[i+1]=='.'){
                tempstr=(char(add) + '0');
                result.insert(0, tempstr);
                result.insert(0,".");
                i++;
                continue;
            }
            tempstr=(char(add) + '0');
            result.insert(0, tempstr);
        }
        if(result[0]=='0'&&result[1]!='.'){
            result.erase(0,1);
        }
        result=delremin(result);
        if(positve) return result;
        result.insert(0,"-");
        return result;
    }
    string multiple(string s1,string s2){
        if(s2.find('.')!=-1) {//浮点数乘法进行非精准计算
            string temp;
            long double a1=stod(s1),a2=stod(s2);
            temp=doubletostr(a1*a2,10);
            temp=delremin(temp);
            return temp;
        }
        long long needed=abs(stoll(s2));
        bool positve= true;
        if (s1[0]=='-'){
            string tmp="";
            for (long long i=1;i<s1.length();i++){
                tmp+=s1[i];
            }
            s1=tmp;
            positve= false;
        }
        if (needed<0){
            positve=(!positve);
        }
        string result="0",temp="0";
        for (long long i=0;i<needed;i++){
            temp=add(s1,temp);
        }
        temp=delremin(temp);
        if (positve){
            return temp;
        }
        result+='-';
        for (long long i=0;i<temp.length();i++){
            result+=temp[i];
        }
        return result;
    }
    string divide(string s1,string s2){
        long double a1=stold(s1),a2=stold(s2);
        string result= doubletostr(a1/a2,10);
        return delremin(result);
    }
    string sqrts(string str){
        if (str=="2") return M_sqrt_2;
        if (str=="pi") return M_sqrt_pi;
        long double a1=stold(str);
        string result= doubletostr(sqrt(a1),10);
        return delremin(result);
    }
    string pows(string num, string times){
        long double a1=stold(num);
        long double time=stold(times);
        long double re=pow(a1,time);
        string result= doubletostr(re,10);
        return delremin(result);
    }
    string sins(string x){
        return doubletostr(lookup_sin(stold(x)),7);
    }
    string coss(string x){
        return doubletostr(lookup_cos(stold(x)),7);
    }
    string tans(string x){
        return doubletostr(lookup_tan(stold(x)),7);
    }
    string cots(string x){
        return doubletostr(lookup_cot(stold(x)),7);
    }
    string facts(string x){
        if(x=="1"||x=="0") return "1";
        string result="0";
        long long ned=stoll(x);
        for(long long i=0;i<ned;i++){

        }
    }
    string exps(string x){
        return doubletostr(exp(stold(x)),10);
    }
    string getMax(string x,string y){
        if(big(x,y)) return x;
        return y;
    }
    string getMin(string x,string y){
        if(big(x,y)) return y;
        return x;
    }

}function;
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
        if(!temp.empty()){
            result.add(temp);
        }
        return result;
    }
    string doubletostr(long double num,int len){
        ostringstream out;
        if (len>20){
            return "wrong";
        }
        out.precision(len+1);
        out<<num;
        return out.str();
    }
    string changetonormal(string a1){
        int point=a1.find('e');
        string temp;
        for(int i=point+1;i<a1.length();i++){
            if(a1[i]<='9'&&a1[i]>='0') temp+=a1[i];
        }
        stringstream ss(a1),s2(temp);
        int len;
        long double d;
        ss>>d;
        s2>>len;
        if (a1.find('-')!=-1){
            int len2=a1.find('.');
            if (len-len2>3){return "wrong";}
        }
        return doubletostr(d,len);
    }
    string calcut(string expression){
        string num1,num2,dosomething,temp;
        int left=expression.find('('),right=expression.find(')');
        if (left!=-1){
            temp=expression.substr(left,right);
            while (temp.find('(')!=-1){

            }
        } else {
            string result;


            return
        }
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
class mut{
public:
    string name;
    string value;
};
void multiline(){
    printf("欢迎进入多行操作模式，请您输入表达式，并在结束的时候输入end结束，注意，每行只能给一个变量进行负值，且结尾必须是需要输出的表达式\n"
           "每行的格式是  变量名=表达式\n"
           "最后一行的内容必须是表达式\n");
    string expression;
    mut M;
    ArrayList<mut> ex;
    expression=readlinecmd();
    while (expression!="end"){
        string name=expression.substr(0,expression.find('=')),value=expression.substr(expression.find('=')+1,expression.length());
        M.name=name;
        M.value=value;
        ex.add(M);//传入动态数组
        expression=readlinecmd();
    }
}
void gethelp(){
    printf("本程序由开心制作\n"
           "版本：1.0\n"
           "相关可以操控的指令如下：\n"
           "-h 获取计算器帮助\n"
           "-c 表达式 进行简单的单行计算，支持（）和常用函数表达式\n"
           "-s 进入多行表达式模式，在进入后会给予提示，请在进入后进行输入\n"
           "本程序提供了如下的科学函数，可以在命令行中直接输入函数get(科学常数)名使用\n"
           "例如：1*get[e]=2.71828182845904523536028747135（自然对数的底数）"
           "注意，在本程序中，所有函数使用[数字]进行表达，如sin[2],exp[2]等\n"
           "本程序提供了如下的函数:自然对数的底数（e）根号2（sqrt_2）π（pi）根号π(sqrt_pi)二分之一π（pi_2）\n"
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
