//
// Created by bxs863 on 07/08/2019.
//

// Custom
#include "Window.h"
#include "Exception/GLFWLoginException.h"

// STL
#include <thread>
#include <iostream>


void Kie::Window::clear(Kie::Color c) {
    if(buf1InBack){
        for (auto &row : _buf1) {
            for (auto &p : row) {
                p = c;
            }
        }
    }
    else{
        for (auto &row : _buf2) {
            for (auto &p : row) {
                p = c;
            }
        }
    }
}

void Kie::Window::draw(Kie::IDrawable &drawable) {
    drawable.draw(*this);
}

void Kie::Window::draw(Kie::IDrawable &&drawable) {
    drawable.draw(*this);
}

std::vector<std::vector<Kie::Color>> &Kie::Window::getBuffer() {
    if(buf1InBack) return _buf1;
    else return _buf2;
}

void Kie::Window::display() {
    if(!buf1InBack){
        _display(_buf1);
    }
    else{
        _display(_buf2);
    }
    buf1InBack = !buf1InBack;
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleepTime*1000.0f)));
}

void Kie::Window::_display(std::vector<std::vector<Color>> &_buf) {
    glfwSwapBuffers(window);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    auto width = getWidth();
    auto height = getHeight();
    for(auto i=0;i<height+1;i++){
        for(auto j = 0;j<width+1;j++) {
            glColor3f(_buf[i][j].getR(), _buf[i][j].getG(), _buf[i][j].getB());
            glVertex2f((float) (j - width / 2.0) / width * 2.0, -(float) (i - height / 2.0) / height * 2.0);
        }
    }
    glEnd();
    if(printfps){
        auto now = std::chrono::system_clock::now();
        std::cout<<"fps: "<<1000.0f/std::chrono::duration_cast<std::chrono::milliseconds>(now-time).count()<<std::endl;
        time = now;
    }
}

Kie::Window::Window(int width, int height, const char *title) {
    if(!glfwInit()) throw GLFWLoginException("GLFW init failed");
    // Set window hint
    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    window = glfwCreateWindow(width,height,title,nullptr,nullptr);
    if(window==nullptr) throw GLFWLoginException("GLFW window create failed");

    for(auto i = 0;i<=mode->height;i++){
        _buf1.emplace_back(std::vector<Color>(mode->width+1,Color(0,0,0)));
        _buf2.emplace_back(std::vector<Color>(mode->width+1,Color(0,0,0)));
    }

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    });
}

int Kie::Window::getWidth() {
    int width;
    int height;
    glfwGetWindowSize(window,&width,&height);
    return width;
}

int Kie::Window::getHeight() {
    int width;
    int height;
    glfwGetWindowSize(window,&width,&height);
    return height;
}

void Kie::Window::setFrameRate(int rate) {
    sleepTime = 1.0f/ static_cast<float>(rate);
}

bool Kie::Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

Kie::Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow *Kie::Window::getWindow() {
    return window;
}

void Kie::Window::printFPS(bool value){
    this->printfps = value;
}


