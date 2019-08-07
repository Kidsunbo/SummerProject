//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_DRAWABLE_H
#define SUMMERPROJECT_DRAWABLE_H


namespace Kie {

    class Window;

    class Drawable {
    public:
        virtual void draw(Window& window) = 0;

    };
}


#endif //SUMMERPROJECT_DRAWABLE_H
