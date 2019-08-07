//
// Created by bxs863 on 07/08/2019.
//

#include "Point.h"
#include "Window/Window.h"
#include "Math/Math.h"


void Kie::Point::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
    if(normalized){
        window.getBuffer().at(static_cast<int>(Math::normalizeYtoRange2(y) * height / 2)).at(static_cast<int>(Math::normalizeXtoRange2(x) * width / 2))=color;
    }else{
        if(y<height && x<width)
            window.getBuffer().at(static_cast<int>(y)).at(static_cast<int>(x)) = color;
    }
}

Kie::Point::Point(int x, int y, Kie::Color c):Point(static_cast<float>(x), static_cast<float>(y),c,false) {
}

Kie::Point::Point(float x, float y, Kie::Color c, bool normalized):color(c),x(x),y(y),normalized(normalized) {
}

