//
// Created by kaloka on 02/11/2020.
//

#include <fstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "helpers.h"

char * helpers::get_ascii_file(const char *filename) {
    std::ifstream file;
    int len = 0;
    file.open(filename);

    file.seekg(0, std::ios::end);
    len = file.tellg(); //get current loc
    char * source_buffer = new char[len]();
    file.read(source_buffer, len); // read file in to source buffer
    file.close();
    return source_buffer; // pointer to source code
}