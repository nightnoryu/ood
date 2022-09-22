#pragma once

#include "../Beverage/CBeverage.h"

class CTea : public CBeverage
{
public:
	CTea()
		: CBeverage("Tea")
	{
	}

	double GetCost() const override;
};
