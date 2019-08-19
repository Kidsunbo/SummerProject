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
    if(window.getZbuffer().at(y).at(x)>this->getZ()) {
        window.getBuffer().at(y).at(x) = color;
        window.getZbuffer().at(y).at(x) = this->getZ();
    }
//    window.getBuffer().at(y).at(x) = color;

}

const Kie::Color &Kie::Point::getColor() {
    return color;
}

void Kie::Point::setColor(Kie::Color c) {
    color = c;
}

Kie::Point::Point(float x, float y, float z, Kie::Color c):color(c),texture(0.0f) {
    this->setPosition(x,y,z);
}

const Kie::Math::Vec2D &Kie::Point::getTexture() const {
    return texture;
}

void Kie::Point::setTexture(const Kie::Math::Vec2D &texture) {
    Point::texture = texture;
}

float Kie::Point::getZ() {
    if(z== nullptr) return getPosition().getZ();
    return *z;
}

void Kie::Point::setZ(float value) {
    z = std::make_shared<float>(value);
}



