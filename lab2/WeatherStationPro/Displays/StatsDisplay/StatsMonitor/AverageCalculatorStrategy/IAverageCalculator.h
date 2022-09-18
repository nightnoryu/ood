#pragma once

class IAverageCalculator
{
public:
	virtual void Update(double value) = 0;
	virtual double GetAverage() const = 0;

	virtual ~IAverageCalculator() = default;
};
