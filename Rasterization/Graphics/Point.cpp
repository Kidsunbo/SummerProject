//
// Created by bxs863 on 07/08/2019.
//

#include "Point.h"
#include "Window/Window.h"
#include "Math/Math.h"


void Kie::Point::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
    if(pos[0]<-1 || pos[0]>1 ||pos[1]<-1 || pos[1]>1) return;
    window.getBuffer().at(static_cast<int>(Math::mapY(pos[1]) * height / 2)).at(static_cast<int>(
                                                                                                     Math::mapX(pos[0]) * width / 2))=color;
}


Kie::Point::Point(float x, float y, Kie::Color c):color(c),pos({x,y,0}) {
}

void Kie::Point::setPosition(float x, float y, float z) {
    pos={x,y,z};
}

Kie::Math::Vec3D Kie::Point::getPosition() {
    return pos;
}


void Kie::Point::rotate(float degree) {
    // Do nothing
}

const Kie::Color &Kie::Point::getColor() const {
    return color;
}

void Kie::Point::move(float x, float y, float z) {
    pos[0]+=x;
    pos[1]+=y;
    pos[2]+=z;
}

void Kie::Point::setPosition(bool useInt,int x, int y, int z, int width, int height) {
    pos={static_cast<float>(x)*2.0f/ static_cast<float>(width)-1,1- static_cast<float>(y)*2.0f/ static_cast<float>(height),0};
}

Kie::Point::Point(bool useInt,int x, int y, int width, int height, Kie::Color c):Point(static_cast<float>(x)*2.0f/ static_cast<float>(width)-1,1- static_cast<float>(y)*2.0f/ static_cast<float>(height),c) {

}

