#pragma once
#include "Player.h"
class ComputerPlayer : public Player
{
private:
	int level = easy;

public:
	ComputerPlayer(int _level,int player) : Player(player) , level(_level) {}
	const int getPlayerLevel()const override { return level; }

};

