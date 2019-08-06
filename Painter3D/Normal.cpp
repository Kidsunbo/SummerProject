//
// Created by bxs863 on 05/08/2019.
//

#include "Normal.h"
#include <cmath>


Kie::Vec3D Kie::Normal::normal(Kie::Triangle &triangle) {
    Vec3D lineA,lineB;
    lineA.x= triangle.vers[1].x-triangle.vers[0].x;
    lineA.y= triangle.vers[1].y-triangle.vers[0].y;
    lineA.z= triangle.vers[1].z-triangle.vers[0].z;
    lineB.x= triangle.vers[2].x-triangle.vers[0].x;
    lineB.y= triangle.vers[2].y-triangle.vers[0].y;
    lineB.z= triangle.vers[2].z-triangle.vers[0].z;
    Vec3D result = crossProduct(lineA,lineB);
    float l = std::sqrt(result.x*result.x+result.y*result.y+result.z*result.z);
    if(l!=0) {
        result.x /= l;
        result.y /= l;
        result.z /= l;
    }
    return result;
}

Kie::Vec3D
Kie::Normal::crossProduct(const Vec3D& a,const Vec3D& b) {
    Vec3D normal;
    normal.x = a.y*b.z-a.z*b.y;
    normal.y = a.z*b.x-a.x*b.z;
    normal.z = a.x*b.y-a.y*b.x;
    return normal;
}
