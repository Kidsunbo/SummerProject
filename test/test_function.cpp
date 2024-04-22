//
// Created by bxs863 on 07/08/2019.
//

#include "graphics/color.h"
#include "graphics/i_transformable.h"


#include <iostream>

int main(){

    Kie::Color c(255,100,20);
    Kie::Color c1(1.0f,0.5f,0.6f);
    std::cout<<c.getR()<<"  "<<c.getG()<<"  "<<c.getB()<<std::endl;
    std::cout<<c1.getR()<<"  "<<c1.getG()<<"  "<<c1.getB()<<std::endl;

    Kie::ITransformable t;
    t.setPosition(10, 10, 10);
    auto[x,y] = t.mapCoordsToPixel(100, 100);
    std::cout<<x<<"  "<<y<<std::endl;

    return 0;
}