//
// Created by bxs863 on 29/07/2019.
//

#ifndef SUMMERPROJECT_ROTATEPROCESSOR_H
#define SUMMERPROJECT_ROTATEPROCESSOR_H


#include <vector>
#include "Shape3D/Triangle.h"

namespace Kie {
    class RotateProcessor {
    public:
        void updateAngleX(float angle);

        void updateAngleY(float angle);

        void updateAngleZ(float angle);

    private:
        float rtime = 0;
        float speed = 0;
    public:
        void setSpeed(float speed);

    private:
        float rotate_x[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
        float rotate_y[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
        float rotate_z[3][3] = {{1,0,0},{0,1,0},{0,0,1}};

        static void multiMat3X3(float(&m1)[3][3], Vec3D& ver);
    public:

        explicit RotateProcessor(float speed);


        void rotate(std::vector<Triangle>& tris, unsigned short axis);
    };
}


#endif //SUMMERPROJECT_ROTATEPROCESSOR_H
