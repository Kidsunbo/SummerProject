//
// Created by bxs863 on 07/08/2019.
//

#include "Point.h"
#include "Window/Window.h"

void Kie::Point::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
    if(normalized){
        window.getBuffer().at(static_cast<int>(y*height/2.0f+height/2.0f)).at(static_cast<int>(x*width/2.0f+width/2.0f))=color;
    }else{
        if(y<height && x<width)
            window.getBuffer().at(static_cast<int>(y)).at(static_cast<int>(x)) = color;
    }
}

Kie::Point::Point(int x, int y, Kie::Color c):Point(static_cast<float>(x), static_cast<float>(y),c,false) {
}

Kie::Point::Point(float x, float y, Kie::Color c, bool normalized):color(c),x(x),y(y),normalized(normalized) {
}

