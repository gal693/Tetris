#include "Menu.h"

void Menu::PresentMenu(int pause) const
{
	Color c = LIGHTGREY;
	setTextColor(c);

	gotoxy(11, 7);
	cout << "TETRIS";
	gotoxy(5, 9);

	cout << "(1) Start a new game - Human vs Human\n";
	gotoxy(5, 10);

	cout << "(2) Start a new game - Human vs Computer \n";
	gotoxy(5, 11);

	cout << "(3) Start a new game - Computer vs Computer \n";

	int space_for_row = 0;
	if (pause)
	{
		space_for_row = 1;
		gotoxy(5, 12);
		cout << "(4) Continue the paused game\n ";
	}

	gotoxy(5, 12 + space_for_row);
	cout << "(8) Present instructions and keys\n";
	gotoxy(5, 13 + space_for_row);
	cout << "(9) EXIT " << endl;
}

void Menu::PresentInstructions() const
{
	gotoxy(5, 7);
	cout << "GAME INSTRUCTIONS\n";
	gotoxy(5, 8);
	cout << "In order to win you will need to keep your shapes from getting to the celling!\n";
	gotoxy(5, 9);
	cout << "You can do that by locating and turning the shapes to line them up as much as possible:\n ";
	gotoxy(5, 10);
	cout << "Every row that will be filled with shapes bricks will DISAPEAR!\n\n\n";

	gotoxy(30, 14);
	cout << "The controls are as below:\n";
	gotoxy(4, 18);
	cout << "Right:\n";
	gotoxy(4, 19);

	cout << "Left:\n";
	gotoxy(4, 20);

	cout << "Drop:\n";
	gotoxy(4, 21);

	cout << "Rotate clockwise:\n";
	gotoxy(4, 22);

	cout << "Rotate counter clockwise:\n";

	gotoxy(30, 16);
	cout << "PLAYER 1           PLAYER 2" << endl;
	gotoxy(31, 18);
	cout << "D or d             L or l" << endl;
	gotoxy(31, 19);
	cout << "A or a             J or j" << endl;
	gotoxy(31, 20);
	cout << "X or x             M or m" << endl;
	gotoxy(31, 21);
	cout << "S or s             K or k" << endl;
	gotoxy(31, 22);
	cout << "W or w             I or i" << endl;


	gotoxy(25, 30);

	cout << "Press any key to return to the menu!\n" << endl;
	hideCursor();
	char ch;
	_kbhit();
	ch = _getch();
	if (ch)
	{
		system("cls");
		return;
	}

}

void Menu::PresentEnd() const
{
	gotoxy(20, 10);
	cout << "THANK YOU FOR PLAYING, SEE YOU NEXT TIME!";
	return;
}

void Menu::PresentColorOptions() const
{
	gotoxy(5, 9);

	cout << "(1) For game with colors\n";
	gotoxy(5, 10);

	cout << "(2) For game without colors " << endl;
}

void Menu::PresentDifficultyOptions() const
{
	gotoxy(5, 9);

	cout << "Choose Computer Difficulty:\n";
	gotoxy(5, 10);

	cout << "(1) Easy\n";
	gotoxy(5, 11);

	cout << "(2) Medium \n";
	gotoxy(5, 12);

	cout << "(3) Hard \n";
	
}