#pragma once

#include "../../WeatherDataProLite/CWeatherDataProLite.h"

class CCurrentConditionsDisplay : public IObserver<WeatherInfo>
{
private:
	void Update(WeatherInfo const& data) override;
};
