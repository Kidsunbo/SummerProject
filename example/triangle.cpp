//
// Created by bxs863 on 19/08/2019.
//


#include <random>
#include "window/window.h"
#include "graphics/point.h"
#include "graphics/triangle.h"

#include <random>
std::random_device e;
std::uniform_real_distribution<float> d(0.2f,1.0f);
std::vector<Kie::Point> ps;
Kie::Window window(640,480,"Hello Triangle");

bool same = true;
bool fill = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        if(same) {
            auto temp = Kie::Color(d(e), d(e), d(e));
            for(auto& p:ps) p.setColor(temp);
        }
        else{
            for(auto& p:ps) p.setColor(Kie::Color(d(e), d(e), d(e)));
        }
    }
    else if(key==GLFW_KEY_S && action==GLFW_PRESS){
        same=!same;
    }
    else if(key==GLFW_KEY_F && action==GLFW_PRESS){
        fill=!fill;
    }
}

void mouse_callback(GLFWwindow* w, int button, int action, int mods)
{

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        double x,y;
        glfwGetCursorPos(w,&x,&y);
        if(ps.size()==3) ps.clear();
        ps.emplace_back((x/window.getWidth()*2)-1.0,1-(y/window.getHeight()*2),0);
    }
}

int main(){

    glfwSetKeyCallback(window.getWindow(),key_callback);
    glfwSetMouseButtonCallback(window.getWindow(),mouse_callback);
    while(!window.shouldClose()){

        glfwPollEvents();

        window.clear(Kie::Color(0,0,0));
        if(ps.size()==1) {
            window.draw(ps[0]);
        }
        if(ps.size()==2){
            window.draw(ps[0]);
            window.draw(ps[1]);

        }
        if(ps.size()==3){
            window.draw(Kie::Triangle(ps[0],ps[1],ps[2],fill));
        }
        window.display();
    }

    return 0;
}