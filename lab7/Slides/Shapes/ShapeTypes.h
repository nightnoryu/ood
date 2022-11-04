#pragma once

#include <cstdint>

using RgbaColor = std::uint32_t;

template <typename T>
struct Point
{
	T x;
	T y;
};

using PointD = Point<double>;

template <typename T>
struct Rect
{
	Point<T> leftTop;
	T width;
	T height;
};

using RectD = Rect<double>;
