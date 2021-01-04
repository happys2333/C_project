//
// Created by 开心 on 2020/12/24.
//

#include "../Header/OpenGUI_label.hpp"


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
        DrawImage( preX, preY);
    }else{
        return;
        DrawString( preX, preY);
    }
}

#include <opencv2/opencv.hpp>
void CLabel::loadImg(const char *filename) {
    using namespace cv;
    Mat img = imread(filename);
//    transpose(img, img);
//    flip(img,img,1);
    int maxH = img.rows;
    int max_width = img.cols;

    for (int i = 0; i < width * height;i++){
        _pixel[i] =Img(max_width,maxH,1,1,1);
    }
    for (int i =0;i<height;i++){
        if(i>=maxH){
            continue;
        }
        for (int j=0;j<width;j++){
            if(j>=max_width){
                continue;
            }
            _pixel[i*width+j].R = (float)img.at<Vec3b>(i,j)[2]/(float)255;
            _pixel[i*width+j].G = (float)img.at<Vec3b>(i,j)[1]/(float)255;
            _pixel[i*width+j].B = (float)img.at<Vec3b>(i,j)[0]/(float)255;
        }
    }
    img.release();
}

CLabel::CLabel(std::string str, bool img, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    this ->str = str;
    this->img = img;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    if(img){
        _pixel = new Img[width * height];
        if(zSlider == 0)
        {
            loadImg(str.c_str());
            zSlider ++;
        }
    }
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
    FT_UInt		charIdx;
    error = FT_Init_FreeType(&library);
    error = FT_New_Face(library, "/System/Library/Fonts/STHeiti Light.ttc", 0, &face);


    if(error){
        printf("error in creating font\n");
        exit(1);
    }


}

CLabel::~CLabel() {
}

void CLabel::free() {
    if(img) {
        delete _pixel;
    }
    str = "";
}


CLabel::Img::Img(int width, int height, float R, float G, float B) {
    ImgWidth = width;
    ImgHeight = height;
    this-> R = R;
    this-> G = G;
    this-> B = B;
}
