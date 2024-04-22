//
// Created by bxs863 on 18/08/2019.
//

#include "graphics/camera.h"

Kie::math::Mat4D &Kie::Camera::getView() {
    return view;
}

void Kie::Camera::updateView() {
    auto& position = getPosition();
    math::Vec3D cameraDirection = (position-target).normalize();
    math::Vec3D cameraRight = up.crossProduct(cameraDirection).normalize();
    math::Vec3D cameraUp = cameraDirection.crossProduct(cameraRight);
    math::Mat4D left = {{cameraRight.getX(),cameraRight.getY(),cameraRight.getZ(),0.0f},
                        {cameraUp.getX(),cameraUp.getY(),cameraUp.getZ(),0.0f},
                        {cameraDirection.getX(),cameraDirection.getY(),cameraDirection.getZ(),0.0f},
                        {0,0,0,1}};
    math::Mat4D  right = {{1,0,0,-position.getX()},
                          {0,1,0,-position.getY()},
                          {0,0,1,-position.getZ()},
                          {0,0,0,1}};
    view = left*right;
}

void Kie::Camera::setPosition(float x, float y, float z) {
    ITransformable::setPosition(x, y, z);
    updateView();
}

void Kie::Camera::setPosition(Kie::math::Vec3D pos) {
    ITransformable::setPosition(pos);
    updateView();
}

const Kie::math::Vec3D &Kie::Camera::getPosition() {
    return ITransformable::getPosition();
}

const Kie::math::Vec3D &Kie::Camera::getPosition() const {
    return ITransformable::getPosition();
}

void Kie::Camera::setTarget(const Kie::math::Vec3D& target) {
    this->target=target;
    updateView();
}

Kie::Camera::Camera(const Kie::math::Vec3D &pos, const Kie::math::Vec3D &target):view(0.0f),target(target) {
    setPosition(pos);
    updateView();
}

void Kie::Camera::setUp(const Kie::math::Vec3D &up) {
    this->up =up;
    updateView();
}

const Kie::math::Vec3D &Kie::Camera::getUp() {
    return up;
}

void Kie::Camera::move(float x, float y, float z) {
    ITransformable::move(x, y, z);
    updateView();
}

Kie::math::Vec3D& Kie::Camera::getTarget() {
    return target;
}

Kie::math::Vec3D Kie::Camera::getDirection() {
    return (target-getPosition()).normalize();
}

