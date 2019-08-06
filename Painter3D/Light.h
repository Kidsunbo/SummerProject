//
// Created by bxs863 on 05/08/2019.
//

#ifndef SUMMERPROJECT_LIGHT_H
#define SUMMERPROJECT_LIGHT_H

#include "Normal.h"
#include "Shape3D/Vec3D.h"
#include "Shape3D/Triangle.h"

namespace Kie {
    class Light {

        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        Vec3D color;
        float strength;
    public:
        void setColor(const Vec3D &color);

        void setStrength(float strength);

    private:


        void normalize(Vec3D& vec);

        float dot(Vec3D& vec1,Vec3D& vec2);

    public:


        Light(float x, float y, float z, Color c = Color::from(255,255,255),float strength = 1.0f);

        void illuminate(Color& c,Vec3D normal,Triangle& triangle);

        void illuminate(Color color, std::vector<Triangle>& vector,Normal& nm);
    };
}


#endif //SUMMERPROJECT_LIGHT_H
