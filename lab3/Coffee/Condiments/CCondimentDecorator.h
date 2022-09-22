#pragma once

#include "../Beverages/IBeverage.h"

class CCondimentDecorator : public IBeverage
{
public:
	std::string GetDescription() const final;
	double GetCost() const final;

	virtual std::string GetCondimentDescription() const = 0;
	virtual double GetCondimentCost() const = 0;

protected:
	explicit CCondimentDecorator(IBeveragePtr&& beverage)
		: m_beverage(std::move(beverage))
	{
	}

private:
	IBeveragePtr m_beverage;
};
