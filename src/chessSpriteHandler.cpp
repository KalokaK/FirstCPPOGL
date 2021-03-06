//
// Created by kaloka on 26/11/2020.
//

#include "chessSpriteHandler.h"

std::map<std::string, unsigned int> *chessSprites::GetChessTextures() {
    auto textureMap = new std::map<std::string, unsigned int>();
    for (const auto &texture : std::filesystem::directory_iterator("chess-sprites")) {
        unsigned int glTextureId = textures::loadTextureToBuffer(texture.path().string(), 0, 0);
        textureMap->insert(std::pair<std::string, unsigned int>(texture.path().filename().string(), glTextureId));
    }
    for (auto i = textureMap->begin(); i != textureMap->end(); i++) {
        std::cout << i->first << " => " << i->second << '\n';
    }
    return textureMap;
}

chessSprites::SpriteBoard::SpriteBoard(sprite *boardSprite) :
board(), boardScale(1), boardX(0), boardY(0), boardSprite(boardSprite), turn(), highlight(), glowTex(), glowShader() {
    glowTex = textures::loadTextureToBuffer(std::string("glow.png"), 0, 0);
    glowShader = shaders::shader_program("shaders/highlight.vert", "shaders/highlight.frag");
}

void chessSprites::SpriteBoard::updateSpriteData() {
    boardSprite->setSpriteAttrib(SCALE, boardScale);
    boardSprite->setSpriteAttrib(X, boardX);
    boardSprite->setSpriteAttrib(Y, boardY);
    for (int idx = 0; idx <= 7; idx++) {
        for (int jdx = 0; jdx <= 7; jdx++) {
            float idxT = (turn * -2 + 1) * (idx - 3.5f);
            float jdxT = (turn * -2 + 1) * (jdx - 3.5f);
            if (board[idx][jdx] == nullptr) continue;
            board[idx][jdx]->setSpriteAttrib(SCALE, boardScale*(1.0f/8));
            board[idx][jdx]->setSpriteAttrib(X, boardX + (boardScale/8)*(jdxT));
            board[idx][jdx]->setSpriteAttrib(Y, boardY + (boardScale/8)*(idxT));
        }
    }
}

void chessSprites::SpriteBoard::draw(unsigned int shader) {
    boardSprite->draw(shader);
    for (auto loc : highlight) {
        glUseProgram(glowShader);
        glUniform1i(glGetUniformLocation(glowShader, "field"), abs(loc - 63*turn));
        glUniform1i(glGetUniformLocation(glowShader, "text"), 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, glowTex);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

        glBindVertexArray(boardSprite->vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    for (int idx = 0; idx <= 7; idx++) {
        for (int jdx = 0; jdx <= 7; jdx++) {
            if (board[idx][jdx] == nullptr) continue;
            board[idx][jdx]->draw(shader);
        }
    }
}

void
chessSprites::SpriteBoard::setupBoard(chessSprites::SpriteBoard *board, std::map<std::string, unsigned int> *pieceTextureLookup) {
    textureLookup = pieceTextureLookup;
    auto boardRef = board->board;
    for (int pawn = 0; pawn <= 7; pawn++) {
        boardRef[1][pawn] = new sprite((*pieceTextureLookup)["w_pawn_png_1024px.png"], 0, 0);
        boardRef[6][pawn] = new sprite((*pieceTextureLookup)["b_pawn_png_1024px.png"], 0, 0);
    }
    for (int pair = -1; pair <= 1; pair += 2) {
        boardRef[0][(int)(3.5f + (pair * 1.5))] = new sprite((*pieceTextureLookup)["w_bishop_png_1024px.png"], 0, 0);
        boardRef[0][(int)(3.5f + (pair * 2.5))] = new sprite((*pieceTextureLookup)["w_knight_png_1024px.png"], 0, 0);
        boardRef[0][(int)(3.5f + (pair * 3.5))] = new sprite((*pieceTextureLookup)["w_rook_png_1024px.png"], 0, 0);
    }
    for (int pair = -1; pair <= 1; pair += 2) {
        boardRef[7][(int)(3.5f + (pair * 1.5))] = new sprite((*pieceTextureLookup)["b_bishop_png_1024px.png"], 0, 0);
        boardRef[7][(int)(3.5f + (pair * 2.5))] = new sprite((*pieceTextureLookup)["b_knight_png_1024px.png"], 0, 0);
        boardRef[7][(int)(3.5f + (pair * 3.5))] = new sprite((*pieceTextureLookup)["b_rook_png_1024px.png"], 0, 0);
    }
    boardRef[0][4] = new sprite((*pieceTextureLookup)["w_king_png_1024px.png"], 0, 0);
    boardRef[7][4] = new sprite((*pieceTextureLookup)["b_king_png_1024px.png"], 0, 0);
    boardRef[0][3] = new sprite((*pieceTextureLookup)["w_queen_png_1024px.png"], 0, 0);
    boardRef[7][3] = new sprite((*pieceTextureLookup)["b_queen_png_1024px.png"], 0, 0);
}

bool chessSprites::SpriteBoard::isTurn() const {
    return turn;
}

void chessSprites::SpriteBoard::setTurn(bool turn) {
    SpriteBoard::turn = turn;
    updateSpriteData();
}

void chessSprites::SpriteBoard::move(int player, int from, int to) {
    if (board[to / 8][to % 8] != nullptr) delete board[to / 8][to % 8]; // if not nullptr
    board[to / 8][to % 8] = board[from / 8][from % 8];
    board[from / 8][from % 8] = nullptr;
    updateSpriteData();
}

