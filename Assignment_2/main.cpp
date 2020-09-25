/* **********************************************************
 * Project name :Assignment 2
 * author: happys
 * date: 2020-9-23
 * file name: main.cpp
 * purpose : main function main entry of the program
 * **********************************************************/
//#include "main.h"
//int main() {
//    changetheconsle();
//    mainloop();
//}
#include<iostream>
#include "arraylist.h"
#include<string>
using namespace std;
#define postive 1
#define negative 0
#define mode 1e9+7
bool isbig(string a1,string a2){
    if (a1[0]=='-'&&a2[0]!='-')return false;
    else if (a1[0]!='-'&&a2[0]=='-') return true;
    else{
        int pointof1=a1.find('.'),pointof2=a2.find('.');
        if (pointof1==-1&&pointof2==-1){
            if (a1[0]=='-'&&a2[0]=='-'){
                if (a1>a2) return false;
                else if (a1<a2) return true;
                else{
                    for (int i=1;i<a1.length();i++){
                        if ()
                    }
                }
            } else{

            }
        }else{
            
        }

    }
}
string addzeros(string str,int begin,int end){
    for (int i=begin;i<end;i++){
        str+="0";
    }
    return str;
}
string minusnum(string a1,string a2){

    if (a1.find('.')==-1||a2.find('.')==-1){
        int a1len=a1.length()-a1.find('.')-1,a2len=a2.length()-a2.find('.')-1;
        if (a1.find('.')==-1){
            a1+='.';
            for (int i=0;i<a2len;i++){
                a1+='0';
            }
        } else if (a2.find('.')==-1){
            a2+='.';
            for (int i=0;i<a1len;i++){
                a2+='0';
            }
        } else if (a1len==a2len) {}
        else{
            if (a1len>a2len){
                for (int i=0;i<a1len-a2len;i++){
                    a1+='0';
                }
            } else{
                for (int i=0;i<a2len-a1len;i++){
                    a2+='0';
                }
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
    a1+="0";a2+="0";
    int maxlength= a1.length()>a2.length()?a1.length():a2.length();
    a1.length()>a2.length()?a2=addzeros(a2,a2.length(),maxlength):a1=addzeros(a1,a1.length(),maxlength);
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
                continue;
            }
            a1[i+1]+=1;
            add-=10;
        }
        tempstr=(char(add) + '0');
        result.insert(0, tempstr);
    }
    if(result[0]=='0'){
        result.erase(0,1);
    }
    result=delremin(result);
    return result;
}
int main()
{
    string str="109000", str2="9.87";
    str=minusnum(str,str2);
    cout << str << endl;

    return 0;
}