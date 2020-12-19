//
//  source.hpp
//  SUSTech_Helper
//
//  Created by 开心 on 2020/12/8.
//

#ifndef source_hpp
#define source_hpp

#include <stdio.h>
#include <vector>

using namespace std;
class GPA {
private:
    float gpa=0;
    int credits=0;
    float sorce =0;
public:
    GPA(float sorce,int classsorce){
        this->sorce = sorce;
        this->credits = classsorce;
        
    }
    ~GPA(){
        gpa = 0;
        credits = 0;
        sorce = 0;
    }
    static float toGPA(int s){
        if(s<60) return 0;
        switch (s) {
            case 60:
                return 1;
            case 61:
                return 1.15;
            case 62:
                return 1.29;
            case 63:
                return 1.43;
            case 64:
                return 1.57;
            case 65:
                return 1.7;
            case 66:
                return 1.83;
            case 67:
                return 1.96;
            case 68:
                return 2.08;
            case 69:
                return 2.2;
            case 70:
                return 2.31;
            case 71:
                return 2.42;
            case 72:
                return 2.53;
            case 73:
                return 2.63;
            case 74:
                return 2.73;
            case 75:
                return 2.83;
            case 76:
                return 2.92;
            case 77:
                return 3.01;
            case 78:
                return 3.09;
            case 79:
                return 3.17;
            case 80:
                return 3.25;
            case 81:
                return 3.32;
            case 82:
                return 3.39;
            case 83:
                return 3.45;
            case 84:
                return 3.52;
            case 85:
                return 3.58;
            case 86:
                return 3.63;
            case 87:
                return 3.68;
            default:
                break;
        }
        if(s>100){
            return 4;
        }
        return -1;
    }
    float getGpa() const {
        return gpa;
    }

    int getCredits() const {
        return credits;
    }
    float getSorce() const {
        return sorce;
    }
    GPA& operator=(float g){
        this->gpa = g;
        return *this;
    }
    GPA& operator+(GPA& g){
        this->credits = this->credits+g.credits;
        this->gpa += g.gpa;
        return *this;
    }


};
//class score{
//private:
//    vector <GPA> gpa;
//public:
//    void addGPA(){
//        
//    }
//    float getFullGPA(){
//        
//    }
//};

#endif /* source_hpp */
