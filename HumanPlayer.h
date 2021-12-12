#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(int playerNumber = Player1) : Player(playerNumber) {}
};

