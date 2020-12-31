//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENUI_OPENGUI_FRAME_H
#define OPENUI_OPENGUI_FRAME_H
#include "GUIroot.h"
#include <string>

class CFrame : UIkit {





    public:
    CFrame(unsigned int x=0,unsigned int y=0,std::string title="OpenGUI_frame");
    void mainloop();
    void add()

};

#endif //OPENUI_OPENGUI_FRAME_H
