#pragma once

#include "../Coffee/CPortionedCoffee.h"

class CLatte : public CPortionedCoffee
{
public:
	explicit CLatte(CoffeePortion portion = CoffeePortion::Standard);

	double GetCost() const override;
};
