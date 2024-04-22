//
// Created by SunBo on 2019-08-12.
//

#ifndef SUMMERPROJECT_LINE_H
#define SUMMERPROJECT_LINE_H

#include "i_drawable.h"
#include "color.h"
#include "i_transformable.h"
#include "point.h"
#include "texture.h"

#include <memory>

namespace Kie {
    /**
     * This is the class for Line
     */
    class Line: public IDrawable, public ITransformable {
    public:
        /**
         * Constructor,z value could be zero as default
         * @param x1 The start x value
         * @param y1 The start y value
         * @param x2 The end x value
         * @param y2 The end y value
         * @param c The color of the line
         */
        Line(float x1,float y1,float x2,float y2,Color c=Color(255,255,255));

        /**
         * The constructor, z value could be zero, but the points contains there own and the z value could be calculate
         * latter
         * @param p1 The start point
         * @param p2 The end point
         * @param c The color, which is default none, if the color is none, the color will be calculated with
         * interpolation
         */
        Line(Point p1,Point p2, Color c=Color(-1,-1,-1,true));

        /**
         * The constructor
         * @param p1 The first point
         * @param p2 The second point
         * @param texture The texture, which is used to add some texture into the line
         */
        Line(Point p1,Point p2,std::shared_ptr<Texture> texture);

        /**
         * The override version of the drawable interface
         * @param window The window
         */
        void draw(Window &window) override;

        /**
         * Reset the Color of the line
         * @param c new Color
         */
        void resetLineColor(Color c = Color(-1.0f,-1.0f,-1.0f,true));

    private:
        std::array<Point,2> vertex;
        Color lineColor;
        bool useTexture = false;
        std::shared_ptr<Texture> texture;
    };
}


#endif //SUMMERPROJECT_LINE_H
