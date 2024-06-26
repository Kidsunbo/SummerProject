//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_POINT_H
#define SUMMERPROJECT_POINT_H

#include "i_drawable.h"
#include "color.h"
#include "i_transformable.h"
#include "math/math.h"
#include <memory>

namespace Kie {

    /**
     * This is the point class which is the base of this library
     */
    class Point : public IDrawable, public ITransformable{
        Color color;
        math::Vec2D texture;
        std::shared_ptr<float> z = nullptr;
    public:
        const math::Vec2D &getTexture() const;

        void setTexture(const math::Vec2D &texture);

        Point(float x, float y, float z, Color c = Color(255,255,255));

        Point(const Point& point);

        explicit Point(Point&& point);

        Point&operator=(const Point& point);

        Point&operator=(Point&& point)noexcept;

        void draw(Window &window) override;

        const Color &getColor();

        void setColor(Color c);
        
        float getZ() const;
        
        void setZ(float value);
    };
}


#endif //SUMMERPROJECT_POINT_H
