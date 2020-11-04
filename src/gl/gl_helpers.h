//
// Created by kaloka on 02/11/2020.
//
#include <cstdlib>
#ifndef OGLINFOPROJ_GL_HELPERS_H
#define OGLINFOPROJ_GL_HELPERS_H
namespace gl_helpers {
    unsigned int *create_shader(const char *shader_source);
    void check_compile_throw(const unsigned int gl_shader);
}
#endif //OGLINFOPROJ_GL_HELPERS_H
