#pragma once

#include "../Shapes/CShape.h"

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
};

class ICanvas
{
public:
	virtual void SetColor(Color color) = 0;
	virtual void DrawLine(Point const& from, Point const& to) = 0;
	virtual void DrawEllipse(Point const& center, int width, int height) = 0;
};
