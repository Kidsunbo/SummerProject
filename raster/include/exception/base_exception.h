//
// Created by bxs863 on 07/08/2019.
//

#ifndef SUMMERPROJECT_BASE_EXCEPTION_H
#define SUMMERPROJECT_BASE_EXCEPTION_H

// STL
#include <exception>

namespace Kie {
    /**
     * The basic exception of this library
     */
    class BaseException : public std::exception {
        const char* msg;
    public:
        explicit BaseException(const char* message);

        virtual const char* what() const noexcept override;
    };
}


#endif //SUMMERPROJECT_BASE_EXCEPTION_H
