//
// Created by kaloka on 02/11/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>

#include "gl_helpers.h"
#include "gl/exceptions/glException.h"

unsigned int * gl_helpers::create_shader(const char * shader_source) {
    auto *shader = new unsigned int(glCreateShader(GL_VERTEX_SHADER));
    glShaderSource(*shader, 1, &shader_source, nullptr);
    glCompileShader(*shader);
    return shader;
}

void gl_helpers::check_compile_throw(const unsigned int gl_shader) {
    int success;
    char compile_msg_out[512];
    glGetShaderiv(gl_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        throw gl_exceptions::glShaderCompileException(compile_msg_out);
    }
}

