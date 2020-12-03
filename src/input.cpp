//
// Created by kaloka on 26/11/2020.
//

#include "input.h"

void input::mousePositionUpdateCallback(GLFWwindow *window, double x, double y) {
    mouseX = x;
    mouseY = y;
}

void input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    mouseClickEvent(window, mouseX, mouseY, button, action, mods);
}
