#pragma once

#include "../CBeverage.h"

class CCoffee : public CBeverage
{
public:
	explicit CCoffee(std::string const& description = "Coffee");

	double GetCost() const override;
};
