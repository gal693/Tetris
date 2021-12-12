#include "Square.h"

Square::Square(Point StartPoint, int direction)  {

    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
    serialNumber = _Square; // update the serial number of the shape
}

void Square::UpdateSquareShape(Point& StartPoint, int direction)
{
    body[0] = StartPoint;
    body[1] = Point(StartPoint.getx() + 1, StartPoint.gety(), StartPoint.getCh());
    body[2] = Point(StartPoint.getx(), StartPoint.gety() + 1, StartPoint.getCh());
    body[3] = Point(StartPoint.getx() + 1, StartPoint.gety() + 1, StartPoint.getCh());
}

void Square::RotateClockWise()
{
}

void Square::RotateCounterWise()
{
}

char* Square::FindBestSpot(Board& playerBoard, int level, int playerNumber)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, curr_holes=0, min_holes = -1;
    Point StartPoint(1 + playerNumber *LeftBoardPlayer2, 1);
    Square* temp = new Square(StartPoint);
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
    for (int j = 1; j < rightBoardPlayer1 - 1; j++)
    {

        temp->CreateDropShape(playerBoard);
        UpdateBestCurPosition(*temp, &x, &y);
        if (temp->CheckRow(playerBoard, y, &curr_holes))
            return  FindPath(y, x, playerBoard, playerNumber);

        if (min_holes == -1)
            min_holes = curr_holes;
        if (curr_holes < min_holes)
        {
            min_holes = curr_holes;
            max_depth = y;
            best_col = x;
        }
        else if (curr_holes == min_holes)
        {
            if (max_depth < y)
            {
                min_holes = curr_holes;
                max_depth = y;
                best_col = x;
            }
        }

        StartPoint.setX(StartPoint.getx() + 1);
        temp->UpdateSquareShape(StartPoint);
    }
    delete temp;
    return  FindPath(max_depth, best_col, playerBoard, playerNumber);
}

char* Square::FindPath(int row, int col, Board& playerBoard,int playerNumber)
{
    char* commands = new char[Bottom + Rotate3];
    int x = body[2].getx() - playerNumber *LeftBoardPlayer2;
    int y = body[2].gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter;
    Counter = col - x;
    if (Counter < 0)
        counterLeft = Counter * (-1);
    else if (Counter > 0)
        counterRight = Counter;
 
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
            commands[i] = Right2;
        counterRight--;
        i++;
    }


    commands[i] = '\0';
    return commands;
}

void Square::UpdateBestCurPosition(Objects& obj, int* x, int* y)
{
    *x = obj.getPointByIdx(2).getx();
    if (*x > rightBoardPlayer1 + 5)
        *x = *x - LeftBoardPlayer2;
    *y = obj.getPointByIdx(2).gety();
   
}

//