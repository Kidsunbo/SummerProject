//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Point.h"
#include <random>


int main(){

    Kie::Window window(640,480,"Hello Dot");

    std::random_device d;
    std::uniform_int_distribution<int> e(0,640);
    Kie::Point point(true,639,200,window.getWidth(),window.getHeight());
    Kie::Point point1(0.5f,0.5f,Kie::Color(255,255,255));
    while(!window.shouldClose()){

        glfwPollEvents();
        point.setPosition(e(d),e(d),0);
        point1.setPosition(e(d),e(d),0);

        //window.clear(Kie::Color(0,0,0));
        window.draw(point);
        window.draw(point1);
        window.display();
    }

    return 0;
}