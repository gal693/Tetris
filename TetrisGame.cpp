#include "gotoxy.h"
#include "TetrisGame.h"


TetrisGame::TetrisGame()
{
    ThePlayers = new Player * [NumOfPlayers];

    ThePlayers[Player1] = nullptr;
    ThePlayers[Player2] = nullptr;

}
TetrisGame::~TetrisGame()
{
    delete ThePlayers[0];
    delete ThePlayers[1];

    delete[] ThePlayers;

}

const TetrisGame& TetrisGame::operator=(const TetrisGame& other)
{
	if (this != &other)
	{
		Player** temp = new Player*[2];
		temp[Player1] = ThePlayers[Player1];
		temp[Player2] = ThePlayers[Player2];

		this->ThePlayers = temp;
		this->GameMenu = other.GameMenu;
		this->gameoverflag = other.gameoverflag;
	}
	return *this;
}

void TetrisGame:: InitPlayersBoards()
{
	ThePlayers[Player1]->getBoardGame().ResetBoard();
	ThePlayers[Player2]->getBoardGame().ResetBoard();
}

void TetrisGame::InitColors()
{
    ThePlayers[Player1]->getShapesarray().InitColorsShapesArray();
    ThePlayers[Player2]->getShapesarray().InitColorsShapesArray();

}

void TetrisGame::DropShape(Objects& S, int player_num, char key)
{
	while (ThePlayers[player_num]->IsPossible(S, key))
	{
		S.move(key);
		Sleep(Dropsleep);
	}
}

void TetrisGame::RandomShape(Objects** S, int player)
{
    int randShape;
    randShape = rand() % RAND;
    int randBomb = rand() % RANDBOMB; //every number have 5% 
    Objects* TempPointerShape;
    TempPointerShape = *S;
    
    if (randBomb != _Bomb)
    {
	   if (player == Player1)
		  *S = ThePlayers[Player1]->getShapesarray().getShape(randShape)->Clone();
	   else
		  *S = ThePlayers[Player2]->getShapesarray().getShape(randShape)->Clone();
    }
    else
    {
	   if (player == Player1)
		  *S = ThePlayers[Player1]->getShapesarray().getShape(_Bomb)->Clone();
	   else
		  *S = ThePlayers[Player2]->getShapesarray().getShape(_Bomb)->Clone();
    }
    delete TempPointerShape;
}

void TetrisGame::createPlayers(int gameType,int level)
{
    if (ThePlayers[0] != nullptr && ThePlayers[1] != nullptr)
    {
	   delete ThePlayers[Player1];
	   delete ThePlayers[Player2];

    }
    if (gameType == HumanVsHuman)
    {
	   ThePlayers[Player1] = new HumanPlayer(Player1);
	   ThePlayers[Player2] = new HumanPlayer(Player2);
    }
	else if (gameType == HumanVsComputer)
	{
		ThePlayers[Player1] = new HumanPlayer(Player1);
		ThePlayers[Player2] = new ComputerPlayer(level,Computer_Player2);
	}
	else if (gameType == ComputerVsComputer)
	{
	    ThePlayers[Player1] = new ComputerPlayer(level, Computer_Player1);
	    ThePlayers[Player2] = new ComputerPlayer(level, Computer_Player2);
	}
}

TetrisGame::TetrisGame(const TetrisGame& other)
{
	*this = other;
}

