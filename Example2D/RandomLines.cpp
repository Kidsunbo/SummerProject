//
// Created by bxs863 on 01/07/2019.
//

#include "Painter.h"
#include <thread>
#include <random>
int main(){

    using Kie::Color;
    Kie::Painter p("Random Lines",640,480);
    p.clear(Color::from(0, 0, 0));
    std::thread t([&p](){
        std::random_device e;
        std::uniform_int_distribution<int> dis_c(100,255);
        while(true) {
            p.clear(Color::from(0, 0, 0));
            std::uniform_int_distribution<int> dis_w(0,p.getWidth());
            std::uniform_int_distribution<int> dis_h(0,p.getHeight());
            p.drawLine(dis_w(e), dis_h(e), dis_w(e), dis_h(e), Color::from(dis_c(e), dis_c(e), dis_c(e)));
            using std::chrono_literals::operator""s;
            std::this_thread::sleep_for(1s);
        }
    });
    t.detach();
    p.paint();


}
