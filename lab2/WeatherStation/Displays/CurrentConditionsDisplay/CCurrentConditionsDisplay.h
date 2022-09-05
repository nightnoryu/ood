#pragma once

#include "../../Weather/CWeatherData.h"

class CCurrentConditionsDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(WeatherInfo const& data) override;
};
