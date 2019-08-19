//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_POINT_H
#define SUMMERPROJECT_POINT_H

#include "IDrawable.h"
#include "Color.h"
#include "ITransformable.h"
#include "Math/Math.h"
#include <memory>

namespace Kie {
    class Point : public IDrawable, public ITransformable{
        Color color;
        Math::Vec2D texture;
        std::shared_ptr<float> z = nullptr;
    public:
        const Math::Vec2D &getTexture() const;

        void setTexture(const Math::Vec2D &texture);

        Point(float x, float y, float z, Color c = Color(255,255,255));

        void draw(Window &window) override;

        const Color &getColor();

        void setColor(Color c);
        
        float getZ();
        
        void setZ(float value);
    };
}


#endif //SUMMERPROJECT_POINT_H
