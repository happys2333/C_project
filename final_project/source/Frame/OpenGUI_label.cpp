//
// Created by 开心 on 2020/12/24.
//

#include "../Header/OpenGUI_label.hpp"
#include <algorithm>

#include <freetype/freetype.h>
#include <freetype/ftglyph.h>

void CLabel::DrawImage(float preX,float preY) {
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    Img temp;
    float beginX = (-1+x*preX),beginY = (1-preY*y);
    for(int i = 0; i <height;i++){
        for (int j=0;j<width;j++){
            temp = _pixel[i*width+j];
            glColor3f(temp.R,temp.G,temp.B);
            glVertex2f(beginX+preX*(float)j,beginY-preY*(float)i);
        }
    }
    glEnd();
}

void CLabel::Draw(float preX,float preY) {
    if(img){
        DrawImage(preX, preY);
    }
}

#include <opencv2/opencv.hpp>
void CLabel::loadImg(const char *filename) {
    using namespace cv;
    Mat img = imread(filename);
    if (img.empty()) {
        std::cerr << "Failed to load image: " << filename << std::endl;
        return;
    }
    int maxH = img.rows;
    int max_width = img.cols;

    for (int i = 0; i < height; i++){
        if(i >= maxH) continue;
        for (int j = 0; j < width; j++){
            if(j >= max_width) continue;
            _pixel[i*width+j].R = (float)img.at<Vec3b>(i,j)[2]/(float)255;
            _pixel[i*width+j].G = (float)img.at<Vec3b>(i,j)[1]/(float)255;
            _pixel[i*width+j].B = (float)img.at<Vec3b>(i,j)[0]/(float)255;
        }
    }
    img.release();
}

CLabel::CLabel(std::string str, bool img, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    this->str = str;
    this->img = img;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    if(img){
        _pixel = new Img[width * height]();
        if(zSlider == 0)
        {
            loadImg(str.c_str());
            zSlider++;
        }
    }
}

CLabel::CLabel(const CLabel& other)
    : UIkit(other), str(other.str), img(other.img), zSlider(other.zSlider), _pixel(nullptr) {
    if (img && other._pixel) {
        _pixel = new Img[width * height];
        std::copy(other._pixel, other._pixel + width * height, _pixel);
    }
}

CLabel& CLabel::operator=(const CLabel& other) {
    if (this == &other) return *this;
    UIkit::operator=(other);
    delete[] _pixel;
    _pixel = nullptr;
    str = other.str;
    img = other.img;
    zSlider = other.zSlider;
    if (img && other._pixel) {
        _pixel = new Img[width * height];
        std::copy(other._pixel, other._pixel + width * height, _pixel);
    }
    return *this;
}

#include <ft2build.h>
#include FT_FREETYPE_H
void CLabel::DrawChar(char c){
    switch(c){

    }
}
void CLabel::DrawString(float preX,float preY) {
    FT_Library	library;
    FT_Face		face;
    FT_Error	error;
    error = FT_Init_FreeType(&library);
    error = FT_New_Face(library, "/System/Library/Fonts/STHeiti Light.ttc", 0, &face);

    if(error){
        printf("error in creating font\n");
        return;
    }
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

CLabel::~CLabel() {
    if (_pixel) {
        delete[] _pixel;
        _pixel = nullptr;
    }
}

void CLabel::free() {
    if (_pixel) {
        delete[] _pixel;
        _pixel = nullptr;
    }
    img = false;
    str = "";
}


CLabel::Img::Img(int width, int height, float R, float G, float B) {
    ImgWidth = width;
    ImgHeight = height;
    this-> R = R;
    this-> G = G;
    this-> B = B;
}
