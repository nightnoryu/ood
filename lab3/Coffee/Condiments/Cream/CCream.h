#pragma once

#include "../CCondimentDecorator.h"

class CCream : public CCondimentDecorator
{
public:
	explicit CCream(IBeveragePtr&& beverage);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;
};
