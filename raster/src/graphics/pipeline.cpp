//
// Created by bxs863 on 14/08/2019.
//

#include "graphics/pipeline.h"
#include "window/window.h"
#include <cmath>


Kie::PipeLine::PipeLine(Window& window, float near, float far, float fov, Kie::Color lightColor, const Kie::math::Vec3D& pos):
light(lightColor,pos),
proMatrix(0.0f),
rotXMatrix({{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}}),
rotYMatrix({{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}}),
rotZMatrix({{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}}),
traMatrix(0.0f)
{
    updatePromatrix(window, near, far, fov);
}

std::shared_ptr<Kie::PipeLine> Kie::PipeLine::pp = nullptr;

Kie::PipeLine& Kie::PipeLine::getInstance(Kie::Window &window) {
    if(pp== nullptr) pp = std::make_shared<PipeLine>(window);
    return *pp;
}

Kie::Object Kie::PipeLine::Projection(Kie::Object object) {
    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            auto pos = proMatrix*math::Vec4D(ver.getPosition(),1.0f);
            float w = pos[0]*proMatrix[0][3]+pos[1]*proMatrix[1][3]+pos[2]*proMatrix[2][3]+proMatrix[3][3];
            auto after = math::Vec4D(pos).toVec3D();
            if(!math::floatEqual(w,0.0f))
                after/=w;
            ver.setPosition(after);
        }
    }
    return object;
}

Kie::Object Kie::PipeLine::Rotate(Kie::Object object) {
    Kie::math::Mat4D xMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
    xMat[1][1] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    xMat[1][2] = -std::sin(object.rotateXDegree/180.0f*3.1415926f);
    xMat[2][1] = std::sin(object.rotateXDegree/180.0f*3.1415926f);
    xMat[2][2] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    Kie::math::Mat4D yMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
    yMat[0][0] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    yMat[0][2] = -std::sin(object.rotateYDegree/180.0f*3.1415926f);
    yMat[2][0] = std::sin(object.rotateYDegree/180.0f*3.1415926f);
    yMat[2][2] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    Kie::math::Mat4D zMat = {{1.0f,0.0f,0.0f,0.0f},{0.0f,1.0f,0.0f,0.0f},{0.0f,0.0f,1.0f,0.0f},{0.0f,0.0f,0.0f,1.0f}};
   zMat[0][0] = std::cos(object.rotateZDegree/180.0f*3.1415926f);
   zMat[0][1] = -std::sin(object.rotateZDegree/180.0f*3.1415926f);
   zMat[1][0] = std::sin(object.rotateZDegree/180.0f*3.1415926f);
   zMat[1][1] = std::cos(object.rotateZDegree/180.0f*3.1415926f);

    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            auto pos = xMat*math::Vec4D(ver.getPosition(),1.0f);
            math::Vec3D after(0);
            if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
            pos = yMat*math::Vec4D(after,1.0f);
            if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
            pos = zMat*math::Vec4D(after,1.0f);
            if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
            ver.setPosition(after);
        }
    }

    return object;
}

Kie::Object Kie::PipeLine::Transform(Kie::Object object) {
    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            math::Vec3D newPos = ver.getPosition()+object.getPosition();
            ver.setPosition(newPos);
        }
    }
    return object;
}

Kie::Object Kie::PipeLine::Clip(Object object){
    for(auto& tri:object.mesh){
        Clip(tri);
    }
    return object;
}

Kie::Object Kie::PipeLine::Illuminate(Kie::Object object) {
    //Ambient
    math::Vec3D ambient = (light.getLightColor()*light.getAmbientStrength()).toVec3D();
    for(auto& tri:object.mesh){
        for(auto& ver:tri.vertex){
            //Diffuse
            math::Vec3D lightDir = (light.getLightPos()-ver.getPosition()).normalize(); // duplicate calculation
            math::Vec3D line1(tri.vertex[1].getPosition()-tri.vertex[0].getPosition());
            math::Vec3D line2(tri.vertex[2].getPosition()-tri.vertex[0].getPosition());
            auto normal = line1.crossProduct(line2).normalize();
            float diff = std::max(normal.dotProduct(lightDir),0.0f);
            math::Vec3D diffuse = (light.getLightColor()*diff).toVec3D();

            ver.setColor(Color(static_cast<math::Vec3D>((ambient+diffuse)*ver.getColor().toVec3D())));
        }
    }

    return object;
}

 Kie::Light &Kie::PipeLine::getLight() {
    return light;
}

void Kie::PipeLine::setLight(const Kie::Light &light) {
    PipeLine::light = light;
}

const Kie::math::Mat4D &Kie::PipeLine::getProMatrix() const {
    return proMatrix;
}

void Kie::PipeLine::setProMatrix(const Kie::math::Mat4D &proMatrix) {
    PipeLine::proMatrix = proMatrix;
}

const Kie::math::Mat4D &Kie::PipeLine::getTraMatrix() const {
    return traMatrix;
}

void Kie::PipeLine::setTraMatrix(const Kie::math::Mat4D &traMatrix) {
    PipeLine::traMatrix = traMatrix;
}

