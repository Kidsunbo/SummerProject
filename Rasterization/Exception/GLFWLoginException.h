//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_GLFWLOGINEXCEPTION_H
#define SUMMERPROJECT_GLFWLOGINEXCEPTION_H

//Custom
#include "BaseException.h"

namespace Kie {
    /**
     * Mainly used when the creation of the window fails
     */
    class GLFWLoginException:public BaseException{
    public:
        using BaseException::BaseException;
    };
}


#endif //SUMMERPROJECT_GLFWLOGINEXCEPTION_H
