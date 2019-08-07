//
// Created by bxs863 on 07/08/2019.
//

#include "BaseException.h"

Kie::BaseException::BaseException(const char *message) {
    msg = message;
}

const char * Kie::BaseException::what() const noexcept {
    return msg;
}
