//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_PROJECTOR_H
#define SUMMERPROJECT_PROJECTOR_H

#include <cmath>
#include "../Painter/Painter.h"
#include <vector>
#include "Shape3D/Mesh.h"
#include "Shape3D/Triangle.h"

namespace Kie {
    class Projector {
    private:
        float Near;
        float Far;
        float Fov;
        float AR;
        float FR;
        float matProj[4][4] = {0};

        Vertex multiplyMat(Vertex& mat);

    public:
        explicit Projector(Painter& painter,float Near = 1.0f,float Far=1000.0f,float Fov=90.0f);

        std::vector<Triangle> projection(std::vector<Mesh>& meshes);


    };


}

#endif //SUMMERPROJECT_PROJECTOR_H
