//
// Created by bxs863 on 05/08/2019.
//

#include "UtilStruct.h"
#include "Light.h"
#include <cmath>
#include <iostream>

Kie::Light::Light(float x, float y, float z, Kie::Color c, float strength) :x(x),y(y),z(z),strength(strength){
    color.x = static_cast<float>(c.r)/255.0f;
    color.y = static_cast<float>(c.g)/255.0f;
    color.z = static_cast<float>(c.b)/255.0f;
}

void Kie::Light::illuminate(Kie::Color &c,Vec3D normal,Triangle& triangle) {
    //Ambient Lighting
    //Apply Strength
    Vec3D ambient = {color.x*strength,color.y*strength,color.z*strength};
    triangle.color.r = static_cast<int>(ambient.x* static_cast<float>(c.r));
    triangle.color.g = static_cast<int>(ambient.y* static_cast<float>(c.g));
    triangle.color.b = static_cast<int>(ambient.z* static_cast<float>(c.b));

    //Apply Light Color
//    c.r = static_cast<int>(static_cast<float>(c.r)*color.x);
//    c.g = static_cast<int>(static_cast<float>(c.g)*color.y);
//    c.b = static_cast<int>(static_cast<float>(c.b)*color.z);


};

void Kie::Light::normalize(Kie::Vec3D &vec) {
    float l = std::sqrt(vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
    vec.x/=l;vec.y/=l;vec.z/=l;
}

float Kie::Light::dot(Vec3D& vec1,Vec3D& vec2){
    return vec1.x*vec2.x+vec1.y*vec2.y+vec1.z*vec2.z;
}

void Kie::Light::setColor(const Kie::Vec3D &color) {
    Light::color = color;
}

void Kie::Light::setStrength(float strength) {
    Light::strength = strength;
}

void Kie::Light::illuminate(Kie::Color color, std::vector<Triangle>& vector,Normal& nm) {
    for(auto& tri:vector) illuminate(color,nm.normal(tri),tri);
}




