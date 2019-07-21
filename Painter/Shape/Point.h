//
// Created by bxs863 on 21/07/2019.
//

#ifndef SUMMERPROJECT_POINT_H
#define SUMMERPROJECT_POINT_H
#include "Pixel.h"

namespace Kie {
    class Point : public Shape {
    public:
        std::vector<Pixel> pixs;
        
        Point(int x, int y, int width = 1, Color c = Color::from(255,255,255)){
            throw NotImplementedException("the way to draw Point is not figured out");
        }
        
        void draw(std::vector<std::vector<Color>> &buf) override {
            for(auto& p : pixs){
                p.draw(buf);
            }
        }

        void writeToFile(std::string filename) override {
            throw NotImplementedException("Point writeToFile is not implemented");
        }

        std::shared_ptr<Shape> readFromFile(std::string filename) override {
            throw NotImplementedException("Point readFromFile is not implemented");
            return std::shared_ptr<Shape>();
        }

    };
}


#endif //SUMMERPROJECT_POINT_H
