#include "Tile.h"

bool Tile::IsAvailable() const
{
	return !player;
}

string Tile::GetApparence() const
{
	return player->GetColor() + player->GetIcon() + RESET;
}
