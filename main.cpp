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

    uint8_t r = 123;
    uint8_t g = 100;
    uint8_t b = 69;
    uint8_t a = 128;

    float f = encodeRGBAAsFloat(r, g, b, a);
    decodeRGBAFromFloat(&r, &g, &b, &a, f);
    printf("r: %d, g: %d, b: %d, a: %d \n", r, g, b, a);

    srand(time(0));
    // create open gl context //
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // //

    // make glfw window //
    GLFWwindow * window = glfwCreateWindow(800, 800, "hangman", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        throw "no glfw window created this is bad, check dependencies";
    }
    glfwMakeContextCurrent(window);
    // //
    glfwSetFramebufferSizeCallback(window, helpers::framebufferSizeCallback);
    // set up glad //
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw "glad died something has gone wrong check dependencies";
    }
    // //

    // shaders //
    char spriteVertFile[] = {"shaders/sprite.vert"};
    char spriteFragFile[] = {"shaders/sprite.frag"};
    unsigned int spriteProg = shaders::shader_program(spriteVertFile, spriteFragFile);
    char textVertFile[] = {"shaders/text.vert"};
    char textFragFile[] = {"shaders/text.frag"};
    unsigned int textProg = shaders::shader_program(textVertFile, textFragFile);
    char uiVertFile[] = {"shaders/ui.vert"};
    char uiFragFile[] = {"shaders/ui.frag"};
    unsigned int uiProg = shaders::shader_program(uiVertFile, uiFragFile);

    glUseProgram(spriteProg);
    // //

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    printf("\nshader success!\n");
    auto chessTextureMapping = chessSprites::GetChessTextures();
    auto spriteUpdate = event<unsigned int>();
    auto textUpdate = event<unsigned int>();
    auto uiUpdate = event<unsigned int>();

    sprites::Text::TextInit();
    auto myTestText = sprites::Text("Hello Chess");
    myTestText.x = -0.5f;
    myTestText.y = -0.6f;
    textUpdate.add(&sprites::Text::draw, &myTestText);

    auto boardSprite = sprite((*chessTextureMapping)["chess.png"], 0, 0);
    auto myTestBoard = chessSprites::SpriteBoard(&boardSprite);
    chessSprites::SpriteBoard::setupBoard(&myTestBoard, chessTextureMapping);
    myTestBoard.boardScale = 1.f;
    myTestBoard.boardY = 0.2;
    myTestBoard.setTurn(true);
    myTestBoard.boardSprite->setSpriteAttrib(COLOR, f);
    myTestBoard.updateSpriteData();
    spriteUpdate.add(&chessSprites::SpriteBoard::draw, &myTestBoard);
    // setup input //
    // //
    // set viewport rect //
    glViewport(0, 0, 800, 800);

    // main game loop //
    while(!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        spriteUpdate(spriteProg);
        textUpdate(textProg);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // //
    return 0;
//
}