void Kie::PipeLine::updatePromatrix(Kie::Window &window, float near, float far, float fov) {
    float AR = static_cast<float>(window.getHeight()) / static_cast<float>(window.getWidth());
    float FR = 1.0f/std::tan(fov * 0.5f / 180.0f * 3.1415926f);
    proMatrix[0][0] = AR*FR;
    proMatrix[1][1] = FR;
    proMatrix[2][2] = far/(far-near);
    proMatrix[3][2] = (-far*near)/(far-near);
    proMatrix[2][3] = 1.0f;
}

Kie::Object Kie::PipeLine::MapToWorld(Kie::Object object) {

    for(auto& tri : object.mesh){
        for(auto& ver:tri.vertex){
            auto oldPos = ver.getPosition();
            ver.setPosition(oldPos+object.getPosition());
        }
    }
    return object;
}

Kie::Object Kie::PipeLine::Culling(Kie::Object object) {
    std::vector<Triangle> vec;
    for(auto& tri:object.mesh) {
        math::Vec3D line1(tri.vertex[1].getPosition()-tri.vertex[0].getPosition());
        math::Vec3D line2(tri.vertex[2].getPosition()-tri.vertex[0].getPosition());
        auto result = line1.crossProduct(line2).normalize();
        if(result[2]<0) vec.push_back(tri);
    }
    object.mesh = vec;
    return object;
}

void Kie::PipeLine::Projection(Kie::Triangle &triangle) {
    for(auto& ver:triangle.vertex){
        auto pos = proMatrix*math::Vec4D(ver.getPosition(),1.0f);
        float w = pos[0]*proMatrix[0][3]+pos[1]*proMatrix[1][3]+pos[2]*proMatrix[2][3]+proMatrix[3][3];
        auto after = math::Vec4D(pos).toVec3D();
        if(!math::floatEqual(w,0.0f))
            after/=w;
        ver.setPosition(after);
    }
}

void Kie::PipeLine::Rotate(Kie::Triangle &triangle) {
    for(auto& ver:triangle.vertex){
        auto pos = rotXMatrix*math::Vec4D(ver.getPosition(),1.0f);
        math::Vec3D after(0);
        if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
        pos = rotYMatrix*math::Vec4D(after,1.0f);
        if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
        pos = rotZMatrix*math::Vec4D(after,1.0f);
        if(!math::floatEqual(pos[3],0.0f))after = math::Vec4D(pos).toVec3D()/=pos[3];
        ver.setPosition(after);
    }
}

void Kie::PipeLine::Transform(Kie::Triangle &triangle, Object& object) {
    for(auto& ver:triangle.vertex){
        math::Vec3D newPos = ver.getPosition()+object.getPosition();
        ver.setPosition(newPos);
    }
}

void Kie::PipeLine::SetupRotateMatrix(Object& object) {
    rotXMatrix[1][1] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    rotXMatrix[1][2] = -std::sin(object.rotateXDegree/180.0f*3.1415926f);
    rotXMatrix[2][1] = std::sin(object.rotateXDegree/180.0f*3.1415926f);
    rotXMatrix[2][2] = std::cos(object.rotateXDegree/180.0f*3.1415926f);
    rotYMatrix[0][0] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    rotYMatrix[0][2] = -std::sin(object.rotateYDegree/180.0f*3.1415926f);
    rotYMatrix[2][0] = std::sin(object.rotateYDegree/180.0f*3.1415926f);
    rotYMatrix[2][2] = std::cos(object.rotateYDegree/180.0f*3.1415926f);
    rotZMatrix[0][0] = std::cos(object.rotateZDegree/180.0f*3.1415926f);
    rotZMatrix[0][1] = -std::sin(object.rotateZDegree/180.0f*3.1415926f);
    rotZMatrix[1][0] = std::sin(object.rotateZDegree/180.0f*3.1415926f);
    rotZMatrix[1][1] = std::cos(object.rotateZDegree/180.0f*3.1415926f);
}

void Kie::PipeLine::Illuminate(Kie::Triangle &triangle) {
    math::Vec3D ambient = (light.getLightColor()*light.getAmbientStrength()).toVec3D();
    math::Vec3D line1(triangle.vertex[1].getPosition()-triangle.vertex[0].getPosition());
    math::Vec3D line2(triangle.vertex[2].getPosition()-triangle.vertex[0].getPosition());
    auto normal = line1.crossProduct(line2).normalize();

    for(auto& ver:triangle.vertex){
        //Diffuse
        math::Vec3D lightDir = (light.getLightPos()-ver.getPosition()).normalize(); // duplicate calculation
        float diff = std::max(normal.dotProduct(lightDir),0.0f);
        math::Vec3D diffuse = (light.getLightColor()*diff).toVec3D();
        ver.setColor(Color(static_cast<math::Vec3D>((ambient+diffuse)*ver.getColor().toVec3D())));
    }
}

