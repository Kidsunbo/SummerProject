//
// Created by SunBo on 2019-08-12.
//

#include "graphics/line.h"

#include <utility>
#include "window/window.h"
#include "graphics/texture.h"

Kie::Line::Line(Kie::Point p1, Kie::Point p2, std::shared_ptr<Texture> texture):
lineColor(-1,-1,-1,true),vertex({std::move(p1),std::move(p2)}),useTexture(true),texture(std::move(texture)) {}

Kie::Line::Line(float x1, float y1, float x2, float y2, Kie::Color c):Line(Point(x1,y1,0,c),Point(x2,y2,0,c)) {}

void Kie::Line::resetLineColor(Kie::Color c) {
    lineColor=c;
}


void Kie::Line::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
    auto[x1_temp, y1_temp] = vertex[0].mapCoordsToPixel(width, height);
    auto[x2_temp, y2_temp] = vertex[1].mapCoordsToPixel(width, height);
    int step = std::max(std::abs(x2_temp-x1_temp),std::abs(y1_temp-y2_temp))*2;
    float x1=vertex[0].getPosition().getX();
    float x2 = vertex[1].getPosition().getX();
    float y1 = vertex[0].getPosition().getY();
    float y2 = vertex[1].getPosition().getY();
    float z1 = vertex[0].getZ();
    float z2 = vertex[1].getZ();
    float delta_x = (x2-x1)/(float)step;
    float delta_y = (y2-y1)/(float)step;
    float delta_z = (z2-z1)/(float)step;
    if(useTexture){
        InterpTexture ic(vertex[0].getTexture(),vertex[1].getTexture(),*texture,step);
        for(int i=0;i<step;i++){
            float x_Pos = x1 + static_cast<float>(i) * delta_x;
            float y_Pos = y1 + static_cast<float>(i) * delta_y;
            float z_Pos = z1 + static_cast<float>(i)*delta_z;
            auto p = Point(x_Pos,y_Pos,z_Pos,++ic);
            p.setTexture(*ic);
            window.draw(p);
        }
    }
    else if (math::floatEqual(lineColor.getR(),-1.0)) {
        InterpColor ic(vertex[0].getColor(),vertex[1].getColor(),step);
        for(int i=0;i<step;i++){
            float x_Pos = x1 + static_cast<float>(i) * delta_x;
            float y_Pos = y1 + static_cast<float>(i) * delta_y;
            float z_Pos = z1 + static_cast<float>(i)*delta_z;
            window.draw(Point(x_Pos,y_Pos,z_Pos,++ic));
        }
    } else {
        for(int i=0;i<step;i++){
            float x_Pos = x1 + static_cast<float>(i) * delta_x;
            float y_Pos = y1 + static_cast<float>(i) * delta_y;
            float z_Pos = z1 + static_cast<float>(i)*delta_z;

            window.draw(Point(x_Pos,y_Pos,z_Pos,lineColor));
        }
    }

}

Kie::Line::Line(Kie::Point p1, Kie::Point p2, Kie::Color c):lineColor(c),vertex({std::move(p1),std::move(p2)}) {
}


