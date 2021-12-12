#pragma once
#include <iostream>
using namespace std;
#include"Point.h"

class Board
{
private:    
    char boardGame[Rows][Cols];
    Color BoardColors[Rows][Cols];

public: 
    Board() ;
    ~Board() {};
    const char getCharAtBoard(int row, int col) const { return boardGame[row][col]; } // Returns the char at the wanted place on the board
    void setPointAtBoard(const Point& point,Color c); //Sets a given point in the board
    
    void UpdateBoardByRow(int row); //Erases the wanted row by index and fixes the board
    void ResetBoard();
    void Explosion(const Point& point);
    void DropPoint(int x , int y);

    bool CheckIfExistAtRow(int row);
    //Printing functions
    void PrintBoardGame(int player) const;
    
};







  