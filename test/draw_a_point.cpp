//
// Created by bxs863 on 07/08/2019.
//

#include "window/window.h"
#include "graphics/point.h"


int main(){

    Kie::Window window(640,480,"Hello Dot");
    std::vector<Kie::Point> ps;
    for(float i=0.0f;i<=0.9f;i+=0.0001f){
        ps.emplace_back(i,0.9-i, 0);
    }
    while(!window.shouldClose()){

        glfwPollEvents();
        for(auto& i: ps)
        window.draw(i);
        window.display();
    }

    return 0;
}