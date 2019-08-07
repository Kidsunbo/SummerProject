//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Point.h"

int main(){

    Kie::Window window(640,480,"Hello Dot");

    Kie::Point point(10,20);
    Kie::Point point1(0.1f,0.5f);
    while(!window.shouldClose()){

        glfwPollEvents();

        window.clear(Kie::Color(0,0,0));
        window.draw(point);
        window.draw(point1);
        window.display();
    }

    return 0;
}