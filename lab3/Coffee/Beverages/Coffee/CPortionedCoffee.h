#pragma once

#include "CCoffee.h"

enum class CoffeePortion
{
	Standard,
	Double,
};

class CPortionedCoffee : public CCoffee
{
public:
	CPortionedCoffee(std::string const&description, CoffeePortion portion);

	std::string GetDescription() const override;

protected:
	CoffeePortion GetPortion() const;

private:
	std::string GetPortionDescription() const;

	CoffeePortion m_portion;
};
