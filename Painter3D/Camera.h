//
// Created by bxs863 on 05/08/2019.
//

#ifndef SUMMERPROJECT_CAMERA_H
#define SUMMERPROJECT_CAMERA_H

#include "Shape3D/Triangle.h"

namespace Kie {
    class Camera {
    public:
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        void moveX(float delta);

        void moveY(float delta);

        void moveZ(float delta);

    };
}

#endif //SUMMERPROJECT_CAMERA_H
