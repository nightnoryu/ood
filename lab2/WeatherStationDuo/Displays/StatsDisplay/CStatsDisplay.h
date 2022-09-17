#pragma once

#include "../../WeatherData/CWeatherData.h"
#include "StatsCalculator/CStatsMonitor.h"
#include <string>

class CStatsDisplay : public IObserver<WeatherInfo>
{
public:
	using Observable = IObservable<WeatherInfo>;

	void SetObservableName(Observable& observable, std::string const& name) override;

private:
	void Update(Observable& observable, WeatherInfo const& data) override;

	void PrintStats(std::string const& header, Stats const& stats) const;

	CStatsMonitor m_temperatureMonitor;
	CStatsMonitor m_humidityMonitor;
	CStatsMonitor m_pressureMonitor;
};
