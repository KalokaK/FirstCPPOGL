//
// Created by kaloka on 10/12/2020.
//

#ifndef OGLHANGMAN_MOVE_H
#define OGLHANGMAN_MOVE_H
#include <eventSystem.h>
#include <chess.h>
#include <chessSpriteHandler.h>
#include <glBoilerplateAndHelpers/sprite.h>
namespace move {
    struct Move {
        Move(int player, int from, int to);
        unsigned int player, from, to; // white 0 black 1
    };
    events::event<int, int, int> *moveEvent();
    class GameHandler {

        std::vector<Move> moves;
        int selectedPiece;
        int selectedField;
    public:
        int turn; // 0 = white, 1 black

        void fieldClickListener(int field);
        void textInputListener(char character);
        chessSprites::SpriteBoard *spriteBoard;
        explicit GameHandler(chessSprites::SpriteBoard * board);
    };

}
#endif //OGLHANGMAN_MOVE_H
