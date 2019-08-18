//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "Window/Window.h"
#include "Graphics/Object.h"


int main() {
    Kie::Window window(640, 480, "Hello Cat");

    Kie::Object object;
    object.load("../../Resource/deer/deer.obj");
    object.setDistance(1000);
    object.setOrigin(0, 0, 0);
    object.setDrawSketch(true);
    object.setDrawFill(false);
    object.setDrawTexture(false);
    object.setRenderForEachTriangle(true);
    Kie::Light light(Kie::Color(255, 255, 255));
    light.setLightPos(Kie::Math::Vec3D({10, 0, -1}));
    Kie::PipLine::getInstance(window).setLight(light);
    window.printFPS(true);
    while (!window.shouldClose()) {

        if(glfwGetKey(window.getWindow(),GLFW_KEY_W)==GLFW_PRESS){
            object.move(0,0.01,0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_S)==GLFW_PRESS){
            object.move(0,-0.01f,0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_UP)==GLFW_PRESS){
            object.rotateX(0.5);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_DOWN)==GLFW_PRESS){
            object.rotateX(-0.5);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_LEFT)==GLFW_PRESS){
            object.rotateY(-1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_RIGHT)==GLFW_PRESS){
            object.rotateY(1);
        }

        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));

        window.draw(object);

//        object.rotateY(1);
//        object.rotateX(0.5);
//        object.rotateZ(1);

        window.display();

    }

    return 0;
}