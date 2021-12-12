#include "Bomb.h"

Bomb::Bomb(const Point& point, int _direction )
{
    body = point;
    direction = _direction;
}

void Bomb::move(char direction)
{

    body.draw(space);
    body.move(direction);
    setTextColor(color);
    draw();

}

char* Bomb::FindBestSpot(Board& playerBoard,int level, int playerNumber)
{
    int max_depth = 0, best_col = 1, x = 0, y = 0, Best_Rotate = 0;
    int mid = (LeftBoardPlayer1 + rightBoardPlayer1) / 2 ,abs1,abs2;
    
    if (level == hard)
    {
        Point StartPoint(1 + playerNumber * LeftBoardPlayer2, 1);
        Bomb* temp = new Bomb(StartPoint);

        for (int i = 1; i < rightBoardPlayer1; i++)
        {
            temp->CreateDropBomb(playerBoard);
            UpdateBestCurPosition(*temp, &x, &y);


            if (max_depth == 0 || max_depth > y)
            {
                max_depth = y;
                best_col = x;
            }
            else if (max_depth == y) //check aprox to mid
            {
                (best_col - mid) < 0 ? abs1 = (best_col - mid) * (-1) : abs1 = (best_col - mid);
                (x - mid) < 0 ? abs2 = (x - mid) * (-1) : abs2 = (x - mid);
                if (abs2 < abs1)
                {
                    max_depth = y;
                    best_col = x;
                }
            }

            temp->body.setX(i + playerNumber * LeftBoardPlayer2 + 1);
            temp->body.setY(1);
        }

        delete temp;
        return  FindPath(max_depth, best_col, playerBoard, playerNumber);
    }
    else
    {
        int i;
        char* commandString = new char[Bottom + Rotate3];
        for ( i = 0; i < CommandLoop -1; i++)
            commandString[i] = MoveDown;

        commandString[i] = '\0';
        return commandString;
    }
}

void Bomb::UpdateBestCurPosition(Objects& obj, int* x, int* y)
{
    
    *x = obj.getPointByIdx(0).getx();
    if(*x > rightBoardPlayer1 + 5)
        *x = *x -LeftBoardPlayer2;
    
    *y = obj.getPointByIdx(0).gety();
}

void Bomb::CreateDropBomb(Board& playerBoard)
{
    bool flag = true;
    int x, y;
    while (flag) {
        x = body.getx();
        if(x > rightBoardPlayer1 +5)
            x= x-LeftBoardPlayer2;
        y = body.gety() + 1;

        if (playerBoard.getCharAtBoard(y, x) != space)
            flag = false;

        if (flag)
        {
            body.move();          
        }
    }
}

char* Bomb::FindPath(int row, int col, Board& playerBoard, int playerNumber)
{
    char* commands = new char[Bottom + Rotate3];
    int x = body.getx() - playerNumber * LeftBoardPlayer2;
    int y = body.gety();
    int i = 0;
    int counterRight = 0, counterLeft = 0, Counter;
    
    Counter = col - x;
    if (Counter < 0)
        counterLeft = Counter * (-1);
    else if (Counter > 0)
        counterRight = Counter;

    while (counterLeft)
    {
        if(playerNumber == Computer_Player2)
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
