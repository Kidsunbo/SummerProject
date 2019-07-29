//
// Created by bxs863 on 29/07/2019.
//

#include "ScaleProcessor.h"

void Kie::ScaleProcessor::scale(Painter& painter,std::vector<Triangle> &tris) {
    auto height = painter.getHeight();
    auto width = painter.getWidth();
    for(auto& tri : tris){
        for(auto & ver : tri.vers){
           ver.x+=1.0f;
           ver.x*=0.5f*width;
           ver.y+=1.0f;
           ver.y*=0.5f*height;
        }
    }
}

