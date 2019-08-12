//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_IDRAWABLE_H
#define SUMMERPROJECT_IDRAWABLE_H


namespace Kie {

    class Window;

    class IDrawable {
    public:
        virtual void draw(Window& window) = 0;

    };
}


#endif //SUMMERPROJECT_IDRAWABLE_H
