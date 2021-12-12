#include <iostream>
using namespace std;

#include <windows.h>
#include <process.h>
#include "TetrisGame.h"
#include "gotoxy.h"
#include"ShapesArray.h"



void gotoxy(int, int); // prototype
void clrscr(); // prototype

void main()
{
    Color c = LIGHTGREY;
    setTextColor(c);
    
    int x = 4;
   

    TetrisGame g;
    hideCursor();
    g.Start();

    gotoxy(20, 20);
}

