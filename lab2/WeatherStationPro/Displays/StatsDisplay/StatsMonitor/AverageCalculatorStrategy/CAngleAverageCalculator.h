#pragma once

#include "IAverageCalculator.h"

// See https://rosettacode.org/wiki/Averages/Mean_angle
class CAngleAverageCalculator : public IAverageCalculator
{
public:
	void Update(double value) override;
	double GetAverage() const override;

private:
	static double DegreesToRadians(double value);
	static double RadiansToDegrees(double value);

	double m_sineSum = 0;
	double m_cosineSum = 0;
`};
