#pragma once

#include "Macro.h"
static string GetLine()
{
	string _line = string();

	do
	{
		const int _charASCII = getchar();
		if (_charASCII == EOF || _charASCII == '\n')
		{
			break;
		}


		_line += char(_charASCII);
	} while (true);

	return _line;
}
