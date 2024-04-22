//
// Created by bxs863 on 18/08/2019.
//

#ifndef SUMMERPROJECT_CAMERA_H
#define SUMMERPROJECT_CAMERA_H

#include "i_transformable.h"

namespace Kie {

    /**
     * This is the camera class
     */
    class Camera: public ITransformable {
        math::Mat4D view;
        math::Vec3D target;
        math::Vec3D up = math::Vec3D{0.0f,1.0f,0.0f};

        /**
         * When the factor changes, the matrix will change
         */
        void updateView();

    public:
        /**
         * This is the constructor of the class
         * @param pos The initial position of the camera class
         * @param target This is the target of the camera
         */
        explicit Camera(const math::Vec3D& pos=math::Vec3D{0.0f,0.0f,-1.0f}, const math::Vec3D& target=math::Vec3D{0.0f});

        /**
         * This method returns the view matrix of the camera
         * @return The view matrix
         */
        math::Mat4D &getView();

        /**
         * This is used to set the position of the camera
         * @param x The x value
         * @param y The y value
         * @param z The z value
         */
        void setPosition(float x, float y, float z) override;

        /**
         * This is the overloading version of the setPosition method
         * @param pos
         */
        void setPosition(math::Vec3D pos) override;

        /**
         * This is the getter fo the position
         * @return
         */
        const math::Vec3D &getPosition() override;

        /**
         * This is for const version
         * @return
         */
        const math::Vec3D &getPosition() const override;

        /**
         * This is the setter of the target
         * @param target
         */
        void setTarget(const math::Vec3D& target);

        /**
         * This is the setter of the up
         * @param up
         */
        void setUp(const math::Vec3D& up);

        /**
         * This is the getter of the up
         * @return
         */
        const math::Vec3D& getUp();

        /**
         * This function moves the position of the camera
         * @param x The offset in x axis
         * @param y The offset in y axis
         * @param z The offset in z axis
         */
        void move(float x, float y, float z) override;

        /**
         * This is the getter of target
         * @return
         */
        math::Vec3D& getTarget();

        /**
         * This method will return the direction of the camera
         * @return The direction of the camera
         */
        math::Vec3D getDirection();


    public:


    };
}


#endif //SUMMERPROJECT_CAMERA_H
