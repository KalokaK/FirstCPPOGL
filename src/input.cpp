//
// Created by kaloka on 26/11/2020.
//

#include <cstdio>
#include "input.h"
namespace input {
    double mouseX;
    double mouseY;
    float *boardX, *boardY, *boardScale;
    EventActionsHolderClass::EventActionsHolderClass() : boardClick(), textInput() {
    }
    EventActionsHolderClass * events;
    int * turn;
}

void input::mousePositionUpdateCallback(GLFWwindow *window, double x, double y) {
    mouseX = x;
    mouseY = y;
}

void input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    auto y = mouseY;
    auto x = mouseX;
    //to ndc
    x /= (float)width;
    x -= 0.5;
    x*=2;
    y /= (float)height;
    y-=0.5;
    y*=-2;
    //distance to bottom left
    x -= *boardX - 0.5 * *boardScale;
    y -= *boardY - 0.5 * *boardScale;
    // get piece
    x *= 8 / *boardScale;
    y *= 8 / *boardScale;
    x = (int)x;
    y = (int)y;
    // bound
    printf("%f, %f, %i, %i \n", x, y, (int)(x + y*8), ((0 <= x && x <= 7) && (0 <= y && y <= 7)) );
    if ((0 <= x && x <= 7) && (0 <= y && y <= 7)) events->boardClick(abs((int)(x + y*8) - 63 * *turn));
}

void input::characterCallback(GLFWwindow *window, unsigned int codepoint) {
    printf("call in character %i", codepoint);
    if (codepoint <= 127) events->textInput((char)codepoint - (96 < codepoint && codepoint < 123) * 32); // if ASCII
}

void input::init(GLFWwindow *window, float *boardScale, float *boardX, float *boardY, EventActionsHolderClass *events, move::GameHandler * gameHandler) {
    input::events = events;
    input::turn = &(gameHandler->turn);
    input::events->boardClick.add(&move::GameHandler::fieldClickListener, gameHandler);
    input::events->textInput.add(&move::GameHandler::textInputListener, gameHandler);
    input::boardScale = boardScale;
    input::boardX = boardX;
    input::boardY = boardY;
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, mousePositionUpdateCallback);
    glfwSetCharCallback(window, characterCallback);
}
