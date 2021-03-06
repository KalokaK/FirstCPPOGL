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
        // if no piece is selected or the move from piece to field is legal -> select the field
        selectedField = field + (waitForConvert > -1) * (selectedField - field);
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
            std::string spriteText;
            chess::piece thePiece;
            switch (character) {
                case 'Q': // uh... at this point making things stateless in chess would be much easier....
                    thePiece = chess::piece(chess::queen, chess::getPiece(waitForConvert).colour);
                    spriteText = !turn ? "b_queen_png_1024px.png" : "w_queen_png_1024px.png";
                    break;
                case 'R':
                    thePiece = chess::piece(chess::queen, chess::getPiece(waitForConvert).colour);
                    spriteText = !turn ? "b_rook_png_1024px.png" : "w_rook_png_1024px.png";
                    break;
                case 'K':
                    thePiece = chess::piece(chess::queen, chess::getPiece(waitForConvert).colour);
                    spriteText = !turn ? "b_knight_png_1024px.png" : "w_knight_png_1024px.png";
                    break;
                case 'B':
                    thePiece = chess::piece(chess::queen, chess::getPiece(waitForConvert).colour);
                    spriteText = !turn ? "b_bishop_png_1024px.png" : "w_bishop_png_1024px.png";
                    break;
                default:
                    return;
            }
            delete spriteBoard->board[waitForConvert / 8][waitForConvert % 8];
            chess::setPiece(waitForConvert, thePiece);
            spriteBoard->board[waitForConvert / 8][waitForConvert % 8] =
                    new sprite((*spriteBoard->textureLookup)[spriteText], 0, 0);
            waitForConvert = -1;
            spriteBoard->updateSpriteData();
            displayText->setText(std::string((bool) turn ? "black" : "white") + "s' turn");
        } else if (!gameOver && selectedField > -1) {
            chess::piece atSelected = chess::getPiece(selectedField);
            if (character == char('E') &&
                waitForConvert < 0) { // accept button // and not waiting for conversion of pawn
                if (atSelected.colour == turn && // same color
                    atSelected.type != chess::none && // and not empty
                    selectedPiece == -1 && // and no piece is set
                    chess::canMove(selectedField)) { // and that piece can actually move
                    selectedPiece = selectedField; // set the selected piece
                    selectedField = -1; // unselect field
                } else if (chess::legal(turn, selectedPiece,
                                        selectedField)) { // the move would be legal // move from or to -1 is not!
                    moveEventBackend(turn, selectedPiece, selectedField); // tell stuff to move
                    if (chess::getPiece(selectedField).type == chess::pawn  &&
                            (selectedField < 8 ||
                             selectedField > 55)) {
                        waitForConvert = selectedField;
                    }
                    turn = !turn; // switch turn
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

                    for (int i = 0; i < 64; i++) { // uh last min fix for enpassant rendering
                        if(chess::getPiece(i).type == chess::none)
                            if (spriteBoard->board[i / 8][i % 8] != nullptr) {
                                delete spriteBoard->board[i / 8][i % 8]; spriteBoard->board[i / 8][i % 8] = nullptr; }
                    }
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

