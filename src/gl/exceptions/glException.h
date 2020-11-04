//
// Created by kaloka on 03/11/2020.
//

#ifndef OGLINFOPROJ_GLEXCEPTION_H
#define OGLINFOPROJ_GLEXCEPTION_H
#include "exception"


namespace gl_exceptions{
    class glShaderCompileException : public std::exception {
    private:
        char gl_compile_info[512];
    public:
        explicit glShaderCompileException(const char compile_info[512]);
        [[nodiscard]] const char * what() const noexcept override;
    };
}

#endif //OGLINFOPROJ_GLEXCEPTION_H
