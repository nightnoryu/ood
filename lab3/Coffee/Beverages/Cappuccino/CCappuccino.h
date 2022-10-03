#pragma once

#include "../Coffee/CPortionedCoffee.h"

class CCappuccino : public CPortionedCoffee
{
public:
	explicit CCappuccino(CoffeePortion portion = CoffeePortion::Standard);

	double GetCost() const override;
};
