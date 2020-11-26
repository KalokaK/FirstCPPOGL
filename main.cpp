#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "helpers.h"
#include <iostream>
#include <time.h>
#include <glBoilerplateAndHelpers/sprite.h>
#include "glBoilerplateAndHelpers/texture.h"
#include <chessSpriteHandler.h>

std::string guess;
std::string word;
std::string fails;
char last;
int lives = 8;
bool win = false;

int main(int argc, char* argv[]) {

    srand(time(0));
    // create open gl context //
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // //

    // make glfw window //
    GLFWwindow * window = glfwCreateWindow(800, 600, "hangman", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        throw "no glfw window created this is bad, check dependencies";
    }
    glfwMakeContextCurrent(window);
    // //

    // set up glad //
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw "glad died something has gone wrong check dependencies";
    }
    // //

    // shaders //
    char vertFile[] = {"shaders/vertshader.vert"};
    char fragFile[] = {"shaders/fragshader.frag"};
    unsigned int shaderprog = shaders::shader_program(vertFile, fragFile);
    glUseProgram(shaderprog);
    // //

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    printf("\nshader success!\n");
    auto chessTextureMapping = chessSprites::GetChessTextures();
    auto update = event<unsigned int>();
    auto whiteKingSprite = sprite((*chessTextureMapping)["w_king_png_1024px.png"], 0, 0, 1, 1);
    update.add(&sprite::draw, &whiteKingSprite);
    // setup input //
    // //
    // set viewport rect //
    glViewport(0, 0, 800, 600);

    // main game loop //
    while(!glfwWindowShouldClose(window))
    {
        update(shaderprog);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // //
    return 0;
//
}
