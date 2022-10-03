#pragma once

#include "../CCondimentDecorator.h"

enum class LiqueurType
{
	Nut,
	Chocolate,
};

class CLiqueur : public CCondimentDecorator
{
public:
	explicit CLiqueur(IBeveragePtr&& beverage, LiqueurType type = LiqueurType::Nut);

protected:
	std::string GetCondimentDescription() const override;
	double GetCondimentCost() const override;

private:
	std::string GetTypeDescription() const;

	LiqueurType m_type;
};
