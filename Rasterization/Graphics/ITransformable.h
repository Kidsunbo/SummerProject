//
// Created by bxs863 on 12/08/2019.
//

#ifndef SUMMERPROJECT_ITRANSFORMABLE_H
#define SUMMERPROJECT_ITRANSFORMABLE_H

#include "Math/Math.h"
#include <tuple>

namespace Kie {
    /**
     * An interface for shapes to do some transformation
     */
    class ITransformable {
        Math::Vec3D pos;
        Math::Vec3D origin;
        float rotation;
        float ratio;
    public:
        ITransformable();
        virtual void setPosition(float x,float y,float z);
        virtual void setPosition(bool useInt,int x,int y,int z,int width,int height);
        virtual void setOrigin(float x,float y,float z);
        virtual void setRotation(float degree);
        virtual void setScale(float ratio);

        virtual const Math::Vec3D& getPosition();
        virtual const Math::Vec3D& getOrigin();
        virtual const float& getRotation();
        virtual const float& getScale();
        virtual void rotate(float offset);
        virtual void scale(float offset);
        virtual void move(float x,float y,float z);

        /**
         * Change this function for 2D or 3D shapes.
         * For 3D shapes, it need to projection the 3D Coordinate to 2D Pixel
         * @param width The width of the View, which is mostly the window
         * @param height The height of the View, which is mostly the window
         * @return The X and Y
         */
        virtual std::tuple<int,int> mapCoordsToPixel(int width, int height);
    };
}


#endif //SUMMERPROJECT_ITRANSFORMABLE_H
