#pragma once

#include "../CBeverage.h"

class CTea : public CBeverage
{
public:
	CTea()
		: CBeverage("Tea")
	{
	}

	double GetCost() const override;
};