void TetrisGame::Start()
{ 
    int input = 0;
    char colorsInput , levelInput;

	GameMenu.PresentColorOptions();
    _kbhit();
    colorsInput = _getch() - '0';
    
    Objects *S1 = nullptr, *S2=nullptr;

	   while (input != EXIT)
	   {
		  clrscr();
		  GameMenu.PresentMenu(gameoverflag);
		  _kbhit();
		  input = _getch() - '0';
		  clrscr();
		  switch (input)
		  {
		  case startHumanVsHuman:
		  {
			 createPlayers(HumanVsHuman);
			 InitPlayersBoards();
			 if (colorsInput == ColorGame)
				InitColors();			 			 
			 S1 = nullptr;
			 S2 = nullptr;
			 
			 RunPlayerVsPlayer(&S1, &S2);

			 gameoverflag = conGame;
			 break;
		  }
		  case startHumanVsComputer:
		  {
			 GameMenu.PresentDifficultyOptions();
			 _kbhit();
			 levelInput = _getch() - '0' -1;
			 clrscr();
			 createPlayers(HumanVsComputer, levelInput);
			 InitPlayersBoards();
			 if (colorsInput == ColorGame)
				InitColors();
			 S1 = nullptr;
			 S2 = nullptr;
			 
			 RunPlayerVsComputer(&S1, &S2);
			 gameoverflag = conGame;
			 break;
		  }
		  case startComputerVsComputer:
		  {
			  GameMenu.PresentDifficultyOptions();
			  _kbhit();
			  levelInput = _getch() - '0' -1;
			  clrscr();
			 createPlayers(ComputerVsComputer, levelInput);

			 InitPlayersBoards();
			 if (colorsInput == ColorGame)
				InitColors();
			 S1 = nullptr;
			 S2 = nullptr;


			 RunComputerVsComputer(&S1, &S2);
			 gameoverflag = conGame;
			 break;
		  }
		  case Continue:
		  {
			 if (strcmp(typeid(ThePlayers[Player1]).name() ,typeid(ComputerPlayer).name()))
				RunComputerVsComputer(&S1, &S2);
			 else if(strcmp(typeid(ThePlayers[Player2]).name(),typeid(Player).name()))
				RunPlayerVsPlayer(&S1,&S2);
			 else
				RunPlayerVsComputer(&S1, &S2);
			 break;
		  }
		  case PresentInstructionskeys:
		  {
			 GameMenu.PresentInstructions();
			 break;
		  }
		  }
	   }

	   if (input == EXIT)
	   {
		   GameMenu.PresentEnd();
	   }
}

bool TetrisGame::IsKeyboard1(char ch)
{
    for (int i = 0; i < CommandLoop; i++)
    {
	   if (ThePlayers[Player1]->getKeys()[i] == ch)
		  return true;
    }
    return false;
}

bool TetrisGame::IsKeyboard2(char ch)
{
    for (int i = 0; i < CommandLoop; i++)
    {
	   if (ThePlayers[Player2]->getKeys()[i] == ch)
		  return true;
    }
    return false;
}

void TetrisGame::printGameOver()
{
    gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2);
	if (!ThePlayers[Player1]->getWinner())
	{
		cout << "PLAYER 2";
		gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2+1);
		cout << "   WON";
	}
	else
	{
		cout << "PLAYER 1";
		gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2 + 1);
		cout << "   WON";
	}

	gotoxy(rightBoardPlayer1 + 2, (TopBoard + Bottom) / 2 +3);
	cout << "GAME OVER";
	Sleep(4000);
	system("cls");
	gameoverflag = startGame;

	return;
}

char TetrisGame::PlayerVsPlayer(Objects** S1, Objects** S2)
{
	char key = 0;
	for (int i = 0; i < CommandLoop; i++)
	{
		if (_kbhit())
		{
			hideCursor();
			key = _getch();
			if (key == ESC)
			{
				clrscr();
				return key;
			}
			if (IsKeyboard1(key))
			{
				if (Drop1 == key || Drop1B == key)
				{
					DropShape(**S1, Player1, key);//Drops shape while possible
					i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player1]->IsPossible(**S1, key))//Checks if a given move input is possible (any move but down)
					(*S1)->move(key);//Moves shape according to given input
			}
			if (IsKeyboard2(key)) {
				if (Drop2 == key || Drop2B == key)
				{
					DropShape(**S2, Player2, key);//Drops shape while possible
					i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player2]->IsPossible(**S2, key))//Checks if a given move input is possible (any move but down)
					(*S2)->move(key);//Moves shape according to given input
			}
		}
		Sleep(CommandLoopSleep);
	}
	return key;
}

char* TetrisGame::UpdateComputerPlayersBoard(Objects** S,int level, int playerNumber)
{
	ThePlayers[playerNumber]->UpdateBoard(**S);
	RandomShape(S, playerNumber);
	ThePlayers[playerNumber]->CheckRow(); //Checks if there is any rows that are full, if so deletes row
	gotoxy(LeftBoardPlayer2*playerNumber, TopBoard);
	ThePlayers[playerNumber]->getBoardGame().PrintBoardGame(playerNumber);//Prints updated board
	return (*S)->FindBestSpot(ThePlayers[playerNumber]->getBoardGame(), level, playerNumber);
}

void TetrisGame::UpdatePlayersBoard(Objects** S, int playerNumber)
{
	ThePlayers[playerNumber]->UpdateBoard(**S);
	RandomShape(S, playerNumber);
	ThePlayers[playerNumber]->CheckRow(); //Checks if there is any rows that are full, if so deletes row
	gotoxy(LeftBoardPlayer2*playerNumber, TopBoard);
	ThePlayers[playerNumber]->getBoardGame().PrintBoardGame(playerNumber);//Prints updated board
	return;
}

