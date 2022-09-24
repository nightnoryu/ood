#include "ChocolateSlices.h"

ChocolateSlices::ChocolateSlices(IBeveragePtr&& beverage, unsigned quantity)
	: CCondimentDecorator(std::move(beverage))
	, m_quantity(quantity)
{
	if (m_quantity > MAX_SLICES)
	{
		throw std::invalid_argument("too many slices");
	}
}

std::string ChocolateSlices::GetCondimentDescription() const
{
	return "Chocolate slices x " + std::to_string(m_quantity);
}

double ChocolateSlices::GetCondimentCost() const
{
	return 10 * m_quantity;
}
