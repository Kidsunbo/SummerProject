//
// Created by bxs863 on 12/08/2019.
//

#ifndef SUMMERPROJECT_I_TRANSFORMABLE_H
#define SUMMERPROJECT_I_TRANSFORMABLE_H

#include "math/math.h"
#include <tuple>

namespace Kie {
    /**
     * An interface for shapes to do some transformation
     */
    class ITransformable {
        math::Vec3D pos;
        math::Vec3D origin;
        float rotation;
        float ratio;
    public:
        /**
         * Constructor
         */
        ITransformable();

        /**
         * This method set the position of the object
         * @param x x value
         * @param y y value
         * @param z z value
         */
        virtual void setPosition(float x,float y,float z);

        /**
         * This method is the overloading version of the setPosition
         * @param pos new pos
         */
        virtual void setPosition(math::Vec3D pos);

        /**
         * Set the center point of the object
         * @param x the x value
         * @param y the y value
         * @param z the z value
         */
        virtual void setOrigin(float x,float y,float z);

        /**
         * Set the rotation of the object, this mehtod is seldom used in three dimension object, but it's quite useful
         * in two dimension shapes
         * @param degree the degree which used to rotate the object
         */
        virtual void setRotation(float degree);

        /**
         * This is the scale of the object, sometimes, the object's local coordinate is huge which make them hard to
         * be displayed with other object, so this method is used to scale them into a standard number
         * @param ratio The ratio
         */
        virtual void setScale(float ratio);

        /**
         * The getter of the position
         * @return The position
         */
        virtual const math::Vec3D& getPosition();

        /**
         * This is the constant version of getPosition
         * @return The position
         */
        virtual const math::Vec3D& getPosition() const;

        /**
         * This is the getter for origin
         * @return The origin
         */
        virtual const math::Vec3D& getOrigin();

        /**
         * This is the getter for rotation
         * @return The rotation
         */
        virtual const float& getRotation();


        /**
         * This is the getter for scale
         * @return The scale
         */
        virtual const float& getScale();

        /**
         * This is the method used to rotate the object with a certain value
         * @param offset The offset of the ratetion
         */
        virtual void rotate(float offset);

        /**
         * This is the method used to scale the object in a certain ratio
         * @param offset
         */
        virtual void scale(float offset);

        /**
         * This is the method used to move the object
         * @param x the x value
         * @param y the y value
         * @param z the z value
         */
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


#endif //SUMMERPROJECT_I_TRANSFORMABLE_H
