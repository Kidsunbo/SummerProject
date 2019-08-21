//
// Created by bxs863 on 15/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Object.h"

#include <random>


int main(){

    Kie::Window window(640,480,"Hello Cube with light");

    Kie::Object object = {

            // SOUTH
            { 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

            // EAST
            { 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
            { 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

            // NORTH
            { 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
            { 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

            // WEST
            { 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

            // TOP
            { 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
            { 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

            // BOTTOM
            { 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
            { 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },

    };

    Kie::Camera camera;
    camera.setPosition({0,0,-10});
    Kie::PipeLine::getInstance(window).setCamera(camera);
    object.setPosition({0,0,0});
    object.setOrigin(0.5f,0.5f,0.5f);
    object.setDrawSketch(true);
    object.setDrawFill(true);
//    object.setRotateZ(45);
    object.setRenderForEachTriangle(true);
    Kie::Light light(Kie::Color(255,100,255));
    light.setLightPos(Kie::Math::Vec3D({0,0,10}));
    Kie::PipeLine::getInstance(window).setLight(light);
//    object.setRotateZ(45);
//    object.setRotateX(60);
    object.turnTheLight();
    //window.printFPS(true);
    while(!window.shouldClose()){

        if(glfwGetKey(window.getWindow(),GLFW_KEY_RIGHT)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(0.1, 0, 0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_LEFT)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(-0.1, 0, 0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_UP)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(0, 0.1, 0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_DOWN)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(0, -0.1, 0);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_PAGE_UP)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(0, 0, 0.1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_PAGE_DOWN)==GLFW_PRESS){
            Kie::PipeLine::getInstance(window).getCamera().move(0, 0, -0.1);
        }


        float radius = 5.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        Kie::PipeLine::getInstance(window).getCamera().setPosition(camX, 0.0, camZ);

//        Kie::Math::Vec3D front = {0.0f, 0.0f, -1.0f};
//        Kie::PipeLine::getInstance(window).getCamera().setTarget(Kie::PipeLine::getInstance(window).getCamera().getPosition()+front);

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(object);

        object.rotateY(1);
//        object.rotateX(0.5);
//        object.rotateZ(1);
        window.display();
    }

    return 0;
}