#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
    Square(Point StartPoint, int direction = Rotate0);
    void UpdateSquareShape(Point& StartPoint, int direction = Rotate0);



    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
	   return new Square(*this);
    }
    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override { return true; };
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override { return true; };
    virtual char* FindBestSpot(Board& playerBoard, int level, int playerNumber = Computer_Player2);
    char* FindPath(int row, int col, Board& playerBoard, int playerNumber = Computer_Player2);
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y);
};

