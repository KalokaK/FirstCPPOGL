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

    virtual void setPossiblePositions() = 0;

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
        for (int field_int = 0; field_int > len; field_int++)
        {
            // todo
            // check if field at field_int would be a legal move
            // remove all other not possible/illegal positions
            // put all legal fields in legalPositions

            //determines if field is legal:
            if (isFieldLegal(possiblePositions[field_int][0],
                             possiblePositions[field_int][1]))
            {
                // add the legal position to the legalPositions array:
                legalPositions[index][0] = possiblePositions[field_int][0];
                legalPositions[index][1] = possiblePositions[field_int][1];
            }

            index ++;
        }
    }

    /// returns true, if field is legal. This function is specific to type of figure.
    bool isFieldLegal(float x, float y)
    {
        // on default false:
        return false;
    }

    /// highlight legit position.
    void highlightPossiblePositions()
    {
        // highlight every field in legalPositions:
        int len = sizeof(legalPositions)/sizeof(legalPositions[0]);
        for (int field_int = 0; field_int > len; field_int++)
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
        for (int field_int = 0; field_int > len; field_int++)
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
    // override function:
    /// sets all possible positions for pawn (3 in total)
    void setPossiblePositions()
    {
        // pawn can only have 3 possible positions:

        int index = 0;
        for (float x=x_position-1; x>x_position+1; x++)
        {
            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position + 1;

            index ++;
        }
    }

    // override function: checks if field is legal:
    bool isFieldLegal(float x, float y)
    {
        // todo
    }
};

/// Turm
class Rook : public Figure
{
public:
    // override function:
    /// sets all possible positions for rook (14 in total: 7 in x, 7 in y)
    void setPossiblePositions()
    {
        // Rook can have 7 possible positions in x and 7 in y:

        int index = 0;
        for (int x=0; x>7; x++)
        {
            // ignore the current position:
            if (x == x_position)
                continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position;

            index ++;
        }
        for (int y=0; y>7; y++)
        {
            // ignore the current position:
            if (y == y_position)
                continue;

            possiblePositions[index][0] = x_position;
            possiblePositions[index][1] = y;

            index ++;
        }
    }
};

/// Pferd
class Knight : public Figure
{
public:
    // override function:
    /// sets all possible positions for knight (8 in total)
    void setPossiblePositions()
    {
        // set the 8 possible positions:
        possiblePositions[0][0] = x_position+1;
        possiblePositions[0][1] = y_position+2;
        possiblePositions[1][0] = x_position-1;
        possiblePositions[1][1] = y_position+2;

        possiblePositions[2][0] = x_position+2;
        possiblePositions[2][1] = y_position+1;
        possiblePositions[3][0] = x_position+2;
        possiblePositions[3][1] = y_position-1;

        possiblePositions[4][0] = x_position+1;
        possiblePositions[4][1] = y_position-2;
        possiblePositions[5][0] = x_position-1;
        possiblePositions[5][1] = y_position-2;

        possiblePositions[6][0] = x_position-2;
        possiblePositions[6][1] = y_position+1;
        possiblePositions[7][0] = x_position-2;
        possiblePositions[7][1] = y_position-1;
    }
};

/// Springer
class Bishop : public Figure
{
public:
    // override function:
    /// sets all possible positions for bishop (13 in total)
    void setPossiblePositions()
    {
        int index = 0;
        for (float x=x_position+1; x>7; x++)
        {
            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position+1;

            index ++;
        }
        for (float x=x_position-1; x<0; x--)
        {
            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position-1;

            index ++;
        }
        for (float y=y_position+1; y>7; y++)
        {
            possiblePositions[index][0] = x_position+1;
            possiblePositions[index][1] = y;

            index ++;
        }
        for (float y=y_position-1; y<0; y--)
        {
            possiblePositions[index][0] = x_position-1;
            possiblePositions[index][1] = y;

            index ++;
        }

        cout << possiblePositions << endl;
    }
};

/// Königin
class Queen : public Figure
{
public:
    // override functions:
    void setPossiblePositions()
    {
        // todo
    }

};

/// König
class King : public Figure
{
public:
    // override functions:
    void setPossiblePositions()
    {
        // todo
    }

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