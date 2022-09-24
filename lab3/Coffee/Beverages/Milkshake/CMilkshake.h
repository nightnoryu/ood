#pragma once

#include "../CBeverage.h"

enum class MilkshakePortion
{
	Small,
	Standard,
	Grand,
};

class CMilkshake : public CBeverage
{
public:
	explicit CMilkshake(MilkshakePortion portion = MilkshakePortion::Standard);

	std::string GetDescription() const override;
	double GetCost() const override;

private:
	std::string GetPortionDescription() const;

	MilkshakePortion m_portion;
};
