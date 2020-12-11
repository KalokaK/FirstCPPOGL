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
    struct Move { // not really ever used...
        // originally was planned to keep track of moves and use reified actions
        Move(int player, int from, int to);
        unsigned int player, from, to; // white 0 black 1
    };
    // i have no clue why this event is global // don't have time to fix it
    events::event<int, int, int> *moveEvent();
    class GameHandler {
        bool gameOver;
        std::vector<Move> moves;
        int selectedPiece;
        int selectedField;
    public:
        int turn; // 0 = white, 1 black

        void fieldClickListener(int field);
        void textInputListener(char character);
        sprites::Text *displayText;
        chessSprites::SpriteBoard *spriteBoard;
        explicit GameHandler(chessSprites::SpriteBoard * board, sprites::Text *displayText);

        int waitForConvert;
    };

}
#endif //OGLHANGMAN_MOVE_H
