//
// Created by bxs863 on 02/07/2019.
//

#ifndef TEST_UTILSTRUCT_H
#define TEST_UTILSTRUCT_H


namespace Kie {
/**
 * This is the inner class Color which will store the color information for each pixel.
 * This inner class is private which can only be created by function createColor
 *
 * @see Painter#createColor
 */
    struct Color {
        int r = 255;
        int g = 255;
        int b = 255;

/**
* This is the function for creating a color object.
* @param r The red value
* @param g The green value
* @param b The blue value
* @return The color object
*/
        static Color from(int r, int g, int b) {
            return Color{r, g, b};
        }
    };

/**
 * This is the class for vertex point of 2D and 3D objects.
 */
    struct Point {
        int x;
        int y;
        Color c = Color::from(0, 0, 0);
    };
    
}

#endif //TEST_UTILSTRUCT_H
