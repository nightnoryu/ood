#pragma once

#include "../../WeatherData/CWeatherData.h"

class CCurrentConditionsDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(WeatherInfo const& data) override;
};
