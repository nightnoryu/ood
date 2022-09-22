#pragma once

#include "../CCondimentDecorator.h"

enum class IceCubeType
{
	DRY,
	WATER,
};

class CIceCubes : public CCondimentDecorator
{
public:
	CIceCubes(IBeveragePtr&& beverage, unsigned quantity, IceCubeType type = IceCubeType::WATER);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	unsigned m_quantity;
	IceCubeType m_type;
};
