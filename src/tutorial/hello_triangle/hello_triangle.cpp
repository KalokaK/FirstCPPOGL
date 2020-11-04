//
// Created by kaloka on 02/11/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "hello_triangle.h"
#include "gl/gl_helpers.h"
#include "helpers/helpers.h"

using namespace hello_triangle;
using namespace gl_helpers;
using namespace helpers;

unsigned int * hello_triangle::load_triangle_to_buffer(float vertices[9]) {
    auto* VBO = new unsigned int;
    glGenBuffers(1, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, 9, vertices, GL_STATIC_DRAW);
    return VBO;
};

void triangle_main() {
    float vertices[] = {
            0.0, 0.5, 0.0,
            0.5, -0.5, 0.0,
            -0.5, -0.5, 0.0,
    };
    unsigned int * triangle_vbo = load_triangle_to_buffer(vertices);
    char shader_filename[] = "hello_triangle.vert";
    char * shader = get_ascii_file(shader_filename);
    unsigned int * passthrough_vertex_shader = create_shader(shader);

};
