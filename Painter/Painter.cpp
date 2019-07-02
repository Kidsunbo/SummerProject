//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include "PainterException.h"
#include <cmath>


using namespace Kie;

Painter::Color Painter::createColor(int r, int g, int b) {
    return Color{r,g,b};
}

Painter::Painter(const char* title,int width,int height){
    // Initialize GLFW
    if(!glfwInit()) throw GLFWLoginException("GLFW init failed");
    // Set window hint
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    // Create window and load GL
    window = glfwCreateWindow(width,height,title,nullptr,nullptr);

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

void Painter::drawPixel(int x, int y, Painter::Color c) {
    this->_buf[x][y] = c;
}

void Painter::drawPixel(int x, int y, int r, int g, int b) {
    this->_buf[x][y] = createColor(r,g,b);
}

void Painter::drawLine(int x1, int y1, int x2, int y2,Color c) {
        int count = (int) std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        float step1 = (float) (x2 - x1) / count;
        float step2 = (float) (y2 - y1) / count;
        for (int i = 0; i <= count; i++) {
            drawPixel(x1 + i * step1, y1 + i * step2,c);
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
}

Painter::~Painter() {
    glfwTerminate();
}

void Painter::clear(Painter::Color c) {
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







