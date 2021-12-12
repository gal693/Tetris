#include "ZleftShape.h"


ZleftShape::ZleftShape(Point StartPoint, int direction)
{
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _ZleftShape; // update the serial number of the shape     
    this->direction = direction;
}

void ZleftShape :: UpdateZleftShape(Point& StartPoint, int direction, int CheckRotate)
{
    switch (direction)
    {
    case Rotate0:
    {
        if (body[0].getx() != 0 && CheckRotate == RegularRoatate)//if it is not the start row
            StartPoint = Point(StartPoint.getx() - 2, StartPoint.gety() + 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
        body[2] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() + 2, StartPoint.gety() + 1, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape     
        this->direction = direction;
        break;
    }
    case Rotate1:
    {
        if (CheckRotate == RegularRoatate)
            StartPoint = Point(StartPoint.getx() + 2, StartPoint.gety() - 1, StartPoint.getCh());
        body[0] = StartPoint;
        body[1] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
        body[2] = Point(StartPoint.getx() - 1, StartPoint.gety() + 1, StartPoint.getCh());
        body[3] = Point(StartPoint.getx() - 1, StartPoint.gety() + 2, StartPoint.getCh());
        serialNumber = _ZleftShape; // update the serial number of the shape
        this->direction = direction;

        break;
    }
    }

}

void ZleftShape::RotateClockWise()
{
    if (direction == 1) 
        direction = 0;
    else
        direction++;

    this-> UpdateZleftShape(body[0], direction);
}

void ZleftShape::RotateCounterWise()
{
    if (direction == 0) 
        direction = 1;
    else
        direction--;
    this -> UpdateZleftShape(body[0], direction);
}

bool ZleftShape::CheckRotate(int playerNumber, Board& boardGameForPlayer)const
{
    int x, y;
    switch (direction)
    {
    case Rotate0:
    {
        if (playerNumber == Player1)
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1;
        }
        else
        {
            y = getPointByIdx(1).gety() - 1;
            x = getPointByIdx(1).getx() + 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1)
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
    case Rotate1:
    {

        if (playerNumber == Player1)
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() - 1;
        }
        else
        {
            y = getPointByIdx(2).gety();
            x = getPointByIdx(2).getx() - 1 - LeftBoardPlayer2;;
        }

        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;
        if (playerNumber == Player1)
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1;
        }
        else
        {
            y = getPointByIdx(3).gety();
            x = getPointByIdx(3).getx() + 1 - LeftBoardPlayer2;;
        }
        if (boardGameForPlayer.getCharAtBoard(y, x) != space)
            return false;


        break;
    }
    }
    return true;
}

bool ZleftShape::CheckCounterRotate(int playerNumber, Board& boardGameForPlayer) const
{
    return CheckRotate(playerNumber, boardGameForPlayer);
}

char* ZleftShape::FindBestSpot(Board& playerBoard, int level, int playerNumber)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0, curr_holes = 0, min_holes = -1;
    Point StartPoint(1 + playerNumber*LeftBoardPlayer2, 1);
    ZleftShape* temp = new ZleftShape(StartPoint);
    int rand_easy = rand() % easy_missing_percentage;
    int rand_medium = rand() % medium_missing_percentage;
    if (rand_easy == easy && level == easy)
    {
        return FindDropShapeMiddle();
    }
    if (rand_medium == medium && level == medium)
    {
        return FindDropShapeMiddle();
    }
    for (int i = 0; i <= Rotate1; i++) {
        temp->UpdateZleftShape(StartPoint, i, _CheckRotate);

        for (int j = 1; j < rightBoardPlayer1; j++)
        {
            temp->CreateDropShape(playerBoard);
            UpdateBestCurPosition(*temp, &x, &y);
            if (temp->CheckRow(playerBoard, y, &curr_holes))
                return  FindPath(y, x, playerBoard, i, playerNumber);


            if (min_holes == -1)
                min_holes = curr_holes;
            if (curr_holes < min_holes)
            {
                min_holes = curr_holes;
                max_depth = y;
                best_col = x;
                Best_Rotate = i;
            }
            else if (curr_holes == min_holes)
            {
                if (max_depth < y)
                {
                    min_holes = curr_holes;
                    max_depth = y;
                    best_col = x;
                    Best_Rotate = i;
                }
            }

            StartPoint.setX(StartPoint.getx() + 1);
            temp->UpdateZleftShape(StartPoint, i, _CheckRotate);
        }

        StartPoint.setX(LeftBoardPlayer2* playerNumber + 1);
        StartPoint.setY(1);



    }
    delete temp;
    return  FindPath(max_depth, best_col, playerBoard, Best_Rotate, playerNumber);
}

void ZleftShape::UpdateBestCurPosition(Objects& obj, int* x, int* y)
{
    switch (obj.getDirection())
    {
    case Rotate0:
    {
        *x = obj.getPointByIdx(2).getx();
        if (*x > rightBoardPlayer1 + 5)
            *x = *x - LeftBoardPlayer2;
        *y = obj.getPointByIdx(2).gety();
        break;
    }
    case Rotate1:
    {  
        *x = obj.getPointByIdx(3).getx();
        if (*x > rightBoardPlayer1 + 5)
            *x = *x - LeftBoardPlayer2;
         *y = obj.getPointByIdx(3).gety();
    break;
    }
    }
}

char* ZleftShape::FindPath(int row, int col, Board& playerBoard, int rotate,int playerNumber )
{
    char* commands = new char[Bottom + Rotate3];
    int x = body[2].getx() - playerNumber * LeftBoardPlayer2;
    int y = body[2].gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter, CounterRotate = rotate;

    Counter = col - x;
    if (Counter < 0)
        counterLeft = Counter * (-1);
    else if (Counter > 0)
        counterRight = Counter;

    if (rotate != 0 && !this->CheckRotate(playerNumber, playerBoard))
    {
        CounterRotate++;
    }
    while (CounterRotate)
    {
        if (playerNumber == Computer_Player2)
            commands[i] = RotateClockWise2;
        else
            commands[i] = RotateClockWise1;
       
        CounterRotate--;
        i++;
    }
    while (counterLeft)
    {
        if (playerNumber == Computer_Player2)
            commands[i] = Left2;
        else
            commands[i] = Left1;
        
        counterLeft--;
        i++;
    }
    while (counterRight)
    {
        if (playerNumber == Computer_Player2)
            commands[i] = Right2;
        else
            commands[i] = Right1;
        counterRight--;
        i++;
    }


    commands[i] = '\0';
    return commands;
}



