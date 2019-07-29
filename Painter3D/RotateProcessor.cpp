//
// Created by bxs863 on 29/07/2019.
//

#include "RotateProcessor.h"
#include <cmath>

void Kie::RotateProcessor::rotate(std::vector<Triangle> &tris, unsigned short axis) {
    rtime+=speed;
    if((axis&0b001)!=0){
        updateAngleX(rtime);
        for(auto& tri:tris)
            for(auto& ver : tri.vers)
                multiMat3X3(rotate_x, ver);
    }
    if((axis&0b010)!=0){
        updateAngleY(rtime);
        for(auto& tri:tris)
            for(auto& ver : tri.vers)
                multiMat3X3(rotate_y, ver);
    }
    if((axis&0b100)!=0){
        updateAngleZ(rtime);
        for(auto& tri:tris)
            for(auto& ver : tri.vers)
                multiMat3X3(rotate_z, ver);
    }
}

Kie::RotateProcessor::RotateProcessor(float speed):speed(speed) {

}


void Kie::RotateProcessor::multiMat3X3(float (&m1)[3][3], Vertex& ver ) {

    float x = m1[0][0]*ver.x+m1[0][1]*ver.y+m1[0][2]*ver.z;
    float y = m1[1][0]*ver.x+m1[1][1]*ver.y+m1[1][2]*ver.z;
    float z = m1[2][0]*ver.x+m1[2][1]*ver.y+m1[2][2]*ver.z;
    ver.x=x;
    ver.y=y;
    ver.z=z;
}

void Kie::RotateProcessor::updateAngleZ(float angle) {
    rotate_x[0][0] = std::cos(angle/360.0f*3.1415926f);
    rotate_x[0][1] = -std::sin(angle/360.0f*3.1415926f);
    rotate_x[1][0] = std::sin(angle/360.0f*3.1415926f);
    rotate_x[1][1] = std::cos(angle/360.0f*3.1415926f);
}

void Kie::RotateProcessor::updateAngleY(float angle) {
    rotate_x[0][0] = std::cos(angle/360.0f*3.1415926f);
    rotate_x[0][2] = -std::sin(angle/360.0f*3.1415926f);
    rotate_x[2][0] = std::sin(angle/360.0f*3.1415926f);
    rotate_x[2][2] = std::cos(angle/360.0f*3.1415926f);
}

void Kie::RotateProcessor::updateAngleX(float angle) {
    rotate_x[1][1] = std::cos(angle/360.0f*3.1415926f/2);
    rotate_x[1][2] = -std::sin(angle/360.0f*3.1415926f/2);
    rotate_x[2][1] = std::sin(angle/360.0f*3.1415926f/2);
    rotate_x[2][2] = std::cos(angle/360.0f*3.1415926f/2);
}

void Kie::RotateProcessor::setSpeed(float speed) {
    RotateProcessor::speed = speed;
}





