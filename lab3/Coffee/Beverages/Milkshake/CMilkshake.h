#pragma once

#include "../Beverage/CBeverage.h"

class CMilkshake : public CBeverage
{
public:
	CMilkshake()
		: CBeverage("Milkshake")
	{
	}

	double GetCost() const override;
};
