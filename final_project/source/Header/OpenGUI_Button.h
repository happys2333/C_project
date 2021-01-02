//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENGUI_OPENGUI_BUTTON_H
#define OPENGUI_OPENGUI_BUTTON_H
#include "GUIroot.h"
typedef void (* ButtonFun)(bool);
class CButton : UIkit{
private:
    ButtonFun f;
    static void EmptyFunc(bool OK){}
public:
    CButton(unsigned width=100,unsigned int height=50,unsigned int x=0,unsigned int y=0,std::string title="Button",ButtonFun f=EmptyFunc);

};


#endif //OPENGUI_OPENGUI_BUTTON_H
