//
// Created by bxs863 on 29/07/2019.
//

#ifndef SUMMERPROJECT_SCALEPROCESSOR_H
#define SUMMERPROJECT_SCALEPROCESSOR_H
#include <vector>
#include "Shape3D/Triangle.h"
#include "Painter.h"

namespace Kie {
    class ScaleProcessor {
    public:

        void scale(Painter& painter,std::vector<Triangle>& tris);


    };
}

#endif //SUMMERPROJECT_SCALEPROCESSOR_H
