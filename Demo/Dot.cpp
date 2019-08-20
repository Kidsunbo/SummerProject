//
// Created by bxs863 on 19/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Point.h"
#include <random>


#include <random>
std::random_device e;
std::uniform_real_distribution<float> d(0.2f,1.0f);
Kie::Color temp(255,255,255);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        temp = Kie::Color(d(e),d(e),d(e));
    }
}

int main(){

    Kie::Window window(640,480,"Hello Dot");
    std::vector<Kie::Point> ps;
    ps.emplace_back(0,0,0);
    glfwSetKeyCallback(window.getWindow(),key_callback);
    window.printFPS(true);
    while(!window.shouldClose()){
        if(glfwGetMouseButton(window.getWindow(),GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS){
            double x,y;
            glfwGetCursorPos(window.getWindow(),&x,&y);
            ps.emplace_back((x/window.getWidth()*2)-1.0,1-(y/window.getHeight()*2),0);
        }

        glfwPollEvents();

        window.clear(Kie::Color(0,0,0));
        for(auto& i: ps) {
            i.setColor(temp);
            window.draw(i);
        }
        window.display();
    }

    return 0;
}