//
// Created by kaloka on 02/11/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "hello_triangle.h"
unsigned int *load_triangle_to_buffer(float vertices[9]) {
    auto* VBO = new unsigned int;
    glGenBuffers(1, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, 9, vertices, GL_STATIC_DRAW);
    return VBO;
};

void triangle_main() {

};