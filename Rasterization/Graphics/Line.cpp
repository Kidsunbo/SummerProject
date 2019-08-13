//
// Created by SunBo on 2019-08-12.
//

#include "Line.h"
#include "Window/Window.h"

Kie::Line::Line(Kie::Point p1, Kie::Point p2):
lineColor(-1,-1,-1,true),vertex({std::move(p1),std::move(p2)}) {}

Kie::Line::Line(float x1, float y1, float x2, float y2, Kie::Color c):Line(Point(x1,y1,c),Point(x2,y2,c)) {}

Kie::Line::Line(bool useInt, int x1, int y1, int x2, int y2, int width, int height, Kie::Color c):
Line(Point(true,x1,y1,width,height,c),Point(true,x2,y2,width,height,c)){}

void Kie::Line::resetLineColor(Kie::Color c) {
    lineColor=c;
}


void Kie::Line::draw(Kie::Window &window) {
    auto width = window.getWidth();
    auto height = window.getHeight();
#if __cplusplus >= 201703L
    auto[x1, y1] = vertex[0].mapCoordsToPixel(width, height);
    auto[x2, y2] = vertex[1].mapCoordsToPixel(width, height);
#else
    auto res1 = vertex[0].mapCoordsToPixel(width, height);
        auto res2 = vertex[1].mapCoordsToPixel(width,height);
        auto x1 = std::get<0>(res1);
        auto y1 = std::get<1>(res1);
        auto x2 = std::get<0>(res2);
        auto y2 = std::get<1>(res2);
#endif
    int step = std::max(std::abs(x2-x1),std::abs(y1-y2));
    float delta_x = (x2-x1)/(float)step;
    float delta_y = (y2-y1)/(float)step;
    if (lineColor.getR() == -1.0) {
        InterpColor ic(vertex[0].getColor(),vertex[1].getColor(),step);
        for(int i=0;i<step;i++){
            int x_Pos = static_cast<int>(x1 + static_cast<float>(i) * delta_x);
            int y_Pos = static_cast<int>(y1 + static_cast<float>(i) * delta_y);
            window.draw(Point(true,x_Pos,y_Pos,width,height,++ic));
        }
    } else {
        for(int i=0;i<step;i++){
            float x_Pos = x1 + static_cast<float>(i) * delta_x;
            float y_Pos = y1 + static_cast<float>(i) * delta_y;
            window.draw(Point(true,static_cast<int>(x_Pos),static_cast<int>(y_Pos),width,height,lineColor));
        }
    }

}
