//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_TRIANGLE_H
#define SUMMERPROJECT_TRIANGLE_H


#include "Vec3D.h"
#include "UtilStruct.h"

namespace Kie {
    struct Triangle {
        Vec3D vers[3];
        Color color = Color::from(255,255,255);
    };
}

#endif //SUMMERPROJECT_TRIANGLE_H
