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
    window = glfwCreateWindow(width,height,title,nullptr,nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
}

void Painter::run() {

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        for(auto i=0;i<width+1;i++){
            for(auto j = 0;j<height+1;j++){
                std::cout<<buf[i][j].r<<"  "<<buf[i][j].g<<"  "<<buf[i][j].b<<std::endl;
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

Painter::Color Painter::createColor(int r, int g, int b) {
    return Color{r,g,b};
}

int Painter::getWidth() {
    return width;
}

int Painter::getHeight() {
    return height;
}
