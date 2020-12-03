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
    double mouseX, mouseY;
    void mousePositionUpdateCallback(GLFWwindow* window, double x, double y);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    auto mouseClickEvent = event<GLFWwindow* , double, double, int, int, int>();
}
#endif //OGLHANGMAN_INPUT_H
