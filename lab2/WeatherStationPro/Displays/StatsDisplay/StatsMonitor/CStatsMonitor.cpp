#include "CStatsMonitor.h"

CStatsMonitor::CStatsMonitor(std::unique_ptr<IAverageCalculator>&& averageCalculator)
	: m_averageCalculator(std::move(averageCalculator))
{
}

void CStatsMonitor::Update(double value)
{
	if (value < m_min)
	{
		m_min = value;
	}

	if (value > m_max)
	{
		m_max = value;
	}

	m_averageCalculator->Update(value);
}

Stats CStatsMonitor::GetStats() const
{
	return {
		.max = m_max,
		.min = m_min,
		.average = m_averageCalculator->GetAverage(),
	};
}
