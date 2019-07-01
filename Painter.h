//
// Created by bxs863 on 01/07/2019.
//

#ifndef TEST_PAINTER_H
#define TEST_PAINTER_H
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
class Painter {
    struct Color{
        int r=255;
        int g=255;
        int b=255;
    };

private:
    GLFWwindow* window;
    int width;
    int height;
    std::string title;
    std::vector<std::vector<Color>> buf;
public:

    static Color createColor(int r,int g,int b);


    Painter(const char* title,int width,int height);


    void drawPixel(int x,int y,Color c);

    void run();

    int getWidth();
    int getHeight();

};


#endif //TEST_PAINTER_H
