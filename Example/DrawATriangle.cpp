//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Triangle.h"


int main(){

    Kie::Window window(640,480,"Hello Triangle");
    Kie::Point p1(0.5f,0.3f,Kie::Color(1.0f,0.0f,0.0f));
    Kie::Point p2(0.0f,-0.5f,Kie::Color(0.0f,1.0f,0.0f));
    Kie::Point p3(-0.5f,0.0f,Kie::Color(0.0f,0.0f,1.0f));
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(Kie::Triangle(p1,p2,p3,true));
        window.display();
    }

    return 0;
}