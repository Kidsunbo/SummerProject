//
// Created by bxs863 on 12/08/2019.
//

#include "ITransformable.h"
#include <cmath>

Kie::ITransformable::ITransformable():pos(0.0f),origin(0.0f),rotation(0.0f),ratio(0.0f) {}

void Kie::ITransformable::setPosition(float x, float y, float z) {
    pos={x,y,z};
}

void Kie::ITransformable::setOrigin(float x, float y, float z) {
    origin={x,y,z};
}

void Kie::ITransformable::setRotation(float degree) {
    rotation = static_cast<float>(fmod(degree,360));
    if(rotation<0) rotation+=360.0f;
}

void Kie::ITransformable::setScale(float ratio) {
    this->ratio=ratio;
}

const Kie::Math::Vec3D& Kie::ITransformable::getPosition() {
    return pos;
}

const Kie::Math::Vec3D &Kie::ITransformable::getOrigin() {
    return origin;
}

const float &Kie::ITransformable::getRotation() {
    return rotation;
}

const float &Kie::ITransformable::getScale() {
    return ratio;
}

void Kie::ITransformable::rotate(float offset) {
    this->setRotation(this->getRotation()+offset);
}

void Kie::ITransformable::scale(float offset) {
    ratio+=offset;
}

void Kie::ITransformable::move(float x, float y, float z) {
    pos+={x,y,z};
}

std::tuple<int, int> Kie::ITransformable::mapCoordsToPixel(int width, int height) {
    auto x = static_cast<int>((pos.getX()+1.0f)* static_cast<float>(width)/2.0f);
    auto y = static_cast<int>((1.0f-pos.getY())* static_cast<float>(height)/2.0f);
    return {x,y};
}













