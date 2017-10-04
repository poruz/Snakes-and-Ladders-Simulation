#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	int id; //Example 2 for player 2
	int currTile;
	long numWins;

public:
	Player(int i);
	int& retCurrTile();
	void incrementWin();
	int retNumWins() const;
};

#endif