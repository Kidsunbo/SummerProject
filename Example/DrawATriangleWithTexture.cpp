//
// Created by bxs863 on 07/08/2019.
//

#include "Window/Window.h"
#include "Graphics/Triangle.h"


int main(){

    Kie::Window window(640,480,"Hello Triangle");
    std::shared_ptr<Kie::Texture> texture = std::make_shared<Kie::Texture>();
    texture->load(R"(../../Resource/img/brick.png)");
    Kie::Point p1(0.0f,1.0f,0,Kie::Color(1.0f,0.0f,0.0f));
    p1.setTexture({0.0f,1.0f});
    Kie::Point p2(0.0f,0.0f,0,Kie::Color(0.0f,1.0f,0.0f));
    p2.setTexture({0,0});
    Kie::Point p3(1.0f,0.5f,0,Kie::Color(0.0f,0.0f,1.0f));
    p3.setTexture({1.0f,0.5f});
    Kie::Triangle tri(p1,p2,p3,true,texture);
    window.setFrameRate(100);
    while(!window.shouldClose()){

        glfwPollEvents();
        window.clear(Kie::Color(0,0,0));
        window.draw(tri);
        //window.draw(Kie::Triangle(Kie::Point(0,0.249981284f,0),Kie::Point(0.187485978,0.249981284,0.0f),Kie::Point(0.0f,0.0f,0),true));
        window.display();
    }

    return 0;
}