#include "board.h"

Board::Board()
{
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
		{
			grid[i][j] = 'B'; //make all tiles blank
		}
}

void Board::addSnake(Snake s)
{
	int mouthTile = s.mouth;
	int tailTile = s.tail;

	//Suppose snake's mouth tile is at 99.
	//It's coordinate in the grid would be (9,8)
	//Suppose snake's tail tile is at 5.
	//It's coordinate in the grid would be (0,4)
	//So if tile is n, it's coordinate is ((n-1)/10, (n-1)%10)
	
	int mx = (mouthTile-1)/10, my = (mouthTile-1)%10;
	int tx = (tailTile-1)/10, ty = (tailTile-1)%10;

	/*Checks to be made***
	* mouth tile should be blank
	* tail tile should be blank
	* mouth tile has to be at a higher row than the tail tile
	* boundary checks
	********************/

	if( grid[mx][my] == 'B' && grid[tx][ty] == 'B' && mx > tx &&
		mouthTile >= 1 && mouthTile <= 100 && tailTile >= 1 && tailTile <= 100)
	{
		grid[mx][my] = 'S'; //Grid got a snake added
		snakes.insert(std::make_pair(mouthTile,tailTile));
	}

}

void Board::addLadder(Ladder l)
{
	int bottomTile = l.bottom;
	int topTile = l.top;

	int bx = (bottomTile-1)/10, by = (bottomTile-1)%10;
	int tx = (topTile-1)/10, ty = (topTile-1)%10;
	
	if( grid[bx][by] == 'B' && grid[tx][ty] == 'B' && bx < tx &&
		bottomTile >= 1 && bottomTile <= 100 && topTile >= 1 && topTile <= 100)
	{
		grid[bx][by] = 'L'; //Grid got a ladder added
		ladders.insert(std::make_pair(bottomTile,topTile));
	}

}

char Board::retTileType(int t)
{
	if(t >= 1 && t <= 99)
	{
		return grid[(t-1)/10][(t-1)%10];
	}
	return 0;
}

int Board::mouthToTail(int t)
{
	return snakes[t];
}

int Board::bottomToTop(int t)
{
	return ladders[t];
}
