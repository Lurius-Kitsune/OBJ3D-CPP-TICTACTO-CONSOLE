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
	u_int x;
	u_int y;

	Coordinates() = default;

	Coordinates(const u_int& _x, const u_int& _y)
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
