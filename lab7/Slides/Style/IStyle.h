#pragma once

#include "../Shapes/ShapeTypes.h"

class IStyle
{
public:
	virtual bool IsEnabled() const = 0;
	virtual void Enable() = 0;
	virtual void Disable() = 0;

	virtual RgbaColor GetColor() const = 0;
	virtual void SetColor(RgbaColor color) = 0;

	virtual ~IStyle() = default;
};
