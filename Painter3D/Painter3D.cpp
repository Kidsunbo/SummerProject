//
// Created by bxs863 on 14/07/2019.
//

#include "Painter3D.h"

Kie::Painter3D::Painter3D(const char *title, int width, int height):
painter(Painter(title,width,height)),
pp(ProjectionProcessor(painter)),
rp(0),
light(0,0,-3,Color::from(255,255,255))
{}

void Kie::Painter3D::paint() {
    painter.paint();
}

void Kie::Painter3D::clear(Color c) {
    painter.clear(c);
}

Kie::Painter &Kie::Painter3D::getPainter() {
    return painter;
}

Kie::ProjectionProcessor &Kie::Painter3D::getPp() {
    return pp;
}

Kie::ScaleProcessor &Kie::Painter3D::getSp() {
    return sp;
}

Kie::RotateProcessor &Kie::Painter3D::getRp() {
    return rp;
}

void Kie::Painter3D::setRotateSpeed(float speed) {
    rp.setSpeed(speed);
}

void Kie::Painter3D::setRotateAxis(unsigned short axis) {
    this->axis = axis;
}

void Kie::Painter3D::setDistance(float distance) {
    pp.setDistance(distance);
}

Kie::Light &Kie::Painter3D::getLight() {
    return light;
}




