#pragma once
#include "Board.h"
#include"Objects.h"

class Shape  : public Objects
{
protected:

    enum { SIZE = 4 };
    Point body[SIZE];
    
     
public:
    Shape();
    Shape(const Shape& other);
   
    ~Shape();
     
   //const int getSerialNumber() const{ return serialNumber; } //Returns the shape's serial number
  virtual const Point& getPointByIdx(int idx) const override{ return body[idx]; } //Returns the wanted point in the body of the shape
  //const Color getColor() const{ return color; } //Returns shapes color

    void initShape();
    virtual void draw() const override ; // Printing the shape to the screen

    virtual void move(char direction = Drop1) override; //Moving the shape by direction (?)

    virtual bool CheckRotate(int playerNumber, Board& boardGameForPlayer)const = 0;
    virtual bool CheckCounterRotate(int playerNumber, Board& boardGameForPlayer)const = 0;
    
    virtual char* FindBestSpot(Board& playerBoard, int level, int playerNumber = Computer_Player2) = 0;
    
    bool CheckLleftRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of L left is possible according to the current board
    bool CheckLRightRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of L right is possible according to the current board
    bool CheckPlusRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const;//Returns true if a counter clockwise rotation of Plus is possible according to the current board

    virtual void RotateClockWise () = 0  ; //Rotates the shape clock wise
    virtual void RotateCounterWise() = 0; //Rotates the shape counter clock wise
    
    virtual void UpdateBestCurPosition(Objects& obj, int* x, int* y) = 0;
    bool CheckRow(Board& playerBoard, int row, int* holes);
    void CreateDropShape(Board& playerBoard);

    char* FindDropShapeMiddle();

    const Shape& operator=(const Shape& other);
    
    int CheckHoles(Board& playerBoard);

    virtual Shape* Clone()const = 0 {};
};

