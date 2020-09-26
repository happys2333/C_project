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

int main()
{
    string str="x=1";
    cout << str.find('=') << endl;
    string name=str.substr(0,str.find('=')),value=str.substr(str.find('=')+1,str.length());
    cout << name << endl<<value;
    return 0;
}