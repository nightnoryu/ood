#pragma once

#include "../CCondimentDecorator.h"

class CLemon : public CCondimentDecorator
{
public:
	explicit CLemon(IBeveragePtr&& beverage, unsigned quantity = 1);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_quantity;
};
