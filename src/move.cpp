//
// Created by kaloka on 10/12/2020.
//

#include "move.h"
using move::Move;
namespace move {
    auto moveEventBackend = events::event<int, int, int>();

    void GameHandler::fieldClickListener(int field) {
        printf("filed listenner call %i", field);
        chess::piece pieceAtField = chess::piece_at(field);
        selectedField = field;
        if (pieceAtField.type != chess::none && pieceAtField.colour == turn && selectedPiece == -1) spriteBoard->highlight = chess::moves(field);
    }

    GameHandler::GameHandler(chessSprites::SpriteBoard * board) :
    turn(0),
    selectedField(-1),
    selectedPiece(-1),
    spriteBoard(board) {
        spriteBoard->setTurn(turn);
    }

    void GameHandler::textInputListener(char character) {
        chess::piece atSelected = chess::piece_at(selectedField);
        switch (character) {
            case char('E'): // enter
                if (selectedField >= 0 && atSelected.colour == turn &&
                    atSelected.type != chess::none && selectedPiece == -1) {
                    selectedPiece = selectedField;
                    selectedField = -1;
                } else if (selectedField >= 0 && // something is selected // this is the branch to make move
                           ((atSelected.colour != turn && atSelected.type != chess::none) || atSelected.type == chess::none) // if not our piece
                           && selectedPiece != -1 && chess::legal(turn, selectedPiece, selectedField)) { // piece is set // move is legal
                    moveEventBackend(turn, selectedPiece, selectedField);
                    turn = !turn;
                    spriteBoard->setTurn(turn);
                    spriteBoard->highlight.clear();
                    selectedField = -1;
                    selectedPiece = -1;
                }
                break;
            default:
                break;
        }
    }

    Move::Move(int player, int from, int to) : player(player), from(from), to(to) {}


    event<int, int, int> *moveEvent() {
        return &move::moveEventBackend;
    }
}

