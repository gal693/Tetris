#pragma once

#include "Board.h"

class Objects
{
protected:
    int serialNumber;
    Color color = LIGHTGREY; 
    int direction = Down;

public:
    
    Objects() { };
    Objects(const Objects& other);

    const int getSerialNumber() const { return serialNumber; } //Returns the shape's serial number
    const Color getColor() const { return color; } //Returns shapes color
    virtual const Point& getPointByIdx(int idx) const = 0; //Returns the wanted point in the body of the shape
    const int getDirection()const { return direction; }
    virtual Objects* Clone()const = 0 {};

    void setColor(Color c) { color = c; }
    virtual void setSerialNumber(int serialNum) { serialNumber = serialNum; } //Sets the shape's serial number
 
    virtual void move(char direction = Drop1) = 0; //Moving the shape by direction 
    virtual void draw() const = 0 ;

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer) const = 0;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const = 0;
    virtual char* FindBestSpot(Board& playerBoard,int level, int playerNumber = Computer_Player2) = 0;//finds the best ideal spot to place the current shape

    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y) = 0;


};

