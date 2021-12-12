#include "Player.h"

Player::Player(int player) : boardGameForPlayer(), shapesarray(player), playerNumber(player)
{
    if (playerNumber == Player1 || playerNumber == Computer_Player1)
    {
        KeyboardKeys[0] = Drop1;
        KeyboardKeys[1] = Drop1B;
        KeyboardKeys[2] = Right1;
        KeyboardKeys[3] = Right1B;
        KeyboardKeys[4] = Left1;
        KeyboardKeys[5] = Left1B;
        KeyboardKeys[6] = RotateClockWise1;
        KeyboardKeys[7] = RotateClockWise1B;
        KeyboardKeys[8] = RotateCounterClockWise1;
        KeyboardKeys[9] = RotateCounterClockWise1B;
    }
    if (playerNumber == Player2 || playerNumber == Computer_Player2)
    {
        KeyboardKeys[0] = Drop2;
        KeyboardKeys[1] = Drop2B;
        KeyboardKeys[2] = Right2;
        KeyboardKeys[3] = Right2B;
        KeyboardKeys[4] = Left2;
        KeyboardKeys[5] = Left2B;
        KeyboardKeys[6] = RotateClockWise2;
        KeyboardKeys[7] = RotateClockWise2B;
        KeyboardKeys[8] = RotateCounterClockWise2;
        KeyboardKeys[9] = RotateCounterClockWise2B;
    }
}
 
Player::~Player()
{
}

Player::Player(const Player& other)
{
    *this = other;
}

const Player& Player::operator=(const Player& other) 
{
    if (this != &other)
    {
        *this = Player(other.playerNumber);
        this->boardGameForPlayer = other.boardGameForPlayer;
        this->shapesarray = other.shapesarray;
        this->playerNumber = other.playerNumber;
        this->winner = other.winner;
    }
    return *this;
}

void const Player::printboard() const
{
    boardGameForPlayer.PrintBoardGame(playerNumber);
}

void Player::UpdateBoard(const Objects& shape)
{
    if (typeid(shape) == typeid(Bomb))
    {
        boardGameForPlayer.Explosion(shape.getPointByIdx(0));
        //UpdateBoardExplosion(shape.getPointByIdx(0));
    }
    else {
        for (int i = 0; i < BodyPointSize; i++)
        {
            boardGameForPlayer.setPointAtBoard(shape.getPointByIdx(i), shape.getColor());
        }
    }

}

void Player::UpdateBoardExplosion(const Point& point)
{
    int x = point.getx() - _BombExplosion;
    int y = point.gety() + _BombExplosion;

    if (x > rightBoardPlayer1)
        x = x - LeftBoardPlayer2;

    for (int i =y ; i > TopBoard ; i--)
    {
        for (int j = x; j < rightBoardPlayer1; j++)
        {   
            if(x < LeftBoardPlayer1)
                boardGameForPlayer.DropPoint(j, i);
        }
    }
}

bool Player::IsPossible(const Objects& shape, char movement)
{
    int serialNum = shape.getSerialNumber();
    int x, y;
    if (Right1 == movement || Right1B == movement || Right2 == movement || Right2B == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx() + 1;
            else
                x = shape.getPointByIdx(i).getx() + 1 - LeftBoardPlayer2;
            y = shape.getPointByIdx(i).gety();
            if (boardGameForPlayer.getCharAtBoard(y, x) != space)
                return false;
        }
    }
    if (Left1 == movement || Left1B == movement || Left2 == movement || Left2B == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx() - 1;
            else
                x = shape.getPointByIdx(i).getx() - 1 - LeftBoardPlayer2;
            y = shape.getPointByIdx(i).gety();
            if (boardGameForPlayer.getCharAtBoard(y, x) != space)
                return false;
        }
    }
    if (Drop1 == movement || Drop1B == movement || Drop2 == movement || Drop2B == movement || MoveDown == movement) {
        for (int i = 0; i < BodyPointSize; i++) {
            if (playerNumber == Player1)
                x = shape.getPointByIdx(i).getx();
            else
                x = shape.getPointByIdx(i).getx() - LeftBoardPlayer2;

            y = shape.getPointByIdx(i).gety() + 1;
            if (boardGameForPlayer.getCharAtBoard(y, x) != space)
                return false;
        }
    }

    if (RotateClockWise1 == movement || RotateClockWise1B == movement || RotateClockWise2 == movement || RotateClockWise2B == movement)
    {
        return  shape.CheckRotate(playerNumber, boardGameForPlayer);
    }
    if (RotateCounterClockWise1 == movement || RotateCounterClockWise1B == movement || RotateCounterClockWise2 == movement || RotateCounterClockWise2B == movement)
    {
        return  shape.CheckCounterRotate(playerNumber, boardGameForPlayer);
    }
    return true;
}

bool Player::CheckGameOver(Objects& shape)
{
    int col;
    
    for (int col = 1; col < rightBoardPlayer1; col++)
    {
        if (boardGameForPlayer.getCharAtBoard(TopBoard + 1, col) != space)
        {
            winner = 0;
            return false;
        }
    }
    return true;
}

void Player::CheckRow()
{
    bool flag; 
    for (int i = 1; i < Rows-1; i++)
    {
        flag = true;
        for (int j = 1; j < Cols -1; j++)
        {
            if (boardGameForPlayer.getCharAtBoard(i, j) == space)
                flag = false;
        }

        if (flag == true)
        {
            boardGameForPlayer.UpdateBoardByRow(i);
        }
    }
    //printboard();
}

