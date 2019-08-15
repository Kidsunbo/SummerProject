//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_LIGHT_H
#define SUMMERPROJECT_LIGHT_H

#include "Math/Math.h"
#include "Color.h"
namespace Kie {
    class Light {
    private:
        Color lightColor;
        Math::Vec3D lightPos;
        float ambientStrength = 0.1f;
    public:
        float getAmbientStrength() const;

        void setAmbientStrength(float ambientStrength);

        const Color &getLightColor() const;

        void setLightColor(const Color &lightColor);

        const Math::Vec3D &getLightPos() const;

        void setLightPos(const Math::Vec3D &lightPos);

    public:
        Light();

        explicit Light(const Color& color);

        explicit Light(const Math::Vec3D& pos);

        Light(const Color& color,const Math::Vec3D& pos);

        Light(Math::Vec3D pos,const Color& color);



    };

}


#endif //SUMMERPROJECT_LIGHT_H
