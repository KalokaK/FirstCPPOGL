//
// Created by kaloka on 17/11/2020.
//

#ifndef OGLHANGMAN_SPRITE_H
#define OGLHANGMAN_SPRITE_H
#include <helpers.h>
#include <string>
#include <stb/stb_image.h>
#include <filesystem>

enum Sprite_Attributes {
    X,
    Y,
    SCALE,
    COLOR
};

using std::string;
class sprite : public sprites::Sprite {
    unsigned int vbo;
    unsigned int texture;
    int texX, texY;
    bool enabled;
    unsigned int ebo;
    uint8_t r, g, b;
public:
    unsigned int vao;
    void setSpriteAttrib(Sprite_Attributes attrib, float val);
    void setTexture(unsigned int i);
    void setEnabled(bool val);
    [[nodiscard]] unsigned int getTexture() const;
    [[nodiscard]] bool isEnabled() const;
private:
    void onEnable();
    void onDisable();
    void generateVertexBuffer();
public:
    explicit sprite(GLuint glTexture, float xPos, float yPos);

    void draw(unsigned int shaderProgram) override;
};

float encodeRGBAAsFloat(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void decodeRGBAFromFloat(uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a, float sadFloat);

#endif //OGLHANGMAN_SPRITE_H
