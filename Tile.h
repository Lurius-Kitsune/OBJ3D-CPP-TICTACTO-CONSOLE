#pragma once
#include "Player.h"
class Player;
class Tile
{
	Player* player;

public:

	Player* GetPlayer() const
	{
		return player;
	}

	void SetPlayer(Player* _player)
	{
		player = _player;
	}

	Tile()
	{
		player = nullptr;
	}

public:
	bool IsAvailable() const;

	string GetApparence() const;
};

