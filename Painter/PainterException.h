//
// Created by bxs863 on 01/07/2019.
//

#ifndef SUMMERPROJECT_PAINTEREXCEPTION_H
#define SUMMERPROJECT_PAINTEREXCEPTION_H
#include <exception>
namespace Kie {



    class BaseException : public std::exception {
        const char* msg;
    public:
        explicit BaseException(const char* message);
        virtual const char* what() const noexcept override;
    };

    class GLFWLoginException:public BaseException{
    public:
        using BaseException::BaseException;
    };

    class NotImplementedException : public BaseException{
    public:
        using BaseException::BaseException;
    };


}

#endif //SUMMERPROJECT_PAINTEREXCEPTION_H
