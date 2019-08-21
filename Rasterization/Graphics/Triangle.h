//
// Created by SunBo on 2019-08-13.
//

#ifndef SUMMERPROJECT_TRIANGLE_H
#define SUMMERPROJECT_TRIANGLE_H

#include "Math/Math.h"
#include "IDrawable.h"
#include "ITransformable.h"
#include "Line.h"
#include "Texture.h"

#include <memory>

namespace Kie {
    class Triangle: public IDrawable, public ITransformable {
        friend class Object;
        friend class PipeLine;

    public:
        Triangle(Point p1,Point p2,Point p3, bool fill=false, Color filledColor=Color(-1,-1,-1,true));

        Triangle(Point p1,Point p2,Point p3, bool useTexure, std::shared_ptr<Texture> texture);

        Triangle(const Triangle& triangle);

        Triangle(Triangle& triangle);

        Triangle&operator=(const Triangle& triangle);

        Triangle&operator=(Triangle&& triangle);

        void draw(Window &window) override;

        void resetFilledColor(bool fill,Color c=Color(-1,-1,-1,true));
        
        void setVertex(const std::array<Point,3>& vertex);

    private:
        void _drawWithoutFill(Window& window);

        void _drawWithFill(Window& window);

        void _fillTopTriangle(Window& window,Point& p1,Point& p2,Point& p3);

        void _fillBottomTriangle(Window& window,Point& p1,Point& p2,Point& p3);

    private:
        std::array<Point,3> vertex;
        Color fillColor;
        bool fill=false;
        bool useTexture = false;
        std::shared_ptr<Texture> texture= nullptr;
    };
}


#endif //SUMMERPROJECT_TRIANGLE_H
