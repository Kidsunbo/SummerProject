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

Kie::Color Kie::Light::illuminate(Kie::Color &col,Vec3D normal,Triangle& triangle) {
    //Ambient Lighting
    //Apply Strength
    Color c;
    Vec3D ambient = {color.x*strength,color.y*strength,color.z*strength};

    //Diffuse
    Vec3D v = {x-(triangle.vers[0].x+triangle.vers[1].x+triangle.vers[2].x)/3/640,
               y-(triangle.vers[0].y+triangle.vers[1].y+triangle.vers[2].y)/3/480,
               z-(triangle.vers[0].z+triangle.vers[1].z+triangle.vers[2].z)/3/10};
    normalize(v);
    float diff = dot(v,normal);
    //diff*=100;
    diff=std::max(diff,0.0f);
    std::cout<<diff*color.x<<std::endl;

    c.r=col.r*std::min(diff*color.x*ambient.x,1.0f);
    c.g=col.g*std::min(diff*color.y*ambient.y,1.0f);
    c.b=col.b*std::min(diff*color.z*ambient.z,1.0f);
    return c;
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





