//
// Created by bxs863 on 19/08/2019.
//

#include "window/window.h"
#include "graphics/triangle.h"


int main(){
    Kie::Window window(640,480,"Hello Two Triangle");
    Kie::Point p1(0.0f,-0.5f,0,Kie::Color(1.0f,0.0f,0.0f));
    Kie::Point p2(0.5f,0.5f,0,Kie::Color(0.0f,1.0f,0.0f));
    Kie::Point p3(-0.5f,0.0f,0,Kie::Color(0.0f,0.0f,1.0f));
    Kie::Triangle tri(p1,p2,p3,true);
    Kie::Point pp1(0.0f,0.5f,1.0,Kie::Color(1.0f,0.0f,0.0f));
    Kie::Point pp2(0.5f,0.0f,-1.0,Kie::Color(0.0f,1.0f,0.0f));
    Kie::Point pp3(-0.5f,0.5f,0,Kie::Color(0.0f,0.0f,1.0f));
    Kie::Triangle tri1(pp1,pp2,pp3,true);
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));

        window.draw(tri);
        window.draw(tri1);

        window.display();
    }

    return 0;
}