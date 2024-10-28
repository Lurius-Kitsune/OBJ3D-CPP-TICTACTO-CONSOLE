#include "Grid.h"

Grid::Grid(const u_int& _gridSize)
{
	gridSize = _gridSize;
	tiles = nullptr;
}

Grid::~Grid()
{
	for (u_int _i = 0; _i < gridSize; _i++)
	{
		delete[] tiles[_i];
	}

	delete[] tiles;
}

void Grid::Init()
{
	tiles = new Tile *[gridSize];
	for (u_int _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		tiles[_rowIndex] = new Tile[gridSize];
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			tiles[_rowIndex][_columnIndex] = Tile();
		}
	}
}

void Grid::Display()
{
	for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
	{
		DISPLAY(" " + to_string(_columnIndex+1), false);
	}
	DISPLAY(" ", true);
	for (u_int _rowIndex = 0; _rowIndex < gridSize; _rowIndex++)
	{
		DISPLAY(char('A' + _rowIndex), false);
		for (u_int _columnIndex = 0; _columnIndex < gridSize; _columnIndex++)
		{
			DISPLAY(" ", false);
			Tile _tile = tiles[_rowIndex][_columnIndex];
			DISPLAY((!_tile.IsAvailable() ? _tile.GetApparence() : "-"), false);
		}

		DISPLAY("", true);
	}
}

bool Grid::PlaceMarker(Player*& _player, const Coordinates& _coordinate)
{
	if (!tiles[_coordinate.x][_coordinate.y].IsAvailable()) return false;

	// On ne place pas l'icon si la case a déja été prise ! 
	tiles[_coordinate.x][_coordinate.y].SetPlayer(_player);
	return true;
}

bool Grid::IsOutOfRange(const Coordinates& _coordinates)
{
	return (_coordinates.x < 0 || _coordinates.x >= gridSize) ||
		(_coordinates.y < 0 || _coordinates.y >= gridSize);
}


