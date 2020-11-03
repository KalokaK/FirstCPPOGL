//
// Created by kaloka on 02/11/2020.
//

#ifndef OGLINFOPROJ_HELLO_TRIANGLE_H
#define OGLINFOPROJ_HELLO_TRIANGLE_H
const char *hello_triangle_vertex_shader_source =
#include "hello_triangle.vert"
;
unsigned int *load_triangle_to_buffer(float vertices[9]);
void triangle_main();
#endif //OGLINFOPROJ_HELLO_TRIANGLE_H
