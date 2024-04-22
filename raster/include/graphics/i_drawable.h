//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_IDRAWABLE_H
#define SUMMERPROJECT_IDRAWABLE_H


namespace Kie {

    class Window;

    /**
     * This is the interface for drawable object
     */
    class IDrawable {
    public:
        /**
         * This is a pure abstract function, which need to be implemented by the sub classes
         * @param window The window
         */
        virtual void draw(Window& window) = 0;

    };
}


#endif //SUMMERPROJECT_IDRAWABLE_H
