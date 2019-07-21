//
// Created by bxs863 on 16/07/2019.
//

#include "Painter.h"
#include <thread>
#include <random>
int main(){

    Kie::Painter p("Random Lines",640,480);
    p.clear(Kie::Color::from(0,0,0));
    std::thread t([&p](){
        std::random_device e;
        std::uniform_int_distribution<int> dis_r(0,100);
        std::uniform_int_distribution<int> dis_c(0,255);
        while(!p.isClosed()) {

            p.clear(Kie::Color::from(dis_c(e),dis_c(e),dis_c(e)));
            std::uniform_int_distribution<int> dis_w(0,p.getWidth());
            std::uniform_int_distribution<int> dis_h(0,p.getHeight());
            auto temp = dis_r(e);
            for(int i=0;i<temp;i++) {
                p.drawCircle(dis_w(e), dis_h(e), dis_r(e), Kie::Color::from(dis_c(e), dis_c(e), dis_c(e)));
                p.drawLine(dis_w(e),dis_h(e),dis_w(e),dis_h(e),Kie::Color::from(dis_c(e),dis_c(e),dis_c(e)));
                p.drawTriangle({Kie::Pixel{dis_w(e),dis_h(e)},Kie::Pixel{dis_w(e),dis_h(e)},Kie::Pixel{dis_w(e),dis_h(e)}},Kie::Color::from(dis_c(e),dis_c(e),dis_c(e)));
            }
            using std::chrono_literals::operator""s;
            std::this_thread::sleep_for(1s);
        }
    });
    t.detach();
    p.paint();


}
