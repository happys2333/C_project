
#include <OpenGUI_label.hpp>
#include <OpenGUI_frame.hpp>
#include <OpenGUI_Button.hpp>
#include <KeyBorad.hpp>
CLabel label2("../img/timg1.jpeg",true,200,200,500,330);
CFrame test(1000,800,0,0,"OpenGUI_frame");
bool Test1(){
    using namespace std;
    cout << "Testing1"<<endl;
    return true;
}
bool Test2(){
    test.addLable(label2);
    return true;
}
int main(){
//    test.BigScreen();
    test.setExitButton(KEY_ESCAPE);
    test.setBackgroundColor(1,1,0,0);
    CButton button("hi",50,30,800,200);
    CButton button2("hi",50,30,800,300);
    button.setBackgroundColor(0,0,0,0);
    button.SetButtonFun(Test1);
    button2.setBackgroundColor(1,1,1,1);
    button2.SetButtonFun(Test2);
    test.addButton(button);
    test.addButton(button2);
    CLabel label("../img/test.bmp",true,100,0,640,640);
    test.addLable(label);
    test.visualize();
}

