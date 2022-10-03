#pragma once

#include "../Observer/CObservable.hpp"
#include <set>

struct WeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;

	double windSpeed = 0;
	double windDirection = 0;
};

enum class WeatherChangedEvent
{
	All,
	Temperature,
	Humidity,
	Pressure,
	WindSpeed,
	WindDirection,
};

class CWeatherDataProLite : public CObservable<WeatherInfo, WeatherChangedEvent>
{
public:
	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	double GetWindSpeed() const;
	double GetWindDirection() const;

	void MeasurementsChanged();

	void SetMeasurements(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

protected:
	WeatherInfo GetChangedData() const override;
	std::set<WeatherChangedEvent> GetCurrentEvents() const override;

private:
	void SetCurrentEvents(double temperature, double humidity, double pressure, double windSpeed, double windDirection);

	std::set<WeatherChangedEvent> m_currentEvents;

	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;

	double m_windSpeed = 0;
	double m_windDirection = 0;
};
