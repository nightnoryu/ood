#pragma once

enum class Color
{
	Red,
	Green,
	Blue,
	Pink,
	Yellow,
	Black,
};

struct Point
{
	int x = 0;
	int y = 0;

	bool operator==(Point const& other) const
	{
		return x == other.x && y == other.y;
	}
};
