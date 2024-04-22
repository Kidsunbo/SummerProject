//
// Created by bxs863 on 14/08/2019.
//

#ifndef SUMMERPROJECT_LIGHT_H
#define SUMMERPROJECT_LIGHT_H

#include "math/math.h"
#include "color.h"
namespace Kie {
    /**
     * This is the light class of the object
     */
    class Light {
    private:
        Color lightColor;
        math::Vec3D lightPos;
        float ambientStrength = 0.1f;
    public:
        /**
         * This is the getter for ambient strength
         * @return the ambient strength
         */
        float getAmbientStrength() const;

        /**
         * This is the setter of the ambient strength
         * @param ambientStrength the new value
         */
        void setAmbientStrength(float ambientStrength);

        /**
         * Getter for the light color
         * @return The color of the light
         */
        const Color &getLightColor() const;

        /**
         * The setter of the light color
         * @param lightColor The new color
         */
        void setLightColor(const Color &lightColor);


        /**
         * The getter of the position
         * @return The position of the light
         */
        const math::Vec3D &getLightPos() const;


        /**
         * The setter of the position
         * @param lightPos The position of the light
         */
        void setLightPos(const math::Vec3D &lightPos);

    public:
        /**
         * The default constructor, which is used to create a light in the origin position
         */
        Light();

        /**
         * Overloading
         * @param color The initial color of the light
         */
        explicit Light(const Color& color);

        /**
         * Overloading
         * @param pos The initial position of the light
         */
        explicit Light(const math::Vec3D& pos);

        /**
         * Overloading
         * @param color The color of the light
         * @param pos The pos of the light
         */
        Light(const Color& color,const math::Vec3D& pos);

        /**
         * Same with the previous one but in different order
         * @param pos The position
         * @param color The color
         */
        Light(math::Vec3D pos,const Color& color);



    };

}


#endif //SUMMERPROJECT_LIGHT_H
