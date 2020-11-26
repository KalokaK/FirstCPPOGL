//
// Created by greut on 12.11.2020.
//

#include <iostream>

using namespace std;

class Figure
{
public:
    // current position on the field:
    float x_position;
    float y_position;

    // all possible positions to go to (max. 14 possible positions)
    int possiblePositions [14][2];
    // all legal positions
    int legalPositions [14][2];

    /// On the selections on the figure, show all possible and legal positions.
    void selectFigure()
    {
        // highlight all possible AND legal positions,
        // todo: so the player only can go to legal positions.

        // filters legal positions
        getLegalFields();

        // highlight all legal positions
        highlightPossiblePositions();
    }

    /// checks if field is legal.
    void getLegalFields()
    {
        // length of array
        int len = sizeof(possiblePositions)/sizeof(possiblePositions[0]);
        int index = 0;
        for (int field_int = 0; field_int < len; field_int++)
        {
            // todo
            // check if field at field_int would be a legal move
            // remove all other not possible/illegal positions
            // put all legal fields in legalPositions
            if (/*field_is_legal*/true)
            {
                // add the legal position to the legalPositions array:
                legalPositions[index][0] = possiblePositions[field_int][0];
                legalPositions[index][1] = possiblePositions[field_int][1];
            }
        }
    }

    /// highlight legit position.
    void highlightPossiblePositions()
    {
        // highlight every field in legalPositions:
        int len = sizeof(legalPositions)/sizeof(legalPositions[0]);
        for (int field_int = 0; field_int < len; field_int++)
        {
            // highlight the following field
            cout << "x=" << legalPositions[field_int][0] <<
                   " y=" << legalPositions[field_int][0] << endl;

            // todo highlight the field
        }
    }

    /// sets new position to figure, when made a new move. xNew/xNew are the coordinates of the new position.
    void moveToNewPosition(float xNew, float yNew)
    {
        // set new positions, where xNew, yNew are the x-,y-coordiantes of the new field,
        // who are the new input values of the mouse, clicked on the legal field.

        // length of array
        int len = sizeof(legalPositions)/sizeof(legalPositions[0]);
        // check if the choosen field is in the legalPosition array:
        for (int field_int = 0; field_int < len; field_int++)
        {
            if (legalPositions[field_int][0] == xNew &&
                legalPositions[field_int][1] == yNew)
            {
                // if it is in the array: set the new position to the choosen position:
                x_position = xNew;
                y_position = yNew;

                //exit the loop:
                break;
            }
        }
    }
};

/// Bauer
class Pawn : public Figure
{
public:

};

/// Turm
class Rook : public Figure
{
public:

};

/// Pferd
class Knight : public Figure
{
public:

};

/// Springer
class Bishop : public Figure
{
public:

};

/// Königin
class Queen : public Figure
{
public:

};

/// König
class King : public Figure
{
public:

};

int main()
{
    // ----------------------------- WHITE -----------------------------
    // Pawns:
    Pawn *w_pawn_01 = new Pawn();
    w_pawn_01->x_position = 0;
    w_pawn_01->y_position = 1;
    Pawn *w_pawn_02 = new Pawn();
    w_pawn_02->x_position = 1;
    w_pawn_02->y_position = 1;
    Pawn *w_pawn_03 = new Pawn();
    w_pawn_03->x_position = 2;
    w_pawn_03->y_position = 1;
    Pawn *w_pawn_04 = new Pawn();
    w_pawn_04->x_position = 3;
    w_pawn_04->y_position = 1;
    Pawn *w_pawn_05 = new Pawn();
    w_pawn_05->x_position = 4;
    w_pawn_05->y_position = 1;
    Pawn *w_pawn_06 = new Pawn();
    w_pawn_06->x_position = 5;
    w_pawn_06->y_position = 1;
    Pawn *w_pawn_07 = new Pawn();
    w_pawn_07->x_position = 6;
    w_pawn_07->y_position = 1;
    Pawn *w_pawn_08 = new Pawn();
    w_pawn_08->x_position = 7;
    w_pawn_08->y_position = 1;

    // Rooks:
    Rook *w_rook_01 = new Rook();
    w_rook_01->x_position = 0;
    w_rook_01->y_position = 0;
    Rook *w_rook_02 = new Rook();
    w_rook_02->x_position = 7;
    w_rook_02->y_position = 0;

    // Knights:
    Knight *w_knight_01 = new Knight();
    w_knight_01->x_position = 1;
    w_knight_01->y_position = 0;
    Knight *w_knight_02 = new Knight();
    w_knight_02->x_position = 6;
    w_knight_02->y_position = 0;

    // Bishops:
    Bishop *w_bishop_01 = new Bishop();
    w_bishop_01->x_position = 2;
    w_bishop_01->y_position = 0;
    Bishop *w_bishop_02 = new Bishop();
    w_bishop_02->x_position = 5;
    w_bishop_02->y_position = 0;

    // Queen:
    Queen *w_queen = new Queen();
    w_queen->x_position = 3;
    w_queen->y_position = 0;

    // King:
    King *w_king = new King();
    w_king->x_position = 4;
    w_king->y_position = 0;

}