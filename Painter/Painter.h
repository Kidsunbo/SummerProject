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

//Custom Header
#include "UtilStruct.h"
#include "Shape/Pixel.h"

// Put all the code in namespace Kie
namespace Kie {

/**
 * This is the painter class which encapsulate some basic operation of openGL, it provides some
 * APIs to draw pixels, and based on this function, some other APIs have been implemented.
 */
    class Painter {

    public:
        // Static method


    private:
        GLFWwindow *window;  // The pointer of the main window
        std::vector<std::vector<Color>> _buf; // This is the most important thing in this class, which stores all the
        // information of each pixel. All the operation operates on it.
        int _width = 1; // The width of the pen, default to 1
        bool closed = false;
    public:

        // Constructor
        /**
         * This is the constructor of the class, nothing special, but initialize some values.
         * @param title
         * @param width
         * @param height
         */
        Painter(const char *title, int width, int height);
        Painter(Painter& painter) = delete;
        Painter(Painter&& painter) = delete;

        // End

        // Destructor
        ~Painter();
        // End


        // Draw APIs
        void drawPixel(int x, int y, Color c);

        void drawPixel(int x, int y, int r = 255, int g = 255, int b = 255);

        void drawLine(int x1, int y1, int x2, int y2,Color c = Color::from(255, 255, 255),LineAlgorithm algorithm = LineAlgorithm::Custom);

        void drawTriangle(const std::vector<Pixel>& vertex,Color c=Color::from(255,255,255));

        void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3,Color c=Color::from(255,255,255));

        void drawCircle(int x,int y,int r,Color c= Color::from(255,255,255));

        void drawEllipse(int x, int y,int a,int b, Color c = Color::from(255,255,255));

        void fillTriangle(std::vector<Pixel>& vertex,Color c = Color::from(255,255,255));

        void fillTriangle(float x1, float y1, float x2, float y2, float x3, float y3, Color c = Color::from(255,255,255));
        // End


        // Loop Functions
        void paint();

        void clear(Color c = Color::from(255, 255, 255));
        // End


        // Information Of Window
        int getWidth();

        int getHeight();
        // End


        // State API
        void setPenWidth(int width);

        int getPenWidth();

        bool isClosed();

    private:
        void fillTopTriangle(const Pixel &p1, const Pixel &p2, const Pixel &p3,Color c);

        void fillBottomTriangle(const Pixel &p1, const Pixel &p2, const Pixel &p3,Color c);


    };

}
#endif //SUMMERPROJECT_PAINT_H
