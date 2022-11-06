#pragma once

#include <cstdint>

using RgbaColor = std::uint32_t;

template <typename T>
struct Point
{
	T x;
	T y;

	bool operator==(Point const& other) const
	{
		return x == other.x && y == other.y;
	}
};

using PointD = Point<double>;

template <typename T>
struct Rect
{
	T Top()
	{
		return leftTop.y;
	}

	T Right()
	{
		return leftTop.x + width;
	}

	T Bottom()
	{
		return leftTop.y + height;
	}

	T Left()
	{
		return leftTop.x;
	}

	bool IsEmpty()
	{
		return width == 0 && height == 0;
	}

	bool operator==(Rect const& other) const
	{
		return leftTop == other.leftTop && width == other.width && height == other.height;
	}

	Point<T> leftTop;
	T width;
	T height;
};

using RectD = Rect<double>;
