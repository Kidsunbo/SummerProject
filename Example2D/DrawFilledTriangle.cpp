//
// Created by bxs863 on 05/08/2019.
//

#include "Painter.h"
using namespace Kie;
int main(){
    Painter painter{"Hello",640,480};
    painter.clear(Color::from(0,0,0));
    painter.fillTriangle(400,100,100,200,300,300);

    painter.paint();

}
