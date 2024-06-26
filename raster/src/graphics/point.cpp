//
// Created by bxs863 on 07/08/2019.
//


#include "graphics/point.h"
#include "window/window.h"
#include "math/math.h"


void Kie::Point::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
    auto [x,y] = this->mapCoordsToPixel(window.getWidth(), window.getHeight());
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

const Kie::math::Vec2D &Kie::Point::getTexture() const {
    return texture;
}

void Kie::Point::setTexture(const Kie::math::Vec2D &texture) {
    Point::texture = texture;
}

float Kie::Point::getZ() const {
    if(z== nullptr) return getPosition().getZ();
    return *z;
}

void Kie::Point::setZ(float value) {
    if(z== nullptr)
        z = std::make_shared<float>(value);
    else *z=value;
}

Kie::Point::Point(const Kie::Point &point):z(point.z),color(point.color),texture(point.texture),ITransformable(point) {

}

Kie::Point::Point(Kie::Point &&point):z(point.z),color(point.color),texture(point.texture),ITransformable(point) {

}

Kie::Point &Kie::Point::operator=(const Kie::Point &point) {
    color=point.color;
    texture=point.texture;
    setPosition(point.getPosition());
    setZ(point.getZ());
    return *this;
}

Kie::Point &Kie::Point::operator=(Kie::Point &&point) noexcept {
    color=point.color;
    texture=point.texture;
    setPosition(point.getPosition());
    setZ(point.getZ());
    return *this;
}



