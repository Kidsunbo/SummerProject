//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include <thread>
#include <random>
#include <iostream>

int main(){
    Painter p("Hello world",640,480);
    auto c = Painter::createColor(0,0,0);
    p.drawPixel(100,100,c);
    std::thread t([&p](){
        std::random_device e;
        std::uniform_int_distribution<int> dis_w(0,p.getWidth());
        std::uniform_int_distribution<int> dis_h(0,p.getHeight());
        std::uniform_int_distribution<int> dis_c(0,255);
        while(true) {
            using std::chrono_literals::operator""us;
            //p.clear();

            //p.drawLine(dis_w(e),dis_h(e),dis_w(e),dis_h(e));
            std::this_thread::sleep_for(100us);
            p.drawPixel(dis_w(e), dis_h(e), dis_c(e), dis_c(e), dis_c(e));
        }
    });
    t.detach();
    p.paint();

    return 0;
}