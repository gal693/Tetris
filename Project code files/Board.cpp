#include "Board.h"
 #include "gotoxy.h"


Board::Board()
{
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {
		  if(j == LeftBoardPlayer1 && i == TopBoard)
			  boardGame[i][j] = 220;
		  else if (j == rightBoardPlayer1 && i == TopBoard)
			  boardGame[i][j] = 220;
		  else if (j == LeftBoardPlayer1 || j == rightBoardPlayer1)
			 boardGame[i][j] = 219;
		  else if (i == TopBoard || i == Bottom)
			 boardGame[i][j] = 220;
		  else
			 boardGame[i][j] = space;
	   }
    }
    
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {
			 BoardColors[i][j] = LIGHTGREY;
	   }
    }
}

void Board::setPointAtBoard(const Point& point,Color c)
{
    int x, y;
    x = point.getx();
    y = point.gety();
    if (x > rightBoardPlayer1)
	   x = x - LeftBoardPlayer2;
    boardGame[y][x] = point.getCh();
    BoardColors[y][x] = c;
}

void Board::UpdateBoardByRow(int row)
{
    for (int i = 1; i < Cols-1; i++)
    {
	   boardGame[row][i] = space;
    }

    for (int i = row; i > 2 ; i--)
    {
	   for (int j = 1; j < Cols - 1; j++)
	   {
		  boardGame[i][j] = boardGame[i-1][j];
		  BoardColors[i][j] = BoardColors[i - 1][j];
	   }	 
    }

}

void Board::ResetBoard()
{
	*this = Board();
}

void Board::Explosion(const Point& point)
{
    int x, y;
    x = point.getx() - _BombExplosion;
    y = point.gety() - _BombExplosion;
   
    if (x > rightBoardPlayer1)
	   x = x - LeftBoardPlayer2;
    

    for (int i= 0; i < _BombExplosionLoop; i++)
    {

	   for (int j = 0; j < _BombExplosionLoop; j++)
	   {
		  if ((y + i) > TopBoard && (y + i) < Bottom && (x + j) > LeftBoardPlayer1 && (x + j) < rightBoardPlayer1)
		  {
			 boardGame[y + i][x + j] = space;
			 BoardColors[y + i][x + j] = LIGHTGREY;
		  }
	   }
    }
}

void Board::DropPoint(int x, int y)
{
    char ch;
    Color color;
    if (boardGame[y][x] == space)
	   return;
    else 
    {
	   ch = boardGame[y][x];
	   color = BoardColors[y][x];
	   boardGame[y][x] = space;
	   while (y < Bottom && boardGame[y + 1][x] == space )
		  y++;
    }
    boardGame[y][x] = ch;
    BoardColors[y][x] = color;
}

bool Board::CheckIfExistAtRow(int row)
{
    for (int i = 1; i < rightBoardPlayer1; i++)
    {
	   if (boardGame[row][i] != space)
		  return true;
    }
	return false;
}

void Board::PrintBoardGame(int player) const
{
     
    
    for (int i = 0; i < Rows; i++)
    {
	   for (int j = 0; j < Cols; j++)
	   {			
		  if(player == Player2)
			  gotoxy(j + LeftBoardPlayer2, i);
		  Color c = BoardColors[i][j];
		  setTextColor(c);
		  cout << boardGame[i][j];
	   }
	   cout << endl;
    }
}