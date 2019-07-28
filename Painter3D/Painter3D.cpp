//
// Created by bxs863 on 14/07/2019.
//

#include "Painter3D.h"

Kie::Painter3D::Painter3D(const char *title, int width, int height):painter(Painter(title,width,height)),projector(painter) {
}

void Kie::Painter3D::paint() {
    painter.paint();
}

void Kie::Painter3D::clear(Color c) {
    painter.clear(c);
}
