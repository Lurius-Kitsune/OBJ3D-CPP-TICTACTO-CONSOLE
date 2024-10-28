#include "Game.h"

Game::Game(const u_int& _gridSize, const string& _player1Name, const string& _player2Name)
{
	player1 = new Player(_player1Name, 'O', BLUE);
	player2 = new Player(_player2Name, 'X', RED);
	gameGrid = new Grid(_gridSize);
	currentPlayerIndex = 0;
}

Game::~Game()
{
	delete player1;
	delete player2;
	delete gameGrid;
}

void Game::LaunchGame()
{
	gameGrid->Init();
	HandleGame();
}

void Game::HandleGame()
{
	Player** _playerList = new Player * [2] {player1, player2};
	Player* _currentPlayer;
	Coordinates _coordinates;
	bool _isNull = false;
	do
	{
		_currentPlayer = _playerList[currentPlayerIndex%2];
		DISPLAY("-> Au tour de " + _currentPlayer->GetName() + RESET, true);
		gameGrid->Display();
		_coordinates = Coordinates::RetrieveCoordinate();
		if (gameGrid->IsOutOfRange(_coordinates) || !gameGrid->PlaceMarker(_currentPlayer, _coordinates))
		{
			CLEAR_SCREEN;
			DISPLAY("Veuillez choisir une case non occupé ou existante !", true);
			continue;
		}
		Tile* _tile = gameGrid->GetTile(_coordinates);
		currentPlayerIndex++;
		CLEAR_SCREEN;
	} while (!IsOver(_coordinates, _isNull));

	gameGrid->Display();
	DISPLAY((_isNull ? "Egalité !" : "Bravo à " + _currentPlayer->GetName()), true);

	delete[] _playerList;

	
}

bool Game::IsOver(const Coordinates& _coords, bool& _isNull)
{
	// si une ligne / diagonale existe
	const Coordinates _directions[] =
	{
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1},
	};

	const u_int _directionsCount = size(_directions);
	u_int _count = 1;
	for (u_int _index = 0; _index < _directionsCount; _index++)
	{
		const Coordinates& _nextPos = 
		_directions[_index] ;
	}

	// Si toute les case sont prises ou -> fin du jeu
	_isNull = currentPlayerIndex >= gameGrid->GetGridSize() * gameGrid->GetGridSize();
	return _isNull;
}
