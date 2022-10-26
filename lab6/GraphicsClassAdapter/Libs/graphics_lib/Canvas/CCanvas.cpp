#include "CCanvas.h"
#include <iostream>

void graphics_lib::CCanvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")\n";
}

void graphics_lib::CCanvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")\n";
}
