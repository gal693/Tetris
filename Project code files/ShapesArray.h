#pragma once
#include"Shape.h"
#include "Bomb.h"


class ShapesArray
{
private:
    enum { NumOfShapes = 8 };
 
    int player;
    Objects** AllShapesArray;

public:
    //Creates all shapes
    ShapesArray(int _player=1);
    ShapesArray(const ShapesArray& other);
    ~ShapesArray();

    Objects* getShape(int idx) const { return AllShapesArray[idx]; } //Returns shape by index  //TODO : CHECK
    void InitColorsShapesArray(); //Sets color to each shape
    const ShapesArray& operator= (const ShapesArray& other);
};

