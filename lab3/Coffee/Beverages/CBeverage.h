#pragma once

#include "IBeverage.h"

class CBeverage : public IBeverage
{
public:
	explicit CBeverage(std::string const& description)
		: m_description(description)
	{
	}

	std::string GetDescription() const final;

private:
	std::string m_description;
};
