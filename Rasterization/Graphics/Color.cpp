//
// Created by bxs863 on 07/08/2019.
//

// Custom
#include "Color.h"

// STL
#include <cmath>

Kie::Color::Color(float r, float g, float b, bool normalized) {
    if(normalized){
        this->r = r;
        this->g = g;
        this->b = b;
    }
    else{
        this->r = r/255.0f;
        this->g = g/255.0f;
        this->b = b/255.0f;
    }
}

Kie::Color::Color(int r, int g, int b):Color(static_cast<float>(std::max(r,0))/255.0f,static_cast<float>(std::max(g,0))/255.0f,static_cast<float>(std::max(b,0))/255.0f) {
}

Kie::Color Kie::Color::operator+(Kie::Color &color) {
    return Color(std::min(r+color.r,1.0f),std::min(g+color.g,1.0f),std::min(b+color.b,1.0f));
}

Kie::Color Kie::Color::operator-(Kie::Color &color) {
    return Color(std::max(r-color.r,0.0f),std::max(g-color.g,0.0f),std::max(b-color.b,0.0f));
}

float Kie::Color::getR() const {
    return r;
}

float Kie::Color::getG() const {
    return g;
}

float Kie::Color::getB() const {
    return b;
}

