#include "CSyrup.h"

CSyrup::CSyrup(IBeveragePtr&& beverage, SyrupType syrupType)
	: CCondimentDecorator(std::move(beverage))
	, m_syrupType(syrupType)
{
}

std::string CSyrup::GetCondimentDescription() const
{
	return std::string(m_syrupType == SyrupType::CHOCOLATE ? "Chocolate" : "Maple")
		+ " syrup";
}

double CSyrup::GetCondimentCost() const
{
	return 15;
}
