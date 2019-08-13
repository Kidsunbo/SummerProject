//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Line.h"
#include <random>


int main(){

    Kie::Window window(640,480,"Hello Dot");
    Kie::Line line(true,10,10,200,200,window.getWidth(),window.getHeight());
    Kie::Point p1(0.0f,0.0f,Kie::Color(0.0f,0.0f,0.0f));
    Kie::Point p2(0.5f,0.5f);
    Kie::Line line1(p1,p2);
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(line);
        window.draw(line1);
        window.display();
    }

    return 0;
}