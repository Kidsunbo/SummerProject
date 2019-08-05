//
// Created by bxs863 on 05/08/2019.
//

#ifndef SUMMERPROJECT_NORMAL_H
#define SUMMERPROJECT_NORMAL_H


#include <vector>
#include "Shape3D/Triangle.h"

namespace Kie {
    class Normal {
    private:
        Vec3D crossProduct(const Vec3D& a,const Vec3D& b);



    public:

        Vec3D normal(Triangle& triangle);
    };

}


#endif //SUMMERPROJECT_NORMAL_H
