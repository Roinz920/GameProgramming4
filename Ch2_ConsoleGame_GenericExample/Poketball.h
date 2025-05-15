#pragma once

#include "ConsoleUtility.h"

class PokeMon
{
private:
	int _number;
	string _name;

public:
	PokeMon() = default;
	~PokeMon() = default;

	PokeMon(int number, string name)
		:_number(number), _name(name) {	}

	int get_number() const
	{
		return _number;
	}

	string get_name() const
	{
		return _name;
	}
};