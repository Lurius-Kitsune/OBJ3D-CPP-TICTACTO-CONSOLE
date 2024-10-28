#pragma once
#include "Random.h"

class Player
{
	string name;
	char icon;
	string color;

public:

	string GetName() const
	{
		return color + name;
	}

	char GetIcon() const
	{
		return icon;
	}

	string GetColor() const
	{
		return color;
	}

	Player() = default;
	Player(const string& _name, const char _icon, const string& _color);
};

