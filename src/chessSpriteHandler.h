//
// Created by kaloka on 26/11/2020.
//

#ifndef OGLHANGMAN_CHESSSPRITEHANDLER_H
#define OGLHANGMAN_CHESSSPRITEHANDLER_H
#include <filesystem>
#include <map>
#include <string>
#include <glBoilerplateAndHelpers/sprite.h>
#include <glBoilerplateAndHelpers/texture.h>
#include <iostream>

namespace chessSprites{
    std::map<std::string, unsigned int> * GetChessTextures();
    struct SpriteBoard {
        std::vector<int> highlight;
        sprite * boardSprite;
        float boardScale, boardX, boardY;
        sprite * board[8][8];
        void move(int player, int from, int to);
        explicit SpriteBoard(sprite *boardSprite);
        void updateSpriteData();
        void draw(unsigned int shader);

        void setupBoard(chessSprites::SpriteBoard *board, std::map<std::string, unsigned int> *pieceTextureLookup);

    private:
        unsigned int glowTex;
        unsigned int glowShader;
        bool turn;
    public:
        bool isTurn() const;

        void setTurn(bool turn);

        std::map<string, unsigned int> *textureLookup;
    };
}
#endif //OGLHANGMAN_CHESSSPRITEHANDLER_H
