//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENGUI_OPENGUI_LABEL_HPP
#define OPENGUI_OPENGUI_LABEL_HPP
#include "GUIroot.hpp"
#include "Func.hpp"
class CLabel :UIkit{
private:

    class Img{
    public:
        int ImgWidth;
        int ImgHeight;
        float R;
        float G;
        float B;
        Img(int width=0, int height=0,float R=1,float G=1,float B=1);
    };
    void loadImg(const char *filename);
    int zSlider = 0;
    std::string str;
    void DrawImage(float preX,float preY);
    bool img;
    Img *_pixel;
    void DrawString(float preX,float preY);
    void DrawChar(char c);
public:
    CLabel(std::string str= "", bool img = false, unsigned int x=0, unsigned int y=0, unsigned int width=50, unsigned int height=30);
    void Draw(float preX,float preY);
    ~CLabel();
    void free();
};


#endif //OPENGUI_OPENGUI_LABEL_HPP
