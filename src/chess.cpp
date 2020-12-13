//
// Created by kaloka on 10/12/2020.
//

#include "chess.h"


namespace chess {
    //indexing is rows then cols
    // bottom left from white is 0 <- white starts
    const int worth[7] = {0, 1, 5, 3, 3, 9, 1000}; // none, pawn, rook, knight, bishop, queen, king

    piece board[64]; // dugh

    int score[2]; // dugh

    bool castling_moved[2][3]; // [player] , [king, tower left, tower right]
    int last_enpassant; // pos
    int last_enpassant_victim; // pos

    void init() {
        for (int i = 0; i < 16; i++) board[i].colour = white; // all pieces there are white
        for (int i = 48; i < 64; i++) board[i].colour = black; // same for black
        board[4].type = board[60].type = king; // all obv setup code
        board[3].type = board[59].type = queen;
        board[0].type = board[7].type = board[56].type = board[63].type = rook;
        board[1].type = board[6].type = board[57].type = board[62].type = knight;
        board[2].type = board[5].type = board[58].type = board[61].type = bishop;
        for (int i = 8; i < 16; i++) board[i].type = pawn;
        for (int i = 48; i < 56; i++) board[i].type = pawn;
        // setup done
        score[0] = score[1] = 0;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                castling_moved[i][j] = false;

        last_enpassant = -1;
    }

    std::vector<int> rookMoves(int pos) {
        std::vector<int> out;
        const int direction[4]{1, -1, 8, -8}; // right , left , up , down

        for (int i = 0; i < 4; i++) {
            int temp = pos;
            while (true) { // basically a raycast along the axis
                if (i == 0 && temp % 8 == 7) break; // check OOB hori
                if (i == 1 && temp % 8 == 0) break;
                temp += direction[i]; // move in the respective dir

                if (temp > 63 || temp < 0) break; // vertical OOB is obv if on chess board -> legal
                if (board[temp].type != none) { // if piece
                    if (board[temp].colour != board[pos].colour) { // if other team
                        out.push_back(temp); // put on list of legal
                    }
                    break; // cannot go past piece
                }
                out.push_back(temp); // legal if no piece
            }
        }
        return out; // all legal moves
    }

    std::vector<int> bishopMoves(int pos) {
        std::vector<int> out;
        const int direction[4]{9, -7, -9, 7}; // right up , right down , left down , left up

        for (int i = 0; i < 4; i++) { // all dirs
            int temp = pos;
            while (true) {
                if (temp % 8 == 7 && i < 2) break; // check hori OOB r
                if (temp % 8 == 0 && i > 1) break; // and l
                temp += direction[i]; // move
                if (temp > 63 || temp < 0) break; // vertical OOB
                if (board[temp].type != none) { // see rook
                    if (board[temp].colour != board[pos].colour) {
                        out.push_back(temp);
                    }
                    break; // does not follow dry but effort >>>>>>>>>> use cuz break in function is cancer
                }
                out.push_back(temp);
            }
        }
        return out;
    }

    std::vector<int> pawnMoves(int pos) {
        std::vector<int> out;
        int fieldFront = pos + 8 * ((board[pos].colour == white) * 2 - 1);
        if (board[fieldFront].type == none) // is empty
            out.push_back(fieldFront);
        for (int i = -1; i < 2; i += 2) { // front left front right
            if (pos % 8 == 0 && i == -1) continue; // check OOB
            if (pos % 8 == 7 && i == 1) continue;
            if (board[fieldFront + i].colour != board[pos].colour //  is enemy
                && (board[fieldFront + i].type != none // and is not empty cuz empty fields have color
                    || (fieldFront + i) == last_enpassant)) // or enpassant
                out.push_back(fieldFront + i); // then field legal
        }
        if (int(pos / 8) == ((board[pos].colour == black) * 5 + 1) // if in second row of color
        // pos + 16 * ((board[pos].colour == white) * 2 - 1) --> two in front
            && board[pos + 16 * ((board[pos].colour == white) * 2 - 1)].type == none) // and empty
            out.push_back(pos + 16 * ((board[pos].colour == white) * 2 - 1)); // legal
        return out;
    }

