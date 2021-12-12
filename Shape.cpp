#include "Shape.h"

Shape::Shape()
{
}

Shape::Shape(const Shape& other)
{
    for (int i = 0; i < SIZE; i++)
        body[i] = other.body[i];

    direction = other.direction;
    serialNumber = other.serialNumber;
    color = other.color;
}

Shape::~Shape()
{

}

void Shape::initShape()
{

    for (int i = 0; i < SIZE; i++)
    {
        body[i] = Point(0, 0, space);
    }
}

void Shape::draw() const
{
    setTextColor(color);

    for (int i = 0; i < SIZE; i++)
    {
        body[i].draw();
    }
}

void Shape::move(char direction)
{
    for (int i = 0; i < BodyPointSize; i++)
    {
        body[i].draw(space);
    }
    if (RotateClockWise1 == direction || RotateClockWise1B == direction || RotateClockWise2 == direction || RotateClockWise2B == direction)
    {
        RotateClockWise();
    }
    else if (RotateCounterClockWise1 == direction || RotateCounterClockWise1B == direction || RotateCounterClockWise2 == direction || RotateCounterClockWise2B == direction)
    {
        RotateCounterWise();
    }
    else {
        for (int i = 0; i < BodyPointSize; i++)
        {
            body[i].move(direction);
        }
    }
    setTextColor(color);
    draw();
}

bool Shape::CheckLleftRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {

        for (int i = 0; i < 3; i++)
        {
            
                if (playerNumber == Player1) //check if the shape is on the left frame
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1;
                }
                else
                {
                    y = getPointByIdx(i).gety();
                    x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
                }

                if (boardGameForPlayer.getCharAtBoard(y, x) != space)
                    return false;
            
        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() - 1;
        }
        else
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(0).gety() -1;
            x = getPointByIdx(0).getx();
        }
        else
        {
            y = getPointByIdx(0).gety() - 1;
            x = getPointByIdx(0).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() + 1;
        }
        else
        {
            y = getPointByIdx(3).gety() ;
            x = getPointByIdx(3).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(0).gety() + 1;
            x = getPointByIdx(0).getx() ;
        }
        else
        {
            y = getPointByIdx(0).gety() + 1;
            x = getPointByIdx(0).getx()  - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;

    }
    }
    return true;
}

bool Shape::CheckLRightRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 1;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety() -2;
            x = getPointByIdx(2).getx();
        }
        else
        {
            y = getPointByIdx(2).gety() - 2;
            x = getPointByIdx(2).getx() - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety()  + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() + 2;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() + 2;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 2;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() - 2 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;

    }
    }

    return true;
}

bool Shape::CheckPlusRotateCounterClockWise(int playerNumber, Board& boardGameForPlayer)const
{

    int x, y;
    switch (direction)
    {
    case Rotate0: //from 0 -> 3
    {
       if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() + 1 ;
            x = getPointByIdx(1).getx() ;
        }
        else
        {
            y = getPointByIdx(1).gety() + 1;
            x = getPointByIdx(1).getx()  - LeftBoardPlayer2;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate1: //from 1 -> 0
    {

        for (int i = 0; i < 3; i++)
        {

            if (playerNumber == Player1) //check if the shape is on the left frame
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1;
            }
            else
            {
                y = getPointByIdx(i).gety();
                x = getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;;
            }

            if (boardGameForPlayer.getCharAtBoard(y, x) != space)
                return false;

        }
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1;
        }
        else
        {
            y = getPointByIdx(1).gety();
            x = getPointByIdx(1).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        break;
    }
    case Rotate2: // from 2 -> 1
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx();
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
       
        break;

    }
    case Rotate3: // from 3 -> 2
    {
        if (playerNumber == Player1) //check if the shape is on the left frame
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() ;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        
        break;

    }
    }

    return true;

}

void Shape::RotateClockWise()
{
    
}

void Shape::RotateCounterWise()
{
   
}

bool Shape::CheckRow(Board& playerBoard, int row, int* holes)
{
    int x,y;
    for (int i = 0; i < BodyPointSize; i++)
    {
        y = body[i].gety();
        x = body[i].getx();
        if (y == 1)
            return false;
        if (x > rightBoardPlayer1)
            x = x-LeftBoardPlayer2;
        if (x <= LeftBoardPlayer1 || x >= rightBoardPlayer1)
            return false;
    }

    for (int i=0 ; i < BodyPointSize ; i++)
        playerBoard.setPointAtBoard(this->getPointByIdx(i), this->getColor());

    *holes = CheckHoles(playerBoard);

    for (int i = 1; i < rightBoardPlayer1; i++)
    {
        if (playerBoard.getCharAtBoard(row, i) == space)
        {
            for (int j = 0; j < 4; j++)
                    playerBoard.setPointAtBoard(Point(this->getPointByIdx(j).getx(), this->getPointByIdx(j).gety(), space), LIGHTGREY);
            return false;
        }
    }

    for (int i = 0; i < BodyPointSize; i++)
            playerBoard.setPointAtBoard(Point(this->getPointByIdx(i).getx(), this->getPointByIdx(i).gety(), space), LIGHTGREY);
    return true;
}

void Shape::CreateDropShape(Board& playerBoard)
{
    int x, y;
    bool flag = true;
    while (flag) {
        for (int i = 0; i < BodyPointSize; i++) {

            x = body[i].getx();
            if(x> rightBoardPlayer1 + 5)
               x = x -LeftBoardPlayer2;
            y = body[i].gety() + 1;
            if (x <= LeftBoardPlayer1 || x >= rightBoardPlayer1)
            {
                flag = false;
            }
            if (playerBoard.getCharAtBoard(y, x) != space)
                flag = false;
        }
        if (flag)
        {
            for (int i = 0; i < SIZE; i++)
            {
                body[i].move();
            }
        }

    }
}

char* Shape::FindDropShapeMiddle()
{
    char* commands = new char[CommandLoop];
    for (int i = 0; i < CommandLoop-1; i++)
        commands[i] = MoveDown;
    commands[CommandLoop-1] = '\0';
    return commands;
}

const Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        for (int i = 0; i < BodyPointSize; i++)
            body[i] = other.body[i];
        direction = other.direction;
        serialNumber = other.serialNumber;
        color = other.color;
    }

    return *this;
}

int Shape::CheckHoles(Board& playerBoard)
{
    int x = 0, y = 0, res = 0, i , j ,inc=1;
   

    for (i = 1; i < rightBoardPlayer1; i++)
    {
        for (j = 1; j < Bottom; j++)
        {
            if (playerBoard.getCharAtBoard(j, i) == '@')
            {
                while (playerBoard.getCharAtBoard(j + inc, i) == space)
                {
                    res++;
                    inc++;
                }
                inc = 1;
            }
        }
    }
    return res;
}




