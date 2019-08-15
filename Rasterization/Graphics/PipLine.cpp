//
// Created by bxs863 on 14/08/2019.
//

#include "PipLine.h"
#include "Window/Window.h"
#include <cmath>


Kie::PipLine::PipLine(Window& window,float near, float far, float fov, Kie::Color lightColor, const Kie::Math::Vec3D& pos):light(lightColor,pos),proMatrix(0.0f),rotMatrix(0.0f),traMatrix(0.0f) {

    updatePromatrix(window, near, far, fov);
}

std::shared_ptr<Kie::PipLine> Kie::PipLine::pp = nullptr;

Kie::PipLine& Kie::PipLine::getInstance(Kie::Window &window) {
    if(pp== nullptr) pp = std::make_shared<PipLine>(window);
    return *pp;
}

Kie::Object Kie::PipLine::Projection(Kie::Object object) {
    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            auto pos = proMatrix*Math::Vec4D(ver.getPosition(),1.0f);
            float w = pos[0]*proMatrix[0][3]+pos[1]*proMatrix[1][3]+pos[2]*proMatrix[2][3]+proMatrix[3][3];
            auto after = Math::Vec4D(pos).toVec3D();
            if(!Math::floatEqual(w,1.0f))
                after/=w;
            ver.setPosition(after);
        }
    }
    return object;
}

Kie::Object Kie::PipLine::Rotate(Kie::Object object) {
    Kie::Math::Mat4D xMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
    xMat[1][1] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    xMat[1][2] = -std::sin(object.rotateXDegree/180.0f*3.1415926f);
    xMat[2][1] = std::sin(object.rotateXDegree/180.0f*3.1415926f);
    xMat[2][2] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    Kie::Math::Mat4D yMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
    yMat[0][0] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    yMat[0][2] = -std::sin(object.rotateYDegree/180.0f*3.1415926f);
    yMat[2][0] = std::sin(object.rotateYDegree/180.0f*3.1415926f);
    yMat[2][2] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    Kie::Math::Mat4D zMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
   zMat[0][0] = std::cos(object.rotateZDegree/180.0f*3.1415926f);
   zMat[0][1] = -std::sin(object.rotateZDegree/180.0f*3.1415926f);
   zMat[1][0] = std::sin(object.rotateZDegree/180.0f*3.1415926f);
   zMat[1][1] = std::cos(object.rotateZDegree/180.0f*3.1415926f);

    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            auto pos = xMat*Math::Vec4D(ver.getPosition(),1.0f);
            Math::Vec3D after(0);
            if(!Math::floatEqual(pos[3],0.0f))after = Math::Vec4D(pos).toVec3D()/=pos[3];
            pos = yMat*Math::Vec4D(after,1.0f);
            if(!Math::floatEqual(pos[3],0.0f))after = Math::Vec4D(pos).toVec3D()/=pos[3];
            pos = zMat*Math::Vec4D(after,1.0f);
            if(!Math::floatEqual(pos[3],0.0f))after = Math::Vec4D(pos).toVec3D()/=pos[3];
            ver.setPosition(after);
        }
    }

    return object;
}

Kie::Object Kie::PipLine::Translate(Kie::Object object) {
    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            Math::Vec3D newPos = ver.getPosition()+object.getPosition();
            ver.setPosition(newPos);
        }
    }
    return object;
}

Kie::Object Kie::PipLine::Illuminate(Kie::Object object) {
    return object;
}

const Kie::Light &Kie::PipLine::getLight() const {
    return light;
}

void Kie::PipLine::setLight(const Kie::Light &light) {
    PipLine::light = light;
}

const Kie::Math::Mat4D &Kie::PipLine::getProMatrix() const {
    return proMatrix;
}

void Kie::PipLine::setProMatrix(const Kie::Math::Mat4D &proMatrix) {
    PipLine::proMatrix = proMatrix;
}

const Kie::Math::Mat4D &Kie::PipLine::getTraMatrix() const {
    return traMatrix;
}

void Kie::PipLine::setTraMatrix(const Kie::Math::Mat4D &traMatrix) {
    PipLine::traMatrix = traMatrix;
}

void Kie::PipLine::updatePromatrix(Kie::Window &window, float near, float far, float fov) {
    float AR = static_cast<float>(window.getHeight()) / static_cast<float>(window.getWidth());
    float FR = 1.0f/std::tan(fov * 0.5f / 180.0f * 3.1415926f);
    proMatrix[0][0] = AR*FR;
    proMatrix[1][1] = FR;
    proMatrix[2][2] = far/(far-near);
    proMatrix[3][2] = (-far*near)/(far-near);
    proMatrix[2][3] = 1.0f;
}

Kie::Object Kie::PipLine::MapToWorld(Kie::Object object) {

    for(auto& tri : object.mesh){
        for(auto& ver:tri.vertex){
            auto oldPos = ver.getPosition();
            ver.setPosition(oldPos+object.getPosition());
        }
    }
    return object;
}

Kie::Object Kie::PipLine::Clipping(Kie::Object object) {
    std::vector<Triangle> vec;
    for(auto& tri:object.mesh) {
        Math::Vec3D line1(tri.vertex[1].getPosition()-tri.vertex[0].getPosition());
        Math::Vec3D line2(tri.vertex[2].getPosition()-tri.vertex[0].getPosition());
        auto result = line1.crossProduct(line2).normalize();
        if(result[2]<0) vec.push_back(tri);
    }
    object.mesh = vec;
    return object;
}
