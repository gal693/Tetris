#pragma once
#include"Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Menu.h"

class TetrisGame
{
private:

    enum { NumOfPlayers =2};
    Player** ThePlayers;

    Menu GameMenu;
    int gameoverflag = startGame;

public:
    //TetrisGame() {};
    TetrisGame();
    ~TetrisGame();
    const TetrisGame& operator=(const TetrisGame& other);
    TetrisGame(const TetrisGame& other);

    void createPlayers(int gameType,int level = easy);
    void RunPlayerVsPlayer(Objects** S1, Objects** S2);
    void RunPlayerVsComputer(Objects** S1, Objects** S2);
    void RunComputerVsComputer(Objects** S1, Objects** S2);
    void FastComputerLoop(Objects& S,char* computer_commands, int& index,int playerNumber);

    void Start(); //Game menu
    bool IsKeyboard1(char ch); //check if the key is of player 1
    bool IsKeyboard2(char ch); //check if the key is of player 2

    void printGameOver();//Prints GAME OVER to the screen
    void InitPlayersBoards();//Resets players boards to default
    void InitColors();//Sets colors to all shapes
    void DropShape(Objects& S, int player_num, char key);//Drops shape as long as its possible

    void RandomShape(Objects** S,int player);
    char PlayerVsPlayer(Objects** S1, Objects** s2);
    char PlayerVsComputerLoop(Objects** S1, Objects** S2, char key);

    char* UpdateComputerPlayersBoard(Objects** S,int level, int playerNumber);
    void UpdatePlayersBoard(Objects** S, int playerNumber);

};

