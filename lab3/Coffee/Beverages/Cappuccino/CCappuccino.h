#pragma once

#include "../Coffee/CCoffee.h"

class CCappuccino : public CCoffee
{
public:
	CCappuccino()
		: CCoffee("Cappuccino")
	{
	}

	double GetCost() const override;
};
