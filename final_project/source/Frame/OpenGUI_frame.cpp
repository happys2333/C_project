//
// Created by 开心 on 2020/12/24.
//
#include "../Header/OpenGUI_frame.h"

#include <utility>

CFrame::CFrame(unsigned int x, unsigned int y, std::string title) {
    this->x = x;
    this->y = y;
    this->title = std::move(title);
}

void CFrame::mainloop() {

}
