//
// Created by bxs863 on 28/07/2019.
//

#ifndef SUMMERPROJECT_PAINTER3DUTIL_H
#define SUMMERPROJECT_PAINTER3DUTIL_H

#include <vector>
#include <type_traits>
#include "Shape3D/Mesh.h"
#include "ProjectionProcessor.h"

namespace Kie {
    class Painter3DUtil {
    public:
        enum ROTATE{
            x = 0b001,
            y = 0b010,
            z= 0b100
        };

        template<typename T,typename=void>
        class HasMeshes:public std::false_type{};

        template <typename T>
        class HasMeshes<T,std::void_t<decltype(std::declval<T>().meshes)>>:public std::true_type{};

        static std::vector<Triangle> meshToTris(std::vector<Mesh>& meshes);

    };

}

#endif //SUMMERPROJECT_PAINTER3DUTIL_H
