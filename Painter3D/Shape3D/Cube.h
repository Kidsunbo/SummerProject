//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_CUBE_H
#define SUMMERPROJECT_CUBE_H
#include <vector>
#include "Mesh.h"

namespace Kie {
    struct Cube {
        std::vector<Mesh> meshes = std::vector<Mesh>(6);
    };

}



#endif //SUMMERPROJECT_CUBE_H
