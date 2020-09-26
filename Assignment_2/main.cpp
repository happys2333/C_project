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
string calcut(string expression){
    string num1,num2,dosomething,temp;
    int left=expression.find('('),right=expression.find_last_of(')');
    if (left!=-1&&right!=-1){
        temp=expression.substr(left+1,right-1);
        temp = calcut(temp);
        return temp;
    }//这里进行报错判断
    else if (left==-1&&right!=-1){

    }
    else if (right==-1&&left!=-1){

    }
    else {
        string result;
        int low=0,high=0;
        //先遍历第一次实现对所有科学函数的处理转化
        while (true){
            low=expression.find('[',low);
            high=expression.find(']',high);
            if(high==-1&&low!=-1) return "wrong";
            else if(high!=-1&&low==-1) return "wrong";
            else if(high==-1&&low==-1) break;
            else{
                switch(expression[low-1]){
                    case 'w': //pow
                        expression.replace()
                        break;
                    case 'p':  //exp
                        break;
                    case 'x': //max
                        break;
                    case 'n': //min and sin and tan
                        break;
                    case 's': //cos and abs
                        break;
                    case 't': //cot and fact and sqrt
                        break;
                    default:
                        break;
                }
            }
        }

        return result;
    }
}
int main()
{
    string str="(0.2+0.8*2+exp[3]*5)";
    cout<<calcut(str)<<endl;
    return 0;
}