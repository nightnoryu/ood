#pragma once

#include "../Coffee/CCoffee.h"

class CLatte : public CCoffee
{
public:
	CLatte()
		: CCoffee("Latte")
	{
	}

	double GetCost() const override;
};
