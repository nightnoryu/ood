#include "CStatsDisplay.h"
#include "StatsMonitor/AverageCalculatorStrategy/CAngleAverageCalculator.h"
#include "StatsMonitor/AverageCalculatorStrategy/CScalarAverageCalculator.h"
#include <iostream>

CStatsDisplay::CStatsDisplay()
	: m_temperatureMonitor(std::make_unique<CScalarAverageCalculator>())
	, m_humidityMonitor(std::make_unique<CScalarAverageCalculator>())
	, m_pressureMonitor(std::make_unique<CScalarAverageCalculator>())
	, m_windSpeedMonitor(std::make_unique<CScalarAverageCalculator>())
	, m_windDirectionMonitor(std::make_unique<CAngleAverageCalculator>())
{
}

void CStatsDisplay::Update(const WeatherInfo& data)
{
	m_temperatureMonitor.Update(data.temperature);
	m_humidityMonitor.Update(data.humidity);
	m_pressureMonitor.Update(data.pressure);
	m_windSpeedMonitor.Update(data.windSpeed);
	m_windDirectionMonitor.Update(data.windDirection);

	PrintStats("Temperature", m_temperatureMonitor.GetStats());
	PrintStats("Humidity", m_humidityMonitor.GetStats());
	PrintStats("Pressure", m_pressureMonitor.GetStats());
	PrintStats("Wind speed", m_windSpeedMonitor.GetStats());
	PrintStats("Wind direction", m_windDirectionMonitor.GetStats());
}

void CStatsDisplay::PrintStats(std::string const& header, Stats const& stats) const
{
	std::cout << "[" << header << "]\n"
			  << "Max " << stats.max << "\n"
			  << "Min " << stats.min << "\n"
			  << "Average " << stats.average << "\n"
			  << "----------------" << std::endl;
}
