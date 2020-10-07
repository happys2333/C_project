/* 本程序是参考Java迁移实现的一个动态数组库，由我在今年早期开发实现，在CSDN上可以找到我写的原文
 * */
//按照java原生ArrayList编写
// 由开心创建于2020年
//使用方法参考开发日志
// this method is from java original method called ArrayList
// made by happy on 2020
// please read the CAVA development logs
//version 1.0
//@email ：happys233@qq.com
#ifndef C___ARRAYLIST_H
#define C___ARRAYLIST_H
#include<iostream>
#include<string>
#include <sstream>
using namespace std;

template <class Object>
class ArrayList {
private:
    int DEFAULT_CAPACITY=10;
    int length =0;
    Object *arr=new Object[10];
    template<typename T> string TtoString(const T& t){
        ostringstream oss;
        oss<<t;
        return oss.str();
    }
    void makesure(){
        if(length==DEFAULT_CAPACITY){
            grow();
            if(length==DEFAULT_CAPACITY){
                DEFAULT_CAPACITY++;
                grow();
            }
        }
    }
    void grow(){
        DEFAULT_CAPACITY=DEFAULT_CAPACITY+(DEFAULT_CAPACITY>>1);
        Object* tmp=new Object[DEFAULT_CAPACITY];
        for (int i = 0; i <length; i++){
            tmp[i]=arr[i];
        }
        delete[] arr;
        arr=tmp;
    }
    int indexOfRange(Object o, int start, int end) {
        Object* tmp=clone();
        int i;
        if (o == NULL) {
            for(i = start; i < end; ++i) {
                if (tmp[i] == NULL) {
                    return i;
                }
            }
        } else {
            for(i = start; i < end; ++i) {
                if (o==tmp[i]) {
                    return i;
                }
            }
        }

        return -1;
    }
public :
    void setSize(int len){
        DEFAULT_CAPACITY=len;
        arr=new Object[len];
    }
    void replace(Object old, Object newobj) {
        for (int i=0;i<length;i++) {
            if (arr[i] == old) {
                arr[i]=newobj;
                return;
            }
        }
    }
    void replaceAll(Object old, Object newobj) {
        for (int i=0;i<length;i++) {
            if (arr[i] == old) {
                arr[i]=newobj;
            }
        }
    }
    void remove(int start, Object old, Object newobj) {
        if(start>=length||start<0) {
            string s="ArrayIndexOutOfBoundsException start: ";
            ostringstream oss;
            oss<<start;
            s.append(oss.str());
            s.append(", Size: ");
            ostringstream oss2;
            oss2<<length;
            s.append(oss2.str());
            cout<<s;
            exit(1);
        }
        for (int i=start; i<length;i++) {
            if (arr[i] == old) {
                arr[i]=newobj;
                return;
            }
        }
    }
    void trimToSize() {
        arr=clone();
        DEFAULT_CAPACITY=length;
    }
    bool contains(Object o) {
        return indexOf(o) >= 0;
    }
    Object* clone() {
        Object* o = new Object[length];
        for (int i = 0; i < length; i++){
            o[i]=arr[i];
        }
        return o;
    }
    bool isEmpty() {
        return length == 0;
    }
    int indexOf(Object o) {
        return indexOfRange(o, 0, length);
    }
    void add(Object t) {
        makesure();
        arr[length] = t;
        length++;
    }
    void add(int index, Object t) {
        if(index>length||index<0){
            string s="IndexOutOfBoundsException Index: ";
            ostringstream oss;
            oss<<index;
            s.append(oss.str());
            s.append(", Size: ");
            ostringstream oss2;
            oss2<<length;
            s.append(oss2.str());
            cout<<s;
            exit(1);
        }
        else if(index==length){
            add(t);
        }
        else{
            Object *ob;
            ob=new Object[length+1];
            for(int i=0;i<length+1;i++){
                if(i<index){
                    ob[i]=arr[i];
                }
                else if (i==index){
                    ob[index]=t;
                }
                else{
                    ob[i]=arr[i-1];
                }
            }
            delete[] arr;
            DEFAULT_CAPACITY++;
            arr=ob;
        }
        length++;
    }
    template  <class T>
    bool remove(T o) {
        for (int index = 0; index < length; index++){
            if (o==arr[index]) {
                remove(index);
                return true;
            }
        }
        return false;
    }
    void remove(int index){
        if(index>length||index<0){
            string s="IndexOutOfBoundsException Index: ";
            ostringstream oss;
            oss<<index;
            s.append(oss.str());
            s.append(", Size: ");
            ostringstream oss2;
            oss2<<length;
            s.append(oss2.str());
            cout<<s;
            exit(1);
        }
        else if(index==length){
            arr[index]=NULL;
        }
        else{
            for (int i = index; i <length-1 ; ++i) {
                arr[i]=arr[i+1];
            }
            arr[length]=NULL;
        }
        length--;
    }
    void set(int index, Object o){
        if (index>= length||index<0)
        {
            string s="ArrayIndexOutOfBoundsException Index: ";
            ostringstream oss;
            oss<<index;
            s.append(oss.str());
            s.append(", Size: ");
            ostringstream oss2;
            oss2<<length;
            s.append(oss2.str());
            cout<<s;
            exit(1);
        }
        else{
            arr[index]=o;
        }
    }
    int size() {
        return length;
    }
    void clear() {
        delete[] arr;
        DEFAULT_CAPACITY=10;
        length =0;
        arr=new Object[10];
    }
    Object get(int index) {
        if (index>= length||index<0)
        {
            string s="ArrayIndexOutOfBoundsException Index: ";
            ostringstream oss;
            oss<<index;
            s.append(oss.str());
            s.append(", Size: ");
            ostringstream oss2;
            oss2<<length;
            s.append(oss2.str());
            cout<<s;
            exit(1);
        }
        else
        {
            return arr[index];
        }
    }
    Object* toArray() {
        return arr;
    }
    string toString() {
        if (length==0)
        {
            string s2;
            s2="[]";
            return s2;
        }
        else
        {
            string s;
            s.append("[");
            int i=0;
            while(true){
                s.append(TtoString(get(i)));
                i++;
                if(i==length){
                    s.append("]");
                    return s;
                }
                s.append(", ");
            }
        }
    }
};
#endif //C___ARRAYLIST_H