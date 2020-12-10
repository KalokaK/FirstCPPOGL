//
// Created by greut on 12.11.2020.
//
#include <iostream>
//#include "chess_figures.h"

using namespace std;

#define VAL_1X     {-1, -1}
#define VAL_2X     VAL_1X,  VAL_1X
#define VAL_4X     VAL_2X,  VAL_2X
#define VAL_8X     VAL_4X,  VAL_4X
#define VAL_16X    VAL_8X,  VAL_8X
#define VAL_32X    VAL_16X, VAL_16X
#define VAL_64X    VAL_32X, VAL_32X

//int myArray[53] = { VAL_32X, VAL_16X, VAL_4X, VAL_1X };

int allOccupiedPositions[32][2] = { VAL_32X };
int availableIndex = 0;

class Figure {
public:
    // current position on the field:
    int x_position = -1;
    int y_position = -1;

    // all possible positions to go to (max. 27 possible positions)
    int possiblePositions[27][2] = {VAL_16X, VAL_8X, VAL_2X, VAL_1X};
    // all legal positions
    int legalPositions[27][2] = {VAL_16X, VAL_8X, VAL_2X, VAL_1X};

    void setPosition(int x, int y)
    {
        // set a new position:
        bool done = false;
        for (int i=0; i < 32; i ++)
        {
            // get the position, where it is saved:
            if (allOccupiedPositions[i][0] == x_position &&
                allOccupiedPositions[i][1] == y_position)
            {
                // set new position:
                //cout << "set pos " << x << " " << y << "  " << i << endl;
                allOccupiedPositions[i][0] = x;
                allOccupiedPositions[i][1] = y;
                done = true;
                break;
            }
        }
        if (!done)
        {
            // if position isn't saved in array:
            //cout << "set pos " << x << " " << y << "  " << availableIndex  << endl;
            allOccupiedPositions[availableIndex][0] = x;
            allOccupiedPositions[availableIndex][1] = y;
            availableIndex += 1;
        }
        x_position = x; y_position = y;
    }

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
        cout << "Possible Positions: " << endl;

