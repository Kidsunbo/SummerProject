//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "Window/Window.h"
#include "Graphics/Object.h"


int main() {
    try {
        Kie::Window window(640, 480, "Hello Cat");
        Kie::Object object;
        object.load("../Resource/cat.obj");
        object.setDistance(10);
        object.setOrigin(0.5f, 0.5f, 0.5f);
        object.setDrawSketch(true);
        object.setDrawFill(true);
        object.move(0, 0, 0);
        object.setRenderForEachTriangle(true);
        Kie::Light light(Kie::Color(255, 100, 255));
        light.setLightPos(Kie::Math::Vec3D({10, 0, -1}));
        Kie::PipLine::getInstance(window).setLight(light);
        window.printFPS(true);
        while (!window.shouldClose()) {
            glfwPollEvents();
            window.clear(Kie::Color(0, 0, 0));
            window.draw(object);
            object.rotateY(1);
            object.rotateX(0.5);
            object.rotateZ(1);
            window.display();
        }
    }
    catch (std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}