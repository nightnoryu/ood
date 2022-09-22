#pragma once

#include "../CCondimentDecorator.h"

class CCoconutFlakes : public CCondimentDecorator
{
public:
	CCoconutFlakes(IBeveragePtr&& beverage, unsigned mass);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_mass;
};
