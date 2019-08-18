//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Object.h"

#include <iostream>


int main(){

    Kie::Window window(640,480,"Hello Cube");
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
    object.setDrawFill(false);
    bool directionZ = false;
    bool directionX = false;
    bool directionY = false;
    window.setFrameRate(20);
    while(!window.shouldClose()){
        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(object);
        if(object.getPosition().getZ()<0.1) directionZ = true;
        if(object.getPosition().getZ()>30) directionZ = false;
        if(directionZ)object.move(0,0,0.1);
        else object.move(0,0,-0.1);

        if(object.getPosition().getX()<-1) directionX = true;
        if(object.getPosition().getX()>1) directionX = false;
        if(directionX)object.move(0.05,0,0);
        else object.move(-0.05,0,0);

        if(object.getPosition().getY()<-1) directionY = true;
        if(object.getPosition().getY()>1) directionY = false;
        if(directionY)object.move(0,0.1,0);
        else object.move(0,-0.1,0);

        object.rotateY(1);
        object.rotateX(0.5);
        object.rotateZ(1);
        window.display();
    }

    return 0;
}