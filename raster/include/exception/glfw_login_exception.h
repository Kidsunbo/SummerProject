//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_GLFW_LOGIN_EXCEPTION_H
#define SUMMERPROJECT_GLFW_LOGIN_EXCEPTION_H

//Custom
#include "exception/base_exception.h"

namespace Kie {
    /**
     * Mainly used when the creation of the window fails
     */
    class GLFWLoginException:public BaseException{
    public:
        using BaseException::BaseException;
    };
}


#endif //SUMMERPROJECT_GLFW_LOGIN_EXCEPTION_H