char TetrisGame::PlayerVsComputerLoop(Objects** S1, Objects** S2, char key)
{

	if (ThePlayers[Player2]->IsPossible(**S2, key))
		if(key != MoveDown)
			(*S2)->move(key);

	for (int i = 0; i < CommandLoop; i++)
	{
		if (_kbhit())
		{
			hideCursor();
			key = _getch();
			if (key == ESC)
			{
				clrscr();
				return key;
			}
			if (IsKeyboard1(key))
			{
				if (Drop1 == key || Drop1B == key)
				{
					DropShape(**S1, Player1, key);//Drops shape while possible
					i = CommandLoop; // quit from the loop
				}
				else if (ThePlayers[Player1]->IsPossible(**S1, key))//Checks if a given move input is possible (any move but down)
					(*S1)->move(key);//Moves shape according to given input
			}
		}
		Sleep(CommandLoopSleep);
	}
	return key;
}

void TetrisGame::RunPlayerVsPlayer(Objects** S1, Objects** S2)
{
	char key = 0;
	int randShape = rand() % RAND;

	if (*S1 == nullptr && *S2 == nullptr) {

		RandomShape(S1, Player1);
		RandomShape(S2, Player2);
	}
	//Prints boards
	ThePlayers[Player1]->getBoardGame().PrintBoardGame(Player1);
	gotoxy(LeftBoardPlayer2, 0);
	ThePlayers[Player2]->getBoardGame().PrintBoardGame(Player2);

	do {
		//Checks if a shape reached the top of the board
		if (!ThePlayers[Player1]->CheckGameOver(**S1) || !ThePlayers[Player2]->CheckGameOver(**S2))
		{
			printGameOver();
			return;
		}
		(*S1)->draw();
		(*S2)->draw();

		//Clears the input buffer for more fluid gaming
		HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
		FlushConsoleInputBuffer(hStdIn);

		key = PlayerVsPlayer(S1, S2);
		if (ThePlayers[Player1]->IsPossible(**S1, MoveDown))//Drops shape by one step
			(*S1)->move(MoveDown);
		else //If shape reached bottom, update the shape in the board and randomly pick new shape
			UpdatePlayersBoard(S1, Player1);

		if (ThePlayers[Player2]->IsPossible(**S2, MoveDown))//Drops shape by one step
			(*S2)->move(MoveDown);
		else//If shape reached bottom, update the shape in the board and randomly pick new shape
			UpdatePlayersBoard(S2, Player2);

		Sleep(Sleep1);
	} while (key != ESC);

}

void TetrisGame::RunPlayerVsComputer(Objects** S1, Objects** S2)
{
	char key = 0;
	int index= 0,level = ThePlayers[Player2]->getPlayerLevel();
	int randShape = rand() % RAND;
	char* computer_commands = nullptr;

	if (*S1 == nullptr && *S2 == nullptr) {

		RandomShape(S1, Player1);
		RandomShape(S2, Player2);
	}
	
	computer_commands = (*S2)->FindBestSpot(ThePlayers[Player2]->getBoardGame(), level);

	//Prints boards
	ThePlayers[Player1]->getBoardGame().PrintBoardGame(Player1);
	gotoxy(LeftBoardPlayer2, 0);
	ThePlayers[Player2]->getBoardGame().PrintBoardGame(Player2);

	do {
		//Checks if a shape reached the top of the board
		if (!ThePlayers[Player1]->CheckGameOver(**S1) || !ThePlayers[Player2]->CheckGameOver(**S2))
		{
		    delete computer_commands;
			printGameOver();
			return;
		}
		(*S1)->draw();
		(*S2)->draw();

		//Clears the input buffer for more fluid gaming
		HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
		FlushConsoleInputBuffer(hStdIn);

		char direction = computer_commands[index];
		key = PlayerVsComputerLoop(S1, S2, direction);
		index++;

		if (ThePlayers[Player1]->IsPossible(**S1, MoveDown))//Drops shape by one step
			(*S1)->move(MoveDown);
		else //If shape reached bottom, update the shape in the board and randomly pick new shape
			UpdatePlayersBoard(S1, Player1);
		
		if (ThePlayers[Player2]->IsPossible(**S2, MoveDown))//Drops shape by one step
			(*S2)->move(MoveDown);
		else//If shape reached bottom, update the shape in the board and randomly pick new shape
		{
			if(computer_commands)
				delete computer_commands;
			computer_commands = UpdateComputerPlayersBoard(S2, level, Computer_Player2);
			index = 0;
		}
		Sleep(CommandLoopSleep);
	} while (key != ESC);

}

