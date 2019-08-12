//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_POINT_H
#define SUMMERPROJECT_POINT_H

#include "IDrawable.h"
#include "Color.h"
#include "ITransformable.h"
#include "Math/Math.h"

namespace Kie {
    class Point : public IDrawable, public ITransformable{
        Color color;
        Math::Vec3D pos;
    public:
        Point(bool useInt,int x ,int y,int width,int height,Color c = Color(255,255,255));

        Point(float x, float y, Color c = Color(255,255,255));

        void draw(Window &window) override;

        void setPosition(float x, float y, float z=0.0f) override;

        void setPosition(bool useInt,int x, int y, int z,int width,int height) override;

        Math::Vec3D getPosition() override;

        void rotate(float degree) override;

        const Color &getColor() const;

        void move(float x, float y, float z=0.0f) override;


    };
}


#endif //SUMMERPROJECT_POINT_H
