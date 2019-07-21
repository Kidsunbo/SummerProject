//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include "PainterException.h"
#include <cmath>

#include <iostream>


using namespace Kie;


Painter::Painter(const char* title,int width,int height){
    // Initialize GLFW
    if(!glfwInit()) throw GLFWLoginException("GLFW init failed");
    // Set window hint
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif

    // Create window and load GL
    window = glfwCreateWindow(width,height,title,nullptr,nullptr);
    if(window==nullptr) throw GLFWLoginException("GLFW window create failed");
    // Create the buffer, the initial value will be the decided by the declaration of the Color class
    for(auto i = 0;i<=mode->width;i++){
        _buf.emplace_back(std::vector<Color>(mode->height+1));
    }

    // Some setting
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    });
}

void Painter::drawPixel(int x, int y, Color c) {
    if(x<_buf.size() && x>=0 && y<_buf[x].size() && y>=0)
        this->_buf[x][y] = c;
}

void Painter::drawPixel(int x, int y, int r, int g, int b) {
    drawPixel(x,y,Color::from(r, g, b));
}

void Painter::drawLine(int x1, int y1, int x2, int y2,Color c,LineAlgorithm algorithm) {
    if(algorithm==LineAlgorithm::Custom) {
        int count = (int) std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        float step1 = (float) (x2 - x1) / count;
        float step2 = (float) (y2 - y1) / count;
        for (int i = 0; i <= count; i++) {
            int x_Pos = x1 + static_cast<int>(i * step1);
            int y_Pos = y1 + static_cast<int>(i * step2);
            drawPixel(x_Pos,y_Pos,c);
        }
    }
    else if(algorithm==LineAlgorithm::DDA){
        throw NotImplementedException("Drawing line with DDA is not implemented");
    }
}

void Painter::paint() {
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        auto width = getWidth();
        auto height = getHeight();
        for(auto i=0;i<width+1;i++){
            for(auto j = 0;j<height+1;j++){
                glColor3ub(_buf[i][j].r,_buf[i][j].g,_buf[i][j].b);
                glVertex2f((float)(i-width/2.0)/width*2.0,-(float)(j-height/2.0)/height*2.0);
            }
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    closed = true;
    glfwTerminate();
}

Painter::~Painter() {
    glfwTerminate();
}

void Painter::clear(Color c) {
    for(auto& row : _buf){
        for(auto& p : row){
            p=c;
        }
    }
}

int Painter::getWidth() {
    int width;
    int height;
    glfwGetWindowSize(window,&width,&height);
    return width;
}

int Painter::getHeight() {
    int width;
    int height;
    glfwGetWindowSize(window,&width,&height);
    return height;
}


void Painter::drawTriangle(const std::vector<Pixel> &vertex,Color c) {
    if(vertex.size()<3) return;
    drawLine(vertex[0].x,vertex[0].y,vertex[1].x,vertex[1].y,c);
    drawLine(vertex[1].x,vertex[1].y,vertex[2].x,vertex[2].y,c);
    drawLine(vertex[2].x,vertex[2].y,vertex[0].x,vertex[0].y,c);
}

void Painter::setPenWidth(int width) {
    this->_width=width;
}

int Painter::getPenWidth() {
    return _width;
}

void Painter::drawCircle(int x, int y, int r,Color c) {
    // Apply Bresenham circle drawing method
    int d = static_cast<int>(1.25-r);
    drawPixel(x,y+r,c); // Top
    drawPixel(x+r,y,c); // Right
    drawPixel(x,y-r,c); // Bottom
    drawPixel(x-r,y,c); // Left
    for(int x_Pos = 0,y_Pos = r;x_Pos<=y_Pos;){
        if(d<=0) {
            d = d + 2 * x_Pos + 3;
            ++x_Pos;
            drawPixel(x_Pos+x,y_Pos+y,c);
            drawPixel(y_Pos+x,x_Pos+y,c);
            drawPixel(-x_Pos+x,y_Pos+y,c);
            drawPixel(-y_Pos+x,x_Pos+y,c);
            drawPixel(x_Pos+x,-y_Pos+y,c);
            drawPixel(y_Pos+x,-x_Pos+y,c);
            drawPixel(-x_Pos+x,-y_Pos+y,c);
            drawPixel(-y_Pos+x,-x_Pos+y,c);
        }
        else{
            d=d+2*(x_Pos-y_Pos)+5;
            ++x_Pos;
            --y_Pos;
            drawPixel(x_Pos+x,y_Pos+y,c);
            drawPixel(y_Pos+x,x_Pos+y,c);
            drawPixel(-x_Pos+x,y_Pos+y,c);
            drawPixel(-y_Pos+x,x_Pos+y,c);
            drawPixel(x_Pos+x,-y_Pos+y,c);
            drawPixel(y_Pos+x,-x_Pos+y,c);
            drawPixel(-x_Pos+x,-y_Pos+y,c);
            drawPixel(-y_Pos+x,-x_Pos+y,c);
        }
    }
}

bool Painter::isClosed() {
    return closed;
}

void Painter::drawEllipse(int x, int y, int a, int b, Color c) {
    // Apply Bresenham oval drawing method
    float d1 = b*b+a*a*(-b+0.25);
    bool d2NoValue = true;
    float d2 =0;

    drawPixel(x,y+b,c); // Top
    drawPixel(x,y-b,c); // Bottom
    for(int x_Pos = 0,y_Pos=b;x_Pos<=a && y_Pos>0;){
        if(2*a*a*(y_Pos-0.5)>2*b*b*(x_Pos+1)){
            if(d1<=0){
                d1 = d1+b*b*(2*x_Pos+3);
                x_Pos++;
            }
            else{
                d1=d1+b*b*(2*x_Pos+3)+a*a*(-2*y_Pos+2);
                x_Pos++;
                y_Pos--;
            }
            drawPixel(x+x_Pos,y+y_Pos,c);
            drawPixel(x+x_Pos,y-y_Pos,c);
            drawPixel(x-x_Pos,y+y_Pos,c);
            drawPixel(x-x_Pos,y-y_Pos,c);
        }
        else{
            if(d2NoValue){
                d2 = b*b*(x_Pos+0.5)*(x_Pos+0.5)+a*a*(y_Pos-1)*(y_Pos-1)-a*a*b*b;
                d2NoValue = false;
            }
            if(d2<=0){
                d2 = b*b*(2*x_Pos+2)+a*a*(-2*y_Pos+3);
                x_Pos++;
                y_Pos--;
            }
            else{
                d2 =d2+a*a*(-2*y_Pos+3);
                y_Pos--;
            }
            drawPixel(x+x_Pos,y+y_Pos,c);
            drawPixel(x+x_Pos,y-y_Pos,c);
            drawPixel(x-x_Pos,y+y_Pos,c);
            drawPixel(x-x_Pos,y-y_Pos,c);
        }
    }


}
















