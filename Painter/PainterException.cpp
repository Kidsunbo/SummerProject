//
// Created by bxs863 on 01/07/2019.
//

#include "PainterException.h"
using namespace Kie;


BaseException::BaseException(const char *message) {
    msg = message;
}

const char *BaseException::what() const noexcept {
    return msg;
}
