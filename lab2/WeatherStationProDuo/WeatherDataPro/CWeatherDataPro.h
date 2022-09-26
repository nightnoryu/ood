#pragma once

#include "../Observer/CObservable.hpp"
#include "../WeatherData/CWeatherData.h"

class CWeatherDataPro : public CBaseWeatherData<CObservable<WeatherInfo>>
{
public:
	double GetWindSpeed() const;
	double GetWindDirection() const;

	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

protected:
	WeatherInfo GetChangedData() const override;

private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;

	double m_windSpeed = 0;
	double m_windDirection = 0;
};
