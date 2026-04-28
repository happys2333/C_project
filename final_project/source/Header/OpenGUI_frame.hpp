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

class CFrame : public UIkit {
private:
    GLint ExitButton = -10;
    LinkedLists<CButton> CButtonlist;
    LinkedLists<CLabel> CLabellist;
    bool Big = false;
    GLFWwindow *window = nullptr;
    float preX, preY;
    int mouseX = 0, mouseY = 0;
    bool prevMousePressed = false;
    void mainloop();
    bool isPress(int button);
    void getPre();
    static void cursorPosCallback(GLFWwindow* window, double x, double y);
public:
    ~CFrame();
    void DrawButton(CButton b);
    void setExitButton(int button);
    explicit CFrame(GLint width=800,GLint height=600,GLint x=0,GLint y=0,std::string title="OpenGUI_frame");
    void addLabel(const CLabel &l);
    void addButton(const CButton &b);
    void visualize();
    void BigScreen();
    void SmallScreen();
    void Setsize(GLint width,GLint height);
    void ReNewWindow();

    GLFWwindow *getWindow() const;

    void setBackgroundColor(float red,float green,float blue,float alpha);
};

#endif //OPENUI_OPENGUI_FRAME_H
