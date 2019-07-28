//
// Created by bxs863 on 28/07/2019.
//

#include "Projector.h"


Kie::Projector::Projector(Kie::Painter &painter, float Near, float Far, float Fov):Near(Near),Far(Far),Fov(Fov){
    AR = static_cast<float>(painter.getHeight())/ static_cast<float>(painter.getWidth());
    FR = 1.0f / std::tan(Fov * 0.5f / 180.0f * 3.1415926f);
    matProj[0][0] = AR*FR;
    matProj[1][1]=FR;
    matProj[2][2]=Far/(Far-Near);
    matProj[3][2]=(-Far*Near)/(Far-Near);
    matProj[2][3]=1.0f;
    matProj[3][3] =0.0f;
}

std::vector<Kie::Triangle> Kie::Projector::projection(std::vector<Mesh> &meshes) {
    std::vector<Triangle> vec;
    for(auto& mesh:meshes){
        for(auto& tri : mesh.tris){
            Triangle rTri;
            for(int i =0;i<3;i++){
                rTri.vers[i] = multiplyMat(tri.vers[i]);
            }
            vec.push_back(rTri);
        }
    }

    return vec;
}

Kie::Vertex Kie::Projector::multiplyMat(Kie::Vertex &mat) {
    Vertex r;
    r.x = mat.x*matProj[0][0]+mat.y*matProj[1][0]+mat.z*matProj[2][0]+matProj[3][0];
    r.y = mat.x*matProj[0][1]+mat.y*matProj[1][1]+mat.z*matProj[2][1]+matProj[3][1];
    r.z = mat.x*matProj[0][2]+mat.y*matProj[1][2]+mat.z*matProj[2][2]+matProj[3][2];
    float w = mat.x*matProj[0][3]+mat.y*matProj[1][3]+mat.z*matProj[2][3]+matProj[3][3];
    if(w!=0.0f){
        r.x/=w;r.y/=w;r.z/=w;
    }
    return r;
}
