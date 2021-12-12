
#pragma once

#include"Objects.h"
#include "Point.h"
class Bomb : public Objects
{
private:
    
    Point body ;

public:
    //Bomb() { body = Point(); }
    Bomb(const Point& point, int _direction = Rotate0);

    virtual Bomb* Clone()const override
    {
        return new Bomb(*this);
    }
    const Point& getBody()const { return body; }

    virtual void move(char direction = Drop1)override;

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer) const { return true; };
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const { return true; };

    virtual void draw() const override {
        setTextColor(color);
        body.draw();
    }
    virtual const Point& getPointByIdx(int idx) const override { return body; };
    virtual char* FindBestSpot(Board& playerBoard, int level,int playerNumber = Computer_Player2);
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y);

    void CreateDropBomb(Board& playerBoard);
    char* FindPath(int row, int col, Board& playerBoard, int playerNumber = Computer_Player2);
};

