//
// Created by kaloka on 02/11/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>

#include "gl_helpers.h"
#include "helpers.h"

using namespace gl_helpers;
unsigned int * gl_helpers::create_shader(const char * shader_source) {
    auto *vertexShader = new unsigned int(glCreateShader(GL_VERTEX_SHADER));
    glShaderSource(*vertexShader, 1, &shader_source, nullptr);
    glCompileShader(*vertexShader);
    return vertexShader;
}

