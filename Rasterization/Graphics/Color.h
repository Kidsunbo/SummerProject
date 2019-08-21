//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_COLOR_H
#define SUMMERPROJECT_COLOR_H

#include "Math/Math.h"


namespace Kie {

    /**
     * This is the color class
     */
    class Color {

        friend class InterpColor;
    private:
        float r;
        float g;
        float b;
    public:
        /**
         * The getter for r
         * @return r
         */
        float getR() const;

        /**
         * The getter for g
         * @return g
         */
        float getG() const;

        /**
         * The getter for b
         * @return b
         */
        float getB() const;

    public:
        /**
         * The constructor of the color class, which use integer as parameters
         * @param r The r ranged between 0-255
         * @param g The g ranged between 0-255
         * @param b The b ranged between 0-255
         */
        Color(int r, int g, int b);

        /**
         * Construct the color with three dimension vector
         * @param vec
         */
        explicit Color(const Math::Vec3D& vec);

        /**
         * Construct the color with three float number, if the normalized variable is true, the float number
         * is between 0.0-1.0, otherwise, they could be 0.0-255.0
         * @param r the r
         * @param g the g
         * @param b the b
         * @param normalized if r,g and b is between 0.0-1.0
         */
        Color(float r, float g, float b, bool normalized = true);

        /**
         * Add two colors, maximum value of the r,g and b is 255.
         * @param color The other color
         * @return The result
         */
        Color operator +(Color& color);

        /**
         * Subtract two colors, minimum value of the r,g and b is 0
         * @param color The other color
         * @return The result
         */
        Color operator -(Color& color);

        /**
         * Multiply a number to a color, same range
         * @param num The ratio of the change
         * @return The result
         */
        Color operator* (float num) const;

        /**
         * Convert the r,g and b into a three dimension vector
         * @return The result
         */
        Math::Vec3D toVec3D() const;
    };

    /**
     * This class used to generate the color in a range with a certain amount
     */
    class InterpColor{
        Color c;
        float step_r;
        float step_g;
        float step_b;
        int count;
    public:
        /**
         * Constructor
         * @param start The start color
         * @param end The end color
         * @param count The number of colors should be generated
         */
        InterpColor(const Color& start,const Color& end,int count);

        /**
         * Method used for range for loop
         * @return Itself
         */
        InterpColor& begin();

        /**
         * Method used for range for loop
         * @return Itself
         */
        InterpColor& end();

        /**
         * Method used to compare if the interpolation should end
         * @param other The end of the value, actually, it has no use
         * @return The boolean value
         */
        bool operator !=(InterpColor& other);

        /**
         * The current color
         * @return current color
         */
        Color operator*();

        /**
         * Move to next color and return it
         * @return the current color
         */
        Color operator++();
    };

}


#endif //SUMMERPROJECT_COLOR_H
