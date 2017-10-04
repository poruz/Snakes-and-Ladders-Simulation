#include "board.h"
#include "player.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	cout << "Enter the number of players: ";
	int numPlayers;
	cin >> numPlayers;

	cout << "Enter the number of simulations you want: ";
	long numSim;
	cin >> numSim;
	
	cout << "\nRunning " << numSim << " simulations\n\n";

	vector<Player> myPlayers;
	//index 0 to corresponds to p1

	for(int i = 0; i < numPlayers; i++)
	{
		myPlayers.push_back(Player(i));
	}

	//Make board
	Board myBoard;

	//Add Snakes
	myBoard.addSnake(Snake(17,7));
	myBoard.addSnake(Snake(84,34));
	myBoard.addSnake(Snake(62,19));
	myBoard.addSnake(Snake(64,60));
	myBoard.addSnake(Snake(87,24));
	myBoard.addSnake(Snake(93,73));
	myBoard.addSnake(Snake(95,75));
	myBoard.addSnake(Snake(99,78));

	//Add ladders
	myBoard.addLadder(Ladder(4,14));
	myBoard.addLadder(Ladder(9,31));
	myBoard.addLadder(Ladder(20,38));
	myBoard.addLadder(Ladder(28,84));
	myBoard.addLadder(Ladder(40,59));
	myBoard.addLadder(Ladder(51,67));
	myBoard.addLadder(Ladder(63,81));
	myBoard.addLadder(Ladder(71,91));

	//Simulations
	for(int i = 1; i <= numSim; i++) //each simulation
	{
		bool gameWon = false;

		while(!gameWon)
		{
			for(int j = 0; j < numPlayers && !gameWon; j++)
			{ //j'th player's turn

				int die;
				do
				{
					//Roll the die
					//Make moves accordingly
					die = rand()%6 + 1; //1 to 6 numbers

					int& pjTile = myPlayers[j].retCurrTile();
					pjTile += die;

					//Check if pjTile is a snake or ladder
					if(myBoard.retTileType(pjTile) == 'S') //snake mouth
					{ //change pjTile to snake's tail
						pjTile = myBoard.mouthToTail(pjTile);
					}
					else if(myBoard.retTileType(pjTile) == 'L') //Ladder's bottom
					{ //change pjTile to ladder's top
						pjTile = myBoard.bottomToTop(pjTile);
					}

					if(myPlayers[j].retCurrTile() > 100)
					{//Update j'th Player's numWin
						myPlayers[j].incrementWin();
						gameWon = true;

						for(int k = 0; k < numPlayers; k++)
						{
							int& pkTile = myPlayers[k].retCurrTile();
							pkTile = 0;
						}
					}
				}while(die == 6 && !gameWon);	

			}
		}
	}

	//Results
	cout << "Results" << endl;
	for(int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i+1 << " - " << myPlayers[i].retNumWins() << " wins "<< endl;
	}

	return 0;
}