//
// Created by bxs863 on 21/07/2019.
//

#ifndef SUMMERPROJECT_SHAPE_H
#define SUMMERPROJECT_SHAPE_H

#include <mutex>
#include <vector>
#include <string>
#include <memory>
#include "../UtilStruct.h"
/**
 * An interface for every object in the 2D world. It has a pure virtual (abstract) method, which will draw the object
 * to the window
 * This class is mainly used when serialize the object
 */
 namespace Kie {
     class Shape {

         static std::mutex shapeLocker; // Share this locker to each subclass, this object aims to stop other object be
         // drawn at the same time, which is useful when two shapes will be collapsed.
     public:
         virtual void draw(std::vector<std::vector<Color>>& buf) = 0;
         virtual void writeToFile(std::string filename) = 0;
         virtual std::shared_ptr<Shape> readFromFile(std::string filename) = 0;
     };
 }


#endif //SUMMERPROJECT_SHAPE_H