        // length of array
        int len = sizeof(possiblePositions)/sizeof(possiblePositions[0]);
        int index = 0;
        for (int field_int = 0; field_int < len; field_int++)
        {
            // todo
            // check if field at field_int would be a legal move
            // remove all other not possible/illegal positions
            // put all legal fields in legalPositions


            cout << "x=" << possiblePositions[field_int][0] << " y=" << possiblePositions[field_int][1] << endl;

            //determines if field is legal:
            if (isFieldLegal(possiblePositions[field_int][0],
                             possiblePositions[field_int][1]) &&
                 checkIfFieldIsOccupied(possiblePositions[field_int][0],
                                        possiblePositions[field_int][1]))
            {
                // add the legal position to the legalPositions array:
                legalPositions[index][0] = possiblePositions[field_int][0];
                legalPositions[index][1] = possiblePositions[field_int][1];

                index ++;
            }
        }
    }

    /// returns true, if field is legal. This function is specific to type of figure.
    virtual bool isFieldLegal(int x, int y)
    {
        // todo find out what i thought for this function... until then it returns true, lol, totally unnecessary.
        // bsp: pawn: oben rechts&links sind legal, wenn occupied, sonst nicht. das machen
        // on default true:
        return true;
    }

    /// returns ture, if the field is not occupied.
    bool checkIfFieldIsOccupied(int x, int y)
    {
        // check if field is in occupiedPositions array:
        for (int i=0; i<32; i++)
        {
            if (allOccupiedPositions[i][0] == x &&
                allOccupiedPositions[i][1] == y)
            {
                // field is occupied:
                return false;
            }
        }

        // when the field isnt occupied, return true:
        return true;
    }

    /// highlight legit position.
    void highlightPossiblePositions()
    {
        cout << "Highlight: " << endl;
        // highlight every field in legalPositions:
        int len = sizeof(legalPositions)/sizeof(legalPositions[0]);
        for (int field_int = 0; field_int < len; field_int++)
        {
            // highlight the following field
            cout << "x=" << legalPositions[field_int][0] <<
                   " y=" << legalPositions[field_int][1] << endl;

            // todo highlight the field
        }
    }

    /// sets new position to figure, when made a new move. xNew/xNew are the coordinates of the new position.
     void moveToNewPosition(int xNew, int yNew)
    {
        // set new positions, where xNew, yNew are the x-,y-coordinates of the new field,
        // who are the new input values of the mouse, clicked on the legal field.

        // length of array
        int len = sizeof(legalPositions)/sizeof(legalPositions[0]);
        // check if the chosen field is in the legalPosition array:
        for (int field_int = 0; field_int < len; field_int++)
        {
            if (legalPositions[field_int][0] == xNew &&
                legalPositions[field_int][1] == yNew)
            {
                // if it is in the array: set the new position to the chosen position:
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
    void setPossiblePositions() override
    {
        // pawn can only have 3 possible positions:

        int index = 0;
        for (int x=x_position-1; x<x_position+1; x++)
        {
            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position + 1;

            index ++;
        }
    }

    // override function: checks if field is legal:
    bool isFieldLegal(int x, int y) override
    {
        // todo
        return false;
    }
};

/// Rook
class Rook : public Figure
{
public:
    // override function:
    /// sets all possible positions for rook (14 in total: 7 in x, 7 in y)
    void setPossiblePositions() override
    {
        // Rook can have 7 possible positions in x and 7 in y:

        int index = 0;
        for (int x=0; x<7; x++)
        {
            // ignore the current position:
            if (x == x_position)
                continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position;

            index ++;
        }
        for (int y=0; y<7; y++)
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

/// Knight
class Knight : public Figure
{
public:
    // override function:
    /// sets all possible positions for knight (8 in total)
    void setPossiblePositions() override
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

        for (int i=0; i<8; i++)
        {
            if (possiblePositions[i][0] < 0 || possiblePositions[i][1] < 0)
            {
                possiblePositions[i][0] = -1;
                possiblePositions[i][1] = -1;
            }
        }
    }
};

/// Springer
class Bishop : public Figure
{
public:
    // override function:
    /// sets all possible positions for bishop (13 in total)
    void setPossiblePositions() override
    {
        int index = 0;
        for (int x=x_position+1; x<=7; x++)
        {
            if (y_position+(x-x_position) < 0) continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position+(x-x_position);

            index ++;
        }
        for (int x=x_position-1; x>=0; x--)
        {
            if (y_position+(x-x_position) < 0) continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position+(x-x_position);

            index ++;
        }
        for (int y=y_position+1; y<=7; y+=1)
        {
            if (y_position-(y-y_position) < 0) continue;

            possiblePositions[index][0] = x_position-(y-y_position);
            possiblePositions[index][1] = y;

            index ++;
        }
        for (int y=y_position-1; y>=0; y--)
        {
            if (y_position-(y-y_position) < 0) continue;

            possiblePositions[index][0] = x_position-(y-y_position);
            possiblePositions[index][1] = y;

            index ++;
        }
    }
};

/// Queen
class Queen : public Figure
{
public:
    // override functions:
    /// 27 possible positions
    void setPossiblePositions() override
    {
        // combine possible positions of bishop and rook:
        //bishop:
        int index = 0;
        for (int x=x_position+1; x<=7; x++)
        {
            if (y_position+(x-x_position) < 0) continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position+(x-x_position);

            index ++;
        }
        for (int x=x_position-1; x>=0; x--)
        {
            if (y_position+(x-x_position) < 0) continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position+(x-x_position);

            index ++;
        }
        for (int y=y_position+1; y<=7; y+=1)
        {
            if (y_position-(y-y_position) < 0) continue;

            possiblePositions[index][0] = x_position-(y-y_position);
            possiblePositions[index][1] = y;

            index ++;
        }
        for (int y=y_position-1; y>=0; y--)
        {
            if (y_position-(y-y_position) < 0) continue;

            possiblePositions[index][0] = x_position-(y-y_position);
            possiblePositions[index][1] = y;

            index ++;
        }
        //rook:
        for (int x=0; x<=7; x++)
        {
            // ignore the current position:
            if (x == x_position)
                continue;

            possiblePositions[index][0] = x;
            possiblePositions[index][1] = y_position;

            index ++;
        }
        for (int y=0; y<=7; y++)
        {
            // ignore the current position:
            if (y == y_position)
                continue;

            possiblePositions[index][0] = x_position;
            possiblePositions[index][1] = y;

            index ++;
        }

        cout << "position = " << x_position << ", " << y_position << endl;
        for (int i=0;i<=27;i++)
            cout << "x= " << possiblePositions[i][0] << "  y= " << possiblePositions[i][1] << endl;

    }

};

/// King
class King : public Figure
{
public:
    // override functions:
    void setPossiblePositions() override
    {
        // todo
    }

};

int main()
{
    /*
    for (int i=0; i < 32; i ++)
    {
        cout << allOccupiedPositions[i][0] << "  " << allOccupiedPositions[i][1] << endl;
    }
     */
    // ----------------------------- WHITE -----------------------------
    // Pawns:
    auto *w_pawn_01 = new Pawn();
    w_pawn_01->setPosition(0, 1);
    auto *w_pawn_02 = new Pawn();
    w_pawn_02->setPosition(1, 1);
    auto *w_pawn_03 = new Pawn();
    w_pawn_03->setPosition(2, 1);
    auto *w_pawn_04 = new Pawn();
    w_pawn_04->setPosition(3, 1);
    auto *w_pawn_05 = new Pawn();
    w_pawn_05->setPosition(4, 1);
    auto *w_pawn_06 = new Pawn();
    w_pawn_06->setPosition(5, 1);
    auto *w_pawn_07 = new Pawn();
    w_pawn_07->setPosition(6, 1);
    auto *w_pawn_08 = new Pawn();
    w_pawn_08->setPosition(7, 1);

    // Rooks:
    auto *w_rook_01 = new Rook();
    w_rook_01->setPosition(0, 0);
    auto *w_rook_02 = new Rook();
    w_rook_02->setPosition(7, 0);

    // Knights:
    auto *w_knight_01 = new Knight();
    w_knight_01->setPosition(1, 0);
    auto *w_knight_02 = new Knight();
    w_knight_02->setPosition(6, 0);

    // Bishops:
    auto *w_bishop_01 = new Bishop();
    w_bishop_01->setPosition(2, 0);
    auto *w_bishop_02 = new Bishop();
    w_bishop_02->setPosition(5, 0);
    w_bishop_02->setPossiblePositions();

    // Queen:
    auto *w_queen = new Queen();
    w_queen->setPosition(3, 0);
    w_queen->setPossiblePositions();
    // King:
    auto *w_king = new King();
    w_king->setPosition(4, 0);

    cout << "Occupied Positions: " << endl;
    for (int i=0; i < 32; i ++)
    {
        cout << allOccupiedPositions[i][0] << "  " << allOccupiedPositions[i][1] << endl;
    }


    w_queen->selectFigure();

    cin.get();

    return 0;
}