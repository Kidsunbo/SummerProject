//
// Created by SunBo on 2019-08-13.
//

#include "Triangle.h"
#include "Window/Window.h"

#include <algorithm>

void Kie::Triangle::draw(Kie::Window &window) {
    if(fill){
        _drawWithFill(window);
    }
    else{
        _drawWithoutFill(window);
    }
}

Kie::Triangle::Triangle(Kie::Point p1, Kie::Point p2, Kie::Point p3, bool fill, Kie::Color filledColor):fillColor(filledColor),vertex({std::move(p1),std::move(p2),std::move(p3)}),fill(fill) {

}

void Kie::Triangle::resetFilledColor(bool fill,Kie::Color c) {
    this->fill=fill;
    fillColor=c;
}

void Kie::Triangle::_drawWithoutFill(Kie::Window &window) {
    window.draw(Line(vertex[0],vertex[1]));
    window.draw(Line(vertex[1],vertex[2]));
    window.draw(Line(vertex[2],vertex[0]));
}

void Kie::Triangle::_drawWithFill(Kie::Window &window) {
    std::sort(vertex.begin(),vertex.end(),[](Point& p1,Point& p2){return p1.getPosition().getY()>p2.getPosition().getY();});

    auto& pos1 = vertex[0].getPosition();
    auto& pos2 = vertex[1].getPosition();
    auto& pos3 = vertex[2].getPosition();

    if(Math::floatEqual(pos2.getY(),pos3.getY())) _fillTopTriangle(window,vertex[0],vertex[1],vertex[2]);
    else if(Math::floatEqual(pos1.getY(),pos2.getY())) _fillBottomTriangle(window,vertex[0],vertex[1],vertex[2]);
    else{
        float r = (pos2.getY()-pos1.getY())/(pos3.getY()-pos1.getY());
        float newX = pos1.getX()+r*(pos3.getX()-pos1.getX());
        float newR = vertex[0].getColor().getR()+(vertex[2].getColor().getR()-vertex[0].getColor().getR())*r;
        float newG = vertex[0].getColor().getG()+(vertex[2].getColor().getG()-vertex[0].getColor().getG())*r;
        float newB = vertex[0].getColor().getB()+(vertex[2].getColor().getB()-vertex[0].getColor().getB())*r;
        Point p(newX,pos2.getY(),Color(newR,newG,newB));
        _fillTopTriangle(window,vertex[0],vertex[1],p);
        _fillBottomTriangle(window,vertex[1],p,vertex[2]);
    }
}

void Kie::Triangle::_fillTopTriangle(Kie::Window &window, Kie::Point &p1, Kie::Point &p2, Kie::Point &p3) {
    float step1 =
            (p2.getPosition().getX() - p1.getPosition().getX()) / (p2.getPosition().getY() - p1.getPosition().getY());
    float step2 =
            (p3.getPosition().getX() - p1.getPosition().getX()) / (p3.getPosition().getY() - p1.getPosition().getY());
    float start = p1.getPosition().getX();
    float end = p1.getPosition().getX();
    auto width = window.getWidth();
    auto height = window.getHeight();
#if __cplusplus >= 201703L
    auto[x1_temp, y1_temp] = p1.mapCoordsToPixel(width, height);
    auto[x2_temp, y2_temp] = p2.mapCoordsToPixel(width, height);
#else
    auto res1 = p1.mapCoordsToPixel(width, height);
    auto res2 = p2.mapCoordsToPixel(width,height);
    auto x1_temp = std::get<0>(res1);
    auto y1_temp = std::get<1>(res1);
    auto x2_temp = std::get<0>(res2);
    auto y2_temp = std::get<1>(res2);
#endif
    float y_step = (p2.getPosition().getY() - p1.getPosition().getY()) / static_cast<float>(y2_temp - y1_temp);
    float end_y = p2.getPosition().getY();
    step1*=y_step;
    step2*=y_step;
    if(Math::floatEqual(fillColor.getR(),-1.0f)) {
        InterpColor left(p1.getColor(),p2.getColor(),y2_temp - y1_temp);
        InterpColor right(p1.getColor(),p3.getColor(),y2_temp - y1_temp);
        for (float y = p1.getPosition().getY(); y >= end_y;) {
            window.draw(Line(Point(start,y,++left),Point(end,y,++right)));
            start+=step1;
            end+=step2;
            y+=y_step;
        }
    }
    else{
        for (float y = p1.getPosition().getY(); y >= end_y;) {
            window.draw(Line(start,y,end,y,fillColor));
            start+=step1;
            end+=step2;
            y+=y_step;
        }
    }
}

void Kie::Triangle::_fillBottomTriangle(Kie::Window &window, Kie::Point &p1, Kie::Point &p2, Kie::Point &p3) {
    float step1 =
            (p3.getPosition().getX() - p1.getPosition().getX()) / (p3.getPosition().getY() - p1.getPosition().getY());
    float step2 =
            (p3.getPosition().getX() - p2.getPosition().getX()) / (p3.getPosition().getY() - p2.getPosition().getY());
    float start = p3.getPosition().getX();
    float end = p3.getPosition().getX();
    auto width = window.getWidth();
    auto height = window.getHeight();
#if __cplusplus >= 201703L
    auto[x1_temp, y1_temp] = p1.mapCoordsToPixel(width, height);
    auto[x2_temp, y2_temp] = p3.mapCoordsToPixel(width, height);
#else
    auto res1 = p2.mapCoordsToPixel(width, height);
        auto res2 = p3.mapCoordsToPixel(width,height);
        auto x1_temp = std::get<0>(res1);
        auto y1_temp = std::get<1>(res1);
        auto x2_temp = std::get<0>(res2);
        auto y2_temp = std::get<1>(res2);
#endif
    float y_step = (p1.getPosition().getY() - p3.getPosition().getY()) / static_cast<float>(y1_temp - y2_temp);
    float end_y = p1.getPosition().getY();
    step1*=y_step;
    step2*=y_step;
    if(Math::floatEqual(fillColor.getR(),-1.0f)) {
        InterpColor left(p3.getColor(),p1.getColor(),y2_temp - y1_temp);
        InterpColor right(p3.getColor(),p2.getColor(),y2_temp - y1_temp);
        for (float y = p3.getPosition().getY(); y <= end_y;) {
            window.draw(Line(Point(start,y,++left),Point(end,y,++right)));
            start-=step1;
            end-=step2;
            y-=y_step;
        }
    }
    else{
        for (float y = p3.getPosition().getY(); y <= end_y;) {
            window.draw(Line(start,y,end,y,fillColor));
            start-=step1;
            end-=step2;
            y-=y_step;
        }
    }
}

