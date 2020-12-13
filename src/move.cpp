//
// Created by kaloka on 10/12/2020.
//

#include "move.h"
using move::Move;
namespace move {
    auto moveEventBackend = events::event<int, int, int>();

    void GameHandler::fieldClickListener(int field) {
        printf("filed listenner call %i", field);
        chess::piece pieceAtField = chess::getPiece(field);
        selectedField = field;
        if (pieceAtField.type != chess::none && pieceAtField.colour == turn && selectedPiece == -1) spriteBoard->highlight = chess::legalMoves(field);
    }

    GameHandler::GameHandler(chessSprites::SpriteBoard * board, sprites::Text *displayText) :
    turn(0),
    gameOver(false),
    selectedField(-1),
    selectedPiece(-1),
    waitForConvert(-1),
    spriteBoard(board),
    displayText(displayText) {
        spriteBoard->setTurn(turn);
    }

    void GameHandler::textInputListener(char character) {
        if (waitForConvert > -1) {
            switch (character) {
                case 'Q': // uh... at this point making things stateless in chess would be much easier....
                    chess::setPiece(waitForConvert, chess::piece(chess::queen, chess::getPiece(waitForConvert).colour));
                    break;
                case 'R':
                    chess::setPiece(waitForConvert, chess::piece(chess::rook, chess::getPiece(waitForConvert).colour));
                    break;
                case 'K':
                    chess::setPiece(waitForConvert,
                                    chess::piece(chess::knight, chess::getPiece(waitForConvert).colour));
                    break;
                case 'B':
                    chess::setPiece(waitForConvert,
                                    chess::piece(chess::bishop, chess::getPiece(waitForConvert).colour));
                    break;
                default:
                    break;
            }
            waitForConvert = -1;
        } else if (!gameOver && selectedField > -1) {
            chess::piece atSelected = chess::getPiece(selectedField);
            if (character == char('E') && waitForConvert < 0) { // enter
                if (selectedField >= 0 && atSelected.colour == turn &&
                    atSelected.type != chess::none && selectedPiece == -1 && chess::canMove(selectedField)) {
                    selectedPiece = selectedField; // select piece at
                    selectedField = -1; // unselect field
                } else if (selectedField >= 0) { // something is selected
                    moveEventBackend(turn, selectedPiece, selectedField); // tell stuff to move
                    turn = !turn; // switch turn
                    if (atSelected.type == chess::pawn) waitForConvert = selectedField;
                    gameOver = chess::gameOver(turn);
                    displayText->setText( // (w / b) + (change pawn [or] normal play ->  (lost [or] won) [or] turn )
                            std::string((waitForConvert > -1) ^ (bool) turn ? "black" : "white") +
                            // flip if waiting for convert // xor
                            ((waitForConvert > -1) ? // if converting pawn
                             std::string(" select [Q]een, [R]ook, [K]night or [B]ishop \n"
                                         "by pressing the respective key \n for field: ")
                             + std::to_string(selectedField % 8)
                             + std::string(", ")
                             + std::to_string(selectedField / 8)
                                                   : // else if normal gameplay
                             (chess::kingIsThreatened(turn) ? // if under threat
                              (gameOver ? " lost!" : " is threatened")  // either game lost or under threat
                                                            : // if not under threat -> turn
                              "'s turn"))
                    );
                    spriteBoard->setTurn(turn); // flip board
                    spriteBoard->highlight.clear(); // no highlights
                    selectedField = -1; // unselect
                    selectedPiece = -1;
                }
            }
        }
    }
    // wanted to use reified actions... I dont know if this struct is ever used...
    Move::Move(int player, int from, int to) : player(player), from(from), to(to) {}


    event<int, int, int> *moveEvent() {
        return &move::moveEventBackend; // static storage duration
    }
}

