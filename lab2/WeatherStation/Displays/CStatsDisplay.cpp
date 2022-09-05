#include "CStatsDisplay.h"
#include <iostream>

void CStatsDisplay::Update(const WeatherInfo& data)
{
	if (m_minTemperature > data.temperature)
	{
		m_minTemperature = data.temperature;
	}
	if (m_maxTemperature < data.temperature)
	{
		m_maxTemperature = data.temperature;
	}
	m_accTemperature += data.temperature;
	++m_countAcc;

	std::cout << "Max Temp " << m_maxTemperature << "\n"
			  << "Min Temp " << m_minTemperature << "\n"
			  << "Average Temp " << (m_accTemperature / m_countAcc) << "\n"
			  << "----------------" << std::endl;
}
