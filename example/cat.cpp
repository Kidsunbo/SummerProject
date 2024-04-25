//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "window/window.h"
#include "graphics/object.h"
#include "graphics/light.h"
#include "graphics/pipeline.h"
#include "graphics/camera.h"



bool drawFill = false;
bool drawTexture = false;
bool drawSketch = true;
bool addDog = false;


void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_F && action == GLFW_PRESS)
    {
        drawFill=true;
        drawSketch = false;
        drawTexture = false;
    }
    if(key == GLFW_KEY_T && action == GLFW_PRESS){
        drawTexture = true;
        drawSketch = false;
    }
    if(key==GLFW_KEY_S && action==GLFW_PRESS){
        drawTexture = false;
        drawFill = false;
        drawSketch = true;
    }
    if(key==GLFW_KEY_D && action == GLFW_PRESS){
        addDog=!addDog;
    }

}

int main() {
    try {
        Kie::Window window(640, 480, "Hello Cat");
        glfwSetKeyCallback(window.getWindow(),key_callback);
        Kie::Object object;
        object.load(std::string{RESOURCE_PATH}+"/cat/cat.obj", std::string{RESOURCE_PATH}+"/cat/cat.png");
        object.setDistance(50);
        object.setOrigin(0.5f, 0.5f, 0.0f);
        object.setRotateZ(180);
        object.setRotateY(180);
        object.move(0, 10, 0);
        object.setRenderForEachTriangle(true);
        Kie::Light light(Kie::Color(255, 255, 255));
        light.setLightPos(Kie::math::Vec3D({10, 0, -1}));
        Kie::PipeLine::getInstance(window).setLight(light);

        Kie::Object dog;
        dog.load(std::string{RESOURCE_PATH}+"/dog/dog.obj", std::string{RESOURCE_PATH}+"/dog/dog.jpg");
        dog.setDistance(50);
        dog.setOrigin(0.5f, 0.5f, 0.0f);
        dog.setDrawSketch(false);
        dog.setDrawFill(true);
        dog.setDrawTexture(true);
        dog.setRotateX(90);
        dog.move(0, 7, 0);
        dog.setRenderForEachTriangle(true);


        Kie::Camera camera = Kie::PipeLine::getInstance(window).getCamera();
        window.printFPS(true);
        while (!window.shouldClose()) {
            object.setDrawSketch(drawSketch);
            object.setDrawFill(drawFill);
            object.setDrawTexture(drawTexture);

            glfwPollEvents();


            window.clear(Kie::Color(0, 0, 0));
            object.rotateY(1);

            window.draw(object);
            if (addDog) {
                dog.rotateY(1);
                window.draw(dog);
            }

            window.display();

        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}