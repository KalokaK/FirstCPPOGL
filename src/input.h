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
    auto keyboardInputEvent = event<GLFWwindow *, int, int, int, int>();
    auto characterInputEvent = event<GLFWwindow *, unsigned int>();
    void keyboardEventCaller();
}
#endif //OGLHANGMAN_INPUT_H
