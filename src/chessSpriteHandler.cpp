//
// Created by kaloka on 26/11/2020.
//

#include "chessSpriteHandler.h"

std::map<std::string, unsigned int> *chessSprites::GetChessTextures() {
    auto textureMap = new std::map<std::string, unsigned int>();
    for (const auto &texture : std::filesystem::directory_iterator("chess-sprites")) {
        unsigned int glTextureId = textures::loadTextureToBuffer(texture.path().c_str(), 0, 0);
        textureMap->insert(std::pair<std::string, unsigned int>(texture.path().filename(), glTextureId));
    }
    for (auto i = textureMap->begin(); i != textureMap->end(); i++) {
        std::cout << i->first << " => " << i->second << '\n';
    }
    return textureMap;
}
