//
// Created by bxs863 on 18/08/2019.
//

#ifndef SUMMERPROJECT_CAMERA_H
#define SUMMERPROJECT_CAMERA_H

#include "ITransformable.h"

namespace Kie {
    class Camera: public ITransformable {
        Math::Mat4D view;
        Math::Vec3D target;
        Math::Vec3D up = Math::Vec3D{0.0f,1.0f,0.0f};
        void updateView();

    public:
        explicit Camera(const Math::Vec3D& pos=Math::Vec3D{0.0f,0.0f,-1.0f}, const Math::Vec3D& target=Math::Vec3D{0.0f});

        Math::Mat4D &getView();

        void setPosition(float x, float y, float z) override;

        void setPosition(Math::Vec3D pos) override;

        const Math::Vec3D &getPosition() override;

        const Math::Vec3D &getPosition() const override;

        void setTarget(const Math::Vec3D& target);

        void setUp(const Math::Vec3D& up);

        const Math::Vec3D& getUp();

        void move(float x, float y, float z) override;

        Math::Vec3D& getTarget();

        Math::Vec3D getDirection();


    public:


    };
}


#endif //SUMMERPROJECT_CAMERA_H
