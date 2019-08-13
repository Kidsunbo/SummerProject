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

        void draw(Window &window) override;

        void resetLineColor(Color c = Color(-1.0f,-1.0f,-1.0f,true));

    private:
        std::array<Point,2> vertex;
        Color lineColor;
    };
}


#endif //SUMMERPROJECT_LINE_H
