#pragma once

#include "../Common/App/IDrawable.h"
#include "IShapeCollection.h"

class ISlide : public IDrawable
{
public:
	virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;

	virtual IShapeCollection& GetShapes() const = 0;
};
