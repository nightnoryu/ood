#pragma once

#include "../../WeatherData/CWeatherData.h"
#include "StatsMonitor/CStatsMonitor.h"
#include <string>

class CStatsDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(WeatherInfo const& data) override;

	void PrintStats(std::string const& header, Stats const& stats) const;

	CStatsMonitor m_temperatureMonitor;
	CStatsMonitor m_humidityMonitor;
	CStatsMonitor m_pressureMonitor;
};
