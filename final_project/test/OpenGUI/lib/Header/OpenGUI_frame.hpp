//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENUI_OPENGUI_FRAME_H
#define OPENUI_OPENGUI_FRAME_H

#include "GUIroot.hpp"

#include "Func.hpp"
#include <iostream>
#include <string>
#include "OpenGUI_Button.hpp"
#include "OpenGUI_label.hpp"

extern bool OPENGUI_Init;
class CFrame : UIkit {
private:
    int ExitButton = -10;
    LinkedLists<CButton> CButtonlist;
    LinkedLists<CLabel> CLabellist;
    bool Big = false;
    GLFWwindow *window;

    void mainloop();
    bool isPress(int button);


public:
    ~CFrame();
    void DrawButton(CButton b);
    void setExitButton(int button);
    explicit CFrame(unsigned weight=800,unsigned height=600,unsigned int x=0,unsigned int y=0,std::string title="OpenGUI_frame");
    void addLable(const CLabel &l);
    void addButton(const CButton &b);
    void visualize();
    void BigScreen();
    void SmallScreen();
    void Setsize(unsigned int width,unsigned int height);
    void ReNewWindow();

    GLFWwindow *getWindow() const;

    void setBackgroundColor(float red,float green,float blue,float alpha);
};

#endif //OPENUI_OPENGUI_FRAME_H
