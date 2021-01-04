//
// Created by 开心 on 2020/12/31.
//

#ifndef OPENGUI_GUIROOT_H
#define OPENGUI_GUIROOT_H

#include <glew.h>
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
public:
    UIkit(){
        srand((unsigned)time(NULL));
        id = rand();
    }
    int getX() const {
        return x;
    }

    void setX(int x) {
        UIkit::x = x;
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
#endif //OPENGUI_GUIROOT_H