void Kie::PipeLine::MapToWorld(Kie::Triangle &triangle, Object& object) {
    for(auto& ver:triangle.vertex){
        auto oldPos = ver.getPosition();
        ver.setPosition(oldPos+object.getPosition());
    }
}

bool Kie::PipeLine::Culling(Kie::Triangle &triangle) {
    math::Vec3D line1(triangle.vertex[1].getPosition()-triangle.vertex[0].getPosition());
    math::Vec3D line2(triangle.vertex[2].getPosition()-triangle.vertex[0].getPosition());
    auto result = line1.crossProduct(line2).normalize();
    return result[2]>=0;
}

Kie::Camera &Kie::PipeLine::getCamera() {
    return camera;
}

void Kie::PipeLine::setCamera(const Kie::Camera &camera) {
    this->camera = camera;
}

void Kie::PipeLine::MapToView(Kie::Triangle &triangle) {
    for(auto& ver:triangle.vertex){
        auto oldPos = ver.getPosition();
        ver.setPosition(math::Vec4D(camera.getView()*math::Vec4D(oldPos,1.0f)).toVec3D());
    }
}

Kie::Object Kie::PipeLine::MapToView(Kie::Object object) {
    for(auto& tri:object.mesh){
        MapToView(tri);
    }
    return object;
}

bool Kie::PipeLine::Clip(Triangle& triangle){
    for(auto& ver:triangle.vertex){
        if(ver.getZ()<=0.5f) return true;
    }
    return false;
}

//std::vector<Kie::Triangle> Kie::PipeLine::Clip(Triangle& triangle){
//    std::vector<Point> inner;
//    std::vector<Point> outer;
//    planeN = planeN.normalize();
//
//    float d1 = dist(triangle.vertex[0]);
//    float d2 = dist(triangle.vertex[1]);
//    float d3 = dist(triangle.vertex[2]);
//
//    if(d1>=0) inner.push_back(triangle.vertex[0]);
//    else outer.push_back(triangle.vertex[0]);
//    if(d2>=0) inner.push_back(triangle.vertex[1]);
//    else outer.push_back(triangle.vertex[1]);
//    if(d3>=0) inner.push_back(triangle.vertex[2]);
//    else outer.push_back(triangle.vertex[2]);
//    std::cout<<outer.size()<<std::endl;
//    if(inner.size()==0) return{};
//    if(inner.size()==3) return{triangle};
//    if(inner.size()==1 && outer.size()==2){
//        Triangle result = triangle;
//        Point p1 = inner.at(0);
//        Point p2 = intersetctPlane(planeP,planeN,inner.at(0),outer.at(0));
//        Point p3 = intersetctPlane(planeP,planeN,inner.at(0),outer.at(1));
//        result.setVertex({p1,p2,p3});
//        return {result};
//    }
//    if(inner.size()==2 && outer.size()==1){
//        Triangle result1 = triangle;
//        Triangle result2 = triangle;
//        Point pp1 = intersetctPlane(planeP,planeN,inner.at(0),outer.at(0));
//        result1.setVertex({inner.at(0),inner.at(1),pp1});
//        result2.setVertex({inner.at(1),pp1,intersetctPlane(planeP,planeN,inner.at(1),outer.at(0))});
//        return {result1,result2};
//    }
//    return {};
//}

//float Kie::PipeLine::dist(Kie::Point &p) {
//    auto p1 = p.getPosition();
//    p1[2]=p.getZ();
//    auto n = p1.normalize();
//    return (planeN.getX()*p1.getX()+planeN.getY()*p1.getY()+planeN.getZ()*p1.getZ()-planeN.dotProduct(planeP));
//}


//Kie::Point
//Kie::PipeLine::intersetctPlane(math::Vec3D &plane, Kie::math::Vec3D &planeN, Kie::Point &start, Kie::Point &end) {
//    planeN = planeN.normalize();
//    float dis = -planeN.dotProduct(plane);
//    auto startPos = start.getPosition();
//    startPos[2] = start.getZ();
//    float aDis = startPos.dotProduct(planeN);
//    auto endPos = end.getPosition();
//    endPos[2] = end.getZ();
//    float bDis = endPos.dotProduct(planeN);
//    float t = (-dis-aDis)/(bDis-aDis);
//    math::Vec3D totalLength = endPos-startPos;
//    math::Vec3D clipped = totalLength*t;
//    math::Vec3D pointPos = startPos+clipped;
//    float newR = start.getColor().getR() + (end.getColor().getR() - start.getColor().getR()) * t;
//    float newG = start.getColor().getG() + (end.getColor().getG() - start.getColor().getG()) * t;
//    float newB = start.getColor().getB() + (end.getColor().getB() - start.getColor().getB()) * t;
//    float newTx = start.getTexture()[0]+(end.getTexture()[0]-start.getTexture()[0])*t;
//    float newTy = start.getTexture()[1]+(end.getTexture()[1]-start.getTexture()[1])*t;
//    auto result = Point(pointPos.getX(),pointPos.getY(),pointPos.getZ(),Color(newR,newG,newB));
//    result .setTexture({newTx,newTy});
//    return result;
//}




