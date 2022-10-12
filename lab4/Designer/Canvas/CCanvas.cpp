#include "CCanvas.h"
#include <iostream>

void CCanvas::SetColor(Color color)
{
	std::cout << "Color: ";
	switch (color)
	{
	case Color::Red:
		std::cout << "red";
	case Color::Green:
		std::cout << "green";
	case Color::Blue:
		std::cout << "blue";
	case Color::Pink:
		std::cout << "pink";
	case Color::Yellow:
		std::cout << "yellow";
	case Color::Black:
		std::cout << "black";
	}

	std::cout << '\n';
}

void CCanvas::DrawLine(const Point& from, const Point& to)
{
	std::cout << "Line from ("
			  << from.x << ", " << from.y << ") to ("
			  << to.x << ", " << to.y << ")\n";
}

void CCanvas::DrawEllipse(const Point& center, int width, int height)
{
	std::cout << "Ellipse in ("
			  << center.x << ", " << center.y << ")"
			  << ", Rh = " << width << ", Rv = " << height << '\n';
}
