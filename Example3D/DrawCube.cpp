//
// Created by bxs863 on 29/07/2019.
//
#include <iostream>
#include "Painter3D.h"
#include "Shape3D/Cube.h"
#include <thread>
#include <chrono>
#include <random>
using std::chrono_literals::operator""ms;

using namespace Kie;

int main(){

    Painter3D painter3D("Hello",640,480);
    Cube cube;
    cube.meshes ={

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
    painter3D.setRotateSpeed(10);
    painter3D.setDistance(3);
    std::random_device e;
    std::uniform_real_distribution<float> dis(0.0f,1.0f);
    painter3D.getRp().updateAngleY(-60);
    painter3D.getRp().updateAngleX(30);
    //painter3D.setRotateAxis(Painter3DUtil::x|Painter3DUtil::y|Painter3DUtil::z);
    std::thread t([&]() {
        while (!painter3D.getPainter().isClosed()) {
            painter3D.getLight().setStrength(0.5);
            std::this_thread::sleep_for(50ms);
            painter3D.clear(Color::from(0, 0, 0));
            painter3D.draw(cube,Kie::Color::from(150,70,200));
        }
    });
    t.detach();

    painter3D.paint();



    return 0;
}