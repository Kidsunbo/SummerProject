//
// Created by bxs863 on 02/07/2019.
//

#include "Painter.h"
#include <thread>
#include <random>
int main(){

    Kie::Painter p("Random Lines",640,480);
    p.clear(Kie::Color::from(0,0,0));
    std::thread t([&p](){
        std::random_device e;
        while(true) {
            p.clear(Kie::Color::from(0,0,0));
            std::uniform_int_distribution<int> dis_w(0,p.getWidth());
            std::uniform_int_distribution<int> dis_h(0,p.getHeight());
            p.drawShape(Kie::Shape::Triangle,{Kie::Point{dis_w(e),dis_h(e)},Kie::Point{dis_w(e),dis_h(e)},Kie::Point{dis_w(e),dis_h(e)}});
            using std::chrono_literals::operator""s;
            std::this_thread::sleep_for(1s);
        }
    });
    t.detach();
    p.paint();


}
