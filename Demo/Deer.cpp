//
// Created by bxs863 on 15/08/2019.
//

#include <iostream>
#include "Window/Window.h"
#include "Graphics/Object.h"
#include <random>

bool drawFill = false;
bool changeLightColor = false;
bool resetColor = false;


void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_F && action == GLFW_PRESS)
    {
        drawFill=!drawFill;
    }
    if(key == GLFW_KEY_C && action == GLFW_PRESS){
        changeLightColor=true;
    }
    if(key==GLFW_KEY_R && action==GLFW_PRESS){
        resetColor = true;
    }
}

int main() {

    std::random_device e;
    std::uniform_real_distribution<float> d(0.0f,1.0f);

    float speed = 100.0f;
    Kie::Window window(640, 480, "Hello Deer");
    glfwSetKeyCallback(window.getWindow(),key_callback);
    Kie::Object object;
    object.load("Resource/deer/deer.obj");
    object.setDistance(1000);
    object.setOrigin(0, 0, 0);
    object.setRotateZ(180);
    object.move(0,-0.5,0);
    object.setDrawSketch(true);
    object.setRenderForEachTriangle(true);
    Kie::Light light(Kie::Color(255, 255, 255));
    light.setLightPos(Kie::Math::Vec3D({10, 0, -1}));
    Kie::PipLine::getInstance(window).setLight(light);
    Kie::PipLine::getInstance(window).getCamera().setTarget({0,0,1000});
    window.printFPS(true);
    Kie::Camera& camera = Kie::PipLine::getInstance(window).getCamera();
    camera.setPosition(0,0,-10);

    Kie::Math::Vec3D cameraFront = {0,0,1};
    Kie::Math::Vec3D cameraUp = {0,1,0};
    while (!window.shouldClose()) {
        object.setDrawFill(drawFill);

        if (glfwGetKey(window.getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() - Kie::Math::Vec3D{0, 100, 0});
            camera.setTarget(camera.getPosition() + cameraFront);
        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() + Kie::Math::Vec3D{0, 100, 0});
            camera.setTarget(camera.getPosition() + cameraFront);

        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {

        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {

        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() + cameraFront * speed);
            camera.setTarget(camera.getPosition() + cameraFront);


        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() - cameraFront * speed);
            camera.setTarget(camera.getPosition() + cameraFront);


        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() + cameraFront.crossProduct(cameraUp).normalize() * speed);
            camera.setTarget(camera.getPosition() + cameraFront);


        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() - cameraFront.crossProduct(cameraUp).normalize() * speed);
            camera.setTarget(camera.getPosition() + cameraFront);

        }

        if(changeLightColor){
            Kie::PipLine::getInstance(window).getLight().setLightColor(Kie::Color(d(e),d(e),d(e)));
            changeLightColor = false;
        }
        if(resetColor){
            Kie::PipLine::getInstance(window).getLight().setLightColor(Kie::Color(255,255,255));
            resetColor = false;
        }

        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));

        window.draw(object);

        object.rotateY(1);


        window.display();

    }

    return 0;
}