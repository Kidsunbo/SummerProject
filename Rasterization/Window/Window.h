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

// Custom
#include "Graphics/Color.h"
#include "Graphics/IDrawable.h"

namespace Kie {
    class Window {

    private:  //Field
        float sleepTime = 0;
        GLFWwindow *window; // The pointer of the main window
        std::vector<std::vector<Color>> _buf1; // This is the most important thing in this class, which stores all the
        std::vector<std::vector<Color>> _buf2;// This is the other buffer which is used to solve the slash.
        std::atomic_bool buf1InBack = true; // Draw and clear will only effect the back buffer

    private:
        void _display(std::vector<std::vector<Color>>& _buf);

    public: //Method
        Window(int width, int height, const char *title);

        void clear(Color c);

        void display();

        void draw(IDrawable& drawable);

        int getWidth();

        int getHeight();

        void setFrameRate(int rate);

        bool shouldClose();

        std::vector<std::vector<Color>>& getBuffer();

        GLFWwindow *getWindow();

        ~Window();
    };
}


#endif //SUMMERPROJECT_WINDOW_H
