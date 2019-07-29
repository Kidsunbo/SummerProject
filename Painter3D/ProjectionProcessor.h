//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_PROJECTIONPROCESSOR_H
#define SUMMERPROJECT_PROJECTIONPROCESSOR_H

#include <cmath>
#include "../Painter/Painter.h"
#include <vector>
#include "Shape3D/Mesh.h"
#include "Shape3D/Triangle.h"

namespace Kie {
    class ProjectionProcessor {
    private:


        float Near;
        float Far;
        float Fov;
        float AR;
        float FR;
        float matProj[4][4] = {0};
        float distance;
    public:
        void setDistance(float distance);

    private:

        Vertex multiplyMat(Vertex& mat);

    public:
        explicit ProjectionProcessor(Painter& painter, float Near = 10.0f, float Far=100.0f, float Fov=90.0f);

        void updateMatProj(Painter& painter,float Near,float Far,float Fov);

        void projection(std::vector<Triangle>& meshes);


    };


}

#endif //SUMMERPROJECT_PROJECTIONPROCESSOR_H
