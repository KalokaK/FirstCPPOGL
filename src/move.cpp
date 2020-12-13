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
        if (gameOver || selectedField < 0) return;
        chess::piece atSelected = chess::getPiece(selectedField);
        if (character == char('E') && waitForConvert < 0) { // enter
            if (selectedField >= 0 && atSelected.colour == turn &&
                atSelected.type != chess::none && selectedPiece == -1 && chess::canMove(selectedField)) {
                selectedPiece = selectedField; // select piece at
                selectedField = -1; // unselect field
            } else if (selectedField >= 0) { // something is selected
                moveEventBackend(turn, selectedPiece, selectedField); // tell stuff to move
                if (atSelected.type == chess::pawn) waitForConvert = selectedField;
                turn = !turn; // switch turn
                gameOver = chess::gameOver(turn);
                displayText->setText(
                        std::string((bool) turn ? "black" : "white") +
                        (chess::kingIsThreatened(turn) ? (gameOver ? " lost!" : " is threatened") : "'s turn"));
                spriteBoard->setTurn(turn); // flip board
                spriteBoard->highlight.clear(); // no highlights
                selectedField = -1; // unselect
                selectedPiece = -1;
            }
        } else if (waitForConvert > -1) {
            switch (character) {
                case 'Q': // uh... at this point making things stateless in chess would be much easier....
                    chess::setPiece(waitForConvert, chess::piece(chess::queen, chess::getPiece(waitForConvert).colour));
                    break;
                case 'R':
                    chess::setPiece(waitForConvert, chess::piece(chess::rook, chess::getPiece(waitForConvert).colour));
                    break;
                case 'K':
                    chess::setPiece(waitForConvert, chess::piece(chess::knight, chess::getPiece(waitForConvert).colour));
                    break;
                case 'B':
                    chess::setPiece(waitForConvert, chess::piece(chess::bishop, chess::getPiece(waitForConvert).colour));
                    break;
                default:
                    break;
            }
            waitForConvert = -1;
        }
    }
    // wanted to use reified actions... I dont know if this struct is ever used...
    Move::Move(int player, int from, int to) : player(player), from(from), to(to) {}


    event<int, int, int> *moveEvent() {
        return &move::moveEventBackend; // static storage duration
    }
}

