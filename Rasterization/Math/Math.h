//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_MATH_H
#define SUMMERPROJECT_MATH_H

#include "MathImpl.h"

namespace Kie::Math {

    bool floatEqual(float f1,float f2);

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

        Vec3D(const Impl::Vec<3>& vec){
            arr = {vec[0],vec[1],vec[2]};
        }

        float getX() const{
            return arr[0];
        }

        float getY() const{
            return arr[1];
        }

        float getZ() const{
            return arr[2];
        }
    };

    using Vec2D = Impl::Vec<2>;

    class Vec4D:public Impl::Vec<4>{
    public:
        using Impl::Vec<4>::Vec;
        Vec4D(const Vec3D& vec3D,float num){
            arr[0] = vec3D.getX();
            arr[1] = vec3D.getY();
            arr[2] = vec3D.getZ();
            arr[3] = num;
        }

        Vec4D(const Impl::Vec<4>& vec){
            arr = {vec[0],vec[1],vec[2],vec[3]};
        }

        Vec3D toVec3D(){
            return {arr[0],arr[1],arr[2]};
        }
    };


    using Mat3D = Impl::Mat<3>;
    using Mat4D = Impl::Mat<4>;
    using Interp = Impl::Interpolation;
}


#endif //SUMMERPROJECT_MATH_H
