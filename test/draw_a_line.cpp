//
// Created by bxs863 on 07/08/2019.
//

#include "graphics/line.h"
#include "window/window.h"



int main(){

    Kie::Window window(640,480,"Hello Line");
    Kie::Line line(-1,1,1,-1);
    Kie::Point p1(0.0f,0.0f,0.0f,Kie::Color(0.0f,0.0f,0.0f));
    Kie::Point p2(0.5f,0.5f,0.0f);
    Kie::Line line1(p1,p2);
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
       // window.draw(line);
        window.draw(line1);
        window.display();
    }

    return 0;
}