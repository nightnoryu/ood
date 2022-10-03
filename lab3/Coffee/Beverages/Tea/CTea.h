#pragma once

#include "../CBeverage.h"

enum class TeaType
{
	Black,
	Green,
	Thyme,
	Karkade,
};

class CTea : public CBeverage
{
public:
	explicit CTea(TeaType type = TeaType::Black);

	std::string GetDescription() const override;
	double GetCost() const override;

private:
	std::string GetTypeDescription() const;

	TeaType m_type;
};
