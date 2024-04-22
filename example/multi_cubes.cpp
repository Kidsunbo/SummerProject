//
// Created by bxs863 on 19/08/2019.
//


#include <random>
#include "window/window.h"
#include "graphics/object.h"
#include "graphics/light.h"
#include "graphics/pipeline.h"
#include "graphics/camera.h"

bool autoRotate = true;
bool changeColor = false;
float radius = 10.0f;

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        autoRotate=!autoRotate;
    }
    if(key == GLFW_KEY_C && action==GLFW_PRESS){
        changeColor = true;
    }
}


int main() {

    std::random_device e;
    std::uniform_int_distribution<int> d(0,255);


    Kie::Window window(640, 480, "Hello Many Cubes");
    glfwSetKeyCallback(window.getWindow(),key_callback);

    float speed = 0.5f;
    float rotateSpeed = 0.05f;
    float angle = 0.0f;

    Kie::Object object = {

            // SOUTH
            {0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f},

            // EAST
            {1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f},

            // NORTH
            {1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f},
            {1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f},

            // WEST
            {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f},

            // TOP
            {0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f},
            {0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f},

            // BOTTOM
            {1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},

    };
    std::vector<Kie::Object> vec;
    for(int i=0;i<6;i++){
        vec.push_back(object);
    }
    for(auto& i:vec){
        i.setDrawFill(true);
        i.setOrigin(0.5f,0.5f,0.5f);
    }
    vec[0].move(-2,0.5,0);
    vec[1].move(-1.7,2,0);
    vec[2].move(-3,1.2,0);
    vec[3].move(0,0,0);
    vec[4].move(0.6,0.7,0);
    vec[5].move(1.7,-0.5,0);




    Kie::Camera& camera = Kie::PipeLine::getInstance(window).getCamera();
    Kie::Light& light = Kie::PipeLine::getInstance(window).getLight();
    camera.setPosition(0,0,-10);
    light.setLightPos(Kie::math::Vec3D{0,0,-100});

    Kie::math::Vec3D cameraFront = {0,0,1};
    Kie::math::Vec3D cameraUp = {0,1,0};
    while (!window.shouldClose()) {

        if(!autoRotate) {
            if (glfwGetKey(window.getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() - Kie::math::Vec3D{0, 1, 0});
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() + Kie::math::Vec3D{0, 1, 0});
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS) {
            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS) {
            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() + cameraFront * speed);
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() - cameraFront * speed);
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() + cameraFront.crossProduct(cameraUp).normalize() * speed);
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() - cameraFront.crossProduct(cameraUp).normalize() * speed);
                camera.setTarget(camera.getPosition()+cameraFront);
            }
        }
        if(changeColor){
            Kie::PipeLine::getInstance(window).getLight().setLightColor(Kie::Color(d(e), d(e), d(e)));
            changeColor = false;
        }



        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));

        if(autoRotate) {
            camera.setTarget(Kie::math::Vec3D{0,0,0});
            float camX = sin(angle) * radius;
            float camZ = cos(angle) * radius;
            Kie::PipeLine::getInstance(window).getCamera().setPosition(camX, 0.0, camZ);
            cameraFront = (camera.getTarget()-camera.getPosition()).normalize();
            angle+=rotateSpeed;
        }

        for(auto& i : vec){
            i.rotateY(1);
            i.rotateX(1);
            i.rotateZ(1);
            window.draw(i);
        }

        window.display();
    }

    return 0;
}
