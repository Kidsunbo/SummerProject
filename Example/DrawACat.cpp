//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "Window/Window.h"
#include "Graphics/Object.h"


int main() {

    Kie::Window window(640, 480, "Hello Cat");
    Kie::Object object;
    object.load("cat.obj");
    object.setDistance(100);
    object.setOrigin(-55.0f, -40.0f, -10.0f);
    object.setDrawSketch(true);
    object.setDrawFill(false);
    object.move(0, -1, 0);
    Kie::Light light(Kie::Color(255, 100, 255));
    light.setLightPos(Kie::Math::Vec3D({0, 0, -1}));
    Kie::PipLine::getInstance(window).setLight(light);

    while (!window.shouldClose()) {
        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));
        window.draw(object);
        //object.rotateX(0.5);
        object.rotateY(1);
        //object.rotateZ(1);
        window.display();
    }

    return 0;
}