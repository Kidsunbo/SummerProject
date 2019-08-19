//
// Created by bxs863 on 19/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Object.h"

#include <random>


bool autoRotate = true;

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        autoRotate=!autoRotate;
    }
}


int main() {

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
    //vec[1].move(-1.7,2,0);
    //vec[2].move(-3,1.2,0);
    //vec[3].move(0,0,0);
    //vec[4].move(0.6,0.7,0);
    //vec[5].move(1.7,-0.5,0);
//    vec[0].move(-20,5,0);
//    vec[1].move(-7,-4,0);
//    vec[2].move(-3,12,0);
//    vec[3].move(0,0,0);
//    vec[4].move(0.6,7,0);
//    vec[5].move(17,-5,0);



    Kie::Camera& camera = Kie::PipLine::getInstance(window).getCamera();
    Kie::Light& light = Kie::PipLine::getInstance(window).getLight();
    camera.setPosition(0,0,-100);
    light.setLightPos(Kie::Math::Vec3D{0,0,-100});

    Kie::Math::Vec3D cameraFront = {0,0,1};
    Kie::Math::Vec3D cameraUp = {0,1,0};
    while (!window.shouldClose()) {

        if(!autoRotate) {
            if (glfwGetKey(window.getWindow(), GLFW_KEY_UP) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() - Kie::Math::Vec3D{0, 1, 0});
                camera.setTarget(camera.getPosition()+cameraFront);

            } else if (glfwGetKey(window.getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS) {
                camera.setPosition(camera.getPosition() + Kie::Math::Vec3D{0, 1, 0});
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


        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));

        if(autoRotate) {
            camera.setTarget(Kie::Math::Vec3D{0,0,0});
            float radius = 10.0f;
            float camX = sin(angle) * radius;
            float camZ = cos(angle) * radius;
            Kie::PipLine::getInstance(window).getCamera().setPosition(camX, 0.0, camZ);
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
