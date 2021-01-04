//
// Created by 开心 on 2020/12/31.
//

#ifndef OPENGUI_GUIROOT_HPP
#define OPENGUI_GUIROOT_HPP
#include <glfw3.h>

#include <iostream>
#include <string>
#include <ctime>

class UIkit{
protected:
    GLint x=0,y=0;
    GLint width=0,height=0;
    int id;
    std::string title;
    float Background_red = 0;
    float Background_green = 0;
    float Background_blue = 0;
    float Background_alpha = 1;
public:
    UIkit(){
        srand((unsigned)time(NULL));
        id = rand();
    }
    GLint getX() const {
        return x;
    }

    void setX1(GLint x) {
        UIkit::x = x;
    }

    void setY1(GLint y) {
        UIkit::y = y;
    }

    void setWidth(GLint width) {
        UIkit::width = width;
    }

    void setHeight(GLint height) {
        UIkit::height = height;
    }

    float getBackgroundRed() const {
        return Background_red;
    }

    void setBackgroundRed(float backgroundRed) {
        Background_red = backgroundRed;
    }

    float getBackgroundGreen() const {
        return Background_green;
    }

    void setBackgroundGreen(float backgroundGreen) {
        Background_green = backgroundGreen;
    }

    float getBackgroundBlue() const {
        return Background_blue;
    }

    void setBackgroundBlue(float backgroundBlue) {
        Background_blue = backgroundBlue;
    }

    float getBackgroundAlpha() const {
        return Background_alpha;
    }

    void setBackgroundAlpha(float backgroundAlpha) {
        Background_alpha = backgroundAlpha;
    }

    void setX(GLint x) {
        UIkit::x = x;
    }
    bool isPress(GLFWwindow *window,GLint button) {
        return glfwGetKey(window,button)==GLFW_PRESS;
    }
    GLint getY() const {
        return y;
    }

    void setY(GLint y) {
        UIkit::y = y;
    }

    GLint getId() const {
        return id;
    }

    void setId(GLint id) {
        UIkit::id = id;
    }

    const std::string &getTitle() const {
        return title;
    }
    void setTitle(const std::string &title) {
        UIkit::title = title;
    }

    GLint getHeight() const {
        return height;
    }
    ~UIkit() {
        x=0,y=0;
        width=0,height=0;
        title = "";
        Background_red = 0;
        Background_green = 0;
        Background_blue = 0;
        Background_alpha = 1;
    }
};
#endif //OPENGUI_GUIROOT_HPP
