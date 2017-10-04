#ifndef BOARD_H
#define BOARD_H

#include <map>

struct Snake
{
	int mouth; //tile number with snake's mouth
	int tail;
	Snake(int m, int t): mouth(m), tail(t) 
	{}
};

struct Ladder
{
	int bottom;
	int top;
	Ladder(int b, int t): bottom(b), top(t) 
	{}
};

class Board
{
	char grid[10][10]; //10x10 board (i.e. tiles 1 to 100)
	//'B' would represent blank tile
	//'S' would represent snake's mouth tile
	//'L' would represent ladder's bottom tile

	std::map<int,int> snakes; //first = mouth tile, second = tail tile
	std::map<int,int> ladders; //first = bottom tile, second = top tile

public:
	Board();
	void addSnake(Snake s);
	void addLadder(Ladder l);
	char retTileType(int t);
	int mouthToTail(int t);
	int bottomToTop(int t);
};

#endif