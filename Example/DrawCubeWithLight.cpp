//
// Created by bxs863 on 15/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Object.h"

#include <iostream>


int main(){

    Kie::Window window(640,480,"Hello Triangle");
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

    object.setDistance(3);
    object.setOrigin(0.5f,0.5f,0.5f);
    object.setDrawSketch(true);
    object.setDrawFill(true);
    object.setRotateZ(45);
    Kie::Light light(Kie::Color(255,100,255));
    light.setLightPos(Kie::Math::Vec3D({0,0,-1}));
    Kie::PipLine::getInstance(window).setLight(light);
//    object.setRotateZ(45);
//    object.setRotateX(60);
    while(!window.shouldClose()){
        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(object);

        object.rotateY(1);
        object.rotateX(0.5);
        object.rotateZ(1);
        window.display();
    }

    return 0;
}