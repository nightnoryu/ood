#include "CAngleAverageCalculator.h"
#include <cmath>

void CAngleAverageCalculator::Update(double value)
{
	auto angle = DegreesToRadians(value);
	m_sineSum += std::sin(angle);
	m_cosineSum += std::cos(angle);
}

double CAngleAverageCalculator::GetAverage() const
{
	return RadiansToDegrees(std::atan2(m_sineSum, m_cosineSum));
}

double CAngleAverageCalculator::DegreesToRadians(double value)
{
	return value * M_PI / 180;
}

double CAngleAverageCalculator::RadiansToDegrees(double value)
{
	return value * 180 / M_PI;
}