void TetrisGame::RunComputerVsComputer(Objects** S1, Objects** S2)
{
    char key =0;
    int index1 = 0, index2 = 0, randShape = rand() % RAND , level1 = ThePlayers[Player1]->getPlayerLevel(),level2 = ThePlayers[Player2]->getPlayerLevel();
    bool flag1 = true, flag2 = true;

    if (*S1 == nullptr && *S2 == nullptr) 
	{
	   RandomShape(S1, Player1);
	   RandomShape(S2, Player2);
    }
    //Prints boards
    ThePlayers[Player1]->getBoardGame().PrintBoardGame(Player1);
    gotoxy(LeftBoardPlayer2, 0);
    ThePlayers[Player2]->getBoardGame().PrintBoardGame(Player2);
	char* computer_commands1 = (*S1)->FindBestSpot(ThePlayers[Player1]->getBoardGame(), level1, Computer_Player1);
	char* computer_commands2 = (*S2)->FindBestSpot(ThePlayers[Player2]->getBoardGame(), level2, Computer_Player2);
    
	do {
	    if (_kbhit())
	    {
		   hideCursor();
		   key = _getch();
	    }
	    //Checks if a shape reached the top of the board
	    if (!ThePlayers[Player1]->CheckGameOver(**S1) || !ThePlayers[Player2]->CheckGameOver(**S2))
	    {
		   delete computer_commands2;
		   delete computer_commands1;
		   printGameOver();
		   return;
	    }

	    (*S1)->draw();
	    (*S2)->draw();
	    //Clears the input buffer for more fluid gaming
	    HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	    FlushConsoleInputBuffer(hStdIn);

	    char direction1 = computer_commands1[index1];
	    char direction2 = computer_commands2[index2];

	    if (index1 >= 21 || index2 >= 21)
		   index1 = index1;
		 if (ThePlayers[Player1]->IsPossible(**S1, direction1))//Drops shape by one step
		   (*S1)->move(direction1);
		 if (ThePlayers[Player2]->IsPossible(**S2, direction2))
		   (*S2)->move(direction2);
		   
	   index1++;
	   index2++;

	   if (ThePlayers[Player1]->getBoardGame().CheckIfExistAtRow(Bottom-6) && computer_commands1[index1] != 's' && flag1)//moves shape faster to avoid getting stuck
	   {
		  FastComputerLoop(**S1, computer_commands1, index1,Player1);
		  flag1 = false;
	   }
	   if (ThePlayers[Player2]->getBoardGame().CheckIfExistAtRow(Bottom - 6) && computer_commands2[index2] != 'k' && flag2)
	   {
		  FastComputerLoop(**S2, computer_commands2, index2,Player2);
		  flag2 = false;
	   }

	   if (ThePlayers[Player1]->IsPossible(**S1, MoveDown))//Drops shape by one step
		  (*S1)->move(MoveDown);	   
	   else //If shape reached bottom, update the shape in the board and randomly pick new shape
	   {
		  if (computer_commands1)
			delete computer_commands1;
		  computer_commands1 = UpdateComputerPlayersBoard(S1, level1, Player1);
		  index1 = 0;
		  flag1 = true;
	   }
	   if (ThePlayers[Player2]->IsPossible(**S2, MoveDown))//Drops shape by one step
		  (*S2)->move(MoveDown);
	   else//If shape reached bottom, update the shape in the board and randomly pick new shape
	   {
		  if (computer_commands2)
			   delete computer_commands2;
		  computer_commands2 = UpdateComputerPlayersBoard(S2, level2, Player2);
		  index2 = 0;
		  flag2 = true;
	   }
	   Sleep(Sleep2);
    } while (key != ESC);
}

void TetrisGame::FastComputerLoop(Objects& S,char* computer_commands, int& index,int playerNumber)
{
    char direction;
    for (int i = 0; i < DirLoop; i++)
    {
	   direction = computer_commands[index];
	   if (ThePlayers[playerNumber]->IsPossible(S, direction)) {//Drops shape by one 
		  S.move(direction);
		  index = index++;
		  S.draw();
	   }
	   else
	   {
		  if (ThePlayers[playerNumber]->IsPossible(S, MoveDown))
			 S.move(MoveDown);
	   }
	   Sleep(CommandLoopSleep);
    }

}
