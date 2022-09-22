#pragma once

#include "../CCondimentDecorator.h"

class CCinnamon : public CCondimentDecorator
{
public:
	explicit CCinnamon(IBeveragePtr&& beverage);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;
};
