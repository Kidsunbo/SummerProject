//
// Created by bxs863 on 12/08/2019.
//

#ifndef SUMMERPROJECT_TRANSFORMABLE_H
#define SUMMERPROJECT_TRANSFORMABLE_H

#include "Math/Math.h"

namespace Kie {
    /**
     * An interface for shapes to do some transformation
     */
    class Transformable {
    protected:
        Math::Vec3D pos;
    public:
        virtual void setPosition(int x,int y,int z=0);
        virtual Math::Vec3D getPosition();
        virtual void rotate(float degree)=0;
        virtual void moveX(int pixels)=0;
        virtual void moveX(float distance)=0;
        virtual void moveY(float distance) = 0;
        virtual void moveY(int pixels) = 0;
    };
}


#endif //SUMMERPROJECT_TRANSFORMABLE_H
