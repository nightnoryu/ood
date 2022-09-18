#pragma once

#include "AverageCalculatorStrategy/IAverageCalculator.h"
#include <numeric>
#include <memory>

struct Stats
{
	double max = 0;
	double min = 0;
	double average = 0;
};

class CStatsMonitor
{
public:
	CStatsMonitor(std::unique_ptr<IAverageCalculator>&& averageCalculator);

	void Update(double value);
	Stats GetStats() const;

private:
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();

	std::unique_ptr<IAverageCalculator> m_averageCalculator;
};
