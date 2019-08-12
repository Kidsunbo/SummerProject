//
// Created by SunBo on 2019-08-12.
//

#include "Line.h"
#include "Window/Window.h"

Kie::Line::Line(Kie::Point p1, Kie::Point p2):
lineColor(-1,-1,-1,true),pos(0.0f),vertex({std::move(p1),std::move(p2)}) {}

Kie::Line::Line(float x1, float y1, float x2, float y2, Kie::Color c):Line(Point(x1,y1,c),Point(x2,y2,c)) {}

Kie::Line::Line(bool useInt, int x1, int y1, int x2, int y2, int width, int height, Kie::Color c):
Line(Point(true,x1,y1,width,height,c),Point(true,x2,y2,width,height,c)){}

void Kie::Line::resetLineColor(Kie::Color c) {
    lineColor=c;
}

void Kie::Line::move(float x, float y, float z) {
    pos[0]+=x;
    pos[1]+=y;
    pos[2]+=z;
}

void Kie::Line::setPosition(float x, float y, float z) {
    pos={x,y,z};
}

void Kie::Line::setPosition(bool useInt, int x, int y, int z, int width, int height) {
    pos={static_cast<float>(x)*2.0f/ static_cast<float>(width)-1,1- static_cast<float>(y)*2.0f/ static_cast<float>(height),0};
}

Kie::Math::Vec3D Kie::Line::getPosition() {
    return pos;
}

void Kie::Line::draw(Kie::Window &window) {
    auto width=window.getWidth();
    auto height = window.getHeight();
    if(lineColor.getR()==-1.0){

    }
    else{

    }

}
