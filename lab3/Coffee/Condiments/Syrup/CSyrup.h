#pragma once

#include "../CCondimentDecorator.h"

enum class SyrupType
{
	Chocolate,
	Maple,
};

class CSyrup : public CCondimentDecorator
{
public:
	explicit CSyrup(IBeveragePtr&& beverage, SyrupType syrupType);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	SyrupType m_syrupType;
};
