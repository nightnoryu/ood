#pragma once

#include "IAverageCalculator.h"

class CAngleAverageCalculator : public IAverageCalculator
{
public:
	void Update(double value) override;
	double GetAverage() const override;
};
