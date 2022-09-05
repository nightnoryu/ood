#pragma once

#include "../Observer/CObservable.hpp"

struct WeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CWeatherData : public CObservable<WeatherInfo>
{
public:
	double GetTemperature() const;
	double GetHumidity() const;
	double GetPressure() const;

	void MeasurementsChanged();

	void SetMeasurements(double temperature, double humidity, double pressure);

protected:
	WeatherInfo GetChangedData() const override;

private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};
