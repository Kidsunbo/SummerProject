//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include "PainterException.h"

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







