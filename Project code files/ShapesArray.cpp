#include "ShapesArray.h"
#include "Square.h"
#include"LleftShape.h"
#include "LrightShape.h"
#include "RowShape.h"
#include "ZleftShape.h"
#include"ZrightShape.h"
#include"PlusShape.h"


ShapesArray::ShapesArray(int _player) : player(_player)
{
    AllShapesArray = new Objects *[NumOfShapes];
    if (player == Player1 || player == Computer_Player1) {
        Point point(LeftBoardPlayer1 + rightBoardPlayer1 / 2, TopBoard + 1);
        AllShapesArray[0] = new Square(point);
        AllShapesArray[1] = new LleftShape(point);
        AllShapesArray[2] = new LrightShape(point);
        AllShapesArray[3] = new RowShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[4] = new ZleftShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[5] = new ZrightShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[6] = new PlusShape(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1));
        AllShapesArray[7] = new Bomb(Point((LeftBoardPlayer1 + rightBoardPlayer1) / 2, TopBoard + 1,'O'));

    }
    if (player == Player2 || player == Computer_Player2)
    {

        AllShapesArray[0] = new Square(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[1] = new LleftShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[2] = new LrightShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[3] = new RowShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[4] = new ZleftShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[5] = new ZrightShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[6] = new PlusShape(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1));
        AllShapesArray[7] = new Bomb(Point((LeftBoardPlayer2 + rightBoardPlayer2) / 2, TopBoard + 1,'O'));

    }
}

ShapesArray::ShapesArray(const ShapesArray& other)
{
    *this = other;
}

const ShapesArray& ShapesArray::operator= (const ShapesArray& other)
{
    if (this != &other)
    {
        this->player = other.player;
        Objects** temp = new Objects * [NumOfShapes];
        for (int i = 0; i < NumOfShapes; i++)
        {
            temp[i] = other.AllShapesArray[i];
        }
        this->AllShapesArray = temp;
    }
    return *this;
}

ShapesArray::~ShapesArray()
{
    for (int i = 0; i < NumOfShapes; i++)
        delete AllShapesArray[i];
    delete[] AllShapesArray;
}

void ShapesArray::InitColorsShapesArray()
{
    AllShapesArray[0]->setColor(YELLOW);
    AllShapesArray[1]->setColor(BROWN);
    AllShapesArray[2]->setColor(BLUE);
    AllShapesArray[3]->setColor(LIGHTBLUE);
    AllShapesArray[4]->setColor(CYAN);
    AllShapesArray[5]->setColor(GREEN);
    AllShapesArray[6]->setColor(MAGENTA);
    AllShapesArray[7]->setColor(RED);

}
