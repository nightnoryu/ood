#include "CScalarAverageCalculator.h"

void CScalarAverageCalculator::Update(double value)
{
	m_accumulated += value;
	++m_accumulatedCount;
}

double CScalarAverageCalculator::GetAverage() const
{
	return m_accumulated / m_accumulatedCount;
}
