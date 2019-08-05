//
// Created by bxs863 on 05/08/2019.
//

#include "Camera.h"


using namespace Kie;
void Camera::moveX(float delta) {
    x+=delta;
}

void Camera::moveY(float delta) {
    y+=delta;
}

void Camera::moveZ(float delta) {
    z+=delta;
}

