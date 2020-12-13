//
// Created by kaloka on 10/12/2020.
//

#ifndef CHESS_H
#include <vector>
#include <iostream>


#define CHESS_H
#define white 0
#define black 1
/*
-------BOARD LAYOUT-------
        black
    __________________
    |56|57 |...|62|63|
    |48|             |
    |.               |
    |.               |
    |.               |
    |0|1|2|...       |

        white
*/
namespace chess {

    typedef enum piecetype {
        none,
        pawn,
        rook,
        bishop,
        knight,
        queen,
        king
    };

    struct piece {
        piece();
        piece(piecetype type, int colour);
        piecetype type = none;
        int colour; // false is black, true is white
    };

    // there is some global state in chess.cpp, did not have time to make a class out of it
    void init();  // setup
    std::vector<int> moves(int pos); // gives all possible moves from that position
    std::vector<int> legalMoves(int pos);
    piece getPiece(int pos);        // returns piece at position
    void setPiece(int pos, piece it);
    bool canMove(int piece);

    bool legal(int player, int from, int to);  // checks if move from from to to is legal
    bool move(int player, int from,
              int to); // checks if move legal and performs move + returns true if yes returns false if no
    bool gameOver(bool player); // return -1 if no, 0 if white, 1 if black
    bool kingIsThreatened(int colour); // checks whether king of color is threatened
    bool castlingPossible(int player, int king, int rook); // can castle, internal
    bool castle(int player, int king, int rook); // castle // internal
    int getScore(bool player);
}
#endif // CHESS_H