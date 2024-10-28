#pragma once
#include "Macro.h"

enum VerticalDirection
{
	VD_LEFT = -1,
	VD_MIDDLE,
	VD_RIGHT,
	VD_NONE
};

enum HorizontalDirection
{
	HD_UNDER = -1,
	HD_MIDDLE,
	HD_TOP,
	HD_NONE,
};

struct Coordinates
{
	int x;
	int y;

	Coordinates() = default;

	Coordinates(const int _x, const int _y)
	{
		x = _x;
		y = _y;
	}

	static Coordinates RetrieveCoordinate()
	{
		DISPLAY("Qu'elle case ?", true);
		const string _answer = GetLine();
		
		return Coordinates((_answer[0] - 'A'), _answer[1]-'1');
	}
};
