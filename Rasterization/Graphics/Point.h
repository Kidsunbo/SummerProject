//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_POINT_H
#define SUMMERPROJECT_POINT_H

#include "Drawable.h"
#include "Color.h"
namespace Kie {
    class Point : public Drawable{
        Color color;
        float x;
        float y;
        bool normalized;
    public:
        Point(int x ,int y,Color c = Color(255,255,255));

        Point(float x, float y, Color c = Color(255,255,255),bool normalized = true);

        void draw(Window &window) override;

    };
}


#endif //SUMMERPROJECT_POINT_H
