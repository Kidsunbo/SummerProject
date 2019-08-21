//
// Created by bxs863 on 18/08/2019.
//

#ifndef SUMMERPROJECT_CAMERA_H
#define SUMMERPROJECT_CAMERA_H

#include "ITransformable.h"

namespace Kie {

    /**
     * This is the camera class
     */
    class Camera: public ITransformable {
        Math::Mat4D view;
        Math::Vec3D target;
        Math::Vec3D up = Math::Vec3D{0.0f,1.0f,0.0f};

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
        explicit Camera(const Math::Vec3D& pos=Math::Vec3D{0.0f,0.0f,-1.0f}, const Math::Vec3D& target=Math::Vec3D{0.0f});

        /**
         * This method returns the view matrix of the camera
         * @return The view matrix
         */
        Math::Mat4D &getView();

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
        void setPosition(Math::Vec3D pos) override;

        /**
         * This is the getter fo the position
         * @return
         */
        const Math::Vec3D &getPosition() override;

        /**
         * This is for const version
         * @return
         */
        const Math::Vec3D &getPosition() const override;

        /**
         * This is the setter of the target
         * @param target
         */
        void setTarget(const Math::Vec3D& target);

        /**
         * This is the setter of the up
         * @param up
         */
        void setUp(const Math::Vec3D& up);

        /**
         * This is the getter of the up
         * @return
         */
        const Math::Vec3D& getUp();

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
        Math::Vec3D& getTarget();

        /**
         * This method will return the direction of the camera
         * @return The direction of the camera
         */
        Math::Vec3D getDirection();


    public:


    };
}


#endif //SUMMERPROJECT_CAMERA_H
