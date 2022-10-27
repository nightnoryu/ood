#include "CCanvas.h"
#include <iomanip>
#include <iostream>

void graphics_lib::CCanvas::SetColor(graphics_lib::RgbColor color)
{
	std::ios oldState(nullptr);
	oldState.copyfmt(std::cout);

	std::cout << "SetColor (0x"
			  << std::setfill('0') << std::hex << std::uppercase << std::setw(6)
			  << color << ")\n";

	std::cout.copyfmt(oldState);
}

void graphics_lib::CCanvas::MoveTo(int x, int y)
{
	std::cout << "MoveTo (" << x << ", " << y << ")\n";
}

void graphics_lib::CCanvas::LineTo(int x, int y)
{
	std::cout << "LineTo (" << x << ", " << y << ")\n";
}
