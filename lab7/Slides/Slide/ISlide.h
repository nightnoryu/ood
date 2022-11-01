#pragma once

#include "../Shapes/IShapes.h"

class ISlide : public IDrawable
{
public:
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual IShapes const& GetShapes() const = 0;
};
