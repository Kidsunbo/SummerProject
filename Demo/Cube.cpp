//
// Created by bxs863 on 19/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Object.h"

#include <random>


Kie::Window window(640, 480, "Hello Cube");
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

bool drawFill = false;
std::random_device e;
std::uniform_real_distribution<float> d(0.2f,1.0f);

void key_callback(GLFWwindow* w, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {

    }
    else if(key==GLFW_KEY_C && action==GLFW_PRESS){
        auto temp = Kie::Color(d(e),d(e),d(e));
        Kie::Light light(Kie::PipLine::getInstance(window).getLight().getLightPos(),temp);
        Kie::PipLine::getInstance(window).setLight(light);
    }
    else if(key==GLFW_KEY_L && action==GLFW_PRESS){
        object.turnTheLight();
    }
    else if(key==GLFW_KEY_F && action==GLFW_PRESS){
        drawFill = !drawFill;
        object.setDrawFill(drawFill);
    }
}
int main() {


    object.turnTheLight();
    object.setDistance(1);
    object.setOrigin(0.5f, 0.5f, 0.5f);
    object.setDrawSketch(true);
    object.setDrawFill(drawFill);
    glfwSetKeyCallback(window.getWindow(),key_callback);
    while (!window.shouldClose()) {

        if(glfwGetKey(window.getWindow(),GLFW_KEY_RIGHT)==GLFW_PRESS){
            object.rotateZ(1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_LEFT)==GLFW_PRESS){
            object.rotateZ(-1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_UP)==GLFW_PRESS){
            object.rotateX(1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_DOWN)==GLFW_PRESS){
            object.rotateX(-1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_PAGE_UP)==GLFW_PRESS){
            object.rotateY(1);
        }
        else if(glfwGetKey(window.getWindow(),GLFW_KEY_PAGE_DOWN)==GLFW_PRESS){
            object.rotateY(-1);
        }


        glfwPollEvents();
        window.clear(Kie::Color(0, 0, 0));

        window.draw(object);

        window.display();
    }

    return 0;
}
