//
// Created by bxs863 on 01/07/2019.
//

#ifndef SUMMERPROJECT_PAINT_H
#define SUMMERPROJECT_PAINT_H
// OpenGL Header

#include <glad/gl.h>
#include <GLFW/glfw3.h>

// STL Header
#include <vector>


// Put all the code in namespace Kie
namespace Kie {

/**
 * This is the painter class which encapsulate some basic operation of openGL, it provides some
 * APIs to draw pixels, and based on this function, some other APIs have been implemented.
 */
    class Painter {
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
        };

    public:
        /**
         * This is the function for creating a color object.
         * @param r The red value
         * @param g The green value
         * @param b The blue value
         * @return The color object
         */
        static Color createColor(int r, int g, int b);


    private:
        GLFWwindow *window;  // The pointer of the main window
        std::vector<std::vector<Color>> _buf; // This is the most important thing in this class, which stores all the
        // information of each pixel. All the operation operates on it.
    public:

        // Constructor
        /**
         * This is the constructor of the class, nothing special, but initialize some values.
         * @param title
         * @param width
         * @param height
         */
        Painter(const char *title, int width, int height);

        // End

        // Destructor
        ~Painter();
        // End


        // Draw APIs
        void drawPixel(int x, int y, Color c);

        void drawPixel(int x, int y, int r = 0, int g = 0, int b = 0);

        void drawLine(int x1, int y1, int x2, int y2, bool smooth = false);
        // End


        // Loop Functions
        void paint();

        void clear(Color c = createColor(255, 255, 255));
        // End


        // Information Of Window
        int getWidth();

        int getHeight();
        // End
    };

}
#endif //SUMMERPROJECT_PAINT_H
