//
// Created by 开心 on 2020/12/24.
//

#ifndef OPENGUI_OPENGUI_LABEL_HPP
#define OPENGUI_OPENGUI_LABEL_HPP
#include "GUIroot.hpp"
#include "Func.hpp"
class CLabel :UIkit{
private:
    int char_font;
    typedef struct{
        GLsizei width;
        GLsizei height;
        GLenum format;
        GLint internalFormat;
        GLuint id;
        GLubyte *texels;
    }gl_texture_t;

    void loadImg(const char *filename);
    int zSlider = 0;
    wchar_t *str;

    bool img = false;

    void DrawImage();
    unsigned char *_pixel;

public:
    CLabel(wchar_t *str= nullptr, bool img = false, unsigned int x=0, unsigned int y=0, unsigned int width=50, unsigned int height=30);
    void Draw();

};


#endif //OPENGUI_OPENGUI_LABEL_HPP
