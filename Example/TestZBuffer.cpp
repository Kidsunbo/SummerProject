//
// Created by bxs863 on 19/08/2019.
//

#include <algorithm>
#include "Window/Window.h"
#include "Graphics/Object.h"



int main() {
    Kie::Window window(640, 480, "Hello Cube");
    float angle = 0.0f;
    float speed = 0.01f;

    Kie::Object object1 = {
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

    Kie::Object object2 = object1;

    std::vector<Kie::Object> vec{object1,object2};
    vec[0].setPosition(0,0,3);
    vec[1].setPosition(0,0,6);

    vec[0].setDrawFill(true);
    vec[1].setDrawFill(true);
    vec[0].setRotateX(0);
    vec[1].setRotateX(0);

    Kie::PipLine::getInstance(window).getCamera().setPosition(0.0f,0.0f,16.0);
    Kie::PipLine::getInstance(window).setLight(Kie::Light(Kie::Color(255,255,255),Kie::Math::Vec3D({0.0f,0.0f,130.0f})));

    while (!window.shouldClose()) {

        if(glfwGetKey(window.getWindow(),GLFW_KEY_UP)==GLFW_PRESS){
            auto temp = std::min(Kie::PipLine::getInstance(window).getLight().getAmbientStrength()+0.01,1.0);
            Kie::PipLine::getInstance(window).getLight().setAmbientStrength(temp);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_DOWN)==GLFW_PRESS){
            auto temp = std::max(Kie::PipLine::getInstance(window).getLight().getAmbientStrength()-0.01,0.0);
            Kie::PipLine::getInstance(window).getLight().setAmbientStrength(temp);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_LEFT)==GLFW_PRESS){
            angle+=speed;
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_RIGHT)==GLFW_PRESS){
            angle-=speed;
        }


        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));
//
//        float radius = 10.0f;
//        float camX = sin(angle) * radius;
//        float camZ = cos(angle) * radius;
//        Kie::PipLine::getInstance(window).getCamera().setPosition(camX, 0.0, camZ);

        for(auto& i:vec){
            window.draw(i);
        }
        vec[1].rotateY(1);
        vec[1].rotateZ(1);

        window.display();
    }

    return 0;
}
