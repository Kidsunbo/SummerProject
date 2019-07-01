//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include <exception>
#include <iostream>
Painter::Painter(const char* title,int width,int height):title(title),width(width),height(height){
    for(auto i = 0;i<=width;i++){
        buf.emplace_back(std::vector<Color>(height+1));
    }
    auto r = glfwInit();
    if(!r) throw std::exception();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
    window = glfwCreateWindow(width,height,title,nullptr,nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
}

void Painter::paint() {

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        for(auto i=0;i<width+1;i++){
            for(auto j = 0;j<height+1;j++){
                glColor3ub(buf[i][j].r,buf[i][j].g,buf[i][j].b);
                glVertex2f((float)(i-width/2.0)/width*2.0,-(float)(j-height/2.0)/height*2.0);
            }
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
}


void Painter::drawPixel(int x, int y, Color c) {
    buf[x][y] = c;
}
void Painter::drawPixel(int x, int y, int r, int g, int b) {
    buf[x][y] = createColor(r,g,b);
}



Painter::Color Painter::createColor(int r, int g, int b) {
    return Color{r,g,b};
}

int Painter::getWidth() {
    return width;
}

int Painter::getHeight() {
    return height;
}

void Painter::drawLine(int x1, int y1, int x2, int y2, bool smooth) {
    if(!smooth){
        if(x1==x2){
            auto _min = y1>y2?y2:y1;
            auto _max = y1>y2?y1:y2;
            for(auto i=_min;i<=_max;i++){
                drawPixel(x1,i);
            }
        }
        else {
            float step = (float) (y2 - y1) / (x2 - x1);
            auto _min_x = x1>x2?x2:x1;
            auto _max_x = x1>x2?x1:x2;
            auto newY1 = _min_x==x1?y1:y2;
            for(auto i = _min_x;i<=_max_x;i++){
                int newY = newY1+step*(i-_min_x);
                drawPixel(i,newY);
            }
        }
    }

    // Smooth version is to be continued.
}

void Painter::clear(Painter::Color c) {
    for(auto& row : buf){
        for(auto& p : row){
            p=c;
        }
    }
}


