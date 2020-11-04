//
// Created by kaloka on 03/11/2020.
//

#include "glException.h"
#include "algorithm"

gl_exceptions::glShaderCompileException::glShaderCompileException(const char *compile_info) {
    std::copy_n(compile_info, 512, gl_compile_info);
}

const char * gl_exceptions::glShaderCompileException::what() const noexcept {
    return gl_compile_info;
}

