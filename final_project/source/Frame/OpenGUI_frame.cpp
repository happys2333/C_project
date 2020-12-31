//
// Created by 开心 on 2020/12/24.
//
#include "../Header/OpenGUI_frame.h"

#include <utility>
#include <glew.h>
#include <glfw3.h>



void CFrame::add() {

}

CFrame::CFrame() {
    initial();

}

void CFrame::visualize() {
    window = glfwCreateWindow(width,high,title.c_str(), nullptr,nullptr);
    if(window==nullptr){
        std::cout<<"Error: Failed to create an Window"<<std::endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glViewport(x,y,width,high);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//清空屏幕
    glClear(GL_COLOR_BUFFER_BIT);// 清空缓冲区

}

CFrame::CFrame(unsigned int weight, unsigned int height, unsigned int x, unsigned int y, std::string title) {
    initial();
    this->width=weight;
    this->high=height;
    this->x = x;
    this->y = y;
    this->title = title;
}

void CFrame::BigScreen() {
    Big = true;
}

void CFrame::SmallScreen() {
    Big = false;
}

CFrame::~CFrame() {
    glfwTerminate();
}


