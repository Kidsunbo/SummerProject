//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Triangle.h"


int main(){

    Kie::Window window(640,480,"Hello Triangle");
    Kie::Point p1(0.0f,-0.5f,0,Kie::Color(1.0f,0.0f,0.0f));
    Kie::Point p2(0.5f,0.5f,0,Kie::Color(0.0f,1.0f,0.0f));
    Kie::Point p3(-0.5f,0.0f,0,Kie::Color(0.0f,0.0f,1.0f));
    Kie::Triangle tri(p1,p2,p3,true);
    Kie::Point pp1(0.0f,0.5f,1.0,Kie::Color(1.0f,0.0f,0.0f));
    Kie::Point pp2(0.5f,0.0f,-1.0,Kie::Color(0.0f,1.0f,0.0f));
    Kie::Point pp3(-0.5f,0.5f,0,Kie::Color(0.0f,0.0f,1.0f));
    Kie::Triangle tri1(pp1,pp2,pp3,true);
    window.setFrameRate(100);
    window.printFPS(true);
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(tri);
        window.draw(tri1);

        //window.draw(Kie::Triangle(Kie::Point(0,0.249981284f,0),Kie::Point(0.187485978,0.249981284,0.0f),Kie::Point(0.0f,0.0f,0),true));
        window.display();
    }

    return 0;
}