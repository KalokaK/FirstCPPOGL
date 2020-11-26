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
}
#endif //OGLHANGMAN_CHESSSPRITEHANDLER_H
