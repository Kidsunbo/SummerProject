//
// Created by bxs863 on 21/07/2019.
//

#ifndef SUMMERPROJECT_LINE_H
#define SUMMERPROJECT_LINE_H

#include <cmath>
#include "Shape.h"
#include "../UtilStruct.h"
#include "../PainterException.h"
#include "Point.h"

namespace Kie {
    class Line : public Shape {
        int x1;
        int y1;
        int x2;
        int y2;
        int width;
        Color c;
    public:

        Line(int x1, int y1, int x2 ,int y2, int width=1, Color c=Color::from(255,255,255)):x1(x1),x2(x2),y1(y1),y2(y2),width(width),c(c){}
        Line(const Line& l) noexcept{
            x1 = l.x1;
            y1 = l.y1;
            x2 = l.x2;
            y2 = l.y2;
            width = l.width;
            c = l.c;
        }
        Line(Line&& l) noexcept{
            x1 = l.x1;
            y1 = l.y1;
            x2 = l.x2;
            y2 = l.y2;
            width = l.width;
            c = l.c;
        }

        Line& operator=(Line&& l) noexcept {
            x1 = l.x1;
            y1 = l.y1;
            x2 = l.x2;
            y2 = l.y2;
            width = l.width;
            c = l.c;
            return *this;
        }

        void draw(std::vector<std::vector<Color>>& buf) override {
            int step = std::max(std::abs(x2-x1),std::abs(y1-y2));
            float delta_x = (x2-x1)/(float)step;
            float delta_y = (y2-y1)/(float)step;
            for(int i=0; i<step;i++){
                Point(static_cast<int>(std::round(x1+step*delta_x)), static_cast<int>(std::round(y1+step*delta_y)),width,c).draw(buf);
            }
        }

        void writeToFile(std::string filename) override {
            throw NotImplementedException("writeToFile is not implemented");
        }

        std::shared_ptr<Shape> readFromFile(std::string filename) override {
            throw NotImplementedException("readFromFile is not implemented");
        }

    };
}

#endif //SUMMERPROJECT_LINE_H
