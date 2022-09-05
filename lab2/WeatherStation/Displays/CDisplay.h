#pragma once

#include "../Weather/CWeatherData.h"

class CDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(WeatherInfo const& data) override;
};
