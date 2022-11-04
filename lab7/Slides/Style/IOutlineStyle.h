#pragma once

#include "IStyle.h"

class IOutlineStyle : public IStyle
{
public:
	virtual double GetThickness() const = 0;
	virtual void SetThickness(double thickness) = 0;
};
