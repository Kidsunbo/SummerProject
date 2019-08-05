//
// Created by bxs863 on 28/07/2019.
//

#include "ProjectionProcessor.h"


Kie::ProjectionProcessor::ProjectionProcessor(Kie::Painter &painter, float Near, float Far, float Fov): Near(Near), Far(Far), Fov(Fov){
    if(Near!=Far) {
        AR = static_cast<float>(painter.getHeight()) / static_cast<float>(painter.getWidth());
        FR = 1.0f / std::tan(Fov * 0.5f / 180.0f * 3.1415926f);
        matProj[0][0] = AR * FR;
        matProj[1][1] = FR;
        matProj[2][2] = Far / (Far - Near);
        matProj[3][2] = (-Far * Near) / (Far - Near);
        matProj[2][3] = 1.0f;
        distance = Near;
    }
}

void Kie::ProjectionProcessor::projection(std::vector<Triangle> &tris) {
    for(auto& tri : tris){
        for(auto & ver : tri.vers){
            ver.z+=distance;
            ver = multiplyMat(ver);
        }
    }
}

Kie::Vec3D Kie::ProjectionProcessor::multiplyMat(Kie::Vec3D &mat) {
    Vec3D r;
    r.x = mat.x*matProj[0][0]+mat.y*matProj[1][0]+mat.z*matProj[2][0]+matProj[3][0];
    r.y = mat.x*matProj[0][1]+mat.y*matProj[1][1]+mat.z*matProj[2][1]+matProj[3][1];
    r.z = mat.x*matProj[0][2]+mat.y*matProj[1][2]+mat.z*matProj[2][2]+matProj[3][2];
    float w = mat.x*matProj[0][3]+mat.y*matProj[1][3]+mat.z*matProj[2][3]+matProj[3][3];
    if(w!=0.0f){
        r.x/=w;r.y/=w;r.z/=w;
    }
    return r;
}

void Kie::ProjectionProcessor::updateMatProj(Painter& painter,float Near, float Far, float Fov) {
    AR = static_cast<float>(painter.getHeight())/ static_cast<float>(painter.getWidth());
    FR = 1.0f / std::tan(Fov * 0.5f / 180.0f * 3.1415926f);
    matProj[0][0] = AR*FR;
    matProj[1][1]=FR;
    matProj[2][2]=Far/(Far-Near);
    matProj[3][2]=(-Far*Near)/(Far-Near);
    matProj[2][3]=1.0f;
}

void Kie::ProjectionProcessor::setDistance(float distance) {
    ProjectionProcessor::distance = distance;
}
