#pragma once
#include "Player.h"

class Menu 
{
private:

public:
    Menu() {};
    ~Menu() {};

    void PresentMenu(int pause) const; //Presents menu to the screen
    void PresentInstructions() const;//Presents instructions and controls to the screen
    void PresentEnd() const;
    void PresentColorOptions() const;
    void PresentDifficultyOptions() const;

};

