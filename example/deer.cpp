//
// Created by bxs863 on 15/08/2019.
//

#include "window/window.h"
#include "graphics/object.h"
#include "graphics/light.h"
#include "graphics/pipeline.h"
#include "graphics/camera.h"
#include <random>

bool drawFill = false;
bool changeLightColor = false;
bool resetColor = false;
bool useLight = false;

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
    if(key==GLFW_KEY_L && action ==GLFW_PRESS){
        useLight=true;
    }
}

int main() {

    std::random_device e;
    std::uniform_real_distribution<float> d(0.0f,1.0f);

    float speed = 0.5f;
    Kie::Window window(640, 480, "Hello Deer");
    glfwSetKeyCallback(window.getWindow(),key_callback);
    Kie::Object object;
    object.load(std::string{RESOURCE_PATH}+"/deer/deer.obj");
    object.setScale(0.01);
    object.setDistance(10);
    object.setOrigin(0, 0, 0);
    object.setRotateZ(180);
    object.move(0,-0.5,0);
    object.setDrawSketch(true);
    object.setRenderForEachTriangle(true);
    Kie::Light light(Kie::Color(255, 255, 255));
    light.setLightPos(Kie::math::Vec3D({10, 0, -1}));
    Kie::PipeLine::getInstance(window).setLight(light);
    Kie::PipeLine::getInstance(window).getCamera().setTarget({0, 0, 1000});
    window.printFPS(true);
    Kie::Camera& camera = Kie::PipeLine::getInstance(window).getCamera();
    camera.setPosition(0,0,-10);
    object.turnTheLight();
    Kie::math::Vec3D cameraFront = {0,0,1};
    Kie::math::Vec3D cameraUp = {0,1,0};
    while (!window.shouldClose()) {
        object.setDrawFill(drawFill);
        if(useLight){
            object.turnTheLight();
            useLight = false;
        }
        if (glfwGetKey(window.getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() - Kie::math::Vec3D{0, 0.5f, 0});
            camera.setTarget(camera.getPosition() + cameraFront);
        } else if (glfwGetKey(window.getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
            camera.setTarget(camera.getPosition() + cameraFront);
            camera.setPosition(camera.getPosition() + Kie::math::Vec3D{0, 0.5f, 0});
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
            Kie::PipeLine::getInstance(window).getLight().setLightColor(Kie::Color(d(e), d(e), d(e)));
            changeLightColor = false;
        }
        if(resetColor){
            Kie::PipeLine::getInstance(window).getLight().setLightColor(Kie::Color(255, 255, 255));
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