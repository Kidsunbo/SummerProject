//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "window/window.h"
#include "graphics/object.h"
#include "graphics/light.h"
#include "graphics/pipeline.h"


int main() {
    try {
        Kie::Window window(640, 480, "Hello Cat");

        Kie::Object object;
        object.load(std::string{RESOURCE_PATH}+"/cat/cat.obj", std::string{RESOURCE_PATH}+"/cat/cat.png");
        object.setDistance(100);
        object.setOrigin(0.5f, 0.5f, 0.0f);
        object.setDrawSketch(false);
        object.setDrawFill(true);
        object.setDrawTexture(true);
        object.setRotateZ(180);
        object.setRotateY(180);
        object.move(0, -0.3, 0);
        object.setRenderForEachTriangle(true);
        Kie::Light light(Kie::Color(255, 255, 255));
        light.setLightPos(Kie::math::Vec3D({10, 0, -1}));
        Kie::PipeLine::getInstance(window).setLight(light);
        window.printFPS(true);
        while (!window.shouldClose()) {
            glfwPollEvents();
            window.clear(Kie::Color(0, 0, 0));

            window.draw(object);

//            object.rotateY(1);
//        object.rotateX(0.5);
//        object.rotateZ(1);

            window.display();

        }
    }
    catch (std::exception& e){
        std::cout<<e.what()<<std::endl;
    }

    return 0;
}