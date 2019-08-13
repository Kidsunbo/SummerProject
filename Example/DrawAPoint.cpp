//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Point.h"
#include <random>


int main(){

    Kie::Window window(640,480,"Hello Dot");
    std::vector<Kie::Point> ps;
    for(int i=10;i<=200;i++){
        ps.emplace_back(true,i,i,window.getWidth(),window.getHeight());
    }
    while(!window.shouldClose()){

        glfwPollEvents();
        for(auto& i: ps)
        window.draw(i);
        window.display();
    }

    return 0;
}