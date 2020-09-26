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
string delremin(string s1){
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
    out.precision(len+1);
    out<<num;
    return delremin(out.str());
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
int main()
{
    string str="0.2",str2="0.2";
    cout << multiple(str,"6") << endl;
    return 0;
}