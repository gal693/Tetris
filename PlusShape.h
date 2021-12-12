#pragma once
#include "Shape.h"
class PlusShape : public Shape
{
public:
    PlusShape(Point StartPoint, int direction = Rotate0);
    
    void UpdatePlusShape(Point& StartPoint, int direction = Rotate0, int CheckRotate = RegularRoatate);

    virtual void RotateClockWise() override;
    virtual void RotateCounterWise() override;

    virtual Shape* Clone()const override
    {
        return new PlusShape(*this);
    }
    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const override;
    virtual char* FindBestSpot(Board& playerBoard, int level,int playerNumber = Computer_Player2);
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y);
    char* FindPath(int row, int col, Board& playerBoard, int rotate,int playerNumber = Computer_Player2);
};

