//
// Created by kaloka on 26/11/2020.
//

#ifndef OGLHANGMAN_INPUT_H
#define OGLHANGMAN_INPUT_H
#include <eventSystem.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using events::event;
namespace input {
    void mousePositionUpdateCallback(GLFWwindow* window, double x, double y);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    event<GLFWwindow* , double, double, int, int, int> * getMouseEvent();
}
#endif //OGLHANGMAN_INPUT_H
