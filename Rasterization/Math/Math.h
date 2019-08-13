//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_MATH_H
#define SUMMERPROJECT_MATH_H

#include "MathImpl.h"

namespace Kie::Math {

    class Vec3D:public Impl::Vec<3>{
        Vec3D():Impl::Vec<3>(0.0f){}
    public:
        using Impl::Vec<3>::Vec;
        Vec3D crossProduct(const Vec3D& vec){
            Vec3D res;
            res.arr[0] = arr[1]*vec.arr[2]-arr[2]*vec.arr[1];
            res.arr[1] =arr[2]*vec.arr[0]-arr[0]*vec.arr[2];
            res.arr[2] = arr[0]*vec.arr[1] - arr[1]*vec.arr[0];
            return res;
        }

        float getX(){
            return arr[0];
        }

        float getY(){
            return arr[1];
        }

        float getZ(){
            return arr[2];
        }
    };

    using Vec2D = Impl::Vec<2>;
    using Vec4D = Impl::Vec<4>;

    using Mat3D = Impl::Mat<3>;
    using Mat4D = Impl::Mat<4>;
    using Interp = Impl::Interpolation;
}


#endif //SUMMERPROJECT_MATH_H
