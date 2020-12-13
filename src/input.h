//
// Created by kaloka on 26/11/2020.
//

#ifndef OGLHANGMAN_INPUT_H
#define OGLHANGMAN_INPUT_H
#include <eventSystem.h>
#include <move.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using events::event;
namespace input {
    struct EventActionsHolderClass {
        EventActionsHolderClass();
        event<int> boardClick;
        event<char> textInput;
    };
    void init(GLFWwindow *window, float *boardScale, float *boardX, float *boardY, EventActionsHolderClass * events, move::GameHandler * gameHandler);
    void mousePositionUpdateCallback(GLFWwindow* window, double x, double y);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void characterCallback(GLFWwindow *window, unsigned int codepoint);
}
#endif //OGLHANGMAN_INPUT_H
