#pragma once

#include "../../WeatherDataPro/CWeatherDataPro.h"
#include "StatsMonitor/CStatsMonitor.h"
#include <string>

class CStatsDisplay : public IObserver<WeatherInfo>
{
public:
	CStatsDisplay();

private:
	void Update(WeatherInfo const& data) override;
	void PrintStats(std::string const& header, Stats const& stats) const;

	CStatsMonitor m_temperatureMonitor;
	CStatsMonitor m_humidityMonitor;
	CStatsMonitor m_pressureMonitor;
	CStatsMonitor m_windSpeedMonitor;
	CStatsMonitor m_windDirectionMonitor;
};
