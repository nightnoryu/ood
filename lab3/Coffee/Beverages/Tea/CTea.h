#pragma once

#include "../CBeverage.h"

enum class TeaType
{
	Black,
	Thyme,
	Karkade,
	Green,
};

class CTea : public CBeverage
{
public:
	CTea()
		: CBeverage("Tea")
	{
	}

	double GetCost() const override;
};
