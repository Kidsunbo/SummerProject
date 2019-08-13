//
// Created by bxs863 on 07/08/2019.
//


#include <iostream>


#include "Point.h"
#include "Window/Window.h"
#include "Math/Math.h"


void Kie::Point::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
#if __cplusplus>=201703L
    auto [x,y] = this->mapCoordsToPixel(window.getWidth(), window.getHeight());
#else
    auto res = this->mapFloatToInt(window.getWidth(),window.getHeight());
    auto x = std::get<0>(res);
    auto y = std::get<1>(res);
#endif
    if(x<0 || x>width ||y<0 || y>height) return;
    window.getBuffer().at(y).at(x) = color;
}

Kie::Point::Point(float x, float y, Kie::Color c):color(c) {
    this->setPosition(x,y,0);
    auto [x1,y1] = this->mapCoordsToPixel(640, 480);
    if(x1!=y1) std::cout<<"hello"<<"  "<<x1<<"  "<<y1<<std::endl;


}


const Kie::Color &Kie::Point::getColor() {
    return color;
}

Kie::Point::Point(bool useInt,int x, int y, int width, int height, Kie::Color c):
Point(static_cast<float>(x)*2.0f/static_cast<float>(width)-1,1- static_cast<float>(y)*2.0f/ static_cast<float>(height),c) {}

void Kie::Point::setColor(Kie::Color c) {
    color = c;
}

