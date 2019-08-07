//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_BASEEXCEPTION_H
#define SUMMERPROJECT_BASEEXCEPTION_H

// STL
#include <string>

namespace Kie {
    class BaseException : public std::exception {
        const char* msg;
    public:
        explicit BaseException(const char* message);

        virtual const char* what() const noexcept override;
    };
}


#endif //SUMMERPROJECT_BASEEXCEPTION_H
