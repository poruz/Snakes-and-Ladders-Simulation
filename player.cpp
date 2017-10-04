#include "player.h"

Player::Player(int i)
:id(i), currTile(0), numWins(0)
{}

int& Player::retCurrTile()
{
	return currTile;
}

void Player::incrementWin()
{
	numWins++;
}

int Player::retNumWins() const
{
	return numWins;
}