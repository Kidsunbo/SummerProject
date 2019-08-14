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
    public:
        Point(float x, float y, Color c = Color(255,255,255));

        Point(float x, float y, float z, Color c = Color(255,255,255));

        void draw(Window &window) override;

        const Color &getColor();

        void setColor(Color c);
    };
}


#endif //SUMMERPROJECT_POINT_H
