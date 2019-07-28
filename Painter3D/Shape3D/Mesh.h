//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_MESH_H
#define SUMMERPROJECT_MESH_H
#include <vector>
#include "Triangle.h"

namespace Kie {
    struct Mesh {
        std::vector<Triangle> tris = std::vector<Triangle>(2);
    };

}

#endif //SUMMERPROJECT_MESH_H
