//
// Created by SunBo on 2019-08-12.
//

#ifndef SUMMERPROJECT_LINE_H
#define SUMMERPROJECT_LINE_H

#include "IDrawable.h"
#include "Color.h"
#include "ITransformable.h"
#include "Point.h"
#include "Math/Math.h"

namespace Kie {
    class Line: public IDrawable, public ITransformable {
    public:
        Line(float x1,float y1,float x2,float y2,Color c=Color(255,255,255));

        Line(Point p1,Point p2);

        Line(bool useInt,int x1,int y1,int x2,int y2,int width,int height,Color c = Color(255,255,255));

        void draw(Window &window) override;

        void setPosition(float x, float y, float z) override;

        void setPosition(bool useInt,int x, int y, int z, int width, int height) override;

        Math::Vec3D getPosition() override;

        void rotate(float degree) override;

        void move(float x, float y, float z) override;

        void resetLineColor(Color c = Color(-1,-1,-1,true));

    private:
        std::array<Point,2> vertex;
        Math::Vec3D pos;
        Color lineColor;
    };
}


#endif //SUMMERPROJECT_LINE_H
