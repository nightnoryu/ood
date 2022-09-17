#include "CStatsDisplay.h"
#include <iostream>

void CStatsDisplay::Update(const WeatherInfo& data)
{
	m_temperatureMonitor.Update(data.temperature);
	m_humidityMonitor.Update(data.humidity);
	m_pressureMonitor.Update(data.pressure);

	PrintStats("Temperature", m_temperatureMonitor.GetStats());
	PrintStats("Humidity", m_humidityMonitor.GetStats());
	PrintStats("Pressure", m_pressureMonitor.GetStats());
}

void CStatsDisplay::PrintStats(std::string const& header, Stats const& stats) const
{
	std::cout << "[" << header << "]\n"
			  << "Max " << stats.max << "\n"
			  << "Min " << stats.min << "\n"
			  << "Average " << stats.average << "\n"
			  << "----------------" << std::endl;
}
