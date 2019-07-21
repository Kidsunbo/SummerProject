#include <utility>

//
// Created by bxs863 on 21/07/2019.
//

#ifndef SUMMERPROJECT_TRIANGLE_H
#define SUMMERPROJECT_TRIANGLE_H
#include "Shape.h"
#include "UtilStruct.h"
#include "PainterException.h"
#include "Line.h"

namespace Kie {
    class Triangle : public Shape {

        Line l1;
        Line l2;
        Line l3;
        int width;
        Color c;
    public:

        Triangle(const Line& l1, const Line& l2, const Line& l3, int width = 1,Color c=Color::from(255,255,255))
        :l1(l1),l2(l2),l3(l3),width(width),c(c){}

        Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int width = 1, Color c = Color::from(255, 255, 255))
        : width(width), c(c),l1(Line(x1,y1,x2,y2,width,c)),l2(Line(x2,y2,x3,y3,width,c)),l3(Line(x3,y3,x1,y1,width,c)) {}



        void draw(std::vector<std::vector<Color>>& buf) override {
            l1.draw(buf);
            l2.draw(buf);
            l3.draw(buf);
        }

        void writeToFile(std::string filename) override {
            throw NotImplementedException("writeToFile is not implemented");
        }

        std::shared_ptr<Shape> readFromFile(std::string filename) override {
            throw NotImplementedException("readFromFile is not implemented");
            return std::make_shared<Triangle>();
        }

    };
}


#endif //SUMMERPROJECT_TRIANGLE_H
