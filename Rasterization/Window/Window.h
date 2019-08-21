//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_WINDOW_H
#define SUMMERPROJECT_WINDOW_H

// Lib
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// STL
#include <vector>
#include <atomic>
#include <chrono>

// Custom
#include "Graphics/Color.h"
#include "Graphics/IDrawable.h"

namespace Kie {
    /**
     * This is the main class for drawing object on the screen. In version 2, it use single thread for safety, but
     * in next version, multiple threading will be added for performance.
     */
    class Window {

    private:  //Field
        float sleepTime = 0;
        GLFWwindow *window; // The pointer of the main window
        std::vector<std::vector<Color>> _buf1; // This is the most important thing in this class, which stores all the
        std::vector<std::vector<Color>> _buf2;// This is the other buffer which is used to solve the slash.
        std::atomic_bool buf1InBack = true; // Draw and clear will only effect the back buffer

        bool printfps = false;
        std::chrono::time_point<std::chrono::system_clock> time;

        std::vector<std::vector<float>> zbuffer;

        std::string title = "";


    private:
        /**
         * This function only draw the pixels in current buffer to the screen.
         * @param _buf The current buffer to be drawn
         */
        void _display(std::vector<std::vector<Color>>& _buf);

    public: //Method
        /**
         * This constructor of the window
         * @param width The width of the window, it's as integer type
         * @param height The height of the window, it's as interger type
         * @param title The title of the application
         */
        Window(int width, int height, const char *title);

        /**
         * This method is used to clear the window into a single color
         * @param c
         */
        void clear(Color c);

        /**
         * This method is used for user to draw the content in the buffer.
         * In this method,it will determine which buffer should be drawn and will change the buffer automatically
         */
        void display();

        /**
         * This is the draw method, which has the left reference version and the right reference version
         * @param drawable The drawable object
         */
        void draw(IDrawable& drawable);

        /**
         * This is the draw method, which has the left reference version and the right reference version
         * @param drawable The drawable object
         */
        void draw(IDrawable&& drawable);

        /**
         * Get the width of the window
         * @return the width of the window
         */
        int getWidth();

        /**
         * Get the height of the window
         * @return the height of the window
         */
        int getHeight();

        /**
         * This function used to set the frame rate of the window, for now, it works improperly
         * @param rate
         */
        void setFrameRate(int rate);

        /**
         * This method will set if the fps should be printed in the title of the window
         * @param value
         */
        void printFPS(bool value);

        /**
         * This method returns the value of if the screen should be closed
         * @return
         */
        bool shouldClose();

        /**
         * Get the z-buffer for depth detection
         * @return The reference of the z-buffer
         */
        std::vector<std::vector<float>>& getZbuffer();

        /**
         * Get the current buffer which is used to be drawing.
         * @return
         */
        std::vector<std::vector<Color>>& getBuffer();

        /**
         * Get the window pointer of the OpenGL context
         * @return The window pointer
         */
        GLFWwindow *getWindow();

        /**
         * The destructor, because I never use raw pointer in this library, so it just does some clean works for OpenGL
         */
        ~Window();
    };
}


#endif //SUMMERPROJECT_WINDOW_H