    std::vector<int> knightMoves(int pos) {
        std::vector<int> out;
        const int knight_dirs[4] = {17, -15, 10, -6}; // moves on one side
        for (int i = -1; i < 2; i += 2) { // left and right
            for (int j = 0; j < 4; j++) {
                if (pos % 8 >= 6 + (j < 2) && (i > 0)) continue; // horizontal r
                if (pos % 8 <= 1 - (j < 2) && (i < 0)) continue;  // l
                if (pos + i * knight_dirs[j] > 63 || pos + i * knight_dirs[j] < 0) continue; // vertical
                if (board[pos + i * knight_dirs[j]].colour != board[pos].colour || // of enemy team of empty
                    board[pos + i * knight_dirs[j]].type == none)
                    out.push_back(pos + i * knight_dirs[j]);
            }
        }
        return out;
    }

    std::vector<int> kingMoves(int pos) {
        std::vector<int> out;
        for (int i = -1; i < 2; i++)
            for (int j = -1; j < 2; j++)
                if (i != j) {
                    if (pos % 8 == 0 && i < 0) continue; // hori l
                    if (pos % 8 == 7 && i > 0) continue; // r
                    if (pos + i + 8 * j < 0 || pos + i + 8 * j > 63) continue; // vert
                    if (board[pos + i + 8 * j].type == none || board[pos + i + 8 * j].colour != board[pos].colour) // if non or other
                        out.push_back(pos + i + 8 * j);
                }
        return out;
    }

    bool threatened(int pos) {
        bool threatened = false;
        const int dirs[8] = {-1, 7, -9, -7, 9, 1, 8, -8}; // fields arround king
        for (int i = 0; i < 8; i++) {// raycast along all axis (diag and hori)
            int temp = pos;
            while (true) {  // move the ray cast
                if (temp % 8 == 7 && i > 3 && i < 6) break; // bounds check hori right // not at right most // and hori move
                if (temp % 8 == 0 && i < 4) break; // left most
                temp += dirs[i];
                if (temp > 63 || temp < 0) break;
                if (board[temp].type != none) {
                    if (board[temp].colour != board[pos].colour) {
                        if ((board[temp].type == queen)
                            || (board[temp].type == rook && i > 4 || i == 0)
                            || (board[temp].type == bishop && i > 0 && i < 5))
                            threatened = true;
                    }
                    break;
                }
            }
        }
        for (int i: knightMoves(pos)) { // if i could do a knight move from here
            if (board[i].type == knight) threatened = true;
        }
        return threatened;
    }

    std::vector<int> legalMoves(int pos) {
        std::vector<int> out = moves(pos);
        for (auto i = out.begin(); i != out.end(); ) {
            if (!legal(board[pos].colour, pos, *i)) out.erase(i);
            else i++;
        }
        return out;
    }

    std::vector<int> moves(int pos) { // get moves for a piece at pos
        std::vector<int> out;
        std::vector<int> temp;

        switch (board[pos].type) {
            case none:
                break;
            case pawn:
                out = pawnMoves(pos);
                break;
            case knight:
                out = knightMoves(pos);
                break;
            case rook:
                out = rookMoves(pos);
                break;
            case bishop:
                out = bishopMoves(pos);
                break;
            case queen:
                out = rookMoves(pos);
                temp = bishopMoves(pos);
                for (int i : temp) out.push_back(i);
                break;
            case king:
                out = kingMoves(pos);
                break;
            default:
                break;
        }
        return out;
    }


    bool kingIsThreatened(int colour) { // get king of color and check
        int k;
        for (int i = 0; i < 64; i++)
            if (board[i].colour == colour && board[i].type == king) {
                k = i;
                break;
            }
        return threatened(k);
    }

