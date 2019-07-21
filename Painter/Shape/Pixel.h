//
// Created by bxs863 on 21/07/2019.
//

#ifndef SUMMERPROJECT_PIXEL_H
#define SUMMERPROJECT_PIXEL_H
#include "Shape.h"
#include "../UtilStruct.h"
#include "../PainterException.h"

namespace Kie {
    class Pixel : public Shape {
    public:
        int x;
        int y;
        Color c = Color::from(0, 0, 0);

        Pixel(int x,int y, Color c):x(x),y(y),c(c){}

        void draw(std::vector<std::vector<Color>>& buf) override {
            buf[x][y] = c;
        }

        void writeToFile(std::string filename) override {
            throw NotImplementedException("Pixel writeToFile is not implemented");
        }

        std::shared_ptr<Shape> readFromFile(std::string filename) override {
            throw NotImplementedException("Pixel readFromFile is not implemented");
            //return std::make_shared<Pixel>();
        }

    };
}



#endif //SUMMERPROJECT_PIXEL_H
