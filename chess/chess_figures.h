//
// Created by greut on 03.12.2020.
//
/*
#ifndef CHESS_CHESS_FIGURES_H
#define CHESS_CHESS_FIGURES_H
class Figure {
    virtual void setPossiblePositions() = 0;
    virtual void getLegalFields();
    virtual bool isFieldLegal(int x, int y);
    void highlightPossiblePositions();
    void moveToNewPosition(int xNew, int yNew);
    virtual void selectFigure();

};
class Pawn : public Figure
{
    void setPossiblePositions() override;
    bool isFieldLegal(int x, int y) override;
};
class Rook : public Figure
{
    void setPossiblePositions() override;
    void selectFigure() override;
};
class Knight : public Figure
{
    void setPossiblePositions() override;
};
class Bishop : public Figure
{
    void setPossiblePositions() override;
};
class Queen : public Figure
{
    void setPossiblePositions() override;
};
class King : public Figure
{
    void setPossiblePositions() override;
};

#endif //CHESS_CHESS_FIGURES_H
*/