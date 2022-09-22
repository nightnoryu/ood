#pragma once

#include "../CBeverage.h"

class CMilkshake : public CBeverage
{
public:
	CMilkshake()
		: CBeverage("Milkshake")
	{
	}

	double GetCost() const override;
};
