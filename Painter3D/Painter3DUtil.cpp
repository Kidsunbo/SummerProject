//
// Created by bxs863 on 28/07/2019.
//

#include "Painter3DUtil.h"

std::vector<Kie::Triangle> Kie::Painter3DUtil::meshToTris(std::vector<Mesh> &meshes) {
    std::vector<Triangle> tris;
    for(auto& mesh:meshes){
        for(auto& tri:mesh.tris){
            tris.push_back(tri);
        }
    }
    return tris;
}
