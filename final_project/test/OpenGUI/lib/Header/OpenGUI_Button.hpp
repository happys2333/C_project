//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENGUI_OPENGUI_BUTTON_HPP
#define OPENGUI_OPENGUI_BUTTON_HPP
#include "GUIroot.hpp"



class CButton : UIkit{
private:
    typedef bool (*ButtonFun) ();
    ButtonFun fun;
public:
    CButton(std::string title="Button",unsigned width=100,unsigned int height=50,unsigned int x=0,unsigned int y=0);
    void setBackgroundColor(float red,float green,float blue,float alpha);
    void draw(GLFWwindow * window,int WINwidth, int WINheight);
    bool isClick(int MouseX,int MouseY);
    void SetButtonFun(ButtonFun f){
        fun=f;
    }
    void DoButtonFun(){
        if(!(*fun)()){
            exit(1);
        }
    }
    int getHeight(){
        return height;
    }
    int getWidth(){
        return width;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    float getBackgroundRed(){
        return Background_red;
    }
    float getBackgroundGreen(){
        return Background_green;
    }
    float getBackgroundBlue(){
        return Background_blue;
    }

};


#endif //OPENGUI_OPENGUI_BUTTON_HPP
