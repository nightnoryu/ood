#pragma once

#include "../CCondimentDecorator.h"
#include <stdexcept>

class CChocolateSlices : public CCondimentDecorator
{
public:
	CChocolateSlices(IBeveragePtr&& beverage, unsigned quantity);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	static const unsigned MAX_SLICES = 5;

	unsigned m_quantity;
};
