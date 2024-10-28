#pragma once
#include "Tile.h"
#include "Coordinates.h"

class Grid
{
	Tile** tiles;
	u_int gridSize;

public:
	u_int GetGridSize()const
	{
		return gridSize;
	}

	Tile* GetTile(Coordinates _coordinates)
	{
		return IsOutOfRange(_coordinates) ? &tiles[_coordinates.x][_coordinates.y] : nullptr;
	}

	Grid() = default;
	Grid(const u_int& _gridSize);
	~Grid();

public:
	void Init();

	void Display();
	
	bool PlaceMarker(Player*& _player, const Coordinates& _coordinate);

	bool IsOutOfRange(const Coordinates& _coordinates);
};

