//
// Created by bxs863 on 12/08/2019.
//

#ifndef SUMMERPROJECT_ITRANSFORMABLE_H
#define SUMMERPROJECT_ITRANSFORMABLE_H

#include "Math/Math.h"

namespace Kie {
    /**
     * An interface for shapes to do some transformation
     */
    class ITransformable {
    public:
        virtual void setPosition(float x,float y,float z)=0;
        virtual void setPosition(bool useInt,int x,int y,int z,int width,int height)=0;
        virtual Math::Vec3D getPosition()=0;
        virtual void rotate(float degree)=0;
        virtual void move(float x,float y,float z)=0;
    };
}


#endif //SUMMERPROJECT_ITRANSFORMABLE_H
