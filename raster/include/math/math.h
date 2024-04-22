//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_MATH_H
#define SUMMERPROJECT_MATH_H

#include "math_impl.h"

namespace Kie::math {

    /**
     * This method is used to compare if two float numbers are equal in certain precise
     * @param f1 The first float number
     * @param f2 The second float number
     * @return If they are equal
     */
    bool floatEqual(float f1,float f2);

    /**
     * This is the class for 3 dimension vector
     */
    class Vec3D:public impl::Vec<3>{
        Vec3D():impl::Vec<3>(0.0f){}
    public:
        using impl::Vec<3>::Vec;

        /**
         * Do the cross production with another three dimension vector
         * @param vec The other three dimension vector
         * @return The result
         */
        Vec3D crossProduct(const Vec3D& vec){
            Vec3D res;
            res.arr[0] = arr[1]*vec.arr[2]-arr[2]*vec.arr[1];
            res.arr[1] =arr[2]*vec.arr[0]-arr[0]*vec.arr[2];
            res.arr[2] = arr[0]*vec.arr[1] - arr[1]*vec.arr[0];
            return res;
        }

        /**
         * The constructor with the base class
         * @param vec
         */
        Vec3D(const impl::Vec<3>& vec){
            arr = {vec[0],vec[1],vec[2]};
        }

        /**
         * Get the first value in the vector
         * @return The first value in the vector
         */
        float getX() const{
            return arr[0];
        }

        /**
         * Get the second value in the vector
         * @return The second value in the vector
         */
        float getY() const{
            return arr[1];
        }

        /**
         * Get the third value in the vector
         * @return The third value in the vector
         */
        float getZ() const{
            return arr[2];
        }
    };

    /**
     * The two dimension vector, which is just a type alias
     */
    using Vec2D = impl::Vec<2>;

    /**
     * The four dimension vector
     */
    class Vec4D:public impl::Vec<4>{
    public:
        using impl::Vec<4>::Vec;
        /**
         * Construct the four dimension vector with three dimension vector and a new number
         * @param vec3D The three dimension vector
         * @param num The new number
         */
        Vec4D(const Vec3D& vec3D,float num){
            arr[0] = vec3D.getX();
            arr[1] = vec3D.getY();
            arr[2] = vec3D.getZ();
            arr[3] = num;
        }

        /**
         * Constructor
         * @param vec The base class version of four dimension vector
         */
        Vec4D(const impl::Vec<4>& vec){
            arr = {vec[0],vec[1],vec[2],vec[3]};
        }

        /**
         * The method which used to convert to three dimension vector.
         * @return
         */
        Vec3D toVec3D(){
            return {arr[0],arr[1],arr[2]};
        }
    };


    /**
     * The 3X3 matrix
     */
    using Mat3D = impl::Mat<3>;
    /**
     * The 4X4 matrix
     */
    using Mat4D = impl::Mat<4>;
    /**
     * The interpolation class, which itself is a iterator
     */
    using Interp = impl::Interpolation;
}


#endif //SUMMERPROJECT_MATH_H
