#pragma once

#include <cstdint>

using RgbaColor = std::uint32_t;

template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

using RectD = Rect<double>;

class ICanvas
{
public:
	virtual void SetLineColor(RgbaColor color) = 0;

	virtual void BeginFill(RgbaColor color) = 0;
	virtual void EndFill() = 0;

	virtual void MoveTo(double x, double y) = 0;
	virtual void LineTo(double x, double y) = 0;

	virtual void DrawEllipse(double left, double top, double width, double height) = 0;

	virtual ~ICanvas() = 0;
};
