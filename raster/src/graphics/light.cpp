//
// Created by bxs863 on 14/08/2019.
//

#include "graphics/light.h"

#include <utility>

Kie::Light::Light():Light(math::Vec3D(0.0f),Color(1.0f,1.0f,1.0f)) {

}

Kie::Light::Light(const Kie::Color &color):Light(math::Vec3D(0.0f), color) {

}

Kie::Light::Light(const Kie::math::Vec3D &pos):Light(pos,Color(1.0f,1.0f,1.0f)) {

}

Kie::Light::Light(const Kie::Color &color, const Kie::math::Vec3D &pos):Light(pos,color) {

}

Kie::Light::Light(Kie::math::Vec3D pos, const Kie::Color &color):lightColor(color),lightPos(std::move(pos)) {

}

const Kie::Color &Kie::Light::getLightColor() const {
    return lightColor;
}

void Kie::Light::setLightColor(const Kie::Color &lc) {
    Light::lightColor = lc;
}

const Kie::math::Vec3D &Kie::Light::getLightPos() const {
    return lightPos;
}

void Kie::Light::setLightPos(const Kie::math::Vec3D &lp) {
    Light::lightPos = lp;
}

float Kie::Light::getAmbientStrength() const {
    return ambientStrength;
}

void Kie::Light::setAmbientStrength(float ambientStrength) {
    Light::ambientStrength = ambientStrength;
}




