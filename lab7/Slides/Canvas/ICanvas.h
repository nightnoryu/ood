#pragma once

#include "../Shapes/ShapeTypes.h"
#include <optional>
#include <vector>

class ICanvas
{
public:
	virtual void DrawLine(PointD start, PointD end, std::optional<RgbaColor> color) = 0;

	virtual void DrawPolygon(
		std::vector<PointD> const& points,
		std::optional<RgbaColor> outlineColor,
		std::optional<RgbaColor> fillColor)
		= 0;

	virtual void DrawEllipse(
		PointD center,
		double horizontalRadius,
		double verticalRadius,
		std::optional<RgbaColor> outlineColor,
		std::optional<RgbaColor> fillColor)
		= 0;

	virtual ~ICanvas() = 0;
};
