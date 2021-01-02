//
// Created by 开心 on 2020/12/24.
//

#include "../Header/OpenGUI_Button.h"

CButton::CButton(unsigned int width, unsigned int height, unsigned int x, unsigned int y, std::string title,
                 ButtonFun f) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->title = title;
    this->f = f;
}
