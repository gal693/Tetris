#include "Point.h"

void Point::draw(char ch) const{
    gotoxy(x, y);
    cout << ch << endl;
}

void Point::draw() const
{
    gotoxy(x, y);
    cout << ch << endl;
}

void Point::move(char direction) {
    
    if (Drop1 == direction || Drop1B == direction || Drop2 == direction || Drop2B == direction || MoveDown == direction)
	   y++;
	
	if (Right1 == direction || Right1B == direction || Right2 == direction || Right2B == direction)
	   x++;

	if (Left1 == direction || Left1B == direction || Left2 == direction || Left2B == direction)
	   --x;
 }

