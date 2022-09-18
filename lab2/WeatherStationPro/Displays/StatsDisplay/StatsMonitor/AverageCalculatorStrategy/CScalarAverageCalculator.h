#pragma once

#include "./IAverageCalculator.h"

class CScalarAverageCalculator : public IAverageCalculator
{
public:
	void Update(double value) override;
	double GetAverage() const override;

private:
	double m_accumulated = 0;
	unsigned m_accumulatedCount = 0;
};
