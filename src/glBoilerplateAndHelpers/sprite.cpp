//
// Created by kaloka on 17/11/2020.
//

#include "sprite.h"

void sprite::draw(unsigned int shaderProgram) {
    if (enabled) {
        glUniform1i(glGetUniformLocation(shaderProgram, "text"), 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

sprite::sprite(GLuint glTexture, float xPos, float yPos) :
enabled(true),
texture(),
texX(), texY(),
r(255), g(255), b(255),
vao(),
vbo(),
ebo() {
    x = xPos;
    y = yPos;
    texture = glTexture;
    int miplevel = 0;
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &texX);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &texY);
    auto max = (float)std::max(texX, texY);
    w = (float)texX / max;
    h = (float)texY / max;
    generateVertexBuffer();
}

void sprite::onEnable() {

}

void sprite::onDisable() {

}

unsigned int sprite::getTexture() const {
    return texture;
}

bool sprite::isEnabled() const {
    return enabled;
}

void sprite::setTexture(unsigned int i) {
    sprite::texture = i;
}

void sprite::setEnabled(bool val) {
    sprite::enabled = val;
}

void sprite::generateVertexBuffer() {
    float vertices[] = {
            // positions          // colors           // texture coords
            x+(w/2),  y+(h/2), 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // top right
            x+(w/2),  y-(h/2), 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // bottom right
            x-(w/2),  y-(h/2), 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // bottom left
            x-(w/2),  y+(h/2), 0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f  // top left
    };
    unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    ebo = EBO;
    vao = VAO;
    vbo = VBO;
}

void sprite::setSpriteAttrib(Sprite_Attributes attrib, float val) {
    uint8_t  a = 255;
    auto max = (float)std::max(texX, texY);
    switch (attrib) {
        case X:
            x = val;
            break;
        case Y:
            y = val;
            break;
        case SCALE:
            w = val * (float)texX / max;
            h = val * (float)texY / max;
            break;
        case COLOR:
            decodeRGBAFromFloat(&r, &g, &b, &a, val);
            printf("%f, %f, %f \n", (float)r/256, (float)g/256, (float)b/256);
            break;
    }
    float vertices[] = {
            // positions          // colors           // texture coords
            x+(w/2),  y+(h/2), 0.0f,   (float)r/256, (float)g/256, (float)b/256,   1.0f, 1.0f, // top right
            x+(w/2),  y-(h/2), 0.0f,   (float)r/256, (float)g/256, (float)b/256,   1.0f, 0.0f, // bottom right
            x-(w/2),  y-(h/2), 0.0f,   (float)r/256, (float)g/256, (float)b/256,   0.0f, 0.0f, // bottom left
            x-(w/2),  y+(h/2), 0.0f,   (float)r/256, (float)g/256, (float)b/256,   0.0f, 1.0f  // top left
    };
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

float encodeRGBAAsFloat(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    uint32_t sadFloat = ((r << 24u) | (g << 16u) | (b << 8u) | a); // float might not always be 32 bit... but we are too cool for that...
    // imports are hard...
    return *((float *) &sadFloat);
}

void decodeRGBAFromFloat(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a, float sadFloat) {
    uint8_t *confusedUintArray = ((uint8_t *) &sadFloat);
    *r = confusedUintArray[3];
    *g = confusedUintArray[2]; // endian ness and such... lets face it this is never gunna run on a big endian server....
    *b = confusedUintArray[1];
    *a = confusedUintArray[0];
}