    bool legal(int colour, int from, int to) {
        if (colour != board[from].colour) return false;
        std::vector<int> possibles = moves(from);
        piece aggressor = board[from];
        piece victim = board[to];
        bool can_move = false;
        for (int i : possibles) { // if in poss moves
            can_move = can_move || (i == to);
        }
        // king threat check
        board[to].colour = board[from].colour; // {
        board[to].type = board[from].type;
        board[from].type = none;  // move }
        can_move = can_move && !kingIsThreatened(colour); // check color
        board[to].colour = victim.colour; // {
        board[to].type = victim.type;
        board[from].type = aggressor.type; // unmove }
        return can_move;
    }

    bool move(int player, int from, int to) {
        bool can_move = legal(player, from, to); // is legal
        if (!can_move) return false; // if not -> sike
        if (board[from].type == pawn) {
            if (abs(from - to) == 16) { // moving two steps
                last_enpassant = from + 8 * ((board[from].colour == white) * 2 - 1); // field behind post move
                last_enpassant_victim = to; // we could now be stabbed. sad
            } else last_enpassant = -1; // else no chance for en passant
            if (to == last_enpassant) { // perform enpassant
                score[board[from].colour] += worth[board[last_enpassant_victim].type]; // move
                board[last_enpassant_victim].type = none; // delvic
            }
        }

        if (board[from].type == king) { //
            castling_moved[player][0] = true; // the king has been moved
        }

        if (board[from].type == rook && (from % 8 == 1 || from % 8 == 7)) {
            castling_moved[player][(from % 8 - 1) / 6 + 1]; // (col(7 / 1) - 1) -> (0 or 1) + 1 ( cuz 0 is king)
        }

        score[board[from].colour] += worth[board[to].type];

        board[to].colour = board[from].colour; // move
        board[to].type = board[from].type;
        board[from].type = none;

        return true;
    }

    piece getPiece(int pos) { // interfacing
        return board[pos];
    }

    bool castlingPossible(int player, int king, int rook) { //
        int dir = (rook - king > 0) * 2 - 1; // left -1 right 1
        if (threatened(king) ||
        threatened(king + dir) ||
        threatened(king + 2*dir) ||
        threatened(rook)) return false; // cannot castle your way out of this

        if (board[king].colour != player || board[rook].colour != player) return false; // we canot castle with the other
        if (rook != 0 && rook != 7 && rook != 56 && rook != 63) return false; // rook not there sad. // this is redundant with moved code
        if (castling_moved[player][0] || castling_moved[player][(rook % 8 - 1) / 6 + 1]) return false; // if moved

        bool possible = true;

        for (int i = king; i < rook; i += (rook - king > 0) ? 1 : -1)
            possible = possible && (board[i].type == none); // no piece there

        return possible;
    }

    bool castle(int player, int king, int rook) {
        if (!castlingPossible(player, king, rook)) return false; // is legal

        int dir = (rook - king > 0) ? 1 : -1;
        int kdest;
        int rdest;
        // move
        kdest = king + 2 * dir;
        rdest = king + dir;

        board[kdest].type = chess::king;
        board[kdest].colour = player;

        board[rdest].type = chess::rook;
        board[rdest].colour = player;

        board[king].type = none;
        board[rook].type = none;

        return true;
    }

    bool gameOver(bool player) {
        for (int i = 0; i <= 64; i++) {
            if (board[i].colour == player && !legalMoves(i).empty()) return false; // short circute will make this more efficient
        }
        return true;
    }

    void setPiece(int pos, piece it) {
        board[pos] = it;
    }

    int getScore(bool player) {
        return score[player];
    }

    bool canMove(int piece) {
        return !legalMoves(piece).empty();
    }

    piece::piece() : type(none), colour(-1) {}

    piece::piece(piecetype type, int colour) : type(type), colour(colour) {}
};

