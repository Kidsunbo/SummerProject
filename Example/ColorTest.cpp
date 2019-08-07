//
// Created by bxs863 on 07/08/2019.
//

#include "Graphics/Color.h"

#include <iostream>

int main(){

    Kie::Color c(255,100,20);
    Kie::Color c1(1.0f,0.5f,0.6f);
    std::cout<<c.getR()<<"  "<<c.getG()<<"  "<<c.getB()<<std::endl;
    std::cout<<c1.getR()<<"  "<<c1.getG()<<"  "<<c1.getB()<<std::endl;

    return 0;
}