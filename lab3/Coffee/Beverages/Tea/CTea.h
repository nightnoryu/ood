#pragma once

#include "../CBeverage.h"

enum class TeaType
{
	BLACK,
	THYME,
	KARKADE,
	GREEN,
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
