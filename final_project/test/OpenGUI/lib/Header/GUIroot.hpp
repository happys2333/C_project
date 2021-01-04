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
    unsigned int x=0,y=0;
    unsigned int width=0,height=0;
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
    int getX() const {
        return x;
    }

    void setX1(unsigned int x) {
        UIkit::x = x;
    }

    void setY1(unsigned int y) {
        UIkit::y = y;
    }

    void setWidth(unsigned int width) {
        UIkit::width = width;
    }

    void setHeight(unsigned int height) {
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

    void setX(int x) {
        UIkit::x = x;
    }
    bool isPress(GLFWwindow *window,int button) {
        return glfwGetKey(window,button)==GLFW_PRESS;
    }
    int getY() const {
        return y;
    }

    void setY(int y) {
        UIkit::y = y;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        UIkit::id = id;
    }

    const std::string &getTitle() const {
        return title;
    }
    void setTitle(const std::string &title) {
        UIkit::title = title;
    }

    unsigned int getHeight() const {
        return height;
    }
};
class Text{
protected:
    std::string words;
    int size;
public:
    Text(std::string words = "", int size = 0){
        this->words = words;
        this->size = size;
    }
    const std::string &getWords() const {
        return words;
    }
    void setWords(const std::string &words) {
        Text::words = words;
    }
    int getSize() const {
        return size;
    }
    void setSize(int size) {
        Text::size = size;
    }



};
#endif //OPENGUI_GUIROOT_HPP
