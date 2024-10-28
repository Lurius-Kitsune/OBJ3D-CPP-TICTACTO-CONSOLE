#pragma once
#include "Grid.h"

class Game
{
	Player* player1;
	Player* player2;
	Grid* gameGrid;
	u_int currentPlayerIndex;


public:
	Game() = default;
	Game(const u_int& _gridSize, const string& _player1Name, const string& _player2Name);
	~Game();

public:
	void LaunchGame();
	void HandleGame();
private:
	bool IsOver(const Coordinates& _coords, bool& _isNull);
};

