//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include <thread>
#include <random>
#include <iostream>

using namespace Kie;
int main(){
    Painter p("Hello world",640,480);
    auto c = Color::from(0, 0, 0);
    p.drawPixel(100,100,c);
    std::thread t([&p](){
        std::random_device e;

        std::uniform_int_distribution<int> dis_c(0,255);
        while(!p.isClosed()) {
            std::uniform_int_distribution<int> dis_w(0,p.getWidth());
            std::uniform_int_distribution<int> dis_h(0,p.getHeight());
            p.drawPixel(dis_w(e), dis_h(e), dis_c(e), dis_c(e), dis_c(e));
        }
    });
    t.detach();
    p.paint();

    return 0;
}